#ifndef GIMBAL_CONTROLLER_API_H_
#define GIMBAL_CONTROLLER_API_H_

#include "gimbal_controller.h"

void gimbal_controller_set_L(real_T value);
void gimbal_controller_set_R(real_T value);
void gimbal_controller_set_U(real_T value);
void gimbal_controller_set_D(real_T value);
void gimbal_controller_set_theta_meas_yaw(real_T value);
void gimbal_controller_set_theta_meas_pitch(real_T value);

real_T gimbal_controller_get_omega_cmd_yaw(void);
real_T gimbal_controller_get_omega_cmd_pitch(void);
boolean_T gimbal_controller_get_beam_valid(void);
real_T gimbal_controller_get_e_x(void);
real_T gimbal_controller_get_e_y(void);
boolean_T gimbal_controller_get_comm_enabled(void);
real_T gimbal_controller_get_lock_counter(void);

#endif /* GIMBAL_CONTROLLER_API_H_ */
