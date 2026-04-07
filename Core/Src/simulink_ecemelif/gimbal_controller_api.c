#include "gimbal_controller_api.h"

void gimbal_controller_set_Q1(real_T value)
{
    gimbal_controller_U.Q1 = value;
}

void gimbal_controller_set_theta_meas_yaw(real_T value)
{
    gimbal_controller_U.theta_meas_yaw = value;
}

real_T gimbal_controller_get_omega_cmd_yaw(void)
{
    return gimbal_controller_Y.omega_cmd_yaw;
}

boolean_T gimbal_controller_get_beam_valid(void)
{
    return gimbal_controller_Y.beam_valid;
}
