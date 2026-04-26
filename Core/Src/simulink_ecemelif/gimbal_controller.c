/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: gimbal_controller.c
 *
 * Code generated for Simulink model 'gimbal_controller'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Wed Apr 22 00:12:13 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Inc/simulink_ecemelif/gimbal_controller.h"
#include <math.h>
#include "Inc/simulink_ecemelif/rtwtypes.h"

/* Block signals (default storage) */
B_gimbal_controller_T gimbal_controller_B;

/* Block states (default storage) */
DW_gimbal_controller_T gimbal_controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_gimbal_controller_T gimbal_controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_gimbal_controller_T gimbal_controller_Y;

/* Real-time model */
static RT_MODEL_gimbal_controller_T gimbal_controller_M_;
RT_MODEL_gimbal_controller_T *const gimbal_controller_M = &gimbal_controller_M_;

/* Model step function */
void gimbal_controller_step(void)
{
  real_T rtb_Abs;
  real_T rtb_FilterCoefficient_p;
  real_T rtb_Integrator_pd;
  real_T rtb_Saturation_b;
  real_T rtb_Sum;
  real_T rtb_Sum2;
  real_T rtb_Sum_g;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_g;

  /* Switch: '<S2>/Switch' incorporates:
   *  Inport: '<Root>/D'
   *  Inport: '<Root>/L'
   *  Inport: '<Root>/R'
   *  Inport: '<Root>/U'
   *  Sum: '<S2>/Add'
   */
  gimbal_controller_Y.e_x = ((gimbal_controller_U.L + gimbal_controller_U.R) +
    gimbal_controller_U.U) + gimbal_controller_U.D;

  /* MinMax: '<S2>/MinMax' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  gimbal_controller_B.S_safe = fmax(gimbal_controller_Y.e_x, 0.05);

  /* RelationalOperator: '<S9>/Compare' incorporates:
   *  Constant: '<S9>/Constant'
   */
  gimbal_controller_Y.beam_valid = (gimbal_controller_Y.e_x >= 0.05);

  /* Switch: '<S2>/Switch' */
  if (gimbal_controller_Y.beam_valid) {
    /* Switch: '<S2>/Switch' incorporates:
     *  Inport: '<Root>/L'
     *  Inport: '<Root>/R'
     *  Product: '<S2>/Divide'
     *  Sum: '<S2>/Add1'
     */
    gimbal_controller_Y.e_x = (gimbal_controller_U.R - gimbal_controller_U.L) /
      gimbal_controller_B.S_safe;
  } else {
    /* Switch: '<S2>/Switch' incorporates:
     *  Constant: '<S2>/Constant'
     */
    gimbal_controller_Y.e_x = 0.0;
  }

  /* End of Switch: '<S2>/Switch' */

  /* Gain: '<S210>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S202>/Filter'
   *  Gain: '<S200>/Derivative Gain'
   *  Sum: '<S202>/SumD'
   */
  gimbal_controller_B.FilterCoefficient = (0.0 * gimbal_controller_Y.e_x -
    gimbal_controller_DW.Filter_DSTATE) * 10.0;

  /* Sum: '<S216>/Sum' incorporates:
   *  DiscreteIntegrator: '<S207>/Integrator'
   *  Gain: '<S212>/Proportional Gain'
   */
  gimbal_controller_B.Filter_i = (0.05 * gimbal_controller_Y.e_x +
    gimbal_controller_DW.Integrator_DSTATE) +
    gimbal_controller_B.FilterCoefficient;

  /* Saturate: '<S214>/Saturation' */
  if (gimbal_controller_B.Filter_i > 1.5) {
    gimbal_controller_B.Saturation = 1.5;
  } else if (gimbal_controller_B.Filter_i < -1.5) {
    gimbal_controller_B.Saturation = -1.5;
  } else {
    gimbal_controller_B.Saturation = gimbal_controller_B.Filter_i;
  }

  /* End of Saturate: '<S214>/Saturation' */

  /* Sum: '<S199>/SumI2' */
  gimbal_controller_B.SumI2 = gimbal_controller_B.Saturation -
    gimbal_controller_B.Filter_i;

  /* Sum: '<S3>/Add' incorporates:
   *  Constant: '<S3>/search_step'
   *  Product: '<S3>/Product'
   *  UnitDelay: '<S3>/theta_search_memory'
   *  UnitDelay: '<S3>/theta_search_yaw_memory'
   */
  gimbal_controller_DW.theta_search_memory_DSTATE +=
    gimbal_controller_DW.theta_search_yaw_memory_DSTATE * 0.002;

  /* Switch: '<Root>/Switch' incorporates:
   *  UnitDelay: '<S3>/theta_search_memory'
   */
  if (gimbal_controller_Y.beam_valid) {
    /* Saturate: '<S5>/Saturation' */
    if (gimbal_controller_B.Saturation > 0.15) {
      gimbal_controller_B.Filter_i = 0.15;
    } else if (gimbal_controller_B.Saturation < -0.15) {
      gimbal_controller_B.Filter_i = -0.15;
    } else {
      gimbal_controller_B.Filter_i = gimbal_controller_B.Saturation;
    }

    /* End of Saturate: '<S5>/Saturation' */
  } else {
    gimbal_controller_B.Filter_i =
      gimbal_controller_DW.theta_search_memory_DSTATE;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Sum: '<S4>/Sum' incorporates:
   *  Inport: '<Root>/theta_meas_yaw'
   */
  gimbal_controller_B.Filter_i -= gimbal_controller_U.theta_meas_yaw;

  /* Gain: '<S52>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S44>/Filter'
   *  Gain: '<S42>/Derivative Gain'
   *  Sum: '<S44>/SumD'
   */
  gimbal_controller_B.Saturation = (0.1 * gimbal_controller_B.Filter_i -
    gimbal_controller_DW.Filter_DSTATE_k) * 10.0;

  /* Sum: '<S58>/Sum' incorporates:
   *  DiscreteIntegrator: '<S49>/Integrator'
   *  Gain: '<S54>/Proportional Gain'
   */
  rtb_Integrator_pd = (2.0 * gimbal_controller_B.Filter_i +
                       gimbal_controller_DW.Integrator_DSTATE_f) +
    gimbal_controller_B.Saturation;

  /* Saturate: '<S56>/Saturation' */
  if (rtb_Integrator_pd > 1.5) {
    /* Abs: '<S1>/Abs1' */
    gimbal_controller_Y.e_y = 1.5;
  } else if (rtb_Integrator_pd < -1.5) {
    /* Abs: '<S1>/Abs1' */
    gimbal_controller_Y.e_y = -1.5;
  } else {
    /* Abs: '<S1>/Abs1' */
    gimbal_controller_Y.e_y = rtb_Integrator_pd;
  }

  /* End of Saturate: '<S56>/Saturation' */

  /* Sum: '<S41>/SumI2' */
  rtb_Integrator_pd = gimbal_controller_Y.e_y - rtb_Integrator_pd;

  /* Saturate: '<S4>/Saturation' */
  if (gimbal_controller_Y.e_y > 1.0) {
    /* Outport: '<Root>/omega_cmd_yaw' */
    gimbal_controller_Y.omega_cmd_yaw = 1.0;
  } else if (gimbal_controller_Y.e_y < -1.0) {
    /* Outport: '<Root>/omega_cmd_yaw' */
    gimbal_controller_Y.omega_cmd_yaw = -1.0;
  } else {
    /* Outport: '<Root>/omega_cmd_yaw' */
    gimbal_controller_Y.omega_cmd_yaw = gimbal_controller_Y.e_y;
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* RelationalOperator: '<S10>/Compare' incorporates:
   *  Constant: '<S10>/Constant'
   *  UnitDelay: '<S3>/theta_search_memory'
   */
  rtb_Compare = (gimbal_controller_DW.theta_search_memory_DSTATE >= 0.2);

  /* RelationalOperator: '<S11>/Compare' incorporates:
   *  Constant: '<S11>/Constant'
   *  UnitDelay: '<S3>/theta_search_memory'
   */
  rtb_Compare_g = (gimbal_controller_DW.theta_search_memory_DSTATE <= -0.2);

  /* Switch: '<S3>/Switch2' incorporates:
   *  Logic: '<S3>/OR'
   */
  if (rtb_Compare || rtb_Compare_g) {
    /* Abs: '<S1>/Abs1' incorporates:
     *  Constant: '<S3>/search_step_pitch'
     *  Sum: '<S3>/Add1'
     *  UnitDelay: '<S3>/theta_search_pitch_memory'
     */
    gimbal_controller_Y.e_y =
      gimbal_controller_DW.theta_search_pitch_memory_DSTAT + 0.01;
  } else {
    /* Abs: '<S1>/Abs1' incorporates:
     *  UnitDelay: '<S3>/theta_search_pitch_memory'
     */
    gimbal_controller_Y.e_y =
      gimbal_controller_DW.theta_search_pitch_memory_DSTAT;
  }

  /* End of Switch: '<S3>/Switch2' */

  /* Switch: '<S3>/Switch3' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S3>/Constant2'
   *  RelationalOperator: '<S12>/Compare'
   *  UnitDelay: '<S3>/theta_search_pitch_memory'
   */
  if (gimbal_controller_Y.e_y >= 0.1) {
    gimbal_controller_DW.theta_search_pitch_memory_DSTAT = -0.1;
  } else {
    gimbal_controller_DW.theta_search_pitch_memory_DSTAT =
      gimbal_controller_Y.e_y;
  }

  /* End of Switch: '<S3>/Switch3' */

  /* Switch: '<S2>/Switch1' */
  if (gimbal_controller_Y.beam_valid) {
    /* Abs: '<S1>/Abs1' incorporates:
     *  Inport: '<Root>/D'
     *  Inport: '<Root>/U'
     *  Product: '<S2>/Divide1'
     *  Sum: '<S2>/Add2'
     */
    gimbal_controller_Y.e_y = (gimbal_controller_U.U - gimbal_controller_U.D) /
      gimbal_controller_B.S_safe;
  } else {
    /* Abs: '<S1>/Abs1' incorporates:
     *  Constant: '<S2>/Constant2'
     */
    gimbal_controller_Y.e_y = 0.0;
  }

  /* End of Switch: '<S2>/Switch1' */

  /* Gain: '<S158>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S150>/Filter'
   *  Gain: '<S148>/Derivative Gain'
   *  Sum: '<S150>/SumD'
   */
  gimbal_controller_B.S_safe = (0.0 * gimbal_controller_Y.e_y -
    gimbal_controller_DW.Filter_DSTATE_a) * 10.0;

  /* Sum: '<S164>/Sum' incorporates:
   *  DiscreteIntegrator: '<S155>/Integrator'
   *  Gain: '<S160>/Proportional Gain'
   */
  rtb_Sum = (0.05 * gimbal_controller_Y.e_y +
             gimbal_controller_DW.Integrator_DSTATE_a) +
    gimbal_controller_B.S_safe;

  /* Saturate: '<S162>/Saturation' */
  if (rtb_Sum > 1.5) {
    rtb_Saturation_b = 1.5;
  } else if (rtb_Sum < -1.5) {
    rtb_Saturation_b = -1.5;
  } else {
    rtb_Saturation_b = rtb_Sum;
  }

  /* End of Saturate: '<S162>/Saturation' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  UnitDelay: '<S3>/theta_search_pitch_memory'
   */
  if (gimbal_controller_Y.beam_valid) {
    /* Saturate: '<S5>/Saturation1' */
    if (rtb_Saturation_b > 0.15) {
      rtb_Sum2 = 0.15;
    } else if (rtb_Saturation_b < -0.15) {
      rtb_Sum2 = -0.15;
    } else {
      rtb_Sum2 = rtb_Saturation_b;
    }

    /* End of Saturate: '<S5>/Saturation1' */
  } else {
    rtb_Sum2 = gimbal_controller_DW.theta_search_pitch_memory_DSTAT;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Sum: '<S4>/Sum2' incorporates:
   *  Inport: '<Root>/theta_meas_pitch'
   */
  rtb_Sum2 -= gimbal_controller_U.theta_meas_pitch;

  /* Gain: '<S104>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S96>/Filter'
   *  Gain: '<S94>/Derivative Gain'
   *  Sum: '<S96>/SumD'
   */
  rtb_FilterCoefficient_p = (0.1 * rtb_Sum2 -
    gimbal_controller_DW.Filter_DSTATE_ke) * 10.0;

  /* Sum: '<S110>/Sum' incorporates:
   *  DiscreteIntegrator: '<S101>/Integrator'
   *  Gain: '<S106>/Proportional Gain'
   */
  rtb_Sum_g = (2.0 * rtb_Sum2 + gimbal_controller_DW.Integrator_DSTATE_b) +
    rtb_FilterCoefficient_p;

  /* Saturate: '<S108>/Saturation' */
  if (rtb_Sum_g > 1.5) {
    rtb_Abs = 1.5;
  } else if (rtb_Sum_g < -1.5) {
    rtb_Abs = -1.5;
  } else {
    rtb_Abs = rtb_Sum_g;
  }

  /* End of Saturate: '<S108>/Saturation' */

  /* Saturate: '<S4>/Saturation1' */
  if (rtb_Abs > 1.0) {
    /* Outport: '<Root>/omega_cmd_pitch' */
    gimbal_controller_Y.omega_cmd_pitch = 1.0;
  } else if (rtb_Abs < -1.0) {
    /* Outport: '<Root>/omega_cmd_pitch' */
    gimbal_controller_Y.omega_cmd_pitch = -1.0;
  } else {
    /* Outport: '<Root>/omega_cmd_pitch' */
    gimbal_controller_Y.omega_cmd_pitch = rtb_Abs;
  }

  /* End of Saturate: '<S4>/Saturation1' */

  /* Switch: '<S1>/Switch' incorporates:
   *  Abs: '<S1>/Abs'
   *  Abs: '<S1>/Abs1'
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  Logic: '<S1>/AND'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   *  Sum: '<S1>/Add'
   *  UnitDelay: '<S1>/lock_counter_memory'
   */
  if ((fabs(gimbal_controller_Y.e_x) < 0.02) && (fabs(gimbal_controller_Y.e_y) <
       0.02) && gimbal_controller_Y.beam_valid) {
    gimbal_controller_Y.lock_counter++;
  } else {
    gimbal_controller_Y.lock_counter = 0.0;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Outport: '<Root>/comm_enabled' incorporates:
   *  Constant: '<S8>/Constant'
   *  RelationalOperator: '<S8>/Compare'
   *  UnitDelay: '<S1>/lock_counter_memory'
   */
  gimbal_controller_Y.comm_enabled = (gimbal_controller_Y.lock_counter >= 100.0);

  /* Switch: '<S3>/Switch1' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Switch: '<S3>/Switch'
   *  UnitDelay: '<S3>/theta_search_yaw_memory'
   */
  if (rtb_Compare_g) {
    gimbal_controller_DW.theta_search_yaw_memory_DSTATE = 1.0;
  } else if (rtb_Compare) {
    /* Switch: '<S3>/Switch' incorporates:
     *  Constant: '<S3>/Constant'
     *  UnitDelay: '<S3>/theta_search_yaw_memory'
     */
    gimbal_controller_DW.theta_search_yaw_memory_DSTATE = -1.0;
  }

  /* End of Switch: '<S3>/Switch1' */

  /* Update for DiscreteIntegrator: '<S207>/Integrator' incorporates:
   *  Gain: '<S204>/Integral Gain'
   *  Sum: '<S199>/SumI4'
   */
  gimbal_controller_DW.Integrator_DSTATE += 0.01 * gimbal_controller_Y.e_x +
    gimbal_controller_B.SumI2;

  /* Update for DiscreteIntegrator: '<S202>/Filter' */
  gimbal_controller_DW.Filter_DSTATE += 0.005 *
    gimbal_controller_B.FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S49>/Integrator' incorporates:
   *  Gain: '<S46>/Integral Gain'
   *  Sum: '<S41>/SumI4'
   */
  gimbal_controller_DW.Integrator_DSTATE_f += 0.3 * gimbal_controller_B.Filter_i
    + rtb_Integrator_pd;

  /* Update for DiscreteIntegrator: '<S44>/Filter' */
  gimbal_controller_DW.Filter_DSTATE_k += 0.005 * gimbal_controller_B.Saturation;

  /* Update for DiscreteIntegrator: '<S155>/Integrator' incorporates:
   *  Gain: '<S152>/Integral Gain'
   *  Sum: '<S147>/SumI2'
   *  Sum: '<S147>/SumI4'
   */
  gimbal_controller_DW.Integrator_DSTATE_a += (rtb_Saturation_b - rtb_Sum) +
    0.01 * gimbal_controller_Y.e_y;

  /* Update for DiscreteIntegrator: '<S150>/Filter' */
  gimbal_controller_DW.Filter_DSTATE_a += 0.005 * gimbal_controller_B.S_safe;

  /* Update for DiscreteIntegrator: '<S101>/Integrator' incorporates:
   *  Gain: '<S98>/Integral Gain'
   *  Sum: '<S93>/SumI2'
   *  Sum: '<S93>/SumI4'
   */
  gimbal_controller_DW.Integrator_DSTATE_b += (rtb_Abs - rtb_Sum_g) + 0.3 *
    rtb_Sum2;

  /* Update for DiscreteIntegrator: '<S96>/Filter' */
  gimbal_controller_DW.Filter_DSTATE_ke += 0.005 * rtb_FilterCoefficient_p;
}

/* Model initialize function */
void gimbal_controller_initialize(void)
{
  /* InitializeConditions for UnitDelay: '<S3>/theta_search_yaw_memory' */
  gimbal_controller_DW.theta_search_yaw_memory_DSTATE = 1.0;

  /* InitializeConditions for UnitDelay: '<S3>/theta_search_pitch_memory' */
  gimbal_controller_DW.theta_search_pitch_memory_DSTAT = -0.1;
}

/* Model terminate function */
void gimbal_controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
