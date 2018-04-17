#ifndef __c2_DetectAndTrackFace_h__
#define __c2_DetectAndTrackFace_h__

/* Type Definitions */
#ifndef struct_tag_seIUUUlWGz1zwZPqxZMWAfE
#define struct_tag_seIUUUlWGz1zwZPqxZMWAfE

struct tag_seIUUUlWGz1zwZPqxZMWAfE
{
  uint32_T MinQuality;
  uint32_T FilterSize;
  uint32_T ROI;
};

#endif                                 /*struct_tag_seIUUUlWGz1zwZPqxZMWAfE*/

#ifndef typedef_c2_seIUUUlWGz1zwZPqxZMWAfE
#define typedef_c2_seIUUUlWGz1zwZPqxZMWAfE

typedef struct tag_seIUUUlWGz1zwZPqxZMWAfE c2_seIUUUlWGz1zwZPqxZMWAfE;

#endif                                 /*typedef_c2_seIUUUlWGz1zwZPqxZMWAfE*/

#ifndef struct_tag_s9s8BC13iTohZXRbLMSIDHE
#define struct_tag_s9s8BC13iTohZXRbLMSIDHE

struct tag_s9s8BC13iTohZXRbLMSIDHE
{
  boolean_T CaseSensitivity;
  boolean_T StructExpand;
  boolean_T PartialMatching;
};

#endif                                 /*struct_tag_s9s8BC13iTohZXRbLMSIDHE*/

#ifndef typedef_c2_s9s8BC13iTohZXRbLMSIDHE
#define typedef_c2_s9s8BC13iTohZXRbLMSIDHE

typedef struct tag_s9s8BC13iTohZXRbLMSIDHE c2_s9s8BC13iTohZXRbLMSIDHE;

#endif                                 /*typedef_c2_s9s8BC13iTohZXRbLMSIDHE*/

#ifndef struct_tag_sCCs8XvuuHlwi23qi5ye9bG
#define struct_tag_sCCs8XvuuHlwi23qi5ye9bG

struct tag_sCCs8XvuuHlwi23qi5ye9bG
{
  uint32_T Metric;
};

#endif                                 /*struct_tag_sCCs8XvuuHlwi23qi5ye9bG*/

#ifndef typedef_c2_sCCs8XvuuHlwi23qi5ye9bG
#define typedef_c2_sCCs8XvuuHlwi23qi5ye9bG

typedef struct tag_sCCs8XvuuHlwi23qi5ye9bG c2_sCCs8XvuuHlwi23qi5ye9bG;

#endif                                 /*typedef_c2_sCCs8XvuuHlwi23qi5ye9bG*/

#ifndef struct_tag_sQGlgQD0TGCsHV1wGoD2xCH
#define struct_tag_sQGlgQD0TGCsHV1wGoD2xCH

struct tag_sQGlgQD0TGCsHV1wGoD2xCH
{
  real32_T Metric;
};

#endif                                 /*struct_tag_sQGlgQD0TGCsHV1wGoD2xCH*/

#ifndef typedef_c2_sQGlgQD0TGCsHV1wGoD2xCH
#define typedef_c2_sQGlgQD0TGCsHV1wGoD2xCH

typedef struct tag_sQGlgQD0TGCsHV1wGoD2xCH c2_sQGlgQD0TGCsHV1wGoD2xCH;

#endif                                 /*typedef_c2_sQGlgQD0TGCsHV1wGoD2xCH*/

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

#ifndef typedef_c2_emxArray_real32_T
#define typedef_c2_emxArray_real32_T

typedef struct emxArray_real32_T c2_emxArray_real32_T;

#endif                                 /*typedef_c2_emxArray_real32_T*/

#ifndef struct_siRxls7pavE5i9o0LnY7mdC
#define struct_siRxls7pavE5i9o0LnY7mdC

struct siRxls7pavE5i9o0LnY7mdC
{
  c2_emxArray_real32_T *pLocation;
  c2_emxArray_real32_T *pMetric;
};

#endif                                 /*struct_siRxls7pavE5i9o0LnY7mdC*/

#ifndef typedef_c2_vision_internal_cornerPoints_cg
#define typedef_c2_vision_internal_cornerPoints_cg

typedef struct siRxls7pavE5i9o0LnY7mdC c2_vision_internal_cornerPoints_cg;

#endif                                 /*typedef_c2_vision_internal_cornerPoints_cg*/

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

#ifndef typedef_c2_emxArray_real_T
#define typedef_c2_emxArray_real_T

typedef struct emxArray_real_T c2_emxArray_real_T;

#endif                                 /*typedef_c2_emxArray_real_T*/

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

#ifndef typedef_c2_emxArray_uint8_T
#define typedef_c2_emxArray_uint8_T

typedef struct emxArray_uint8_T c2_emxArray_uint8_T;

#endif                                 /*typedef_c2_emxArray_uint8_T*/

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

#ifndef typedef_c2_emxArray_int32_T
#define typedef_c2_emxArray_int32_T

typedef struct emxArray_int32_T c2_emxArray_int32_T;

#endif                                 /*typedef_c2_emxArray_int32_T*/

#ifndef struct_emxArray_int32_T_1x4
#define struct_emxArray_int32_T_1x4

struct emxArray_int32_T_1x4
{
  int32_T data[4];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_int32_T_1x4*/

#ifndef typedef_c2_emxArray_int32_T_1x4
#define typedef_c2_emxArray_int32_T_1x4

typedef struct emxArray_int32_T_1x4 c2_emxArray_int32_T_1x4;

#endif                                 /*typedef_c2_emxArray_int32_T_1x4*/

#ifndef struct_sTCp9CVqcBuQ2RAAhrP3nJG
#define struct_sTCp9CVqcBuQ2RAAhrP3nJG

struct sTCp9CVqcBuQ2RAAhrP3nJG
{
  real32_T MinQuality;
  real_T FilterSize;
  boolean_T usingROI;
  c2_emxArray_int32_T_1x4 ROI;
};

#endif                                 /*struct_sTCp9CVqcBuQ2RAAhrP3nJG*/

#ifndef typedef_c2_swtWcLs9dbtZb7aBThYWFXD
#define typedef_c2_swtWcLs9dbtZb7aBThYWFXD

typedef struct sTCp9CVqcBuQ2RAAhrP3nJG c2_swtWcLs9dbtZb7aBThYWFXD;

#endif                                 /*typedef_c2_swtWcLs9dbtZb7aBThYWFXD*/

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

#ifndef typedef_c2_emxArray_boolean_T
#define typedef_c2_emxArray_boolean_T

typedef struct emxArray_boolean_T c2_emxArray_boolean_T;

#endif                                 /*typedef_c2_emxArray_boolean_T*/

#ifndef struct_sDtbDZ0RYAYdXVNW8KjNICE
#define struct_sDtbDZ0RYAYdXVNW8KjNICE

struct sDtbDZ0RYAYdXVNW8KjNICE
{
  c2_emxArray_real32_T *Location;
  c2_emxArray_real32_T *Metric;
};

#endif                                 /*struct_sDtbDZ0RYAYdXVNW8KjNICE*/

#ifndef typedef_c2_sjeQsvJNEhdsHQhIigwA2FF
#define typedef_c2_sjeQsvJNEhdsHQhIigwA2FF

typedef struct sDtbDZ0RYAYdXVNW8KjNICE c2_sjeQsvJNEhdsHQhIigwA2FF;

#endif                                 /*typedef_c2_sjeQsvJNEhdsHQhIigwA2FF*/

#ifndef typedef_c2_cell_wrap_2
#define typedef_c2_cell_wrap_2

typedef struct {
  uint32_T f1[8];
} c2_cell_wrap_2;

#endif                                 /*typedef_c2_cell_wrap_2*/

#ifndef typedef_c2_vision_CascadeObjectDetector
#define typedef_c2_vision_CascadeObjectDetector

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  boolean_T tunablePropertyChanged[4];
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  c2_cell_wrap_2 inputVarSize[1];
  real_T ScaleFactor;
  real_T MergeThreshold;
  void * pCascadeClassifier;
} c2_vision_CascadeObjectDetector;

#endif                                 /*typedef_c2_vision_CascadeObjectDetector*/

#ifndef typedef_SFc2_DetectAndTrackFaceInstanceStruct
#define typedef_SFc2_DetectAndTrackFaceInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_DetectAndTrackFace;
  c2_vision_CascadeObjectDetector c2_faceDetector;
  boolean_T c2_faceDetector_not_empty;
  real_T c2_videoFrameGray[1048576];
  real_T c2_u[1048576];
  void *c2_fEmlrtCtx;
  real_T (*c2_bBox_data)[16];
  int32_T (*c2_bBox_sizes)[2];
  real_T (*c2_b_videoFrameGray)[1048576];
  real32_T (*c2_featurePointLocations_data)[1000];
  int32_T (*c2_featurePointLocations_sizes)[2];
  real_T *c2_decimationFactor;
  real_T *c2_numberOfFeaturePoints;
} SFc2_DetectAndTrackFaceInstanceStruct;

#endif                                 /*typedef_SFc2_DetectAndTrackFaceInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_DetectAndTrackFace_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c2_DetectAndTrackFace_get_check_sum(mxArray *plhs[]);
extern void c2_DetectAndTrackFace_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
