/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DOIO.h
 *
 * Code generated for Simulink model 'DOIO'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Aug 13 19:31:38 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef DOIO_h_
#define DOIO_h_
#ifndef DOIO_COMMON_INCLUDES_
#define DOIO_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* DOIO_COMMON_INCLUDES_ */

#include "DOIO_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  boolean_T ctrlSW_B;                  /* '<Root>/ctrlSW_B' */
} ExtU_DOIO_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T IndicatorLamp_B;           /* '<Root>/IndicatorLamp_B' */
} ExtY_DOIO_T;

/* Real-time Model Data Structure */
struct tag_RTM_DOIO_T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_DOIO_T DOIO_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_DOIO_T DOIO_Y;

/* Model entry point functions */
extern void DOIO_initialize(void);
extern void DOIO_step(void);
extern void DOIO_terminate(void);

/* Real-time Model object */
extern RT_MODEL_DOIO_T *const DOIO_M;

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
 * '<Root>' : 'DOIO'
 * '<S1>'   : 'DOIO/indicatorLampFunc'
 */
#endif                                 /* DOIO_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
