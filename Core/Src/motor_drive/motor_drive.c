#include "motor_drive.h"
#include "main.h"
#include "stm32f1xx_hal_gpio.h"

void enable_motor(motors_t motors_et)
{
    if(YAW_MOTOR == motors_et)
    {
        HAL_GPIO_WritePin(ENA_YAW_GPIO_Port, ENA_YAW_Pin, GPIO_PIN_RESET);
    }
    else if(PITCH_MOTOR == motors_et)
    {
        HAL_GPIO_WritePin(ENA_PITCH_GPIO_Port, ENA_PITCH_Pin, GPIO_PIN_RESET);
    }
}

void disable_motor(motors_t motors_et)
{
    if(YAW_MOTOR == motors_et)
    {
        HAL_GPIO_WritePin(ENA_YAW_GPIO_Port, ENA_YAW_Pin, GPIO_PIN_SET);
    }
    else if(PITCH_MOTOR == motors_et)
    {
        HAL_GPIO_WritePin(ENA_PITCH_GPIO_Port, ENA_PITCH_Pin, GPIO_PIN_SET);
    }
}

void drive_motor(motors_t motors_et, uint8_t direction)
{
    
}