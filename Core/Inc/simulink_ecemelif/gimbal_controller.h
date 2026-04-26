/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: gimbal_controller.h
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

#ifndef gimbal_controller_h_
#define gimbal_controller_h_
#ifndef gimbal_controller_COMMON_INCLUDES_
#define gimbal_controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* gimbal_controller_COMMON_INCLUDES_ */

#include "gimbal_controller_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T S_safe;                       /* '<S2>/MinMax' */
  real_T FilterCoefficient;            /* '<S210>/Filter Coefficient' */
  real_T Filter_i;                     /* '<S150>/Filter' */
  real_T Saturation;                   /* '<S214>/Saturation' */
  real_T SumI2;                        /* '<S199>/SumI2' */
} B_gimbal_controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S207>/Integrator' */
  real_T Filter_DSTATE;                /* '<S202>/Filter' */
  real_T theta_search_yaw_memory_DSTATE;/* '<S3>/theta_search_yaw_memory' */
  real_T theta_search_memory_DSTATE;   /* '<S3>/theta_search_memory' */
  real_T Integrator_DSTATE_f;          /* '<S49>/Integrator' */
  real_T Filter_DSTATE_k;              /* '<S44>/Filter' */
  real_T theta_search_pitch_memory_DSTAT;/* '<S3>/theta_search_pitch_memory' */
  real_T Integrator_DSTATE_a;          /* '<S155>/Integrator' */
  real_T Filter_DSTATE_a;              /* '<S150>/Filter' */
  real_T Integrator_DSTATE_b;          /* '<S101>/Integrator' */
  real_T Filter_DSTATE_ke;             /* '<S96>/Filter' */
} DW_gimbal_controller_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T L;                            /* '<Root>/L' */
  real_T R;                            /* '<Root>/R' */
  real_T U;                            /* '<Root>/U' */
  real_T D;                            /* '<Root>/D' */
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

/* Block signals (default storage) */
extern B_gimbal_controller_T gimbal_controller_B;

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
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S41>/Kb' : Eliminated nontunable gain of 1
 * Block '<S93>/Kb' : Eliminated nontunable gain of 1
 * Block '<S147>/Kb' : Eliminated nontunable gain of 1
 * Block '<S199>/Kb' : Eliminated nontunable gain of 1
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
 * '<S12>'  : 'gimbal_controller/Search_Mode_Generator/Compare To Constant2'
 * '<S13>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller'
 * '<S14>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1'
 * '<S15>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Anti-windup'
 * '<S16>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/D Gain'
 * '<S17>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/External Derivative'
 * '<S18>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Filter'
 * '<S19>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Filter ICs'
 * '<S20>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/I Gain'
 * '<S21>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Ideal P Gain'
 * '<S22>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S23>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Integrator'
 * '<S24>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Integrator ICs'
 * '<S25>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/N Copy'
 * '<S26>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/N Gain'
 * '<S27>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/P Copy'
 * '<S28>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Parallel P Gain'
 * '<S29>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Reset Signal'
 * '<S30>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Saturation'
 * '<S31>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Saturation Fdbk'
 * '<S32>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Sum'
 * '<S33>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Sum Fdbk'
 * '<S34>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Tracking Mode'
 * '<S35>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Tracking Mode Sum'
 * '<S36>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Tsamp - Integral'
 * '<S37>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Tsamp - Ngain'
 * '<S38>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/postSat Signal'
 * '<S39>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/preInt Signal'
 * '<S40>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/preSat Signal'
 * '<S41>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Anti-windup/Back Calculation'
 * '<S42>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S43>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/External Derivative/Error'
 * '<S44>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S45>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S46>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S47>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S48>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S49>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Integrator/Discrete'
 * '<S50>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S51>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/N Copy/Disabled'
 * '<S52>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S53>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/P Copy/Disabled'
 * '<S54>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S55>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Reset Signal/Disabled'
 * '<S56>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Saturation/Enabled'
 * '<S57>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S58>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Sum/Sum_PID'
 * '<S59>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S60>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S61>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S62>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S63>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S64>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S65>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S66>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S67>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Anti-windup'
 * '<S68>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/D Gain'
 * '<S69>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/External Derivative'
 * '<S70>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Filter'
 * '<S71>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Filter ICs'
 * '<S72>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/I Gain'
 * '<S73>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Ideal P Gain'
 * '<S74>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S75>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Integrator'
 * '<S76>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Integrator ICs'
 * '<S77>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/N Copy'
 * '<S78>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/N Gain'
 * '<S79>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/P Copy'
 * '<S80>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Parallel P Gain'
 * '<S81>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Reset Signal'
 * '<S82>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Saturation'
 * '<S83>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Saturation Fdbk'
 * '<S84>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Sum'
 * '<S85>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Sum Fdbk'
 * '<S86>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Tracking Mode'
 * '<S87>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Tracking Mode Sum'
 * '<S88>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Tsamp - Integral'
 * '<S89>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Tsamp - Ngain'
 * '<S90>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/postSat Signal'
 * '<S91>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/preInt Signal'
 * '<S92>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/preSat Signal'
 * '<S93>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Anti-windup/Back Calculation'
 * '<S94>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S95>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/External Derivative/Error'
 * '<S96>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S97>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S98>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S99>'  : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S100>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S101>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Integrator/Discrete'
 * '<S102>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S103>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/N Copy/Disabled'
 * '<S104>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/N Gain/Internal Parameters'
 * '<S105>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/P Copy/Disabled'
 * '<S106>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S107>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S108>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Saturation/Enabled'
 * '<S109>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S110>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Sum/Sum_PID'
 * '<S111>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S112>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S113>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S114>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S115>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S116>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S117>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S118>' : 'gimbal_controller/Stabilization_controller/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S119>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1'
 * '<S120>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2'
 * '<S121>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Anti-windup'
 * '<S122>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/D Gain'
 * '<S123>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/External Derivative'
 * '<S124>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Filter'
 * '<S125>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Filter ICs'
 * '<S126>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/I Gain'
 * '<S127>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Ideal P Gain'
 * '<S128>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S129>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Integrator'
 * '<S130>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Integrator ICs'
 * '<S131>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/N Copy'
 * '<S132>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/N Gain'
 * '<S133>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/P Copy'
 * '<S134>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Parallel P Gain'
 * '<S135>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Reset Signal'
 * '<S136>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Saturation'
 * '<S137>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Saturation Fdbk'
 * '<S138>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Sum'
 * '<S139>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Sum Fdbk'
 * '<S140>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Tracking Mode'
 * '<S141>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Tracking Mode Sum'
 * '<S142>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Tsamp - Integral'
 * '<S143>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Tsamp - Ngain'
 * '<S144>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/postSat Signal'
 * '<S145>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/preInt Signal'
 * '<S146>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/preSat Signal'
 * '<S147>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Anti-windup/Back Calculation'
 * '<S148>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S149>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/External Derivative/Error'
 * '<S150>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S151>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S152>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S153>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S154>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S155>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Integrator/Discrete'
 * '<S156>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S157>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/N Copy/Disabled'
 * '<S158>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/N Gain/Internal Parameters'
 * '<S159>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/P Copy/Disabled'
 * '<S160>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S161>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S162>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Saturation/Enabled'
 * '<S163>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S164>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Sum/Sum_PID'
 * '<S165>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S166>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S167>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S168>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S169>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S170>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S171>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/preInt Signal/Internal PreInt'
 * '<S172>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S173>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Anti-windup'
 * '<S174>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/D Gain'
 * '<S175>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/External Derivative'
 * '<S176>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Filter'
 * '<S177>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Filter ICs'
 * '<S178>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/I Gain'
 * '<S179>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Ideal P Gain'
 * '<S180>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Ideal P Gain Fdbk'
 * '<S181>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Integrator'
 * '<S182>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Integrator ICs'
 * '<S183>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/N Copy'
 * '<S184>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/N Gain'
 * '<S185>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/P Copy'
 * '<S186>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Parallel P Gain'
 * '<S187>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Reset Signal'
 * '<S188>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Saturation'
 * '<S189>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Saturation Fdbk'
 * '<S190>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Sum'
 * '<S191>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Sum Fdbk'
 * '<S192>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Tracking Mode'
 * '<S193>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Tracking Mode Sum'
 * '<S194>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Tsamp - Integral'
 * '<S195>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Tsamp - Ngain'
 * '<S196>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/postSat Signal'
 * '<S197>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/preInt Signal'
 * '<S198>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/preSat Signal'
 * '<S199>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Anti-windup/Back Calculation'
 * '<S200>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/D Gain/Internal Parameters'
 * '<S201>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/External Derivative/Error'
 * '<S202>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Filter/Disc. Forward Euler Filter'
 * '<S203>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Filter ICs/Internal IC - Filter'
 * '<S204>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/I Gain/Internal Parameters'
 * '<S205>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Ideal P Gain/Passthrough'
 * '<S206>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S207>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Integrator/Discrete'
 * '<S208>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Integrator ICs/Internal IC'
 * '<S209>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/N Copy/Disabled'
 * '<S210>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/N Gain/Internal Parameters'
 * '<S211>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/P Copy/Disabled'
 * '<S212>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S213>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Reset Signal/Disabled'
 * '<S214>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Saturation/Enabled'
 * '<S215>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Saturation Fdbk/Disabled'
 * '<S216>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Sum/Sum_PID'
 * '<S217>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Sum Fdbk/Disabled'
 * '<S218>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Tracking Mode/Disabled'
 * '<S219>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S220>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S221>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S222>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/postSat Signal/Forward_Path'
 * '<S223>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/preInt Signal/Internal PreInt'
 * '<S224>' : 'gimbal_controller/Tracking_Controller/Discrete PID Controller2/preSat Signal/Forward_Path'
 */
#endif                                 /* gimbal_controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
