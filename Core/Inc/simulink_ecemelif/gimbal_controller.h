/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: gimbal_controller.h
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

#ifndef gimbal_controller_h_
#define gimbal_controller_h_
#ifndef gimbal_controller_COMMON_INCLUDES_
#define gimbal_controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* gimbal_controller_COMMON_INCLUDES_ */

#include "gimbal_controller_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S206>/Integrator' */
  real_T Filter_DSTATE;                /* '<S201>/Filter' */
  real_T dir_memory_DSTATE;            /* '<S3>/dir_memory' */
  real_T theta_search_memory_DSTATE;   /* '<S3>/theta_search_memory' */
  real_T Integrator_DSTATE_f;          /* '<S48>/Integrator' */
  real_T Filter_DSTATE_k;              /* '<S43>/Filter' */
  real_T Integrator_DSTATE_a;          /* '<S154>/Integrator' */
  real_T Filter_DSTATE_a;              /* '<S149>/Filter' */
  real_T Integrator_DSTATE_b;          /* '<S100>/Integrator' */
  real_T Filter_DSTATE_ke;             /* '<S95>/Filter' */
} DW_gimbal_controller_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Q1;                           /* '<Root>/Q1' */
  real_T Q2;                           /* '<Root>/Q2' */
  real_T Q3;                           /* '<Root>/Q3' */
  real_T Q4;                           /* '<Root>/Q4' */
  real_T theta_meas_yaw;               /* '<Root>/theta_meas_yaw' */
  real_T theta_meas_pitch;             /* '<Root>/theta_meas_pitch' */
} ExtU_gimbal_controller_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T omega_cmd_yaw;                /* '<Root>/omega_cmd_yaw' */
  real_T omega_cmd_pitch;              /* '<Root>/omega_cmd_pitch' */
  boolean_T beam_valid;                /* '<Root>/beam_valid' */
  real_T e_x;                          /* '<Root>/e_x' */
  real_T e_y;                          /* '<Root>/e_y' */
  boolean_T comm_enabled;              /* '<Root>/comm_enabled' */
  real_T lock_counter;                 /* '<Root>/lock_counter' */
} ExtY_gimbal_controller_T;

/* Real-time Model Data Structure */
struct tag_RTM_gimbal_controller_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_gimbal_controller_T gimbal_controller_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_gimbal_controller_T gimbal_controller_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_gimbal_controller_T gimbal_controller_Y;

/* Model entry point functions */
extern void gimbal_controller_initialize(void);
extern void gimbal_controller_step(void);
extern void gimbal_controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_gimbal_controller_T *const gimbal_controller_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S40>/Kb' : Eliminated nontunable gain of 1
 * Block '<S92>/Kb' : Eliminated nontunable gain of 1
 * Block '<S146>/Kb' : Eliminated nontunable gain of 1
 * Block '<S198>/Kb' : Eliminated nontunable gain of 1
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'gimbal_controller'
 * '<S1>'   : 'gimbal_controller/Lock_Detection'
 * '<S2>'   : 'gimbal_controller/Photodiode_Signal_Processing'
 * '<S3>'   : 'gimbal_controller/Search_Mode_Generator'
 * '<S4>'   : 'gimbal_controller/Stabilization_controller'
 * '<S5>'   : 'gimbal_controller/Tracking_Controller'
 * '<S6>'   : 'gimbal_controller/Lock_Detection/Compare To Constant'
 * '<S7>'   : 'gimbal_controller/Lock_Detection/Compare To Constant1'
 * '<S8>'   : 'gimbal_controller/Lock_Detection/Compare To Constant2'
 * '<S9>'   : 'gimbal_controller/Photodiode_Signal_Processing/Compare To Constant'
 * '<S10>'  : 'gimbal_controller/Search_Mode_Generator/Compare To Constant'
 * '<S11>'  : 'gimbal_controller/Search_Mode_Generator/Compare To Constant1'
 * '<S12>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller'
 * '<S13>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1'
 * '<S14>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Anti-windup'
 * '<S15>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/D Gain'
 * '<S16>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/External Derivative'
 * '<S17>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Filter'
 * '<S18>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Filter ICs'
 * '<S19>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/I Gain'
 * '<S20>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Ideal P Gain'
 * '<S21>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S22>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Integrator'
 * '<S23>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Integrator ICs'
 * '<S24>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/N Copy'
 * '<S25>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/N Gain'
 * '<S26>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/P Copy'
 * '<S27>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Parallel P Gain'
 * '<S28>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Reset Signal'
 * '<S29>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Saturation'
 * '<S30>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Saturation Fdbk'
 * '<S31>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Sum'
 * '<S32>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Sum Fdbk'
 * '<S33>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Tracking Mode'
 * '<S34>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Tracking Mode Sum'
 * '<S35>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Tsamp - Integral'
 * '<S36>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Tsamp - Ngain'
 * '<S37>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/postSat Signal'
 * '<S38>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/preInt Signal'
 * '<S39>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/preSat Signal'
 * '<S40>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Anti-windup/Back Calculation'
 * '<S41>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S42>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/External Derivative/Error'
 * '<S43>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S44>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S45>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S46>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S47>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S48>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Integrator/Discrete'
 * '<S49>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S50>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/N Copy/Disabled'
 * '<S51>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S52>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/P Copy/Disabled'
 * '<S53>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S54>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Reset Signal/Disabled'
 * '<S55>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Saturation/Enabled'
 * '<S56>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S57>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Sum/Sum_PID'
 * '<S58>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S59>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S60>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S61>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S62>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S63>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S64>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S65>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S66>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Anti-windup'
 * '<S67>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/D Gain'
 * '<S68>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/External Derivative'
 * '<S69>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Filter'
 * '<S70>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Filter ICs'
 * '<S71>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/I Gain'
 * '<S72>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Ideal P Gain'
 * '<S73>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S74>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Integrator'
 * '<S75>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Integrator ICs'
 * '<S76>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/N Copy'
 * '<S77>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/N Gain'
 * '<S78>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/P Copy'
 * '<S79>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Parallel P Gain'
 * '<S80>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Reset Signal'
 * '<S81>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Saturation'
 * '<S82>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Saturation Fdbk'
 * '<S83>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Sum'
 * '<S84>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Sum Fdbk'
 * '<S85>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Tracking Mode'
 * '<S86>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Tracking Mode Sum'
 * '<S87>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Tsamp - Integral'
 * '<S88>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Tsamp - Ngain'
 * '<S89>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/postSat Signal'
 * '<S90>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/preInt Signal'
 * '<S91>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/preSat Signal'
 * '<S92>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Anti-windup/Back Calculation'
 * '<S93>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S94>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/External Derivative/Error'
 * '<S95>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S96>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S97>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S98>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S99>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S100>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Integrator/Discrete'
 * '<S101>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S102>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/N Copy/Disabled'
 * '<S103>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/N Gain/Internal Parameters'
 * '<S104>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/P Copy/Disabled'
 * '<S105>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S106>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S107>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Saturation/Enabled'
 * '<S108>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S109>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Sum/Sum_PID'
 * '<S110>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S111>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S112>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S113>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S114>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S115>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S116>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S117>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S118>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1'
 * '<S119>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2'
 * '<S120>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Anti-windup'
 * '<S121>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/D Gain'
 * '<S122>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/External Derivative'
 * '<S123>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Filter'
 * '<S124>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Filter ICs'
 * '<S125>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/I Gain'
 * '<S126>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Ideal P Gain'
 * '<S127>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S128>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Integrator'
 * '<S129>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Integrator ICs'
 * '<S130>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/N Copy'
 * '<S131>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/N Gain'
 * '<S132>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/P Copy'
 * '<S133>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Parallel P Gain'
 * '<S134>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Reset Signal'
 * '<S135>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Saturation'
 * '<S136>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Saturation Fdbk'
 * '<S137>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Sum'
 * '<S138>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Sum Fdbk'
 * '<S139>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Tracking Mode'
 * '<S140>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Tracking Mode Sum'
 * '<S141>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Tsamp - Integral'
 * '<S142>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Tsamp - Ngain'
 * '<S143>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/postSat Signal'
 * '<S144>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/preInt Signal'
 * '<S145>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/preSat Signal'
 * '<S146>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Anti-windup/Back Calculation'
 * '<S147>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S148>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/External Derivative/Error'
 * '<S149>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S150>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S151>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S152>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S153>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S154>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Integrator/Discrete'
 * '<S155>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S156>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/N Copy/Disabled'
 * '<S157>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/N Gain/Internal Parameters'
 * '<S158>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/P Copy/Disabled'
 * '<S159>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S160>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S161>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Saturation/Enabled'
 * '<S162>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S163>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Sum/Sum_PID'
 * '<S164>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S165>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S166>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S167>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S168>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S169>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S170>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S171>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S172>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Anti-windup'
 * '<S173>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/D Gain'
 * '<S174>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/External Derivative'
 * '<S175>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Filter'
 * '<S176>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Filter ICs'
 * '<S177>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/I Gain'
 * '<S178>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Ideal P Gain'
 * '<S179>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Ideal P Gain Fdbk'
 * '<S180>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Integrator'
 * '<S181>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Integrator ICs'
 * '<S182>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/N Copy'
 * '<S183>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/N Gain'
 * '<S184>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/P Copy'
 * '<S185>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Parallel P Gain'
 * '<S186>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Reset Signal'
 * '<S187>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Saturation'
 * '<S188>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Saturation Fdbk'
 * '<S189>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Sum'
 * '<S190>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Sum Fdbk'
 * '<S191>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Tracking Mode'
 * '<S192>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Tracking Mode Sum'
 * '<S193>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Tsamp - Integral'
 * '<S194>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Tsamp - Ngain'
 * '<S195>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/postSat Signal'
 * '<S196>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/preInt Signal'
 * '<S197>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/preSat Signal'
 * '<S198>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Anti-windup/Back Calculation'
 * '<S199>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/D Gain/Internal Parameters'
 * '<S200>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/External Derivative/Error'
 * '<S201>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Filter/Disc. Forward Euler Filter'
 * '<S202>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Filter ICs/Internal IC - Filter'
 * '<S203>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/I Gain/Internal Parameters'
 * '<S204>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Ideal P Gain/Passthrough'
 * '<S205>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S206>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Integrator/Discrete'
 * '<S207>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Integrator ICs/Internal IC'
 * '<S208>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/N Copy/Disabled'
 * '<S209>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/N Gain/Internal Parameters'
 * '<S210>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/P Copy/Disabled'
 * '<S211>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S212>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Reset Signal/Disabled'
 * '<S213>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Saturation/Enabled'
 * '<S214>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Saturation Fdbk/Disabled'
 * '<S215>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Sum/Sum_PID'
 * '<S216>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Sum Fdbk/Disabled'
 * '<S217>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Tracking Mode/Disabled'
 * '<S218>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S219>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S220>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S221>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/postSat Signal/Forward_Path'
 * '<S222>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/preInt Signal/Internal PreInt'
 * '<S223>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/preSat Signal/Forward_Path'
 */
#endif                                 /* gimbal_controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
