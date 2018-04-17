#ifndef __c1_DetectAndTrackFace_h__
#define __c1_DetectAndTrackFace_h__

/* Type Definitions */
#ifndef struct_tag_sZlKirm9OkQ9U2eqsjm1Q3C
#define struct_tag_sZlKirm9OkQ9U2eqsjm1Q3C

struct tag_sZlKirm9OkQ9U2eqsjm1Q3C
{
  int32_T NoError;
  int32_T NotEnoughPts;
  int32_T NotEnoughInliers;
};

#endif                                 /*struct_tag_sZlKirm9OkQ9U2eqsjm1Q3C*/

#ifndef typedef_c1_sZlKirm9OkQ9U2eqsjm1Q3C
#define typedef_c1_sZlKirm9OkQ9U2eqsjm1Q3C

typedef struct tag_sZlKirm9OkQ9U2eqsjm1Q3C c1_sZlKirm9OkQ9U2eqsjm1Q3C;

#endif                                 /*typedef_c1_sZlKirm9OkQ9U2eqsjm1Q3C*/

#ifndef struct_tag_s7H0Qn4ySTowQr3jwtPmyX
#define struct_tag_s7H0Qn4ySTowQr3jwtPmyX

struct tag_s7H0Qn4ySTowQr3jwtPmyX
{
  uint32_T MaxNumTrials;
  uint32_T Confidence;
  uint32_T MaxDistance;
};

#endif                                 /*struct_tag_s7H0Qn4ySTowQr3jwtPmyX*/

#ifndef typedef_c1_s7H0Qn4ySTowQr3jwtPmyX
#define typedef_c1_s7H0Qn4ySTowQr3jwtPmyX

typedef struct tag_s7H0Qn4ySTowQr3jwtPmyX c1_s7H0Qn4ySTowQr3jwtPmyX;

#endif                                 /*typedef_c1_s7H0Qn4ySTowQr3jwtPmyX*/

#ifndef struct_tag_s9s8BC13iTohZXRbLMSIDHE
#define struct_tag_s9s8BC13iTohZXRbLMSIDHE

struct tag_s9s8BC13iTohZXRbLMSIDHE
{
  boolean_T CaseSensitivity;
  boolean_T StructExpand;
  boolean_T PartialMatching;
};

#endif                                 /*struct_tag_s9s8BC13iTohZXRbLMSIDHE*/

#ifndef typedef_c1_s9s8BC13iTohZXRbLMSIDHE
#define typedef_c1_s9s8BC13iTohZXRbLMSIDHE

typedef struct tag_s9s8BC13iTohZXRbLMSIDHE c1_s9s8BC13iTohZXRbLMSIDHE;

#endif                                 /*typedef_c1_s9s8BC13iTohZXRbLMSIDHE*/

#ifndef struct_tag_svT7UAnr23JjyThWngsAoUB
#define struct_tag_svT7UAnr23JjyThWngsAoUB

struct tag_svT7UAnr23JjyThWngsAoUB
{
  int32_T maxNumTrials;
  real32_T confidence;
  real32_T maxDistance;
  boolean_T recomputeModelFromInliers;
  real32_T sampleSize;
};

#endif                                 /*struct_tag_svT7UAnr23JjyThWngsAoUB*/

#ifndef typedef_c1_svT7UAnr23JjyThWngsAoUB
#define typedef_c1_svT7UAnr23JjyThWngsAoUB

typedef struct tag_svT7UAnr23JjyThWngsAoUB c1_svT7UAnr23JjyThWngsAoUB;

#endif                                 /*typedef_c1_svT7UAnr23JjyThWngsAoUB*/

#include <stdlib.h>
#ifndef struct_emxArray_real32_T_500x2
#define struct_emxArray_real32_T_500x2

struct emxArray_real32_T_500x2
{
  real32_T data[1000];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real32_T_500x2*/

#ifndef typedef_c1_emxArray_real32_T_500x2
#define typedef_c1_emxArray_real32_T_500x2

typedef struct emxArray_real32_T_500x2 c1_emxArray_real32_T_500x2;

#endif                                 /*typedef_c1_emxArray_real32_T_500x2*/

#ifndef struct_emxArray_real_T_4x2
#define struct_emxArray_real_T_4x2

struct emxArray_real_T_4x2
{
  real_T data[8];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real_T_4x2*/

#ifndef typedef_c1_emxArray_real_T_4x2
#define typedef_c1_emxArray_real_T_4x2

typedef struct emxArray_real_T_4x2 c1_emxArray_real_T_4x2;

#endif                                 /*typedef_c1_emxArray_real_T_4x2*/

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef typedef_c1_emxArray_boolean_T
#define typedef_c1_emxArray_boolean_T

typedef struct emxArray_boolean_T c1_emxArray_boolean_T;

#endif                                 /*typedef_c1_emxArray_boolean_T*/

#ifndef struct_emxArray_real32_T
#define struct_emxArray_real32_T

struct emxArray_real32_T
{
  real32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real32_T*/

#ifndef typedef_c1_emxArray_real32_T
#define typedef_c1_emxArray_real32_T

typedef struct emxArray_real32_T c1_emxArray_real32_T;

#endif                                 /*typedef_c1_emxArray_real32_T*/

#ifndef struct_emxArray_real32_T_3x3
#define struct_emxArray_real32_T_3x3

struct emxArray_real32_T_3x3
{
  real32_T data[9];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real32_T_3x3*/

#ifndef typedef_c1_emxArray_real32_T_3x3
#define typedef_c1_emxArray_real32_T_3x3

typedef struct emxArray_real32_T_3x3 c1_emxArray_real32_T_3x3;

#endif                                 /*typedef_c1_emxArray_real32_T_3x3*/

#ifndef struct_s3M78OkxeEehRdlzD8WuFiE
#define struct_s3M78OkxeEehRdlzD8WuFiE

struct s3M78OkxeEehRdlzD8WuFiE
{
  real_T Dimensionality;
  c1_emxArray_real32_T_3x3 T;
};

#endif                                 /*struct_s3M78OkxeEehRdlzD8WuFiE*/

#ifndef typedef_c1_affine2d
#define typedef_c1_affine2d

typedef struct s3M78OkxeEehRdlzD8WuFiE c1_affine2d;

#endif                                 /*typedef_c1_affine2d*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_c1_emxArray_real_T
#define typedef_c1_emxArray_real_T

typedef struct emxArray_real_T c1_emxArray_real_T;

#endif                                 /*typedef_c1_emxArray_real_T*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_c1_emxArray_int32_T
#define typedef_c1_emxArray_int32_T

typedef struct emxArray_int32_T c1_emxArray_int32_T;

#endif                                 /*typedef_c1_emxArray_int32_T*/

#ifndef struct_emxArray_uint8_T
#define struct_emxArray_uint8_T

struct emxArray_uint8_T
{
  uint8_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_uint8_T*/

#ifndef typedef_c1_emxArray_uint8_T
#define typedef_c1_emxArray_uint8_T

typedef struct emxArray_uint8_T c1_emxArray_uint8_T;

#endif                                 /*typedef_c1_emxArray_uint8_T*/

#ifndef struct_sFpHUBpERbaNzO8NjT9RHZ
#define struct_sFpHUBpERbaNzO8NjT9RHZ

struct sFpHUBpERbaNzO8NjT9RHZ
{
  c1_emxArray_real32_T *f1;
  c1_emxArray_real_T *f2;
  c1_emxArray_real_T *f3;
  c1_emxArray_real32_T *f4;
};

#endif                                 /*struct_sFpHUBpERbaNzO8NjT9RHZ*/

#ifndef typedef_c1_cell_19
#define typedef_c1_cell_19

typedef struct sFpHUBpERbaNzO8NjT9RHZ c1_cell_19;

#endif                                 /*typedef_c1_cell_19*/

#ifndef struct_shPFQZ2AzvSbYEipJc8963B
#define struct_shPFQZ2AzvSbYEipJc8963B

struct shPFQZ2AzvSbYEipJc8963B
{
  c1_emxArray_real32_T *f1;
};

#endif                                 /*struct_shPFQZ2AzvSbYEipJc8963B*/

#ifndef typedef_c1_cell_wrap_20
#define typedef_c1_cell_wrap_20

typedef struct shPFQZ2AzvSbYEipJc8963B c1_cell_wrap_20;

#endif                                 /*typedef_c1_cell_wrap_20*/

#ifndef typedef_c1_cell_wrap_2
#define typedef_c1_cell_wrap_2

typedef struct {
  uint32_T f1[8];
} c1_cell_wrap_2;

#endif                                 /*typedef_c1_cell_wrap_2*/

#ifndef typedef_c1_vision_PointTracker
#define typedef_c1_vision_PointTracker

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  c1_cell_wrap_2 inputVarSize[1];
  void * pTracker;
  real_T FrameSize[2];
  real_T NumPoints;
  boolean_T IsRGB;
  real_T FrameClassID;
} c1_vision_PointTracker;

#endif                                 /*typedef_c1_vision_PointTracker*/

#ifndef struct_tag_skA5dKpnjgSNaA6XSElXHZH
#define struct_tag_skA5dKpnjgSNaA6XSElXHZH

struct tag_skA5dKpnjgSNaA6XSElXHZH
{
  real_T BlockSize[2];
  real_T NumPyramidLevels;
  real_T MaxIterations;
  real_T Epsilon;
  real_T MaxBidirectionalError;
};

#endif                                 /*struct_tag_skA5dKpnjgSNaA6XSElXHZH*/

#ifndef typedef_c1_skA5dKpnjgSNaA6XSElXHZH
#define typedef_c1_skA5dKpnjgSNaA6XSElXHZH

typedef struct tag_skA5dKpnjgSNaA6XSElXHZH c1_skA5dKpnjgSNaA6XSElXHZH;

#endif                                 /*typedef_c1_skA5dKpnjgSNaA6XSElXHZH*/

#ifndef typedef_SFc1_DetectAndTrackFaceInstanceStruct
#define typedef_SFc1_DetectAndTrackFaceInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_DetectAndTrackFace;
  c1_vision_PointTracker c1_pointTracker;
  boolean_T c1_pointTracker_not_empty;
  c1_emxArray_real32_T_500x2 c1_oldPoints;
  boolean_T c1_oldPoints_not_empty;
  c1_emxArray_real_T_4x2 c1_bboxPoints;
  boolean_T c1_bboxPoints_not_empty;
  real_T c1_first_time;
  boolean_T c1_first_time_not_empty;
  real_T c1_numPts;
  boolean_T c1_numPts_not_empty;
  uint32_T c1_method;
  boolean_T c1_method_not_empty;
  uint32_T c1_state;
  boolean_T c1_state_not_empty;
  uint32_T c1_b_state[2];
  boolean_T c1_b_state_not_empty;
  uint32_T c1_c_state[625];
  boolean_T c1_c_state_not_empty;
  real_T c1_videoFrameGray[1048576];
  real_T c1_u[1048576];
  void *c1_fEmlrtCtx;
  real_T (*c1_b_videoFrameGray)[1048576];
  real_T *c1_decimationFactor;
  real_T (*c1_bBox_data)[16];
  int32_T (*c1_bBox_sizes)[2];
  real_T (*c1_bBoxCornerPts_data)[8];
  int32_T (*c1_bBoxCornerPts_sizes)[2];
  real32_T (*c1_featurePointLocations_data)[1000];
  int32_T (*c1_featurePointLocations_sizes)[2];
  real32_T (*c1_newFeaturePointLocations_data)[1000];
  int32_T (*c1_newFeaturePointLocations_sizes)[2];
  real_T *c1_numberOfFeaturePoints;
} SFc1_DetectAndTrackFaceInstanceStruct;

#endif                                 /*typedef_SFc1_DetectAndTrackFaceInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_DetectAndTrackFace_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c1_DetectAndTrackFace_get_check_sum(mxArray *plhs[]);
extern void c1_DetectAndTrackFace_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
