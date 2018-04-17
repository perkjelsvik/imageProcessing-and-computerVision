/* Include files */

#include "DetectAndTrackFace_sfun.h"
#include "DetectAndTrackFace_sfun_debug_macros.h"
#include "c1_DetectAndTrackFace.h"
#include "c2_DetectAndTrackFace.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _DetectAndTrackFaceMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void DetectAndTrackFace_initializer(void)
{
}

void DetectAndTrackFace_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_DetectAndTrackFace_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_DetectAndTrackFace_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_DetectAndTrackFace_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_DetectAndTrackFace_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4054178288U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2698960009U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4272822571U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3552528197U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_DetectAndTrackFace_get_check_sum(mxArray *plhs[]);
          sf_c1_DetectAndTrackFace_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_DetectAndTrackFace_get_check_sum(mxArray *plhs[]);
          sf_c2_DetectAndTrackFace_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(806793726U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1240701950U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1207731614U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4283163528U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1606449116U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1939495286U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2365887475U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2413762233U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_DetectAndTrackFace_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "0X2sTJlJJosOjPnFqVxYIB") == 0) {
          extern mxArray *sf_c1_DetectAndTrackFace_get_autoinheritance_info(void);
          plhs[0] = sf_c1_DetectAndTrackFace_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "rkeCrnzyYuv8cwyCmDdiPD") == 0) {
          extern mxArray *sf_c2_DetectAndTrackFace_get_autoinheritance_info(void);
          plhs[0] = sf_c2_DetectAndTrackFace_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_DetectAndTrackFace_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  char instanceChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    mxGetString(prhs[2], instanceChksum,sizeof(instanceChksum)/sizeof(char));
    instanceChksum[(sizeof(instanceChksum)/sizeof(char)-1)] = '\0';
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(instanceChksum, "sIsP9toTX8dPy9PDnhTIqUB") == 0) {
          extern const mxArray
            *sf_c1_DetectAndTrackFace_get_eml_resolved_functions_info(void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c1_DetectAndTrackFace_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     case 2:
      {
        if (strcmp(instanceChksum, "sMo4nouOik8x2YV4kgxDZp") == 0) {
          extern const mxArray
            *sf_c2_DetectAndTrackFace_get_eml_resolved_functions_info(void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c2_DetectAndTrackFace_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_DetectAndTrackFace_third_party_uses_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "sIsP9toTX8dPy9PDnhTIqUB") == 0) {
          extern mxArray *sf_c1_DetectAndTrackFace_third_party_uses_info(void);
          plhs[0] = sf_c1_DetectAndTrackFace_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "sMo4nouOik8x2YV4kgxDZp") == 0) {
          extern mxArray *sf_c2_DetectAndTrackFace_third_party_uses_info(void);
          plhs[0] = sf_c2_DetectAndTrackFace_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_DetectAndTrackFace_jit_fallback_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "sIsP9toTX8dPy9PDnhTIqUB") == 0) {
          extern mxArray *sf_c1_DetectAndTrackFace_jit_fallback_info(void);
          plhs[0] = sf_c1_DetectAndTrackFace_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "sMo4nouOik8x2YV4kgxDZp") == 0) {
          extern mxArray *sf_c2_DetectAndTrackFace_jit_fallback_info(void);
          plhs[0] = sf_c2_DetectAndTrackFace_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_DetectAndTrackFace_updateBuildInfo_args_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "sIsP9toTX8dPy9PDnhTIqUB") == 0) {
          extern mxArray *sf_c1_DetectAndTrackFace_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c1_DetectAndTrackFace_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "sMo4nouOik8x2YV4kgxDZp") == 0) {
          extern mxArray *sf_c2_DetectAndTrackFace_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c2_DetectAndTrackFace_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void DetectAndTrackFace_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _DetectAndTrackFaceMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "DetectAndTrackFace","sfun",0,3,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _DetectAndTrackFaceMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _DetectAndTrackFaceMachineNumber_,0);
}

void DetectAndTrackFace_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
typedef struct SfOptimizationInfoFlagsTag {
  boolean_T isRtwGen;
  boolean_T isModelRef;
  boolean_T isExternal;
} SfOptimizationInfoFlags;

static SfOptimizationInfoFlags sOptimizationInfoFlags;
void unload_DetectAndTrackFace_optimization_info(void);
mxArray* load_DetectAndTrackFace_optimization_info(boolean_T isRtwGen, boolean_T
  isModelRef, boolean_T isExternal)
{
  if (sOptimizationInfoFlags.isRtwGen != isRtwGen ||
      sOptimizationInfoFlags.isModelRef != isModelRef ||
      sOptimizationInfoFlags.isExternal != isExternal) {
    unload_DetectAndTrackFace_optimization_info();
  }

  sOptimizationInfoFlags.isRtwGen = isRtwGen;
  sOptimizationInfoFlags.isModelRef = isModelRef;
  sOptimizationInfoFlags.isExternal = isExternal;
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "DetectAndTrackFace", "DetectAndTrackFace");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_DetectAndTrackFace_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
