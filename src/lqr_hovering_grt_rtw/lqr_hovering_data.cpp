/*
 * lqr_hovering_data.cpp
 *
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * Code generation for model "lqr_hovering".
 *
 * Model version              : 1.520
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C++ source code generated on : Mon Jan 15 14:01:12 2018
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objective: Execution efficiency
 * Validation result: Passed (1), Warnings (3), Error (0)
 */

#include "lqr_hovering.h"
#include "lqr_hovering_private.h"

/* Constant parameters (auto storage) */
const ConstP_lqr_hovering_T lqr_hovering_ConstP = {
  /* Expression: [mass*gra 0 0 0]'
   * Referenced by: '<Root>/              '
   */
  { 15.141735000000002, 0.0, 0.0, 0.0 },

  /* Expression: Ki_lqr
   * Referenced by: '<Root>/ '
   */
  { -0.0, -0.0, 0.31622776601682878, -0.0, -0.0, -0.31622776601683983, -0.0,
    -0.0, 10.00000000000002, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    0.031622776601683784 },

  /* Expression: Kx_lqr
   * Referenced by: '<Root>/                   '
   */
  { 0.0, 0.0, 0.58535094418501865, 0.0, 0.0, -0.5724754418822311, 0.0, 0.0,
    13.693372885112046, 0.0, 0.0, 0.0, 0.0, 0.0, 0.46269771238671381, 0.0, 0.0,
    -0.4391267330134847, 0.0, 0.0, 6.875423048536061, 0.0, 0.0, 0.0, 0.0,
    1.8130916329319566, 0.0, 0.0, 0.0, 0.0, 1.9891558282137727, 0.0, 0.0, 0.0,
    0.0, 0.12151586108810278, 0.0, 0.36882612901385659, 0.0, 0.0, 0.0, 0.0,
    0.43883511598009456, 0.0, 0.0, 0.0, 0.0, 0.15441567037258644 },

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
    10.416666666666657, -10.416666666666661, 10.416666666666661 }
};
