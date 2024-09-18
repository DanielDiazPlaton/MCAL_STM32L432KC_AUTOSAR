/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PCCI.h
 *
 * Code generated for Simulink model 'PCCI'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Aug 28 17:41:25 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef PCCI_h_
#define PCCI_h_
#ifndef PCCI_COMMON_INCLUDES_
#define PCCI_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* PCCI_COMMON_INCLUDES_ */

#include "PCCI_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint16_T percRawVal_U16;             /* '<Root>/percRawVal_U16' */
} ExtU_PCCI_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T indicatorLamp_B;           /* '<Root>/indicatorLamp_B' */
} ExtY_PCCI_T;

/* Real-time Model Data Structure */
struct tag_RTM_PCCI_T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_PCCI_T PCCI_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_PCCI_T PCCI_Y;

/* Model entry point functions */
extern void PCCI_initialize(void);
extern void PCCI_step(void);
extern void PCCI_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PCCI_T *const PCCI_M;

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
 * '<Root>' : 'PCCI'
 * '<S1>'   : 'PCCI/calculatePercentFunc'
 */
#endif                                 /* PCCI_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
