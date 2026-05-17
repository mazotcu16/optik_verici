#ifndef ENKODER_H
#define ENKODER_H

#include "main.h"
#include <stdint.h>

/* --------------------------------------------------------------------------
 * User config — set to 1 to calibrate zero on init, 0 for normal run
 * -------------------------------------------------------------------------- */
#define MT6701_CALIBRATE_ZERO   FALSE
#define MT6701_CAL_MAX_ERR_DEG  5.0f

/* --------------------------------------------------------------------------
 * Definitions
 * -------------------------------------------------------------------------- */
#define MT6701_I2C_ADDR         (0x06 << 1)

#define MT6701_REG_ANGLE_H      0x03
#define MT6701_REG_ANGLE_L      0x04
#define MT6701_REG_PROG_KEY     0x09
#define MT6701_REG_PROG_CMD     0x0A
#define MT6701_REG_ZERO_H       0x32
#define MT6701_REG_ZERO_L       0x33
#define MT6701_REG_OUT_CFG      0x38

#define MT6701_PROG_KEY_VAL     0xB3
#define MT6701_PROG_CMD_VAL     0x05
#define MT6701_14BIT_RES        16384
#define MT6701_12BIT_RES        4096
#define MT6701_DEG_PER_14BIT    (360.0f / 16384.0f)
#define MT6701_DEG_PER_12BIT    (360.0f / 4096.0f)
#define MT6701_I2C_TIMEOUT      100
#define MT6701_POWER_UP_MS      5

/* --------------------------------------------------------------------------
 * Types
 * -------------------------------------------------------------------------- */
typedef struct {
    I2C_HandleTypeDef *hi2c;
    uint8_t           addr;
    uint16_t          raw_angle;
    float             angle_deg;
    uint8_t           is_present;
    uint8_t           cal_ok;
} MT6701_Handle;

typedef enum {
    MT6701_CAL_OK         = 0,
    MT6701_CAL_ERR_I2C    = 1,
    MT6701_CAL_ERR_VERIFY = 2,
    MT6701_CAL_ERR_EEPROM = 3,
} MT6701_CalStatus;

typedef struct {
    MT6701_CalStatus status;
    uint16_t old_zero_raw;
    float    old_zero_deg;
    uint16_t new_zero_raw;
    float    new_zero_deg;
    float    post_cal_angle;
    uint16_t eeprom_readback;
} MT6701_CalResult;

/* --------------------------------------------------------------------------
 * API
 * -------------------------------------------------------------------------- */
HAL_StatusTypeDef   MT6701_Init                    (MT6701_Handle *dev, I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef   MT6701_ReadAngle               (MT6701_Handle *dev);
HAL_StatusTypeDef   MT6701_GetZero                 (MT6701_Handle *dev, uint16_t *zero_raw, float *zero_deg);
HAL_StatusTypeDef   MT6701_SetZeroRaw              (MT6701_Handle *dev, uint16_t zero_raw);
HAL_StatusTypeDef   MT6701_SetZeroDegrees          (MT6701_Handle *dev, float angle_deg);
HAL_StatusTypeDef   MT6701_SetCurrentPositionAsZero(MT6701_Handle *dev);
HAL_StatusTypeDef   MT6701_SetAnalogOutput         (MT6701_Handle *dev);
HAL_StatusTypeDef   MT6701_SetPWMOutput            (MT6701_Handle *dev);
HAL_StatusTypeDef   MT6701_ProgramEEPROM           (MT6701_Handle *dev);
MT6701_CalStatus    MT6701_CalibrateZero           (MT6701_Handle *dev, MT6701_CalResult *result,
                                                    uint8_t burn_eeprom, float max_error_deg);

#endif