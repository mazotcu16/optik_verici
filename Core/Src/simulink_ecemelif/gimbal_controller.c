/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: gimbal_controller.c
 *
 * Code generated for Simulink model 'gimbal_controller'.
 *
 * Model version                  : 1.28
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue Apr  7 22:29:49 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "gimbal_controller.h"
#include <math.h>
#include "rtwtypes.h"

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
  real_T rtb_FilterCoefficient;
  real_T rtb_FilterCoefficient_b;
  real_T rtb_FilterCoefficient_mo;
  real_T rtb_Filter_p;
  real_T rtb_IntegralGain;
  real_T rtb_Integrator_e;
  real_T rtb_Integrator_k;
  real_T rtb_S_safe;
  real_T rtb_Saturation;
  real_T rtb_Saturation_f;
  real_T rtb_Sum;
  real_T rtb_SumI2;

  /* Sum: '<S2>/Sum' incorporates:
   *  Inport: '<Root>/Q1'
   *  Inport: '<Root>/Q2'
   *  Inport: '<Root>/Q3'
   *  Inport: '<Root>/Q4'
   *  Sum: '<S2>/Sum2'
   *  Switch: '<S2>/Switch1'
   */
  rtb_FilterCoefficient_mo = gimbal_controller_U.Q1 + gimbal_controller_U.Q2;
  rtb_Integrator_e = (rtb_FilterCoefficient_mo + gimbal_controller_U.Q3) +
    gimbal_controller_U.Q4;

  /* MinMax: '<S2>/MinMax' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  rtb_S_safe = fmax(rtb_Integrator_e, 0.05);

  /* RelationalOperator: '<S9>/Compare' incorporates:
   *  Constant: '<S9>/Constant'
   */
  gimbal_controller_Y.beam_valid = (rtb_Integrator_e >= 0.05);

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   *  Inport: '<Root>/Q1'
   *  Inport: '<Root>/Q2'
   *  Inport: '<Root>/Q3'
   *  Inport: '<Root>/Q4'
   *  Product: '<S2>/Divide'
   *  Sum: '<S2>/Sum1'
   */
  if (gimbal_controller_Y.beam_valid) {
    rtb_Integrator_e = (((gimbal_controller_U.Q1 + gimbal_controller_U.Q3) -
                         gimbal_controller_U.Q2) - gimbal_controller_U.Q4) /
      rtb_S_safe;
  } else {
    rtb_Integrator_e = 0.0;
  }

  /* End of Switch: '<S2>/Switch' */

  /* Gain: '<S209>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S201>/Filter'
   *  Gain: '<S199>/Derivative Gain'
   *  Sum: '<S201>/SumD'
   */
  rtb_FilterCoefficient = (0.0 * rtb_Integrator_e -
    gimbal_controller_DW.Filter_DSTATE) * 10.0;

  /* Sum: '<S215>/Sum' incorporates:
   *  DiscreteIntegrator: '<S206>/Integrator'
   *  Gain: '<S211>/Proportional Gain'
   */
  rtb_Filter_p = (0.05 * rtb_Integrator_e +
                  gimbal_controller_DW.Integrator_DSTATE) +
    rtb_FilterCoefficient;

  /* Saturate: '<S213>/Saturation' */
  if (rtb_Filter_p > 1.5) {
    rtb_Saturation = 1.5;
  } else if (rtb_Filter_p < -1.5) {
    rtb_Saturation = -1.5;
  } else {
    rtb_Saturation = rtb_Filter_p;
  }

  /* End of Saturate: '<S213>/Saturation' */

  /* Sum: '<S198>/SumI2' */
  rtb_SumI2 = rtb_Saturation - rtb_Filter_p;

  /* Gain: '<S203>/Integral Gain' */
  rtb_IntegralGain = 0.01 * rtb_Integrator_e;

  /* Sum: '<S3>/Add' incorporates:
   *  Constant: '<S3>/search_step'
   *  Product: '<S3>/Product'
   *  UnitDelay: '<S3>/dir_memory'
   *  UnitDelay: '<S3>/theta_search_memory'
   */
  gimbal_controller_DW.theta_search_memory_DSTATE +=
    gimbal_controller_DW.dir_memory_DSTATE * 0.002;

  /* Switch: '<Root>/Switch' incorporates:
   *  Saturate: '<S5>/Saturation'
   *  UnitDelay: '<S3>/theta_search_memory'
   */
  if (gimbal_controller_Y.beam_valid) {
    /* Saturate: '<S5>/Saturation' */
    if (rtb_Saturation > 0.15) {
      rtb_Filter_p = 0.15;
    } else if (rtb_Saturation < -0.15) {
      rtb_Filter_p = -0.15;
    } else {
      rtb_Filter_p = rtb_Saturation;
    }
  } else {
    rtb_Filter_p = gimbal_controller_DW.theta_search_memory_DSTATE;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Sum: '<S4>/Sum' incorporates:
   *  Inport: '<Root>/theta_meas_yaw'
   */
  rtb_Filter_p -= gimbal_controller_U.theta_meas_yaw;

  /* Gain: '<S51>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S43>/Filter'
   *  Gain: '<S41>/Derivative Gain'
   *  Sum: '<S43>/SumD'
   */
  rtb_Saturation = (0.1 * rtb_Filter_p - gimbal_controller_DW.Filter_DSTATE_k) *
    10.0;

  /* Sum: '<S57>/Sum' incorporates:
   *  DiscreteIntegrator: '<S48>/Integrator'
   *  Gain: '<S53>/Proportional Gain'
   */
  rtb_Integrator_k = (2.0 * rtb_Filter_p +
                      gimbal_controller_DW.Integrator_DSTATE_f) + rtb_Saturation;

  /* Saturate: '<S55>/Saturation' */
  if (rtb_Integrator_k > 1.5) {
    /* Switch: '<S2>/Switch1' */
    gimbal_controller_Y.e_y = 1.5;
  } else if (rtb_Integrator_k < -1.5) {
    /* Switch: '<S2>/Switch1' */
    gimbal_controller_Y.e_y = -1.5;
  } else {
    /* Switch: '<S2>/Switch1' */
    gimbal_controller_Y.e_y = rtb_Integrator_k;
  }

  /* End of Saturate: '<S55>/Saturation' */

  /* Sum: '<S40>/SumI2' */
  rtb_Integrator_k = gimbal_controller_Y.e_y - rtb_Integrator_k;

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

  /* Switch: '<S3>/Switch1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S11>/Constant'
   *  Constant: '<S3>/Constant1'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S11>/Compare'
   *  Switch: '<S3>/Switch'
   *  UnitDelay: '<S3>/dir_memory'
   *  UnitDelay: '<S3>/theta_search_memory'
   */
  if (gimbal_controller_DW.theta_search_memory_DSTATE <= -0.2) {
    gimbal_controller_DW.dir_memory_DSTATE = 1.0;
  } else if (gimbal_controller_DW.theta_search_memory_DSTATE >= 0.2) {
    /* Switch: '<S3>/Switch' incorporates:
     *  Constant: '<S3>/Constant'
     *  UnitDelay: '<S3>/dir_memory'
     */
    gimbal_controller_DW.dir_memory_DSTATE = -1.0;
  }

  /* End of Switch: '<S3>/Switch1' */

  /* Outport: '<Root>/e_x' */
  gimbal_controller_Y.e_x = rtb_Integrator_e;

  /* Switch: '<S2>/Switch1' */
  if (gimbal_controller_Y.beam_valid) {
    /* Switch: '<S2>/Switch1' incorporates:
     *  Inport: '<Root>/Q3'
     *  Inport: '<Root>/Q4'
     *  Product: '<S2>/Divide1'
     *  Sum: '<S2>/Sum2'
     */
    gimbal_controller_Y.e_y = ((rtb_FilterCoefficient_mo -
      gimbal_controller_U.Q3) - gimbal_controller_U.Q4) / rtb_S_safe;
  } else {
    /* Switch: '<S2>/Switch1' incorporates:
     *  Constant: '<S2>/Constant2'
     */
    gimbal_controller_Y.e_y = 0.0;
  }

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
  if ((fabs(rtb_Integrator_e) < 0.02) && (fabs(gimbal_controller_Y.e_y) < 0.02) &&
      gimbal_controller_Y.beam_valid) {
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

  /* Gain: '<S157>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S149>/Filter'
   *  Gain: '<S147>/Derivative Gain'
   *  Sum: '<S149>/SumD'
   */
  rtb_FilterCoefficient_mo = (0.0 * gimbal_controller_Y.e_y -
    gimbal_controller_DW.Filter_DSTATE_a) * 10.0;

  /* Sum: '<S163>/Sum' incorporates:
   *  DiscreteIntegrator: '<S154>/Integrator'
   *  Gain: '<S159>/Proportional Gain'
   */
  rtb_Integrator_e = (0.05 * gimbal_controller_Y.e_y +
                      gimbal_controller_DW.Integrator_DSTATE_a) +
    rtb_FilterCoefficient_mo;

  /* Saturate: '<S161>/Saturation' */
  if (rtb_Integrator_e > 1.5) {
    rtb_S_safe = 1.5;
  } else if (rtb_Integrator_e < -1.5) {
    rtb_S_safe = -1.5;
  } else {
    rtb_S_safe = rtb_Integrator_e;
  }

  /* End of Saturate: '<S161>/Saturation' */

  /* Sum: '<S146>/SumI2' */
  rtb_Integrator_e = rtb_S_safe - rtb_Integrator_e;

  /* Saturate: '<S5>/Saturation1' */
  if (rtb_S_safe > 0.15) {
    rtb_S_safe = 0.15;
  } else if (rtb_S_safe < -0.15) {
    rtb_S_safe = -0.15;
  }

  /* Sum: '<S4>/Sum2' incorporates:
   *  Inport: '<Root>/theta_meas_pitch'
   *  Saturate: '<S5>/Saturation1'
   */
  rtb_S_safe -= gimbal_controller_U.theta_meas_pitch;

  /* Gain: '<S103>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S95>/Filter'
   *  Gain: '<S93>/Derivative Gain'
   *  Sum: '<S95>/SumD'
   */
  rtb_FilterCoefficient_b = (0.1 * rtb_S_safe -
    gimbal_controller_DW.Filter_DSTATE_ke) * 10.0;

  /* Sum: '<S109>/Sum' incorporates:
   *  DiscreteIntegrator: '<S100>/Integrator'
   *  Gain: '<S105>/Proportional Gain'
   */
  rtb_Sum = (2.0 * rtb_S_safe + gimbal_controller_DW.Integrator_DSTATE_b) +
    rtb_FilterCoefficient_b;

  /* Saturate: '<S107>/Saturation' */
  if (rtb_Sum > 1.5) {
    rtb_Saturation_f = 1.5;
  } else if (rtb_Sum < -1.5) {
    rtb_Saturation_f = -1.5;
  } else {
    rtb_Saturation_f = rtb_Sum;
  }

  /* End of Saturate: '<S107>/Saturation' */

  /* Saturate: '<S4>/Saturation1' */
  if (rtb_Saturation_f > 1.0) {
    /* Outport: '<Root>/omega_cmd_pitch' */
    gimbal_controller_Y.omega_cmd_pitch = 1.0;
  } else if (rtb_Saturation_f < -1.0) {
    /* Outport: '<Root>/omega_cmd_pitch' */
    gimbal_controller_Y.omega_cmd_pitch = -1.0;
  } else {
    /* Outport: '<Root>/omega_cmd_pitch' */
    gimbal_controller_Y.omega_cmd_pitch = rtb_Saturation_f;
  }

  /* End of Saturate: '<S4>/Saturation1' */

  /* Update for DiscreteIntegrator: '<S206>/Integrator' incorporates:
   *  Sum: '<S198>/SumI4'
   */
  gimbal_controller_DW.Integrator_DSTATE += rtb_SumI2 + rtb_IntegralGain;

  /* Update for DiscreteIntegrator: '<S201>/Filter' */
  gimbal_controller_DW.Filter_DSTATE += 0.005 * rtb_FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S48>/Integrator' incorporates:
   *  Gain: '<S45>/Integral Gain'
   *  Sum: '<S40>/SumI4'
   */
  gimbal_controller_DW.Integrator_DSTATE_f += 0.3 * rtb_Filter_p +
    rtb_Integrator_k;

  /* Update for DiscreteIntegrator: '<S43>/Filter' */
  gimbal_controller_DW.Filter_DSTATE_k += 0.005 * rtb_Saturation;

  /* Update for DiscreteIntegrator: '<S154>/Integrator' incorporates:
   *  Gain: '<S151>/Integral Gain'
   *  Sum: '<S146>/SumI4'
   */
  gimbal_controller_DW.Integrator_DSTATE_a += 0.01 * gimbal_controller_Y.e_y +
    rtb_Integrator_e;

  /* Update for DiscreteIntegrator: '<S149>/Filter' */
  gimbal_controller_DW.Filter_DSTATE_a += 0.005 * rtb_FilterCoefficient_mo;

  /* Update for DiscreteIntegrator: '<S100>/Integrator' incorporates:
   *  Gain: '<S97>/Integral Gain'
   *  Sum: '<S92>/SumI2'
   *  Sum: '<S92>/SumI4'
   */
  gimbal_controller_DW.Integrator_DSTATE_b += (rtb_Saturation_f - rtb_Sum) + 0.3
    * rtb_S_safe;

  /* Update for DiscreteIntegrator: '<S95>/Filter' */
  gimbal_controller_DW.Filter_DSTATE_ke += 0.005 * rtb_FilterCoefficient_b;
}

/* Model initialize function */
void gimbal_controller_initialize(void)
{
  /* InitializeConditions for UnitDelay: '<S3>/dir_memory' */
  gimbal_controller_DW.dir_memory_DSTATE = 1.0;
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
