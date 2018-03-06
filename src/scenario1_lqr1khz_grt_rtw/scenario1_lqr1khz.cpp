/*
 * scenario1_lqr1khz.cpp
 *
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * Code generation for model "scenario1_lqr1khz".
 *
 * Model version              : 1.769
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C++ source code generated on : Mon Mar  5 19:51:09 2018
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objective: Execution efficiency
 * Validation result: Passed (1), Warnings (3), Error (0)
 */

#include "scenario1_lqr1khz.h"
#include "scenario1_lqr1khz_private.h"

/*
 * This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
void scenario1_lqr1khzModelClass::rt_ertODEUpdateContinuousStates(RTWSolverInfo *
  si )
{
  /* Solver Matrices */
  static const real_T rt_ODE5_A[6] = {
    1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
  };

  static const real_T rt_ODE5_B[6][6] = {
    { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

    { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

    { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

    { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0,
      0.0 },

    { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  scenario1_lqr1khz_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  scenario1_lqr1khz_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  this->step();
  scenario1_lqr1khz_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  this->step();
  scenario1_lqr1khz_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++) {
    hB[i] = h * rt_ODE5_B[3][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  this->step();
  scenario1_lqr1khz_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++) {
    hB[i] = h * rt_ODE5_B[4][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  this->step();
  scenario1_lqr1khz_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++) {
    hB[i] = h * rt_ODE5_B[5][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void scenario1_lqr1khzModelClass::step()
{
  real_T psi;
  real_T rtb_VectorConcatenate[12];
  real_T rtb_Sum1_g;
  real_T rtb_Sum1_c;
  real_T rtb_Sum3_f;
  int32_T i;
  real_T rtb_ref_idx_0;
  real_T rtb_Sqrt1;
  real_T rtb_rads_to_RPM;
  if (rtmIsMajorTimeStep((&scenario1_lqr1khz_M))) {
    /* set solver stop time */
    if (!((&scenario1_lqr1khz_M)->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&(&scenario1_lqr1khz_M)->solverInfo,
                            (((&scenario1_lqr1khz_M)->Timing.clockTickH0 + 1) *
        (&scenario1_lqr1khz_M)->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&(&scenario1_lqr1khz_M)->solverInfo,
                            (((&scenario1_lqr1khz_M)->Timing.clockTick0 + 1) * (
        &scenario1_lqr1khz_M)->Timing.stepSize0 + (&scenario1_lqr1khz_M)
        ->Timing.clockTickH0 * (&scenario1_lqr1khz_M)->Timing.stepSize0 *
        4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&scenario1_lqr1khz_M))) {
    (&scenario1_lqr1khz_M)->Timing.t[0] = rtsiGetT(&(&scenario1_lqr1khz_M)
      ->solverInfo);
  }

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Inport: '<Root>/X0'
   */
  rtb_VectorConcatenate[0] = scenario1_lqr1khz_U.X0[0];
  rtb_VectorConcatenate[1] = scenario1_lqr1khz_U.X0[1];
  rtb_VectorConcatenate[2] = scenario1_lqr1khz_U.X0[2];

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn2' */
  for (i = 0; i < 5; i++) {
    rtb_VectorConcatenate[i + 3] = 0.0;
  }

  /* End of SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn2' */

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn3' incorporates:
   *  Inport: '<Root>/X0'
   */
  rtb_VectorConcatenate[8] = scenario1_lqr1khz_U.X0[3];

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn4' */
  rtb_VectorConcatenate[9] = 0.0;
  rtb_VectorConcatenate[10] = 0.0;
  rtb_VectorConcatenate[11] = 0.0;

  /* Sum: '<Root>/Sum' incorporates:
   *  Inport: '<Root>/X'
   */
  for (i = 0; i < 12; i++) {
    rtb_VectorConcatenate[i] = scenario1_lqr1khz_U.X[i] -
      rtb_VectorConcatenate[i];
  }

  /* End of Sum: '<Root>/Sum' */

  /* Sum: '<S5>/Sum1' incorporates:
   *  Gain: '<S5>/ '
   *  Gain: '<S5>/                    '
   *  Integrator: '<S5>/Integrator1'
   *  SignalConversion: '<S5>/TmpSignal ConversionAt                    Inport1'
   */
  rtb_Sum1_g = 0.17320508075688992 * scenario1_lqr1khz_X.Integrator1_CSTATE_h -
    (0.32349951352987977 * rtb_VectorConcatenate[0] + 0.2732366014912751 *
     rtb_VectorConcatenate[3]);

  /* Sum: '<S6>/Sum1' incorporates:
   *  Gain: '<S6>/  '
   *  Gain: '<S6>/                     '
   *  Integrator: '<S6>/Integrator1'
   *  SignalConversion: '<S6>/TmpSignal ConversionAt                     Inport1'
   */
  rtb_Sum1_c = -0.173205080756885 * scenario1_lqr1khz_X.Integrator1_CSTATE_j - (
    -0.31312578517366968 * rtb_VectorConcatenate[1] + -0.25417198201077484 *
    rtb_VectorConcatenate[4]);

  /* Fcn: '<Root>/Fcn1' incorporates:
   *  Inport: '<Root>/X'
   */
  psi = rtb_Sum1_c * std::cos(scenario1_lqr1khz_U.X[8]) + rtb_Sum1_g * std::sin
    (scenario1_lqr1khz_U.X[8]);

  /* Saturate: '<S2>/roll' */
  if (psi > 0.52359877559829882) {
    psi = 0.52359877559829882;
  } else {
    if (psi < -0.52359877559829882) {
      psi = -0.52359877559829882;
    }
  }

  /* End of Saturate: '<S2>/roll' */

  /* Sum: '<S2>/Sum1' incorporates:
   *  Gain: '<S2>/                    '
   *  SignalConversion: '<S2>/TmpSignal ConversionAt                    Inport1'
   */
  rtb_Sum3_f = psi - (1.1365283480217869 * rtb_VectorConcatenate[6] +
                      0.28178545108770103 * rtb_VectorConcatenate[9]);

  /* Fcn: '<Root>/Fcn' incorporates:
   *  Inport: '<Root>/X'
   */
  rtb_Sum1_g = -rtb_Sum1_c * std::sin(scenario1_lqr1khz_U.X[8]) + rtb_Sum1_g *
    std::cos(scenario1_lqr1khz_U.X[8]);

  /* Sum: '<Root>/Sum2' incorporates:
   *  Gain: '<S7>/  '
   *  Gain: '<S7>/                     '
   *  Integrator: '<S7>/Integrator1'
   *  SignalConversion: '<S7>/TmpSignal ConversionAt                     Inport1'
   *  Sum: '<S7>/Sum1'
   */
  rtb_ref_idx_0 = 10.000000000000018 * scenario1_lqr1khz_X.Integrator1_CSTATE -
    (12.219481695651957 * rtb_VectorConcatenate[2] + 6.215786645518647 *
     rtb_VectorConcatenate[5]);

  /* Sum: '<S4>/Sum1' incorporates:
   *  Saturate: '<S4>/pitch'
   */
  if (rtb_Sum1_g > 0.52359877559829882) {
    rtb_Sum1_g = 0.52359877559829882;
  } else {
    if (rtb_Sum1_g < -0.52359877559829882) {
      rtb_Sum1_g = -0.52359877559829882;
    }
  }

  /* Sum: '<Root>/Sum2' incorporates:
   *  Gain: '<S3>/  '
   *  Gain: '<S3>/                     '
   *  Gain: '<S4>/                    '
   *  Integrator: '<S3>/Integrator1'
   *  SignalConversion: '<S3>/TmpSignal ConversionAt                     Inport1'
   *  SignalConversion: '<S4>/TmpSignal ConversionAt                    Inport1'
   *  Sum: '<S3>/Sum1'
   *  Sum: '<S4>/Sum1'
   */
  rtb_Sum1_g -= 1.2859205994736729 * rtb_VectorConcatenate[7] +
    0.34413551249350854 * rtb_VectorConcatenate[10];
  rtb_Sum1_c = 0.15811388300841925 * scenario1_lqr1khz_X.Integrator1_CSTATE_b -
    (0.3035552054947866 * rtb_VectorConcatenate[8] + 0.24395632222527311 *
     rtb_VectorConcatenate[11]);

  /* Outport: '<Root>/virtual_control' incorporates:
   *  Sum: '<Root>/Sum2'
   */
  scenario1_lqr1khz_Y.virtual_control[0] = rtb_ref_idx_0 + 15.107400000000002;
  scenario1_lqr1khz_Y.virtual_control[1] = rtb_Sum3_f;
  scenario1_lqr1khz_Y.virtual_control[2] = rtb_Sum1_g;
  scenario1_lqr1khz_Y.virtual_control[3] = rtb_Sum1_c;
  for (i = 0; i < 6; i++) {
    /* Gain: '<Root>/                 ' incorporates:
     *  Gain: '<Root>/      '
     *  Sum: '<Root>/Sum2'
     */
    psi = scenario1_lqr1khz_ConstP._Gain_m[i + 18] * rtb_Sum1_c +
      (scenario1_lqr1khz_ConstP._Gain_m[i + 12] * rtb_Sum1_g +
       (scenario1_lqr1khz_ConstP._Gain_m[i + 6] * rtb_Sum3_f + (rtb_ref_idx_0 +
         15.107400000000002) * scenario1_lqr1khz_ConstP._Gain_m[i]));

    /* Sqrt: '<Root>/Sqrt1' incorporates:
     *  Gain: '<Root>/      '
     */
    rtb_Sqrt1 = std::sqrt(116978.4923343994 * psi);

    /* Gain: '<Root>/rads_to_RPM' */
    rtb_rads_to_RPM = 9.5493 * rtb_Sqrt1;

    /* Gain: '<Root>/mapping_0_200' incorporates:
     *  Constant: '<Root>/Constant '
     *  Sum: '<Root>/Sum3'
     */
    psi = (rtb_rads_to_RPM - 1250.0) * 0.022857142857142857;

    /* Saturate: '<Root>/Saturation' */
    if (psi > 200.0) {
      /* Outport: '<Root>/motor_command' */
      scenario1_lqr1khz_Y.motor_command[i] = 200.0;
    } else if (psi < 0.0) {
      /* Outport: '<Root>/motor_command' */
      scenario1_lqr1khz_Y.motor_command[i] = 0.0;
    } else {
      /* Outport: '<Root>/motor_command' */
      scenario1_lqr1khz_Y.motor_command[i] = psi;
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* Outport: '<Root>/motor_speed' */
    scenario1_lqr1khz_Y.motor_speed[i] = rtb_Sqrt1;

    /* Outport: '<Root>/motor_RPM' */
    scenario1_lqr1khz_Y.motor_RPM[i] = rtb_rads_to_RPM;
  }

  /* Clock: '<Root>/Clock' */
  rtb_Sum1_g = (&scenario1_lqr1khz_M)->Timing.t[0];

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Inport: '<Root>/X0'
   */
  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  /* '<S1>:1:2' x = X0(1); */
  /* '<S1>:1:2' y = X0(2); */
  /* '<S1>:1:2' z = X0(3); */
  /* '<S1>:1:2' psi = X0(4); */
  /* '<S1>:1:3' if t <= 20 */
  if (rtb_Sum1_g <= 20.0) {
    /* '<S1>:1:4' x = X0(1); */
    rtb_Sum1_g = scenario1_lqr1khz_U.X0[0];

    /* '<S1>:1:5' y = X0(2); */
    rtb_Sum1_c = scenario1_lqr1khz_U.X0[1];

    /* '<S1>:1:6' z = 0.75; */
    rtb_Sum3_f = 0.75;

    /* '<S1>:1:7' psi = X0(4); */
    psi = scenario1_lqr1khz_U.X0[3];
  } else if (rtb_Sum1_g <= 35.0) {
    /* '<S1>:1:8' elseif t<=35 */
    /* '<S1>:1:9' x = X0(1)-1; */
    rtb_Sum1_g = scenario1_lqr1khz_U.X0[0] - 1.0;

    /* '<S1>:1:10' y = X0(2); */
    rtb_Sum1_c = scenario1_lqr1khz_U.X0[1];

    /* '<S1>:1:11' z = 0.75; */
    rtb_Sum3_f = 0.75;

    /* '<S1>:1:12' psi = X0(4); */
    psi = scenario1_lqr1khz_U.X0[3];
  } else if (rtb_Sum1_g <= 50.0) {
    /* '<S1>:1:13' elseif t<=50 */
    /* '<S1>:1:14' x = X0(1)-1; */
    rtb_Sum1_g = scenario1_lqr1khz_U.X0[0] - 1.0;

    /* '<S1>:1:15' y = X0(2)+1; */
    rtb_Sum1_c = scenario1_lqr1khz_U.X0[1] + 1.0;

    /* '<S1>:1:16' z = 0.75; */
    rtb_Sum3_f = 0.75;

    /* '<S1>:1:17' psi = X0(4); */
    psi = scenario1_lqr1khz_U.X0[3];
  } else if (rtb_Sum1_g <= 80.0) {
    /* '<S1>:1:18' elseif t<=80 */
    /* '<S1>:1:19' x = X0(1)-1; */
    rtb_Sum1_g = scenario1_lqr1khz_U.X0[0] - 1.0;

    /* '<S1>:1:20' y = X0(2)+1; */
    rtb_Sum1_c = scenario1_lqr1khz_U.X0[1] + 1.0;

    /* '<S1>:1:21' z = 0.75; */
    rtb_Sum3_f = 0.75;

    /* '<S1>:1:22' psi = X0(4)+pi/2; */
    psi = scenario1_lqr1khz_U.X0[3] + 1.5707963267948966;
  } else {
    /* '<S1>:1:23' else */
    /* '<S1>:1:24' x = X0(1)-1; */
    rtb_Sum1_g = scenario1_lqr1khz_U.X0[0] - 1.0;

    /* '<S1>:1:25' y = X0(2)+1; */
    rtb_Sum1_c = scenario1_lqr1khz_U.X0[1] + 1.0;

    /* '<S1>:1:26' z = 0.0; */
    rtb_Sum3_f = 0.0;

    /* '<S1>:1:27' psi = X0(4)+pi/2; */
    psi = scenario1_lqr1khz_U.X0[3] + 1.5707963267948966;
  }

  /* Outport: '<Root>/ref' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  /* '<S1>:1:29' ref = [x;y;z;psi]; */
  scenario1_lqr1khz_Y.ref[0] = rtb_Sum1_g;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Inport: '<Root>/X0'
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  rtb_ref_idx_0 = rtb_Sum1_g - scenario1_lqr1khz_U.X0[0];

  /* Outport: '<Root>/ref' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  scenario1_lqr1khz_Y.ref[1] = rtb_Sum1_c;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Inport: '<Root>/X0'
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  rtb_Sum1_g = rtb_Sum1_c - scenario1_lqr1khz_U.X0[1];

  /* Outport: '<Root>/ref' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  scenario1_lqr1khz_Y.ref[2] = rtb_Sum3_f;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Inport: '<Root>/X0'
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  rtb_Sum3_f -= scenario1_lqr1khz_U.X0[2];

  /* Outport: '<Root>/ref' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  scenario1_lqr1khz_Y.ref[3] = psi;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Inport: '<Root>/X0'
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  psi -= scenario1_lqr1khz_U.X0[3];

  /* Saturate: '<S3>/yaw' */
  if (psi > 3.1415926535897931) {
    psi = 3.1415926535897931;
  } else {
    if (psi < -3.1415926535897931) {
      psi = -3.1415926535897931;
    }
  }

  /* End of Saturate: '<S3>/yaw' */

  /* Sum: '<S3>/Sum3' */
  psi -= rtb_VectorConcatenate[8];

  /* Saturate: '<S3>/psi_e' */
  if (psi > 0.78539816339744828) {
    scenario1_lqr1khz_B.psi_e = 0.78539816339744828;
  } else if (psi < -0.78539816339744828) {
    scenario1_lqr1khz_B.psi_e = -0.78539816339744828;
  } else {
    scenario1_lqr1khz_B.psi_e = psi;
  }

  /* End of Saturate: '<S3>/psi_e' */

  /* Saturate: '<S5>/x' */
  if (rtb_ref_idx_0 > 1.0) {
    rtb_ref_idx_0 = 1.0;
  } else {
    if (rtb_ref_idx_0 < -1.0) {
      rtb_ref_idx_0 = -1.0;
    }
  }

  /* End of Saturate: '<S5>/x' */

  /* Sum: '<S5>/Sum3' */
  psi = rtb_ref_idx_0 - rtb_VectorConcatenate[0];

  /* Saturate: '<S5>/xe' */
  if (psi > 1.0) {
    scenario1_lqr1khz_B.xe = 1.0;
  } else if (psi < -1.0) {
    scenario1_lqr1khz_B.xe = -1.0;
  } else {
    scenario1_lqr1khz_B.xe = psi;
  }

  /* End of Saturate: '<S5>/xe' */

  /* Saturate: '<S6>/y' */
  if (rtb_Sum1_g > 1.0) {
    rtb_Sum1_g = 1.0;
  } else {
    if (rtb_Sum1_g < -1.0) {
      rtb_Sum1_g = -1.0;
    }
  }

  /* End of Saturate: '<S6>/y' */

  /* Sum: '<S6>/Sum3' */
  psi = rtb_Sum1_g - rtb_VectorConcatenate[1];

  /* Saturate: '<S6>/ye' */
  if (psi > 1.0) {
    scenario1_lqr1khz_B.ye = 1.0;
  } else if (psi < -1.0) {
    scenario1_lqr1khz_B.ye = -1.0;
  } else {
    scenario1_lqr1khz_B.ye = psi;
  }

  /* End of Saturate: '<S6>/ye' */

  /* Saturate: '<S7>/z' */
  if (rtb_Sum3_f > 1.0) {
    rtb_Sum3_f = 1.0;
  } else {
    if (rtb_Sum3_f < 0.0) {
      rtb_Sum3_f = 0.0;
    }
  }

  /* End of Saturate: '<S7>/z' */

  /* Sum: '<S7>/Sum3' */
  psi = rtb_Sum3_f - rtb_VectorConcatenate[2];

  /* Saturate: '<S7>/ze' */
  if (psi > 0.5) {
    scenario1_lqr1khz_B.ze = 0.5;
  } else if (psi < -0.5) {
    scenario1_lqr1khz_B.ze = -0.5;
  } else {
    scenario1_lqr1khz_B.ze = psi;
  }

  /* End of Saturate: '<S7>/ze' */
  if (rtmIsMajorTimeStep((&scenario1_lqr1khz_M))) {
    rt_ertODEUpdateContinuousStates(&(&scenario1_lqr1khz_M)->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++(&scenario1_lqr1khz_M)->Timing.clockTick0)) {
      ++(&scenario1_lqr1khz_M)->Timing.clockTickH0;
    }

    (&scenario1_lqr1khz_M)->Timing.t[0] = rtsiGetSolverStopTime
      (&(&scenario1_lqr1khz_M)->solverInfo);

    {
      /* Update absolute timer for sample time: [0.005s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.005, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      (&scenario1_lqr1khz_M)->Timing.clockTick1++;
      if (!(&scenario1_lqr1khz_M)->Timing.clockTick1) {
        (&scenario1_lqr1khz_M)->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void scenario1_lqr1khzModelClass::scenario1_lqr1khz_derivatives()
{
  XDot_scenario1_lqr1khz_T *_rtXdot;
  _rtXdot = ((XDot_scenario1_lqr1khz_T *) (&scenario1_lqr1khz_M)->derivs);

  /* Derivatives for Integrator: '<S7>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = scenario1_lqr1khz_B.ze;

  /* Derivatives for Integrator: '<S5>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_h = scenario1_lqr1khz_B.xe;

  /* Derivatives for Integrator: '<S6>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_j = scenario1_lqr1khz_B.ye;

  /* Derivatives for Integrator: '<S3>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_b = scenario1_lqr1khz_B.psi_e;
}

/* Model initialize function */
void scenario1_lqr1khzModelClass::initialize()
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)(&scenario1_lqr1khz_M), 0,
                sizeof(RT_MODEL_scenario1_lqr1khz_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&scenario1_lqr1khz_M)->solverInfo,
                          &(&scenario1_lqr1khz_M)->Timing.simTimeStep);
    rtsiSetTPtr(&(&scenario1_lqr1khz_M)->solverInfo, &rtmGetTPtr
                ((&scenario1_lqr1khz_M)));
    rtsiSetStepSizePtr(&(&scenario1_lqr1khz_M)->solverInfo,
                       &(&scenario1_lqr1khz_M)->Timing.stepSize0);
    rtsiSetdXPtr(&(&scenario1_lqr1khz_M)->solverInfo, &(&scenario1_lqr1khz_M)
                 ->derivs);
    rtsiSetContStatesPtr(&(&scenario1_lqr1khz_M)->solverInfo, (real_T **)
                         &(&scenario1_lqr1khz_M)->contStates);
    rtsiSetNumContStatesPtr(&(&scenario1_lqr1khz_M)->solverInfo,
      &(&scenario1_lqr1khz_M)->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&scenario1_lqr1khz_M)->solverInfo,
      &(&scenario1_lqr1khz_M)->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&scenario1_lqr1khz_M)->solverInfo,
      &(&scenario1_lqr1khz_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&scenario1_lqr1khz_M)->solverInfo,
      &(&scenario1_lqr1khz_M)->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&scenario1_lqr1khz_M)->solverInfo,
                          (&rtmGetErrorStatus((&scenario1_lqr1khz_M))));
    rtsiSetRTModelPtr(&(&scenario1_lqr1khz_M)->solverInfo, (&scenario1_lqr1khz_M));
  }

  rtsiSetSimTimeStep(&(&scenario1_lqr1khz_M)->solverInfo, MAJOR_TIME_STEP);
  (&scenario1_lqr1khz_M)->intgData.y = (&scenario1_lqr1khz_M)->odeY;
  (&scenario1_lqr1khz_M)->intgData.f[0] = (&scenario1_lqr1khz_M)->odeF[0];
  (&scenario1_lqr1khz_M)->intgData.f[1] = (&scenario1_lqr1khz_M)->odeF[1];
  (&scenario1_lqr1khz_M)->intgData.f[2] = (&scenario1_lqr1khz_M)->odeF[2];
  (&scenario1_lqr1khz_M)->intgData.f[3] = (&scenario1_lqr1khz_M)->odeF[3];
  (&scenario1_lqr1khz_M)->intgData.f[4] = (&scenario1_lqr1khz_M)->odeF[4];
  (&scenario1_lqr1khz_M)->intgData.f[5] = (&scenario1_lqr1khz_M)->odeF[5];
  getRTM()->contStates = ((X_scenario1_lqr1khz_T *) &scenario1_lqr1khz_X);
  rtsiSetSolverData(&(&scenario1_lqr1khz_M)->solverInfo, (void *)
                    &(&scenario1_lqr1khz_M)->intgData);
  rtsiSetSolverName(&(&scenario1_lqr1khz_M)->solverInfo,"ode5");
  rtmSetTPtr(getRTM(), &(&scenario1_lqr1khz_M)->Timing.tArray[0]);
  (&scenario1_lqr1khz_M)->Timing.stepSize0 = 0.005;

  /* block I/O */
  (void) memset(((void *) &scenario1_lqr1khz_B), 0,
                sizeof(B_scenario1_lqr1khz_T));

  /* states (continuous) */
  {
    (void) memset((void *)&scenario1_lqr1khz_X, 0,
                  sizeof(X_scenario1_lqr1khz_T));
  }

  /* external inputs */
  (void)memset((void *)&scenario1_lqr1khz_U, 0, sizeof(ExtU_scenario1_lqr1khz_T));

  /* external outputs */
  (void) memset((void *)&scenario1_lqr1khz_Y, 0,
                sizeof(ExtY_scenario1_lqr1khz_T));

  /* InitializeConditions for Integrator: '<S7>/Integrator1' */
  scenario1_lqr1khz_X.Integrator1_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S5>/Integrator1' */
  scenario1_lqr1khz_X.Integrator1_CSTATE_h = 0.0;

  /* InitializeConditions for Integrator: '<S6>/Integrator1' */
  scenario1_lqr1khz_X.Integrator1_CSTATE_j = 0.0;

  /* InitializeConditions for Integrator: '<S3>/Integrator1' */
  scenario1_lqr1khz_X.Integrator1_CSTATE_b = 0.0;
}

/* Model terminate function */
void scenario1_lqr1khzModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
scenario1_lqr1khzModelClass::scenario1_lqr1khzModelClass()
{
}

/* Destructor */
scenario1_lqr1khzModelClass::~scenario1_lqr1khzModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_scenario1_lqr1khz_T * scenario1_lqr1khzModelClass::getRTM()
{
  return (&scenario1_lqr1khz_M);
}
