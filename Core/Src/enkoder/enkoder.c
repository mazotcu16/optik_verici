#include "enkoder.h"
#include <string.h>

/* --------------------------------------------------------------------------
 * Low-level I2C
 * -------------------------------------------------------------------------- */

static HAL_StatusTypeDef MT6701_ReadReg(MT6701_Handle *dev, uint8_t reg, uint8_t *data)
{
    return HAL_I2C_Mem_Read(dev->hi2c, dev->addr, reg,
                            I2C_MEMADD_SIZE_8BIT, data, 1,
                            MT6701_I2C_TIMEOUT);
}

static HAL_StatusTypeDef MT6701_WriteReg(MT6701_Handle *dev, uint8_t reg, uint8_t data)
{
    return HAL_I2C_Mem_Write(dev->hi2c, dev->addr, reg,
                             I2C_MEMADD_SIZE_8BIT, &data, 1,
                             MT6701_I2C_TIMEOUT);
}

/* --------------------------------------------------------------------------
 * Zero position
 * -------------------------------------------------------------------------- */

HAL_StatusTypeDef MT6701_GetZero(MT6701_Handle *dev, uint16_t *zero_raw, float *zero_deg)
{
    uint8_t h, l;
    HAL_StatusTypeDef s;

    s = MT6701_ReadReg(dev, MT6701_REG_ZERO_H, &h);
    if (s != HAL_OK) return s;

    s = MT6701_ReadReg(dev, MT6701_REG_ZERO_L, &l);
    if (s != HAL_OK) return s;

    *zero_raw = ((uint16_t)(h & 0x0F) << 8) | (uint16_t)l;
    *zero_deg = (float)(*zero_raw) * MT6701_DEG_PER_12BIT;

    return HAL_OK;
}

HAL_StatusTypeDef MT6701_SetZeroRaw(MT6701_Handle *dev, uint16_t zero_raw)
{
    HAL_StatusTypeDef s;
    uint8_t reg_val;

    zero_raw &= 0x0FFF;

    s = MT6701_ReadReg(dev, MT6701_REG_ZERO_H, &reg_val);
    if (s != HAL_OK) return s;

    reg_val = (reg_val & 0xF0) | ((zero_raw >> 8) & 0x0F);
    s = MT6701_WriteReg(dev, MT6701_REG_ZERO_H, reg_val);
    if (s != HAL_OK) return s;

    s = MT6701_WriteReg(dev, MT6701_REG_ZERO_L, (uint8_t)(zero_raw & 0xFF));
    return s;
}

HAL_StatusTypeDef MT6701_SetZeroDegrees(MT6701_Handle *dev, float angle_deg)
{
    while (angle_deg < 0.0f)    angle_deg += 360.0f;
    while (angle_deg >= 360.0f) angle_deg -= 360.0f;

    uint16_t raw = (uint16_t)(angle_deg / MT6701_DEG_PER_12BIT);
    if (raw > 4095) raw = 4095;

    return MT6701_SetZeroRaw(dev, raw);
}

HAL_StatusTypeDef MT6701_SetCurrentPositionAsZero(MT6701_Handle *dev)
{
    HAL_StatusTypeDef s;
    uint8_t h, l;

    uint16_t old_zero;
    float dummy;
    s = MT6701_GetZero(dev, &old_zero, &dummy);
    if (s != HAL_OK) return s;

    s = MT6701_ReadReg(dev, MT6701_REG_ANGLE_H, &h);
    if (s != HAL_OK) return s;

    s = MT6701_ReadReg(dev, MT6701_REG_ANGLE_L, &l);
    if (s != HAL_OK) return s;

    uint16_t angle_14bit    = ((uint16_t)h << 6) | ((uint16_t)l >> 2);
    uint16_t reported_12bit = angle_14bit >> 2;
    uint16_t new_zero       = (old_zero + reported_12bit) % MT6701_12BIT_RES;

    return MT6701_SetZeroRaw(dev, new_zero);
}

/* --------------------------------------------------------------------------
 * Angle
 * -------------------------------------------------------------------------- */

HAL_StatusTypeDef MT6701_ReadAngle(MT6701_Handle *dev)
{
    uint8_t h, l;
    HAL_StatusTypeDef s;

    s = MT6701_ReadReg(dev, MT6701_REG_ANGLE_H, &h);
    if (s != HAL_OK) return s;

    s = MT6701_ReadReg(dev, MT6701_REG_ANGLE_L, &l);
    if (s != HAL_OK) return s;

    dev->raw_angle = ((uint16_t)h << 6) | ((uint16_t)l >> 2);
    dev->angle_deg = (float)dev->raw_angle * MT6701_DEG_PER_14BIT;

    return HAL_OK;
}

/* --------------------------------------------------------------------------
 * Output mode
 * -------------------------------------------------------------------------- */

HAL_StatusTypeDef MT6701_SetAnalogOutput(MT6701_Handle *dev)
{
    uint8_t val;
    HAL_StatusTypeDef s = MT6701_ReadReg(dev, MT6701_REG_OUT_CFG, &val);
    if (s != HAL_OK) return s;

    val &= ~(1 << 5);
    return MT6701_WriteReg(dev, MT6701_REG_OUT_CFG, val);
}

HAL_StatusTypeDef MT6701_SetPWMOutput(MT6701_Handle *dev)
{
    uint8_t val;
    HAL_StatusTypeDef s = MT6701_ReadReg(dev, MT6701_REG_OUT_CFG, &val);
    if (s != HAL_OK) return s;

    val |= (1 << 5);
    return MT6701_WriteReg(dev, MT6701_REG_OUT_CFG, val);
}

/* --------------------------------------------------------------------------
 * EEPROM
 * -------------------------------------------------------------------------- */

HAL_StatusTypeDef MT6701_ProgramEEPROM(MT6701_Handle *dev)
{
    HAL_StatusTypeDef s;

    s = MT6701_WriteReg(dev, MT6701_REG_PROG_KEY, MT6701_PROG_KEY_VAL);
    if (s != HAL_OK) return s;

    s = MT6701_WriteReg(dev, MT6701_REG_PROG_CMD, MT6701_PROG_CMD_VAL);
    if (s != HAL_OK) return s;

    HAL_Delay(700);

    return HAL_OK;
}

/* --------------------------------------------------------------------------
 * Full calibration
 * -------------------------------------------------------------------------- */

MT6701_CalStatus MT6701_CalibrateZero(MT6701_Handle   *dev,
                                       MT6701_CalResult *result,
                                       uint8_t          burn_eeprom,
                                       float            max_error_deg)
{
    HAL_StatusTypeDef s;
    uint8_t h, l;

    memset(result, 0, sizeof(MT6701_CalResult));

    s = MT6701_GetZero(dev, &result->old_zero_raw, &result->old_zero_deg);
    if (s != HAL_OK) { result->status = MT6701_CAL_ERR_I2C; return result->status; }

    s = MT6701_ReadReg(dev, MT6701_REG_ANGLE_H, &h);
    if (s != HAL_OK) { result->status = MT6701_CAL_ERR_I2C; return result->status; }

    s = MT6701_ReadReg(dev, MT6701_REG_ANGLE_L, &l);
    if (s != HAL_OK) { result->status = MT6701_CAL_ERR_I2C; return result->status; }

    uint16_t angle_14bit    = ((uint16_t)h << 6) | ((uint16_t)l >> 2);
    uint16_t reported_12bit = angle_14bit >> 2;

    result->new_zero_raw = (result->old_zero_raw + reported_12bit) % MT6701_12BIT_RES;
    result->new_zero_deg = (float)result->new_zero_raw * MT6701_DEG_PER_12BIT;

    s = MT6701_SetZeroRaw(dev, result->new_zero_raw);
    if (s != HAL_OK) { result->status = MT6701_CAL_ERR_I2C; return result->status; }

    HAL_Delay(10);

    s = MT6701_ReadAngle(dev);
    if (s != HAL_OK) { result->status = MT6701_CAL_ERR_I2C; return result->status; }

    result->post_cal_angle = dev->angle_deg;

    if (max_error_deg > 0.0f) {
        float error = result->post_cal_angle;
        if (error > 180.0f) error = 360.0f - error;
        if (error > max_error_deg) {
            result->status = MT6701_CAL_ERR_VERIFY;
            return result->status;
        }
    }

    if (burn_eeprom) {
        s = MT6701_ProgramEEPROM(dev);
        if (s != HAL_OK) { result->status = MT6701_CAL_ERR_EEPROM; return result->status; }

        uint16_t readback;
        float readback_deg;
        s = MT6701_GetZero(dev, &readback, &readback_deg);
        if (s != HAL_OK) { result->status = MT6701_CAL_ERR_EEPROM; return result->status; }

        result->eeprom_readback = readback;

        if (readback != result->new_zero_raw) {
            result->status = MT6701_CAL_ERR_EEPROM;
            return result->status;
        }
    }

    result->status = MT6701_CAL_OK;
    return result->status;
}

/* --------------------------------------------------------------------------
 * Init — runs calibration if MT6701_CALIBRATE_ZERO == 1
 * -------------------------------------------------------------------------- */

HAL_StatusTypeDef MT6701_Init(MT6701_Handle *dev, I2C_HandleTypeDef *hi2c)
{
    dev->hi2c       = hi2c;
    dev->addr       = MT6701_I2C_ADDR;
    dev->raw_angle  = 0;
    dev->angle_deg  = 0.0f;
    dev->is_present = 0;
    dev->cal_ok     = 0;

    HAL_Delay(MT6701_POWER_UP_MS);

    if (HAL_I2C_IsDeviceReady(hi2c, dev->addr, 3, MT6701_I2C_TIMEOUT) != HAL_OK)
        return HAL_ERROR;

    uint8_t dummy;
    if (MT6701_ReadReg(dev, MT6701_REG_OUT_CFG, &dummy) != HAL_OK)
        return HAL_ERROR;

    dev->is_present = 1;

#if MT6701_CALIBRATE_ZERO
    MT6701_CalResult cal;
    MT6701_CalStatus cal_s = MT6701_CalibrateZero(dev, &cal, 1, MT6701_CAL_MAX_ERR_DEG);
    dev->cal_ok = (cal_s == MT6701_CAL_OK) ? 1 : 0;
    if (cal_s != MT6701_CAL_OK)
        return HAL_ERROR;
#endif

    return HAL_OK;
}