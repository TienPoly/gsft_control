/*
 * lqr_outer_data.cpp
 *
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * Code generation for model "lqr_outer".
 *
 * Model version              : 1.540
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C++ source code generated on : Thu Jan 11 18:24:43 2018
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
  { 14.715, 0.0, 0.0, 0.0 },

  /* Expression: Ki_lqr
   * Referenced by: '<S1>/ '
   */
  { 3.1622776601683844, -0.0, -0.0, -0.0, -0.0, 1.4142135623731, -0.0, -0.0,
    -0.0, -0.0, 1.4142135623730938, -0.0, -0.0, -0.0, -0.0, 0.022360679774997897
  },

  /* Expression: Kx_lqr
   * Referenced by: '<S1>/                   '
   */
  { 6.1569071256520767, 0.0, 0.0, 0.0, 4.4125640365842047, 0.0, 0.0, 0.0, 0.0,
    0.84735286755264017, 0.0, 0.0, 0.0, 0.0, 0.92370083734550157, 0.0, 0.0, 0.0,
    0.0, 0.10751094505248825, 0.0, 0.24678269984145915, 0.0, 0.0, 0.0, 0.0,
    0.2945889005316164, 0.0, 0.0, 0.0, 0.0, 0.14665482829847848 },

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
  { 0.0, 0.042699914198735672, -0.042699914198735756, 0.0, 0.0,
    0.093570215120754474, -0.093570215120754585, 0.0 }
};