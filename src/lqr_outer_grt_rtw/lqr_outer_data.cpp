/*
 * lqr_outer_data.cpp
 *
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * Code generation for model "lqr_outer".
 *
 * Model version              : 1.560
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C++ source code generated on : Thu Jan 18 14:17:51 2018
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objective: Execution efficiency
 * Validation result: Passed (1), Warnings (3), Error (0)
 */

#include "lqr_outer.h"
#include "lqr_outer_private.h"

/* Constant parameters (auto storage) */
const ConstP_lqr_outer_T lqr_outer_ConstP = {
  /* Expression: [mass*gra 0 0 0]'
   * Referenced by: '<Root>/              '
   */
  { 15.141735000000002, 0.0, 0.0, 0.0 },

  /* Expression: Ki_lqr
   * Referenced by: '<S1>/ '
   */
  { 9.999999999999984, -0.0, -0.0, -0.0, -0.0, 1.4142135623730989, -0.0, -0.0,
    -0.0, -0.0, 1.4142135623730929, -0.0, -0.0, -0.0, -0.0, 0.031622776601683875
  },

  /* Expression: Kx_lqr
   * Referenced by: '<S1>/                   '
   */
  { 13.693372885111996, 0.0, 0.0, 0.0, 6.8754230485360539, 0.0, 0.0, 0.0, 0.0,
    0.83503792561070767, 0.0, 0.0, 0.0, 0.0, 0.913060511985932, 0.0, 0.0, 0.0,
    0.0, 0.099118361810886346, 0.0, 0.2429931219351836, 0.0, 0.0, 0.0, 0.0,
    0.29121467947381752, 0.0, 0.0, 0.0, 0.0, 0.1395267999269216 },

  /* Expression: B_ENU_inv
   * Referenced by: '<Root>/Gain'
   */
  { 0.16666666666666674, 0.16666666666666669, 0.16666666666666671,
    0.16666666666666671, 0.16666666666666674, 0.16666666666666671,
    0.77519379844961245, 1.5503875968992242, 0.77519379844961234,
    -0.775193798449612, -1.5503875968992249, -0.77519379844961223,
    -1.3426750446270366, 7.0851742975913985E-16, 1.3426750446270364,
    1.3426750446270364, -4.8647282483410855E-16, -1.3426750446270366,
    -10.416666666666663, 10.416666666666663, -10.416666666666655,
    10.416666666666657, -10.416666666666661, 10.416666666666661 },

  /* Expression: Kxo_lqr
   * Referenced by: '<S3>/                   '
   */
  { 0.47821928763789895, 0.0, 0.0, 0.47821928763790095, 0.97802790107225246, 0.0,
    0.0, 0.97802790107225612 }
};
