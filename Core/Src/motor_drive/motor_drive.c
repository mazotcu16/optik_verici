#include "motor_drive.h"
#include "main.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_tim.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;

static uint32_t get_motor_pwm_pulse(motors_t motors_et)
{
    if (YAW_MOTOR == motors_et)
    {
        return (htim1.Init.Period + 1U) / 2U;
    }
    return (htim2.Init.Period + 1U) / 2U;
}

static void set_motor_pwm(motors_t motors_et, uint32_t pulse)
{
    if (YAW_MOTOR == motors_et)
    {
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, pulse);
    }
    else
    {
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, pulse);
    }
}

static void start_motor_pwm(motors_t motors_et)
{
    if (YAW_MOTOR == motors_et)
    {
        HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
    }
    else
    {
        HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
    }
}

static void stop_motor_pwm(motors_t motors_et)
{
    if (YAW_MOTOR == motors_et)
    {
        HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_4);
    }
    else
    {
        HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_4);
    }
}

void enable_motor(motors_t motors_et)
{
    if (YAW_MOTOR == motors_et)
    {
        HAL_GPIO_WritePin(ENA_YAW_GPIO_Port, ENA_YAW_Pin, GPIO_PIN_RESET);
    }
    else if (PITCH_MOTOR == motors_et)
    {
        HAL_GPIO_WritePin(ENA_PITCH_GPIO_Port, ENA_PITCH_Pin, GPIO_PIN_RESET);
    }

    set_motor_pwm(motors_et, get_motor_pwm_pulse(motors_et));
    start_motor_pwm(motors_et);
}

void disable_motor(motors_t motors_et)
{
    set_motor_pwm(motors_et, 0U);
    stop_motor_pwm(motors_et);

    if (YAW_MOTOR == motors_et)
    {
        HAL_GPIO_WritePin(ENA_YAW_GPIO_Port, ENA_YAW_Pin, GPIO_PIN_SET);
    }
    else if (PITCH_MOTOR == motors_et)
    {
        HAL_GPIO_WritePin(ENA_PITCH_GPIO_Port, ENA_PITCH_Pin, GPIO_PIN_SET);
    }
}

void drive_motor(motors_t motors_et, uint8_t direction)
{
    GPIO_PinState dir_state = (direction != 0U) ? GPIO_PIN_SET : GPIO_PIN_RESET;

    if (YAW_MOTOR == motors_et)
    {
        HAL_GPIO_WritePin(DIR_YAW_GPIO_Port, DIR_YAW_Pin, dir_state);
    }
    else if (PITCH_MOTOR == motors_et)
    {
        HAL_GPIO_WritePin(DIR_PITCH_GPIO_Port, DIR_PITCH_Pin, dir_state);
    }

    enable_motor(motors_et);
}
