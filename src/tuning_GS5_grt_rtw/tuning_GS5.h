/*
 * tuning_GS5.h
 *
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * Code generation for model "tuning_GS5".
 *
 * Model version              : 1.1537
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C++ source code generated on : Mon Oct 29 23:06:09 2018
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objective: Execution efficiency
 * Validation result: Passed (1), Warnings (3), Error (0)
 */

#ifndef RTW_HEADER_tuning_GS5_h_
#define RTW_HEADER_tuning_GS5_h_
#include <cmath>
#include <string.h>
#ifndef tuning_GS5_COMMON_INCLUDES_
# define tuning_GS5_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* tuning_GS5_COMMON_INCLUDES_ */

#include "tuning_GS5_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Sum2;                         /* '<S57>/Sum2' */
  real_T Sum3;                         /* '<S57>/Sum3' */
  real_T T_outer[3];                   /* '<S5>/T_outer' */
  real_T Fcn1;                         /* '<S5>/Fcn1' */
  real_T Fcn;                          /* '<S5>/Fcn' */
  real_T u[6];                         /* '<Root>/                  ' */
  real_T Sum1;                         /* '<S57>/Sum1' */
  real_T Sum4;                         /* '<S57>/Sum4' */
  real_T Sum3_f;                       /* '<S60>/Sum3' */
  real_T Sum3_n;                       /* '<S61>/Sum3' */
  real_T Product2[6];                  /* '<S56>/Product2' */
  real_T Product3[6];                  /* '<S55>/Product3' */
} B_tuning_GS5_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T MemoryX_DSTATE[6];            /* '<S4>/MemoryX' */
  real_T Memory_PreviousInput[6];      /* '<S2>/Memory' */
  uint8_T icLoad;                      /* '<S4>/MemoryX' */
  boolean_T MeasurementUpdate_MODE;    /* '<S30>/MeasurementUpdate' */
  boolean_T EnabledSubsystem_MODE;     /* '<S35>/Enabled Subsystem' */
} DW_tuning_GS5_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S61>/Integrator1' */
  real_T Integrator1_CSTATE_f;         /* '<S57>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S57>/Integrator' */
  real_T Integrator1_CSTATE_a;         /* '<S60>/Integrator1' */
} X_tuning_GS5_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S61>/Integrator1' */
  real_T Integrator1_CSTATE_f;         /* '<S57>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S57>/Integrator' */
  real_T Integrator1_CSTATE_a;         /* '<S60>/Integrator1' */
} XDot_tuning_GS5_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<S61>/Integrator1' */
  boolean_T Integrator1_CSTATE_f;      /* '<S57>/Integrator1' */
  boolean_T Integrator_CSTATE;         /* '<S57>/Integrator' */
  boolean_T Integrator1_CSTATE_a;      /* '<S60>/Integrator1' */
} XDis_tuning_GS5_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: B_ENU_inv
   * Referenced by: '<Root>/Control Allocation'
   */
  real_T ControlAllocation_Gain[24];

  /* Expression: M_bias'
   * Referenced by: '<S2>/Constant'
   */
  real_T Constant_Value_g[3];

  /* Expression: Ib
   * Referenced by: '<S2>/Constant1'
   */
  real_T Constant1_Value[9];

  /* Expression: pInitialization.M
   * Referenced by: '<S12>/KalmanGainM'
   */
  real_T KalmanGainM_Value[18];

  /* Expression: pInitialization.C
   * Referenced by: '<S4>/C'
   */
  real_T C_Value[18];

  /* Expression: pInitialization.A
   * Referenced by: '<S4>/A'
   */
  real_T A_Value[36];

  /* Expression: pInitialization.L
   * Referenced by: '<S12>/KalmanGainL'
   */
  real_T KalmanGainL_Value[18];
} ConstP_tuning_GS5_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T X[12];                        /* '<Root>/X' */
  real_T Y0[4];                        /* '<Root>/Y0' */
  real_T mode;                         /* '<Root>/mode' */
  real_T mode1;                        /* '<Root>/mode1' */
  real_T ref[4];                       /* '<Root>/ref' */
  real_T LOE_t[6];                     /* '<Root>/LOE_t' */
  real_T LOE_a[6];                     /* '<Root>/LOE_a' */
  real_T gain[18];                     /* '<Root>/gain' */
} ExtU_tuning_GS5_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T motor_command[6];             /* '<Root>/motor_command' */
  real_T virtual_control[4];           /* '<Root>/virtual_control' */
  real_T ref_out[4];                   /* '<Root>/ref_out' */
  real_T LOE_true[6];                  /* '<Root>/LOE_true' */
  real_T LOE13_estimated[3];           /* '<Root>/LOE13_estimated' */
  real_T thrust_pre[6];                /* '<Root>/thrust_pre' */
  real_T thrust_after[6];              /* '<Root>/thrust_after' */
  real_T M_Kalman[3];                  /* '<Root>/M_Kalman' */
  real_T LOE_GS[6];                    /* '<Root>/LOE_GS' */
} ExtY_tuning_GS5_T;

/* Real-time Model Data Structure */
struct tag_RTM_tuning_GS5_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_tuning_GS5_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T blkStateChange;
  real_T odeY[4];
  real_T odeF[4][4];
  ODE4_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

/* Constant parameters (auto storage) */
extern const ConstP_tuning_GS5_T tuning_GS5_ConstP;

/* Class declaration for model tuning_GS5 */
class tuning_GS5ModelClass {
  /* public data and function members */
 public:
  /* External inputs */
  ExtU_tuning_GS5_T tuning_GS5_U;

  /* External outputs */
  ExtY_tuning_GS5_T tuning_GS5_Y;

  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  tuning_GS5ModelClass();

  /* Destructor */
  ~tuning_GS5ModelClass();

  /* Real-Time Model get method */
  RT_MODEL_tuning_GS5_T * getRTM();

  /* private data and function members */
 private:
  /* Block signals */
  B_tuning_GS5_T tuning_GS5_B;

  /* Block states */
  DW_tuning_GS5_T tuning_GS5_DW;
  X_tuning_GS5_T tuning_GS5_X;         /* Block continuous states */

  /* Real-Time Model */
  RT_MODEL_tuning_GS5_T tuning_GS5_M;

  /* Continuous states update member function*/
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  /* Derivatives member function */
  void tuning_GS5_derivatives();
};

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S12>/ConstantP' : Unused code path elimination
 * Block '<S12>/CovarianceZ' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate' : Unused code path elimination
 * Block '<S52>/Data Type Duplicate' : Unused code path elimination
 * Block '<S53>/Conversion' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Conversion' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Add1' : Unused code path elimination
 * Block '<S13>/Product' : Unused code path elimination
 * Block '<S13>/Product1' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Conversion' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Conversion' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Conversion' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Conversion' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Conversion' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Conversion' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Conversion' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/Conversion' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/G' : Unused code path elimination
 * Block '<S4>/H' : Unused code path elimination
 * Block '<S4>/ManualSwitchPZ' : Unused code path elimination
 * Block '<S4>/N' : Unused code path elimination
 * Block '<S4>/P0' : Unused code path elimination
 * Block '<S4>/Q' : Unused code path elimination
 * Block '<S4>/R' : Unused code path elimination
 * Block '<S31>/Constant' : Unused code path elimination
 * Block '<S4>/Reset' : Unused code path elimination
 * Block '<S4>/Reshapeyhat' : Unused code path elimination
 * Block '<S50>/CheckSignalProperties' : Unused code path elimination
 * Block '<Root>/                          ' : Eliminated since input and output rates are identical
 * Block '<Root>/                             ' : Eliminated since input and output rates are identical
 * Block '<Root>/                                     ' : Eliminated since input and output rates are identical
 * Block '<S51>/Conversion' : Eliminate redundant data type conversion
 * Block '<S52>/Conversion' : Eliminate redundant data type conversion
 * Block '<S14>/Conversion' : Eliminate redundant data type conversion
 * Block '<S15>/Conversion' : Eliminate redundant data type conversion
 * Block '<S16>/Conversion' : Eliminate redundant data type conversion
 * Block '<S17>/Conversion' : Eliminate redundant data type conversion
 * Block '<S4>/DataTypeConversionEnable' : Eliminate redundant data type conversion
 * Block '<S26>/Conversion' : Eliminate redundant data type conversion
 * Block '<S27>/Conversion' : Eliminate redundant data type conversion
 * Block '<S28>/Conversion' : Eliminate redundant data type conversion
 * Block '<S30>/Reshape' : Reshape block reduction
 * Block '<S4>/ReshapeX0' : Reshape block reduction
 * Block '<S4>/Reshapeu' : Reshape block reduction
 * Block '<S4>/Reshapexhat' : Reshape block reduction
 * Block '<S4>/Reshapey' : Reshape block reduction
 * Block '<S57>/Reshape' : Reshape block reduction
 * Block '<S57>/Reshape1' : Reshape block reduction
 * Block '<S58>/Reshape' : Reshape block reduction
 * Block '<S59>/Reshape' : Reshape block reduction
 * Block '<S60>/Reshape' : Reshape block reduction
 * Block '<S61>/Reshape' : Reshape block reduction
 * Block '<Root>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<Root>/Reshape' : Reshape block reduction
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
 * '<Root>' : 'tuning_GS5'
 * '<S1>'   : 'tuning_GS5/Actuator_Fault'
 * '<S2>'   : 'tuning_GS5/FDD_Kalman'
 * '<S3>'   : 'tuning_GS5/FDD_fictive'
 * '<S4>'   : 'tuning_GS5/Kalman Filter'
 * '<S5>'   : 'tuning_GS5/Nominal_Controller'
 * '<S6>'   : 'tuning_GS5/Test_config_and_data'
 * '<S7>'   : 'tuning_GS5/Thrust2command'
 * '<S8>'   : 'tuning_GS5/FDD_Kalman/Cross Product'
 * '<S9>'   : 'tuning_GS5/FDD_Kalman/MATLAB Function1'
 * '<S10>'  : 'tuning_GS5/FDD_Kalman/Cross Product/Subsystem'
 * '<S11>'  : 'tuning_GS5/FDD_Kalman/Cross Product/Subsystem2'
 * '<S12>'  : 'tuning_GS5/Kalman Filter/CalculatePL'
 * '<S13>'  : 'tuning_GS5/Kalman Filter/CalculateYhat'
 * '<S14>'  : 'tuning_GS5/Kalman Filter/DataTypeConversionA'
 * '<S15>'  : 'tuning_GS5/Kalman Filter/DataTypeConversionB'
 * '<S16>'  : 'tuning_GS5/Kalman Filter/DataTypeConversionC'
 * '<S17>'  : 'tuning_GS5/Kalman Filter/DataTypeConversionD'
 * '<S18>'  : 'tuning_GS5/Kalman Filter/DataTypeConversionG'
 * '<S19>'  : 'tuning_GS5/Kalman Filter/DataTypeConversionH'
 * '<S20>'  : 'tuning_GS5/Kalman Filter/DataTypeConversionN'
 * '<S21>'  : 'tuning_GS5/Kalman Filter/DataTypeConversionP'
 * '<S22>'  : 'tuning_GS5/Kalman Filter/DataTypeConversionP0'
 * '<S23>'  : 'tuning_GS5/Kalman Filter/DataTypeConversionQ'
 * '<S24>'  : 'tuning_GS5/Kalman Filter/DataTypeConversionR'
 * '<S25>'  : 'tuning_GS5/Kalman Filter/DataTypeConversionReset'
 * '<S26>'  : 'tuning_GS5/Kalman Filter/DataTypeConversionX'
 * '<S27>'  : 'tuning_GS5/Kalman Filter/DataTypeConversionX0'
 * '<S28>'  : 'tuning_GS5/Kalman Filter/DataTypeConversionu'
 * '<S29>'  : 'tuning_GS5/Kalman Filter/MemoryP'
 * '<S30>'  : 'tuning_GS5/Kalman Filter/Observer'
 * '<S31>'  : 'tuning_GS5/Kalman Filter/ReducedQRN'
 * '<S32>'  : 'tuning_GS5/Kalman Filter/ScalarExpansionP0'
 * '<S33>'  : 'tuning_GS5/Kalman Filter/ScalarExpansionQ'
 * '<S34>'  : 'tuning_GS5/Kalman Filter/ScalarExpansionR'
 * '<S35>'  : 'tuning_GS5/Kalman Filter/UseCurrentEstimator'
 * '<S36>'  : 'tuning_GS5/Kalman Filter/checkA'
 * '<S37>'  : 'tuning_GS5/Kalman Filter/checkB'
 * '<S38>'  : 'tuning_GS5/Kalman Filter/checkC'
 * '<S39>'  : 'tuning_GS5/Kalman Filter/checkD'
 * '<S40>'  : 'tuning_GS5/Kalman Filter/checkEnable'
 * '<S41>'  : 'tuning_GS5/Kalman Filter/checkG'
 * '<S42>'  : 'tuning_GS5/Kalman Filter/checkH'
 * '<S43>'  : 'tuning_GS5/Kalman Filter/checkN'
 * '<S44>'  : 'tuning_GS5/Kalman Filter/checkP0'
 * '<S45>'  : 'tuning_GS5/Kalman Filter/checkQ'
 * '<S46>'  : 'tuning_GS5/Kalman Filter/checkR'
 * '<S47>'  : 'tuning_GS5/Kalman Filter/checkReset'
 * '<S48>'  : 'tuning_GS5/Kalman Filter/checkX0'
 * '<S49>'  : 'tuning_GS5/Kalman Filter/checku'
 * '<S50>'  : 'tuning_GS5/Kalman Filter/checky'
 * '<S51>'  : 'tuning_GS5/Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S52>'  : 'tuning_GS5/Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S53>'  : 'tuning_GS5/Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S54>'  : 'tuning_GS5/Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S55>'  : 'tuning_GS5/Kalman Filter/Observer/MeasurementUpdate'
 * '<S56>'  : 'tuning_GS5/Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 * '<S57>'  : 'tuning_GS5/Nominal_Controller/XY State Feedback'
 * '<S58>'  : 'tuning_GS5/Nominal_Controller/pitch_controller_SF'
 * '<S59>'  : 'tuning_GS5/Nominal_Controller/roll_controller_SF'
 * '<S60>'  : 'tuning_GS5/Nominal_Controller/yaw_controller'
 * '<S61>'  : 'tuning_GS5/Nominal_Controller/z_controller'
 * '<S62>'  : 'tuning_GS5/Test_config_and_data/FFW'
 * '<S63>'  : 'tuning_GS5/Test_config_and_data/LOE_'
 * '<S64>'  : 'tuning_GS5/Test_config_and_data/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_tuning_GS5_h_ */
