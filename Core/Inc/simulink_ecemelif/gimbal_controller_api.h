#ifndef GIMBAL_CONTROLLER_API_H_
#define GIMBAL_CONTROLLER_API_H_

#include "gimbal_controller.h"

void gimbal_controller_set_Q1(real_T value);
void gimbal_controller_set_theta_meas_yaw(real_T value);

real_T gimbal_controller_get_omega_cmd_yaw(void);
boolean_T gimbal_controller_get_beam_valid(void);

#endif /* GIMBAL_CONTROLLER_API_H_ */
