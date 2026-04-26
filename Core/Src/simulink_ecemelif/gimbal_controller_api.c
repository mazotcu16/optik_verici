#include "simulink_ecemelif/gimbal_controller_api.h"

void gimbal_controller_set_L(real_T value)
{
    gimbal_controller_U.L = value;
}

void gimbal_controller_set_R(real_T value)
{
    gimbal_controller_U.R = value;
}

void gimbal_controller_set_U(real_T value)
{
    gimbal_controller_U.U = value;
}

void gimbal_controller_set_D(real_T value)
{
    gimbal_controller_U.D = value;
}

void gimbal_controller_set_theta_meas_yaw(real_T value)
{
    gimbal_controller_U.theta_meas_yaw = value;
}

void gimbal_controller_set_theta_meas_pitch(real_T value)
{
    gimbal_controller_U.theta_meas_pitch = value;
}

real_T gimbal_controller_get_omega_cmd_yaw(void)
{
    return gimbal_controller_Y.omega_cmd_yaw;
}

real_T gimbal_controller_get_omega_cmd_pitch(void)
{
    return gimbal_controller_Y.omega_cmd_pitch;
}

boolean_T gimbal_controller_get_beam_valid(void)
{
    return gimbal_controller_Y.beam_valid;
}

real_T gimbal_controller_get_e_x(void)
{
    return gimbal_controller_Y.e_x;
}

real_T gimbal_controller_get_e_y(void)
{
    return gimbal_controller_Y.e_y;
}

boolean_T gimbal_controller_get_comm_enabled(void)
{
    return gimbal_controller_Y.comm_enabled;
}

real_T gimbal_controller_get_lock_counter(void)
{
    return gimbal_controller_Y.lock_counter;
}
