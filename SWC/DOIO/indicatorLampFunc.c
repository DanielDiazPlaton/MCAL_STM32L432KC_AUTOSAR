/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: indicatorLampFunc.c
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

#include "rtwtypes.h"
#include "indicatorLampFunc.h"

/* Output and update for atomic system: '<Root>/indicatorLampFunc' */
boolean_T DOIO_indicatorLampFunc(boolean_T rtu_ctrlSW_B)
{
  /* Switch: '<S1>/Switch' */
  return rtu_ctrlSW_B;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
