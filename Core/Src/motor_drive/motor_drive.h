#include "stdint.h"

typedef enum
{
  YAW_MOTOR = 0,
  PITCH_MOTOR
}motors_t;

void enable_motor(motors_t motors_et);
void disable_motor(motors_t motors_et);

void drive_motor(motors_t motors_et, uint8_t direction);