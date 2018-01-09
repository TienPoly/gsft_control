/*
 * lqr_identification_data.cpp
 *
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * Code generation for model "lqr_identification".
 *
 * Model version              : 1.524
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C++ source code generated on : Tue Jan  9 13:04:46 2018
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objective: Execution efficiency
 * Validation result: Passed (1), Warnings (3), Error (0)
 */

#include "lqr_identification.h"
#include "lqr_identification_private.h"

/* Constant parameters (auto storage) */
const ConstP_lqr_identification_T lqr_identification_ConstP = {
  /* Expression: [mass*gra 0 0 0]'
   * Referenced by: '<Root>/              '
   */
  { 14.679084052499999, 0.0, 0.0, 0.0 },

  /* Expression: Ki_lqr
   * Referenced by: '<Root>/ '
   */
  { -0.0, -0.0, 0.070710678118655654, -0.0, -0.0, -0.070710678118655529, -0.0,
    -0.0, 8.66025403784446, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    0.0070710678118654615 },

  /* Expression: Kx_lqr
   * Referenced by: '<Root>/                   '
   */
  { 0.0, 0.0, 0.34819385127905428, 0.0, 0.0, -0.34632220227728128, 0.0, 0.0,
    13.600014649902779, 0.0, 0.0, 0.0, 0.0, 0.0, 0.503735503349274, 0.0, 0.0,
    -0.4945438910430468, 0.0, 0.0, 7.791942239096354, 0.0, 0.0, 0.0, 0.0,
    2.1488737063542938, 0.0, 0.0, 0.0, 0.0, 2.2780293631016675, 0.0, 0.0, 0.0,
    0.0, 0.040017289903298545, 0.0, 0.49937340578000788, 0.0, 0.0, 0.0, 0.0,
    0.5559593038305749, 0.0, 0.0, 0.0, 0.0, 0.099092776967368137 },

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
