/*
 * tunning_nominal_data.cpp
 *
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * Code generation for model "tunning_nominal".
 *
 * Model version              : 1.1489
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C++ source code generated on : Wed Aug 22 15:30:20 2018
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objective: Execution efficiency
 * Validation result: Passed (1), Warnings (3), Error (0)
 */

#include "tunning_nominal.h"
#include "tunning_nominal_private.h"

/* Constant parameters (auto storage) */
const ConstP_tunning_nominal_T tunning_nominal_ConstP = {
  /* Expression: B_ENU_inv
   * Referenced by: '<Root>/Control Allocation'
   */
  { 0.16666666666666674, 0.16666666666666669, 0.16666666666666671,
    0.16666666666666671, 0.16666666666666674, 0.16666666666666671,
    0.77519379844962388, 1.5503875968992147, 0.77519379844962344,
    -0.77519379844962344, -1.5503875968992149, -0.77519379844962344,
    -1.3426750446270113, -2.5529533974250051E-14, 1.3426750446270619,
    1.3426750446270113, 2.5418511671787539E-14, -1.3426750446270626,
    -4.5662100456621, 4.5662100456621, -4.5662100456620989, 4.5662100456620971,
    -4.5662100456621006, 4.5662100456620989 },

  /* Expression: M_bias'
   * Referenced by: '<S2>/Constant'
   */
  { -0.01, -0.04, 0.0 },

  /* Expression: Ib
   * Referenced by: '<S2>/Constant1'
   */
  { 0.0347563, 0.0, 0.0, 0.0, 0.0458929, 0.0, 0.0, 0.0, 0.0977 },

  /* Expression: pInitialization.M
   * Referenced by: '<S16>/KalmanGainM'
   */
  { 0.0013828503617181014, 0.0, 0.0, 0.000956799230966391, 0.0, 0.0, 0.0,
    0.0030895047538060691, 0.0, 0.0, 0.004779906439668552, 0.0, 0.0, 0.0,
    0.0030895047538062703, 0.0, 0.0, 0.0047799064396673212 },

  /* Expression: pInitialization.C
   * Referenced by: '<S3>/C'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 },

  /* Expression: pInitialization.A
   * Referenced by: '<S3>/A'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 1.0 },

  /* Expression: pInitialization.L
   * Referenced by: '<S16>/KalmanGainL'
   */
  { 0.0013838071609490678, 0.0, 0.0, 0.000956799230966391, 0.0, 0.0, 0.0,
    0.0030942846602457375, 0.0, 0.0, 0.004779906439668552, 0.0, 0.0, 0.0,
    0.0030942846602459379, 0.0, 0.0, 0.0047799064396673212 }
};
