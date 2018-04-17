/* Include files */

#include "DetectAndTrackFace_sfun.h"
#include "c1_DetectAndTrackFace.h"
#include <math.h>
#include <string.h>
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DetectAndTrackFace_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const mxArray *c1_eml_mx;
static const mxArray *c1_b_eml_mx;
static const char * c1_debug_family_names[17] = { "isFound", "visiblePoints",
  "oldInliers", "xform", "videoFrameGray", "nargin", "nargout",
  "decimationFactor", "bBox", "featurePointLocations", "bBoxCornerPts",
  "newFeaturePointLocations", "numberOfFeaturePoints", "oldPoints", "bboxPoints",
  "first_time", "numPts" };

static emlrtRTEInfo c1_emlrtRTEI = { 7,/* lineNo */
  12,                                  /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_b_emlrtRTEI = { 8,/* lineNo */
  12,                                  /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_c_emlrtRTEI = { 18,/* lineNo */
  5,                                   /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_d_emlrtRTEI = { 22,/* lineNo */
  5,                                   /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_e_emlrtRTEI = { 30,/* lineNo */
  1,                                   /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_f_emlrtRTEI = { 34,/* lineNo */
  46,                                  /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_g_emlrtRTEI = { 67,/* lineNo */
  62,                                  /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_h_emlrtRTEI = { 61,/* lineNo */
  9,                                   /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_i_emlrtRTEI = { 42,/* lineNo */
  9,                                   /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_j_emlrtRTEI = { 67,/* lineNo */
  32,                                  /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_k_emlrtRTEI = { 62,/* lineNo */
  9,                                   /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_l_emlrtRTEI = { 46,/* lineNo */
  38,                                  /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_m_emlrtRTEI = { 48,/* lineNo */
  28,                                  /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_n_emlrtRTEI = { 69,/* lineNo */
  5,                                   /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_o_emlrtRTEI = { 46,/* lineNo */
  64,                                  /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_p_emlrtRTEI = { 49,/* lineNo */
  33,                                  /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_q_emlrtRTEI = { 530,/* lineNo */
  26,                                  /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_r_emlrtRTEI = { 70,/* lineNo */
  5,                                   /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_s_emlrtRTEI = { 563,/* lineNo */
  27,                                  /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_t_emlrtRTEI = { 92,/* lineNo */
  9,                                   /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_u_emlrtRTEI = { 78,/* lineNo */
  13,                                  /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_v_emlrtRTEI = { 563,/* lineNo */
  35,                                  /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_w_emlrtRTEI = { 93,/* lineNo */
  9,                                   /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_x_emlrtRTEI = { 78,/* lineNo */
  25,                                  /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_y_emlrtRTEI = { 52,/* lineNo */
  9,                                   /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_ab_emlrtRTEI = { 77,/* lineNo */
  10,                                  /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_bb_emlrtRTEI = { 77,/* lineNo */
  20,                                  /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_cb_emlrtRTEI = { 81,/* lineNo */
  59,                                  /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_db_emlrtRTEI = { 58,/* lineNo */
  34,                                  /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_eb_emlrtRTEI = { 81,/* lineNo */
  52,                                  /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_fb_emlrtRTEI = { 58,/* lineNo */
  9,                                   /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_gb_emlrtRTEI = { 72,/* lineNo */
  9,                                   /* colNo */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/eml/padarray.m"/* pName */
};

static emlrtRTEInfo c1_hb_emlrtRTEI = { 59,/* lineNo */
  9,                                   /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_ib_emlrtRTEI = { 150,/* lineNo */
  17,                                  /* colNo */
  "affine2d",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/affine2d.m"/* pName */
};

static emlrtRTEInfo c1_jb_emlrtRTEI = { 81,/* lineNo */
  9,                                   /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_kb_emlrtRTEI = { 82,/* lineNo */
  9,                                   /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_lb_emlrtRTEI = { 86,/* lineNo */
  9,                                   /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_mb_emlrtRTEI = { 89,/* lineNo */
  9,                                   /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_nb_emlrtRTEI = { 90,/* lineNo */
  33,                                  /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_ob_emlrtRTEI = { 4,/* lineNo */
  90,                                  /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_pb_emlrtRTEI = { 69,/* lineNo */
  46,                                  /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_qb_emlrtRTEI = { 70,/* lineNo */
  28,                                  /* colNo */
  "Detection and Tracking/Tracking",   /* fName */
  "#DetectAndTrackFace:13"             /* pName */
};

static emlrtRTEInfo c1_rb_emlrtRTEI = { 491,/* lineNo */
  22,                                  /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_sb_emlrtRTEI = { 79,/* lineNo */
  17,                                  /* colNo */
  "pointTrackerBuildable",             /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+buildable/pointTrackerBuildable.m"/* pName */
};

static emlrtRTEInfo c1_tb_emlrtRTEI = { 491,/* lineNo */
  7,                                   /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_ub_emlrtRTEI = { 39,/* lineNo */
  13,                                  /* colNo */
  "im2uint8",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/eml/im2uint8.m"/* pName */
};

static emlrtRTEInfo c1_vb_emlrtRTEI = { 473,/* lineNo */
  26,                                  /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_wb_emlrtRTEI = { 508,/* lineNo */
  56,                                  /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_xb_emlrtRTEI = { 155,/* lineNo */
  37,                                  /* colNo */
  "validateattributes",                /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/lang/validateattributes.m"/* pName */
};

static emlrtRTEInfo c1_yb_emlrtRTEI = { 1,/* lineNo */
  1,                                   /* colNo */
  "SystemCore",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"/* pName */
};

static emlrtRTEInfo c1_ac_emlrtRTEI = { 306,/* lineNo */
  7,                                   /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_bc_emlrtRTEI = { 327,/* lineNo */
  11,                                  /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_cc_emlrtRTEI = { 141,/* lineNo */
  17,                                  /* colNo */
  "pointTrackerBuildable",             /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+buildable/pointTrackerBuildable.m"/* pName */
};

static emlrtRTEInfo c1_dc_emlrtRTEI = { 327,/* lineNo */
  12,                                  /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_ec_emlrtRTEI = { 335,/* lineNo */
  7,                                   /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_fc_emlrtRTEI = { 1,/* lineNo */
  11,                                  /* colNo */
  "SystemCore",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"/* pName */
};

static emlrtRTEInfo c1_gc_emlrtRTEI = { 292,/* lineNo */
  23,                                  /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_hc_emlrtRTEI = { 607,/* lineNo */
  7,                                   /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_ic_emlrtRTEI = { 608,/* lineNo */
  7,                                   /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_jc_emlrtRTEI = { 609,/* lineNo */
  15,                                  /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_kc_emlrtRTEI = { 609,/* lineNo */
  25,                                  /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_lc_emlrtRTEI = { 609,/* lineNo */
  14,                                  /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_mc_emlrtRTEI = { 610,/* lineNo */
  12,                                  /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_nc_emlrtRTEI = { 610,/* lineNo */
  37,                                  /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_oc_emlrtRTEI = { 609,/* lineNo */
  7,                                   /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_pc_emlrtRTEI = { 606,/* lineNo */
  21,                                  /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_qc_emlrtRTEI = { 572,/* lineNo */
  23,                                  /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_rc_emlrtRTEI = { 338,/* lineNo */
  45,                                  /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_sc_emlrtRTEI = { 118,/* lineNo */
  17,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_tc_emlrtRTEI = { 192,/* lineNo */
  39,                                  /* colNo */
  "validateattributes",                /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/lang/validateattributes.m"/* pName */
};

static emlrtRTEInfo c1_uc_emlrtRTEI = { 142,/* lineNo */
  5,                                   /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_vc_emlrtRTEI = { 126,/* lineNo */
  19,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_wc_emlrtRTEI = { 143,/* lineNo */
  5,                                   /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_xc_emlrtRTEI = { 151,/* lineNo */
  5,                                   /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_yc_emlrtRTEI = { 2,/* lineNo */
  7,                                   /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_ad_emlrtRTEI = { 152,/* lineNo */
  5,                                   /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_bd_emlrtRTEI = { 153,/* lineNo */
  5,                                   /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_cd_emlrtRTEI = { 148,/* lineNo */
  5,                                   /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_dd_emlrtRTEI = { 168,/* lineNo */
  22,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_ed_emlrtRTEI = { 149,/* lineNo */
  5,                                   /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_fd_emlrtRTEI = { 128,/* lineNo */
  24,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_gd_emlrtRTEI = { 128,/* lineNo */
  15,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_hd_emlrtRTEI = { 355,/* lineNo */
  17,                                  /* colNo */
  "affine2d",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/affine2d.m"/* pName */
};

static emlrtRTEInfo c1_id_emlrtRTEI = { 14,/* lineNo */
  13,                                  /* colNo */
  "isinf",                             /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elmat/isinf.m"/* pName */
};

static emlrtRTEInfo c1_jd_emlrtRTEI = { 139,/* lineNo */
  9,                                   /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_kd_emlrtRTEI = { 14,/* lineNo */
  13,                                  /* colNo */
  "isnan",                             /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elmat/isnan.m"/* pName */
};

static emlrtRTEInfo c1_ld_emlrtRTEI = { 353,/* lineNo */
  17,                                  /* colNo */
  "affine2d",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/affine2d.m"/* pName */
};

static emlrtRTEInfo c1_md_emlrtRTEI = { 137,/* lineNo */
  39,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_nd_emlrtRTEI = { 364,/* lineNo */
  48,                                  /* colNo */
  "affine2d",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/affine2d.m"/* pName */
};

static emlrtRTEInfo c1_od_emlrtRTEI = { 371,/* lineNo */
  13,                                  /* colNo */
  "affine2d",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/affine2d.m"/* pName */
};

static emlrtRTEInfo c1_pd_emlrtRTEI = { 126,/* lineNo */
  5,                                   /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_qd_emlrtRTEI = { 148,/* lineNo */
  36,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_rd_emlrtRTEI = { 149,/* lineNo */
  36,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_sd_emlrtRTEI = { 44,/* lineNo */
  5,                                   /* colNo */
  "msac",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"/* pName */
};

static emlrtRTEInfo c1_td_emlrtRTEI = { 54,/* lineNo */
  1,                                   /* colNo */
  "msac",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"/* pName */
};

static emlrtRTEInfo c1_ud_emlrtRTEI = { 97,/* lineNo */
  27,                                  /* colNo */
  "msac",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"/* pName */
};

static emlrtRTEInfo c1_vd_emlrtRTEI = { 66,/* lineNo */
  5,                                   /* colNo */
  "msac",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"/* pName */
};

static emlrtRTEInfo c1_wd_emlrtRTEI = { 98,/* lineNo */
  34,                                  /* colNo */
  "msac",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"/* pName */
};

static emlrtRTEInfo c1_xd_emlrtRTEI = { 120,/* lineNo */
  5,                                   /* colNo */
  "msac",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"/* pName */
};

static emlrtRTEInfo c1_yd_emlrtRTEI = { 62,/* lineNo */
  5,                                   /* colNo */
  "randperm",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/randfun/randperm.m"/* pName */
};

static emlrtRTEInfo c1_ae_emlrtRTEI = { 63,/* lineNo */
  5,                                   /* colNo */
  "randperm",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/randfun/randperm.m"/* pName */
};

static emlrtRTEInfo c1_be_emlrtRTEI = { 1,/* lineNo */
  70,                                  /* colNo */
  "msac",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"/* pName */
};

static emlrtRTEInfo c1_ce_emlrtRTEI = { 64,/* lineNo */
  5,                                   /* colNo */
  "randperm",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/randfun/randperm.m"/* pName */
};

static emlrtRTEInfo c1_de_emlrtRTEI = { 65,/* lineNo */
  5,                                   /* colNo */
  "randperm",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/randfun/randperm.m"/* pName */
};

static emlrtRTEInfo c1_ee_emlrtRTEI = { 69,/* lineNo */
  5,                                   /* colNo */
  "msac",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"/* pName */
};

static emlrtRTEInfo c1_fe_emlrtRTEI = { 102,/* lineNo */
  37,                                  /* colNo */
  "msac",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"/* pName */
};

static emlrtRTEInfo c1_ge_emlrtRTEI = { 70,/* lineNo */
  33,                                  /* colNo */
  "msac",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"/* pName */
};

static emlrtRTEInfo c1_he_emlrtRTEI = { 104,/* lineNo */
  13,                                  /* colNo */
  "msac",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"/* pName */
};

static emlrtRTEInfo c1_ie_emlrtRTEI = { 130,/* lineNo */
  14,                                  /* colNo */
  "msac",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"/* pName */
};

static emlrtRTEInfo c1_je_emlrtRTEI = { 78,/* lineNo */
  13,                                  /* colNo */
  "msac",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"/* pName */
};

static emlrtRTEInfo c1_ke_emlrtRTEI = { 103,/* lineNo */
  10,                                  /* colNo */
  "msac",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"/* pName */
};

static emlrtRTEInfo c1_le_emlrtRTEI = { 106,/* lineNo */
  9,                                   /* colNo */
  "msac",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"/* pName */
};

static emlrtRTEInfo c1_me_emlrtRTEI = { 107,/* lineNo */
  34,                                  /* colNo */
  "msac",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"/* pName */
};

static emlrtRTEInfo c1_ne_emlrtRTEI = { 109,/* lineNo */
  13,                                  /* colNo */
  "msac",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"/* pName */
};

static emlrtRTEInfo c1_oe_emlrtRTEI = { 83,/* lineNo */
  13,                                  /* colNo */
  "msac",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"/* pName */
};

static emlrtRTEInfo c1_pe_emlrtRTEI = { 84,/* lineNo */
  13,                                  /* colNo */
  "msac",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"/* pName */
};

static emlrtRTEInfo c1_qe_emlrtRTEI = { 85,/* lineNo */
  34,                                  /* colNo */
  "msac",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"/* pName */
};

static emlrtRTEInfo c1_re_emlrtRTEI = { 102,/* lineNo */
  47,                                  /* colNo */
  "msac",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"/* pName */
};

static emlrtRTEInfo c1_se_emlrtRTEI = { 128,/* lineNo */
  1,                                   /* colNo */
  "msac",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+ransac/msac.m"/* pName */
};

static emlrtRTEInfo c1_te_emlrtRTEI = { 333,/* lineNo */
  21,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_ue_emlrtRTEI = { 336,/* lineNo */
  1,                                   /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_ve_emlrtRTEI = { 337,/* lineNo */
  13,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_we_emlrtRTEI = { 337,/* lineNo */
  33,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_xe_emlrtRTEI = { 338,/* lineNo */
  23,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_ye_emlrtRTEI = { 337,/* lineNo */
  32,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_af_emlrtRTEI = { 339,/* lineNo */
  13,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_bf_emlrtRTEI = { 340,/* lineNo */
  23,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_cf_emlrtRTEI = { 25,/* lineNo */
  18,                                  /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo c1_df_emlrtRTEI = { 339,/* lineNo */
  32,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_ef_emlrtRTEI = { 31,/* lineNo */
  14,                                  /* colNo */
  "svd",                               /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/matfun/svd.m"/* pName */
};

static emlrtRTEInfo c1_ff_emlrtRTEI = { 329,/* lineNo */
  14,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_gf_emlrtRTEI = { 103,/* lineNo */
  1,                                   /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo c1_hf_emlrtRTEI = { 398,/* lineNo */
  37,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_if_emlrtRTEI = { 400,/* lineNo */
  37,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_jf_emlrtRTEI = { 402,/* lineNo */
  12,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_kf_emlrtRTEI = { 402,/* lineNo */
  1,                                   /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_lf_emlrtRTEI = { 403,/* lineNo */
  12,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_mf_emlrtRTEI = { 403,/* lineNo */
  1,                                   /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_nf_emlrtRTEI = { 393,/* lineNo */
  5,                                   /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_of_emlrtRTEI = { 16,/* lineNo */
  1,                                   /* colNo */
  "normalizePoints",                   /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/normalizePoints.m"/* pName */
};

static emlrtRTEInfo c1_pf_emlrtRTEI = { 22,/* lineNo */
  20,                                  /* colNo */
  "normalizePoints",                   /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/normalizePoints.m"/* pName */
};

static emlrtRTEInfo c1_qf_emlrtRTEI = { 45,/* lineNo */
  6,                                   /* colNo */
  "applyBinaryScalarFunction",         /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"/* pName */
};

static emlrtRTEInfo c1_rf_emlrtRTEI = { 25,/* lineNo */
  45,                                  /* colNo */
  "normalizePoints",                   /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/normalizePoints.m"/* pName */
};

static emlrtRTEInfo c1_sf_emlrtRTEI = { 58,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/ops/power.m"/* pName */
};

static emlrtRTEInfo c1_tf_emlrtRTEI = { 77,/* lineNo */
  13,                                  /* colNo */
  "blockedSummation",                  /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/datafun/private/blockedSummation.m"/* pName */
};

static emlrtRTEInfo c1_uf_emlrtRTEI = { 9,/* lineNo */
  1,                                   /* colNo */
  "sum",                               /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/datafun/sum.m"/* pName */
};

static emlrtRTEInfo c1_vf_emlrtRTEI = { 15,/* lineNo */
  1,                                   /* colNo */
  "sqrt",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtRTEInfo c1_wf_emlrtRTEI = { 46,/* lineNo */
  5,                                   /* colNo */
  "normalizePoints",                   /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/normalizePoints.m"/* pName */
};

static emlrtRTEInfo c1_xf_emlrtRTEI = { 25,/* lineNo */
  41,                                  /* colNo */
  "normalizePoints",                   /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/normalizePoints.m"/* pName */
};

static emlrtRTEInfo c1_yf_emlrtRTEI = { 25,/* lineNo */
  36,                                  /* colNo */
  "normalizePoints",                   /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/normalizePoints.m"/* pName */
};

static emlrtRTEInfo c1_ag_emlrtRTEI = { 76,/* lineNo */
  66,                                  /* colNo */
  "svd",                               /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/eml/+coder/+internal/svd.m"/* pName */
};

static emlrtRTEInfo c1_bg_emlrtRTEI = { 76,/* lineNo */
  9,                                   /* colNo */
  "svd",                               /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/eml/+coder/+internal/svd.m"/* pName */
};

static emlrtRTEInfo c1_cg_emlrtRTEI = { 51,/* lineNo */
  28,                                  /* colNo */
  "svd",                               /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/eml/+coder/+internal/svd.m"/* pName */
};

static emlrtRTEInfo c1_dg_emlrtRTEI = { 51,/* lineNo */
  5,                                   /* colNo */
  "svd",                               /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/eml/+coder/+internal/svd.m"/* pName */
};

static emlrtRTEInfo c1_eg_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "svd",                               /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/eml/+coder/+internal/svd.m"/* pName */
};

static emlrtRTEInfo c1_fg_emlrtRTEI = { 48,/* lineNo */
  25,                                  /* colNo */
  "xgesvd",                            /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pName */
};

static emlrtRTEInfo c1_gg_emlrtRTEI = { 112,/* lineNo */
  9,                                   /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo c1_hg_emlrtRTEI = { 412,/* lineNo */
  11,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_ig_emlrtRTEI = { 416,/* lineNo */
  1,                                   /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_jg_emlrtRTEI = { 417,/* lineNo */
  1,                                   /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_kg_emlrtRTEI = { 418,/* lineNo */
  1,                                   /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_lg_emlrtRTEI = { 20,/* lineNo */
  5,                                   /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo c1_mg_emlrtRTEI = { 419,/* lineNo */
  1,                                   /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_ng_emlrtRTEI = { 420,/* lineNo */
  1,                                   /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_og_emlrtRTEI = { 19,/* lineNo */
  24,                                  /* colNo */
  "scalexpAllocNoCheck",               /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/eml/+coder/+internal/scalexpAllocNoCheck.m"/* pName */
};

static emlrtRTEInfo c1_pg_emlrtRTEI = { 421,/* lineNo */
  15,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_qg_emlrtRTEI = { 421,/* lineNo */
  26,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_rg_emlrtRTEI = { 12,/* lineNo */
  5,                                   /* colNo */
  "hypot",                             /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elfun/hypot.m"/* pName */
};

static emlrtRTEInfo c1_sg_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "abs",                               /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elfun/abs.m"/* pName */
};

static emlrtRTEInfo c1_tg_emlrtRTEI = { 422,/* lineNo */
  5,                                   /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_ug_emlrtRTEI = { 411,/* lineNo */
  16,                                  /* colNo */
  "estimateGeometricTransform",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/estimateGeometricTransform.m"/* pName */
};

static emlrtRTEInfo c1_vg_emlrtRTEI = { 12,/* lineNo */
  1,                                   /* colNo */
  "isfinite",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elmat/isfinite.m"/* pName */
};

static emlrtRTEInfo c1_wg_emlrtRTEI = { 20,/* lineNo */
  1,                                   /* colNo */
  "det",                               /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/matfun/det.m"/* pName */
};

static emlrtRTEInfo c1_xg_emlrtRTEI = { 1,/* lineNo */
  26,                                  /* colNo */
  "xgetrf",                            /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pName */
};

static emlrtRTEInfo c1_yg_emlrtRTEI = { 574,/* lineNo */
  7,                                   /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_ah_emlrtRTEI = { 575,/* lineNo */
  14,                                  /* colNo */
  "PointTracker",                      /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/PointTracker.m"/* pName */
};

static emlrtRTEInfo c1_bh_emlrtRTEI = { 53,/* lineNo */
  5,                                   /* colNo */
  "xgetrf",                            /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pName */
};

static emlrtRTEInfo c1_ch_emlrtRTEI = { 27,/* lineNo */
  5,                                   /* colNo */
  "xgetrf",                            /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pName */
};

static const char_T c1_cv0[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y',
  's', 't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
  'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o', 'd',
  'e', 'g', 'e', 'n' };

static const char_T c1_cv1[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
  'L', 'A', 'B', ':', 'i', 'n', 'n', 'e', 'r', 'd', 'i', 'm' };

static const char_T c1_cv2[45] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'm', 't', 'i', 'm', 'e', 's', '_', 'n', 'o', 'D', 'y',
  'n', 'a', 'm', 'i', 'c', 'S', 'c', 'a', 'l', 'a', 'r', 'E', 'x', 'p', 'a', 'n',
  's', 'i', 'o', 'n' };

static const char_T c1_cv3[36] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'P', 'o',
  'i', 'n', 't', 'T', 'r', 'a', 'c', 'k', 'e', 'r', ':', 'e', 'x', 'p', 'e', 'c',
  't', 'e', 'd', 'N', 'o', 'n', 'e', 'm', 'p', 't', 'y' };

static const char_T c1_cv4[26] = { 'E', 'x', 'p', 'e', 'c', 't', 'e', 'd', ' ',
  'I', ' ', 't', 'o', ' ', 'b', 'e', ' ', 'n', 'o', 'n', 'e', 'm', 'p', 't', 'y',
  '.' };

static const char_T c1_cv5[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y',
  's', 't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
  'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e', 'a',
  's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

static const char_T c1_cv6[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
  'E', 'r', 'r', 'o', 'r' };

static const char_T c1_cv7[55] = { 'v', 'i', 's', 'i', 'o', 'n', ':', 'P', 'o',
  'i', 'n', 't', 'T', 'r', 'a', 'c', 'k', 'e', 'r', ':', 'e', 'x', 'p', 'e', 'c',
  't', 'e', 'd', 'S', 'a', 'm', 'e', 'I', 'm', 'a', 'g', 'e', 'C', 'l', 'a', 's',
  's', 'A', 's', 'I', 'n', 'i', 't', 'i', 'a', 'l', 'i', 'z', 'e', 'd' };

static const char_T c1_cv8[31] = { 'v', 'i', 's', 'i', 'o', 'n', ':', 'P', 'o',
  'i', 'n', 't', 'T', 'r', 'a', 'c', 'k', 'e', 'r', ':', 'e', 'x', 'p', 'e', 'c',
  't', 'e', 'd', 'R', 'G', 'B' };

static const char_T c1_cv9[54] = { 'v', 'i', 's', 'i', 'o', 'n', ':', 'P', 'o',
  'i', 'n', 't', 'T', 'r', 'a', 'c', 'k', 'e', 'r', ':', 'e', 'x', 'p', 'e', 'c',
  't', 'e', 'd', 'S', 'a', 'm', 'e', 'I', 'm', 'a', 'g', 'e', 'S', 'i', 'z', 'e',
  'A', 's', 'I', 'n', 'i', 't', 'i', 'a', 'l', 'i', 'z', 'e', 'd' };

static const char_T c1_cv10[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a',
  't', 'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i', 'm',
  'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

static const real32_T c1_fv0[3] = { 0.0F, 0.0F, 1.0F };

static const char_T c1_cv11[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i',
  'm', 'a', 'g', 'r', 'e', 'e' };

static const char_T c1_cv12[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
  'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

static const char_T c1_cv13[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K', 'C', 'a', 'l', 'l', 'E',
  'r', 'r', 'o', 'r', 'I', 'n', 'f', 'o' };

static const char_T c1_cv14[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r', '_',
  'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o', 'm',
  'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

/* Function Declarations */
static void initialize_c1_DetectAndTrackFace
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance);
static void initialize_params_c1_DetectAndTrackFace
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance);
static void enable_c1_DetectAndTrackFace(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance);
static void disable_c1_DetectAndTrackFace(SFc1_DetectAndTrackFaceInstanceStruct *
  chartInstance);
static void c1_update_debugger_state_c1_DetectAndTrackFace
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_DetectAndTrackFace
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance);
static void set_sim_state_c1_DetectAndTrackFace
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_DetectAndTrackFace(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance);
static void sf_gateway_c1_DetectAndTrackFace
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance);
static void mdl_start_c1_DetectAndTrackFace
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance);
static void c1_chartstep_c1_DetectAndTrackFace
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance);
static void initSimStructsc1_DetectAndTrackFace
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static void c1_eML_blk_kernel_free(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_numPts, const char_T *c1_identifier,
  boolean_T *c1_svPtr);
static real_T c1_b_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T *c1_svPtr);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[], int32_T c1_inData_size[2]);
static void c1_c_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_bboxPoints, const char_T *c1_identifier,
  boolean_T *c1_svPtr, real_T c1_y_data[], int32_T c1_y_size[2]);
static void c1_d_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T *c1_svPtr, real_T c1_y_data[], int32_T c1_y_size[2]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[], int32_T
  c1_outData_size[2]);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, real32_T
  c1_inData_data[], int32_T c1_inData_size[2]);
static void c1_e_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_oldPoints, const char_T *c1_identifier,
  boolean_T *c1_svPtr, real32_T c1_y_data[], int32_T c1_y_size[2]);
static void c1_f_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T *c1_svPtr, real32_T c1_y_data[], int32_T c1_y_size[2]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real32_T c1_outData_data[],
  int32_T c1_outData_size[2]);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_g_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_numberOfFeaturePoints, const char_T
  *c1_identifier);
static real_T c1_h_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, real32_T
  c1_inData_data[], int32_T c1_inData_size[2]);
static void c1_i_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_newFeaturePointLocations, const char_T
  *c1_identifier, real32_T c1_y_data[], int32_T c1_y_size[2]);
static void c1_j_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  real32_T c1_y_data[], int32_T c1_y_size[2]);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real32_T c1_outData_data[],
  int32_T c1_outData_size[2]);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[], int32_T c1_inData_size[2]);
static void c1_k_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_bBoxCornerPts, const char_T *c1_identifier,
  real_T c1_y_data[], int32_T c1_y_size[2]);
static void c1_l_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y_data[], int32_T c1_y_size[2]);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[], int32_T
  c1_outData_size[2]);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[], int32_T c1_inData_size[2]);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid,
  c1_emxArray_real_T *c1_inData);
static void c1_m_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  c1_emxArray_real_T *c1_y);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, c1_emxArray_real_T *c1_outData);
static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, c1_affine2d
  *c1_inData);
static void c1_n_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  c1_affine2d *c1_y);
static void c1_o_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  real32_T c1_y_data[], int32_T c1_y_size[2]);
static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, c1_affine2d *c1_outData);
static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid,
  c1_emxArray_real32_T *c1_inData);
static void c1_p_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  c1_emxArray_real32_T *c1_y);
static void c1_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, c1_emxArray_real32_T *c1_outData);
static const mxArray *c1_l_sf_marshallOut(void *chartInstanceVoid,
  c1_emxArray_boolean_T *c1_inData);
static void c1_q_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  c1_emxArray_boolean_T *c1_y);
static void c1_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, c1_emxArray_boolean_T *c1_outData);
static void c1_PointTracker_initialize(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_vision_PointTracker *c1_obj, c1_emxArray_real_T *c1_I);
static void c1_im2uint8(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  c1_emxArray_real_T *c1_img, c1_emxArray_uint8_T *c1_b_u);
static c1_skA5dKpnjgSNaA6XSElXHZH c1_PointTracker_getKLTParams
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance, c1_vision_PointTracker *
   c1_obj);
static void c1_check_forloop_overflow_error
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance, boolean_T c1_overflow);
static void c1_error(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance);
static void c1_b_PointTracker_initialize(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_vision_PointTracker *c1_obj, real32_T c1_points_data[],
  int32_T c1_points_size[2], c1_emxArray_real_T *c1_I);
static void c1_PointTracker_validatePoints(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, real32_T c1_points_data[], int32_T c1_points_size[2]);
static boolean_T c1_all(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  real32_T c1_a_data[], int32_T c1_a_size[2]);
static void c1_SystemCore_step(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_vision_PointTracker *c1_obj, c1_emxArray_real_T
  *c1_varargin_1);
static boolean_T c1_SystemCore_detectInputSizeChange
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance, c1_vision_PointTracker *
   c1_obj, c1_emxArray_real_T *c1_varargin_1);
static void c1_PointTracker_pointsOutsideImage
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance, c1_vision_PointTracker *
   c1_obj, c1_emxArray_real32_T *c1_points, c1_emxArray_boolean_T *c1_inds);
static void c1_PointTracker_normalizeScores
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance, c1_vision_PointTracker *
   c1_obj, c1_emxArray_real_T *c1_scores, c1_emxArray_boolean_T *c1_validity,
   c1_emxArray_real_T *c1_b_scores);
static void c1_b_error(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance);
static void c1_bbox2points(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  real_T c1_bbox_data[], int32_T c1_bbox_size[2], real_T c1_points[8]);
static void c1_b_SystemCore_step(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_vision_PointTracker *c1_obj, c1_emxArray_real_T
  *c1_varargin_1, c1_emxArray_real32_T *c1_varargout_1, c1_emxArray_boolean_T
  *c1_varargout_2);
static boolean_T c1_size_check(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T *c1_a);
static void c1_estimateGeometricTransform(SFc1_DetectAndTrackFaceInstanceStruct *
  chartInstance, c1_emxArray_real32_T *c1_matchedPoints1, c1_emxArray_real32_T
  *c1_matchedPoints2, c1_affine2d *c1_tform, c1_emxArray_real32_T
  *c1_inlierPoints1, c1_emxArray_real32_T *c1_inlierPoints2);
static void c1_c_error(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance);
static void c1_msac(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
                    c1_emxArray_real32_T *c1_allPoints,
                    c1_svT7UAnr23JjyThWngsAoUB c1_params, boolean_T *c1_isFound,
                    real32_T c1_bestModelParams_data[], int32_T
                    c1_bestModelParams_size[2], c1_emxArray_boolean_T
                    *c1_inliers);
static real_T c1_rand(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance);
static void c1_eml_rand_mt19937ar(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, uint32_T c1_d_state[625], uint32_T c1_e_state[625], real_T
  *c1_r);
static void c1_d_error(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance);
static real_T c1_mod(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
                     real_T c1_x, real_T c1_y);
static void c1_computeSimilarity(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T *c1_points, real32_T c1_T[9]);
static void c1_normalizePoints(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T *c1_points, c1_emxArray_real32_T
  *c1_samples1, c1_emxArray_real32_T *c1_samples2, real32_T c1_normMatrix1[9],
  real32_T c1_normMatrix2[9]);
static void c1_b_normalizePoints(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T *c1_p, c1_emxArray_real32_T
  *c1_normPoints, real32_T c1_T[9]);
static boolean_T c1_dimagree(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T *c1_z, c1_emxArray_real32_T
  *c1_varargin_1);
static real32_T c1_mean(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  c1_emxArray_real32_T *c1_x);
static void c1_svd(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
                   c1_emxArray_real32_T *c1_A, c1_emxArray_real32_T *c1_U,
                   real32_T c1_s_data[], int32_T c1_s_size[1], real32_T c1_V[25]);
static void c1_e_error(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance);
static void c1_f_error(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  int32_T c1_varargin_2);
static void c1_ceval_xgesvd(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  c1_emxArray_real32_T *c1_A, c1_emxArray_real32_T *c1_U, real32_T c1_S_data[],
  int32_T c1_S_size[1], real32_T c1_V[25], int32_T *c1_info);
static void c1_g_error(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  int32_T c1_varargin_2);
static void c1_h_error(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance);
static void c1_warning(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance);
static void c1_evaluateTForm(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, real32_T c1_tform[9], c1_emxArray_real32_T *c1_points,
  c1_emxArray_real32_T *c1_dis);
static boolean_T c1_b_dimagree(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T *c1_z, c1_emxArray_real32_T
  *c1_varargin_1, c1_emxArray_real32_T *c1_varargin_2);
static real32_T c1_sum(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  c1_emxArray_real32_T *c1_x);
static real_T c1_b_sum(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  c1_emxArray_boolean_T *c1_x);
static void c1_i_error(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance);
static boolean_T c1_checkTForm(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, real32_T c1_tform_data[], int32_T c1_tform_size[2]);
static boolean_T c1_any(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  c1_emxArray_boolean_T *c1_x);
static real32_T c1_det(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  real32_T c1_x_data[], int32_T c1_x_size[2]);
static void c1_xgetrf(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
                      int32_T c1_m, int32_T c1_n, real32_T c1_A_data[], int32_T
                      c1_A_size[2], int32_T c1_lda, real32_T c1_b_A_data[],
                      int32_T c1_b_A_size[2], int32_T c1_ipiv_data[], int32_T
                      c1_ipiv_size[2]);
static void c1_j_error(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  int32_T c1_varargin_2);
static const mxArray *c1_m_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_r_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_n_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[16], int32_T c1_inData_sizes[2]);
static const mxArray *c1_o_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[8], int32_T c1_inData_sizes[2]);
static void c1_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[8],
  int32_T c1_outData_sizes[2]);
static const mxArray *c1_p_sf_marshallOut(void *chartInstanceVoid, real32_T
  c1_inData_data[1000], int32_T c1_inData_sizes[2]);
static void c1_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real32_T c1_outData_data[1000],
  int32_T c1_outData_sizes[2]);
static uint32_T c1_s_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_method, const char_T *c1_identifier,
  boolean_T *c1_svPtr);
static uint32_T c1_t_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T *c1_svPtr);
static void c1_u_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_d_state, const char_T *c1_identifier,
  boolean_T *c1_svPtr, uint32_T c1_y[625]);
static void c1_v_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T *c1_svPtr, uint32_T c1_y[625]);
static void c1_w_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_d_state, const char_T *c1_identifier,
  boolean_T *c1_svPtr, uint32_T c1_y[2]);
static void c1_x_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T *c1_svPtr, uint32_T c1_y[2]);
static uint8_T c1_y_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_DetectAndTrackFace, const
  char_T *c1_identifier);
static uint8_T c1_ab_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_PointTracker_normalizeScores
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance, c1_vision_PointTracker *
   c1_obj, c1_emxArray_real_T *c1_scores, c1_emxArray_boolean_T *c1_validity);
static real_T c1_b_eml_rand_mt19937ar(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, uint32_T c1_d_state[625]);
static void c1_b_xgetrf(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  int32_T c1_m, int32_T c1_n, real32_T c1_A_data[], int32_T c1_A_size[2],
  int32_T c1_lda, int32_T c1_ipiv_data[], int32_T c1_ipiv_size[2]);
static void c1_emxEnsureCapacity_real_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real_T *c1_emxArray, int32_T c1_oldNumel, const
  emlrtRTEInfo *c1_srcLocation);
static void c1_emxEnsureCapacity_boolean_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_boolean_T *c1_emxArray, int32_T c1_oldNumel, const
  emlrtRTEInfo *c1_srcLocation);
static void c1_emxEnsureCapacity_int32_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_int32_T *c1_emxArray, int32_T c1_oldNumel, const
  emlrtRTEInfo *c1_srcLocation);
static void c1_emxEnsureCapacity_real32_T(SFc1_DetectAndTrackFaceInstanceStruct *
  chartInstance, c1_emxArray_real32_T *c1_emxArray, int32_T c1_oldNumel, const
  emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_boolean_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_boolean_T **c1_pEmxArray, int32_T c1_numDimensions,
  const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_real32_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T **c1_pEmxArray, int32_T c1_numDimensions,
  const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_real_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real_T **c1_pEmxArray, int32_T c1_numDimensions,
  const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_int32_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_int32_T **c1_pEmxArray, int32_T c1_numDimensions,
  const emlrtRTEInfo *c1_srcLocation);
static void c1_emxFree_boolean_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_boolean_T **c1_pEmxArray);
static void c1_emxFree_real32_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T **c1_pEmxArray);
static void c1_emxFree_real_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real_T **c1_pEmxArray);
static void c1_emxFree_int32_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_int32_T **c1_pEmxArray);
static void c1_emxEnsureCapacity_uint8_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_uint8_T *c1_emxArray, int32_T c1_oldNumel, const
  emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_uint8_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_uint8_T **c1_pEmxArray, int32_T c1_numDimensions,
  const emlrtRTEInfo *c1_srcLocation);
static void c1_emxFree_uint8_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_uint8_T **c1_pEmxArray);
static void c1_emxEnsureCapacity_real_T1(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real_T *c1_emxArray, int32_T c1_oldNumel, const
  emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_real_T1(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real_T **c1_pEmxArray, int32_T c1_numDimensions,
  const emlrtRTEInfo *c1_srcLocation);
static void c1_emxEnsureCapacity_real32_T1(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T *c1_emxArray, int32_T c1_oldNumel, const
  emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_real32_T1(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T **c1_pEmxArray, int32_T c1_numDimensions,
  const emlrtRTEInfo *c1_srcLocation);
static void c1_emxEnsureCapacity_boolean_T1
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance, c1_emxArray_boolean_T
   *c1_emxArray, int32_T c1_oldNumel, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxEnsureCapacity_real32_T2(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T *c1_emxArray, int32_T c1_oldNumel, const
  emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_real32_T2(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T **c1_pEmxArray, int32_T c1_numDimensions,
  const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_boolean_T1(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_boolean_T **c1_pEmxArray, int32_T c1_numDimensions,
  const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInitStruct_cell_19(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_cell_19 *c1_pStruct, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxFreeStruct_cell_19(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_cell_19 *c1_pStruct);
static void c1_emxInitMatrix_cell_wrap_20(SFc1_DetectAndTrackFaceInstanceStruct *
  chartInstance, c1_cell_wrap_20 c1_pMatrix[2], const emlrtRTEInfo
  *c1_srcLocation);
static void c1_emxInitStruct_cell_wrap_20(SFc1_DetectAndTrackFaceInstanceStruct *
  chartInstance, c1_cell_wrap_20 *c1_pStruct, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxFreeMatrix_cell_wrap_20(SFc1_DetectAndTrackFaceInstanceStruct *
  chartInstance, c1_cell_wrap_20 c1_pMatrix[2]);
static void c1_emxFreeStruct_cell_wrap_20(SFc1_DetectAndTrackFaceInstanceStruct *
  chartInstance, c1_cell_wrap_20 *c1_pStruct);
static int32_T c1_div_s32_floor(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, int32_T c1_numerator, int32_T c1_denominator, uint32_T
  c1_ssid_src_loc, int32_T c1_offset_src_loc, int32_T c1_length_src_loc);
static int32_T c1_div_nzp_s32(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, int32_T c1_numerator, int32_T c1_denominator, uint32_T
  c1_ssid_src_loc, int32_T c1_offset_src_loc, int32_T c1_length_src_loc);
static int32_T c1__s32_d_(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  real_T c1_b, uint32_T c1_ssid_src_loc, int32_T c1_offset_src_loc, int32_T
  c1_length_src_loc);
static void init_dsm_address_info(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_DetectAndTrackFace
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  emlrtLicenseCheckR2012b(chartInstance->c1_fEmlrtCtx,
    "Video_and_Image_Blockset", 2);
  emlrtLicenseCheckR2012b(chartInstance->c1_fEmlrtCtx, "Image_Toolbox", 2);
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc1_DetectAndTrackFace(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_pointTracker_not_empty = false;
  chartInstance->c1_oldPoints_not_empty = false;
  chartInstance->c1_bboxPoints_not_empty = false;
  chartInstance->c1_first_time_not_empty = false;
  chartInstance->c1_numPts_not_empty = false;
  chartInstance->c1_method_not_empty = false;
  chartInstance->c1_state_not_empty = false;
  chartInstance->c1_b_state_not_empty = false;
  chartInstance->c1_c_state_not_empty = false;
  chartInstance->c1_is_active_c1_DetectAndTrackFace = 0U;
  chartInstance->c1_oldPoints.size[1] = 0;
  chartInstance->c1_bboxPoints.size[1] = 0;
  sf_mex_assign(&c1_b_eml_mx, sf_mex_create("eml_mx", NULL, 0, 0U, 1U, 0U, 2, 0,
    0), true);
  sf_mex_assign(&c1_eml_mx, sf_mex_create("eml_mx", NULL, 10, 0U, 1U, 0U, 2, 0,
    0), true);
}

static void initialize_params_c1_DetectAndTrackFace
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_DetectAndTrackFace(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_DetectAndTrackFace(SFc1_DetectAndTrackFaceInstanceStruct *
  chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_DetectAndTrackFace
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_DetectAndTrackFace
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  real_T c1_hoistedGlobal;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  real_T c1_b_hoistedGlobal;
  const mxArray *c1_f_y = NULL;
  uint32_T c1_c_hoistedGlobal;
  const mxArray *c1_g_y = NULL;
  real_T c1_d_hoistedGlobal;
  const mxArray *c1_h_y = NULL;
  const mxArray *c1_i_y = NULL;
  uint32_T c1_e_hoistedGlobal;
  const mxArray *c1_j_y = NULL;
  const mxArray *c1_k_y = NULL;
  const mxArray *c1_l_y = NULL;
  uint8_T c1_f_hoistedGlobal;
  const mxArray *c1_m_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(12, 1), false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", (void *)
    chartInstance->c1_bBoxCornerPts_data, 0, 0U, 1U, 0U, 2,
    (*chartInstance->c1_bBoxCornerPts_sizes)[0],
    (*chartInstance->c1_bBoxCornerPts_sizes)[1]), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", (void *)
    chartInstance->c1_newFeaturePointLocations_data, 1, 0U, 1U, 0U, 2,
    (*chartInstance->c1_newFeaturePointLocations_sizes)[0],
    (*chartInstance->c1_newFeaturePointLocations_sizes)[1]), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_hoistedGlobal = *chartInstance->c1_numberOfFeaturePoints;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_hoistedGlobal, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_e_y = NULL;
  if (!chartInstance->c1_bboxPoints_not_empty) {
    sf_mex_assign(&c1_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_e_y, sf_mex_create("y", chartInstance->c1_bboxPoints.data,
      0, 0U, 1U, 0U, 2, chartInstance->c1_bboxPoints.size[0],
      chartInstance->c1_bboxPoints.size[1]), false);
  }

  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_b_hoistedGlobal = chartInstance->c1_first_time;
  c1_f_y = NULL;
  if (!chartInstance->c1_numPts_not_empty) {
    sf_mex_assign(&c1_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_b_hoistedGlobal, 0, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_c_hoistedGlobal = chartInstance->c1_method;
  c1_g_y = NULL;
  if (!chartInstance->c1_method_not_empty) {
    sf_mex_assign(&c1_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_c_hoistedGlobal, 7, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_d_hoistedGlobal = chartInstance->c1_numPts;
  c1_h_y = NULL;
  if (!chartInstance->c1_numPts_not_empty) {
    sf_mex_assign(&c1_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_d_hoistedGlobal, 0, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c1_y, 6, c1_h_y);
  c1_i_y = NULL;
  if (!chartInstance->c1_oldPoints_not_empty) {
    sf_mex_assign(&c1_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_i_y, sf_mex_create("y", chartInstance->c1_oldPoints.data,
      1, 0U, 1U, 0U, 2, chartInstance->c1_oldPoints.size[0],
      chartInstance->c1_oldPoints.size[1]), false);
  }

  sf_mex_setcell(c1_y, 7, c1_i_y);
  c1_e_hoistedGlobal = chartInstance->c1_state;
  c1_j_y = NULL;
  if (!chartInstance->c1_method_not_empty) {
    sf_mex_assign(&c1_j_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_e_hoistedGlobal, 7, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c1_y, 8, c1_j_y);
  c1_k_y = NULL;
  if (!chartInstance->c1_c_state_not_empty) {
    sf_mex_assign(&c1_k_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_k_y, sf_mex_create("y", chartInstance->c1_c_state, 7, 0U,
      1U, 0U, 1, 625), false);
  }

  sf_mex_setcell(c1_y, 9, c1_k_y);
  c1_l_y = NULL;
  if (!chartInstance->c1_b_state_not_empty) {
    sf_mex_assign(&c1_l_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_l_y, sf_mex_create("y", chartInstance->c1_b_state, 7, 0U,
      1U, 0U, 1, 2), false);
  }

  sf_mex_setcell(c1_y, 10, c1_l_y);
  c1_f_hoistedGlobal = chartInstance->c1_is_active_c1_DetectAndTrackFace;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_f_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 11, c1_m_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_DetectAndTrackFace
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_b_u;
  real_T c1_tmp_data[8];
  int32_T c1_tmp_size[2];
  int32_T c1_i0;
  int32_T c1_i1;
  int32_T c1_loop_ub;
  int32_T c1_i2;
  real32_T c1_b_tmp_data[1000];
  int32_T c1_b_tmp_size[2];
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_b_loop_ub;
  int32_T c1_i5;
  real_T c1_c_tmp_data[8];
  int32_T c1_c_tmp_size[2];
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_c_loop_ub;
  int32_T c1_i8;
  real32_T c1_d_tmp_data[1000];
  int32_T c1_d_tmp_size[2];
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_d_loop_ub;
  int32_T c1_i11;
  uint32_T c1_uv0[625];
  int32_T c1_i12;
  uint32_T c1_uv1[2];
  int32_T c1_i13;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_b_u = sf_mex_dup(c1_st);
  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_b_u, 0)),
                        "bBoxCornerPts", c1_tmp_data, c1_tmp_size);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 0, c1_tmp_size[0]);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 1, c1_tmp_size[1]);
  c1_i0 = (*chartInstance->c1_bBoxCornerPts_sizes)[0];
  c1_i1 = (*chartInstance->c1_bBoxCornerPts_sizes)[1];
  c1_loop_ub = c1_tmp_size[0] * c1_tmp_size[1] - 1;
  for (c1_i2 = 0; c1_i2 <= c1_loop_ub; c1_i2++) {
    (*chartInstance->c1_bBoxCornerPts_data)[c1_i2] = c1_tmp_data[c1_i2];
  }

  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_b_u, 1)),
                        "newFeaturePointLocations", c1_b_tmp_data, c1_b_tmp_size);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 2, 0,
    c1_b_tmp_size[0]);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 2, 1,
    c1_b_tmp_size[1]);
  c1_i3 = (*chartInstance->c1_newFeaturePointLocations_sizes)[0];
  c1_i4 = (*chartInstance->c1_newFeaturePointLocations_sizes)[1];
  c1_b_loop_ub = c1_b_tmp_size[0] * c1_b_tmp_size[1] - 1;
  for (c1_i5 = 0; c1_i5 <= c1_b_loop_ub; c1_i5++) {
    (*chartInstance->c1_newFeaturePointLocations_data)[c1_i5] =
      c1_b_tmp_data[c1_i5];
  }

  *chartInstance->c1_numberOfFeaturePoints = c1_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_b_u, 2)), "numberOfFeaturePoints");
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_b_u, 3)),
                        "bboxPoints", &chartInstance->c1_bboxPoints_not_empty,
                        c1_c_tmp_data, c1_c_tmp_size);
  chartInstance->c1_bboxPoints.size[0] = c1_c_tmp_size[0];
  chartInstance->c1_bboxPoints.size[1] = 2;
  c1_i6 = chartInstance->c1_bboxPoints.size[0];
  c1_i7 = chartInstance->c1_bboxPoints.size[1];
  c1_c_loop_ub = c1_c_tmp_size[0] * c1_c_tmp_size[1] - 1;
  for (c1_i8 = 0; c1_i8 <= c1_c_loop_ub; c1_i8++) {
    chartInstance->c1_bboxPoints.data[c1_i8] = c1_c_tmp_data[c1_i8];
  }

  chartInstance->c1_first_time = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_b_u, 4)), "first_time",
    &chartInstance->c1_first_time_not_empty);
  chartInstance->c1_method = c1_s_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_b_u, 5)), "method", &chartInstance->c1_method_not_empty);
  chartInstance->c1_numPts = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_b_u, 6)), "numPts", &chartInstance->c1_numPts_not_empty);
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_b_u, 7)),
                        "oldPoints", &chartInstance->c1_oldPoints_not_empty,
                        c1_d_tmp_data, c1_d_tmp_size);
  chartInstance->c1_oldPoints.size[0] = c1_d_tmp_size[0];
  chartInstance->c1_oldPoints.size[1] = c1_d_tmp_size[1];
  c1_i9 = chartInstance->c1_oldPoints.size[0];
  c1_i10 = chartInstance->c1_oldPoints.size[1];
  c1_d_loop_ub = c1_d_tmp_size[0] * c1_d_tmp_size[1] - 1;
  for (c1_i11 = 0; c1_i11 <= c1_d_loop_ub; c1_i11++) {
    chartInstance->c1_oldPoints.data[c1_i11] = c1_d_tmp_data[c1_i11];
  }

  chartInstance->c1_state = c1_s_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_b_u, 8)), "state", &chartInstance->c1_state_not_empty);
  c1_u_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_b_u, 9)),
                        "state", &chartInstance->c1_c_state_not_empty, c1_uv0);
  for (c1_i12 = 0; c1_i12 < 625; c1_i12++) {
    chartInstance->c1_c_state[c1_i12] = c1_uv0[c1_i12];
  }

  c1_w_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_b_u, 10)),
                        "state", &chartInstance->c1_b_state_not_empty, c1_uv1);
  for (c1_i13 = 0; c1_i13 < 2; c1_i13++) {
    chartInstance->c1_b_state[c1_i13] = c1_uv1[c1_i13];
  }

  chartInstance->c1_is_active_c1_DetectAndTrackFace = c1_y_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_b_u, 11)),
     "is_active_c1_DetectAndTrackFace");
  sf_mex_destroy(&c1_b_u);
  c1_update_debugger_state_c1_DetectAndTrackFace(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_DetectAndTrackFace(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance)
{
  c1_eML_blk_kernel_free(chartInstance);
  sf_mex_destroy(&c1_eml_mx);
  sf_mex_destroy(&c1_b_eml_mx);
}

static void sf_gateway_c1_DetectAndTrackFace
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  int32_T c1_loop_ub;
  int32_T c1_i14;
  int32_T c1_b_loop_ub;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_c_loop_ub;
  int32_T c1_i17;
  int32_T c1_d_loop_ub;
  int32_T c1_i18;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_loop_ub = (*chartInstance->c1_featurePointLocations_sizes)[0] *
    (*chartInstance->c1_featurePointLocations_sizes)[1] - 1;
  for (c1_i14 = 0; c1_i14 <= c1_loop_ub; c1_i14++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c1_featurePointLocations_data)
                          [c1_i14], 3U);
  }

  c1_b_loop_ub = (*chartInstance->c1_bBox_sizes)[0] *
    (*chartInstance->c1_bBox_sizes)[1] - 1;
  for (c1_i15 = 0; c1_i15 <= c1_b_loop_ub; c1_i15++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_bBox_data)[c1_i15], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_decimationFactor, 1U);
  for (c1_i16 = 0; c1_i16 < 1048576; c1_i16++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_b_videoFrameGray)[c1_i16], 0U);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_DetectAndTrackFace(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DetectAndTrackFaceMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  c1_c_loop_ub = (*chartInstance->c1_bBoxCornerPts_sizes)[0] *
    (*chartInstance->c1_bBoxCornerPts_sizes)[1] - 1;
  for (c1_i17 = 0; c1_i17 <= c1_c_loop_ub; c1_i17++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_bBoxCornerPts_data)[c1_i17], 4U);
  }

  c1_d_loop_ub = (*chartInstance->c1_newFeaturePointLocations_sizes)[0] *
    (*chartInstance->c1_newFeaturePointLocations_sizes)[1] - 1;
  for (c1_i18 = 0; c1_i18 <= c1_d_loop_ub; c1_i18++) {
    _SFD_DATA_RANGE_CHECK((real_T)
                          (*chartInstance->c1_newFeaturePointLocations_data)
                          [c1_i18], 5U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_numberOfFeaturePoints, 6U);
}

static void mdl_start_c1_DetectAndTrackFace
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void c1_chartstep_c1_DetectAndTrackFace
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  c1_emxArray_boolean_T *c1_isFound;
  c1_emxArray_real32_T *c1_visiblePoints;
  c1_emxArray_real32_T *c1_oldInliers;
  c1_emxArray_real_T *c1_c_videoFrameGray;
  int32_T c1_i19;
  real_T c1_b_decimationFactor;
  int32_T c1_bBox_size[2];
  int32_T c1_bBox;
  int32_T c1_b_bBox;
  int32_T c1_loop_ub;
  int32_T c1_i20;
  int32_T c1_featurePointLocations_size[2];
  real_T c1_b_bBox_data[16];
  int32_T c1_featurePointLocations;
  int32_T c1_b_featurePointLocations;
  int32_T c1_b_loop_ub;
  int32_T c1_i21;
  uint32_T c1_debug_family_var_map[17];
  real32_T c1_b_featurePointLocations_data[1000];
  c1_affine2d c1_xform;
  real_T c1_nargin = 4.0;
  real_T c1_nargout = 3.0;
  real_T c1_b_bBoxCornerPts_data[8];
  int32_T c1_bBoxCornerPts_size[2];
  real32_T c1_b_newFeaturePointLocations_data[1000];
  int32_T c1_newFeaturePointLocations_size[2];
  real_T c1_b_numberOfFeaturePoints;
  c1_vision_PointTracker *c1_obj;
  int32_T c1_i22;
  void * c1_ptrObj;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  boolean_T c1_b0;
  int32_T c1_i27;
  boolean_T c1_b1;
  int32_T c1_i28;
  int32_T c1_i29;
  boolean_T c1_b2;
  boolean_T c1_b3;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_c_loop_ub;
  int32_T c1_i33;
  int32_T c1_d_loop_ub;
  int32_T c1_i34;
  c1_emxArray_real_T *c1_d_videoFrameGray;
  int32_T c1_i35;
  c1_emxArray_real_T *c1_e_videoFrameGray;
  boolean_T c1_b4;
  int32_T c1_i36;
  boolean_T c1_b5;
  int32_T c1_f_videoFrameGray;
  int32_T c1_g_videoFrameGray;
  int32_T c1_e_loop_ub;
  int32_T c1_h_videoFrameGray;
  int32_T c1_i37;
  int32_T c1_i_videoFrameGray;
  int32_T c1_bBoxCornerPts;
  int32_T c1_newFeaturePointLocations;
  int32_T c1_f_loop_ub;
  int32_T c1_b_bBoxCornerPts;
  int32_T c1_b_newFeaturePointLocations;
  int32_T c1_i38;
  int32_T c1_g_loop_ub;
  int32_T c1_i39;
  c1_emxArray_real32_T *c1_c_newFeaturePointLocations;
  int32_T c1_d_newFeaturePointLocations;
  c1_emxArray_boolean_T *c1_b_isFound;
  int32_T c1_e_newFeaturePointLocations;
  int32_T c1_i40;
  c1_vision_PointTracker *c1_b_obj;
  int32_T c1_h_loop_ub;
  const mxArray *c1_y = NULL;
  boolean_T c1_flag;
  int32_T c1_i41;
  const mxArray *c1_b_y = NULL;
  static char_T c1_cv15[8] = { 'i', 's', 'L', 'o', 'c', 'k', 'e', 'd' };

  int32_T c1_i42;
  c1_emxArray_real_T *c1_j_videoFrameGray;
  int32_T c1_b_newFeaturePointLocations_size[2];
  int32_T c1_i43;
  int32_T c1_i_loop_ub;
  int32_T c1_i44;
  int32_T c1_f_newFeaturePointLocations;
  int32_T c1_i45;
  int32_T c1_g_newFeaturePointLocations;
  const mxArray *c1_c_y = NULL;
  int32_T c1_j_loop_ub;
  static char_T c1_cv16[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i', 'l',
    't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F',
    'a', 'i', 'l', 'e', 'd' };

  int32_T c1_i46;
  int32_T c1_end;
  int32_T c1_k_videoFrameGray;
  int32_T c1_trueCount;
  int32_T c1_l_videoFrameGray;
  int32_T c1_i;
  int32_T c1_i47;
  int32_T c1_k_loop_ub;
  c1_emxArray_real_T *c1_m_videoFrameGray;
  real32_T c1_c_newFeaturePointLocations_data[1000];
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i50;
  int32_T c1_l_loop_ub;
  c1_emxArray_int32_T *c1_r0;
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_n_videoFrameGray;
  c1_vision_PointTracker *c1_c_obj;
  int32_T c1_o_videoFrameGray;
  int32_T c1_partialTrueCount;
  int32_T c1_points_size[2];
  int32_T c1_m_loop_ub;
  int32_T c1_b_i;
  int32_T c1_i53;
  int32_T c1_points;
  int32_T c1_b_points;
  int32_T c1_h_newFeaturePointLocations;
  int32_T c1_n_loop_ub;
  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  int32_T c1_b_points_size[2];
  real32_T c1_points_data[1000];
  int32_T c1_c_points;
  int32_T c1_o_loop_ub;
  int32_T c1_d_points;
  int32_T c1_i57;
  int32_T c1_p_loop_ub;
  int32_T c1_i58;
  int32_T c1_b_end;
  int32_T c1_b_trueCount;
  int32_T c1_c_i;
  real32_T c1_b_points_data[1000];
  void * c1_b_ptrObj;
  c1_emxArray_int32_T *c1_r1;
  int32_T c1_hoistedGlobal_size[2];
  int32_T c1_i59;
  int32_T c1_hoistedGlobal;
  int32_T c1_b_hoistedGlobal;
  int32_T c1_b_partialTrueCount;
  int32_T c1_q_loop_ub;
  int32_T c1_d_i;
  int32_T c1_i60;
  int32_T c1_i61;
  int32_T c1_pointValidity_size[1];
  real32_T c1_hoistedGlobal_data[1000];
  int32_T c1_i62;
  int32_T c1_r_loop_ub;
  int32_T c1_i63;
  int32_T c1_i64;
  boolean_T c1_pointValidity_data[500];
  int32_T c1_s_loop_ub;
  int32_T c1_i65;
  int32_T c1_i66;
  int32_T c1_t_loop_ub;
  int32_T c1_i67;
  int32_T c1_i68;
  int32_T c1_u_loop_ub;
  int32_T c1_i69;
  c1_emxArray_real32_T *c1_b_oldInliers;
  boolean_T c1_b6;
  boolean_T c1_b7;
  int32_T c1_i70;
  int32_T c1_c_bBoxCornerPts;
  int32_T c1_d_bBoxCornerPts;
  int32_T c1_i71;
  int32_T c1_c_oldInliers;
  int32_T c1_b_bBox_size[2];
  int32_T c1_d_oldInliers;
  int32_T c1_i_newFeaturePointLocations;
  int32_T c1_v_loop_ub;
  int32_T c1_w_loop_ub;
  int32_T c1_j_newFeaturePointLocations;
  int32_T c1_i72;
  int32_T c1_i73;
  c1_emxArray_real32_T *c1_b_visiblePoints;
  real_T c1_c_bBox_data[8];
  real_T c1_dv0[8];
  int32_T c1_i74;
  int32_T c1_i75;
  int32_T c1_i76;
  int32_T c1_c_visiblePoints;
  int32_T c1_i77;
  int32_T c1_d_visiblePoints;
  int32_T c1_x_loop_ub;
  int32_T c1_i78;
  c1_emxArray_real32_T *c1_unusedU0;
  c1_emxArray_real32_T *c1_e_visiblePoints;
  int32_T c1_e_bBoxCornerPts;
  c1_affine2d c1_b_xform;
  int32_T c1_f_bBoxCornerPts;
  int32_T c1_y_loop_ub;
  int32_T c1_i79;
  int32_T c1_i80;
  int32_T c1_f_visiblePoints;
  int32_T c1_g_visiblePoints;
  int32_T c1_ab_loop_ub;
  int32_T c1_i81;
  int32_T c1_b_hoistedGlobal_size[2];
  int32_T c1_c_hoistedGlobal;
  int32_T c1_d_hoistedGlobal;
  int32_T c1_bb_loop_ub;
  int32_T c1_i82;
  real_T c1_b_hoistedGlobal_data[8];
  int32_T c1_U_size[2];
  real_T c1_d0;
  int32_T c1_e_i;
  int32_T c1_j;
  real_T c1_U_data[12];
  int32_T c1_b_j;
  int32_T c1_b;
  boolean_T c1_overflow;
  int32_T c1_f_i;
  int32_T c1_g_i;
  int32_T c1_X_size[2];
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  int32_T c1_cb_loop_ub;
  int32_T c1_i83;
  int32_T c1_X;
  int32_T c1_db_loop_ub;
  int32_T c1_i84;
  int32_T c1_i85;
  int32_T c1_i86;
  real32_T c1_X_data[12];
  int32_T c1_i87;
  int32_T c1_i88;
  int32_T c1_eb_loop_ub;
  int32_T c1_i89;
  int32_T c1_g_bBoxCornerPts;
  int32_T c1_h_bBoxCornerPts;
  int32_T c1_fb_loop_ub;
  int32_T c1_i90;
  const mxArray *c1_f_y = NULL;
  int32_T c1_k_newFeaturePointLocations;
  int32_T c1_l_newFeaturePointLocations;
  int32_T c1_gb_loop_ub;
  int32_T c1_i91;
  int32_T c1_i92;
  int32_T c1_i93;
  int32_T c1_hb_loop_ub;
  int32_T c1_i94;
  boolean_T c1_b8;
  boolean_T c1_b9;
  int32_T c1_e_hoistedGlobal;
  int32_T c1_f_hoistedGlobal;
  int32_T c1_ib_loop_ub;
  int32_T c1_i95;
  c1_vision_PointTracker *c1_d_obj;
  int32_T c1_c_hoistedGlobal_size[2];
  int32_T c1_g_hoistedGlobal;
  int32_T c1_h_hoistedGlobal;
  int32_T c1_jb_loop_ub;
  int32_T c1_i96;
  real32_T c1_c_hoistedGlobal_data[1000];
  void * c1_c_ptrObj;
  int32_T c1_e_points;
  int32_T c1_f_points;
  int32_T c1_kb_loop_ub;
  int32_T c1_i97;
  int32_T c1_lb_loop_ub;
  int32_T c1_i98;
  c1_emxInit_boolean_T(chartInstance, &c1_isFound, 1, &c1_j_emlrtRTEI);
  c1_emxInit_real32_T(chartInstance, &c1_visiblePoints, 2, &c1_n_emlrtRTEI);
  c1_emxInit_real32_T(chartInstance, &c1_oldInliers, 2, &c1_r_emlrtRTEI);
  c1_emxInit_real_T(chartInstance, &c1_c_videoFrameGray, 2, &c1_ob_emlrtRTEI);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i19 = 0; c1_i19 < 1048576; c1_i19++) {
    chartInstance->c1_videoFrameGray[c1_i19] =
      (*chartInstance->c1_b_videoFrameGray)[c1_i19];
  }

  c1_b_decimationFactor = *chartInstance->c1_decimationFactor;
  c1_bBox_size[0] = (*chartInstance->c1_bBox_sizes)[0];
  c1_bBox_size[1] = (*chartInstance->c1_bBox_sizes)[1];
  c1_bBox = c1_bBox_size[0];
  c1_b_bBox = c1_bBox_size[1];
  c1_loop_ub = (*chartInstance->c1_bBox_sizes)[0] *
    (*chartInstance->c1_bBox_sizes)[1] - 1;
  for (c1_i20 = 0; c1_i20 <= c1_loop_ub; c1_i20++) {
    c1_b_bBox_data[c1_i20] = (*chartInstance->c1_bBox_data)[c1_i20];
  }

  c1_featurePointLocations_size[0] =
    (*chartInstance->c1_featurePointLocations_sizes)[0];
  c1_featurePointLocations_size[1] =
    (*chartInstance->c1_featurePointLocations_sizes)[1];
  c1_featurePointLocations = c1_featurePointLocations_size[0];
  c1_b_featurePointLocations = c1_featurePointLocations_size[1];
  c1_b_loop_ub = (*chartInstance->c1_featurePointLocations_sizes)[0] *
    (*chartInstance->c1_featurePointLocations_sizes)[1] - 1;
  for (c1_i21 = 0; c1_i21 <= c1_b_loop_ub; c1_i21++) {
    c1_b_featurePointLocations_data[c1_i21] =
      (*chartInstance->c1_featurePointLocations_data)[c1_i21];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 18U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE(c1_isFound->data, (const int32_T *)
    c1_isFound->size, NULL, 0, 0, (void *)c1_l_sf_marshallOut, (void *)
    c1_j_sf_marshallIn, (void *)c1_isFound, true);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE(c1_visiblePoints->data, (const
    int32_T *)c1_visiblePoints->size, NULL, 0, 1, (void *)c1_k_sf_marshallOut,
    (void *)c1_i_sf_marshallIn, (void *)c1_visiblePoints, true);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE(c1_oldInliers->data, (const
    int32_T *)c1_oldInliers->size, NULL, 0, 2, (void *)c1_k_sf_marshallOut,
    (void *)c1_i_sf_marshallIn, (void *)c1_oldInliers, true);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(&c1_xform, NULL, c1_xform.T.size, 0,
    3, (void *)c1_j_sf_marshallOut, (void *)c1_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE(c1_c_videoFrameGray->data, (const
    int32_T *)c1_c_videoFrameGray->size, NULL, 0, -1, (void *)
    c1_i_sf_marshallOut, (void *)c1_g_sf_marshallIn, (void *)c1_c_videoFrameGray,
    true);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 5U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 6U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c1_videoFrameGray, 4U,
    c1_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_decimationFactor, 7U, c1_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX((void *)&c1_b_bBox_data, (const int32_T *)
    &c1_bBox_size, NULL, 1, 8, (void *)c1_g_sf_marshallOut, (void *)
    &c1_b_bBox_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX((void *)&c1_b_featurePointLocations_data, (
    const int32_T *)&c1_featurePointLocations_size, NULL, 1, 9, (void *)
    c1_e_sf_marshallOut, (void *)&c1_b_featurePointLocations_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)&c1_b_bBoxCornerPts_data,
    (const int32_T *)&c1_bBoxCornerPts_size, NULL, 0, 10, (void *)
    c1_f_sf_marshallOut, (void *)c1_f_sf_marshallIn, (void *)
    &c1_b_bBoxCornerPts_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)
    &c1_b_newFeaturePointLocations_data, (const int32_T *)
    &c1_newFeaturePointLocations_size, NULL, 0, 11, (void *)c1_e_sf_marshallOut,
    (void *)c1_e_sf_marshallIn, (void *)&c1_b_newFeaturePointLocations_data,
    false);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_numberOfFeaturePoints, 12U,
    c1_d_sf_marshallOut, c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE(chartInstance->c1_oldPoints.data,
    (const int32_T *)&chartInstance->c1_oldPoints.size, NULL, 1, 13, (void *)
    c1_c_sf_marshallOut, (void *)c1_c_sf_marshallIn, (void *)
    &chartInstance->c1_oldPoints, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE(chartInstance->c1_bboxPoints.data,
    (const int32_T *)&chartInstance->c1_bboxPoints.size, NULL, 1, 14, (void *)
    c1_b_sf_marshallOut, (void *)c1_b_sf_marshallIn, (void *)
    &chartInstance->c1_bboxPoints, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c1_first_time, 15U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c1_numPts, 16U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c1_pointTracker_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
    c1_obj = &chartInstance->c1_pointTracker;
    chartInstance->c1_pointTracker.IsRGB = false;
    chartInstance->c1_pointTracker.matlabCodegenIsDeleted = false;
    chartInstance->c1_pointTracker.isInitialized = 0;
    chartInstance->c1_pointTracker.matlabCodegenIsDeleted = false;
    c1_ptrObj = NULL;
    pointTracker_construct(&c1_ptrObj);
    c1_obj->pTracker = c1_ptrObj;
    chartInstance->c1_pointTracker_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c1_bboxPoints_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
    chartInstance->c1_bboxPoints.size[0] = 1;
    chartInstance->c1_bboxPoints.size[1] = 2;
    c1_i22 = chartInstance->c1_bboxPoints.size[0];
    c1_i23 = chartInstance->c1_bboxPoints.size[1];
    for (c1_i24 = 0; c1_i24 < 2; c1_i24++) {
      chartInstance->c1_bboxPoints.data[c1_i24] = 0.0;
    }

    chartInstance->c1_bboxPoints_not_empty = true;
    chartInstance->c1_bboxPoints_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
  if (CV_EML_IF(0, 1, 2, !chartInstance->c1_oldPoints_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 22);
    chartInstance->c1_oldPoints.size[0] = 1;
    chartInstance->c1_oldPoints.size[1] = 2;
    c1_i25 = chartInstance->c1_oldPoints.size[0];
    c1_i26 = chartInstance->c1_oldPoints.size[1];
    for (c1_i27 = 0; c1_i27 < 2; c1_i27++) {
      chartInstance->c1_oldPoints.data[c1_i27] = 0.0F;
    }

    chartInstance->c1_oldPoints_not_empty = true;
    chartInstance->c1_oldPoints_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
  if (CV_EML_IF(0, 1, 3, !chartInstance->c1_numPts_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 26);
    chartInstance->c1_numPts = 0.0;
    chartInstance->c1_numPts_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 30);
  c1_b0 = (c1_b_decimationFactor == 0.0);
  c1_b1 = (0.0 > c1_b_decimationFactor);
  if (c1_b0 || c1_b1) {
    c1_i28 = 1;
    c1_i29 = 0;
  } else {
    c1_i28 = c1__s32_d_(chartInstance, sf_integer_check(chartInstance->S, 1U,
      687U, 16U, c1_b_decimationFactor), 1U, 685U, 22U);
    c1_i29 = 1024;
  }

  c1_b2 = (c1_b_decimationFactor == 0.0);
  c1_b3 = (0.0 > c1_b_decimationFactor);
  if (c1_b2 || c1_b3) {
    c1_i30 = 1;
    c1_i31 = 0;
  } else {
    c1_i30 = c1__s32_d_(chartInstance, sf_integer_check(chartInstance->S, 1U,
      710U, 16U, c1_b_decimationFactor), 1U, 708U, 22U);
    c1_i31 = 1024;
  }

  c1_i32 = c1_c_videoFrameGray->size[0] * c1_c_videoFrameGray->size[1];
  c1_c_videoFrameGray->size[0] = c1_div_s32_floor(chartInstance, c1_i29 - 1,
    c1_i28, 1U, 653U, 78U) + 1;
  c1_c_videoFrameGray->size[1] = c1_div_s32_floor(chartInstance, c1_i31 - 1,
    c1_i30, 1U, 653U, 78U) + 1;
  c1_emxEnsureCapacity_real_T(chartInstance, c1_c_videoFrameGray, c1_i32,
    &c1_e_emlrtRTEI);
  c1_c_loop_ub = c1_div_s32_floor(chartInstance, c1_i31 - 1, c1_i30, 1U, 653U,
    78U);
  for (c1_i33 = 0; c1_i33 <= c1_c_loop_ub; c1_i33++) {
    c1_d_loop_ub = c1_div_s32_floor(chartInstance, c1_i29 - 1, c1_i28, 1U, 653U,
      78U);
    for (c1_i34 = 0; c1_i34 <= c1_d_loop_ub; c1_i34++) {
      c1_c_videoFrameGray->data[c1_i34 + c1_c_videoFrameGray->size[0] * c1_i33] =
        chartInstance->c1_videoFrameGray[c1_i28 * c1_i34 + ((c1_i30 * c1_i33) <<
        10)];
    }
  }

  _SFD_SYMBOL_SWITCH(4U, 4U);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 33);
  if (CV_EML_IF(0, 1, 4, !chartInstance->c1_first_time_not_empty)) {
    c1_emxInit_real_T(chartInstance, &c1_d_videoFrameGray, 2, &c1_f_emlrtRTEI);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 34);
    c1_i35 = c1_d_videoFrameGray->size[0] * c1_d_videoFrameGray->size[1];
    c1_d_videoFrameGray->size[0] = c1_c_videoFrameGray->size[0];
    c1_d_videoFrameGray->size[1] = c1_c_videoFrameGray->size[1];
    c1_emxEnsureCapacity_real_T(chartInstance, c1_d_videoFrameGray, c1_i35,
      &c1_f_emlrtRTEI);
    c1_f_videoFrameGray = c1_d_videoFrameGray->size[0];
    c1_g_videoFrameGray = c1_d_videoFrameGray->size[1];
    c1_e_loop_ub = c1_c_videoFrameGray->size[0] * c1_c_videoFrameGray->size[1] -
      1;
    for (c1_i37 = 0; c1_i37 <= c1_e_loop_ub; c1_i37++) {
      c1_d_videoFrameGray->data[c1_i37] = c1_c_videoFrameGray->data[c1_i37];
    }

    c1_PointTracker_initialize(chartInstance, &chartInstance->c1_pointTracker,
      c1_d_videoFrameGray);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 35);
    chartInstance->c1_first_time = 0.0;
    chartInstance->c1_first_time_not_empty = true;
    c1_emxFree_real_T(chartInstance, &c1_d_videoFrameGray);
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 38);
  if (CV_EML_IF(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 0, chartInstance->c1_numPts,
        10.0, -1, 2U, chartInstance->c1_numPts < 10.0))) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 39);
    c1_b4 = (c1_featurePointLocations_size[0] == 0);
    c1_b5 = (c1_featurePointLocations_size[1] == 0);
    if (CV_EML_IF(0, 1, 6, CV_EML_MCDC(0, 1, 0, !CV_EML_COND(0, 1, 0, c1_b4 ||
           c1_b5)))) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 42);
      c1_newFeaturePointLocations_size[0] = c1_featurePointLocations_size[0];
      c1_newFeaturePointLocations_size[1] = c1_featurePointLocations_size[1];
      c1_newFeaturePointLocations = c1_newFeaturePointLocations_size[0];
      c1_b_newFeaturePointLocations = c1_newFeaturePointLocations_size[1];
      c1_g_loop_ub = c1_featurePointLocations_size[0] *
        c1_featurePointLocations_size[1] - 1;
      for (c1_i39 = 0; c1_i39 <= c1_g_loop_ub; c1_i39++) {
        c1_b_newFeaturePointLocations_data[c1_i39] =
          c1_b_featurePointLocations_data[c1_i39];
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 43);
      chartInstance->c1_numPts = (real_T)c1_newFeaturePointLocations_size[0];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 45);
      c1_b_obj = &chartInstance->c1_pointTracker;
      if (chartInstance->c1_pointTracker.isInitialized != 2) {
      } else {
        c1_y = NULL;
        sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv0, 10, 0U, 1U, 0U, 2, 1, 45),
                      false);
        c1_b_y = NULL;
        sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv15, 10, 0U, 1U, 0U, 2, 1,
          8), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "message", 1U, 2U, 14, c1_y, 14, c1_b_y));
      }

      c1_flag = (c1_b_obj->isInitialized == 1);
      if (CV_EML_IF(0, 1, 7, CV_EML_MCDC(0, 1, 1, !CV_EML_COND(0, 1, 1, c1_flag))))
      {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 46);
        c1_b_newFeaturePointLocations_size[0] =
          c1_newFeaturePointLocations_size[0];
        c1_b_newFeaturePointLocations_size[1] =
          c1_newFeaturePointLocations_size[1];
        c1_f_newFeaturePointLocations = c1_b_newFeaturePointLocations_size[0];
        c1_g_newFeaturePointLocations = c1_b_newFeaturePointLocations_size[1];
        c1_j_loop_ub = c1_newFeaturePointLocations_size[0] *
          c1_newFeaturePointLocations_size[1] - 1;
        for (c1_i46 = 0; c1_i46 <= c1_j_loop_ub; c1_i46++) {
          c1_c_newFeaturePointLocations_data[c1_i46] =
            c1_b_newFeaturePointLocations_data[c1_i46];
        }

        c1_emxInit_real_T(chartInstance, &c1_m_videoFrameGray, 2,
                          &c1_o_emlrtRTEI);
        c1_i50 = c1_m_videoFrameGray->size[0] * c1_m_videoFrameGray->size[1];
        c1_m_videoFrameGray->size[0] = c1_c_videoFrameGray->size[0];
        c1_m_videoFrameGray->size[1] = c1_c_videoFrameGray->size[1];
        c1_emxEnsureCapacity_real_T(chartInstance, c1_m_videoFrameGray, c1_i50,
          &c1_o_emlrtRTEI);
        c1_n_videoFrameGray = c1_m_videoFrameGray->size[0];
        c1_o_videoFrameGray = c1_m_videoFrameGray->size[1];
        c1_m_loop_ub = c1_c_videoFrameGray->size[0] * c1_c_videoFrameGray->size
          [1] - 1;
        for (c1_i53 = 0; c1_i53 <= c1_m_loop_ub; c1_i53++) {
          c1_m_videoFrameGray->data[c1_i53] = c1_c_videoFrameGray->data[c1_i53];
        }

        c1_b_PointTracker_initialize(chartInstance,
          &chartInstance->c1_pointTracker, c1_c_newFeaturePointLocations_data,
          c1_b_newFeaturePointLocations_size, c1_m_videoFrameGray);
        c1_emxFree_real_T(chartInstance, &c1_m_videoFrameGray);
      }

      c1_emxInit_real_T(chartInstance, &c1_j_videoFrameGray, 2, &c1_m_emlrtRTEI);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 48);
      c1_i44 = c1_j_videoFrameGray->size[0] * c1_j_videoFrameGray->size[1];
      c1_j_videoFrameGray->size[0] = c1_c_videoFrameGray->size[0];
      c1_j_videoFrameGray->size[1] = c1_c_videoFrameGray->size[1];
      c1_emxEnsureCapacity_real_T(chartInstance, c1_j_videoFrameGray, c1_i44,
        &c1_m_emlrtRTEI);
      c1_k_videoFrameGray = c1_j_videoFrameGray->size[0];
      c1_l_videoFrameGray = c1_j_videoFrameGray->size[1];
      c1_k_loop_ub = c1_c_videoFrameGray->size[0] * c1_c_videoFrameGray->size[1]
        - 1;
      for (c1_i49 = 0; c1_i49 <= c1_k_loop_ub; c1_i49++) {
        c1_j_videoFrameGray->data[c1_i49] = c1_c_videoFrameGray->data[c1_i49];
      }

      c1_SystemCore_step(chartInstance, &chartInstance->c1_pointTracker,
                         c1_j_videoFrameGray);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 49);
      c1_c_obj = &chartInstance->c1_pointTracker;
      c1_points_size[0] = c1_newFeaturePointLocations_size[0];
      c1_points_size[1] = c1_newFeaturePointLocations_size[1];
      c1_points = c1_points_size[0];
      c1_b_points = c1_points_size[1];
      c1_n_loop_ub = c1_newFeaturePointLocations_size[0] *
        c1_newFeaturePointLocations_size[1] - 1;
      c1_emxFree_real_T(chartInstance, &c1_j_videoFrameGray);
      for (c1_i55 = 0; c1_i55 <= c1_n_loop_ub; c1_i55++) {
        c1_points_data[c1_i55] = c1_b_newFeaturePointLocations_data[c1_i55];
      }

      c1_b_points_size[0] = c1_points_size[0];
      c1_b_points_size[1] = c1_points_size[1];
      c1_c_points = c1_b_points_size[0];
      c1_d_points = c1_b_points_size[1];
      c1_p_loop_ub = c1_points_size[0] * c1_points_size[1] - 1;
      for (c1_i58 = 0; c1_i58 <= c1_p_loop_ub; c1_i58++) {
        c1_b_points_data[c1_i58] = c1_points_data[c1_i58];
      }

      c1_PointTracker_validatePoints(chartInstance, c1_b_points_data,
        c1_b_points_size);
      c1_c_obj->NumPoints = (real_T)c1_points_size[0];
      c1_b_ptrObj = c1_c_obj->pTracker;
      c1_hoistedGlobal_size[0] = c1_points_size[0];
      c1_hoistedGlobal_size[1] = c1_points_size[1];
      c1_hoistedGlobal = c1_hoistedGlobal_size[0];
      c1_b_hoistedGlobal = c1_hoistedGlobal_size[1];
      c1_q_loop_ub = c1_points_size[0] * c1_points_size[1] - 1;
      for (c1_i60 = 0; c1_i60 <= c1_q_loop_ub; c1_i60++) {
        c1_hoistedGlobal_data[c1_i60] = c1_points_data[c1_i60];
      }

      c1_pointValidity_size[0] = c1_points_size[0];
      c1_r_loop_ub = c1_points_size[0] - 1;
      for (c1_i64 = 0; c1_i64 <= c1_r_loop_ub; c1_i64++) {
        c1_pointValidity_data[c1_i64] = true;
      }

      pointTracker_setPoints(c1_b_ptrObj, &c1_hoistedGlobal_data[0],
        c1_points_size[0], &c1_pointValidity_data[0]);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 52);
      chartInstance->c1_oldPoints.size[0] = c1_newFeaturePointLocations_size[0];
      chartInstance->c1_oldPoints.size[1] = c1_newFeaturePointLocations_size[1];
      c1_i66 = chartInstance->c1_oldPoints.size[0];
      c1_i67 = chartInstance->c1_oldPoints.size[1];
      c1_u_loop_ub = c1_newFeaturePointLocations_size[0] *
        c1_newFeaturePointLocations_size[1] - 1;
      for (c1_i69 = 0; c1_i69 <= c1_u_loop_ub; c1_i69++) {
        chartInstance->c1_oldPoints.data[c1_i69] =
          c1_b_newFeaturePointLocations_data[c1_i69];
      }

      c1_b6 = (chartInstance->c1_oldPoints.size[0] == 0);
      c1_b7 = (chartInstance->c1_oldPoints.size[1] == 0);
      chartInstance->c1_oldPoints_not_empty = !(c1_b6 || c1_b7);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 58);
      (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 1781, 1, MAX_uint32_T, 1, 1, c1_bBox_size[0]);
      c1_i71 = c1_bBox_size[1];
      c1_b_bBox_size[0] = 1;
      c1_b_bBox_size[1] = c1_i71;
      c1_w_loop_ub = c1_i71 - 1;
      for (c1_i73 = 0; c1_i73 <= c1_w_loop_ub; c1_i73++) {
        c1_c_bBox_data[c1_b_bBox_size[0] * c1_i73] =
          c1_b_bBox_data[c1_bBox_size[0] * c1_i73];
      }

      c1_bbox2points(chartInstance, c1_c_bBox_data, c1_b_bBox_size, c1_dv0);
      chartInstance->c1_bboxPoints.size[0] = 4;
      chartInstance->c1_bboxPoints.size[1] = 2;
      c1_i75 = chartInstance->c1_bboxPoints.size[0];
      c1_i76 = chartInstance->c1_bboxPoints.size[1];
      for (c1_i77 = 0; c1_i77 < 8; c1_i77++) {
        chartInstance->c1_bboxPoints.data[c1_i77] = c1_dv0[c1_i77];
      }

      chartInstance->c1_bboxPoints_not_empty = true;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 59);
      c1_bBoxCornerPts_size[0] = chartInstance->c1_bboxPoints.size[0];
      c1_bBoxCornerPts_size[1] = 2;
      c1_e_bBoxCornerPts = c1_bBoxCornerPts_size[0];
      c1_f_bBoxCornerPts = c1_bBoxCornerPts_size[1];
      c1_y_loop_ub = chartInstance->c1_bboxPoints.size[0] *
        chartInstance->c1_bboxPoints.size[1] - 1;
      for (c1_i80 = 0; c1_i80 <= c1_y_loop_ub; c1_i80++) {
        c1_b_bBoxCornerPts_data[c1_i80] = chartInstance->
          c1_bboxPoints.data[c1_i80];
      }
    } else {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 61);
      c1_bBoxCornerPts_size[0] = 0;
      c1_bBoxCornerPts_size[1] = 0;
      c1_bBoxCornerPts = c1_bBoxCornerPts_size[0];
      c1_b_bBoxCornerPts = c1_bBoxCornerPts_size[1];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 62);
      c1_newFeaturePointLocations_size[0] = 0;
      c1_newFeaturePointLocations_size[1] = 0;
      c1_d_newFeaturePointLocations = c1_newFeaturePointLocations_size[0];
      c1_e_newFeaturePointLocations = c1_newFeaturePointLocations_size[1];
    }
  } else {
    c1_emxInit_real_T(chartInstance, &c1_e_videoFrameGray, 2, &c1_g_emlrtRTEI);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 67);
    c1_i36 = c1_e_videoFrameGray->size[0] * c1_e_videoFrameGray->size[1];
    c1_e_videoFrameGray->size[0] = c1_c_videoFrameGray->size[0];
    c1_e_videoFrameGray->size[1] = c1_c_videoFrameGray->size[1];
    c1_emxEnsureCapacity_real_T(chartInstance, c1_e_videoFrameGray, c1_i36,
      &c1_g_emlrtRTEI);
    c1_h_videoFrameGray = c1_e_videoFrameGray->size[0];
    c1_i_videoFrameGray = c1_e_videoFrameGray->size[1];
    c1_f_loop_ub = c1_c_videoFrameGray->size[0] * c1_c_videoFrameGray->size[1] -
      1;
    for (c1_i38 = 0; c1_i38 <= c1_f_loop_ub; c1_i38++) {
      c1_e_videoFrameGray->data[c1_i38] = c1_c_videoFrameGray->data[c1_i38];
    }

    c1_emxInit_real32_T(chartInstance, &c1_c_newFeaturePointLocations, 2,
                        (emlrtRTEInfo *)NULL);
    c1_emxInit_boolean_T(chartInstance, &c1_b_isFound, 1, (emlrtRTEInfo *)NULL);
    c1_b_SystemCore_step(chartInstance, &chartInstance->c1_pointTracker,
                         c1_e_videoFrameGray, c1_c_newFeaturePointLocations,
                         c1_b_isFound);
    c1_i40 = c1_isFound->size[0];
    c1_isFound->size[0] = c1_b_isFound->size[0];
    c1_emxEnsureCapacity_boolean_T(chartInstance, c1_isFound, c1_i40,
      &c1_j_emlrtRTEI);
    c1_h_loop_ub = c1_b_isFound->size[0] - 1;
    c1_emxFree_real_T(chartInstance, &c1_e_videoFrameGray);
    for (c1_i41 = 0; c1_i41 <= c1_h_loop_ub; c1_i41++) {
      c1_isFound->data[c1_i41] = c1_b_isFound->data[c1_i41];
    }

    c1_emxFree_boolean_T(chartInstance, &c1_b_isFound);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 68);
    if ((real_T)c1_c_newFeaturePointLocations->size[0] < 500.0) {
    } else {
      c1_c_y = NULL;
      sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv16, 10, 0U, 1U, 0U, 2, 1,
        30), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c1_c_y));
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 69);
    c1_end = c1_isFound->size[0] - 1;
    c1_trueCount = 0;
    c1_i = 0;
    while (c1_i <= c1_end) {
      if (c1_isFound->data[c1_i]) {
        c1_trueCount++;
      }

      c1_i++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    c1_emxInit_int32_T(chartInstance, &c1_r0, 1, &c1_pb_emlrtRTEI);
    c1_i52 = c1_r0->size[0];
    c1_r0->size[0] = c1_trueCount;
    c1_emxEnsureCapacity_int32_T(chartInstance, c1_r0, c1_i52, (emlrtRTEInfo *)
      NULL);
    c1_partialTrueCount = 0;
    c1_b_i = 0;
    while (c1_b_i <= c1_end) {
      if (c1_isFound->data[c1_b_i]) {
        c1_r0->data[c1_partialTrueCount] = c1_b_i + 1;
        c1_partialTrueCount++;
      }

      c1_b_i++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    c1_h_newFeaturePointLocations = c1_c_newFeaturePointLocations->size[0];
    c1_i54 = c1_visiblePoints->size[0] * c1_visiblePoints->size[1];
    c1_visiblePoints->size[0] = c1_r0->size[0];
    c1_visiblePoints->size[1] = 2;
    c1_emxEnsureCapacity_real32_T(chartInstance, c1_visiblePoints, c1_i54,
      &c1_n_emlrtRTEI);
    for (c1_i56 = 0; c1_i56 < 2; c1_i56++) {
      c1_o_loop_ub = c1_r0->size[0] - 1;
      for (c1_i57 = 0; c1_i57 <= c1_o_loop_ub; c1_i57++) {
        c1_visiblePoints->data[c1_i57 + c1_visiblePoints->size[0] * c1_i56] =
          c1_c_newFeaturePointLocations->data[(sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 2121, 7,
           MAX_uint32_T, c1_r0->data[c1_i57], 1, c1_h_newFeaturePointLocations)
          + c1_c_newFeaturePointLocations->size[0] * c1_i56) - 1];
      }
    }

    c1_emxFree_int32_T(chartInstance, &c1_r0);
    c1_emxFree_real32_T(chartInstance, &c1_c_newFeaturePointLocations);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 70);
    c1_b_end = c1_isFound->size[0] - 1;
    c1_b_trueCount = 0;
    c1_c_i = 0;
    while (c1_c_i <= c1_b_end) {
      if (c1_isFound->data[c1_c_i]) {
        c1_b_trueCount++;
      }

      c1_c_i++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    c1_emxInit_int32_T(chartInstance, &c1_r1, 1, &c1_qb_emlrtRTEI);
    c1_i59 = c1_r1->size[0];
    c1_r1->size[0] = c1_b_trueCount;
    c1_emxEnsureCapacity_int32_T(chartInstance, c1_r1, c1_i59, (emlrtRTEInfo *)
      NULL);
    c1_b_partialTrueCount = 0;
    c1_d_i = 0;
    while (c1_d_i <= c1_b_end) {
      if (c1_isFound->data[c1_d_i]) {
        c1_r1->data[c1_b_partialTrueCount] = c1_d_i + 1;
        c1_b_partialTrueCount++;
      }

      c1_d_i++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    c1_i61 = chartInstance->c1_oldPoints.size[0];
    c1_i62 = chartInstance->c1_oldPoints.size[1];
    c1_i63 = c1_oldInliers->size[0] * c1_oldInliers->size[1];
    c1_oldInliers->size[0] = c1_r1->size[0];
    c1_oldInliers->size[1] = c1_i62;
    c1_emxEnsureCapacity_real32_T(chartInstance, c1_oldInliers, c1_i63,
      &c1_r_emlrtRTEI);
    c1_s_loop_ub = c1_i62 - 1;
    for (c1_i65 = 0; c1_i65 <= c1_s_loop_ub; c1_i65++) {
      c1_t_loop_ub = c1_r1->size[0] - 1;
      for (c1_i68 = 0; c1_i68 <= c1_t_loop_ub; c1_i68++) {
        c1_oldInliers->data[c1_i68 + c1_oldInliers->size[0] * c1_i65] =
          chartInstance->c1_oldPoints.data[(sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 2161, 7,
           MAX_uint32_T, c1_r1->data[c1_i68], 1, c1_i61) +
          chartInstance->c1_oldPoints.size[0] * c1_i65) - 1];
      }
    }

    c1_emxFree_int32_T(chartInstance, &c1_r1);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 72);
    chartInstance->c1_numPts = (real_T)c1_visiblePoints->size[0];
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 74);
    if (CV_EML_IF(0, 1, 8, CV_RELATIONAL_EVAL(4U, 0U, 1,
          chartInstance->c1_numPts, 10.0, -1, 5U, chartInstance->c1_numPts >=
          10.0))) {
      c1_emxInit_real32_T(chartInstance, &c1_b_oldInliers, 2, &c1_u_emlrtRTEI);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 77);
      c1_i70 = c1_b_oldInliers->size[0] * c1_b_oldInliers->size[1];
      c1_b_oldInliers->size[0] = c1_oldInliers->size[0];
      c1_b_oldInliers->size[1] = c1_oldInliers->size[1];
      c1_emxEnsureCapacity_real32_T(chartInstance, c1_b_oldInliers, c1_i70,
        &c1_u_emlrtRTEI);
      c1_c_oldInliers = c1_b_oldInliers->size[0];
      c1_d_oldInliers = c1_b_oldInliers->size[1];
      c1_v_loop_ub = c1_oldInliers->size[0] * c1_oldInliers->size[1] - 1;
      for (c1_i72 = 0; c1_i72 <= c1_v_loop_ub; c1_i72++) {
        c1_b_oldInliers->data[c1_i72] = c1_oldInliers->data[c1_i72];
      }

      c1_emxInit_real32_T(chartInstance, &c1_b_visiblePoints, 2, &c1_x_emlrtRTEI);
      c1_i74 = c1_b_visiblePoints->size[0] * c1_b_visiblePoints->size[1];
      c1_b_visiblePoints->size[0] = c1_visiblePoints->size[0];
      c1_b_visiblePoints->size[1] = c1_visiblePoints->size[1];
      c1_emxEnsureCapacity_real32_T(chartInstance, c1_b_visiblePoints, c1_i74,
        &c1_x_emlrtRTEI);
      c1_c_visiblePoints = c1_b_visiblePoints->size[0];
      c1_d_visiblePoints = c1_b_visiblePoints->size[1];
      c1_x_loop_ub = c1_visiblePoints->size[0] * c1_visiblePoints->size[1] - 1;
      for (c1_i78 = 0; c1_i78 <= c1_x_loop_ub; c1_i78++) {
        c1_b_visiblePoints->data[c1_i78] = c1_visiblePoints->data[c1_i78];
      }

      c1_emxInit_real32_T(chartInstance, &c1_unusedU0, 2, (emlrtRTEInfo *)NULL);
      c1_emxInit_real32_T(chartInstance, &c1_e_visiblePoints, 2, (emlrtRTEInfo *)
                          NULL);
      c1_estimateGeometricTransform(chartInstance, c1_b_oldInliers,
        c1_b_visiblePoints, &c1_b_xform, c1_unusedU0, c1_e_visiblePoints);
      c1_xform = c1_b_xform;
      c1_i79 = c1_visiblePoints->size[0] * c1_visiblePoints->size[1];
      c1_visiblePoints->size[0] = c1_e_visiblePoints->size[0];
      c1_visiblePoints->size[1] = c1_e_visiblePoints->size[1];
      c1_emxEnsureCapacity_real32_T(chartInstance, c1_visiblePoints, c1_i79,
        &c1_bb_emlrtRTEI);
      c1_f_visiblePoints = c1_visiblePoints->size[0];
      c1_g_visiblePoints = c1_visiblePoints->size[1];
      c1_ab_loop_ub = c1_e_visiblePoints->size[0] * c1_e_visiblePoints->size[1]
        - 1;
      c1_emxFree_real32_T(chartInstance, &c1_b_visiblePoints);
      c1_emxFree_real32_T(chartInstance, &c1_b_oldInliers);
      c1_emxFree_real32_T(chartInstance, &c1_unusedU0);
      for (c1_i81 = 0; c1_i81 <= c1_ab_loop_ub; c1_i81++) {
        c1_visiblePoints->data[c1_i81] = c1_e_visiblePoints->data[c1_i81];
      }

      c1_emxFree_real32_T(chartInstance, &c1_e_visiblePoints);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 81);
      c1_b_hoistedGlobal_size[0] = chartInstance->c1_bboxPoints.size[0];
      c1_b_hoistedGlobal_size[1] = 2;
      c1_c_hoistedGlobal = c1_b_hoistedGlobal_size[0];
      c1_d_hoistedGlobal = c1_b_hoistedGlobal_size[1];
      c1_bb_loop_ub = chartInstance->c1_bboxPoints.size[0] *
        chartInstance->c1_bboxPoints.size[1] - 1;
      for (c1_i82 = 0; c1_i82 <= c1_bb_loop_ub; c1_i82++) {
        c1_b_hoistedGlobal_data[c1_i82] = chartInstance->
          c1_bboxPoints.data[c1_i82];
      }

      c1_b_xform = c1_xform;
      c1_U_size[0] = c1_b_hoistedGlobal_size[0];
      c1_U_size[1] = 3;
      c1_d0 = (real_T)c1_U_size[0];
      for (c1_e_i = 0; c1_e_i < (int32_T)c1_d0; c1_e_i++) {
        c1_U_data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                    chartInstance->S, 1U, 2558, 41, MAX_uint32_T, c1_e_i + 1, 1,
                    c1_U_size[0]) + (c1_U_size[0] << 1)) - 1] = 1.0;
      }

      for (c1_j = 0; c1_j < 2; c1_j++) {
        c1_b = c1_U_size[0];
        c1_overflow = ((!(c1_b_hoistedGlobal_size[0] + 1 > c1_U_size[0])) &&
                       (c1_U_size[0] > 2147483646));
        if (c1_overflow) {
          c1_check_forloop_overflow_error(chartInstance, true);
        }

        for (c1_g_i = c1_b_hoistedGlobal_size[0] + 1; c1_g_i <= c1_b; c1_g_i++)
        {
          c1_U_data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                      chartInstance->S, 1U, 2558, 41, MAX_uint32_T, c1_g_i, 1,
                      c1_U_size[0]) + c1_U_size[0] * c1_j) - 1] = 1.0;
        }
      }

      for (c1_b_j = 0; c1_b_j < 2; c1_b_j++) {
        for (c1_f_i = 0; c1_f_i < c1_b_hoistedGlobal_size[0]; c1_f_i++) {
          c1_U_data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                      chartInstance->S, 1U, 2558, 41, MAX_uint32_T, c1_f_i + 1,
                      1, c1_U_size[0]) + c1_U_size[0] * c1_b_j) - 1] =
            c1_b_hoistedGlobal_data[(sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 2558, 41,
             MAX_uint32_T, c1_f_i + 1, 1, c1_b_hoistedGlobal_size[0]) +
            c1_b_hoistedGlobal_size[0] * c1_b_j) - 1];
        }
      }

      if (!(3.0 == (real_T)c1_b_xform.T.size[0])) {
        if ((c1_b_xform.T.size[0] == 1) && (c1_b_xform.T.size[1] == 1)) {
          c1_e_y = NULL;
          sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_cv2, 10, 0U, 1U, 0U, 2, 1,
            45), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                            sf_mex_call_debug(sfGlobalDebugInstanceStruct,
            "message", 1U, 1U, 14, c1_e_y));
        } else {
          c1_d_y = NULL;
          sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_cv1, 10, 0U, 1U, 0U, 2, 1,
            21), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                            sf_mex_call_debug(sfGlobalDebugInstanceStruct,
            "message", 1U, 1U, 14, c1_d_y));
        }
      }

      c1_X_size[0] = c1_U_size[0];
      c1_X_size[1] = c1_b_xform.T.size[1];
      c1_cb_loop_ub = c1_U_size[0] - 1;
      for (c1_i83 = 0; c1_i83 <= c1_cb_loop_ub; c1_i83++) {
        c1_db_loop_ub = c1_b_xform.T.size[1] - 1;
        for (c1_i85 = 0; c1_i85 <= c1_db_loop_ub; c1_i85++) {
          c1_X_data[c1_i83 + c1_X_size[0] * c1_i85] = 0.0F;
          for (c1_i87 = 0; c1_i87 < 3; c1_i87++) {
            c1_X_data[c1_i83 + c1_X_size[0] * c1_i85] += (real32_T)
              c1_U_data[c1_i83 + c1_U_size[0] * c1_i87] *
              c1_b_xform.T.data[c1_i87 + c1_b_xform.T.size[0] * c1_i85];
          }
        }
      }

      c1_X = c1_X_size[1];
      for (c1_i84 = 0; c1_i84 < 2; c1_i84++) {
        (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 2558, 41, MAX_uint32_T, c1_i84 + 1, 1, c1_X);
      }

      c1_i86 = c1_X_size[0];
      chartInstance->c1_bboxPoints.size[0] = c1_i86;
      chartInstance->c1_bboxPoints.size[1] = 2;
      for (c1_i88 = 0; c1_i88 < 2; c1_i88++) {
        c1_eb_loop_ub = c1_i86 - 1;
        for (c1_i89 = 0; c1_i89 <= c1_eb_loop_ub; c1_i89++) {
          chartInstance->c1_bboxPoints.data[c1_i89 +
            chartInstance->c1_bboxPoints.size[0] * c1_i88] = c1_X_data[c1_i89 +
            c1_X_size[0] * ((c1_i88 + 1) - 1)];
        }
      }

      chartInstance->c1_bboxPoints_not_empty = true;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 82);
      _SFD_DIM_SIZE_GEQ_CHECK(4, chartInstance->c1_bboxPoints.size[0], 1);
      c1_bBoxCornerPts_size[0] = chartInstance->c1_bboxPoints.size[0];
      c1_bBoxCornerPts_size[1] = 2;
      c1_g_bBoxCornerPts = c1_bBoxCornerPts_size[0];
      c1_h_bBoxCornerPts = c1_bBoxCornerPts_size[1];
      c1_fb_loop_ub = chartInstance->c1_bboxPoints.size[0] *
        chartInstance->c1_bboxPoints.size[1] - 1;
      for (c1_i90 = 0; c1_i90 <= c1_fb_loop_ub; c1_i90++) {
        c1_b_bBoxCornerPts_data[c1_i90] = chartInstance->
          c1_bboxPoints.data[c1_i90];
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 85);
      if ((real_T)c1_visiblePoints->size[0] < 500.0) {
      } else {
        c1_f_y = NULL;
        sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_cv16, 10, 0U, 1U, 0U, 2, 1,
          30), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "message", 1U, 1U, 14, c1_f_y));
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 86);
      _SFD_DIM_SIZE_GEQ_CHECK(500, c1_visiblePoints->size[0], 1);
      _SFD_DIM_SIZE_GEQ_CHECK(2, c1_visiblePoints->size[1], 2);
      c1_newFeaturePointLocations_size[0] = c1_visiblePoints->size[0];
      c1_newFeaturePointLocations_size[1] = c1_visiblePoints->size[1];
      c1_k_newFeaturePointLocations = c1_newFeaturePointLocations_size[0];
      c1_l_newFeaturePointLocations = c1_newFeaturePointLocations_size[1];
      c1_gb_loop_ub = c1_visiblePoints->size[0] * c1_visiblePoints->size[1] - 1;
      for (c1_i91 = 0; c1_i91 <= c1_gb_loop_ub; c1_i91++) {
        c1_b_newFeaturePointLocations_data[c1_i91] = c1_visiblePoints->
          data[c1_i91];
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 89);
      chartInstance->c1_oldPoints.size[0] = c1_visiblePoints->size[0];
      chartInstance->c1_oldPoints.size[1] = c1_visiblePoints->size[1];
      c1_i92 = chartInstance->c1_oldPoints.size[0];
      c1_i93 = chartInstance->c1_oldPoints.size[1];
      c1_hb_loop_ub = c1_visiblePoints->size[0] * c1_visiblePoints->size[1] - 1;
      for (c1_i94 = 0; c1_i94 <= c1_hb_loop_ub; c1_i94++) {
        chartInstance->c1_oldPoints.data[c1_i94] = c1_visiblePoints->data[c1_i94];
      }

      c1_b8 = (chartInstance->c1_oldPoints.size[0] == 0);
      c1_b9 = (chartInstance->c1_oldPoints.size[1] == 0);
      chartInstance->c1_oldPoints_not_empty = !(c1_b8 || c1_b9);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 90);
      c1_hoistedGlobal_size[0] = chartInstance->c1_oldPoints.size[0];
      c1_hoistedGlobal_size[1] = chartInstance->c1_oldPoints.size[1];
      c1_e_hoistedGlobal = c1_hoistedGlobal_size[0];
      c1_f_hoistedGlobal = c1_hoistedGlobal_size[1];
      c1_ib_loop_ub = chartInstance->c1_oldPoints.size[0] *
        chartInstance->c1_oldPoints.size[1] - 1;
      for (c1_i95 = 0; c1_i95 <= c1_ib_loop_ub; c1_i95++) {
        c1_hoistedGlobal_data[c1_i95] = chartInstance->c1_oldPoints.data[c1_i95];
      }

      c1_d_obj = &chartInstance->c1_pointTracker;
      c1_c_hoistedGlobal_size[0] = c1_hoistedGlobal_size[0];
      c1_c_hoistedGlobal_size[1] = c1_hoistedGlobal_size[1];
      c1_g_hoistedGlobal = c1_c_hoistedGlobal_size[0];
      c1_h_hoistedGlobal = c1_c_hoistedGlobal_size[1];
      c1_jb_loop_ub = c1_hoistedGlobal_size[0] * c1_hoistedGlobal_size[1] - 1;
      for (c1_i96 = 0; c1_i96 <= c1_jb_loop_ub; c1_i96++) {
        c1_c_hoistedGlobal_data[c1_i96] = c1_hoistedGlobal_data[c1_i96];
      }

      c1_PointTracker_validatePoints(chartInstance, c1_c_hoistedGlobal_data,
        c1_c_hoistedGlobal_size);
      c1_d_obj->NumPoints = (real_T)c1_hoistedGlobal_size[0];
      c1_c_ptrObj = c1_d_obj->pTracker;
      c1_points_size[0] = c1_hoistedGlobal_size[0];
      c1_points_size[1] = c1_hoistedGlobal_size[1];
      c1_e_points = c1_points_size[0];
      c1_f_points = c1_points_size[1];
      c1_kb_loop_ub = c1_hoistedGlobal_size[0] * c1_hoistedGlobal_size[1] - 1;
      for (c1_i97 = 0; c1_i97 <= c1_kb_loop_ub; c1_i97++) {
        c1_points_data[c1_i97] = c1_hoistedGlobal_data[c1_i97];
      }

      c1_pointValidity_size[0] = c1_hoistedGlobal_size[0];
      c1_lb_loop_ub = c1_hoistedGlobal_size[0] - 1;
      for (c1_i98 = 0; c1_i98 <= c1_lb_loop_ub; c1_i98++) {
        c1_pointValidity_data[c1_i98] = true;
      }

      pointTracker_setPoints(c1_c_ptrObj, &c1_points_data[0],
        c1_hoistedGlobal_size[0], &c1_pointValidity_data[0]);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 92);
      c1_bBoxCornerPts_size[0] = 0;
      c1_bBoxCornerPts_size[1] = 0;
      c1_c_bBoxCornerPts = c1_bBoxCornerPts_size[0];
      c1_d_bBoxCornerPts = c1_bBoxCornerPts_size[1];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 93);
      c1_newFeaturePointLocations_size[0] = 0;
      c1_newFeaturePointLocations_size[1] = 0;
      c1_i_newFeaturePointLocations = c1_newFeaturePointLocations_size[0];
      c1_j_newFeaturePointLocations = c1_newFeaturePointLocations_size[1];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 98);
  c1_b_numberOfFeaturePoints = chartInstance->c1_numPts;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -98);
  _SFD_SYMBOL_SCOPE_POP();
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 0,
    c1_bBoxCornerPts_size[0]);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 1,
    c1_bBoxCornerPts_size[1]);
  c1_i42 = (*chartInstance->c1_bBoxCornerPts_sizes)[0];
  c1_i43 = (*chartInstance->c1_bBoxCornerPts_sizes)[1];
  c1_i_loop_ub = c1_bBoxCornerPts_size[0] * c1_bBoxCornerPts_size[1] - 1;
  for (c1_i45 = 0; c1_i45 <= c1_i_loop_ub; c1_i45++) {
    (*chartInstance->c1_bBoxCornerPts_data)[c1_i45] =
      c1_b_bBoxCornerPts_data[c1_i45];
  }

  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 2, 0,
    c1_newFeaturePointLocations_size[0]);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 2, 1,
    c1_newFeaturePointLocations_size[1]);
  c1_i47 = (*chartInstance->c1_newFeaturePointLocations_sizes)[0];
  c1_i48 = (*chartInstance->c1_newFeaturePointLocations_sizes)[1];
  c1_l_loop_ub = c1_newFeaturePointLocations_size[0] *
    c1_newFeaturePointLocations_size[1] - 1;
  for (c1_i51 = 0; c1_i51 <= c1_l_loop_ub; c1_i51++) {
    (*chartInstance->c1_newFeaturePointLocations_data)[c1_i51] =
      c1_b_newFeaturePointLocations_data[c1_i51];
  }

  *chartInstance->c1_numberOfFeaturePoints = c1_b_numberOfFeaturePoints;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_emxFree_real_T(chartInstance, &c1_c_videoFrameGray);
  c1_emxFree_real32_T(chartInstance, &c1_oldInliers);
  c1_emxFree_real32_T(chartInstance, &c1_visiblePoints);
  c1_emxFree_boolean_T(chartInstance, &c1_isFound);
}

static void initSimStructsc1_DetectAndTrackFace
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)(c1_machineNumber);
  (void)(c1_chartNumber);
  (void)(c1_instanceNumber);
}

static void c1_eML_blk_kernel_free(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  real_T c1_b_u;
  const mxArray *c1_y = NULL;
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_b_u = *(real_T *)c1_inData;
  c1_y = NULL;
  if (!chartInstance->c1_numPts_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_numPts, const char_T *c1_identifier,
  boolean_T *c1_svPtr)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_numPts),
    &c1_thisId, c1_svPtr);
  sf_mex_destroy(&c1_b_numPts);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T *c1_svPtr)
{
  real_T c1_y;
  real_T c1_d1;
  (void)chartInstance;
  if (mxIsEmpty(c1_b_u)) {
    *c1_svPtr = false;
  } else {
    *c1_svPtr = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_d1, 1, 0, 0U, 0, 0U, 0);
    c1_y = c1_d1;
  }

  sf_mex_destroy(&c1_b_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_numPts;
  boolean_T *c1_svPtr;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_b_numPts = sf_mex_dup(c1_mxArrayInData);
  c1_svPtr = &chartInstance->c1_numPts_not_empty;
  c1_thisId.fIdentifier = (const char *)c1_varName;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_numPts),
    &c1_thisId, c1_svPtr);
  sf_mex_destroy(&c1_b_numPts);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[], int32_T c1_inData_size[2])
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_u_size[2];
  int32_T c1_b_u;
  int32_T c1_c_u;
  int32_T c1_loop_ub;
  int32_T c1_i99;
  const mxArray *c1_y = NULL;
  real_T c1_u_data[8];
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u_size[0] = c1_inData_size[0];
  c1_u_size[1] = 2;
  c1_b_u = c1_u_size[0];
  c1_c_u = c1_u_size[1];
  c1_loop_ub = c1_inData_size[0] * c1_inData_size[1] - 1;
  for (c1_i99 = 0; c1_i99 <= c1_loop_ub; c1_i99++) {
    c1_u_data[c1_i99] = c1_inData_data[c1_i99];
  }

  c1_y = NULL;
  if (!chartInstance->c1_bboxPoints_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", (void *)&c1_u_data, 0, 0U, 1U, 0U, 2,
      c1_u_size[0], c1_u_size[1]), false);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_bboxPoints, const char_T *c1_identifier,
  boolean_T *c1_svPtr, real_T c1_y_data[], int32_T c1_y_size[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_bboxPoints), &c1_thisId,
                        c1_svPtr, c1_y_data, c1_y_size);
  sf_mex_destroy(&c1_b_bboxPoints);
}

static void c1_d_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T *c1_svPtr, real_T c1_y_data[], int32_T c1_y_size[2])
{
  int32_T c1_i100;
  uint32_T c1_uv2[2];
  int32_T c1_tmp_size[2];
  int32_T c1_i101;
  real_T c1_tmp_data[8];
  boolean_T c1_bv0[2];
  static boolean_T c1_bv1[2] = { true, false };

  int32_T c1_y;
  int32_T c1_b_y;
  int32_T c1_loop_ub;
  int32_T c1_i102;
  (void)chartInstance;
  for (c1_i100 = 0; c1_i100 < 2; c1_i100++) {
    c1_uv2[c1_i100] = 4U + (uint32_T)(-2 * c1_i100);
  }

  if (mxIsEmpty(c1_b_u)) {
    *c1_svPtr = false;
    c1_y_size[0] = 0;
    c1_y_size[1] = 2;
  } else {
    *c1_svPtr = true;
    c1_tmp_size[0] = sf_mex_get_dimension(c1_b_u, 0);
    c1_tmp_size[1] = sf_mex_get_dimension(c1_b_u, 1);
    for (c1_i101 = 0; c1_i101 < 2; c1_i101++) {
      c1_bv0[c1_i101] = c1_bv1[c1_i101];
    }

    sf_mex_import_vs(c1_parentId, sf_mex_dup(c1_b_u), (void *)&c1_tmp_data, 1, 0,
                     0U, 1, 0U, 2, c1_bv0, c1_uv2, c1_tmp_size);
    c1_y_size[0] = c1_tmp_size[0];
    c1_y_size[1] = 2;
    c1_y = c1_y_size[0];
    c1_b_y = c1_y_size[1];
    c1_loop_ub = c1_tmp_size[0] * c1_tmp_size[1] - 1;
    for (c1_i102 = 0; c1_i102 <= c1_loop_ub; c1_i102++) {
      c1_y_data[c1_i102] = c1_tmp_data[c1_i102];
    }
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[], int32_T
  c1_outData_size[2])
{
  const mxArray *c1_b_bboxPoints;
  boolean_T *c1_svPtr;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y_data[8];
  int32_T c1_y_size[2];
  int32_T c1_i103;
  int32_T c1_loop_ub;
  int32_T c1_i104;
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_b_bboxPoints = sf_mex_dup(c1_mxArrayInData);
  c1_svPtr = &chartInstance->c1_bboxPoints_not_empty;
  c1_thisId.fIdentifier = (const char *)c1_varName;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_bboxPoints), &c1_thisId,
                        c1_svPtr, c1_y_data, c1_y_size);
  sf_mex_destroy(&c1_b_bboxPoints);
  c1_outData_size[0] = c1_y_size[0];
  c1_outData_size[1] = 2;
  for (c1_i103 = 0; c1_i103 < 2; c1_i103++) {
    c1_loop_ub = c1_y_size[0] - 1;
    for (c1_i104 = 0; c1_i104 <= c1_loop_ub; c1_i104++) {
      c1_outData_data[c1_i104 + c1_outData_size[0] * c1_i103] =
        c1_y_data[c1_i104 + c1_y_size[0] * c1_i103];
    }
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, real32_T
  c1_inData_data[], int32_T c1_inData_size[2])
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_u_size[2];
  int32_T c1_b_u;
  int32_T c1_c_u;
  int32_T c1_loop_ub;
  int32_T c1_i105;
  const mxArray *c1_y = NULL;
  real32_T c1_u_data[1000];
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u_size[0] = c1_inData_size[0];
  c1_u_size[1] = c1_inData_size[1];
  c1_b_u = c1_u_size[0];
  c1_c_u = c1_u_size[1];
  c1_loop_ub = c1_inData_size[0] * c1_inData_size[1] - 1;
  for (c1_i105 = 0; c1_i105 <= c1_loop_ub; c1_i105++) {
    c1_u_data[c1_i105] = c1_inData_data[c1_i105];
  }

  c1_y = NULL;
  if (!chartInstance->c1_oldPoints_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", (void *)&c1_u_data, 1, 0U, 1U, 0U, 2,
      c1_u_size[0], c1_u_size[1]), false);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_oldPoints, const char_T *c1_identifier,
  boolean_T *c1_svPtr, real32_T c1_y_data[], int32_T c1_y_size[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_oldPoints), &c1_thisId,
                        c1_svPtr, c1_y_data, c1_y_size);
  sf_mex_destroy(&c1_b_oldPoints);
}

static void c1_f_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T *c1_svPtr, real32_T c1_y_data[], int32_T c1_y_size[2])
{
  int32_T c1_i106;
  uint32_T c1_uv3[2];
  int32_T c1_tmp_size[2];
  int32_T c1_i107;
  real32_T c1_tmp_data[1000];
  boolean_T c1_bv2[2];
  int32_T c1_y;
  int32_T c1_b_y;
  int32_T c1_loop_ub;
  int32_T c1_i108;
  (void)chartInstance;
  for (c1_i106 = 0; c1_i106 < 2; c1_i106++) {
    c1_uv3[c1_i106] = 500U + (uint32_T)(-498 * c1_i106);
  }

  if (mxIsEmpty(c1_b_u)) {
    *c1_svPtr = false;
    c1_y_size[0] = 0;
    c1_y_size[1] = 0;
  } else {
    *c1_svPtr = true;
    c1_tmp_size[0] = sf_mex_get_dimension(c1_b_u, 0);
    c1_tmp_size[1] = sf_mex_get_dimension(c1_b_u, 1);
    for (c1_i107 = 0; c1_i107 < 2; c1_i107++) {
      c1_bv2[c1_i107] = true;
    }

    sf_mex_import_vs(c1_parentId, sf_mex_dup(c1_b_u), (void *)&c1_tmp_data, 1, 1,
                     0U, 1, 0U, 2, c1_bv2, c1_uv3, c1_tmp_size);
    c1_y_size[0] = c1_tmp_size[0];
    c1_y_size[1] = c1_tmp_size[1];
    c1_y = c1_y_size[0];
    c1_b_y = c1_y_size[1];
    c1_loop_ub = c1_tmp_size[0] * c1_tmp_size[1] - 1;
    for (c1_i108 = 0; c1_i108 <= c1_loop_ub; c1_i108++) {
      c1_y_data[c1_i108] = c1_tmp_data[c1_i108];
    }
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real32_T c1_outData_data[],
  int32_T c1_outData_size[2])
{
  const mxArray *c1_b_oldPoints;
  boolean_T *c1_svPtr;
  emlrtMsgIdentifier c1_thisId;
  real32_T c1_y_data[1000];
  int32_T c1_y_size[2];
  int32_T c1_loop_ub;
  int32_T c1_i109;
  int32_T c1_b_loop_ub;
  int32_T c1_i110;
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_b_oldPoints = sf_mex_dup(c1_mxArrayInData);
  c1_svPtr = &chartInstance->c1_oldPoints_not_empty;
  c1_thisId.fIdentifier = (const char *)c1_varName;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_oldPoints), &c1_thisId,
                        c1_svPtr, c1_y_data, c1_y_size);
  sf_mex_destroy(&c1_b_oldPoints);
  c1_outData_size[0] = c1_y_size[0];
  c1_outData_size[1] = c1_y_size[1];
  c1_loop_ub = c1_y_size[1] - 1;
  for (c1_i109 = 0; c1_i109 <= c1_loop_ub; c1_i109++) {
    c1_b_loop_ub = c1_y_size[0] - 1;
    for (c1_i110 = 0; c1_i110 <= c1_b_loop_ub; c1_i110++) {
      c1_outData_data[c1_i110 + c1_outData_size[0] * c1_i109] =
        c1_y_data[c1_i110 + c1_y_size[0] * c1_i109];
    }
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  real_T c1_b_u;
  const mxArray *c1_y = NULL;
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_b_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_g_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_numberOfFeaturePoints, const char_T
  *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_numberOfFeaturePoints), &c1_thisId);
  sf_mex_destroy(&c1_b_numberOfFeaturePoints);
  return c1_y;
}

static real_T c1_h_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d2;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_d2, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d2;
  sf_mex_destroy(&c1_b_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_numberOfFeaturePoints;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_b_numberOfFeaturePoints = sf_mex_dup(c1_mxArrayInData);
  c1_thisId.fIdentifier = (const char *)c1_varName;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_numberOfFeaturePoints), &c1_thisId);
  sf_mex_destroy(&c1_b_numberOfFeaturePoints);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, real32_T
  c1_inData_data[], int32_T c1_inData_size[2])
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_u_size[2];
  int32_T c1_b_u;
  int32_T c1_c_u;
  int32_T c1_loop_ub;
  int32_T c1_i111;
  const mxArray *c1_y = NULL;
  real32_T c1_u_data[1000];
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u_size[0] = c1_inData_size[0];
  c1_u_size[1] = c1_inData_size[1];
  c1_b_u = c1_u_size[0];
  c1_c_u = c1_u_size[1];
  c1_loop_ub = c1_inData_size[0] * c1_inData_size[1] - 1;
  for (c1_i111 = 0; c1_i111 <= c1_loop_ub; c1_i111++) {
    c1_u_data[c1_i111] = c1_inData_data[c1_i111];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", (void *)&c1_u_data, 1, 0U, 1U, 0U, 2,
    c1_u_size[0], c1_u_size[1]), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_i_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_newFeaturePointLocations, const char_T
  *c1_identifier, real32_T c1_y_data[], int32_T c1_y_size[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_newFeaturePointLocations),
                        &c1_thisId, c1_y_data, c1_y_size);
  sf_mex_destroy(&c1_newFeaturePointLocations);
}

static void c1_j_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  real32_T c1_y_data[], int32_T c1_y_size[2])
{
  int32_T c1_i112;
  int32_T c1_tmp_size[2];
  uint32_T c1_uv4[2];
  int32_T c1_i113;
  real32_T c1_tmp_data[1000];
  boolean_T c1_bv3[2];
  int32_T c1_y;
  int32_T c1_b_y;
  int32_T c1_loop_ub;
  int32_T c1_i114;
  (void)chartInstance;
  for (c1_i112 = 0; c1_i112 < 2; c1_i112++) {
    c1_uv4[c1_i112] = 500U + (uint32_T)(-498 * c1_i112);
  }

  c1_tmp_size[0] = sf_mex_get_dimension(c1_b_u, 0);
  c1_tmp_size[1] = sf_mex_get_dimension(c1_b_u, 1);
  for (c1_i113 = 0; c1_i113 < 2; c1_i113++) {
    c1_bv3[c1_i113] = true;
  }

  sf_mex_import_vs(c1_parentId, sf_mex_dup(c1_b_u), (void *)&c1_tmp_data, 1, 1,
                   0U, 1, 0U, 2, c1_bv3, c1_uv4, c1_tmp_size);
  c1_y_size[0] = c1_tmp_size[0];
  c1_y_size[1] = c1_tmp_size[1];
  c1_y = c1_y_size[0];
  c1_b_y = c1_y_size[1];
  c1_loop_ub = c1_tmp_size[0] * c1_tmp_size[1] - 1;
  for (c1_i114 = 0; c1_i114 <= c1_loop_ub; c1_i114++) {
    c1_y_data[c1_i114] = c1_tmp_data[c1_i114];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real32_T c1_outData_data[],
  int32_T c1_outData_size[2])
{
  const mxArray *c1_newFeaturePointLocations;
  emlrtMsgIdentifier c1_thisId;
  real32_T c1_y_data[1000];
  int32_T c1_y_size[2];
  int32_T c1_loop_ub;
  int32_T c1_i115;
  int32_T c1_b_loop_ub;
  int32_T c1_i116;
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_newFeaturePointLocations = sf_mex_dup(c1_mxArrayInData);
  c1_thisId.fIdentifier = (const char *)c1_varName;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_newFeaturePointLocations),
                        &c1_thisId, c1_y_data, c1_y_size);
  sf_mex_destroy(&c1_newFeaturePointLocations);
  c1_outData_size[0] = c1_y_size[0];
  c1_outData_size[1] = c1_y_size[1];
  c1_loop_ub = c1_y_size[1] - 1;
  for (c1_i115 = 0; c1_i115 <= c1_loop_ub; c1_i115++) {
    c1_b_loop_ub = c1_y_size[0] - 1;
    for (c1_i116 = 0; c1_i116 <= c1_b_loop_ub; c1_i116++) {
      c1_outData_data[c1_i116 + c1_outData_size[0] * c1_i115] =
        c1_y_data[c1_i116 + c1_y_size[0] * c1_i115];
    }
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[], int32_T c1_inData_size[2])
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_u_size[2];
  int32_T c1_b_u;
  int32_T c1_c_u;
  int32_T c1_loop_ub;
  int32_T c1_i117;
  const mxArray *c1_y = NULL;
  real_T c1_u_data[8];
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u_size[0] = c1_inData_size[0];
  c1_u_size[1] = c1_inData_size[1];
  c1_b_u = c1_u_size[0];
  c1_c_u = c1_u_size[1];
  c1_loop_ub = c1_inData_size[0] * c1_inData_size[1] - 1;
  for (c1_i117 = 0; c1_i117 <= c1_loop_ub; c1_i117++) {
    c1_u_data[c1_i117] = c1_inData_data[c1_i117];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", (void *)&c1_u_data, 0, 0U, 1U, 0U, 2,
    c1_u_size[0], c1_u_size[1]), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_k_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_bBoxCornerPts, const char_T *c1_identifier,
  real_T c1_y_data[], int32_T c1_y_size[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_bBoxCornerPts), &c1_thisId,
                        c1_y_data, c1_y_size);
  sf_mex_destroy(&c1_bBoxCornerPts);
}

static void c1_l_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y_data[], int32_T c1_y_size[2])
{
  int32_T c1_i118;
  int32_T c1_tmp_size[2];
  uint32_T c1_uv5[2];
  int32_T c1_i119;
  real_T c1_tmp_data[8];
  boolean_T c1_bv4[2];
  int32_T c1_y;
  int32_T c1_b_y;
  int32_T c1_loop_ub;
  int32_T c1_i120;
  (void)chartInstance;
  for (c1_i118 = 0; c1_i118 < 2; c1_i118++) {
    c1_uv5[c1_i118] = 4U + (uint32_T)(-2 * c1_i118);
  }

  c1_tmp_size[0] = sf_mex_get_dimension(c1_b_u, 0);
  c1_tmp_size[1] = sf_mex_get_dimension(c1_b_u, 1);
  for (c1_i119 = 0; c1_i119 < 2; c1_i119++) {
    c1_bv4[c1_i119] = true;
  }

  sf_mex_import_vs(c1_parentId, sf_mex_dup(c1_b_u), (void *)&c1_tmp_data, 1, 0,
                   0U, 1, 0U, 2, c1_bv4, c1_uv5, c1_tmp_size);
  c1_y_size[0] = c1_tmp_size[0];
  c1_y_size[1] = c1_tmp_size[1];
  c1_y = c1_y_size[0];
  c1_b_y = c1_y_size[1];
  c1_loop_ub = c1_tmp_size[0] * c1_tmp_size[1] - 1;
  for (c1_i120 = 0; c1_i120 <= c1_loop_ub; c1_i120++) {
    c1_y_data[c1_i120] = c1_tmp_data[c1_i120];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[], int32_T
  c1_outData_size[2])
{
  const mxArray *c1_bBoxCornerPts;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y_data[8];
  int32_T c1_y_size[2];
  int32_T c1_loop_ub;
  int32_T c1_i121;
  int32_T c1_b_loop_ub;
  int32_T c1_i122;
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_bBoxCornerPts = sf_mex_dup(c1_mxArrayInData);
  c1_thisId.fIdentifier = (const char *)c1_varName;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_bBoxCornerPts), &c1_thisId,
                        c1_y_data, c1_y_size);
  sf_mex_destroy(&c1_bBoxCornerPts);
  c1_outData_size[0] = c1_y_size[0];
  c1_outData_size[1] = c1_y_size[1];
  c1_loop_ub = c1_y_size[1] - 1;
  for (c1_i121 = 0; c1_i121 <= c1_loop_ub; c1_i121++) {
    c1_b_loop_ub = c1_y_size[0] - 1;
    for (c1_i122 = 0; c1_i122 <= c1_b_loop_ub; c1_i122++) {
      c1_outData_data[c1_i122 + c1_outData_size[0] * c1_i121] =
        c1_y_data[c1_i122 + c1_y_size[0] * c1_i121];
    }
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[], int32_T c1_inData_size[2])
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_u_size[2];
  int32_T c1_b_u;
  int32_T c1_c_u;
  int32_T c1_loop_ub;
  int32_T c1_i123;
  const mxArray *c1_y = NULL;
  real_T c1_u_data[16];
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u_size[0] = c1_inData_size[0];
  c1_u_size[1] = c1_inData_size[1];
  c1_b_u = c1_u_size[0];
  c1_c_u = c1_u_size[1];
  c1_loop_ub = c1_inData_size[0] * c1_inData_size[1] - 1;
  for (c1_i123 = 0; c1_i123 <= c1_loop_ub; c1_i123++) {
    c1_u_data[c1_i123] = c1_inData_data[c1_i123];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", (void *)&c1_u_data, 0, 0U, 1U, 0U, 2,
    c1_u_size[0], c1_u_size[1]), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i124;
  int32_T c1_i125;
  const mxArray *c1_y = NULL;
  int32_T c1_i126;
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_i124 = 0;
  for (c1_i125 = 0; c1_i125 < 1024; c1_i125++) {
    for (c1_i126 = 0; c1_i126 < 1024; c1_i126++) {
      chartInstance->c1_u[c1_i126 + c1_i124] = (*(real_T (*)[1048576])c1_inData)
        [c1_i126 + c1_i124];
    }

    c1_i124 += 1024;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", chartInstance->c1_u, 0, 0U, 1U, 0U, 2,
    1024, 1024), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid,
  c1_emxArray_real_T *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  c1_emxArray_real_T *c1_b_u;
  int32_T c1_i127;
  int32_T c1_c_u;
  int32_T c1_d_u;
  int32_T c1_loop_ub;
  int32_T c1_i128;
  const mxArray *c1_y = NULL;
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_emxInit_real_T(chartInstance, &c1_b_u, 2, (emlrtRTEInfo *)NULL);
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_i127 = c1_b_u->size[0] * c1_b_u->size[1];
  c1_b_u->size[0] = c1_inData->size[0];
  c1_b_u->size[1] = c1_inData->size[1];
  c1_emxEnsureCapacity_real_T(chartInstance, c1_b_u, c1_i127, (emlrtRTEInfo *)
    NULL);
  c1_c_u = c1_b_u->size[0];
  c1_d_u = c1_b_u->size[1];
  c1_loop_ub = c1_inData->size[0] * c1_inData->size[1] - 1;
  for (c1_i128 = 0; c1_i128 <= c1_loop_ub; c1_i128++) {
    c1_b_u->data[c1_i128] = c1_inData->data[c1_i128];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_u->data, 0, 0U, 1U, 0U, 2,
    c1_b_u->size[0], c1_b_u->size[1]), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  c1_emxFree_real_T(chartInstance, &c1_b_u);
  return c1_mxArrayOutData;
}

static void c1_m_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  c1_emxArray_real_T *c1_y)
{
  c1_emxArray_real_T *c1_r2;
  int32_T c1_i129;
  int32_T c1_i130;
  uint32_T c1_uv6[2];
  int32_T c1_i131;
  boolean_T c1_bv5[2];
  int32_T c1_i132;
  int32_T c1_b_y;
  int32_T c1_c_y;
  int32_T c1_loop_ub;
  int32_T c1_i133;
  c1_emxInit_real_T(chartInstance, &c1_r2, 2, (emlrtRTEInfo *)NULL);
  for (c1_i129 = 0; c1_i129 < 2; c1_i129++) {
    c1_uv6[c1_i129] = 1024U;
  }

  c1_i130 = c1_r2->size[0] * c1_r2->size[1];
  c1_r2->size[0] = sf_mex_get_dimension(c1_b_u, 0);
  c1_r2->size[1] = sf_mex_get_dimension(c1_b_u, 1);
  c1_emxEnsureCapacity_real_T(chartInstance, c1_r2, c1_i130, (emlrtRTEInfo *)
    NULL);
  for (c1_i131 = 0; c1_i131 < 2; c1_i131++) {
    c1_bv5[c1_i131] = true;
  }

  sf_mex_import_vs(c1_parentId, sf_mex_dup(c1_b_u), c1_r2->data, 1, 0, 0U, 1, 0U,
                   2, c1_bv5, c1_uv6, c1_r2->size);
  c1_i132 = c1_y->size[0] * c1_y->size[1];
  c1_y->size[0] = c1_r2->size[0];
  c1_y->size[1] = c1_r2->size[1];
  c1_emxEnsureCapacity_real_T(chartInstance, c1_y, c1_i132, (emlrtRTEInfo *)NULL);
  c1_b_y = c1_y->size[0];
  c1_c_y = c1_y->size[1];
  c1_loop_ub = c1_r2->size[0] * c1_r2->size[1] - 1;
  for (c1_i133 = 0; c1_i133 <= c1_loop_ub; c1_i133++) {
    c1_y->data[c1_i133] = c1_r2->data[c1_i133];
  }

  sf_mex_destroy(&c1_b_u);
  c1_emxFree_real_T(chartInstance, &c1_r2);
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, c1_emxArray_real_T *c1_outData)
{
  c1_emxArray_real_T *c1_y;
  const mxArray *c1_c_videoFrameGray;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_i134;
  int32_T c1_loop_ub;
  int32_T c1_i135;
  int32_T c1_b_loop_ub;
  int32_T c1_i136;
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_emxInit_real_T(chartInstance, &c1_y, 2, (emlrtRTEInfo *)NULL);
  c1_c_videoFrameGray = sf_mex_dup(c1_mxArrayInData);
  c1_thisId.fIdentifier = (const char *)c1_varName;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_c_videoFrameGray),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_c_videoFrameGray);
  c1_i134 = c1_outData->size[0] * c1_outData->size[1];
  c1_outData->size[0] = c1_y->size[0];
  c1_outData->size[1] = c1_y->size[1];
  c1_emxEnsureCapacity_real_T(chartInstance, c1_outData, c1_i134, (emlrtRTEInfo *)
    NULL);
  c1_loop_ub = c1_y->size[1] - 1;
  for (c1_i135 = 0; c1_i135 <= c1_loop_ub; c1_i135++) {
    c1_b_loop_ub = c1_y->size[0] - 1;
    for (c1_i136 = 0; c1_i136 <= c1_b_loop_ub; c1_i136++) {
      c1_outData->data[c1_i136 + c1_outData->size[0] * c1_i135] = c1_y->
        data[c1_i136 + c1_y->size[0] * c1_i135];
    }
  }

  c1_emxFree_real_T(chartInstance, &c1_y);
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, c1_affine2d
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  c1_affine2d c1_b_u;
  const mxArray *c1_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_propValues[2];
  int32_T c1_u_size[2];
  int32_T c1_d_u;
  int32_T c1_e_u;
  int32_T c1_loop_ub;
  int32_T c1_i137;
  const mxArray *c1_c_y = NULL;
  real32_T c1_u_data[9];
  const char * c1_propNames[2] = { "Dimensionality", "T" };

  const char * c1_propClasses[2] = {
    "images.geotrans.internal.GeometricTransformation", "affine2d" };

  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_b_u = *c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create_class_instance("affine2d"), false);
  c1_c_u = c1_b_u.Dimensionality;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), false);
  c1_propValues[0] = c1_b_y;
  c1_u_size[0] = c1_b_u.T.size[0];
  c1_u_size[1] = c1_b_u.T.size[1];
  c1_d_u = c1_u_size[0];
  c1_e_u = c1_u_size[1];
  c1_loop_ub = c1_b_u.T.size[0] * c1_b_u.T.size[1] - 1;
  for (c1_i137 = 0; c1_i137 <= c1_loop_ub; c1_i137++) {
    c1_u_data[c1_i137] = c1_b_u.T.data[c1_i137];
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", (void *)&c1_u_data, 1, 0U, 1U, 0U, 2,
    c1_b_u.T.size[0], c1_b_u.T.size[1]), false);
  c1_propValues[1] = c1_c_y;
  sf_mex_set_all_properties(&c1_y, 0, 2, c1_propNames, c1_propClasses,
    c1_propValues);
  sf_mex_assign(&c1_y, sf_mex_convert_to_redirect_source(c1_y, 0, "affine2d"),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_n_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  c1_affine2d *c1_y)
{
  emlrtMsgIdentifier c1_thisId;
  const char * c1_propNames[2] = { "Dimensionality", "T" };

  const char * c1_propClasses[2] = {
    "images.geotrans.internal.GeometricTransformation", "affine2d" };

  const mxArray *c1_propValues[2];
  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_mcos_class(c1_parentId, c1_b_u, "affine2d");
  sf_mex_get_all_properties(c1_b_u, 0, 2, c1_propNames, c1_propClasses,
    c1_propValues);
  c1_thisId.fIdentifier = "Dimensionality";
  c1_y->Dimensionality = c1_h_emlrt_marshallIn(chartInstance, c1_propValues[0],
    &c1_thisId);
  c1_thisId.fIdentifier = "T";
  c1_o_emlrt_marshallIn(chartInstance, c1_propValues[1], &c1_thisId,
                        c1_y->T.data, c1_y->T.size);
  sf_mex_destroy(&c1_b_u);
}

static void c1_o_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  real32_T c1_y_data[], int32_T c1_y_size[2])
{
  int32_T c1_i138;
  int32_T c1_tmp_size[2];
  uint32_T c1_uv7[2];
  int32_T c1_i139;
  real32_T c1_tmp_data[9];
  boolean_T c1_bv6[2];
  int32_T c1_y;
  int32_T c1_b_y;
  int32_T c1_loop_ub;
  int32_T c1_i140;
  (void)chartInstance;
  for (c1_i138 = 0; c1_i138 < 2; c1_i138++) {
    c1_uv7[c1_i138] = 3U;
  }

  c1_tmp_size[0] = sf_mex_get_dimension(c1_b_u, 0);
  c1_tmp_size[1] = sf_mex_get_dimension(c1_b_u, 1);
  for (c1_i139 = 0; c1_i139 < 2; c1_i139++) {
    c1_bv6[c1_i139] = true;
  }

  sf_mex_import_vs(c1_parentId, sf_mex_dup(c1_b_u), (void *)&c1_tmp_data, 1, 1,
                   0U, 1, 0U, 2, c1_bv6, c1_uv7, c1_tmp_size);
  c1_y_size[0] = c1_tmp_size[0];
  c1_y_size[1] = c1_tmp_size[1];
  c1_y = c1_y_size[0];
  c1_b_y = c1_y_size[1];
  c1_loop_ub = c1_tmp_size[0] * c1_tmp_size[1] - 1;
  for (c1_i140 = 0; c1_i140 <= c1_loop_ub; c1_i140++) {
    c1_y_data[c1_i140] = c1_tmp_data[c1_i140];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, c1_affine2d *c1_outData)
{
  const mxArray *c1_xform;
  emlrtMsgIdentifier c1_thisId;
  c1_affine2d c1_y;
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_xform = sf_mex_dup(c1_mxArrayInData);
  c1_thisId.fIdentifier = (const char *)c1_varName;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_xform), &c1_thisId, &c1_y);
  sf_mex_destroy(&c1_xform);
  *c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid,
  c1_emxArray_real32_T *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  c1_emxArray_real32_T *c1_b_u;
  int32_T c1_i141;
  int32_T c1_c_u;
  int32_T c1_d_u;
  int32_T c1_loop_ub;
  int32_T c1_i142;
  const mxArray *c1_y = NULL;
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_emxInit_real32_T(chartInstance, &c1_b_u, 2, (emlrtRTEInfo *)NULL);
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_i141 = c1_b_u->size[0] * c1_b_u->size[1];
  c1_b_u->size[0] = c1_inData->size[0];
  c1_b_u->size[1] = c1_inData->size[1];
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_b_u, c1_i141, (emlrtRTEInfo *)
    NULL);
  c1_c_u = c1_b_u->size[0];
  c1_d_u = c1_b_u->size[1];
  c1_loop_ub = c1_inData->size[0] * c1_inData->size[1] - 1;
  for (c1_i142 = 0; c1_i142 <= c1_loop_ub; c1_i142++) {
    c1_b_u->data[c1_i142] = c1_inData->data[c1_i142];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_u->data, 1, 0U, 1U, 0U, 2,
    c1_b_u->size[0], c1_b_u->size[1]), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  c1_emxFree_real32_T(chartInstance, &c1_b_u);
  return c1_mxArrayOutData;
}

static void c1_p_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  c1_emxArray_real32_T *c1_y)
{
  c1_emxArray_real32_T *c1_r3;
  int32_T c1_i143;
  int32_T c1_i144;
  uint32_T c1_uv8[2];
  static uint32_T c1_uv9[2] = { MAX_uint32_T, 2U };

  int32_T c1_i145;
  boolean_T c1_bv7[2];
  int32_T c1_i146;
  int32_T c1_b_y;
  int32_T c1_c_y;
  int32_T c1_loop_ub;
  int32_T c1_i147;
  c1_emxInit_real32_T(chartInstance, &c1_r3, 2, (emlrtRTEInfo *)NULL);
  for (c1_i143 = 0; c1_i143 < 2; c1_i143++) {
    c1_uv8[c1_i143] = c1_uv9[c1_i143];
  }

  c1_i144 = c1_r3->size[0] * c1_r3->size[1];
  c1_r3->size[0] = sf_mex_get_dimension(c1_b_u, 0);
  c1_r3->size[1] = sf_mex_get_dimension(c1_b_u, 1);
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_r3, c1_i144, (emlrtRTEInfo *)
    NULL);
  for (c1_i145 = 0; c1_i145 < 2; c1_i145++) {
    c1_bv7[c1_i145] = true;
  }

  sf_mex_import_vs(c1_parentId, sf_mex_dup(c1_b_u), c1_r3->data, 1, 1, 0U, 1, 0U,
                   2, c1_bv7, c1_uv8, c1_r3->size);
  c1_i146 = c1_y->size[0] * c1_y->size[1];
  c1_y->size[0] = c1_r3->size[0];
  c1_y->size[1] = c1_r3->size[1];
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_y, c1_i146, (emlrtRTEInfo *)
    NULL);
  c1_b_y = c1_y->size[0];
  c1_c_y = c1_y->size[1];
  c1_loop_ub = c1_r3->size[0] * c1_r3->size[1] - 1;
  for (c1_i147 = 0; c1_i147 <= c1_loop_ub; c1_i147++) {
    c1_y->data[c1_i147] = c1_r3->data[c1_i147];
  }

  sf_mex_destroy(&c1_b_u);
  c1_emxFree_real32_T(chartInstance, &c1_r3);
}

static void c1_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, c1_emxArray_real32_T *c1_outData)
{
  c1_emxArray_real32_T *c1_y;
  const mxArray *c1_oldInliers;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_i148;
  int32_T c1_loop_ub;
  int32_T c1_i149;
  int32_T c1_b_loop_ub;
  int32_T c1_i150;
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_emxInit_real32_T(chartInstance, &c1_y, 2, (emlrtRTEInfo *)NULL);
  c1_oldInliers = sf_mex_dup(c1_mxArrayInData);
  c1_thisId.fIdentifier = (const char *)c1_varName;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_oldInliers), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_oldInliers);
  c1_i148 = c1_outData->size[0] * c1_outData->size[1];
  c1_outData->size[0] = c1_y->size[0];
  c1_outData->size[1] = c1_y->size[1];
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_outData, c1_i148,
    (emlrtRTEInfo *)NULL);
  c1_loop_ub = c1_y->size[1] - 1;
  for (c1_i149 = 0; c1_i149 <= c1_loop_ub; c1_i149++) {
    c1_b_loop_ub = c1_y->size[0] - 1;
    for (c1_i150 = 0; c1_i150 <= c1_b_loop_ub; c1_i150++) {
      c1_outData->data[c1_i150 + c1_outData->size[0] * c1_i149] = c1_y->
        data[c1_i150 + c1_y->size[0] * c1_i149];
    }
  }

  c1_emxFree_real32_T(chartInstance, &c1_y);
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_l_sf_marshallOut(void *chartInstanceVoid,
  c1_emxArray_boolean_T *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  c1_emxArray_boolean_T *c1_b_u;
  int32_T c1_i151;
  int32_T c1_loop_ub;
  int32_T c1_i152;
  const mxArray *c1_y = NULL;
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_emxInit_boolean_T(chartInstance, &c1_b_u, 1, (emlrtRTEInfo *)NULL);
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_i151 = c1_b_u->size[0];
  c1_b_u->size[0] = c1_inData->size[0];
  c1_emxEnsureCapacity_boolean_T(chartInstance, c1_b_u, c1_i151, (emlrtRTEInfo *)
    NULL);
  c1_loop_ub = c1_inData->size[0] - 1;
  for (c1_i152 = 0; c1_i152 <= c1_loop_ub; c1_i152++) {
    c1_b_u->data[c1_i152] = c1_inData->data[c1_i152];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_u->data, 11, 0U, 1U, 0U, 1,
    c1_b_u->size[0]), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  c1_emxFree_boolean_T(chartInstance, &c1_b_u);
  return c1_mxArrayOutData;
}

static void c1_q_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  c1_emxArray_boolean_T *c1_y)
{
  c1_emxArray_boolean_T *c1_r4;
  uint32_T c1_uv10[1];
  int32_T c1_i153;
  boolean_T c1_bv8[1];
  int32_T c1_i154;
  int32_T c1_loop_ub;
  int32_T c1_i155;
  c1_emxInit_boolean_T(chartInstance, &c1_r4, 1, (emlrtRTEInfo *)NULL);
  c1_uv10[0] = MAX_uint32_T;
  c1_i153 = c1_r4->size[0];
  c1_r4->size[0] = sf_mex_get_dimension(c1_b_u, 0);
  c1_emxEnsureCapacity_boolean_T(chartInstance, c1_r4, c1_i153, (emlrtRTEInfo *)
    NULL);
  c1_bv8[0] = true;
  sf_mex_import_vs(c1_parentId, sf_mex_dup(c1_b_u), c1_r4->data, 1, 11, 0U, 1,
                   0U, 1, c1_bv8, c1_uv10, c1_r4->size);
  c1_i154 = c1_y->size[0];
  c1_y->size[0] = c1_r4->size[0];
  c1_emxEnsureCapacity_boolean_T(chartInstance, c1_y, c1_i154, (emlrtRTEInfo *)
    NULL);
  c1_loop_ub = c1_r4->size[0] - 1;
  for (c1_i155 = 0; c1_i155 <= c1_loop_ub; c1_i155++) {
    c1_y->data[c1_i155] = c1_r4->data[c1_i155];
  }

  sf_mex_destroy(&c1_b_u);
  c1_emxFree_boolean_T(chartInstance, &c1_r4);
}

static void c1_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, c1_emxArray_boolean_T *c1_outData)
{
  c1_emxArray_boolean_T *c1_y;
  const mxArray *c1_isFound;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_i156;
  int32_T c1_loop_ub;
  int32_T c1_i157;
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_emxInit_boolean_T(chartInstance, &c1_y, 1, (emlrtRTEInfo *)NULL);
  c1_isFound = sf_mex_dup(c1_mxArrayInData);
  c1_thisId.fIdentifier = (const char *)c1_varName;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_isFound), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_isFound);
  c1_i156 = c1_outData->size[0];
  c1_outData->size[0] = c1_y->size[0];
  c1_emxEnsureCapacity_boolean_T(chartInstance, c1_outData, c1_i156,
    (emlrtRTEInfo *)NULL);
  c1_loop_ub = c1_y->size[0] - 1;
  for (c1_i157 = 0; c1_i157 <= c1_loop_ub; c1_i157++) {
    c1_outData->data[c1_i157] = c1_y->data[c1_i157];
  }

  c1_emxFree_boolean_T(chartInstance, &c1_y);
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_DetectAndTrackFace_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static void c1_PointTracker_initialize(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_vision_PointTracker *c1_obj, c1_emxArray_real_T *c1_I)
{
  const mxArray *c1_y = NULL;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  int32_T c1_i158;
  static char_T c1_cv17[5] = { 's', 'e', 't', 'u', 'p' };

  int32_T c1_i159;
  int32_T c1_i160;
  c1_cell_wrap_2 c1_varSizes[1];
  real_T c1_d3;
  const mxArray *c1_e_y = NULL;
  c1_emxArray_real_T *c1_b_I;
  uint32_T c1_u0;
  const mxArray *c1_f_y = NULL;
  int32_T c1_i161;
  int32_T c1_c_I;
  int32_T c1_d_I;
  int32_T c1_loop_ub;
  int32_T c1_i162;
  c1_emxArray_uint8_T *c1_Iu8;
  int32_T c1_i163;
  void * c1_ptrObj;
  c1_skA5dKpnjgSNaA6XSElXHZH c1_params;
  int32_T c1_i164;
  c1_emxArray_uint8_T *c1_Iu8_grayT;
  real32_T c1_points[2];
  int32_T c1_blockH;
  int32_T c1_blockW;
  cvstPTStruct_T c1_paramStruct;
  int32_T c1_outVal;
  real_T c1_b_outVal;
  int32_T c1_i165;
  int32_T c1_b_loop_ub;
  int32_T c1_i166;
  int32_T c1_c_loop_ub;
  int32_T c1_i167;
  if (!((c1_I->size[0] == 0) || (c1_I->size[1] == 0))) {
  } else {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv3, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv4, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c1_y, 14,
                      c1_b_y);
  }

  if (c1_obj->isInitialized == 0) {
  } else {
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv5, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_cv17, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c1_c_y, 14, c1_d_y));
  }

  c1_obj->isInitialized = 1;
  for (c1_i158 = 0; c1_i158 < 2; c1_i158++) {
    c1_i160 = c1_I->size[c1_i158];
    if (c1_i160 < 0) {
      c1_i160 = 0;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
    }

    c1_varSizes[0].f1[c1_i158] = (uint32_T)c1_i160;
  }

  for (c1_i159 = 0; c1_i159 < 6; c1_i159++) {
    c1_d3 = muDoubleScalarRound(1.0);
    if (c1_d3 < 4.294967296E+9) {
      if (c1_d3 >= 0.0) {
        c1_u0 = (uint32_T)c1_d3;
      } else {
        c1_u0 = 0U;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      }
    } else if (c1_d3 >= 4.294967296E+9) {
      c1_u0 = MAX_uint32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
    } else {
      c1_u0 = 0U;
    }

    c1_varSizes[0].f1[c1_i159 + 2] = c1_u0;
  }

  c1_obj->inputVarSize[0] = c1_varSizes[0];
  if (!((c1_I->size[0] == 0) || (c1_I->size[1] == 0))) {
  } else {
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_cv3, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_cv4, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c1_e_y,
                      14, c1_f_y);
  }

  c1_emxInit_real_T(chartInstance, &c1_b_I, 2, &c1_rb_emlrtRTEI);
  c1_obj->FrameClassID = 0.0;
  c1_i161 = c1_b_I->size[0] * c1_b_I->size[1];
  c1_b_I->size[0] = c1_I->size[0];
  c1_b_I->size[1] = c1_I->size[1];
  c1_emxEnsureCapacity_real_T(chartInstance, c1_b_I, c1_i161, &c1_rb_emlrtRTEI);
  c1_c_I = c1_b_I->size[0];
  c1_d_I = c1_b_I->size[1];
  c1_loop_ub = c1_I->size[0] * c1_I->size[1] - 1;
  for (c1_i162 = 0; c1_i162 <= c1_loop_ub; c1_i162++) {
    c1_b_I->data[c1_i162] = c1_I->data[c1_i162];
  }

  c1_emxInit_uint8_T(chartInstance, &c1_Iu8, 2, &c1_tb_emlrtRTEI);
  c1_im2uint8(chartInstance, c1_b_I, c1_Iu8);
  c1_emxFree_real_T(chartInstance, &c1_b_I);
  for (c1_i163 = 0; c1_i163 < 2; c1_i163++) {
    c1_obj->FrameSize[c1_i163] = (real_T)c1_Iu8->size[c1_i163];
  }

  c1_obj->NumPoints = 1.0;
  c1_ptrObj = c1_obj->pTracker;
  c1_params = c1_PointTracker_getKLTParams(chartInstance, c1_obj);
  for (c1_i164 = 0; c1_i164 < 2; c1_i164++) {
    c1_points[c1_i164] = 10.0F;
  }

  c1_emxInit_uint8_T(chartInstance, &c1_Iu8_grayT, 2, &c1_sb_emlrtRTEI);
  c1_blockH = (int32_T)(31.0);
  c1_blockW = (int32_T)(31.0);
  c1_paramStruct.blockSize[0] = c1_blockH;
  c1_paramStruct.blockSize[1] = c1_blockW;
  c1_outVal = (int32_T)(c1_params.NumPyramidLevels);
  c1_paramStruct.numPyramidLevels = c1_outVal;
  c1_b_outVal = (double)(30.0);
  c1_paramStruct.maxIterations = c1_b_outVal;
  c1_paramStruct.epsilon = 0.01;
  c1_paramStruct.maxBidirectionalError = 2.0;
  c1_i165 = c1_Iu8_grayT->size[0] * c1_Iu8_grayT->size[1];
  c1_Iu8_grayT->size[0] = c1_Iu8->size[1];
  c1_Iu8_grayT->size[1] = c1_Iu8->size[0];
  c1_emxEnsureCapacity_uint8_T(chartInstance, c1_Iu8_grayT, c1_i165,
    &c1_sb_emlrtRTEI);
  c1_b_loop_ub = c1_Iu8->size[0] - 1;
  for (c1_i166 = 0; c1_i166 <= c1_b_loop_ub; c1_i166++) {
    c1_c_loop_ub = c1_Iu8->size[1] - 1;
    for (c1_i167 = 0; c1_i167 <= c1_c_loop_ub; c1_i167++) {
      c1_Iu8_grayT->data[c1_i167 + c1_Iu8_grayT->size[0] * c1_i166] =
        c1_Iu8->data[c1_i166 + c1_Iu8->size[0] * c1_i167];
    }
  }

  pointTracker_initialize(c1_ptrObj, &c1_Iu8_grayT->data[0], c1_Iu8->size[0],
    c1_Iu8->size[1], c1_points, 1, &c1_paramStruct);
  c1_emxFree_uint8_T(chartInstance, &c1_Iu8_grayT);
  c1_emxFree_uint8_T(chartInstance, &c1_Iu8);
}

static void c1_im2uint8(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  c1_emxArray_real_T *c1_img, c1_emxArray_uint8_T *c1_b_u)
{
  int32_T c1_i168;
  c1_i168 = c1_b_u->size[0] * c1_b_u->size[1];
  c1_b_u->size[0] = c1_img->size[0];
  c1_b_u->size[1] = c1_img->size[1];
  c1_emxEnsureCapacity_uint8_T(chartInstance, c1_b_u, c1_i168, &c1_ub_emlrtRTEI);
  grayto8_real64(&c1_img->data[0], &c1_b_u->data[0], (real_T)(c1_img->size[0] *
    c1_img->size[1]));
}

static c1_skA5dKpnjgSNaA6XSElXHZH c1_PointTracker_getKLTParams
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance, c1_vision_PointTracker *
   c1_obj)
{
  c1_skA5dKpnjgSNaA6XSElXHZH c1_kltParams;
  int32_T c1_i169;
  int32_T c1_i170;
  int32_T c1_ixstart;
  real_T c1_varargin_1[2];
  real_T c1_mtmp;
  int32_T c1_ix;
  boolean_T c1_p;
  real_T c1_f;
  real_T c1_t;
  real_T c1_fdbl;
  int32_T c1_eint;
  real_T c1_inte;
  boolean_T exitg1;
  for (c1_i169 = 0; c1_i169 < 2; c1_i169++) {
    c1_kltParams.BlockSize[c1_i169] = 31.0;
  }

  for (c1_i170 = 0; c1_i170 < 2; c1_i170++) {
    c1_varargin_1[c1_i170] = c1_obj->FrameSize[c1_i170];
  }

  c1_ixstart = 1;
  c1_mtmp = c1_varargin_1[0];
  if (muDoubleScalarIsNaN(c1_varargin_1[0])) {
    c1_ix = 2;
    exitg1 = false;
    while ((!exitg1) && (c1_ix < 3)) {
      c1_ixstart = 2;
      if (!muDoubleScalarIsNaN(c1_varargin_1[1])) {
        c1_mtmp = c1_varargin_1[1];
        exitg1 = true;
      } else {
        c1_ix = 3;
      }
    }
  }

  if ((c1_ixstart < 2) && (c1_varargin_1[1] < c1_mtmp)) {
    c1_mtmp = c1_varargin_1[1];
  }

  c1_p = (c1_mtmp < 0.0);
  if (c1_p) {
    c1_error(chartInstance);
  }

  if (c1_mtmp == 0.0) {
    c1_f = rtMinusInf;
  } else if (c1_mtmp < 0.0) {
    c1_f = rtNaN;
  } else if ((!muDoubleScalarIsInf(c1_mtmp)) && (!muDoubleScalarIsNaN(c1_mtmp)))
  {
    if ((!muDoubleScalarIsInf(c1_mtmp)) && (!muDoubleScalarIsNaN(c1_mtmp))) {
      c1_fdbl = frexp(c1_mtmp, &c1_eint);
      c1_t = c1_fdbl;
      c1_inte = (real_T)c1_eint;
    } else {
      c1_t = c1_mtmp;
      c1_inte = 0.0;
    }

    if (c1_t == 0.5) {
      c1_f = c1_inte - 1.0;
    } else if ((c1_inte == 1.0) && (c1_t < 0.75)) {
      c1_f = muDoubleScalarLog(2.0 * c1_t) / 0.69314718055994529;
    } else {
      c1_f = muDoubleScalarLog(c1_t) / 0.69314718055994529 + c1_inte;
    }
  } else {
    c1_f = c1_mtmp;
  }

  c1_kltParams.NumPyramidLevels = muDoubleScalarMax(0.0, muDoubleScalarMin
    (muDoubleScalarFloor(c1_f - 2.0), 3.0));
  c1_kltParams.MaxIterations = 30.0;
  c1_kltParams.Epsilon = 0.01;
  c1_kltParams.MaxBidirectionalError = 2.0;
  return c1_kltParams;
}

static void c1_check_forloop_overflow_error
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance, boolean_T c1_overflow)
{
  const mxArray *c1_y = NULL;
  static char_T c1_cv18[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *c1_b_y = NULL;
  static char_T c1_cv19[5] = { 'i', 'n', 't', '3', '2' };

  (void)chartInstance;
  (void)c1_overflow;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv18, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv19, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c1_y, 14, c1_b_y));
}

static void c1_error(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  const mxArray *c1_y = NULL;
  const mxArray *c1_b_y = NULL;
  static char_T c1_cv20[4] = { 'l', 'o', 'g', '2' };

  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv6, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv20, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c1_y, 14, c1_b_y));
}

static void c1_b_PointTracker_initialize(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_vision_PointTracker *c1_obj, real32_T c1_points_data[],
  int32_T c1_points_size[2], c1_emxArray_real_T *c1_I)
{
  int32_T c1_b_points_size[2];
  int32_T c1_points;
  int32_T c1_b_points;
  int32_T c1_loop_ub;
  int32_T c1_i171;
  real32_T c1_b_points_data[1000];
  const mxArray *c1_y = NULL;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  int32_T c1_i172;
  static char_T c1_cv21[5] = { 's', 'e', 't', 'u', 'p' };

  int32_T c1_i173;
  int32_T c1_i174;
  c1_cell_wrap_2 c1_varSizes[1];
  real_T c1_d4;
  const mxArray *c1_e_y = NULL;
  c1_emxArray_real_T *c1_b_I;
  uint32_T c1_u1;
  const mxArray *c1_f_y = NULL;
  int32_T c1_i175;
  int32_T c1_c_I;
  int32_T c1_d_I;
  int32_T c1_b_loop_ub;
  int32_T c1_i176;
  c1_emxArray_uint8_T *c1_Iu8;
  int32_T c1_i177;
  void * c1_ptrObj;
  c1_skA5dKpnjgSNaA6XSElXHZH c1_params;
  int32_T c1_c_points_size[2];
  int32_T c1_c_points;
  int32_T c1_d_points;
  int32_T c1_c_loop_ub;
  int32_T c1_i178;
  c1_emxArray_uint8_T *c1_Iu8_grayT;
  real32_T c1_c_points_data[1000];
  int32_T c1_blockH;
  int32_T c1_blockW;
  cvstPTStruct_T c1_paramStruct;
  int32_T c1_outVal;
  real_T c1_b_outVal;
  int32_T c1_i179;
  int32_T c1_d_loop_ub;
  int32_T c1_i180;
  int32_T c1_e_loop_ub;
  int32_T c1_i181;
  c1_b_points_size[0] = c1_points_size[0];
  c1_b_points_size[1] = c1_points_size[1];
  c1_points = c1_b_points_size[0];
  c1_b_points = c1_b_points_size[1];
  c1_loop_ub = c1_points_size[0] * c1_points_size[1] - 1;
  for (c1_i171 = 0; c1_i171 <= c1_loop_ub; c1_i171++) {
    c1_b_points_data[c1_i171] = c1_points_data[c1_i171];
  }

  c1_PointTracker_validatePoints(chartInstance, c1_b_points_data,
    c1_b_points_size);
  if (!((c1_I->size[0] == 0) || (c1_I->size[1] == 0))) {
  } else {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv3, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv4, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c1_y, 14,
                      c1_b_y);
  }

  if (c1_obj->isInitialized == 0) {
  } else {
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv5, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_cv21, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c1_c_y, 14, c1_d_y));
  }

  c1_obj->isInitialized = 1;
  for (c1_i172 = 0; c1_i172 < 2; c1_i172++) {
    c1_i174 = c1_I->size[c1_i172];
    if (c1_i174 < 0) {
      c1_i174 = 0;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
    }

    c1_varSizes[0].f1[c1_i172] = (uint32_T)c1_i174;
  }

  for (c1_i173 = 0; c1_i173 < 6; c1_i173++) {
    c1_d4 = muDoubleScalarRound(1.0);
    if (c1_d4 < 4.294967296E+9) {
      if (c1_d4 >= 0.0) {
        c1_u1 = (uint32_T)c1_d4;
      } else {
        c1_u1 = 0U;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      }
    } else if (c1_d4 >= 4.294967296E+9) {
      c1_u1 = MAX_uint32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
    } else {
      c1_u1 = 0U;
    }

    c1_varSizes[0].f1[c1_i173 + 2] = c1_u1;
  }

  c1_obj->inputVarSize[0] = c1_varSizes[0];
  if (!((c1_I->size[0] == 0) || (c1_I->size[1] == 0))) {
  } else {
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_cv3, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_cv4, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c1_e_y,
                      14, c1_f_y);
  }

  c1_emxInit_real_T(chartInstance, &c1_b_I, 2, &c1_rb_emlrtRTEI);
  c1_obj->FrameClassID = 0.0;
  c1_i175 = c1_b_I->size[0] * c1_b_I->size[1];
  c1_b_I->size[0] = c1_I->size[0];
  c1_b_I->size[1] = c1_I->size[1];
  c1_emxEnsureCapacity_real_T(chartInstance, c1_b_I, c1_i175, &c1_rb_emlrtRTEI);
  c1_c_I = c1_b_I->size[0];
  c1_d_I = c1_b_I->size[1];
  c1_b_loop_ub = c1_I->size[0] * c1_I->size[1] - 1;
  for (c1_i176 = 0; c1_i176 <= c1_b_loop_ub; c1_i176++) {
    c1_b_I->data[c1_i176] = c1_I->data[c1_i176];
  }

  c1_emxInit_uint8_T(chartInstance, &c1_Iu8, 2, &c1_tb_emlrtRTEI);
  c1_im2uint8(chartInstance, c1_b_I, c1_Iu8);
  c1_emxFree_real_T(chartInstance, &c1_b_I);
  for (c1_i177 = 0; c1_i177 < 2; c1_i177++) {
    c1_obj->FrameSize[c1_i177] = (real_T)c1_Iu8->size[c1_i177];
  }

  c1_obj->NumPoints = (real_T)c1_points_size[0];
  c1_ptrObj = c1_obj->pTracker;
  c1_params = c1_PointTracker_getKLTParams(chartInstance, c1_obj);
  c1_c_points_size[0] = c1_points_size[0];
  c1_c_points_size[1] = c1_points_size[1];
  c1_c_points = c1_c_points_size[0];
  c1_d_points = c1_c_points_size[1];
  c1_c_loop_ub = c1_points_size[0] * c1_points_size[1] - 1;
  for (c1_i178 = 0; c1_i178 <= c1_c_loop_ub; c1_i178++) {
    c1_c_points_data[c1_i178] = c1_points_data[c1_i178];
  }

  c1_emxInit_uint8_T(chartInstance, &c1_Iu8_grayT, 2, &c1_sb_emlrtRTEI);
  c1_blockH = (int32_T)(31.0);
  c1_blockW = (int32_T)(31.0);
  c1_paramStruct.blockSize[0] = c1_blockH;
  c1_paramStruct.blockSize[1] = c1_blockW;
  c1_outVal = (int32_T)(c1_params.NumPyramidLevels);
  c1_paramStruct.numPyramidLevels = c1_outVal;
  c1_b_outVal = (double)(30.0);
  c1_paramStruct.maxIterations = c1_b_outVal;
  c1_paramStruct.epsilon = 0.01;
  c1_paramStruct.maxBidirectionalError = 2.0;
  c1_i179 = c1_Iu8_grayT->size[0] * c1_Iu8_grayT->size[1];
  c1_Iu8_grayT->size[0] = c1_Iu8->size[1];
  c1_Iu8_grayT->size[1] = c1_Iu8->size[0];
  c1_emxEnsureCapacity_uint8_T(chartInstance, c1_Iu8_grayT, c1_i179,
    &c1_sb_emlrtRTEI);
  c1_d_loop_ub = c1_Iu8->size[0] - 1;
  for (c1_i180 = 0; c1_i180 <= c1_d_loop_ub; c1_i180++) {
    c1_e_loop_ub = c1_Iu8->size[1] - 1;
    for (c1_i181 = 0; c1_i181 <= c1_e_loop_ub; c1_i181++) {
      c1_Iu8_grayT->data[c1_i181 + c1_Iu8_grayT->size[0] * c1_i180] =
        c1_Iu8->data[c1_i180 + c1_Iu8->size[0] * c1_i181];
    }
  }

  pointTracker_initialize(c1_ptrObj, &c1_Iu8_grayT->data[0], c1_Iu8->size[0],
    c1_Iu8->size[1], &c1_c_points_data[0], c1_points_size[0], &c1_paramStruct);
  c1_emxFree_uint8_T(chartInstance, &c1_Iu8_grayT);
  c1_emxFree_uint8_T(chartInstance, &c1_Iu8);
}

static void c1_PointTracker_validatePoints(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, real32_T c1_points_data[], int32_T c1_points_size[2])
{
  boolean_T c1_p;
  real_T c1_d5;
  int32_T c1_k;
  boolean_T c1_b10;
  const mxArray *c1_y = NULL;
  static char_T c1_cv22[36] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'P', 'o', 'i',
    'n', 't', 'T', 'r', 'a', 'c', 'k', 'e', 'r', ':', 'e', 'x', 'p', 'e', 'c',
    't', 'e', 'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  int32_T c1_b_points_size[2];
  const mxArray *c1_b_y = NULL;
  static char_T c1_cv23[31] = { 'E', 'x', 'p', 'e', 'c', 't', 'e', 'd', ' ', 'P',
    'O', 'I', 'N', 'T', 'S', ' ', 't', 'o', ' ', 'b', 'e', ' ', 'p', 'o', 's',
    'i', 't', 'i', 'v', 'e', '.' };

  int32_T c1_points;
  int32_T c1_b_points;
  int32_T c1_loop_ub;
  int32_T c1_i182;
  boolean_T c1_b11;
  real32_T c1_b_points_data[1500];
  const mxArray *c1_c_y = NULL;
  static char_T c1_cv24[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'P', 'o', 'i',
    'n', 't', 'T', 'r', 'a', 'c', 'k', 'e', 'r', ':', 'e', 'x', 'p', 'e', 'c',
    't', 'e', 'd', 'F', 'i', 'n', 'i', 't', 'e' };

  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  static char_T c1_cv25[29] = { 'E', 'x', 'p', 'e', 'c', 't', 'e', 'd', ' ', 'P',
    'O', 'I', 'N', 'T', 'S', ' ', 't', 'o', ' ', 'b', 'e', ' ', 'f', 'i', 'n',
    'i', 't', 'e', '.' };

  static char_T c1_cv26[36] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'P', 'o', 'i',
    'n', 't', 'T', 'r', 'a', 'c', 'k', 'e', 'r', ':', 'i', 'n', 'c', 'o', 'r',
    'r', 'e', 'c', 't', 'N', 'u', 'm', 'c', 'o', 'l', 's' };

  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  static char_T c1_b_u[65] = { 'E', 'x', 'p', 'e', 'c', 't', 'e', 'd', ' ', 'P',
    'O', 'I', 'N', 'T', 'S', ' ', 't', 'o', ' ', 'b', 'e', ' ', 'a', 'n', ' ',
    'a', 'r', 'r', 'a', 'y', ' ', 'w', 'i', 't', 'h', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', 'o', 'f', ' ', 'c', 'o', 'l', 'u', 'm', 'n', 's', ' ', 'e',
    'q', 'u', 'a', 'l', ' ', 't', 'o', ' ', '2', '.' };

  const mxArray *c1_h_y = NULL;
  static char_T c1_cv27[31] = { 'E', 'x', 'p', 'e', 'c', 't', 'e', 'd', ' ', 'P',
    'O', 'I', 'N', 'T', 'S', ' ', 't', 'o', ' ', 'b', 'e', ' ', 'n', 'o', 'n',
    'e', 'm', 'p', 't', 'y', '.' };

  boolean_T exitg1;
  c1_p = true;
  c1_d5 = (real_T)(c1_points_size[0] * c1_points_size[1]);
  c1_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c1_k <= (int32_T)c1_d5 - 1)) {
    if (!(c1_points_data[c1_k] <= 0.0F)) {
      c1_k++;
    } else {
      c1_p = false;
      exitg1 = true;
    }
  }

  c1_b10 = c1_p;
  if (c1_b10) {
  } else {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv22, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv23, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c1_y, 14,
                      c1_b_y);
  }

  c1_b_points_size[0] = c1_points_size[0];
  c1_b_points_size[1] = c1_points_size[1];
  c1_points = c1_b_points_size[0];
  c1_b_points = c1_b_points_size[1];
  c1_loop_ub = c1_points_size[0] * c1_points_size[1] - 1;
  for (c1_i182 = 0; c1_i182 <= c1_loop_ub; c1_i182++) {
    c1_b_points_data[c1_i182] = c1_points_data[c1_i182];
  }

  c1_b11 = c1_all(chartInstance, c1_b_points_data, c1_b_points_size);
  if (c1_b11) {
  } else {
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv24, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_cv25, 10, 0U, 1U, 0U, 2, 1, 29),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c1_c_y,
                      14, c1_d_y);
  }

  if ((real_T)c1_points_size[1] == 2.0) {
  } else {
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_cv26, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 65),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c1_e_y,
                      14, c1_f_y);
  }

  if (!(c1_points_size[0] == 0)) {
  } else {
    c1_g_y = NULL;
    sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_cv3, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c1_h_y = NULL;
    sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_cv27, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c1_g_y,
                      14, c1_h_y);
  }
}

static boolean_T c1_all(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  real32_T c1_a_data[], int32_T c1_a_size[2])
{
  boolean_T c1_p;
  real_T c1_d6;
  int32_T c1_k;
  boolean_T exitg1;
  (void)chartInstance;
  c1_p = true;
  c1_d6 = (real_T)(c1_a_size[0] * c1_a_size[1]);
  c1_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c1_k <= (int32_T)c1_d6 - 1)) {
    if ((!muSingleScalarIsInf(c1_a_data[c1_k])) && (!muSingleScalarIsNaN
         (c1_a_data[c1_k]))) {
      c1_k++;
    } else {
      c1_p = false;
      exitg1 = true;
    }
  }

  return c1_p;
}

static void c1_SystemCore_step(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_vision_PointTracker *c1_obj, c1_emxArray_real_T
  *c1_varargin_1)
{
  const mxArray *c1_y = NULL;
  const mxArray *c1_b_y = NULL;
  static char_T c1_cv28[4] = { 's', 't', 'e', 'p' };

  c1_emxArray_real_T *c1_b_varargin_1;
  const mxArray *c1_c_y = NULL;
  int32_T c1_i183;
  const mxArray *c1_d_y = NULL;
  int32_T c1_i184;
  static char_T c1_cv29[5] = { 's', 'e', 't', 'u', 'p' };

  int32_T c1_c_varargin_1;
  int32_T c1_i185;
  int32_T c1_i186;
  int32_T c1_d_varargin_1;
  int32_T c1_loop_ub;
  int32_T c1_i187;
  c1_cell_wrap_2 c1_varSizes[1];
  real_T c1_d7;
  const mxArray *c1_e_y = NULL;
  boolean_T c1_anyInputSizeChanged;
  uint32_T c1_u2;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  const mxArray *c1_h_y = NULL;
  c1_emxArray_uint8_T *c1_Iu8;
  const mxArray *c1_i_y = NULL;
  int32_T c1_i188;
  const mxArray *c1_j_y = NULL;
  int32_T c1_i189;
  boolean_T c1_k_y;
  boolean_T c1_x[2];
  int32_T c1_k;
  boolean_T c1_b12;
  const mxArray *c1_l_y = NULL;
  c1_emxArray_real_T *c1_scores;
  c1_emxArray_boolean_T *c1_pointValidity;
  c1_emxArray_real32_T *c1_pointsTmp;
  c1_emxArray_uint8_T *c1_Iu8_grayT;
  void * c1_ptrObj;
  real_T c1_num_points;
  real_T c1_d8;
  int32_T c1_i190;
  int32_T c1_numPoints;
  int32_T c1_i191;
  int32_T c1_i192;
  int32_T c1_i193;
  int32_T c1_i194;
  int32_T c1_b_loop_ub;
  int32_T c1_i195;
  c1_emxArray_real32_T *c1_b_pointsTmp;
  int32_T c1_c_loop_ub;
  int32_T c1_i196;
  int32_T c1_i197;
  int32_T c1_c_pointsTmp;
  int32_T c1_d_pointsTmp;
  int32_T c1_d_loop_ub;
  int32_T c1_i198;
  c1_emxArray_boolean_T *c1_badPoints;
  int32_T c1_i;
  c1_emxArray_real_T *c1_b_obj;
  boolean_T exitg1;
  if (c1_obj->isInitialized != 2) {
  } else {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv0, 10, 0U, 1U, 0U, 2, 1, 45),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv28, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c1_y, 14, c1_b_y));
  }

  if (c1_obj->isInitialized != 1) {
    if (c1_obj->isInitialized == 0) {
    } else {
      c1_c_y = NULL;
      sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv5, 10, 0U, 1U, 0U, 2, 1, 51),
                    false);
      c1_d_y = NULL;
      sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_cv29, 10, 0U, 1U, 0U, 2, 1, 5),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 2U, 14, c1_c_y, 14, c1_d_y));
    }

    c1_obj->isInitialized = 1;
    for (c1_i184 = 0; c1_i184 < 2; c1_i184++) {
      c1_i186 = c1_varargin_1->size[c1_i184];
      if (c1_i186 < 0) {
        c1_i186 = 0;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      }

      c1_varSizes[0].f1[c1_i184] = (uint32_T)c1_i186;
    }

    for (c1_i185 = 0; c1_i185 < 6; c1_i185++) {
      c1_d7 = muDoubleScalarRound(1.0);
      if (c1_d7 < 4.294967296E+9) {
        if (c1_d7 >= 0.0) {
          c1_u2 = (uint32_T)c1_d7;
        } else {
          c1_u2 = 0U;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
        }
      } else if (c1_d7 >= 4.294967296E+9) {
        c1_u2 = MAX_uint32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      } else {
        c1_u2 = 0U;
      }

      c1_varSizes[0].f1[c1_i185 + 2] = c1_u2;
    }

    c1_obj->inputVarSize[0] = c1_varSizes[0];
    if (!((c1_varargin_1->size[0] == 0) || (c1_varargin_1->size[1] == 0))) {
    } else {
      c1_e_y = NULL;
      sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_cv3, 10, 0U, 1U, 0U, 2, 1, 36),
                    false);
      c1_f_y = NULL;
      sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_cv4, 10, 0U, 1U, 0U, 2, 1, 26),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c1_e_y,
                        14, c1_f_y);
    }
  }

  c1_emxInit_real_T(chartInstance, &c1_b_varargin_1, 2, &c1_yb_emlrtRTEI);
  c1_i183 = c1_b_varargin_1->size[0] * c1_b_varargin_1->size[1];
  c1_b_varargin_1->size[0] = c1_varargin_1->size[0];
  c1_b_varargin_1->size[1] = c1_varargin_1->size[1];
  c1_emxEnsureCapacity_real_T(chartInstance, c1_b_varargin_1, c1_i183,
    &c1_yb_emlrtRTEI);
  c1_c_varargin_1 = c1_b_varargin_1->size[0];
  c1_d_varargin_1 = c1_b_varargin_1->size[1];
  c1_loop_ub = c1_varargin_1->size[0] * c1_varargin_1->size[1] - 1;
  for (c1_i187 = 0; c1_i187 <= c1_loop_ub; c1_i187++) {
    c1_b_varargin_1->data[c1_i187] = c1_varargin_1->data[c1_i187];
  }

  c1_anyInputSizeChanged = c1_SystemCore_detectInputSizeChange(chartInstance,
    c1_obj, c1_b_varargin_1);
  c1_emxFree_real_T(chartInstance, &c1_b_varargin_1);
  if (c1_anyInputSizeChanged && ((c1_varargin_1->size[0] == 0) ||
       (c1_varargin_1->size[1] == 0))) {
    c1_g_y = NULL;
    sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_cv3, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c1_i_y = NULL;
    sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_cv4, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c1_g_y,
                      14, c1_i_y);
  }

  if (!(0.0 != c1_obj->FrameClassID)) {
  } else {
    c1_h_y = NULL;
    sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_cv7, 10, 0U, 1U, 0U, 2, 1, 55),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_h_y));
  }

  c1_emxInit_uint8_T(chartInstance, &c1_Iu8, 2, &c1_ac_emlrtRTEI);
  c1_i188 = c1_Iu8->size[0] * c1_Iu8->size[1];
  c1_Iu8->size[0] = c1_varargin_1->size[0];
  c1_Iu8->size[1] = c1_varargin_1->size[1];
  c1_emxEnsureCapacity_uint8_T(chartInstance, c1_Iu8, c1_i188, &c1_ac_emlrtRTEI);
  grayto8_real64(&c1_varargin_1->data[0], &c1_Iu8->data[0], (real_T)
                 (c1_varargin_1->size[0] * c1_varargin_1->size[1]));
  if (!c1_obj->IsRGB) {
  } else {
    c1_j_y = NULL;
    sf_mex_assign(&c1_j_y, sf_mex_create("y", c1_cv8, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_j_y));
  }

  for (c1_i189 = 0; c1_i189 < 2; c1_i189++) {
    c1_x[c1_i189] = ((real_T)c1_Iu8->size[c1_i189] != c1_obj->FrameSize[c1_i189]);
  }

  c1_k_y = false;
  c1_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c1_k < 2)) {
    c1_b12 = !c1_x[c1_k];
    if (!c1_b12) {
      c1_k_y = true;
      exitg1 = true;
    } else {
      c1_k++;
    }
  }

  if (!c1_k_y) {
  } else {
    c1_l_y = NULL;
    sf_mex_assign(&c1_l_y, sf_mex_create("y", c1_cv9, 10, 0U, 1U, 0U, 2, 1, 54),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_l_y));
  }

  c1_emxInit_real_T1(chartInstance, &c1_scores, 1, &c1_fc_emlrtRTEI);
  c1_emxInit_boolean_T(chartInstance, &c1_pointValidity, 1, &c1_gc_emlrtRTEI);
  c1_emxInit_real32_T(chartInstance, &c1_pointsTmp, 2, &c1_fc_emlrtRTEI);
  c1_emxInit_uint8_T(chartInstance, &c1_Iu8_grayT, 2, &c1_cc_emlrtRTEI);
  c1_ptrObj = c1_obj->pTracker;
  c1_num_points = c1_obj->NumPoints;
  c1_d8 = muDoubleScalarRound(c1_num_points);
  if (c1_d8 < 2.147483648E+9) {
    if (c1_d8 >= -2.147483648E+9) {
      c1_i190 = (int32_T)c1_d8;
    } else {
      c1_i190 = MIN_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
    }
  } else if (c1_d8 >= 2.147483648E+9) {
    c1_i190 = MAX_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else {
    c1_i190 = 0;
  }

  c1_numPoints = c1_i190;
  _SFD_NON_NEGATIVE_CHECK("", (real_T)c1_numPoints);
  c1_i191 = c1_pointsTmp->size[0] * c1_pointsTmp->size[1];
  c1_pointsTmp->size[0] = c1_numPoints;
  c1_pointsTmp->size[1] = 2;
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_pointsTmp, c1_i191,
    &c1_bc_emlrtRTEI);
  c1_i192 = c1_pointValidity->size[0];
  c1_pointValidity->size[0] = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)
    c1_numPoints);
  c1_emxEnsureCapacity_boolean_T(chartInstance, c1_pointValidity, c1_i192,
    &c1_bc_emlrtRTEI);
  c1_i193 = c1_scores->size[0];
  c1_scores->size[0] = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c1_numPoints);
  c1_emxEnsureCapacity_real_T1(chartInstance, c1_scores, c1_i193,
    &c1_bc_emlrtRTEI);
  c1_i194 = c1_Iu8_grayT->size[0] * c1_Iu8_grayT->size[1];
  c1_Iu8_grayT->size[0] = c1_Iu8->size[1];
  c1_Iu8_grayT->size[1] = c1_Iu8->size[0];
  c1_emxEnsureCapacity_uint8_T(chartInstance, c1_Iu8_grayT, c1_i194,
    &c1_cc_emlrtRTEI);
  c1_b_loop_ub = c1_Iu8->size[0] - 1;
  for (c1_i195 = 0; c1_i195 <= c1_b_loop_ub; c1_i195++) {
    c1_c_loop_ub = c1_Iu8->size[1] - 1;
    for (c1_i196 = 0; c1_i196 <= c1_c_loop_ub; c1_i196++) {
      c1_Iu8_grayT->data[c1_i196 + c1_Iu8_grayT->size[0] * c1_i195] =
        c1_Iu8->data[c1_i195 + c1_Iu8->size[0] * c1_i196];
    }
  }

  c1_emxInit_real32_T(chartInstance, &c1_b_pointsTmp, 2, &c1_dc_emlrtRTEI);
  pointTracker_step(c1_ptrObj, &c1_Iu8_grayT->data[0], c1_Iu8->size[0],
                    c1_Iu8->size[1], &c1_pointsTmp->data[0],
                    &c1_pointValidity->data[0], &c1_scores->data[0]);
  c1_i197 = c1_b_pointsTmp->size[0] * c1_b_pointsTmp->size[1];
  c1_b_pointsTmp->size[0] = c1_pointsTmp->size[0];
  c1_b_pointsTmp->size[1] = c1_pointsTmp->size[1];
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_b_pointsTmp, c1_i197,
    &c1_dc_emlrtRTEI);
  c1_c_pointsTmp = c1_b_pointsTmp->size[0];
  c1_d_pointsTmp = c1_b_pointsTmp->size[1];
  c1_d_loop_ub = c1_pointsTmp->size[0] * c1_pointsTmp->size[1] - 1;
  c1_emxFree_uint8_T(chartInstance, &c1_Iu8_grayT);
  c1_emxFree_uint8_T(chartInstance, &c1_Iu8);
  for (c1_i198 = 0; c1_i198 <= c1_d_loop_ub; c1_i198++) {
    c1_b_pointsTmp->data[c1_i198] = c1_pointsTmp->data[c1_i198];
  }

  c1_emxFree_real32_T(chartInstance, &c1_pointsTmp);
  c1_emxInit_boolean_T(chartInstance, &c1_badPoints, 1, &c1_ec_emlrtRTEI);
  c1_PointTracker_pointsOutsideImage(chartInstance, c1_obj, c1_b_pointsTmp,
    c1_badPoints);
  c1_i = 0;
  c1_emxFree_real32_T(chartInstance, &c1_b_pointsTmp);
  while (c1_i <= c1_badPoints->size[0] - 1) {
    if (c1_badPoints->data[c1_i]) {
      c1_pointValidity->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c1_i + 1, 1, c1_pointValidity->size[0]) - 1] = false;
    }

    c1_i++;
  }

  c1_emxFree_boolean_T(chartInstance, &c1_badPoints);
  c1_emxInit_real_T1(chartInstance, &c1_b_obj, 1, &c1_fc_emlrtRTEI);
  c1_PointTracker_normalizeScores(chartInstance, c1_obj, c1_scores,
    c1_pointValidity, c1_b_obj);
  c1_emxFree_real_T(chartInstance, &c1_b_obj);
  c1_emxFree_boolean_T(chartInstance, &c1_pointValidity);
  c1_emxFree_real_T(chartInstance, &c1_scores);
}

static boolean_T c1_SystemCore_detectInputSizeChange
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance, c1_vision_PointTracker *
   c1_obj, c1_emxArray_real_T *c1_varargin_1)
{
  boolean_T c1_anyInputSizeChanged;
  int32_T c1_i199;
  int32_T c1_i200;
  int32_T c1_i201;
  int32_T c1_k;
  real_T c1_d9;
  uint32_T c1_inSize[8];
  uint32_T c1_u3;
  int32_T c1_i202;
  boolean_T exitg1;
  (void)chartInstance;
  c1_anyInputSizeChanged = false;
  for (c1_i199 = 0; c1_i199 < 2; c1_i199++) {
    c1_i201 = c1_varargin_1->size[c1_i199];
    if (c1_i201 < 0) {
      c1_i201 = 0;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
    }

    c1_inSize[c1_i199] = (uint32_T)c1_i201;
  }

  for (c1_i200 = 0; c1_i200 < 6; c1_i200++) {
    c1_d9 = muDoubleScalarRound(1.0);
    if (c1_d9 < 4.294967296E+9) {
      if (c1_d9 >= 0.0) {
        c1_u3 = (uint32_T)c1_d9;
      } else {
        c1_u3 = 0U;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      }
    } else if (c1_d9 >= 4.294967296E+9) {
      c1_u3 = MAX_uint32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
    } else {
      c1_u3 = 0U;
    }

    c1_inSize[c1_i200 + 2] = c1_u3;
  }

  c1_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c1_k < 8)) {
    if (c1_obj->inputVarSize[0].f1[c1_k] != c1_inSize[c1_k]) {
      c1_anyInputSizeChanged = true;
      for (c1_i202 = 0; c1_i202 < 8; c1_i202++) {
        c1_obj->inputVarSize[0].f1[c1_i202] = c1_inSize[c1_i202];
      }

      exitg1 = true;
    } else {
      c1_k++;
    }
  }

  return c1_anyInputSizeChanged;
}

static void c1_PointTracker_pointsOutsideImage
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance, c1_vision_PointTracker *
   c1_obj, c1_emxArray_real32_T *c1_points, c1_emxArray_boolean_T *c1_inds)
{
  c1_emxArray_real32_T *c1_x;
  int32_T c1_i203;
  int32_T c1_i204;
  int32_T c1_loop_ub;
  int32_T c1_i205;
  c1_emxArray_real32_T *c1_y;
  int32_T c1_i206;
  int32_T c1_i207;
  int32_T c1_b_loop_ub;
  int32_T c1_i208;
  int32_T c1_i209;
  int32_T c1_c_loop_ub;
  int32_T c1_i210;
  c1_emxArray_boolean_T *c1_r5;
  int32_T c1_i211;
  int32_T c1_d_loop_ub;
  int32_T c1_i212;
  int32_T c1_i213;
  int32_T c1_e_loop_ub;
  int32_T c1_i214;
  real_T c1_b_obj;
  int32_T c1_i215;
  int32_T c1_f_loop_ub;
  int32_T c1_i216;
  int32_T c1_i217;
  int32_T c1_g_loop_ub;
  int32_T c1_i218;
  real_T c1_c_obj;
  int32_T c1_i219;
  int32_T c1_h_loop_ub;
  int32_T c1_i220;
  int32_T c1_i221;
  int32_T c1_i_loop_ub;
  int32_T c1_i222;
  c1_emxInit_real32_T1(chartInstance, &c1_x, 1, &c1_hc_emlrtRTEI);
  c1_i203 = c1_points->size[0];
  c1_i204 = c1_x->size[0];
  c1_x->size[0] = c1_i203;
  c1_emxEnsureCapacity_real32_T1(chartInstance, c1_x, c1_i204, &c1_hc_emlrtRTEI);
  c1_loop_ub = c1_i203 - 1;
  for (c1_i205 = 0; c1_i205 <= c1_loop_ub; c1_i205++) {
    c1_x->data[c1_i205] = c1_points->data[c1_i205];
  }

  c1_emxInit_real32_T1(chartInstance, &c1_y, 1, &c1_ic_emlrtRTEI);
  c1_i206 = c1_points->size[0];
  c1_i207 = c1_y->size[0];
  c1_y->size[0] = c1_i206;
  c1_emxEnsureCapacity_real32_T1(chartInstance, c1_y, c1_i207, &c1_ic_emlrtRTEI);
  c1_b_loop_ub = c1_i206 - 1;
  for (c1_i208 = 0; c1_i208 <= c1_b_loop_ub; c1_i208++) {
    c1_y->data[c1_i208] = c1_points->data[c1_i208 + c1_points->size[0]];
  }

  c1_i209 = c1_inds->size[0];
  c1_inds->size[0] = c1_x->size[0];
  c1_emxEnsureCapacity_boolean_T(chartInstance, c1_inds, c1_i209,
    &c1_jc_emlrtRTEI);
  c1_c_loop_ub = c1_x->size[0] - 1;
  for (c1_i210 = 0; c1_i210 <= c1_c_loop_ub; c1_i210++) {
    c1_inds->data[c1_i210] = (c1_x->data[c1_i210] < 1.0F);
  }

  c1_emxInit_boolean_T(chartInstance, &c1_r5, 1, &c1_pc_emlrtRTEI);
  c1_i211 = c1_r5->size[0];
  c1_r5->size[0] = c1_y->size[0];
  c1_emxEnsureCapacity_boolean_T(chartInstance, c1_r5, c1_i211, &c1_kc_emlrtRTEI);
  c1_d_loop_ub = c1_y->size[0] - 1;
  for (c1_i212 = 0; c1_i212 <= c1_d_loop_ub; c1_i212++) {
    c1_r5->data[c1_i212] = (c1_y->data[c1_i212] < 1.0F);
  }

  _SFD_SIZE_EQ_CHECK_1D(c1_inds->size[0], c1_r5->size[0]);
  c1_i213 = c1_inds->size[0];
  c1_inds->size[0];
  c1_emxEnsureCapacity_boolean_T(chartInstance, c1_inds, c1_i213,
    &c1_lc_emlrtRTEI);
  c1_e_loop_ub = c1_inds->size[0] - 1;
  for (c1_i214 = 0; c1_i214 <= c1_e_loop_ub; c1_i214++) {
    c1_inds->data[c1_i214] = (c1_inds->data[c1_i214] || c1_r5->data[c1_i214]);
  }

  c1_b_obj = c1_obj->FrameSize[1];
  c1_i215 = c1_r5->size[0];
  c1_r5->size[0] = c1_x->size[0];
  c1_emxEnsureCapacity_boolean_T(chartInstance, c1_r5, c1_i215, &c1_mc_emlrtRTEI);
  c1_f_loop_ub = c1_x->size[0] - 1;
  for (c1_i216 = 0; c1_i216 <= c1_f_loop_ub; c1_i216++) {
    c1_r5->data[c1_i216] = ((real_T)c1_x->data[c1_i216] > c1_b_obj);
  }

  c1_emxFree_real32_T(chartInstance, &c1_x);
  _SFD_SIZE_EQ_CHECK_1D(c1_inds->size[0], c1_r5->size[0]);
  c1_i217 = c1_inds->size[0];
  c1_inds->size[0];
  c1_emxEnsureCapacity_boolean_T(chartInstance, c1_inds, c1_i217,
    &c1_lc_emlrtRTEI);
  c1_g_loop_ub = c1_inds->size[0] - 1;
  for (c1_i218 = 0; c1_i218 <= c1_g_loop_ub; c1_i218++) {
    c1_inds->data[c1_i218] = (c1_inds->data[c1_i218] || c1_r5->data[c1_i218]);
  }

  c1_c_obj = c1_obj->FrameSize[0];
  c1_i219 = c1_r5->size[0];
  c1_r5->size[0] = c1_y->size[0];
  c1_emxEnsureCapacity_boolean_T(chartInstance, c1_r5, c1_i219, &c1_nc_emlrtRTEI);
  c1_h_loop_ub = c1_y->size[0] - 1;
  for (c1_i220 = 0; c1_i220 <= c1_h_loop_ub; c1_i220++) {
    c1_r5->data[c1_i220] = ((real_T)c1_y->data[c1_i220] > c1_c_obj);
  }

  c1_emxFree_real32_T(chartInstance, &c1_y);
  _SFD_SIZE_EQ_CHECK_1D(c1_inds->size[0], c1_r5->size[0]);
  c1_i221 = c1_inds->size[0];
  c1_inds->size[0];
  c1_emxEnsureCapacity_boolean_T(chartInstance, c1_inds, c1_i221,
    &c1_oc_emlrtRTEI);
  c1_i_loop_ub = c1_inds->size[0] - 1;
  for (c1_i222 = 0; c1_i222 <= c1_i_loop_ub; c1_i222++) {
    c1_inds->data[c1_i222] = (c1_inds->data[c1_i222] || c1_r5->data[c1_i222]);
  }

  c1_emxFree_boolean_T(chartInstance, &c1_r5);
}

static void c1_PointTracker_normalizeScores
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance, c1_vision_PointTracker *
   c1_obj, c1_emxArray_real_T *c1_scores, c1_emxArray_boolean_T *c1_validity,
   c1_emxArray_real_T *c1_b_scores)
{
  int32_T c1_i223;
  int32_T c1_loop_ub;
  int32_T c1_i224;
  c1_emxArray_boolean_T *c1_b_validity;
  int32_T c1_i225;
  int32_T c1_b_loop_ub;
  int32_T c1_i226;
  c1_i223 = c1_b_scores->size[0];
  c1_b_scores->size[0] = c1_scores->size[0];
  c1_emxEnsureCapacity_real_T1(chartInstance, c1_b_scores, c1_i223,
    &c1_qc_emlrtRTEI);
  c1_loop_ub = c1_scores->size[0] - 1;
  for (c1_i224 = 0; c1_i224 <= c1_loop_ub; c1_i224++) {
    c1_b_scores->data[c1_i224] = c1_scores->data[c1_i224];
  }

  c1_emxInit_boolean_T(chartInstance, &c1_b_validity, 1, &c1_qc_emlrtRTEI);
  c1_i225 = c1_b_validity->size[0];
  c1_b_validity->size[0] = c1_validity->size[0];
  c1_emxEnsureCapacity_boolean_T(chartInstance, c1_b_validity, c1_i225,
    &c1_qc_emlrtRTEI);
  c1_b_loop_ub = c1_validity->size[0] - 1;
  for (c1_i226 = 0; c1_i226 <= c1_b_loop_ub; c1_i226++) {
    c1_b_validity->data[c1_i226] = c1_validity->data[c1_i226];
  }

  c1_b_PointTracker_normalizeScores(chartInstance, c1_obj, c1_b_scores,
    c1_b_validity);
  c1_emxFree_boolean_T(chartInstance, &c1_b_validity);
}

static void c1_b_error(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  const mxArray *c1_y = NULL;
  const mxArray *c1_b_y = NULL;
  static char_T c1_cv30[4] = { 's', 'q', 'r', 't' };

  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv6, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv30, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c1_y, 14, c1_b_y));
}

static void c1_bbox2points(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  real_T c1_bbox_data[], int32_T c1_bbox_size[2], real_T c1_points[8])
{
  static real_T c1_dv1[2] = { 0.0, 4.0 };

  const mxArray *c1_y = NULL;
  static char_T c1_cv31[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'b', 'b', 'o',
    'x', '2', 'p', 'o', 'i', 'n', 't', 's', ':', 'e', 'x', 'p', 'e', 'c', 't',
    'e', 'd', 'N', 'o', 'n', 'e', 'm', 'p', 't', 'y' };

  boolean_T c1_p;
  const mxArray *c1_b_y = NULL;
  int32_T c1_k;
  static char_T c1_cv32[29] = { 'E', 'x', 'p', 'e', 'c', 't', 'e', 'd', ' ', 'b',
    'b', 'o', 'x', ' ', 't', 'o', ' ', 'b', 'e', ' ', 'n', 'o', 'n', 'e', 'm',
    'p', 't', 'y', '.' };

  boolean_T c1_b13;
  const mxArray *c1_c_y = NULL;
  static char_T c1_cv33[33] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'b', 'b', 'o',
    'x', '2', 'p', 'o', 'i', 'n', 't', 's', ':', 'e', 'x', 'p', 'e', 'c', 't',
    'e', 'd', 'F', 'i', 'n', 'i', 't', 'e' };

  boolean_T c1_b_p;
  const mxArray *c1_d_y = NULL;
  int32_T c1_b_k;
  static char_T c1_cv34[27] = { 'E', 'x', 'p', 'e', 'c', 't', 'e', 'd', ' ', 'b',
    'b', 'o', 'x', ' ', 't', 'o', ' ', 'b', 'e', ' ', 'f', 'i', 'n', 'i', 't',
    'e', '.' };

  real_T c1_szk;
  const mxArray *c1_e_y = NULL;
  static char_T c1_cv35[32] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'b', 'b', 'o',
    'x', '2', 'p', 'o', 'i', 'n', 't', 's', ':', 'i', 'n', 'c', 'o', 'r', 'r',
    'e', 'c', 't', 'S', 'i', 'z', 'e' };

  int32_T c1_bbox;
  const mxArray *c1_f_y = NULL;
  int32_T c1_i227;
  static char_T c1_b_u[37] = { 'b', 'b', 'o', 'x', ' ', 'd', 'o', 'e', 's', ' ',
    'n', 'o', 't', ' ', 'h', 'a', 'v', 'e', ' ', 't', 'h', 'e', ' ', 'e', 'x',
    'p', 'e', 'c', 't', 'e', 'd', ' ', 's', 'i', 'z', 'e', '.' };

  boolean_T c1_c_p;
  int32_T c1_c_k;
  static int32_T c1_iv0[2] = { 2, 3 };

  const mxArray *c1_g_y = NULL;
  static char_T c1_cv36[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'b', 'b', 'o',
    'x', '2', 'p', 'o', 'i', 'n', 't', 's', ':', 'n', 'o', 't', 'G', 'r', 'e',
    'a', 't', 'e', 'r', 'E', 'q', 'u', 'a', 'l' };

  const mxArray *c1_h_y = NULL;
  static char_T c1_c_u[66] = { 'E', 'x', 'p', 'e', 'c', 't', 'e', 'd', ' ', 'b',
    'b', 'o', 'x', '(', ':', ',', '[', '3', ',', '4', ']', ')', ' ', 't', 'o',
    ' ', 'b', 'e', ' ', 'a', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'w', 'i',
    't', 'h', ' ', 'a', 'l', 'l', ' ', 'o', 'f', ' ', 't', 'h', 'e', ' ', 'v',
    'a', 'l', 'u', 'e', 's', ' ', '>', '=', ' ', '0', '.' };

  boolean_T exitg1;
  c1_dv1[0U] = rtNaN;
  if (!(c1_bbox_size[1] == 0)) {
  } else {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv31, 10, 0U, 1U, 0U, 2, 1, 35),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv32, 10, 0U, 1U, 0U, 2, 1, 29),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c1_y, 14,
                      c1_b_y);
  }

  c1_p = true;
  c1_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c1_k <= c1_bbox_size[1] - 1)) {
    if ((!muDoubleScalarIsInf(c1_bbox_data[c1_k])) && (!muDoubleScalarIsNaN
         (c1_bbox_data[c1_k]))) {
      c1_k++;
    } else {
      c1_p = false;
      exitg1 = true;
    }
  }

  c1_b13 = c1_p;
  if (c1_b13) {
  } else {
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv33, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_cv34, 10, 0U, 1U, 0U, 2, 1, 27),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c1_c_y,
                      14, c1_d_y);
  }

  c1_b_p = true;
  c1_b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c1_b_k < 2)) {
    c1_szk = c1_dv1[c1_b_k];
    if (muDoubleScalarIsNaN(c1_szk) || (c1_szk == (real_T)c1_bbox_size[c1_b_k]))
    {
      c1_b_k++;
    } else {
      c1_b_p = false;
      exitg1 = true;
    }
  }

  if (c1_b_p) {
  } else {
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_cv35, 10, 0U, 1U, 0U, 2, 1, 32),
                  false);
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 37),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c1_e_y,
                      14, c1_f_y);
  }

  c1_bbox = c1_bbox_size[1];
  for (c1_i227 = 0; c1_i227 < 2; c1_i227++) {
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)(3.0 + (real_T)c1_i227),
      1, c1_bbox);
  }

  c1_c_p = true;
  c1_c_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c1_c_k < 2)) {
    if (c1_bbox_data[c1_bbox_size[0] * c1_iv0[c1_c_k]] >= 0.0) {
      c1_c_k++;
    } else {
      c1_c_p = false;
      exitg1 = true;
    }
  }

  if (c1_c_p) {
  } else {
    c1_g_y = NULL;
    sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_cv36, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    c1_h_y = NULL;
    sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_c_u, 10, 0U, 1U, 0U, 2, 1, 66),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c1_g_y,
                      14, c1_h_y);
  }

  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c1_bbox_size[1]);
  c1_points[0] = c1_bbox_data[0];
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 2, 1, c1_bbox_size[1]);
  c1_points[4] = c1_bbox_data[c1_bbox_size[0]];
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c1_bbox_size[1]);
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 3, 1, c1_bbox_size[1]);
  c1_points[1] = c1_bbox_data[0] + c1_bbox_data[c1_bbox_size[0] << 1];
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 2, 1, c1_bbox_size[1]);
  c1_points[5] = c1_bbox_data[c1_bbox_size[0]];
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c1_bbox_size[1]);
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 3, 1, c1_bbox_size[1]);
  c1_points[2] = c1_bbox_data[0] + c1_bbox_data[c1_bbox_size[0] << 1];
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 2, 1, c1_bbox_size[1]);
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 4, 1, c1_bbox_size[1]);
  c1_points[6] = c1_bbox_data[c1_bbox_size[0]] + c1_bbox_data[c1_bbox_size[0] *
    3];
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c1_bbox_size[1]);
  c1_points[3] = c1_bbox_data[0];
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 2, 1, c1_bbox_size[1]);
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 4, 1, c1_bbox_size[1]);
  c1_points[7] = c1_bbox_data[c1_bbox_size[0]] + c1_bbox_data[c1_bbox_size[0] *
    3];
}

static void c1_b_SystemCore_step(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_vision_PointTracker *c1_obj, c1_emxArray_real_T
  *c1_varargin_1, c1_emxArray_real32_T *c1_varargout_1, c1_emxArray_boolean_T
  *c1_varargout_2)
{
  const mxArray *c1_y = NULL;
  const mxArray *c1_b_y = NULL;
  static char_T c1_cv37[4] = { 's', 't', 'e', 'p' };

  c1_emxArray_real_T *c1_b_varargin_1;
  const mxArray *c1_c_y = NULL;
  int32_T c1_i228;
  const mxArray *c1_d_y = NULL;
  int32_T c1_i229;
  static char_T c1_cv38[5] = { 's', 'e', 't', 'u', 'p' };

  int32_T c1_c_varargin_1;
  int32_T c1_i230;
  int32_T c1_i231;
  int32_T c1_d_varargin_1;
  int32_T c1_loop_ub;
  int32_T c1_i232;
  c1_cell_wrap_2 c1_varSizes[1];
  real_T c1_d10;
  const mxArray *c1_e_y = NULL;
  boolean_T c1_anyInputSizeChanged;
  uint32_T c1_u4;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  const mxArray *c1_h_y = NULL;
  c1_emxArray_uint8_T *c1_Iu8;
  const mxArray *c1_i_y = NULL;
  int32_T c1_i233;
  const mxArray *c1_j_y = NULL;
  int32_T c1_i234;
  boolean_T c1_k_y;
  boolean_T c1_x[2];
  int32_T c1_k;
  boolean_T c1_b14;
  const mxArray *c1_l_y = NULL;
  c1_emxArray_real_T *c1_scores;
  c1_emxArray_real32_T *c1_pointsTmp;
  c1_emxArray_uint8_T *c1_Iu8_grayT;
  void * c1_ptrObj;
  real_T c1_num_points;
  real_T c1_d11;
  int32_T c1_i235;
  int32_T c1_numPoints;
  int32_T c1_i236;
  int32_T c1_i237;
  int32_T c1_i238;
  int32_T c1_i239;
  int32_T c1_b_loop_ub;
  int32_T c1_i240;
  c1_emxArray_real32_T *c1_b_pointsTmp;
  int32_T c1_c_loop_ub;
  int32_T c1_i241;
  int32_T c1_i242;
  int32_T c1_c_pointsTmp;
  int32_T c1_d_pointsTmp;
  int32_T c1_d_loop_ub;
  int32_T c1_i243;
  c1_emxArray_boolean_T *c1_badPoints;
  int32_T c1_i;
  c1_emxArray_boolean_T *c1_b_varargout_2;
  int32_T c1_i244;
  int32_T c1_e_loop_ub;
  int32_T c1_i245;
  c1_emxArray_real_T *c1_b_obj;
  int32_T c1_i246;
  int32_T c1_b_varargout_1;
  int32_T c1_c_varargout_1;
  int32_T c1_f_loop_ub;
  int32_T c1_i247;
  boolean_T exitg1;
  if (c1_obj->isInitialized != 2) {
  } else {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv0, 10, 0U, 1U, 0U, 2, 1, 45),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv37, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c1_y, 14, c1_b_y));
  }

  if (c1_obj->isInitialized != 1) {
    if (c1_obj->isInitialized == 0) {
    } else {
      c1_c_y = NULL;
      sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv5, 10, 0U, 1U, 0U, 2, 1, 51),
                    false);
      c1_d_y = NULL;
      sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_cv38, 10, 0U, 1U, 0U, 2, 1, 5),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 2U, 14, c1_c_y, 14, c1_d_y));
    }

    c1_obj->isInitialized = 1;
    for (c1_i229 = 0; c1_i229 < 2; c1_i229++) {
      c1_i231 = c1_varargin_1->size[c1_i229];
      if (c1_i231 < 0) {
        c1_i231 = 0;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      }

      c1_varSizes[0].f1[c1_i229] = (uint32_T)c1_i231;
    }

    for (c1_i230 = 0; c1_i230 < 6; c1_i230++) {
      c1_d10 = muDoubleScalarRound(1.0);
      if (c1_d10 < 4.294967296E+9) {
        if (c1_d10 >= 0.0) {
          c1_u4 = (uint32_T)c1_d10;
        } else {
          c1_u4 = 0U;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
        }
      } else if (c1_d10 >= 4.294967296E+9) {
        c1_u4 = MAX_uint32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      } else {
        c1_u4 = 0U;
      }

      c1_varSizes[0].f1[c1_i230 + 2] = c1_u4;
    }

    c1_obj->inputVarSize[0] = c1_varSizes[0];
    if (!((c1_varargin_1->size[0] == 0) || (c1_varargin_1->size[1] == 0))) {
    } else {
      c1_e_y = NULL;
      sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_cv3, 10, 0U, 1U, 0U, 2, 1, 36),
                    false);
      c1_f_y = NULL;
      sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_cv4, 10, 0U, 1U, 0U, 2, 1, 26),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c1_e_y,
                        14, c1_f_y);
    }
  }

  c1_emxInit_real_T(chartInstance, &c1_b_varargin_1, 2, &c1_yb_emlrtRTEI);
  c1_i228 = c1_b_varargin_1->size[0] * c1_b_varargin_1->size[1];
  c1_b_varargin_1->size[0] = c1_varargin_1->size[0];
  c1_b_varargin_1->size[1] = c1_varargin_1->size[1];
  c1_emxEnsureCapacity_real_T(chartInstance, c1_b_varargin_1, c1_i228,
    &c1_yb_emlrtRTEI);
  c1_c_varargin_1 = c1_b_varargin_1->size[0];
  c1_d_varargin_1 = c1_b_varargin_1->size[1];
  c1_loop_ub = c1_varargin_1->size[0] * c1_varargin_1->size[1] - 1;
  for (c1_i232 = 0; c1_i232 <= c1_loop_ub; c1_i232++) {
    c1_b_varargin_1->data[c1_i232] = c1_varargin_1->data[c1_i232];
  }

  c1_anyInputSizeChanged = c1_SystemCore_detectInputSizeChange(chartInstance,
    c1_obj, c1_b_varargin_1);
  c1_emxFree_real_T(chartInstance, &c1_b_varargin_1);
  if (c1_anyInputSizeChanged && ((c1_varargin_1->size[0] == 0) ||
       (c1_varargin_1->size[1] == 0))) {
    c1_g_y = NULL;
    sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_cv3, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c1_i_y = NULL;
    sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_cv4, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c1_g_y,
                      14, c1_i_y);
  }

  if (!(0.0 != c1_obj->FrameClassID)) {
  } else {
    c1_h_y = NULL;
    sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_cv7, 10, 0U, 1U, 0U, 2, 1, 55),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_h_y));
  }

  c1_emxInit_uint8_T(chartInstance, &c1_Iu8, 2, &c1_ac_emlrtRTEI);
  c1_i233 = c1_Iu8->size[0] * c1_Iu8->size[1];
  c1_Iu8->size[0] = c1_varargin_1->size[0];
  c1_Iu8->size[1] = c1_varargin_1->size[1];
  c1_emxEnsureCapacity_uint8_T(chartInstance, c1_Iu8, c1_i233, &c1_ac_emlrtRTEI);
  grayto8_real64(&c1_varargin_1->data[0], &c1_Iu8->data[0], (real_T)
                 (c1_varargin_1->size[0] * c1_varargin_1->size[1]));
  if (!c1_obj->IsRGB) {
  } else {
    c1_j_y = NULL;
    sf_mex_assign(&c1_j_y, sf_mex_create("y", c1_cv8, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_j_y));
  }

  for (c1_i234 = 0; c1_i234 < 2; c1_i234++) {
    c1_x[c1_i234] = ((real_T)c1_Iu8->size[c1_i234] != c1_obj->FrameSize[c1_i234]);
  }

  c1_k_y = false;
  c1_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c1_k < 2)) {
    c1_b14 = !c1_x[c1_k];
    if (!c1_b14) {
      c1_k_y = true;
      exitg1 = true;
    } else {
      c1_k++;
    }
  }

  if (!c1_k_y) {
  } else {
    c1_l_y = NULL;
    sf_mex_assign(&c1_l_y, sf_mex_create("y", c1_cv9, 10, 0U, 1U, 0U, 2, 1, 54),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_l_y));
  }

  c1_emxInit_real_T1(chartInstance, &c1_scores, 1, &c1_fc_emlrtRTEI);
  c1_emxInit_real32_T(chartInstance, &c1_pointsTmp, 2, &c1_fc_emlrtRTEI);
  c1_emxInit_uint8_T(chartInstance, &c1_Iu8_grayT, 2, &c1_cc_emlrtRTEI);
  c1_ptrObj = c1_obj->pTracker;
  c1_num_points = c1_obj->NumPoints;
  c1_d11 = muDoubleScalarRound(c1_num_points);
  if (c1_d11 < 2.147483648E+9) {
    if (c1_d11 >= -2.147483648E+9) {
      c1_i235 = (int32_T)c1_d11;
    } else {
      c1_i235 = MIN_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
    }
  } else if (c1_d11 >= 2.147483648E+9) {
    c1_i235 = MAX_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else {
    c1_i235 = 0;
  }

  c1_numPoints = c1_i235;
  _SFD_NON_NEGATIVE_CHECK("", (real_T)c1_numPoints);
  c1_i236 = c1_pointsTmp->size[0] * c1_pointsTmp->size[1];
  c1_pointsTmp->size[0] = c1_numPoints;
  c1_pointsTmp->size[1] = 2;
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_pointsTmp, c1_i236,
    &c1_bc_emlrtRTEI);
  c1_i237 = c1_varargout_2->size[0];
  c1_varargout_2->size[0] = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)
    c1_numPoints);
  c1_emxEnsureCapacity_boolean_T(chartInstance, c1_varargout_2, c1_i237,
    &c1_bc_emlrtRTEI);
  c1_i238 = c1_scores->size[0];
  c1_scores->size[0] = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c1_numPoints);
  c1_emxEnsureCapacity_real_T1(chartInstance, c1_scores, c1_i238,
    &c1_bc_emlrtRTEI);
  c1_i239 = c1_Iu8_grayT->size[0] * c1_Iu8_grayT->size[1];
  c1_Iu8_grayT->size[0] = c1_Iu8->size[1];
  c1_Iu8_grayT->size[1] = c1_Iu8->size[0];
  c1_emxEnsureCapacity_uint8_T(chartInstance, c1_Iu8_grayT, c1_i239,
    &c1_cc_emlrtRTEI);
  c1_b_loop_ub = c1_Iu8->size[0] - 1;
  for (c1_i240 = 0; c1_i240 <= c1_b_loop_ub; c1_i240++) {
    c1_c_loop_ub = c1_Iu8->size[1] - 1;
    for (c1_i241 = 0; c1_i241 <= c1_c_loop_ub; c1_i241++) {
      c1_Iu8_grayT->data[c1_i241 + c1_Iu8_grayT->size[0] * c1_i240] =
        c1_Iu8->data[c1_i240 + c1_Iu8->size[0] * c1_i241];
    }
  }

  c1_emxInit_real32_T(chartInstance, &c1_b_pointsTmp, 2, &c1_dc_emlrtRTEI);
  pointTracker_step(c1_ptrObj, &c1_Iu8_grayT->data[0], c1_Iu8->size[0],
                    c1_Iu8->size[1], &c1_pointsTmp->data[0],
                    &c1_varargout_2->data[0], &c1_scores->data[0]);
  c1_i242 = c1_b_pointsTmp->size[0] * c1_b_pointsTmp->size[1];
  c1_b_pointsTmp->size[0] = c1_pointsTmp->size[0];
  c1_b_pointsTmp->size[1] = c1_pointsTmp->size[1];
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_b_pointsTmp, c1_i242,
    &c1_dc_emlrtRTEI);
  c1_c_pointsTmp = c1_b_pointsTmp->size[0];
  c1_d_pointsTmp = c1_b_pointsTmp->size[1];
  c1_d_loop_ub = c1_pointsTmp->size[0] * c1_pointsTmp->size[1] - 1;
  c1_emxFree_uint8_T(chartInstance, &c1_Iu8_grayT);
  c1_emxFree_uint8_T(chartInstance, &c1_Iu8);
  for (c1_i243 = 0; c1_i243 <= c1_d_loop_ub; c1_i243++) {
    c1_b_pointsTmp->data[c1_i243] = c1_pointsTmp->data[c1_i243];
  }

  c1_emxInit_boolean_T(chartInstance, &c1_badPoints, 1, &c1_ec_emlrtRTEI);
  c1_PointTracker_pointsOutsideImage(chartInstance, c1_obj, c1_b_pointsTmp,
    c1_badPoints);
  c1_i = 0;
  c1_emxFree_real32_T(chartInstance, &c1_b_pointsTmp);
  while (c1_i <= c1_badPoints->size[0] - 1) {
    if (c1_badPoints->data[c1_i]) {
      c1_varargout_2->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, c1_i + 1, 1,
        c1_varargout_2->size[0]) - 1] = false;
    }

    c1_i++;
  }

  c1_emxFree_boolean_T(chartInstance, &c1_badPoints);
  c1_emxInit_boolean_T(chartInstance, &c1_b_varargout_2, 1, &c1_rc_emlrtRTEI);
  c1_i244 = c1_b_varargout_2->size[0];
  c1_b_varargout_2->size[0] = c1_varargout_2->size[0];
  c1_emxEnsureCapacity_boolean_T(chartInstance, c1_b_varargout_2, c1_i244,
    &c1_rc_emlrtRTEI);
  c1_e_loop_ub = c1_varargout_2->size[0] - 1;
  for (c1_i245 = 0; c1_i245 <= c1_e_loop_ub; c1_i245++) {
    c1_b_varargout_2->data[c1_i245] = c1_varargout_2->data[c1_i245];
  }

  c1_emxInit_real_T1(chartInstance, &c1_b_obj, 1, &c1_fc_emlrtRTEI);
  c1_PointTracker_normalizeScores(chartInstance, c1_obj, c1_scores,
    c1_b_varargout_2, c1_b_obj);
  c1_i246 = c1_varargout_1->size[0] * c1_varargout_1->size[1];
  c1_varargout_1->size[0] = c1_pointsTmp->size[0];
  c1_varargout_1->size[1] = c1_pointsTmp->size[1];
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_varargout_1, c1_i246,
    &c1_yb_emlrtRTEI);
  c1_b_varargout_1 = c1_varargout_1->size[0];
  c1_c_varargout_1 = c1_varargout_1->size[1];
  c1_f_loop_ub = c1_pointsTmp->size[0] * c1_pointsTmp->size[1] - 1;
  c1_emxFree_real_T(chartInstance, &c1_b_obj);
  c1_emxFree_boolean_T(chartInstance, &c1_b_varargout_2);
  c1_emxFree_real_T(chartInstance, &c1_scores);
  for (c1_i247 = 0; c1_i247 <= c1_f_loop_ub; c1_i247++) {
    c1_varargout_1->data[c1_i247] = c1_pointsTmp->data[c1_i247];
  }

  c1_emxFree_real32_T(chartInstance, &c1_pointsTmp);
}

static boolean_T c1_size_check(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T *c1_a)
{
  boolean_T c1_p;
  static real_T c1_dv2[2] = { 0.0, 2.0 };

  int32_T c1_k;
  real_T c1_szk;
  boolean_T exitg1;
  (void)chartInstance;
  c1_dv2[0U] = rtNaN;
  c1_p = true;
  c1_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c1_k < 2)) {
    c1_szk = c1_dv2[c1_k];
    if (muDoubleScalarIsNaN(c1_szk) || (c1_szk == (real_T)c1_a->size[c1_k])) {
      c1_k++;
    } else {
      c1_p = false;
      exitg1 = true;
    }
  }

  return c1_p;
}

static void c1_estimateGeometricTransform(SFc1_DetectAndTrackFaceInstanceStruct *
  chartInstance, c1_emxArray_real32_T *c1_matchedPoints1, c1_emxArray_real32_T
  *c1_matchedPoints2, c1_affine2d *c1_tform, c1_emxArray_real32_T
  *c1_inlierPoints1, c1_emxArray_real32_T *c1_inlierPoints2)
{
  c1_emxArray_real32_T *c1_b_matchedPoints1;
  int32_T c1_i248;
  int32_T c1_c_matchedPoints1;
  int32_T c1_d_matchedPoints1;
  int32_T c1_loop_ub;
  int32_T c1_i249;
  const mxArray *c1_y = NULL;
  static char_T c1_cv39[47] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'e', 's', 't',
    'i', 'm', 'a', 't', 'e', 'G', 'e', 'o', 'm', 'e', 't', 'r', 'i', 'c', 'T',
    'r', 'a', 'n', 's', 'f', 'o', 'r', 'm', ':', 'i', 'n', 'c', 'o', 'r', 'r',
    'e', 'c', 't', 'S', 'i', 'z', 'e' };

  const mxArray *c1_b_y = NULL;
  c1_emxArray_real32_T *c1_b_matchedPoints2;
  static char_T c1_b_u[47] = { 'M', 'A', 'T', 'C', 'H', 'E', 'D', 'P', 'O', 'I',
    'N', 'T', 'S', '1', ' ', 'd', 'o', 'e', 's', ' ', 'n', 'o', 't', ' ', 'h',
    'a', 'v', 'e', ' ', 't', 'h', 'e', ' ', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', ' ', 's', 'i', 'z', 'e', '.' };

  int32_T c1_i250;
  int32_T c1_c_matchedPoints2;
  int32_T c1_d_matchedPoints2;
  int32_T c1_b_loop_ub;
  int32_T c1_i251;
  const mxArray *c1_c_y = NULL;
  static char_T c1_cv40[47] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'e', 's', 't',
    'i', 'm', 'a', 't', 'e', 'G', 'e', 'o', 'm', 'e', 't', 'r', 'i', 'c', 'T',
    'r', 'a', 'n', 's', 'f', 'o', 'r', 'm', ':', 'i', 'n', 'c', 'o', 'r', 'r',
    'e', 'c', 't', 'S', 'i', 'z', 'e' };

  const mxArray *c1_d_y = NULL;
  int32_T c1_i252;
  static char_T c1_c_u[47] = { 'M', 'A', 'T', 'C', 'H', 'E', 'D', 'P', 'O', 'I',
    'N', 'T', 'S', '2', ' ', 'd', 'o', 'e', 's', ' ', 'n', 'o', 't', ' ', 'h',
    'a', 'v', 'e', ' ', 't', 'h', 'e', ' ', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', ' ', 's', 'i', 'z', 'e', '.' };

  int32_T c1_i253;
  real_T c1_points1[2];
  boolean_T c1_p;
  real_T c1_points2[2];
  boolean_T c1_b_p;
  int32_T c1_k;
  const mxArray *c1_e_y = NULL;
  static char_T c1_cv41[28] = { 'v', 'i', 's', 'i', 'o', 'n', ':', 'p', 'o', 'i',
    'n', 't', 's', ':', 'n', 'u', 'm', 'P', 't', 's', 'M', 'i', 's', 'm', 'a',
    't', 'c', 'h' };

  int32_T c1_status;
  const mxArray *c1_f_y = NULL;
  c1_svT7UAnr23JjyThWngsAoUB c1_ransacParams;
  static char_T c1_cv42[14] = { 'M', 'A', 'T', 'C', 'H', 'E', 'D', 'P', 'O', 'I',
    'N', 'T', 'S', '1' };

  const mxArray *c1_g_y = NULL;
  static char_T c1_cv43[14] = { 'M', 'A', 'T', 'C', 'H', 'E', 'D', 'P', 'O', 'I',
    'N', 'T', 'S', '2' };

  int32_T c1_b_status;
  int32_T c1_i254;
  int32_T c1_b_k;
  real32_T c1_failedMatrix[9];
  int32_T c1_c_k;
  c1_emxArray_boolean_T *c1_inliers;
  int32_T c1_i255;
  c1_emxArray_real32_T *c1_points;
  real_T c1_ysize[3];
  int32_T c1_i256;
  int32_T c1_b_inliers;
  int32_T c1_c_inliers;
  int32_T c1_c_loop_ub;
  int32_T c1_i257;
  int32_T c1_tmatrix_size[2];
  int32_T c1_j;
  int32_T c1_tmatrix;
  int32_T c1_b_tmatrix;
  boolean_T c1_c_p;
  int32_T c1_i258;
  const mxArray *c1_h_y = NULL;
  real32_T c1_tmatrix_data[9];
  static char_T c1_cv44[39] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'c', 'a', 't', 'e', 'n', 'a', 't', 'e', '_', 'd', 'i', 'm',
    'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  int32_T c1_i259;
  int32_T c1_end;
  int32_T c1_b_j;
  int32_T c1_trueCount;
  int32_T c1_i;
  boolean_T c1_d_p;
  int32_T c1_e_matchedPoints1;
  int32_T c1_b_inlierPoints1;
  c1_emxArray_int32_T *c1_r6;
  int32_T c1_c_inlierPoints1;
  int32_T c1_i260;
  const mxArray *c1_i_y = NULL;
  int32_T c1_i261;
  int32_T c1_iy;
  int32_T c1_b;
  int32_T c1_partialTrueCount;
  boolean_T c1_overflow;
  int32_T c1_b_i;
  int32_T c1_e_matchedPoints2;
  int32_T c1_b_inlierPoints2;
  int32_T c1_c_j;
  int32_T c1_c_inlierPoints2;
  int32_T c1_f_matchedPoints1;
  int32_T c1_i262;
  int32_T c1_i263;
  int32_T c1_b_b;
  int32_T c1_c_tmatrix;
  boolean_T c1_b_overflow;
  int32_T c1_d_tmatrix;
  int32_T c1_i264;
  int32_T c1_d_loop_ub;
  int32_T c1_d_j;
  int32_T c1_i265;
  c1_emxArray_boolean_T *c1_d_inliers;
  int32_T c1_e_loop_ub;
  boolean_T c1_isFound;
  const mxArray *c1_j_y = NULL;
  int32_T c1_b_end;
  int32_T c1_i266;
  int32_T c1_i267;
  static char_T c1_cv45[33] = { 'v', 'i', 's', 'i', 'o', 'n', ':', 'p', 'o', 'i',
    'n', 't', 's', ':', 'n', 'o', 't', 'E', 'n', 'o', 'u', 'g', 'h', 'M', 'a',
    't', 'c', 'h', 'e', 'd', 'P', 't', 's' };

  int32_T c1_b_trueCount;
  const mxArray *c1_k_y = NULL;
  const mxArray *c1_l_y = NULL;
  int32_T c1_c_i;
  static char_T c1_cv46[14] = { 'm', 'a', 't', 'c', 'h', 'e', 'd', 'P', 'o', 'i',
    'n', 't', 's', '1' };

  static char_T c1_cv47[36] = { 'v', 'i', 's', 'i', 'o', 'n', ':', 'p', 'o', 'i',
    'n', 't', 's', ':', 'n', 'o', 't', 'E', 'n', 'o', 'u', 'g', 'h', 'I', 'n',
    'l', 'i', 'e', 'r', 'M', 'a', 't', 'c', 'h', 'e', 's' };

  int32_T c1_i268;
  const mxArray *c1_m_y = NULL;
  const mxArray *c1_n_y = NULL;
  int32_T c1_e_tmatrix;
  int32_T c1_e_inliers;
  static char_T c1_cv48[14] = { 'm', 'a', 't', 'c', 'h', 'e', 'd', 'P', 'o', 'i',
    'n', 't', 's', '2' };

  int32_T c1_A_size[2];
  c1_emxArray_int32_T *c1_r7;
  int32_T c1_f_inliers;
  real32_T c1_d_u;
  const mxArray *c1_o_y = NULL;
  int32_T c1_i269;
  int32_T c1_f_loop_ub;
  const mxArray *c1_p_y = NULL;
  int32_T c1_i270;
  int32_T c1_i271;
  int32_T c1_b_partialTrueCount;
  int32_T c1_i272;
  int32_T c1_g_loop_ub;
  int32_T c1_d_i;
  int32_T c1_i273;
  boolean_T c1_e_p;
  int32_T c1_f_matchedPoints2;
  boolean_T c1_f_p;
  real32_T c1_A_data[6];
  int32_T c1_i274;
  int32_T c1_b_tmatrix_size[2];
  int32_T c1_d_k;
  int32_T c1_f_tmatrix;
  int32_T c1_g_tmatrix;
  int32_T c1_i275;
  int32_T c1_h_loop_ub;
  int32_T c1_i276;
  int32_T c1_i_loop_ub;
  int32_T c1_i277;
  int32_T c1_i278;
  real32_T c1_varargin_1;
  real32_T c1_b_tmatrix_data[9];
  int32_T c1_iv1[2];
  boolean_T c1_g_p;
  int32_T c1_h_tmatrix;
  boolean_T c1_h_p;
  int32_T c1_i_tmatrix;
  int32_T c1_j_loop_ub;
  int32_T c1_i279;
  int32_T c1_i280;
  int32_T c1_iv2[2];
  boolean_T c1_b15;
  c1_emxArray_boolean_T *c1_r8;
  const mxArray *c1_q_y = NULL;
  boolean_T c1_i_p;
  int32_T c1_i281;
  int32_T c1_tmp_size[1];
  int32_T c1_e_k;
  int32_T c1_iv3[2];
  int32_T c1_k_loop_ub;
  int32_T c1_i282;
  int32_T c1_result;
  int32_T c1_j_tmatrix;
  int32_T c1_b_tmp_size[1];
  boolean_T c1_tmp_data[9];
  int32_T c1_k_tmatrix;
  const mxArray *c1_r_y = NULL;
  int32_T c1_iv4[2];
  int32_T c1_l_loop_ub;
  int32_T c1_i283;
  static char_T c1_cv49[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'a', 'f', 'f',
    'i', 'n', 'e', '2', 'd', '.', 's', 'e', 't', '.', 'T', ':', 'i', 'n', 'c',
    'o', 'r', 'r', 'e', 'c', 't', 'S', 'i', 'z', 'e' };

  int32_T c1_c_tmatrix_size[2];
  int32_T c1_i284;
  const mxArray *c1_s_y = NULL;
  static char_T c1_e_u[34] = { 'T', ' ', 'd', 'o', 'e', 's', ' ', 'n', 'o', 't',
    ' ', 'h', 'a', 'v', 'e', ' ', 't', 'h', 'e', ' ', 'e', 'x', 'p', 'e', 'c',
    't', 'e', 'd', ' ', 's', 'i', 'z', 'e', '.' };

  int32_T c1_l_tmatrix;
  int32_T c1_m_tmatrix;
  int32_T c1_m_loop_ub;
  int32_T c1_i285;
  boolean_T c1_b_tmp_data[9];
  int32_T c1_n_loop_ub;
  int32_T c1_i286;
  int32_T c1_i287;
  int32_T c1_o_loop_ub;
  int32_T c1_i288;
  int32_T c1_i289;
  int32_T c1_i290;
  boolean_T c1_b16;
  real32_T c1_c_tmatrix_data[1500];
  const mxArray *c1_t_y = NULL;
  static char_T c1_cv50[36] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'a', 'f', 'f',
    'i', 'n', 'e', '2', 'd', '.', 's', 'e', 't', '.', 'T', ':', 'e', 'x', 'p',
    'e', 'c', 't', 'e', 'd', 'F', 'i', 'n', 'i', 't', 'e' };

  int32_T c1_d_tmatrix_size[2];
  const mxArray *c1_u_y = NULL;
  static char_T c1_cv51[24] = { 'E', 'x', 'p', 'e', 'c', 't', 'e', 'd', ' ', 'T',
    ' ', 't', 'o', ' ', 'b', 'e', ' ', 'f', 'i', 'n', 'i', 't', 'e', '.' };

  int32_T c1_n_tmatrix;
  int32_T c1_o_tmatrix;
  int32_T c1_p_loop_ub;
  int32_T c1_i291;
  real32_T c1_b_varargin_1;
  real32_T c1_d_tmatrix_data[9];
  boolean_T c1_j_p;
  boolean_T c1_k_p;
  const mxArray *c1_v_y = NULL;
  static char_T c1_cv52[44] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'g', 'e', 'o',
    't', 'r', 'a', 'n', 's', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'T',
    'r', 'a', 'n', 's', 'f', 'o', 'r', 'm', 'a', 't', 'i', 'o', 'n', 'M', 'a',
    't', 'r', 'i', 'x' };

  boolean_T c1_l_p;
  boolean_T c1_m_p;
  int32_T c1_i292;
  boolean_T c1_n_p;
  boolean_T c1_o_p;
  int32_T c1_i293;
  int32_T c1_f_k;
  const mxArray *c1_w_y = NULL;
  int32_T c1_i294;
  static char_T c1_cv53[35] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'g', 'e', 'o',
    't', 'r', 'a', 'n', 's', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'A', 'f',
    'f', 'i', 'n', 'e', 'M', 'a', 't', 'r', 'i', 'x' };

  static real_T c1_varargin_2[3] = { 0.0, 0.0, 1.0 };

  int32_T c1_b_tform;
  int32_T c1_c_tform;
  int32_T c1_q_loop_ub;
  int32_T c1_i295;
  boolean_T guard1 = false;
  boolean_T exitg1;
  int32_T exitg2;
  c1_emxInit_real32_T(chartInstance, &c1_b_matchedPoints1, 2, &c1_sc_emlrtRTEI);
  c1_i248 = c1_b_matchedPoints1->size[0] * c1_b_matchedPoints1->size[1];
  c1_b_matchedPoints1->size[0] = c1_matchedPoints1->size[0];
  c1_b_matchedPoints1->size[1] = c1_matchedPoints1->size[1];
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_b_matchedPoints1, c1_i248,
    &c1_sc_emlrtRTEI);
  c1_c_matchedPoints1 = c1_b_matchedPoints1->size[0];
  c1_d_matchedPoints1 = c1_b_matchedPoints1->size[1];
  c1_loop_ub = c1_matchedPoints1->size[0] * c1_matchedPoints1->size[1] - 1;
  for (c1_i249 = 0; c1_i249 <= c1_loop_ub; c1_i249++) {
    c1_b_matchedPoints1->data[c1_i249] = c1_matchedPoints1->data[c1_i249];
  }

  if (c1_size_check(chartInstance, c1_b_matchedPoints1)) {
  } else {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv39, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c1_y, 14,
                      c1_b_y);
  }

  c1_emxFree_real32_T(chartInstance, &c1_b_matchedPoints1);
  c1_emxInit_real32_T(chartInstance, &c1_b_matchedPoints2, 2, &c1_tc_emlrtRTEI);
  c1_i250 = c1_b_matchedPoints2->size[0] * c1_b_matchedPoints2->size[1];
  c1_b_matchedPoints2->size[0] = c1_matchedPoints2->size[0];
  c1_b_matchedPoints2->size[1] = 2;
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_b_matchedPoints2, c1_i250,
    &c1_tc_emlrtRTEI);
  c1_c_matchedPoints2 = c1_b_matchedPoints2->size[0];
  c1_d_matchedPoints2 = c1_b_matchedPoints2->size[1];
  c1_b_loop_ub = c1_matchedPoints2->size[0] * c1_matchedPoints2->size[1] - 1;
  for (c1_i251 = 0; c1_i251 <= c1_b_loop_ub; c1_i251++) {
    c1_b_matchedPoints2->data[c1_i251] = c1_matchedPoints2->data[c1_i251];
  }

  if (c1_size_check(chartInstance, c1_b_matchedPoints2)) {
  } else {
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv40, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_c_u, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c1_c_y,
                      14, c1_d_y);
  }

  c1_emxFree_real32_T(chartInstance, &c1_b_matchedPoints2);
  for (c1_i252 = 0; c1_i252 < 2; c1_i252++) {
    c1_points1[c1_i252] = (real_T)c1_matchedPoints1->size[c1_i252];
  }

  for (c1_i253 = 0; c1_i253 < 2; c1_i253++) {
    c1_points2[c1_i253] = (real_T)c1_matchedPoints2->size[c1_i253];
  }

  c1_p = false;
  c1_b_p = true;
  c1_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c1_k < 2)) {
    if (!(c1_points1[c1_k] == c1_points2[c1_k])) {
      c1_b_p = false;
      exitg1 = true;
    } else {
      c1_k++;
    }
  }

  if (!c1_b_p) {
  } else {
    c1_p = true;
  }

  if (c1_p) {
  } else {
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_cv41, 10, 0U, 1U, 0U, 2, 1, 28),
                  false);
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_cv42, 10, 0U, 1U, 0U, 2, 1, 14),
                  false);
    c1_g_y = NULL;
    sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_cv43, 10, 0U, 1U, 0U, 2, 1, 14),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 3U, 14, c1_e_y, 14, c1_f_y, 14, c1_g_y));
  }

  c1_status = ((real_T)c1_matchedPoints1->size[0] < 2.0);
  c1_ransacParams.maxNumTrials = 1000;
  c1_ransacParams.confidence = 99.0F;
  c1_ransacParams.maxDistance = 4.0F;
  c1_ransacParams.recomputeModelFromInliers = true;
  c1_ransacParams.sampleSize = 2.0F;
  c1_b_status = c1_status;
  for (c1_i254 = 0; c1_i254 < 9; c1_i254++) {
    c1_failedMatrix[c1_i254] = 0.0F;
  }

  c1_b_k = 0;
  for (c1_c_k = 0; c1_c_k < 3; c1_c_k++) {
    c1_failedMatrix[c1_b_k] = 1.0F;
    c1_b_k += 4;
  }

  c1_emxInit_boolean_T1(chartInstance, &c1_inliers, 2, &c1_fd_emlrtRTEI);
  if (c1_status == 0) {
    c1_emxInit_real32_T2(chartInstance, &c1_points, 3, &c1_pd_emlrtRTEI);
    c1_ysize[0] = (real_T)c1_matchedPoints1->size[0];
    c1_ysize[1] = (real_T)c1_matchedPoints1->size[1];
    c1_i256 = c1_points->size[0] * c1_points->size[1] * c1_points->size[2];
    c1_points->size[0] = (int32_T)c1_ysize[0];
    c1_points->size[1] = (int32_T)c1_ysize[1];
    c1_points->size[2] = 2;
    c1_emxEnsureCapacity_real32_T2(chartInstance, c1_points, c1_i256,
      &c1_vc_emlrtRTEI);
    if ((c1_matchedPoints1->size[0] == 0) || (c1_matchedPoints1->size[1] == 0))
    {
      c1_c_error(chartInstance);
    }

    c1_j = 0;
    do {
      exitg2 = 0;
      if (c1_j < 2) {
        if ((real_T)c1_points->size[c1_j] != (real_T)c1_matchedPoints1->
            size[c1_j]) {
          c1_c_p = false;
          exitg2 = 1;
        } else {
          c1_j++;
        }
      } else {
        c1_c_p = true;
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (c1_c_p) {
    } else {
      c1_h_y = NULL;
      sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_cv44, 10, 0U, 1U, 0U, 2, 1,
        39), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c1_h_y));
    }

    if (c1_matchedPoints2->size[0] == 0) {
      c1_c_error(chartInstance);
    }

    c1_b_j = 0;
    do {
      exitg2 = 0;
      if (c1_b_j < 2) {
        if ((real_T)c1_points->size[c1_b_j] != (real_T)c1_matchedPoints2->
            size[c1_b_j]) {
          c1_d_p = false;
          exitg2 = 1;
        } else {
          c1_b_j++;
        }
      } else {
        c1_d_p = true;
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (c1_d_p) {
    } else {
      c1_i_y = NULL;
      sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_cv44, 10, 0U, 1U, 0U, 2, 1,
        39), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c1_i_y));
    }

    c1_iy = -1;
    c1_b = c1_matchedPoints1->size[0] * c1_matchedPoints1->size[1];
    c1_overflow = ((!(1 > c1_b)) && (c1_b > 2147483646));
    if (c1_overflow) {
      c1_check_forloop_overflow_error(chartInstance, true);
    }

    for (c1_c_j = 0; c1_c_j + 1 <= c1_b; c1_c_j++) {
      c1_iy++;
      c1_points->data[c1_iy] = c1_matchedPoints1->data[c1_c_j];
    }

    c1_b_b = c1_matchedPoints2->size[0] << 1;
    c1_b_overflow = ((!(1 > c1_b_b)) && (c1_b_b > 2147483646));
    if (c1_b_overflow) {
      c1_check_forloop_overflow_error(chartInstance, true);
    }

    for (c1_d_j = 0; c1_d_j + 1 <= c1_b_b; c1_d_j++) {
      c1_iy++;
      c1_points->data[c1_iy] = c1_matchedPoints2->data[c1_d_j];
    }

    c1_emxInit_boolean_T(chartInstance, &c1_d_inliers, 1, &c1_yc_emlrtRTEI);
    c1_msac(chartInstance, c1_points, c1_ransacParams, &c1_isFound,
            c1_tmatrix_data, c1_tmatrix_size, c1_d_inliers);
    c1_i267 = c1_inliers->size[0] * c1_inliers->size[1];
    c1_inliers->size[0] = c1_d_inliers->size[0];
    c1_inliers->size[1] = 1;
    c1_emxEnsureCapacity_boolean_T1(chartInstance, c1_inliers, c1_i267,
      &c1_fd_emlrtRTEI);
    c1_e_inliers = c1_inliers->size[0];
    c1_f_inliers = c1_inliers->size[1];
    c1_f_loop_ub = c1_d_inliers->size[0] - 1;
    c1_emxFree_real32_T(chartInstance, &c1_points);
    for (c1_i271 = 0; c1_i271 <= c1_f_loop_ub; c1_i271++) {
      c1_inliers->data[c1_i271] = c1_d_inliers->data[c1_i271];
    }

    c1_emxFree_boolean_T(chartInstance, &c1_d_inliers);
    if (!c1_isFound) {
      c1_b_status = 2;
    }

    c1_b_tmatrix_size[0] = c1_tmatrix_size[0];
    c1_b_tmatrix_size[1] = c1_tmatrix_size[1];
    c1_f_tmatrix = c1_b_tmatrix_size[0];
    c1_g_tmatrix = c1_b_tmatrix_size[1];
    c1_h_loop_ub = c1_tmatrix_size[0] * c1_tmatrix_size[1] - 1;
    for (c1_i276 = 0; c1_i276 <= c1_h_loop_ub; c1_i276++) {
      c1_b_tmatrix_data[c1_i276] = c1_tmatrix_data[c1_i276];
    }

    c1_varargin_1 = c1_det(chartInstance, c1_b_tmatrix_data, c1_b_tmatrix_size);
    c1_g_p = false;
    c1_h_p = true;
    if (!(c1_varargin_1 == 0.0F)) {
      c1_h_p = false;
    }

    if (!c1_h_p) {
    } else {
      c1_g_p = true;
    }

    c1_emxInit_boolean_T(chartInstance, &c1_r8, 1, &c1_md_emlrtRTEI);
    guard1 = false;
    if (c1_g_p) {
      guard1 = true;
    } else {
      c1_tmp_size[0] = c1_tmatrix_size[0] * c1_tmatrix_size[1];
      c1_k_loop_ub = c1_tmatrix_size[0] * c1_tmatrix_size[1] - 1;
      for (c1_i282 = 0; c1_i282 <= c1_k_loop_ub; c1_i282++) {
        c1_tmp_data[c1_i282] = muSingleScalarIsInf(c1_tmatrix_data[c1_i282]);
      }

      c1_b_tmp_size[0] = c1_tmatrix_size[0] * c1_tmatrix_size[1];
      c1_l_loop_ub = c1_tmatrix_size[0] * c1_tmatrix_size[1] - 1;
      for (c1_i284 = 0; c1_i284 <= c1_l_loop_ub; c1_i284++) {
        c1_b_tmp_data[c1_i284] = muSingleScalarIsNaN(c1_tmatrix_data[c1_i284]);
      }

      c1_i285 = c1_r8->size[0];
      c1_r8->size[0] = c1_tmp_size[0];
      c1_emxEnsureCapacity_boolean_T(chartInstance, c1_r8, c1_i285,
        &c1_md_emlrtRTEI);
      c1_o_loop_ub = c1_tmp_size[0] - 1;
      for (c1_i290 = 0; c1_i290 <= c1_o_loop_ub; c1_i290++) {
        c1_r8->data[c1_i290] = !((!c1_tmp_data[c1_i290]) &&
          (!c1_b_tmp_data[c1_i290]));
      }

      if (c1_any(chartInstance, c1_r8)) {
        guard1 = true;
      }
    }

    if (guard1) {
      c1_b_status = 2;
      c1_tmatrix_size[0] = 3;
      c1_tmatrix_size[1] = 3;
      c1_j_tmatrix = c1_tmatrix_size[0];
      c1_k_tmatrix = c1_tmatrix_size[1];
      for (c1_i283 = 0; c1_i283 < 9; c1_i283++) {
        c1_tmatrix_data[c1_i283] = c1_failedMatrix[c1_i283];
      }
    }

    c1_emxFree_boolean_T(chartInstance, &c1_r8);
  } else {
    c1_i255 = c1_inliers->size[0] * c1_inliers->size[1];
    c1_inliers->size[0] = c1_matchedPoints1->size[0];
    c1_inliers->size[1] = c1_matchedPoints1->size[0];
    c1_emxEnsureCapacity_boolean_T1(chartInstance, c1_inliers, c1_i255,
      &c1_uc_emlrtRTEI);
    c1_b_inliers = c1_inliers->size[0];
    c1_c_inliers = c1_inliers->size[1];
    c1_c_loop_ub = c1_matchedPoints1->size[0] * c1_matchedPoints1->size[0] - 1;
    for (c1_i257 = 0; c1_i257 <= c1_c_loop_ub; c1_i257++) {
      c1_inliers->data[c1_i257] = false;
    }

    c1_tmatrix_size[0] = 3;
    c1_tmatrix_size[1] = 3;
    c1_tmatrix = c1_tmatrix_size[0];
    c1_b_tmatrix = c1_tmatrix_size[1];
    for (c1_i258 = 0; c1_i258 < 9; c1_i258++) {
      c1_tmatrix_data[c1_i258] = c1_failedMatrix[c1_i258];
    }
  }

  if (c1_b_status == 0) {
    c1_end = c1_inliers->size[0] * c1_inliers->size[1] - 1;
    c1_trueCount = 0;
    for (c1_i = 0; c1_i <= c1_end; c1_i++) {
      if (c1_inliers->data[c1_i]) {
        c1_trueCount++;
      }
    }

    c1_emxInit_int32_T(chartInstance, &c1_r6, 1, &c1_qd_emlrtRTEI);
    c1_i260 = c1_r6->size[0];
    c1_r6->size[0] = c1_trueCount;
    c1_emxEnsureCapacity_int32_T(chartInstance, c1_r6, c1_i260, &c1_yc_emlrtRTEI);
    c1_partialTrueCount = 0;
    for (c1_b_i = 0; c1_b_i <= c1_end; c1_b_i++) {
      if (c1_inliers->data[c1_b_i]) {
        c1_r6->data[c1_partialTrueCount] = c1_b_i + 1;
        c1_partialTrueCount++;
      }
    }

    c1_f_matchedPoints1 = c1_matchedPoints1->size[0];
    c1_i262 = c1_matchedPoints1->size[1];
    c1_i263 = c1_inlierPoints1->size[0] * c1_inlierPoints1->size[1];
    c1_inlierPoints1->size[0] = c1_r6->size[0];
    c1_inlierPoints1->size[1] = c1_i262;
    c1_emxEnsureCapacity_real32_T(chartInstance, c1_inlierPoints1, c1_i263,
      &c1_cd_emlrtRTEI);
    c1_d_loop_ub = c1_i262 - 1;
    for (c1_i265 = 0; c1_i265 <= c1_d_loop_ub; c1_i265++) {
      c1_e_loop_ub = c1_r6->size[0] - 1;
      for (c1_i266 = 0; c1_i266 <= c1_e_loop_ub; c1_i266++) {
        c1_inlierPoints1->data[c1_i266 + c1_inlierPoints1->size[0] * c1_i265] =
          c1_matchedPoints1->data[(sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c1_r6->data[c1_i266], 1, c1_f_matchedPoints1) +
          c1_matchedPoints1->size[0] * c1_i265) - 1];
      }
    }

    c1_emxFree_int32_T(chartInstance, &c1_r6);
    c1_b_end = c1_inliers->size[0] * c1_inliers->size[1] - 1;
    c1_b_trueCount = 0;
    for (c1_c_i = 0; c1_c_i <= c1_b_end; c1_c_i++) {
      if (c1_inliers->data[c1_c_i]) {
        c1_b_trueCount++;
      }
    }

    c1_emxInit_int32_T(chartInstance, &c1_r7, 1, &c1_rd_emlrtRTEI);
    c1_i269 = c1_r7->size[0];
    c1_r7->size[0] = c1_b_trueCount;
    c1_emxEnsureCapacity_int32_T(chartInstance, c1_r7, c1_i269, &c1_yc_emlrtRTEI);
    c1_b_partialTrueCount = 0;
    for (c1_d_i = 0; c1_d_i <= c1_b_end; c1_d_i++) {
      if (c1_inliers->data[c1_d_i]) {
        c1_r7->data[c1_b_partialTrueCount] = c1_d_i + 1;
        c1_b_partialTrueCount++;
      }
    }

    c1_f_matchedPoints2 = c1_matchedPoints2->size[0];
    c1_i274 = c1_inlierPoints2->size[0] * c1_inlierPoints2->size[1];
    c1_inlierPoints2->size[0] = c1_r7->size[0];
    c1_inlierPoints2->size[1] = 2;
    c1_emxEnsureCapacity_real32_T(chartInstance, c1_inlierPoints2, c1_i274,
      &c1_ed_emlrtRTEI);
    for (c1_i275 = 0; c1_i275 < 2; c1_i275++) {
      c1_i_loop_ub = c1_r7->size[0] - 1;
      for (c1_i278 = 0; c1_i278 <= c1_i_loop_ub; c1_i278++) {
        c1_inlierPoints2->data[c1_i278 + c1_inlierPoints2->size[0] * c1_i275] =
          c1_matchedPoints2->data[(sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c1_r7->data[c1_i278], 1, c1_f_matchedPoints2) +
          c1_matchedPoints2->size[0] * c1_i275) - 1];
      }
    }

    c1_emxFree_int32_T(chartInstance, &c1_r7);
  } else {
    c1_i259 = c1_inlierPoints1->size[0] * c1_inlierPoints1->size[1];
    c1_inlierPoints1->size[0] = 0;
    c1_inlierPoints1->size[1] = 0;
    c1_emxEnsureCapacity_real32_T(chartInstance, c1_inlierPoints1, c1_i259,
      &c1_xc_emlrtRTEI);
    c1_e_matchedPoints1 = c1_matchedPoints1->size[0] * c1_matchedPoints1->size[1];
    c1_b_inlierPoints1 = c1_inlierPoints1->size[0];
    c1_c_inlierPoints1 = c1_inlierPoints1->size[1];
    c1_i261 = c1_inlierPoints2->size[0] * c1_inlierPoints2->size[1];
    c1_inlierPoints2->size[0] = 0;
    c1_inlierPoints2->size[1] = 0;
    c1_emxEnsureCapacity_real32_T(chartInstance, c1_inlierPoints2, c1_i261,
      &c1_ad_emlrtRTEI);
    c1_e_matchedPoints2 = c1_matchedPoints2->size[0] << 1;
    c1_b_inlierPoints2 = c1_inlierPoints2->size[0];
    c1_c_inlierPoints2 = c1_inlierPoints2->size[1];
    c1_tmatrix_size[0] = 3;
    c1_tmatrix_size[1] = 3;
    c1_c_tmatrix = c1_tmatrix_size[0];
    c1_d_tmatrix = c1_tmatrix_size[1];
    for (c1_i264 = 0; c1_i264 < 9; c1_i264++) {
      c1_tmatrix_data[c1_i264] = c1_failedMatrix[c1_i264];
    }
  }

  c1_emxFree_boolean_T(chartInstance, &c1_inliers);
  if (!(c1_b_status == 1)) {
  } else {
    c1_j_y = NULL;
    sf_mex_assign(&c1_j_y, sf_mex_create("y", c1_cv45, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    c1_k_y = NULL;
    sf_mex_assign(&c1_k_y, sf_mex_create("y", c1_cv46, 10, 0U, 1U, 0U, 2, 1, 14),
                  false);
    c1_m_y = NULL;
    sf_mex_assign(&c1_m_y, sf_mex_create("y", c1_cv48, 10, 0U, 1U, 0U, 2, 1, 14),
                  false);
    c1_d_u = 2.0F;
    c1_p_y = NULL;
    sf_mex_assign(&c1_p_y, sf_mex_create("y", &c1_d_u, 1, 0U, 0U, 0U, 0), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 4U, 14, c1_j_y, 14, c1_k_y, 14, c1_m_y, 14, c1_p_y));
  }

  if (!(c1_b_status == 2)) {
  } else {
    c1_l_y = NULL;
    sf_mex_assign(&c1_l_y, sf_mex_create("y", c1_cv47, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c1_n_y = NULL;
    sf_mex_assign(&c1_n_y, sf_mex_create("y", c1_cv46, 10, 0U, 1U, 0U, 2, 1, 14),
                  false);
    c1_o_y = NULL;
    sf_mex_assign(&c1_o_y, sf_mex_create("y", c1_cv48, 10, 0U, 1U, 0U, 2, 1, 14),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 3U, 14, c1_l_y, 14, c1_n_y, 14, c1_o_y));
  }

  c1_i268 = c1_tmatrix_size[0];
  c1_e_tmatrix = c1_tmatrix_size[1];
  c1_A_size[0] = c1_i268;
  c1_A_size[1] = 2;
  for (c1_i270 = 0; c1_i270 < 2; c1_i270++) {
    c1_g_loop_ub = c1_i268 - 1;
    for (c1_i273 = 0; c1_i273 <= c1_g_loop_ub; c1_i273++) {
      c1_A_data[c1_i273 + c1_A_size[0] * c1_i270] = c1_tmatrix_data[c1_i273 +
        c1_tmatrix_size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c1_i270 + 1, 1, c1_e_tmatrix) - 1)];
    }
  }

  c1_i272 = c1_tmatrix_size[0];
  c1_points1[0] = (real_T)c1_i272;
  c1_points1[1] = 2.0;
  c1_e_p = false;
  c1_f_p = true;
  c1_d_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c1_d_k < 2)) {
    if (!(c1_points1[c1_d_k] == 3.0 + -(real_T)c1_d_k)) {
      c1_f_p = false;
      exitg1 = true;
    } else {
      c1_d_k++;
    }
  }

  if (!c1_f_p) {
  } else {
    c1_e_p = true;
  }

  if (c1_e_p) {
    c1_i277 = c1_tmatrix_size[0];
    c1_iv1[0] = c1_i277;
    c1_iv1[1] = 2;
    if (c1_iv1[0] == 3) {
      c1_b15 = true;
    } else {
      c1_i279 = c1_tmatrix_size[0];
      c1_iv2[0] = c1_i279;
      c1_iv2[1] = 2;
      if (c1_iv2[0] == 0) {
        c1_b15 = true;
      } else {
        c1_b15 = false;
      }
    }

    if (c1_b15) {
    } else {
      c1_q_y = NULL;
      sf_mex_assign(&c1_q_y, sf_mex_create("y", c1_cv10, 10, 0U, 1U, 0U, 2, 1,
        39), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c1_q_y));
    }

    c1_i281 = c1_tmatrix_size[0];
    c1_iv3[0] = c1_i281;
    c1_iv3[1] = 2;
    if (!(c1_iv3[0] == 0)) {
      c1_result = 2;
    } else {
      c1_result = 0;
    }

    c1_iv4[0] = 3;
    c1_iv4[1] = c1_result;
    c1_tmatrix_size[0] = 3;
    c1_tmatrix_size[1] = c1_iv4[1] + 1;
    c1_m_loop_ub = c1_iv4[1] - 1;
    for (c1_i286 = 0; c1_i286 <= c1_m_loop_ub; c1_i286++) {
      for (c1_i289 = 0; c1_i289 < 3; c1_i289++) {
        c1_tmatrix_data[c1_i289 + c1_tmatrix_size[0] * c1_i286] =
          c1_A_data[c1_i289 + c1_iv4[0] * c1_i286];
      }
    }

    for (c1_i288 = 0; c1_i288 < 3; c1_i288++) {
      c1_tmatrix_data[c1_i288 + c1_tmatrix_size[0] * c1_iv4[1]] = c1_fv0[c1_i288];
    }
  } else {
    c1_tmatrix_size[0] = c1_A_size[0];
    c1_tmatrix_size[1] = 2;
    c1_h_tmatrix = c1_tmatrix_size[0];
    c1_i_tmatrix = c1_tmatrix_size[1];
    c1_j_loop_ub = c1_A_size[0] * c1_A_size[1] - 1;
    for (c1_i280 = 0; c1_i280 <= c1_j_loop_ub; c1_i280++) {
      c1_tmatrix_data[c1_i280] = c1_A_data[c1_i280];
    }
  }

  c1_i_p = true;
  c1_e_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c1_e_k < 2)) {
    if (3.0 == (real_T)c1_tmatrix_size[c1_e_k]) {
      c1_e_k++;
    } else {
      c1_i_p = false;
      exitg1 = true;
    }
  }

  if (c1_i_p) {
  } else {
    c1_r_y = NULL;
    sf_mex_assign(&c1_r_y, sf_mex_create("y", c1_cv49, 10, 0U, 1U, 0U, 2, 1, 35),
                  false);
    c1_s_y = NULL;
    sf_mex_assign(&c1_s_y, sf_mex_create("y", c1_e_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c1_r_y,
                      14, c1_s_y);
  }

  c1_c_tmatrix_size[0] = c1_tmatrix_size[0];
  c1_c_tmatrix_size[1] = c1_tmatrix_size[1];
  c1_l_tmatrix = c1_c_tmatrix_size[0];
  c1_m_tmatrix = c1_c_tmatrix_size[1];
  c1_n_loop_ub = c1_tmatrix_size[0] * c1_tmatrix_size[1] - 1;
  for (c1_i287 = 0; c1_i287 <= c1_n_loop_ub; c1_i287++) {
    c1_c_tmatrix_data[c1_i287] = c1_tmatrix_data[c1_i287];
  }

  c1_b16 = c1_all(chartInstance, c1_c_tmatrix_data, c1_c_tmatrix_size);
  if (c1_b16) {
  } else {
    c1_t_y = NULL;
    sf_mex_assign(&c1_t_y, sf_mex_create("y", c1_cv50, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c1_u_y = NULL;
    sf_mex_assign(&c1_u_y, sf_mex_create("y", c1_cv51, 10, 0U, 1U, 0U, 2, 1, 24),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c1_t_y,
                      14, c1_u_y);
  }

  c1_d_tmatrix_size[0] = c1_tmatrix_size[0];
  c1_d_tmatrix_size[1] = c1_tmatrix_size[1];
  c1_n_tmatrix = c1_d_tmatrix_size[0];
  c1_o_tmatrix = c1_d_tmatrix_size[1];
  c1_p_loop_ub = c1_tmatrix_size[0] * c1_tmatrix_size[1] - 1;
  for (c1_i291 = 0; c1_i291 <= c1_p_loop_ub; c1_i291++) {
    c1_d_tmatrix_data[c1_i291] = c1_tmatrix_data[c1_i291];
  }

  c1_b_varargin_1 = c1_det(chartInstance, c1_d_tmatrix_data, c1_d_tmatrix_size);
  c1_j_p = false;
  c1_k_p = true;
  if (!(c1_b_varargin_1 == 0.0F)) {
    c1_k_p = false;
  }

  if (!c1_k_p) {
  } else {
    c1_j_p = true;
  }

  if (!c1_j_p) {
  } else {
    c1_v_y = NULL;
    sf_mex_assign(&c1_v_y, sf_mex_create("y", c1_cv52, 10, 0U, 1U, 0U, 2, 1, 44),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_v_y));
  }

  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 3, 1, c1_tmatrix_size[1]);
  c1_l_p = false;
  c1_m_p = false;
  c1_i292 = c1_tmatrix_size[0];
  if ((real_T)c1_i292 != 3.0) {
  } else {
    c1_m_p = true;
  }

  c1_n_p = c1_m_p;
  c1_o_p = c1_n_p;
  if (c1_n_p) {
    c1_i293 = c1_tmatrix_size[0];
    if (!(c1_i293 == 0)) {
      c1_f_k = 0;
      exitg1 = false;
      while ((!exitg1) && (c1_f_k < 3)) {
        c1_i294 = c1_tmatrix_size[0];
        if (!((real_T)c1_tmatrix_data[c1_f_k + (c1_tmatrix_size[0] << 1)] ==
              c1_varargin_2[c1_f_k])) {
          c1_o_p = false;
          exitg1 = true;
        } else {
          c1_f_k++;
        }
      }
    }
  }

  if (!c1_o_p) {
  } else {
    c1_l_p = true;
  }

  if (c1_l_p) {
  } else {
    c1_w_y = NULL;
    sf_mex_assign(&c1_w_y, sf_mex_create("y", c1_cv53, 10, 0U, 1U, 0U, 2, 1, 35),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_w_y));
  }

  c1_tform->T.size[0] = c1_tmatrix_size[0];
  c1_tform->T.size[1] = c1_tmatrix_size[1];
  c1_b_tform = c1_tform->T.size[0];
  c1_c_tform = c1_tform->T.size[1];
  c1_q_loop_ub = c1_tmatrix_size[0] * c1_tmatrix_size[1] - 1;
  for (c1_i295 = 0; c1_i295 <= c1_q_loop_ub; c1_i295++) {
    c1_tform->T.data[c1_i295] = c1_tmatrix_data[c1_i295];
  }

  c1_tform->Dimensionality = 2.0;
}

static void c1_c_error(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  const mxArray *c1_y = NULL;
  static char_T c1_cv54[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'c', 'a', 't', '_', 'U', 'n', 's', 'u', 'p', 'p', 'o',
    'r', 't', 'e', 'd', 'V', 'a', 'r', 'i', 'a', 'b', 'l', 'e', 'S', 'i', 'z',
    'e', 'E', 'm', 'p', 't', 'y' };

  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv54, 10, 0U, 1U, 0U, 2, 1, 46),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c1_y));
}

static void c1_msac(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
                    c1_emxArray_real32_T *c1_allPoints,
                    c1_svT7UAnr23JjyThWngsAoUB c1_params, boolean_T *c1_isFound,
                    real32_T c1_bestModelParams_data[], int32_T
                    c1_bestModelParams_size[2], c1_emxArray_boolean_T
                    *c1_inliers)
{
  c1_emxArray_boolean_T *c1_bestInliers;
  real_T c1_b_numPts;
  real_T c1_idxTrial;
  int32_T c1_numTrials;
  real32_T c1_bestDis;
  int32_T c1_bestModelParams;
  int32_T c1_b_bestModelParams;
  real_T c1_skipTrials;
  int32_T c1_i296;
  int32_T c1_loop_ub;
  int32_T c1_i297;
  c1_emxArray_real32_T *c1_dis;
  c1_emxArray_boolean_T *c1_b_dis;
  c1_emxArray_real32_T *c1_c_dis;
  c1_emxArray_real32_T *c1_b_allPoints;
  c1_emxArray_real32_T *c1_samplePoints;
  boolean_T c1_b17;
  const mxArray *c1_y = NULL;
  static char_T c1_cv55[25] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'a', 'n',
    'd', 'p', 'e', 'r', 'm', ':', 'i', 'n', 'p', 'u', 't', 'T', 'y', 'p', 'e' };

  int32_T c1_b_bestModelParams_size[2];
  const mxArray *c1_b_y = NULL;
  static char_T c1_cv56[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'a', 'n',
    'd', 'p', 'e', 'r', 'm', ':', 'i', 'n', 'p', 'u', 't', 'K', 'T', 'o', 'o',
    'L', 'a', 'r', 'g', 'e' };

  int32_T c1_indices_size[2];
  int32_T c1_c_bestModelParams;
  int32_T c1_d_bestModelParams;
  int32_T c1_indices;
  int32_T c1_b_loop_ub;
  int32_T c1_b_indices;
  int32_T c1_i298;
  int32_T c1_i299;
  c1_emxArray_boolean_T *c1_b_bestInliers;
  real32_T c1_b_bestModelParams_data[9];
  real_T c1_indices_data[2];
  int32_T c1_hashTbl_size[1];
  real_T c1_t;
  real_T c1_x;
  int32_T c1_i300;
  int32_T c1_i301;
  int32_T c1_m;
  real_T c1_j;
  boolean_T c1_b_isFound;
  int32_T c1_c_loop_ub;
  int32_T c1_link_size[1];
  real_T c1_hashTbl_data[2];
  real_T c1_denom;
  boolean_T c1_c_isFound;
  int32_T c1_i302;
  int32_T c1_i303;
  real_T c1_pt;
  int32_T c1_c_allPoints;
  c1_emxArray_int32_T *c1_r9;
  real_T c1_b_u;
  int32_T c1_i304;
  c1_emxArray_boolean_T *c1_b_inliers;
  int32_T c1_samplePoints_size[3];
  c1_emxArray_real32_T *c1_d_dis;
  int32_T c1_val_size[1];
  real_T c1_link_data[2];
  c1_emxArray_real32_T *c1_d_allPoints;
  int32_T c1_i305;
  c1_emxArray_real32_T *c1_e_allPoints;
  real_T c1_b_x;
  int32_T c1_i306;
  int32_T c1_i307;
  int32_T c1_end;
  int32_T c1_loc_size[1];
  real_T c1_val_data[2];
  int32_T c1_trueCount;
  int32_T c1_i308;
  int32_T c1_i309;
  int32_T c1_d_loop_ub;
  int32_T c1_i;
  int32_T c1_i310;
  int32_T c1_e_loop_ub;
  int32_T c1_i311;
  real_T c1_newEntry;
  real_T c1_loc_data[2];
  int32_T c1_i312;
  int32_T c1_i313;
  int32_T c1_b_samplePoints;
  int32_T c1_b_m;
  int32_T c1_c_samplePoints;
  int32_T c1_partialTrueCount;
  int32_T c1_d_samplePoints;
  real32_T c1_samplePoints_data[8];
  int32_T c1_b_i;
  int32_T c1_f_loop_ub;
  real_T c1_nleftm1;
  int32_T c1_i314;
  real_T c1_c_x;
  int32_T c1_f_allPoints;
  real_T c1_selectedLoc;
  int32_T c1_i315;
  real_T c1_c_i;
  real32_T c1_modelParams[9];
  int32_T c1_i316;
  int32_T c1_i317;
  int32_T c1_i318;
  boolean_T c1_b[9];
  int32_T c1_i319;
  boolean_T c1_isValidModel;
  boolean_T c1_b_b[9];
  int32_T c1_k;
  int32_T c1_g_loop_ub;
  real_T c1_jlast;
  int32_T c1_i320;
  int32_T c1_i321;
  int32_T c1_i322;
  real32_T c1_b_modelParams[9];
  int32_T c1_h_loop_ub;
  int32_T c1_i323;
  int32_T c1_i324;
  real_T c1_lastVal;
  int32_T c1_i325;
  real32_T c1_c_modelParams[9];
  int32_T c1_g_allPoints;
  int32_T c1_h_allPoints;
  int32_T c1_i_allPoints;
  int32_T c1_i_loop_ub;
  int32_T c1_j_allPoints;
  int32_T c1_i326;
  int32_T c1_k_allPoints;
  int32_T c1_l_allPoints;
  int32_T c1_j_loop_ub;
  int32_T c1_i327;
  int32_T c1_b_end;
  int32_T c1_d_i;
  int32_T c1_c_end;
  int32_T c1_i328;
  int32_T c1_e_i;
  int32_T c1_k_loop_ub;
  int32_T c1_i329;
  int32_T c1_i330;
  int32_T c1_l_loop_ub;
  int32_T c1_i331;
  int32_T c1_e_bestModelParams;
  real32_T c1_accDis;
  int32_T c1_f_bestModelParams;
  int32_T c1_i332;
  int32_T c1_i333;
  static int32_T c1_iv5[2] = { 3, 3 };

  int32_T c1_i334;
  int32_T c1_m_loop_ub;
  int32_T c1_i335;
  int32_T c1_n_loop_ub;
  int32_T c1_i336;
  int32_T c1_g_bestModelParams;
  int32_T c1_h_bestModelParams;
  int32_T c1_i337;
  int32_T c1_i338;
  int32_T c1_i339;
  int32_T c1_o_loop_ub;
  int32_T c1_i340;
  int32_T c1_i341;
  int32_T c1_p_loop_ub;
  int32_T c1_i342;
  int32_T c1_q_loop_ub;
  int32_T c1_i343;
  real32_T c1_inlierNum;
  real32_T c1_inlierProbability;
  boolean_T c1_p;
  int32_T c1_num;
  real32_T c1_f0;
  int32_T c1_i344;
  boolean_T guard1 = false;
  boolean_T exitg1;
  (void)c1_params;
  c1_emxInit_boolean_T(chartInstance, &c1_bestInliers, 1, &c1_td_emlrtRTEI);
  c1_b_numPts = (real_T)c1_allPoints->size[0];
  c1_idxTrial = 1.0;
  c1_numTrials = 1000;
  c1_bestDis = 4.0F * (real32_T)c1_allPoints->size[0];
  c1_bestModelParams_size[0] = 0;
  c1_bestModelParams_size[1] = 0;
  c1_bestModelParams = c1_bestModelParams_size[0];
  c1_b_bestModelParams = c1_bestModelParams_size[1];
  c1_skipTrials = 0.0;
  c1_i296 = c1_bestInliers->size[0];
  c1_bestInliers->size[0] = c1_allPoints->size[0];
  c1_emxEnsureCapacity_boolean_T(chartInstance, c1_bestInliers, c1_i296,
    &c1_td_emlrtRTEI);
  c1_loop_ub = c1_allPoints->size[0] - 1;
  for (c1_i297 = 0; c1_i297 <= c1_loop_ub; c1_i297++) {
    c1_bestInliers->data[c1_i297] = false;
  }

  c1_emxInit_real32_T1(chartInstance, &c1_dis, 1, &c1_se_emlrtRTEI);
  c1_emxInit_boolean_T(chartInstance, &c1_b_dis, 1, &c1_qe_emlrtRTEI);
  c1_emxInit_real32_T1(chartInstance, &c1_c_dis, 1, &c1_ie_emlrtRTEI);
  c1_emxInit_real32_T2(chartInstance, &c1_b_allPoints, 3, &c1_je_emlrtRTEI);
  c1_emxInit_real32_T2(chartInstance, &c1_samplePoints, 3, &c1_ge_emlrtRTEI);
  while ((c1_idxTrial <= (real_T)c1_numTrials) && (c1_skipTrials < 10000.0)) {
    c1_b17 = (c1_b_numPts == muDoubleScalarFloor(c1_b_numPts));
    if (c1_b17) {
    } else {
      c1_y = NULL;
      sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv55, 10, 0U, 1U, 0U, 2, 1, 25),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c1_y));
    }

    if (2.0 <= c1_b_numPts) {
    } else {
      c1_b_y = NULL;
      sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv56, 10, 0U, 1U, 0U, 2, 1,
        30), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c1_b_y));
    }

    c1_indices_size[0] = 1;
    c1_indices_size[1] = 2;
    c1_indices = c1_indices_size[0];
    c1_b_indices = c1_indices_size[1];
    for (c1_i299 = 0; c1_i299 < 2; c1_i299++) {
      c1_indices_data[c1_i299] = 0.0;
    }

    if (2.0 >= c1_b_numPts) {
      c1_indices_data[0] = 1.0;
      c1_x = c1_rand(chartInstance) * 2.0;
      c1_j = muDoubleScalarFloor(c1_x);
      c1_indices_data[1] = c1_indices_data[(int32_T)(c1_j + 1.0) - 1];
      c1_indices_data[(int32_T)(c1_j + 1.0) - 1] = 2.0;
    } else if (2.0 >= c1_b_numPts / 4.0) {
      c1_t = 0.0;
      for (c1_m = 0; c1_m < 2; c1_m++) {
        c1_denom = c1_b_numPts - c1_t;
        c1_pt = (2.0 - (real_T)c1_m) / c1_denom;
        c1_b_u = c1_rand(chartInstance);
        while (c1_b_u > c1_pt) {
          c1_t++;
          c1_denom--;
          c1_pt += (1.0 - c1_pt) * ((2.0 - (real_T)c1_m) / c1_denom);
        }

        c1_t++;
        c1_b_x = c1_rand(chartInstance) * ((real_T)c1_m + 1.0);
        c1_j = muDoubleScalarFloor(c1_b_x);
        c1_indices_data[c1_m] = c1_indices_data[(int32_T)(c1_j + 1.0) - 1];
        c1_indices_data[(int32_T)(c1_j + 1.0) - 1] = c1_t;
      }
    } else {
      c1_hashTbl_size[0] = 2;
      for (c1_i301 = 0; c1_i301 < 2; c1_i301++) {
        c1_hashTbl_data[c1_i301] = 0.0;
      }

      c1_link_size[0] = 2;
      for (c1_i303 = 0; c1_i303 < 2; c1_i303++) {
        c1_link_data[c1_i303] = 0.0;
      }

      c1_val_size[0] = 2;
      for (c1_i305 = 0; c1_i305 < 2; c1_i305++) {
        c1_val_data[c1_i305] = 0.0;
      }

      c1_loc_size[0] = 2;
      for (c1_i308 = 0; c1_i308 < 2; c1_i308++) {
        c1_loc_data[c1_i308] = 0.0;
      }

      c1_newEntry = 1.0;
      c1_indices_size[0] = 1;
      c1_indices_size[1] = 2;
      for (c1_b_m = 0; c1_b_m < 2; c1_b_m++) {
        c1_nleftm1 = c1_b_numPts - (1.0 + (real_T)c1_b_m);
        c1_c_x = c1_rand(chartInstance) * (c1_nleftm1 + 1.0);
        c1_selectedLoc = muDoubleScalarFloor(c1_c_x);
        c1_c_i = 1.0 + c1_mod(chartInstance, c1_selectedLoc, 2.0);
        c1_j = c1_hashTbl_data[(int32_T)c1_c_i - 1];
        while ((c1_j > 0.0) && (c1_loc_data[(int32_T)c1_j - 1] != c1_selectedLoc))
        {
          c1_j = c1_link_data[(int32_T)c1_j - 1];
        }

        if (c1_j > 0.0) {
          c1_indices_data[c1_b_m] = c1_val_data[(int32_T)c1_j - 1] + 1.0;
        } else {
          c1_indices_data[c1_b_m] = c1_selectedLoc + 1.0;
          c1_j = c1_newEntry;
          c1_newEntry++;
          c1_loc_data[(int32_T)c1_j - 1] = c1_selectedLoc;
          c1_link_data[(int32_T)c1_j - 1] = c1_hashTbl_data[(int32_T)c1_c_i - 1];
          c1_hashTbl_data[(int32_T)c1_c_i - 1] = c1_j;
        }

        if (1.0 + (real_T)c1_b_m < 2.0) {
          c1_jlast = c1_hashTbl_data[(int32_T)(1.0 + c1_mod(chartInstance,
            c1_nleftm1, 2.0)) - 1];
          while ((c1_jlast > 0.0) && (c1_loc_data[(int32_T)c1_jlast - 1] !=
                  c1_nleftm1)) {
            c1_jlast = c1_link_data[(int32_T)c1_jlast - 1];
          }

          if (c1_jlast > 0.0) {
            c1_lastVal = c1_val_data[(int32_T)c1_jlast - 1];
          } else {
            c1_lastVal = c1_nleftm1;
          }

          c1_val_data[(int32_T)c1_j - 1] = c1_lastVal;
        }
      }
    }

    c1_c_allPoints = c1_allPoints->size[0];
    c1_i304 = c1_allPoints->size[1];
    c1_samplePoints_size[0] = 2;
    c1_samplePoints_size[1] = c1_i304;
    c1_samplePoints_size[2] = 2;
    for (c1_i306 = 0; c1_i306 < 2; c1_i306++) {
      c1_d_loop_ub = c1_i304 - 1;
      for (c1_i310 = 0; c1_i310 <= c1_d_loop_ub; c1_i310++) {
        for (c1_i313 = 0; c1_i313 < 2; c1_i313++) {
          c1_samplePoints_data[(c1_i313 + c1_samplePoints_size[0] * c1_i310) +
            c1_samplePoints_size[0] * c1_samplePoints_size[1] * c1_i306] =
            c1_allPoints->data[((sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, (int32_T)c1_indices_data[c1_indices_size[0] * c1_i313],
             1, c1_c_allPoints) + c1_allPoints->size[0] * c1_i310) +
                                c1_allPoints->size[0] * c1_allPoints->size[1] *
                                c1_i306) - 1];
        }
      }
    }

    c1_i309 = c1_samplePoints->size[0] * c1_samplePoints->size[1] *
      c1_samplePoints->size[2];
    c1_samplePoints->size[0] = 2;
    c1_samplePoints->size[1] = c1_samplePoints_size[1];
    c1_samplePoints->size[2] = 2;
    c1_emxEnsureCapacity_real32_T2(chartInstance, c1_samplePoints, c1_i309,
      &c1_ge_emlrtRTEI);
    c1_b_samplePoints = c1_samplePoints->size[0];
    c1_c_samplePoints = c1_samplePoints->size[1];
    c1_d_samplePoints = c1_samplePoints->size[2];
    c1_f_loop_ub = c1_samplePoints_size[0] * c1_samplePoints_size[1] *
      c1_samplePoints_size[2] - 1;
    for (c1_i314 = 0; c1_i314 <= c1_f_loop_ub; c1_i314++) {
      c1_samplePoints->data[c1_i314] = c1_samplePoints_data[c1_i314];
    }

    c1_computeSimilarity(chartInstance, c1_samplePoints, c1_modelParams);
    for (c1_i317 = 0; c1_i317 < 9; c1_i317++) {
      c1_b[c1_i317] = muSingleScalarIsInf(c1_modelParams[c1_i317]);
    }

    for (c1_i318 = 0; c1_i318 < 9; c1_i318++) {
      c1_b_b[c1_i318] = muSingleScalarIsNaN(c1_modelParams[c1_i318]);
    }

    c1_isValidModel = true;
    c1_k = 0;
    exitg1 = false;
    while ((!exitg1) && (c1_k < 9)) {
      if (!((!c1_b[c1_k]) && (!c1_b_b[c1_k]))) {
        c1_isValidModel = false;
        exitg1 = true;
      } else {
        c1_k++;
      }
    }

    if (c1_isValidModel) {
      for (c1_i323 = 0; c1_i323 < 9; c1_i323++) {
        c1_c_modelParams[c1_i323] = c1_modelParams[c1_i323];
      }

      c1_i325 = c1_b_allPoints->size[0] * c1_b_allPoints->size[1] *
        c1_b_allPoints->size[2];
      c1_b_allPoints->size[0] = c1_allPoints->size[0];
      c1_b_allPoints->size[1] = c1_allPoints->size[1];
      c1_b_allPoints->size[2] = 2;
      c1_emxEnsureCapacity_real32_T2(chartInstance, c1_b_allPoints, c1_i325,
        &c1_je_emlrtRTEI);
      c1_j_allPoints = c1_b_allPoints->size[0];
      c1_k_allPoints = c1_b_allPoints->size[1];
      c1_l_allPoints = c1_b_allPoints->size[2];
      c1_j_loop_ub = c1_allPoints->size[0] * c1_allPoints->size[1] *
        c1_allPoints->size[2] - 1;
      for (c1_i327 = 0; c1_i327 <= c1_j_loop_ub; c1_i327++) {
        c1_b_allPoints->data[c1_i327] = c1_allPoints->data[c1_i327];
      }

      c1_evaluateTForm(chartInstance, c1_c_modelParams, c1_b_allPoints, c1_dis);
      c1_c_end = c1_dis->size[0] - 1;
      for (c1_e_i = 0; c1_e_i <= c1_c_end; c1_e_i++) {
        if (c1_dis->data[c1_e_i] > 4.0F) {
          c1_dis->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, c1_e_i + 1, 1,
            c1_dis->size[0]) - 1] = 4.0F;
        }
      }

      c1_i329 = c1_c_dis->size[0];
      c1_c_dis->size[0] = c1_dis->size[0];
      c1_emxEnsureCapacity_real32_T1(chartInstance, c1_c_dis, c1_i329,
        &c1_ie_emlrtRTEI);
      c1_l_loop_ub = c1_dis->size[0] - 1;
      for (c1_i331 = 0; c1_i331 <= c1_l_loop_ub; c1_i331++) {
        c1_c_dis->data[c1_i331] = c1_dis->data[c1_i331];
      }

      c1_accDis = c1_sum(chartInstance, c1_c_dis);
      if (c1_accDis < c1_bestDis) {
        c1_bestDis = c1_accDis;
        c1_i333 = c1_bestInliers->size[0];
        c1_bestInliers->size[0] = c1_dis->size[0];
        c1_emxEnsureCapacity_boolean_T(chartInstance, c1_bestInliers, c1_i333,
          &c1_oe_emlrtRTEI);
        c1_m_loop_ub = c1_dis->size[0] - 1;
        for (c1_i335 = 0; c1_i335 <= c1_m_loop_ub; c1_i335++) {
          c1_bestInliers->data[c1_i335] = (c1_dis->data[c1_i335] < 4.0F);
        }

        c1_bestModelParams_size[0] = 3;
        c1_bestModelParams_size[1] = 3;
        c1_g_bestModelParams = c1_bestModelParams_size[0];
        c1_h_bestModelParams = c1_bestModelParams_size[1];
        for (c1_i338 = 0; c1_i338 < 9; c1_i338++) {
          c1_bestModelParams_data[c1_i338] = c1_modelParams[c1_i338];
        }

        c1_i340 = c1_b_dis->size[0];
        c1_b_dis->size[0] = c1_dis->size[0];
        c1_emxEnsureCapacity_boolean_T(chartInstance, c1_b_dis, c1_i340,
          &c1_qe_emlrtRTEI);
        c1_q_loop_ub = c1_dis->size[0] - 1;
        for (c1_i343 = 0; c1_i343 <= c1_q_loop_ub; c1_i343++) {
          c1_b_dis->data[c1_i343] = (c1_dis->data[c1_i343] < 4.0F);
        }

        c1_inlierNum = (real32_T)c1_b_sum(chartInstance, c1_b_dis);
        c1_inlierProbability = muSingleScalarPower(c1_inlierNum / (real32_T)
          c1_b_numPts, 2.0F);
        if (c1_inlierProbability < 1.1920929E-7F) {
          c1_num = MAX_int32_T;
        } else {
          c1_p = (1.0F - c1_inlierProbability < 0.0F);
          if (c1_p) {
            c1_i_error(chartInstance);
          }

          c1_f0 = muSingleScalarRound(muSingleScalarCeil(-1.99999785F /
            muSingleScalarLog10(1.0F - c1_inlierProbability)));
          if (c1_f0 < 2.14748365E+9F) {
            if (c1_f0 >= -2.14748365E+9F) {
              c1_i344 = (int32_T)c1_f0;
            } else {
              c1_i344 = MIN_int32_T;
              _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
            }
          } else if (c1_f0 >= 2.14748365E+9F) {
            c1_i344 = MAX_int32_T;
            _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
          } else {
            c1_i344 = 0;
          }

          c1_num = c1_i344;
        }

        c1_numTrials = muIntScalarMin_sint32(c1_numTrials, c1_num);
      }

      c1_idxTrial++;
    } else {
      c1_skipTrials++;
    }
  }

  c1_emxFree_real32_T(chartInstance, &c1_samplePoints);
  c1_emxFree_real32_T(chartInstance, &c1_b_allPoints);
  c1_emxFree_real32_T(chartInstance, &c1_c_dis);
  c1_emxFree_boolean_T(chartInstance, &c1_b_dis);
  c1_b_bestModelParams_size[0] = c1_bestModelParams_size[0];
  c1_b_bestModelParams_size[1] = c1_bestModelParams_size[1];
  c1_c_bestModelParams = c1_b_bestModelParams_size[0];
  c1_d_bestModelParams = c1_b_bestModelParams_size[1];
  c1_b_loop_ub = c1_bestModelParams_size[0] * c1_bestModelParams_size[1] - 1;
  for (c1_i298 = 0; c1_i298 <= c1_b_loop_ub; c1_i298++) {
    c1_b_bestModelParams_data[c1_i298] = c1_bestModelParams_data[c1_i298];
  }

  c1_emxInit_boolean_T(chartInstance, &c1_b_bestInliers, 1, &c1_wd_emlrtRTEI);
  if (c1_checkTForm(chartInstance, c1_b_bestModelParams_data,
                    c1_b_bestModelParams_size) && (!(c1_bestInliers->size[0] ==
        0))) {
    c1_i300 = c1_b_bestInliers->size[0];
    c1_b_bestInliers->size[0] = c1_bestInliers->size[0];
    c1_emxEnsureCapacity_boolean_T(chartInstance, c1_b_bestInliers, c1_i300,
      &c1_wd_emlrtRTEI);
    c1_c_loop_ub = c1_bestInliers->size[0] - 1;
    for (c1_i302 = 0; c1_i302 <= c1_c_loop_ub; c1_i302++) {
      c1_b_bestInliers->data[c1_i302] = c1_bestInliers->data[c1_i302];
    }

    if (c1_b_sum(chartInstance, c1_b_bestInliers) >= 2.0) {
      c1_b_isFound = true;
    } else {
      c1_b_isFound = false;
    }
  } else {
    c1_b_isFound = false;
  }

  c1_emxFree_boolean_T(chartInstance, &c1_b_bestInliers);
  c1_c_isFound = c1_b_isFound;
  c1_emxInit_int32_T(chartInstance, &c1_r9, 1, &c1_re_emlrtRTEI);
  c1_emxInit_boolean_T(chartInstance, &c1_b_inliers, 1, &c1_me_emlrtRTEI);
  c1_emxInit_real32_T1(chartInstance, &c1_d_dis, 1, &c1_ie_emlrtRTEI);
  c1_emxInit_real32_T2(chartInstance, &c1_d_allPoints, 3, &c1_he_emlrtRTEI);
  c1_emxInit_real32_T2(chartInstance, &c1_e_allPoints, 3, &c1_fe_emlrtRTEI);
  if (c1_b_isFound) {
    c1_end = c1_bestInliers->size[0] - 1;
    c1_trueCount = 0;
    for (c1_i = 0; c1_i <= c1_end; c1_i++) {
      if (c1_bestInliers->data[c1_i]) {
        c1_trueCount++;
      }
    }

    c1_i312 = c1_r9->size[0];
    c1_r9->size[0] = c1_trueCount;
    c1_emxEnsureCapacity_int32_T(chartInstance, c1_r9, c1_i312, &c1_be_emlrtRTEI);
    c1_partialTrueCount = 0;
    for (c1_b_i = 0; c1_b_i <= c1_end; c1_b_i++) {
      if (c1_bestInliers->data[c1_b_i]) {
        c1_r9->data[c1_partialTrueCount] = c1_b_i + 1;
        c1_partialTrueCount++;
      }
    }

    c1_f_allPoints = c1_allPoints->size[0];
    c1_i315 = c1_allPoints->size[1];
    c1_i316 = c1_e_allPoints->size[0] * c1_e_allPoints->size[1] *
      c1_e_allPoints->size[2];
    c1_e_allPoints->size[0] = c1_r9->size[0];
    c1_e_allPoints->size[1] = c1_i315;
    c1_e_allPoints->size[2] = 2;
    c1_emxEnsureCapacity_real32_T2(chartInstance, c1_e_allPoints, c1_i316,
      &c1_fe_emlrtRTEI);
    for (c1_i319 = 0; c1_i319 < 2; c1_i319++) {
      c1_g_loop_ub = c1_i315 - 1;
      for (c1_i321 = 0; c1_i321 <= c1_g_loop_ub; c1_i321++) {
        c1_h_loop_ub = c1_r9->size[0] - 1;
        for (c1_i324 = 0; c1_i324 <= c1_h_loop_ub; c1_i324++) {
          c1_e_allPoints->data[(c1_i324 + c1_e_allPoints->size[0] * c1_i321) +
            c1_e_allPoints->size[0] * c1_e_allPoints->size[1] * c1_i319] =
            c1_allPoints->data[((sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, c1_r9->data[c1_i324], 1, c1_f_allPoints) +
            c1_allPoints->size[0] * c1_i321) + c1_allPoints->size[0] *
                                c1_allPoints->size[1] * c1_i319) - 1];
        }
      }
    }

    c1_computeSimilarity(chartInstance, c1_e_allPoints, c1_modelParams);
    for (c1_i320 = 0; c1_i320 < 9; c1_i320++) {
      c1_b_modelParams[c1_i320] = c1_modelParams[c1_i320];
    }

    c1_i322 = c1_d_allPoints->size[0] * c1_d_allPoints->size[1] *
      c1_d_allPoints->size[2];
    c1_d_allPoints->size[0] = c1_allPoints->size[0];
    c1_d_allPoints->size[1] = c1_allPoints->size[1];
    c1_d_allPoints->size[2] = 2;
    c1_emxEnsureCapacity_real32_T2(chartInstance, c1_d_allPoints, c1_i322,
      &c1_he_emlrtRTEI);
    c1_g_allPoints = c1_d_allPoints->size[0];
    c1_h_allPoints = c1_d_allPoints->size[1];
    c1_i_allPoints = c1_d_allPoints->size[2];
    c1_i_loop_ub = c1_allPoints->size[0] * c1_allPoints->size[1] *
      c1_allPoints->size[2] - 1;
    for (c1_i326 = 0; c1_i326 <= c1_i_loop_ub; c1_i326++) {
      c1_d_allPoints->data[c1_i326] = c1_allPoints->data[c1_i326];
    }

    c1_evaluateTForm(chartInstance, c1_b_modelParams, c1_d_allPoints, c1_dis);
    c1_b_end = c1_dis->size[0] - 1;
    for (c1_d_i = 0; c1_d_i <= c1_b_end; c1_d_i++) {
      if (c1_dis->data[c1_d_i] > 4.0F) {
        c1_dis->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, c1_d_i + 1, 1, c1_dis->size
          [0]) - 1] = 4.0F;
      }
    }

    c1_i328 = c1_d_dis->size[0];
    c1_d_dis->size[0] = c1_dis->size[0];
    c1_emxEnsureCapacity_real32_T1(chartInstance, c1_d_dis, c1_i328,
      &c1_ie_emlrtRTEI);
    c1_k_loop_ub = c1_dis->size[0] - 1;
    for (c1_i330 = 0; c1_i330 <= c1_k_loop_ub; c1_i330++) {
      c1_d_dis->data[c1_i330] = c1_dis->data[c1_i330];
    }

    c1_sum(chartInstance, c1_d_dis);
    c1_bestModelParams_size[0] = 3;
    c1_bestModelParams_size[1] = 3;
    c1_e_bestModelParams = c1_bestModelParams_size[0];
    c1_f_bestModelParams = c1_bestModelParams_size[1];
    for (c1_i332 = 0; c1_i332 < 9; c1_i332++) {
      c1_bestModelParams_data[c1_i332] = c1_modelParams[c1_i332];
    }

    c1_isValidModel = c1_checkTForm(chartInstance, c1_modelParams, c1_iv5);
    c1_i334 = c1_inliers->size[0];
    c1_inliers->size[0] = c1_dis->size[0];
    c1_emxEnsureCapacity_boolean_T(chartInstance, c1_inliers, c1_i334,
      &c1_le_emlrtRTEI);
    c1_n_loop_ub = c1_dis->size[0] - 1;
    for (c1_i336 = 0; c1_i336 <= c1_n_loop_ub; c1_i336++) {
      c1_inliers->data[c1_i336] = (c1_dis->data[c1_i336] < 4.0F);
    }

    guard1 = false;
    if (!c1_isValidModel) {
      guard1 = true;
    } else {
      c1_i337 = c1_b_inliers->size[0];
      c1_b_inliers->size[0] = c1_inliers->size[0];
      c1_emxEnsureCapacity_boolean_T(chartInstance, c1_b_inliers, c1_i337,
        &c1_me_emlrtRTEI);
      c1_o_loop_ub = c1_inliers->size[0] - 1;
      for (c1_i341 = 0; c1_i341 <= c1_o_loop_ub; c1_i341++) {
        c1_b_inliers->data[c1_i341] = c1_inliers->data[c1_i341];
      }

      if (!c1_any(chartInstance, c1_b_inliers)) {
        guard1 = true;
      }
    }

    if (guard1) {
      c1_c_isFound = false;
      c1_i339 = c1_inliers->size[0];
      c1_inliers->size[0] = c1_allPoints->size[0];
      c1_emxEnsureCapacity_boolean_T(chartInstance, c1_inliers, c1_i339,
        &c1_ne_emlrtRTEI);
      c1_p_loop_ub = c1_allPoints->size[0] - 1;
      for (c1_i342 = 0; c1_i342 <= c1_p_loop_ub; c1_i342++) {
        c1_inliers->data[c1_i342] = false;
      }
    }
  } else {
    c1_i307 = c1_inliers->size[0];
    c1_inliers->size[0] = c1_allPoints->size[0];
    c1_emxEnsureCapacity_boolean_T(chartInstance, c1_inliers, c1_i307,
      &c1_xd_emlrtRTEI);
    c1_e_loop_ub = c1_allPoints->size[0] - 1;
    for (c1_i311 = 0; c1_i311 <= c1_e_loop_ub; c1_i311++) {
      c1_inliers->data[c1_i311] = false;
    }
  }

  c1_emxFree_real32_T(chartInstance, &c1_e_allPoints);
  c1_emxFree_real32_T(chartInstance, &c1_d_allPoints);
  c1_emxFree_real32_T(chartInstance, &c1_d_dis);
  c1_emxFree_boolean_T(chartInstance, &c1_b_inliers);
  c1_emxFree_real32_T(chartInstance, &c1_dis);
  c1_emxFree_int32_T(chartInstance, &c1_r9);
  c1_emxFree_boolean_T(chartInstance, &c1_bestInliers);
  *c1_isFound = c1_c_isFound;
}

static real_T c1_rand(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  int32_T c1_i345;
  real_T c1_d12;
  uint32_T c1_b_r;
  int32_T c1_mti;
  real_T c1_d13;
  uint32_T c1_u5;
  if (!chartInstance->c1_method_not_empty) {
    chartInstance->c1_method = 7U;
    chartInstance->c1_method_not_empty = true;
  }

  if (!chartInstance->c1_c_state_not_empty) {
    for (c1_i345 = 0; c1_i345 < 625; c1_i345++) {
      chartInstance->c1_c_state[c1_i345] = 0U;
    }

    c1_b_r = 5489U;
    chartInstance->c1_c_state[0] = 5489U;
    for (c1_mti = 0; c1_mti < 623; c1_mti++) {
      c1_d13 = muDoubleScalarRound((2.0 + (real_T)c1_mti) - 1.0);
      if (c1_d13 < 4.294967296E+9) {
        if (c1_d13 >= 0.0) {
          c1_u5 = (uint32_T)c1_d13;
        } else {
          c1_u5 = 0U;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
        }
      } else if (c1_d13 >= 4.294967296E+9) {
        c1_u5 = MAX_uint32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      } else {
        c1_u5 = 0U;
      }

      c1_b_r = (c1_b_r ^ c1_b_r >> 30U) * 1812433253U + c1_u5;
      chartInstance->c1_c_state[c1_mti + 1] = c1_b_r;
    }

    chartInstance->c1_c_state[624] = 624U;
    chartInstance->c1_c_state_not_empty = true;
  }

  c1_d12 = c1_b_eml_rand_mt19937ar(chartInstance, chartInstance->c1_c_state);
  return c1_d12;
}

static void c1_eml_rand_mt19937ar(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, uint32_T c1_d_state[625], uint32_T c1_e_state[625], real_T
  *c1_r)
{
  int32_T c1_i346;
  for (c1_i346 = 0; c1_i346 < 625; c1_i346++) {
    c1_e_state[c1_i346] = c1_d_state[c1_i346];
  }

  *c1_r = c1_b_eml_rand_mt19937ar(chartInstance, c1_e_state);
}

static void c1_d_error(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  const mxArray *c1_y = NULL;
  static char_T c1_cv57[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv57, 10, 0U, 1U, 0U, 2, 1, 37),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c1_y));
}

static real_T c1_mod(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
                     real_T c1_x, real_T c1_y)
{
  real_T c1_r;
  (void)chartInstance;
  (void)c1_y;
  if ((!muDoubleScalarIsInf(c1_x)) && (!muDoubleScalarIsNaN(c1_x))) {
    if (c1_x == 0.0) {
      c1_r = 0.0;
    } else {
      c1_r = muDoubleScalarRem(c1_x, 2.0);
      if (c1_r == 0.0) {
        c1_r = 0.0;
      }
    }
  } else {
    c1_r = rtNaN;
  }

  return c1_r;
}

static void c1_computeSimilarity(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T *c1_points, real32_T c1_T[9])
{
  c1_emxArray_real32_T *c1_b_points;
  int32_T c1_i347;
  int32_T c1_c_points;
  int32_T c1_d_points;
  int32_T c1_e_points;
  int32_T c1_loop_ub;
  int32_T c1_i348;
  c1_emxArray_real32_T *c1_constraints;
  c1_emxArray_real32_T *c1_points1;
  c1_emxArray_real32_T *c1_points2;
  real32_T c1_normMatrix1[9];
  real32_T c1_normMatrix2[9];
  int32_T c1_i349;
  int32_T c1_b_constraints;
  int32_T c1_c_constraints;
  int32_T c1_b_loop_ub;
  int32_T c1_i350;
  real_T c1_d14;
  int32_T c1_iv6[2];
  int32_T c1_i351;
  int32_T c1_i352;
  c1_emxArray_int32_T *c1_r10;
  int32_T c1_iv7[2];
  int32_T c1_i353;
  int32_T c1_c_loop_ub;
  int32_T c1_i354;
  c1_emxArray_real32_T *c1_varargin_1;
  int32_T c1_i355;
  int32_T c1_i356;
  int32_T c1_d_loop_ub;
  int32_T c1_i357;
  c1_emxArray_real_T *c1_varargin_4;
  int32_T c1_i358;
  int32_T c1_e_loop_ub;
  int32_T c1_i359;
  boolean_T c1_b18;
  const mxArray *c1_y = NULL;
  int32_T c1_i360;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  int32_T c1_i361;
  const mxArray *c1_e_y = NULL;
  c1_emxArray_real32_T *c1_r11;
  int32_T c1_i362;
  int32_T c1_b_points1[1];
  int32_T c1_i363;
  int32_T c1_i364;
  int32_T c1_f_loop_ub;
  int32_T c1_i365;
  int32_T c1_g_loop_ub;
  int32_T c1_i366;
  int32_T c1_h_loop_ub;
  int32_T c1_i367;
  int32_T c1_i_loop_ub;
  int32_T c1_i368;
  int32_T c1_j_loop_ub;
  int32_T c1_i369;
  int32_T c1_iv8[2];
  int32_T c1_i370;
  int32_T c1_k_loop_ub;
  real_T c1_d15;
  int32_T c1_i371;
  int32_T c1_i372;
  int32_T c1_i373;
  int32_T c1_i374;
  int32_T c1_i375;
  int32_T c1_l_loop_ub;
  int32_T c1_i376;
  int32_T c1_i377;
  int32_T c1_i378;
  int32_T c1_m_loop_ub;
  int32_T c1_i379;
  int32_T c1_result;
  boolean_T c1_b19;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  const mxArray *c1_h_y = NULL;
  const mxArray *c1_i_y = NULL;
  boolean_T c1_empty_non_axis_sizes;
  int32_T c1_b_result;
  c1_cell_19 c1_reshapes;
  int32_T c1_i380;
  int32_T c1_b_reshapes;
  int32_T c1_c_reshapes;
  int32_T c1_n_loop_ub;
  int32_T c1_i381;
  int32_T c1_c_result;
  int32_T c1_i382;
  int32_T c1_d_reshapes;
  int32_T c1_e_reshapes;
  int32_T c1_o_loop_ub;
  int32_T c1_i383;
  int32_T c1_d_result;
  int32_T c1_i384;
  int32_T c1_f_reshapes;
  int32_T c1_g_reshapes;
  int32_T c1_p_loop_ub;
  int32_T c1_i385;
  int32_T c1_e_result;
  c1_emxArray_real32_T *c1_U1;
  int32_T c1_f_result[2];
  int32_T c1_i386;
  int32_T c1_q_loop_ub;
  int32_T c1_i387;
  int32_T c1_r_loop_ub;
  int32_T c1_s_loop_ub;
  int32_T c1_i388;
  int32_T c1_i389;
  int32_T c1_t_loop_ub;
  int32_T c1_u_loop_ub;
  int32_T c1_i390;
  int32_T c1_i391;
  int32_T c1_v_loop_ub;
  int32_T c1_w_loop_ub;
  int32_T c1_i392;
  int32_T c1_i393;
  int32_T c1_x_loop_ub;
  int32_T c1_i394;
  int32_T c1_iv9[2];
  int32_T c1_iv10[2];
  int32_T c1_i395;
  int32_T c1_y_loop_ub;
  int32_T c1_nx;
  int32_T c1_i396;
  boolean_T c1_p;
  boolean_T c1_overflow;
  int32_T c1_k;
  int32_T c1_i397;
  real32_T c1_s1_data[5];
  int32_T c1_s1_size[1];
  real32_T c1_V1[25];
  boolean_T c1_b_p;
  c1_emxArray_real32_T *c1_r12;
  real_T c1_dv3[2];
  int32_T c1_i398;
  real32_T c1_B;
  int32_T c1_i399;
  int32_T c1_i400;
  int32_T c1_i401;
  int32_T c1_ab_loop_ub;
  int32_T c1_i402;
  int32_T c1_i403;
  int32_T c1_i404;
  int32_T c1_i405;
  int32_T c1_i406;
  int32_T c1_r1;
  int32_T c1_i407;
  int32_T c1_r2;
  int32_T c1_i408;
  int32_T c1_r3;
  real32_T c1_maxval;
  real32_T c1_b_B[9];
  real32_T c1_a21;
  int32_T c1_rtemp;
  int32_T c1_b_k;
  int32_T c1_i409;
  int32_T c1_i410;
  real32_T c1_b_T;
  int32_T c1_i411;
  int32_T c1_i412;
  int32_T c1_i413;
  int32_T c1_i414;
  c1_emxInit_real32_T2(chartInstance, &c1_b_points, 3, &c1_te_emlrtRTEI);
  c1_i347 = c1_b_points->size[0] * c1_b_points->size[1] * c1_b_points->size[2];
  c1_b_points->size[0] = c1_points->size[0];
  c1_b_points->size[1] = c1_points->size[1];
  c1_b_points->size[2] = 2;
  c1_emxEnsureCapacity_real32_T2(chartInstance, c1_b_points, c1_i347,
    &c1_te_emlrtRTEI);
  c1_c_points = c1_b_points->size[0];
  c1_d_points = c1_b_points->size[1];
  c1_e_points = c1_b_points->size[2];
  c1_loop_ub = c1_points->size[0] * c1_points->size[1] * c1_points->size[2] - 1;
  for (c1_i348 = 0; c1_i348 <= c1_loop_ub; c1_i348++) {
    c1_b_points->data[c1_i348] = c1_points->data[c1_i348];
  }

  c1_emxInit_real32_T(chartInstance, &c1_constraints, 2, &c1_ue_emlrtRTEI);
  c1_emxInit_real32_T(chartInstance, &c1_points1, 2, &c1_ff_emlrtRTEI);
  c1_emxInit_real32_T(chartInstance, &c1_points2, 2, &c1_ff_emlrtRTEI);
  c1_normalizePoints(chartInstance, c1_b_points, c1_points1, c1_points2,
                     c1_normMatrix1, c1_normMatrix2);
  c1_i349 = c1_constraints->size[0] * c1_constraints->size[1];
  c1_constraints->size[0] = (int32_T)sf_integer_check(chartInstance->S, 1U, 0U,
    0U, 2.0 * (real_T)c1_points1->size[0]);
  c1_constraints->size[1] = 5;
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_constraints, c1_i349,
    &c1_ue_emlrtRTEI);
  c1_b_constraints = c1_constraints->size[0];
  c1_c_constraints = c1_constraints->size[1];
  c1_b_loop_ub = (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U, 2.0 *
    (real_T)c1_points1->size[0]) * 5 - 1;
  c1_emxFree_real32_T(chartInstance, &c1_b_points);
  for (c1_i350 = 0; c1_i350 <= c1_b_loop_ub; c1_i350++) {
    c1_constraints->data[c1_i350] = 0.0F;
  }

  c1_d14 = 2.0 * (real_T)c1_points1->size[0];
  if (1.0 > c1_d14) {
    c1_i351 = 1;
    c1_i352 = 0;
  } else {
    c1_iv6[0] = (int32_T)(2.0 * (real_T)c1_points1->size[0]);
    c1_iv6[1] = 5;
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c1_iv6[0]);
    c1_i351 = 2;
    c1_iv7[0] = (int32_T)(2.0 * (real_T)c1_points1->size[0]);
    c1_iv7[1] = 5;
    c1_i352 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c1_d14, 1, c1_iv7[0]);
  }

  c1_emxInit_int32_T(chartInstance, &c1_r10, 1, &c1_ff_emlrtRTEI);
  c1_i353 = c1_r10->size[0];
  c1_r10->size[0] = c1_div_s32_floor(chartInstance, c1_i352 - 1, c1_i351, 1U, 0U,
    0U) + 1;
  c1_emxEnsureCapacity_int32_T(chartInstance, c1_r10, c1_i353, &c1_ve_emlrtRTEI);
  c1_c_loop_ub = c1_div_s32_floor(chartInstance, c1_i352 - 1, c1_i351, 1U, 0U,
    0U);
  for (c1_i354 = 0; c1_i354 <= c1_c_loop_ub; c1_i354++) {
    c1_r10->data[c1_i354] = c1_i351 * c1_i354;
  }

  c1_emxInit_real32_T1(chartInstance, &c1_varargin_1, 1, &c1_we_emlrtRTEI);
  c1_i355 = c1_points1->size[0];
  c1_i356 = c1_varargin_1->size[0];
  c1_varargin_1->size[0] = c1_i355;
  c1_emxEnsureCapacity_real32_T1(chartInstance, c1_varargin_1, c1_i356,
    &c1_we_emlrtRTEI);
  c1_d_loop_ub = c1_i355 - 1;
  for (c1_i357 = 0; c1_i357 <= c1_d_loop_ub; c1_i357++) {
    c1_varargin_1->data[c1_i357] = -c1_points1->data[c1_i357 + c1_points1->size
      [0]];
  }

  c1_emxInit_real_T1(chartInstance, &c1_varargin_4, 1, &c1_xe_emlrtRTEI);
  c1_i358 = c1_varargin_4->size[0];
  c1_varargin_4->size[0] = c1_points1->size[0];
  c1_emxEnsureCapacity_real_T1(chartInstance, c1_varargin_4, c1_i358,
    &c1_xe_emlrtRTEI);
  c1_e_loop_ub = c1_points1->size[0] - 1;
  for (c1_i359 = 0; c1_i359 <= c1_e_loop_ub; c1_i359++) {
    c1_varargin_4->data[c1_i359] = -1.0;
  }

  c1_b18 = true;
  if (c1_b18) {
  } else {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv10, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_y));
  }

  c1_i360 = c1_points1->size[0];
  if (c1_i360 == c1_varargin_1->size[0]) {
  } else {
    c1_b18 = false;
  }

  if (c1_b18) {
  } else {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv10, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_b_y));
  }

  c1_b18 = (c1_points1->size[0] == c1_varargin_1->size[0]);
  if (c1_b18) {
  } else {
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv10, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_c_y));
  }

  c1_b18 = (c1_varargin_4->size[0] == c1_varargin_1->size[0]);
  if (c1_b18) {
  } else {
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_cv10, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_d_y));
  }

  c1_i361 = c1_points2->size[0];
  c1_b18 = (c1_i361 == c1_varargin_1->size[0]);
  if (c1_b18) {
  } else {
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_cv10, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_e_y));
  }

  c1_emxInit_real32_T(chartInstance, &c1_r11, 2, &c1_ff_emlrtRTEI);
  c1_i362 = c1_points1->size[0];
  c1_b_points1[0] = c1_points1->size[0];
  c1_i363 = c1_points2->size[0];
  c1_i364 = c1_r11->size[0] * c1_r11->size[1];
  c1_r11->size[0] = c1_varargin_1->size[0];
  c1_r11->size[1] = 5;
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_r11, c1_i364, &c1_ye_emlrtRTEI);
  c1_f_loop_ub = c1_varargin_1->size[0] - 1;
  for (c1_i365 = 0; c1_i365 <= c1_f_loop_ub; c1_i365++) {
    c1_r11->data[c1_i365] = c1_varargin_1->data[c1_i365];
  }

  c1_g_loop_ub = c1_i362 - 1;
  for (c1_i366 = 0; c1_i366 <= c1_g_loop_ub; c1_i366++) {
    c1_r11->data[c1_i366 + c1_r11->size[0]] = c1_points1->data[c1_i366];
  }

  c1_h_loop_ub = c1_b_points1[0] - 1;
  for (c1_i367 = 0; c1_i367 <= c1_h_loop_ub; c1_i367++) {
    c1_r11->data[c1_i367 + (c1_r11->size[0] << 1)] = 0.0F;
  }

  c1_i_loop_ub = c1_varargin_4->size[0] - 1;
  for (c1_i368 = 0; c1_i368 <= c1_i_loop_ub; c1_i368++) {
    c1_r11->data[c1_i368 + c1_r11->size[0] * 3] = (real32_T)c1_varargin_4->
      data[c1_i368];
  }

  c1_emxFree_real_T(chartInstance, &c1_varargin_4);
  c1_j_loop_ub = c1_i363 - 1;
  for (c1_i369 = 0; c1_i369 <= c1_j_loop_ub; c1_i369++) {
    c1_r11->data[c1_i369 + (c1_r11->size[0] << 2)] = c1_points2->data[c1_i369 +
      c1_points2->size[0]];
  }

  c1_iv8[0] = c1_r10->size[0];
  c1_iv8[1] = 5;
  _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c1_iv8, 2, *(int32_T (*)[2])c1_r11->size, 2);
  for (c1_i370 = 0; c1_i370 < 5; c1_i370++) {
    c1_k_loop_ub = c1_r11->size[0] - 1;
    for (c1_i371 = 0; c1_i371 <= c1_k_loop_ub; c1_i371++) {
      c1_constraints->data[c1_r10->data[c1_i371] + c1_constraints->size[0] *
        c1_i370] = c1_r11->data[c1_i371 + c1_r11->size[0] * c1_i370];
    }
  }

  c1_emxFree_real32_T(chartInstance, &c1_r11);
  c1_d15 = 2.0 * (real_T)c1_points1->size[0];
  if (2.0 > c1_d15) {
    c1_i372 = 1;
    c1_i373 = 1;
    c1_i374 = 0;
  } else {
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, 2, 1, c1_constraints->size[0]);
    c1_i372 = 2;
    c1_i373 = 2;
    c1_i374 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c1_d15, 1,
      c1_constraints->size[0]);
  }

  c1_i375 = c1_r10->size[0];
  c1_r10->size[0] = c1_div_s32_floor(chartInstance, c1_i374 - c1_i372, c1_i373,
    1U, 0U, 0U) + 1;
  c1_emxEnsureCapacity_int32_T(chartInstance, c1_r10, c1_i375, &c1_af_emlrtRTEI);
  c1_l_loop_ub = c1_div_s32_floor(chartInstance, c1_i374 - c1_i372, c1_i373, 1U,
    0U, 0U);
  for (c1_i376 = 0; c1_i376 <= c1_l_loop_ub; c1_i376++) {
    c1_r10->data[c1_i376] = (c1_i372 + c1_i373 * c1_i376) - 1;
  }

  c1_i377 = c1_points2->size[0];
  c1_i378 = c1_varargin_1->size[0];
  c1_varargin_1->size[0] = c1_i377;
  c1_emxEnsureCapacity_real32_T1(chartInstance, c1_varargin_1, c1_i378,
    &c1_bf_emlrtRTEI);
  c1_m_loop_ub = c1_i377 - 1;
  for (c1_i379 = 0; c1_i379 <= c1_m_loop_ub; c1_i379++) {
    c1_varargin_1->data[c1_i379] = -c1_points2->data[c1_i379];
  }

  c1_emxFree_real32_T(chartInstance, &c1_points2);
  if (!((c1_points1->size[0] == 0) || (c1_points1->size[1] == 0))) {
    c1_result = c1_points1->size[0];
  } else if (!(c1_points1->size[0] == 0)) {
    c1_result = c1_points1->size[0];
  } else if (!(c1_points1->size[0] == 0)) {
    c1_result = c1_points1->size[0];
  } else if (!(c1_varargin_1->size[0] == 0)) {
    c1_result = c1_varargin_1->size[0];
  } else {
    c1_result = (int32_T)sf_MAX(c1_points1->size[0], 0);
    if (c1_points1->size[0] > c1_result) {
      c1_result = c1_points1->size[0];
    }

    if (c1_points1->size[0] > c1_result) {
      c1_result = c1_points1->size[0];
    }

    if (c1_varargin_1->size[0] > c1_result) {
      c1_result = c1_varargin_1->size[0];
    }
  }

  if ((c1_points1->size[0] == c1_result) || ((c1_points1->size[0] == 0) ||
       (c1_points1->size[1] == 0))) {
    c1_b19 = true;
  } else {
    c1_b19 = false;
  }

  if (c1_b19) {
  } else {
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_cv10, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_f_y));
  }

  if ((c1_points1->size[0] == c1_result) || (c1_points1->size[0] == 0)) {
    c1_b19 = true;
  } else {
    c1_b19 = false;
  }

  if (c1_b19) {
  } else {
    c1_g_y = NULL;
    sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_cv10, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_g_y));
  }

  if ((c1_points1->size[0] == c1_result) || (c1_points1->size[0] == 0)) {
    c1_b19 = true;
  } else {
    c1_b19 = false;
  }

  if (c1_b19) {
  } else {
    c1_h_y = NULL;
    sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_cv10, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_h_y));
  }

  if ((c1_varargin_1->size[0] == c1_result) || (c1_varargin_1->size[0] == 0)) {
    c1_b19 = true;
  } else {
    c1_b19 = false;
  }

  if (c1_b19) {
  } else {
    c1_i_y = NULL;
    sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_cv10, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_i_y));
  }

  c1_empty_non_axis_sizes = (c1_result == 0);
  if (c1_empty_non_axis_sizes || (!((c1_points1->size[0] == 0) ||
        (c1_points1->size[1] == 0)))) {
    c1_b_result = c1_points1->size[1];
  } else {
    c1_b_result = 0;
  }

  c1_emxInitStruct_cell_19(chartInstance, &c1_reshapes, &c1_gf_emlrtRTEI);
  c1_i380 = c1_reshapes.f1->size[0] * c1_reshapes.f1->size[1];
  c1_reshapes.f1->size[0] = c1_result;
  c1_reshapes.f1->size[1] = c1_b_result;
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_reshapes.f1, c1_i380,
    &c1_cf_emlrtRTEI);
  c1_b_reshapes = c1_reshapes.f1->size[0];
  c1_c_reshapes = c1_reshapes.f1->size[1];
  c1_n_loop_ub = c1_result * c1_b_result - 1;
  for (c1_i381 = 0; c1_i381 <= c1_n_loop_ub; c1_i381++) {
    c1_reshapes.f1->data[c1_i381] = c1_points1->data[c1_i381];
  }

  if (c1_empty_non_axis_sizes || (!(c1_points1->size[0] == 0))) {
    c1_c_result = 1;
  } else {
    c1_c_result = 0;
  }

  c1_i382 = c1_reshapes.f2->size[0] * c1_reshapes.f2->size[1];
  c1_reshapes.f2->size[0] = c1_result;
  c1_reshapes.f2->size[1] = c1_c_result;
  c1_emxEnsureCapacity_real_T(chartInstance, c1_reshapes.f2, c1_i382,
    &c1_cf_emlrtRTEI);
  c1_d_reshapes = c1_reshapes.f2->size[0];
  c1_e_reshapes = c1_reshapes.f2->size[1];
  c1_o_loop_ub = c1_result * c1_c_result - 1;
  for (c1_i383 = 0; c1_i383 <= c1_o_loop_ub; c1_i383++) {
    c1_reshapes.f2->data[c1_i383] = 1.0;
  }

  if (c1_empty_non_axis_sizes || (!(c1_points1->size[0] == 0))) {
    c1_d_result = 1;
  } else {
    c1_d_result = 0;
  }

  c1_emxFree_real32_T(chartInstance, &c1_points1);
  c1_i384 = c1_reshapes.f3->size[0] * c1_reshapes.f3->size[1];
  c1_reshapes.f3->size[0] = c1_result;
  c1_reshapes.f3->size[1] = c1_d_result;
  c1_emxEnsureCapacity_real_T(chartInstance, c1_reshapes.f3, c1_i384,
    &c1_cf_emlrtRTEI);
  c1_f_reshapes = c1_reshapes.f3->size[0];
  c1_g_reshapes = c1_reshapes.f3->size[1];
  c1_p_loop_ub = c1_result * c1_d_result - 1;
  for (c1_i385 = 0; c1_i385 <= c1_p_loop_ub; c1_i385++) {
    c1_reshapes.f3->data[c1_i385] = 0.0;
  }

  if (c1_empty_non_axis_sizes || (!(c1_varargin_1->size[0] == 0))) {
    c1_e_result = 1;
  } else {
    c1_e_result = 0;
  }

  c1_emxInit_real32_T(chartInstance, &c1_U1, 2, &c1_ff_emlrtRTEI);
  c1_f_result[0] = c1_result;
  c1_f_result[1] = c1_e_result;
  c1_i386 = c1_U1->size[0] * c1_U1->size[1];
  c1_U1->size[0] = c1_reshapes.f1->size[0];
  c1_U1->size[1] = ((c1_reshapes.f1->size[1] + c1_reshapes.f2->size[1]) +
                    c1_reshapes.f3->size[1]) + c1_f_result[1];
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_U1, c1_i386, &c1_df_emlrtRTEI);
  c1_q_loop_ub = c1_reshapes.f1->size[1] - 1;
  for (c1_i387 = 0; c1_i387 <= c1_q_loop_ub; c1_i387++) {
    c1_s_loop_ub = c1_reshapes.f1->size[0] - 1;
    for (c1_i389 = 0; c1_i389 <= c1_s_loop_ub; c1_i389++) {
      c1_U1->data[c1_i389 + c1_U1->size[0] * c1_i387] = c1_reshapes.f1->
        data[c1_i389 + c1_reshapes.f1->size[0] * c1_i387];
    }
  }

  c1_r_loop_ub = c1_reshapes.f2->size[1] - 1;
  for (c1_i388 = 0; c1_i388 <= c1_r_loop_ub; c1_i388++) {
    c1_u_loop_ub = c1_reshapes.f2->size[0] - 1;
    for (c1_i391 = 0; c1_i391 <= c1_u_loop_ub; c1_i391++) {
      c1_U1->data[c1_i391 + c1_U1->size[0] * (c1_i388 + c1_reshapes.f1->size[1])]
        = (real32_T)c1_reshapes.f2->data[c1_i391 + c1_reshapes.f2->size[0] *
        c1_i388];
    }
  }

  c1_t_loop_ub = c1_reshapes.f3->size[1] - 1;
  for (c1_i390 = 0; c1_i390 <= c1_t_loop_ub; c1_i390++) {
    c1_w_loop_ub = c1_reshapes.f3->size[0] - 1;
    for (c1_i393 = 0; c1_i393 <= c1_w_loop_ub; c1_i393++) {
      c1_U1->data[c1_i393 + c1_U1->size[0] * ((c1_i390 + c1_reshapes.f1->size[1])
        + c1_reshapes.f2->size[1])] = (real32_T)c1_reshapes.f3->data[c1_i393 +
        c1_reshapes.f3->size[0] * c1_i390];
    }
  }

  c1_v_loop_ub = c1_f_result[1] - 1;
  for (c1_i392 = 0; c1_i392 <= c1_v_loop_ub; c1_i392++) {
    c1_x_loop_ub = c1_f_result[0] - 1;
    for (c1_i394 = 0; c1_i394 <= c1_x_loop_ub; c1_i394++) {
      c1_U1->data[c1_i394 + c1_U1->size[0] * (((c1_i392 + c1_reshapes.f1->size[1])
        + c1_reshapes.f2->size[1]) + c1_reshapes.f3->size[1])] =
        c1_varargin_1->data[c1_i394 + c1_f_result[0] * c1_i392];
    }
  }

  c1_emxFreeStruct_cell_19(chartInstance, &c1_reshapes);
  c1_emxFree_real32_T(chartInstance, &c1_varargin_1);
  c1_iv9[0] = c1_r10->size[0];
  c1_iv9[1] = 5;
  _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c1_iv9, 2, *(int32_T (*)[2])c1_U1->size, 2);
  c1_iv10[0] = c1_r10->size[0];
  c1_iv10[1] = 5;
  for (c1_i395 = 0; c1_i395 < 5; c1_i395++) {
    c1_y_loop_ub = c1_iv10[0] - 1;
    for (c1_i396 = 0; c1_i396 <= c1_y_loop_ub; c1_i396++) {
      c1_constraints->data[c1_r10->data[c1_i396] + c1_constraints->size[0] *
        c1_i395] = c1_U1->data[c1_i396 + c1_iv10[0] * c1_i395];
    }
  }

  c1_emxFree_int32_T(chartInstance, &c1_r10);
  c1_nx = c1_constraints->size[0] * 5;
  c1_p = true;
  c1_overflow = ((!(1 > c1_nx)) && (c1_nx > 2147483646));
  if (c1_overflow) {
    c1_check_forloop_overflow_error(chartInstance, true);
  }

  for (c1_k = 0; c1_k + 1 <= c1_nx; c1_k++) {
    if (c1_p && ((!muSingleScalarIsInf(c1_constraints->data[c1_k])) &&
                 (!muSingleScalarIsNaN(c1_constraints->data[c1_k])))) {
      c1_b_p = true;
    } else {
      c1_b_p = false;
    }

    c1_p = c1_b_p;
  }

  if (c1_p) {
    c1_svd(chartInstance, c1_constraints, c1_U1, c1_s1_data, c1_s1_size, c1_V1);
  } else {
    for (c1_i397 = 0; c1_i397 < 2; c1_i397++) {
      c1_dv3[c1_i397] = (real_T)c1_constraints->size[c1_i397];
    }

    c1_emxInit_real32_T(chartInstance, &c1_r12, 2, &c1_ef_emlrtRTEI);
    c1_i398 = c1_r12->size[0] * c1_r12->size[1];
    c1_r12->size[0] = (int32_T)c1_dv3[0];
    c1_r12->size[1] = 5;
    c1_emxEnsureCapacity_real32_T(chartInstance, c1_r12, c1_i398,
      &c1_ef_emlrtRTEI);
    c1_i400 = c1_r12->size[0];
    c1_i401 = c1_r12->size[1];
    c1_ab_loop_ub = (int32_T)c1_dv3[0] * 5 - 1;
    for (c1_i402 = 0; c1_i402 <= c1_ab_loop_ub; c1_i402++) {
      c1_r12->data[c1_i402] = 0.0F;
    }

    c1_svd(chartInstance, c1_r12, c1_U1, c1_s1_data, c1_s1_size, c1_V1);
    c1_emxFree_real32_T(chartInstance, &c1_r12);
    for (c1_i406 = 0; c1_i406 < 25; c1_i406++) {
      c1_V1[c1_i406] = ((real32_T)rtNaN);
    }
  }

  c1_emxFree_real32_T(chartInstance, &c1_U1);
  c1_emxFree_real32_T(chartInstance, &c1_constraints);
  c1_B = c1_V1[24];
  for (c1_i399 = 0; c1_i399 < 3; c1_i399++) {
    c1_T[c1_i399] = c1_V1[c1_i399 + 20] / c1_B;
  }

  c1_T[3] = -c1_V1[21] / c1_B;
  c1_T[4] = c1_V1[20] / c1_B;
  c1_T[5] = c1_V1[23] / c1_B;
  for (c1_i403 = 0; c1_i403 < 3; c1_i403++) {
    c1_T[c1_i403 + 6] = c1_fv0[c1_i403];
  }

  c1_i404 = 0;
  for (c1_i405 = 0; c1_i405 < 3; c1_i405++) {
    c1_i407 = 0;
    for (c1_i408 = 0; c1_i408 < 3; c1_i408++) {
      c1_b_B[c1_i408 + c1_i404] = c1_normMatrix2[c1_i407 + c1_i405];
      c1_i407 += 3;
    }

    c1_i404 += 3;
  }

  c1_r1 = 0;
  c1_r2 = 1;
  c1_r3 = 2;
  c1_maxval = muSingleScalarAbs(c1_b_B[0]) + muSingleScalarAbs(0.0F);
  c1_a21 = muSingleScalarAbs(c1_b_B[1]) + muSingleScalarAbs(0.0F);
  if (c1_a21 > c1_maxval) {
    c1_maxval = c1_a21;
    c1_r1 = 1;
    c1_r2 = 0;
  }

  if (muSingleScalarAbs(c1_b_B[2]) + muSingleScalarAbs(0.0F) > c1_maxval) {
    c1_r1 = 2;
    c1_r2 = 1;
    c1_r3 = 0;
  }

  c1_b_B[c1_r2] /= c1_b_B[c1_r1];
  c1_b_B[c1_r3] /= c1_b_B[c1_r1];
  c1_b_B[3 + c1_r2] -= c1_b_B[c1_r2] * c1_b_B[3 + c1_r1];
  c1_b_B[3 + c1_r3] -= c1_b_B[c1_r3] * c1_b_B[3 + c1_r1];
  c1_b_B[6 + c1_r2] -= c1_b_B[c1_r2] * c1_b_B[6 + c1_r1];
  c1_b_B[6 + c1_r3] -= c1_b_B[c1_r3] * c1_b_B[6 + c1_r1];
  if (muSingleScalarAbs(c1_b_B[3 + c1_r3]) + muSingleScalarAbs(0.0F) >
      muSingleScalarAbs(c1_b_B[3 + c1_r2]) + muSingleScalarAbs(0.0F)) {
    c1_rtemp = c1_r2 + 1;
    c1_r2 = c1_r3;
    c1_r3 = c1_rtemp - 1;
  }

  c1_b_B[3 + c1_r3] /= c1_b_B[3 + c1_r2];
  c1_b_B[6 + c1_r3] -= c1_b_B[3 + c1_r3] * c1_b_B[6 + c1_r2];
  if ((c1_b_B[c1_r1] == 0.0F) || (c1_b_B[3 + c1_r2] == 0.0F) || (c1_b_B[6 +
       c1_r3] == 0.0F)) {
    c1_warning(chartInstance);
  }

  for (c1_b_k = 0; c1_b_k < 3; c1_b_k++) {
    c1_normMatrix2[c1_b_k + 3 * c1_r1] = c1_T[c1_b_k] / c1_b_B[c1_r1];
    c1_normMatrix2[c1_b_k + 3 * c1_r2] = c1_T[3 + c1_b_k] -
      c1_normMatrix2[c1_b_k + 3 * c1_r1] * c1_b_B[3 + c1_r1];
    c1_normMatrix2[c1_b_k + 3 * c1_r3] = c1_T[6 + c1_b_k] -
      c1_normMatrix2[c1_b_k + 3 * c1_r1] * c1_b_B[6 + c1_r1];
    c1_normMatrix2[c1_b_k + 3 * c1_r2] /= c1_b_B[3 + c1_r2];
    c1_normMatrix2[c1_b_k + 3 * c1_r3] -= c1_normMatrix2[c1_b_k + 3 * c1_r2] *
      c1_b_B[6 + c1_r2];
    c1_normMatrix2[c1_b_k + 3 * c1_r3] /= c1_b_B[6 + c1_r3];
    c1_normMatrix2[c1_b_k + 3 * c1_r2] -= c1_normMatrix2[c1_b_k + 3 * c1_r3] *
      c1_b_B[3 + c1_r3];
    c1_normMatrix2[c1_b_k + 3 * c1_r1] -= c1_normMatrix2[c1_b_k + 3 * c1_r3] *
      c1_b_B[c1_r3];
    c1_normMatrix2[c1_b_k + 3 * c1_r1] -= c1_normMatrix2[c1_b_k + 3 * c1_r2] *
      c1_b_B[c1_r2];
  }

  c1_i409 = 0;
  for (c1_i410 = 0; c1_i410 < 3; c1_i410++) {
    c1_i411 = 0;
    for (c1_i413 = 0; c1_i413 < 3; c1_i413++) {
      c1_T[c1_i411 + c1_i410] = 0.0F;
      for (c1_i414 = 0; c1_i414 < 3; c1_i414++) {
        c1_T[c1_i411 + c1_i410] += c1_normMatrix1[c1_i414 + c1_i409] *
          c1_normMatrix2[c1_i414 + c1_i411];
      }

      c1_i411 += 3;
    }

    c1_i409 += 3;
  }

  c1_b_T = c1_T[8];
  for (c1_i412 = 0; c1_i412 < 9; c1_i412++) {
    c1_T[c1_i412] /= c1_b_T;
  }
}

static void c1_normalizePoints(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T *c1_points, c1_emxArray_real32_T
  *c1_samples1, c1_emxArray_real32_T *c1_samples2, real32_T c1_normMatrix1[9],
  real32_T c1_normMatrix2[9])
{
  c1_emxArray_real32_T *c1_b_points;
  int32_T c1_i415;
  int32_T c1_i416;
  int32_T c1_i417;
  int32_T c1_loop_ub;
  int32_T c1_i418;
  c1_emxArray_real32_T *c1_b_samples1;
  int32_T c1_b_loop_ub;
  c1_emxArray_real32_T *c1_c_points;
  int32_T c1_i419;
  int32_T c1_i420;
  int32_T c1_i421;
  int32_T c1_i422;
  int32_T c1_c_loop_ub;
  int32_T c1_i423;
  c1_emxArray_real32_T *c1_b_samples2;
  int32_T c1_d_loop_ub;
  c1_emxArray_real32_T *c1_c_samples1;
  int32_T c1_i424;
  int32_T c1_i425;
  int32_T c1_i426;
  int32_T c1_d_samples1[2];
  int32_T c1_e_loop_ub;
  int32_T c1_i427;
  int32_T c1_i428;
  int32_T c1_f_loop_ub;
  int32_T c1_i429;
  int32_T c1_g_loop_ub;
  c1_emxArray_real32_T *c1_c_samples2;
  int32_T c1_i430;
  int32_T c1_i431;
  int32_T c1_i432;
  int32_T c1_d_samples2[2];
  int32_T c1_h_loop_ub;
  int32_T c1_i433;
  int32_T c1_i434;
  int32_T c1_i_loop_ub;
  int32_T c1_i435;
  int32_T c1_j_loop_ub;
  int32_T c1_i436;
  c1_emxInit_real32_T(chartInstance, &c1_b_points, 2, &c1_hf_emlrtRTEI);
  c1_i415 = c1_points->size[0];
  c1_i416 = c1_points->size[1];
  c1_i417 = c1_b_points->size[0] * c1_b_points->size[1];
  c1_b_points->size[0] = c1_i416;
  c1_b_points->size[1] = c1_i415;
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_b_points, c1_i417,
    &c1_hf_emlrtRTEI);
  c1_loop_ub = c1_i415 - 1;
  for (c1_i418 = 0; c1_i418 <= c1_loop_ub; c1_i418++) {
    c1_b_loop_ub = c1_i416 - 1;
    for (c1_i419 = 0; c1_i419 <= c1_b_loop_ub; c1_i419++) {
      c1_b_points->data[c1_i419 + c1_b_points->size[0] * c1_i418] =
        c1_points->data[c1_i418 + c1_points->size[0] * c1_i419];
    }
  }

  c1_emxInit_real32_T(chartInstance, &c1_b_samples1, 2, &c1_nf_emlrtRTEI);
  c1_emxInit_real32_T(chartInstance, &c1_c_points, 2, &c1_if_emlrtRTEI);
  c1_b_normalizePoints(chartInstance, c1_b_points, c1_b_samples1, c1_normMatrix1);
  c1_i420 = c1_points->size[0];
  c1_i421 = c1_points->size[1];
  c1_i422 = c1_c_points->size[0] * c1_c_points->size[1];
  c1_c_points->size[0] = c1_i421;
  c1_c_points->size[1] = c1_i420;
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_c_points, c1_i422,
    &c1_if_emlrtRTEI);
  c1_c_loop_ub = c1_i420 - 1;
  c1_emxFree_real32_T(chartInstance, &c1_b_points);
  for (c1_i423 = 0; c1_i423 <= c1_c_loop_ub; c1_i423++) {
    c1_d_loop_ub = c1_i421 - 1;
    for (c1_i424 = 0; c1_i424 <= c1_d_loop_ub; c1_i424++) {
      c1_c_points->data[c1_i424 + c1_c_points->size[0] * c1_i423] =
        c1_points->data[(c1_i423 + c1_points->size[0] * c1_i424) +
        c1_points->size[0] * c1_points->size[1]];
    }
  }

  c1_emxInit_real32_T(chartInstance, &c1_b_samples2, 2, &c1_nf_emlrtRTEI);
  c1_emxInit_real32_T(chartInstance, &c1_c_samples1, 2, &c1_jf_emlrtRTEI);
  c1_b_normalizePoints(chartInstance, c1_c_points, c1_b_samples2, c1_normMatrix2);
  c1_i425 = c1_c_samples1->size[0] * c1_c_samples1->size[1];
  c1_c_samples1->size[0] = c1_b_samples1->size[1];
  c1_c_samples1->size[1] = 2;
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_c_samples1, c1_i425,
    &c1_jf_emlrtRTEI);
  c1_emxFree_real32_T(chartInstance, &c1_c_points);
  for (c1_i426 = 0; c1_i426 < 2; c1_i426++) {
    c1_e_loop_ub = c1_b_samples1->size[1] - 1;
    for (c1_i427 = 0; c1_i427 <= c1_e_loop_ub; c1_i427++) {
      c1_c_samples1->data[c1_i427 + c1_c_samples1->size[0] * c1_i426] =
        c1_b_samples1->data[c1_i426 + c1_b_samples1->size[0] * c1_i427];
    }
  }

  c1_d_samples1[0] = c1_b_samples1->size[1];
  c1_d_samples1[1] = c1_b_samples1->size[0];
  c1_i428 = c1_samples1->size[0] * c1_samples1->size[1];
  c1_samples1->size[0] = c1_d_samples1[0];
  c1_samples1->size[1] = c1_d_samples1[1];
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_samples1, c1_i428,
    &c1_kf_emlrtRTEI);
  c1_f_loop_ub = c1_d_samples1[1] - 1;
  c1_emxFree_real32_T(chartInstance, &c1_b_samples1);
  for (c1_i429 = 0; c1_i429 <= c1_f_loop_ub; c1_i429++) {
    c1_g_loop_ub = c1_d_samples1[0] - 1;
    for (c1_i430 = 0; c1_i430 <= c1_g_loop_ub; c1_i430++) {
      c1_samples1->data[c1_i430 + c1_samples1->size[0] * c1_i429] =
        c1_c_samples1->data[c1_i430 + c1_d_samples1[0] * c1_i429];
    }
  }

  c1_emxFree_real32_T(chartInstance, &c1_c_samples1);
  c1_emxInit_real32_T(chartInstance, &c1_c_samples2, 2, &c1_lf_emlrtRTEI);
  c1_i431 = c1_c_samples2->size[0] * c1_c_samples2->size[1];
  c1_c_samples2->size[0] = c1_b_samples2->size[1];
  c1_c_samples2->size[1] = 2;
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_c_samples2, c1_i431,
    &c1_lf_emlrtRTEI);
  for (c1_i432 = 0; c1_i432 < 2; c1_i432++) {
    c1_h_loop_ub = c1_b_samples2->size[1] - 1;
    for (c1_i433 = 0; c1_i433 <= c1_h_loop_ub; c1_i433++) {
      c1_c_samples2->data[c1_i433 + c1_c_samples2->size[0] * c1_i432] =
        c1_b_samples2->data[c1_i432 + c1_b_samples2->size[0] * c1_i433];
    }
  }

  c1_d_samples2[0] = c1_b_samples2->size[1];
  c1_d_samples2[1] = c1_b_samples2->size[0];
  c1_i434 = c1_samples2->size[0] * c1_samples2->size[1];
  c1_samples2->size[0] = c1_d_samples2[0];
  c1_samples2->size[1] = c1_d_samples2[1];
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_samples2, c1_i434,
    &c1_mf_emlrtRTEI);
  c1_i_loop_ub = c1_d_samples2[1] - 1;
  c1_emxFree_real32_T(chartInstance, &c1_b_samples2);
  for (c1_i435 = 0; c1_i435 <= c1_i_loop_ub; c1_i435++) {
    c1_j_loop_ub = c1_d_samples2[0] - 1;
    for (c1_i436 = 0; c1_i436 <= c1_j_loop_ub; c1_i436++) {
      c1_samples2->data[c1_i436 + c1_samples2->size[0] * c1_i435] =
        c1_c_samples2->data[c1_i436 + c1_d_samples2[0] * c1_i435];
    }
  }

  c1_emxFree_real32_T(chartInstance, &c1_c_samples2);
}

static void c1_b_normalizePoints(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T *c1_p, c1_emxArray_real32_T
  *c1_normPoints, real32_T c1_T[9])
{
  c1_emxArray_real32_T *c1_points;
  int32_T c1_b_p;
  int32_T c1_i437;
  int32_T c1_i438;
  int32_T c1_loop_ub;
  int32_T c1_i439;
  int32_T c1_i440;
  int32_T c1_i441;
  int32_T c1_iv11[2];
  int32_T c1_i442;
  int32_T c1_iv12[2];
  int32_T c1_i443;
  int32_T c1_i444;
  real32_T c1_cent[2];
  int32_T c1_iv13[2];
  int32_T c1_i445;
  int32_T c1_iv14[2];
  int32_T c1_firstBlockLength;
  int32_T c1_i446;
  real32_T c1_f1;
  int32_T c1_i447;
  int32_T c1_iv15[2];
  int32_T c1_i448;
  int32_T c1_iv16[2];
  int32_T c1_nblocks;
  int32_T c1_lastBlockLength;
  int32_T c1_i449;
  int32_T c1_i450;
  int32_T c1_iv17[2];
  int32_T c1_iv18[2];
  int32_T c1_xj;
  int32_T c1_csz[2];
  int32_T c1_i451;
  boolean_T c1_overflow;
  int32_T c1_k;
  int32_T c1_szc;
  int32_T c1_i452;
  c1_emxArray_real32_T *c1_b_normPoints;
  int32_T c1_iv19[2];
  int32_T c1_i453;
  boolean_T c1_b_overflow;
  int32_T c1_xoffset;
  int32_T c1_b_xj;
  int32_T c1_acoef;
  int32_T c1_b_k;
  int32_T c1_ib;
  int32_T c1_i454;
  int32_T c1_ia;
  int32_T c1_xblockoffset;
  int32_T c1_c_k;
  int32_T c1_c_xj;
  int32_T c1_c_normPoints;
  int32_T c1_d_normPoints;
  int32_T c1_i455;
  int32_T c1_b_loop_ub;
  real32_T c1_bsum[2];
  int32_T c1_i456;
  int32_T c1_hi;
  boolean_T c1_c_overflow;
  const mxArray *c1_y = NULL;
  int32_T c1_d_k;
  int32_T c1_i457;
  int32_T c1_d_xj;
  int32_T c1_e_xj;
  int32_T c1_iv20[2];
  int32_T c1_nx;
  boolean_T c1_d_overflow;
  int32_T c1_e_k;
  c1_emxArray_real32_T *c1_b_y;
  int32_T c1_i458;
  int32_T c1_i459;
  int32_T c1_i460;
  real_T c1_x[2];
  boolean_T c1_e_overflow;
  int32_T c1_xi;
  int32_T c1_c_y;
  int32_T c1_d_y;
  int32_T c1_c_loop_ub;
  int32_T c1_xpageoffset;
  int32_T c1_i461;
  c1_emxArray_real32_T *c1_b_x;
  boolean_T c1_c_p;
  int32_T c1_f_k;
  int32_T c1_i462;
  boolean_T c1_d_p;
  int32_T c1_c_x;
  int32_T c1_d_x;
  int32_T c1_d_loop_ub;
  int32_T c1_i463;
  boolean_T c1_f_overflow;
  int32_T c1_g_k;
  real32_T c1_meanDistanceFromCenter;
  real32_T c1_scale;
  int32_T c1_i464;
  int32_T c1_i465;
  real32_T c1_e_y[3];
  int32_T c1_j;
  int32_T c1_b_j;
  real32_T c1_b_scale;
  int32_T c1_i466;
  int32_T c1_i467;
  int32_T c1_e_normPoints;
  int32_T c1_f_normPoints;
  int32_T c1_g_normPoints;
  int32_T c1_h_normPoints;
  int32_T c1_e_loop_ub;
  int32_T c1_i468;
  boolean_T guard1 = false;
  c1_emxInit_real32_T(chartInstance, &c1_points, 2, &c1_of_emlrtRTEI);
  c1_b_p = c1_p->size[0];
  c1_i437 = c1_p->size[1];
  c1_i438 = c1_points->size[0] * c1_points->size[1];
  c1_points->size[0] = 2;
  c1_points->size[1] = c1_i437;
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_points, c1_i438,
    &c1_of_emlrtRTEI);
  c1_loop_ub = c1_i437 - 1;
  for (c1_i439 = 0; c1_i439 <= c1_loop_ub; c1_i439++) {
    for (c1_i441 = 0; c1_i441 < 2; c1_i441++) {
      c1_points->data[c1_i441 + c1_points->size[0] * c1_i439] = c1_p->data
        [(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
           chartInstance->S, 1U, 0, 0, MAX_uint32_T, c1_i441 + 1, 1, c1_b_p) +
          c1_p->size[0] * c1_i439) - 1];
    }
  }

  c1_i440 = c1_p->size[1];
  c1_iv11[0] = 2;
  c1_iv11[1] = c1_i440;
  guard1 = false;
  if (c1_iv11[1] == 0) {
    guard1 = true;
  } else {
    c1_i442 = c1_p->size[1];
    c1_iv12[0] = 2;
    c1_iv12[1] = c1_i442;
    if (c1_iv12[1] == 0) {
      guard1 = true;
    } else {
      c1_i444 = c1_p->size[1];
      c1_iv13[0] = 2;
      c1_iv13[1] = c1_i444;
      if (c1_iv13[1] <= 1024) {
        c1_i446 = c1_p->size[1];
        c1_iv15[0] = 2;
        c1_iv15[1] = c1_i446;
        c1_firstBlockLength = c1_iv15[1];
        c1_lastBlockLength = 0;
        c1_nblocks = 1;
      } else {
        c1_firstBlockLength = 1024;
        c1_i447 = c1_p->size[1];
        c1_iv16[0] = 2;
        c1_iv16[1] = c1_i447;
        c1_nblocks = c1_div_nzp_s32(chartInstance, c1_iv16[1], 1024, 1U, 0U, 0U);
        c1_i450 = c1_p->size[1];
        c1_iv18[0] = 2;
        c1_iv18[1] = c1_i450;
        c1_lastBlockLength = c1_iv18[1] - (c1_nblocks << 10);
        if (c1_lastBlockLength > 0) {
          c1_nblocks++;
        } else {
          c1_lastBlockLength = 1024;
        }
      }

      for (c1_xj = 0; c1_xj < 2; c1_xj++) {
        c1_cent[c1_xj] = c1_points->data[c1_xj];
      }

      c1_overflow = ((!(2 > c1_firstBlockLength)) && (c1_firstBlockLength >
        2147483646));
      if (c1_overflow) {
        c1_check_forloop_overflow_error(chartInstance, true);
      }

      for (c1_k = 1; c1_k + 1 <= c1_firstBlockLength; c1_k++) {
        c1_xoffset = c1_k << 1;
        for (c1_b_xj = 0; c1_b_xj < 2; c1_b_xj++) {
          c1_cent[c1_b_xj] += c1_points->data[c1_xoffset + c1_b_xj];
        }
      }

      c1_b_overflow = ((!(2 > c1_nblocks)) && (c1_nblocks > 2147483646));
      if (c1_b_overflow) {
        c1_check_forloop_overflow_error(chartInstance, true);
      }

      for (c1_ib = 2; c1_ib <= c1_nblocks; c1_ib++) {
        c1_xblockoffset = (c1_ib - 1) << 11;
        for (c1_c_xj = 0; c1_c_xj < 2; c1_c_xj++) {
          c1_bsum[c1_c_xj] = c1_points->data[c1_xblockoffset + c1_c_xj];
        }

        if (c1_ib == c1_nblocks) {
          c1_hi = c1_lastBlockLength;
        } else {
          c1_hi = 1024;
        }

        c1_c_overflow = ((!(2 > c1_hi)) && (c1_hi > 2147483646));
        if (c1_c_overflow) {
          c1_check_forloop_overflow_error(chartInstance, true);
        }

        for (c1_d_k = 1; c1_d_k + 1 <= c1_hi; c1_d_k++) {
          c1_xoffset = c1_xblockoffset + (c1_d_k << 1);
          for (c1_e_xj = 0; c1_e_xj < 2; c1_e_xj++) {
            c1_bsum[c1_e_xj] += c1_points->data[c1_xoffset + c1_e_xj];
          }
        }

        for (c1_d_xj = 0; c1_d_xj < 2; c1_d_xj++) {
          c1_cent[c1_d_xj] += c1_bsum[c1_d_xj];
        }
      }
    }
  }

  if (guard1) {
    for (c1_i443 = 0; c1_i443 < 2; c1_i443++) {
      c1_cent[c1_i443] = 0.0F;
    }
  }

  c1_i445 = c1_p->size[1];
  c1_iv14[0] = 2;
  c1_iv14[1] = c1_i445;
  c1_f1 = (real32_T)c1_iv14[1];
  for (c1_i448 = 0; c1_i448 < 2; c1_i448++) {
    c1_cent[c1_i448] /= c1_f1;
  }

  c1_i449 = c1_p->size[1];
  c1_iv17[0] = 2;
  c1_iv17[1] = c1_i449;
  c1_csz[1] = c1_iv17[1];
  c1_i451 = c1_normPoints->size[0] * c1_normPoints->size[1];
  c1_normPoints->size[0] = 2;
  c1_normPoints->size[1] = c1_csz[1];
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_normPoints, c1_i451,
    &c1_pf_emlrtRTEI);
  if (c1_normPoints->size[1] == 0) {
  } else {
    c1_szc = c1_normPoints->size[1] - 1;
    c1_i452 = c1_p->size[1];
    c1_iv19[0] = 2;
    c1_iv19[1] = c1_i452;
    c1_acoef = (c1_iv19[1] != 1);
    for (c1_b_k = 0; c1_b_k <= c1_szc; c1_b_k++) {
      c1_ia = c1_acoef * c1_b_k;
      for (c1_c_k = 0; c1_c_k < 2; c1_c_k++) {
        c1_i455 = c1_p->size[1];
        c1_normPoints->data[c1_c_k + c1_normPoints->size[0] * c1_b_k] =
          c1_p->data[((c1_c_k + 1) + c1_p->size[0] * c1_ia) - 1] -
          c1_cent[c1_c_k];
      }
    }
  }

  c1_emxInit_real32_T(chartInstance, &c1_b_normPoints, 2, &c1_rf_emlrtRTEI);
  c1_i453 = c1_points->size[0] * c1_points->size[1];
  c1_points->size[0] = 2;
  c1_points->size[1] = c1_normPoints->size[1];
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_points, c1_i453,
    &c1_qf_emlrtRTEI);
  c1_i454 = c1_b_normPoints->size[0] * c1_b_normPoints->size[1];
  c1_b_normPoints->size[0] = 2;
  c1_b_normPoints->size[1] = c1_normPoints->size[1];
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_b_normPoints, c1_i454,
    &c1_rf_emlrtRTEI);
  c1_c_normPoints = c1_b_normPoints->size[0];
  c1_d_normPoints = c1_b_normPoints->size[1];
  c1_b_loop_ub = c1_normPoints->size[0] * c1_normPoints->size[1] - 1;
  for (c1_i456 = 0; c1_i456 <= c1_b_loop_ub; c1_i456++) {
    c1_b_normPoints->data[c1_i456] = c1_normPoints->data[c1_i456];
  }

  if (c1_dimagree(chartInstance, c1_points, c1_b_normPoints)) {
  } else {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv11, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_y));
  }

  c1_emxFree_real32_T(chartInstance, &c1_b_normPoints);
  c1_i457 = c1_points->size[0] * c1_points->size[1];
  c1_points->size[0] = 2;
  c1_points->size[1] = c1_normPoints->size[1];
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_points, c1_i457,
    &c1_sf_emlrtRTEI);
  c1_iv20[0] = 2;
  c1_iv20[1] = c1_normPoints->size[1];
  c1_nx = c1_iv20[1] << 1;
  c1_d_overflow = ((!(1 > c1_nx)) && (c1_nx > 2147483646));
  if (c1_d_overflow) {
    c1_check_forloop_overflow_error(chartInstance, true);
  }

  for (c1_e_k = 0; c1_e_k + 1 <= c1_nx; c1_e_k++) {
    c1_points->data[c1_e_k] = c1_normPoints->data[c1_e_k] * c1_normPoints->
      data[c1_e_k];
  }

  c1_emxInit_real32_T(chartInstance, &c1_b_y, 2, &c1_xf_emlrtRTEI);
  if (c1_points->size[1] == 0) {
    for (c1_i459 = 0; c1_i459 < 2; c1_i459++) {
      c1_x[c1_i459] = (real_T)c1_points->size[c1_i459];
    }

    c1_i460 = c1_b_y->size[0] * c1_b_y->size[1];
    c1_b_y->size[0] = 1;
    c1_b_y->size[1] = (int32_T)c1_x[1];
    c1_emxEnsureCapacity_real32_T(chartInstance, c1_b_y, c1_i460,
      &c1_uf_emlrtRTEI);
    c1_c_y = c1_b_y->size[0];
    c1_d_y = c1_b_y->size[1];
    c1_c_loop_ub = (int32_T)c1_x[1] - 1;
    for (c1_i461 = 0; c1_i461 <= c1_c_loop_ub; c1_i461++) {
      c1_b_y->data[c1_i461] = 0.0F;
    }
  } else {
    c1_i458 = c1_b_y->size[0] * c1_b_y->size[1];
    c1_b_y->size[0] = 1;
    c1_b_y->size[1] = c1_points->size[1];
    c1_emxEnsureCapacity_real32_T(chartInstance, c1_b_y, c1_i458,
      &c1_tf_emlrtRTEI);
    c1_e_overflow = ((!(1 > c1_points->size[1])) && (c1_points->size[1] >
      2147483646));
    if (c1_e_overflow) {
      c1_check_forloop_overflow_error(chartInstance, true);
    }

    for (c1_xi = 0; c1_xi + 1 <= c1_points->size[1]; c1_xi++) {
      c1_xpageoffset = c1_xi << 1;
      c1_b_y->data[c1_xi] = c1_points->data[c1_xpageoffset];
      c1_b_y->data[c1_xi] += c1_points->data[c1_xpageoffset + 1];
    }
  }

  c1_emxFree_real32_T(chartInstance, &c1_points);
  c1_emxInit_real32_T(chartInstance, &c1_b_x, 2, &c1_yf_emlrtRTEI);
  c1_c_p = false;
  for (c1_f_k = 0; c1_f_k < c1_b_y->size[1]; c1_f_k++) {
    if (c1_c_p || (c1_b_y->data[c1_f_k] < 0.0F)) {
      c1_d_p = true;
    } else {
      c1_d_p = false;
    }

    c1_c_p = c1_d_p;
  }

  if (c1_c_p) {
    c1_b_error(chartInstance);
  }

  c1_i462 = c1_b_x->size[0] * c1_b_x->size[1];
  c1_b_x->size[0] = 1;
  c1_b_x->size[1] = c1_b_y->size[1];
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_b_x, c1_i462, &c1_vf_emlrtRTEI);
  c1_c_x = c1_b_x->size[0];
  c1_d_x = c1_b_x->size[1];
  c1_d_loop_ub = c1_b_y->size[0] * c1_b_y->size[1] - 1;
  for (c1_i463 = 0; c1_i463 <= c1_d_loop_ub; c1_i463++) {
    c1_b_x->data[c1_i463] = c1_b_y->data[c1_i463];
  }

  c1_f_overflow = ((!(1 > c1_b_y->size[1])) && (c1_b_y->size[1] > 2147483646));
  if (c1_f_overflow) {
    c1_check_forloop_overflow_error(chartInstance, true);
  }

  for (c1_g_k = 0; c1_g_k + 1 <= c1_b_y->size[1]; c1_g_k++) {
    c1_b_x->data[c1_g_k] = muSingleScalarSqrt(c1_b_x->data[c1_g_k]);
  }

  c1_emxFree_real32_T(chartInstance, &c1_b_y);
  c1_meanDistanceFromCenter = c1_mean(chartInstance, c1_b_x);
  c1_emxFree_real32_T(chartInstance, &c1_b_x);
  if (c1_meanDistanceFromCenter > 0.0F) {
    c1_scale = 1.41421354F / c1_meanDistanceFromCenter;
  } else {
    c1_scale = 1.0F;
  }

  for (c1_i464 = 0; c1_i464 < 3; c1_i464++) {
    c1_e_y[c1_i464] = c1_scale;
  }

  for (c1_i465 = 0; c1_i465 < 9; c1_i465++) {
    c1_T[c1_i465] = 0.0F;
  }

  c1_j = 0;
  for (c1_b_j = 0; c1_b_j < 3; c1_b_j++) {
    c1_T[c1_j] = c1_e_y[c1_b_j];
    c1_j += 4;
  }

  c1_b_scale = -c1_scale;
  for (c1_i466 = 0; c1_i466 < 2; c1_i466++) {
    c1_T[c1_i466 + 6] = c1_b_scale * c1_cent[c1_i466];
  }

  c1_T[8] = 1.0F;
  c1_i467 = c1_normPoints->size[0] * c1_normPoints->size[1];
  c1_normPoints->size[0] = 2;
  c1_normPoints->size[1];
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_normPoints, c1_i467,
    &c1_wf_emlrtRTEI);
  c1_e_normPoints = c1_normPoints->size[0];
  c1_f_normPoints = c1_normPoints->size[1];
  c1_g_normPoints = c1_normPoints->size[0];
  c1_h_normPoints = c1_normPoints->size[1];
  c1_e_loop_ub = c1_e_normPoints * c1_f_normPoints - 1;
  for (c1_i468 = 0; c1_i468 <= c1_e_loop_ub; c1_i468++) {
    c1_normPoints->data[c1_i468] *= c1_scale;
  }
}

static boolean_T c1_dimagree(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T *c1_z, c1_emxArray_real32_T
  *c1_varargin_1)
{
  boolean_T c1_p;
  boolean_T c1_b_p;
  int32_T c1_k;
  boolean_T exitg1;
  (void)chartInstance;
  c1_p = true;
  c1_b_p = true;
  c1_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c1_k + 1 < 3)) {
    if (c1_z->size[c1_k] != c1_varargin_1->size[c1_k]) {
      c1_b_p = false;
      exitg1 = true;
    } else {
      c1_k++;
    }
  }

  if (c1_b_p) {
  } else {
    c1_p = false;
  }

  return c1_p;
}

static real32_T c1_mean(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  c1_emxArray_real32_T *c1_x)
{
  boolean_T c1_b20;
  const mxArray *c1_b_y = NULL;
  real32_T c1_c_y;
  int32_T c1_firstBlockLength;
  int32_T c1_nblocks;
  int32_T c1_lastBlockLength;
  boolean_T c1_overflow;
  int32_T c1_k;
  boolean_T c1_b_overflow;
  int32_T c1_ib;
  int32_T c1_xblockoffset;
  real32_T c1_bsum;
  int32_T c1_hi;
  boolean_T c1_c_overflow;
  int32_T c1_b_k;
  if ((c1_x->size[1] == 1) || ((real_T)c1_x->size[1] != 1.0)) {
    c1_b20 = true;
  } else {
    c1_b20 = false;
  }

  if (c1_b20) {
  } else {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv12, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_b_y));
  }

  if ((c1_x->size[1] == 0) || (c1_x->size[1] == 0)) {
    c1_c_y = 0.0F;
  } else {
    if (c1_x->size[1] <= 1024) {
      c1_firstBlockLength = c1_x->size[1];
      c1_lastBlockLength = 0;
      c1_nblocks = 1;
    } else {
      c1_firstBlockLength = 1024;
      c1_nblocks = c1_div_nzp_s32(chartInstance, c1_x->size[1], 1024, 1U, 0U, 0U);
      c1_lastBlockLength = c1_x->size[1] - (c1_nblocks << 10);
      if (c1_lastBlockLength > 0) {
        c1_nblocks++;
      } else {
        c1_lastBlockLength = 1024;
      }
    }

    c1_c_y = c1_x->data[0];
    c1_overflow = ((!(2 > c1_firstBlockLength)) && (c1_firstBlockLength >
      2147483646));
    if (c1_overflow) {
      c1_check_forloop_overflow_error(chartInstance, true);
    }

    for (c1_k = 1; c1_k + 1 <= c1_firstBlockLength; c1_k++) {
      c1_c_y += c1_x->data[c1_k];
    }

    c1_b_overflow = ((!(2 > c1_nblocks)) && (c1_nblocks > 2147483646));
    if (c1_b_overflow) {
      c1_check_forloop_overflow_error(chartInstance, true);
    }

    for (c1_ib = 2; c1_ib <= c1_nblocks; c1_ib++) {
      c1_xblockoffset = (c1_ib - 1) << 10;
      c1_bsum = c1_x->data[c1_xblockoffset];
      if (c1_ib == c1_nblocks) {
        c1_hi = c1_lastBlockLength;
      } else {
        c1_hi = 1024;
      }

      c1_c_overflow = ((!(2 > c1_hi)) && (c1_hi > 2147483646));
      if (c1_c_overflow) {
        c1_check_forloop_overflow_error(chartInstance, true);
      }

      for (c1_b_k = 1; c1_b_k + 1 <= c1_hi; c1_b_k++) {
        c1_bsum += c1_x->data[c1_xblockoffset + c1_b_k];
      }

      c1_c_y += c1_bsum;
    }
  }

  return c1_c_y / (real32_T)c1_x->size[1];
}

static void c1_svd(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
                   c1_emxArray_real32_T *c1_A, c1_emxArray_real32_T *c1_U,
                   real32_T c1_s_data[], int32_T c1_s_size[1], real32_T c1_V[25])
{
  c1_emxArray_real32_T *c1_b_A;
  int32_T c1_m;
  int32_T c1_i469;
  int32_T c1_c_A;
  int32_T c1_d_A;
  int32_T c1_loop_ub;
  int32_T c1_i470;
  c1_emxArray_real32_T *c1_Utmp;
  int32_T c1_i471;
  int32_T c1_info;
  ptrdiff_t c1_info_t;
  real32_T c1_Vt[25];
  int32_T c1_b_info;
  int32_T c1_i472;
  c1_emxArray_real32_T *c1_e_A;
  int32_T c1_i473;
  int32_T c1_i474;
  int32_T c1_iv21[2];
  int32_T c1_i475;
  int32_T c1_i476;
  int32_T c1_f_A;
  int32_T c1_i477;
  int32_T c1_g_A;
  int32_T c1_b_loop_ub;
  int32_T c1_i478;
  real_T c1_d16;
  int32_T c1_k;
  int32_T c1_c_info;
  c1_emxInit_real32_T(chartInstance, &c1_b_A, 2, &c1_ag_emlrtRTEI);
  c1_m = c1_A->size[0];
  c1_i469 = c1_b_A->size[0] * c1_b_A->size[1];
  c1_b_A->size[0] = c1_A->size[0];
  c1_b_A->size[1] = 5;
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_b_A, c1_i469, &c1_ag_emlrtRTEI);
  c1_c_A = c1_b_A->size[0];
  c1_d_A = c1_b_A->size[1];
  c1_loop_ub = c1_A->size[0] * c1_A->size[1] - 1;
  for (c1_i470 = 0; c1_i470 <= c1_loop_ub; c1_i470++) {
    c1_b_A->data[c1_i470] = c1_A->data[c1_i470];
  }

  c1_emxInit_real32_T(chartInstance, &c1_Utmp, 2, &c1_eg_emlrtRTEI);
  c1_i471 = c1_Utmp->size[0] * c1_Utmp->size[1];
  c1_Utmp->size[0] = c1_A->size[0];
  c1_Utmp->size[1] = c1_A->size[0];
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_Utmp, c1_i471,
    &c1_bg_emlrtRTEI);
  c1_s_size[0] = muIntScalarMin_sint32(c1_m, 5);
  if (!(c1_A->size[0] == 0)) {
    c1_info_t = LAPACKE_sgesdd(102, 'A', (ptrdiff_t)c1_A->size[0], (ptrdiff_t)5,
      &c1_b_A->data[0], (ptrdiff_t)c1_A->size[0], &c1_s_data[0], &c1_Utmp->data
      [0], (ptrdiff_t)c1_A->size[0], &c1_Vt[0], (ptrdiff_t)5);
    c1_info = (int32_T)c1_info_t;
    if (c1_info < 0) {
      if (c1_info == -1010) {
        c1_e_error(chartInstance);
      } else {
        c1_f_error(chartInstance, c1_info);
      }
    }
  } else {
    c1_info = 0;
  }

  c1_emxFree_real32_T(chartInstance, &c1_b_A);
  c1_b_info = c1_info;
  if (c1_info > 0) {
    c1_emxInit_real32_T(chartInstance, &c1_e_A, 2, &c1_cg_emlrtRTEI);
    c1_i474 = c1_e_A->size[0] * c1_e_A->size[1];
    c1_e_A->size[0] = c1_A->size[0];
    c1_e_A->size[1] = 5;
    c1_emxEnsureCapacity_real32_T(chartInstance, c1_e_A, c1_i474,
      &c1_cg_emlrtRTEI);
    c1_f_A = c1_e_A->size[0];
    c1_g_A = c1_e_A->size[1];
    c1_b_loop_ub = c1_A->size[0] * c1_A->size[1] - 1;
    for (c1_i478 = 0; c1_i478 <= c1_b_loop_ub; c1_i478++) {
      c1_e_A->data[c1_i478] = c1_A->data[c1_i478];
    }

    c1_ceval_xgesvd(chartInstance, c1_e_A, c1_U, c1_s_data, c1_s_size, c1_V,
                    &c1_c_info);
    c1_b_info = c1_c_info;
    c1_emxFree_real32_T(chartInstance, &c1_e_A);
  } else {
    c1_i472 = 0;
    for (c1_i473 = 0; c1_i473 < 5; c1_i473++) {
      c1_i475 = 0;
      for (c1_i476 = 0; c1_i476 < 5; c1_i476++) {
        c1_V[c1_i476 + c1_i472] = c1_Vt[c1_i475 + c1_i473];
        c1_i475 += 5;
      }

      c1_i472 += 5;
    }

    c1_iv21[0] = c1_A->size[0];
    c1_iv21[1] = muIntScalarMin_sint32(c1_m, 5);
    c1_i477 = c1_U->size[0] * c1_U->size[1];
    c1_U->size[0] = c1_iv21[0];
    c1_U->size[1] = c1_iv21[1];
    c1_emxEnsureCapacity_real32_T(chartInstance, c1_U, c1_i477, &c1_dg_emlrtRTEI);
    c1_d16 = (real_T)(c1_U->size[0] * c1_U->size[1]);
    for (c1_k = 0; c1_k < (int32_T)c1_d16; c1_k++) {
      c1_U->data[c1_k] = c1_Utmp->data[c1_k];
    }
  }

  c1_emxFree_real32_T(chartInstance, &c1_Utmp);
  if (c1_b_info > 0) {
    c1_h_error(chartInstance);
  }
}

static void c1_e_error(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  const mxArray *c1_y = NULL;
  static char_T c1_cv58[12] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'm',
    'e', 'm' };

  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv58, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c1_y));
}

static void c1_f_error(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  int32_T c1_varargin_2)
{
  const mxArray *c1_y = NULL;
  const mxArray *c1_b_y = NULL;
  static char_T c1_cv59[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 's', 'g',
    'e', 's', 'd', 'd' };

  const mxArray *c1_c_y = NULL;
  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv13, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv59, 10, 0U, 1U, 0U, 2, 1, 14),
                false);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_varargin_2, 6, 0U, 0U, 0U, 0),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    3U, 14, c1_y, 14, c1_b_y, 14, c1_c_y));
}

static void c1_ceval_xgesvd(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  c1_emxArray_real32_T *c1_A, c1_emxArray_real32_T *c1_U, real32_T c1_S_data[],
  int32_T c1_S_size[1], real32_T c1_V[25], int32_T *c1_info)
{
  int32_T c1_m;
  int32_T c1_minnm;
  int32_T c1_i479;
  int32_T c1_b_info;
  int32_T c1_superb_size[1];
  int32_T c1_i480;
  int32_T c1_i481;
  ptrdiff_t c1_info_t;
  real32_T c1_Vt[25];
  real32_T c1_superb_data[4];
  int32_T c1_i482;
  int32_T c1_i483;
  c1_m = c1_A->size[0];
  c1_minnm = muIntScalarMin_sint32(5, c1_m);
  c1_i479 = c1_U->size[0] * c1_U->size[1];
  c1_U->size[0] = c1_A->size[0];
  c1_U->size[1] = c1_minnm;
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_U, c1_i479, &c1_fg_emlrtRTEI);
  c1_S_size[0] = c1_minnm;
  if (!(c1_A->size[0] == 0)) {
    if (c1_minnm > 1) {
      c1_superb_size[0] = c1_minnm - 1;
    } else {
      c1_superb_size[0] = 1;
    }

    c1_info_t = LAPACKE_sgesvd(102, 'S', 'A', (ptrdiff_t)c1_A->size[0],
      (ptrdiff_t)5, &c1_A->data[0], (ptrdiff_t)c1_A->size[0], &c1_S_data[0],
      &c1_U->data[0], (ptrdiff_t)c1_A->size[0], &c1_Vt[0], (ptrdiff_t)5,
      &c1_superb_data[0]);
    c1_b_info = (int32_T)c1_info_t;
  } else {
    c1_b_info = 0;
  }

  c1_i480 = 0;
  for (c1_i481 = 0; c1_i481 < 5; c1_i481++) {
    c1_i482 = 0;
    for (c1_i483 = 0; c1_i483 < 5; c1_i483++) {
      c1_V[c1_i483 + c1_i480] = c1_Vt[c1_i482 + c1_i481];
      c1_i482 += 5;
    }

    c1_i480 += 5;
  }

  if (c1_b_info < 0) {
    if (c1_b_info == -1010) {
      c1_e_error(chartInstance);
    } else {
      c1_g_error(chartInstance, c1_b_info);
    }
  }

  *c1_info = c1_b_info;
}

static void c1_g_error(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  int32_T c1_varargin_2)
{
  const mxArray *c1_y = NULL;
  const mxArray *c1_b_y = NULL;
  static char_T c1_cv60[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 's', 'g',
    'e', 's', 'v', 'd' };

  const mxArray *c1_c_y = NULL;
  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv13, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv60, 10, 0U, 1U, 0U, 2, 1, 14),
                false);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_varargin_2, 6, 0U, 0U, 0U, 0),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    3U, 14, c1_y, 14, c1_b_y, 14, c1_c_y));
}

static void c1_h_error(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  const mxArray *c1_y = NULL;
  static char_T c1_cv61[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r',
    'g', 'e', 'n', 'c', 'e' };

  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv61, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c1_y));
}

static void c1_warning(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  const mxArray *c1_y = NULL;
  static char_T c1_cv62[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c1_b_y = NULL;
  static char_T c1_cv63[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c1_c_y = NULL;
  static char_T c1_msgID[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't',
    'r', 'i', 'x' };

  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv62, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv63, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_msgID, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c1_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    2U, 14, c1_b_y, 14, c1_c_y));
}

static void c1_evaluateTForm(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, real32_T c1_tform[9], c1_emxArray_real32_T *c1_points,
  c1_emxArray_real32_T *c1_dis)
{
  int32_T c1_i484;
  int32_T c1_i485;
  int32_T c1_iv22[2];
  real_T c1_numPoints;
  int32_T c1_i486;
  int32_T c1_i487;
  int32_T c1_i488;
  int32_T c1_i489;
  int32_T c1_iv23[2];
  int32_T c1_iv24[2];
  int32_T c1_i490;
  int32_T c1_i491;
  int32_T c1_i492;
  int32_T c1_i493;
  int32_T c1_iv25[2];
  int32_T c1_iv26[2];
  int32_T c1_result;
  int32_T c1_i494;
  int32_T c1_i495;
  int32_T c1_i496;
  int32_T c1_i497;
  int32_T c1_iv27[2];
  int32_T c1_iv28[2];
  int32_T c1_i498;
  int32_T c1_i499;
  int32_T c1_iv29[2];
  int32_T c1_i500;
  int32_T c1_i501;
  int32_T c1_i502;
  int32_T c1_iv30[2];
  int32_T c1_i503;
  int32_T c1_i504;
  int32_T c1_i505;
  boolean_T c1_b21;
  int32_T c1_iv31[2];
  int32_T c1_i506;
  int32_T c1_i507;
  int32_T c1_iv32[2];
  const mxArray *c1_y = NULL;
  int32_T c1_i508;
  int32_T c1_i509;
  int32_T c1_i510;
  int32_T c1_iv33[2];
  int32_T c1_i511;
  int32_T c1_iv34[2];
  int32_T c1_iv35[2];
  int32_T c1_i512;
  int32_T c1_i513;
  int32_T c1_iv36[2];
  const mxArray *c1_b_y = NULL;
  boolean_T c1_empty_non_axis_sizes;
  int32_T c1_i514;
  int32_T c1_i515;
  int32_T c1_i516;
  int32_T c1_i517;
  int32_T c1_i518;
  int32_T c1_i519;
  int32_T c1_iv37[2];
  int32_T c1_iv38[2];
  int32_T c1_b_result;
  int32_T c1_iv39[2];
  int32_T c1_i520;
  int32_T c1_i521;
  int32_T c1_c_result;
  int32_T c1_iv40[2];
  c1_cell_wrap_20 c1_reshapes[2];
  int32_T c1_i522;
  int32_T c1_b_reshapes;
  int32_T c1_c_reshapes;
  int32_T c1_loop_ub;
  int32_T c1_i523;
  c1_emxArray_real32_T *c1_b_points;
  int32_T c1_i524;
  int32_T c1_i525;
  int32_T c1_i526;
  int32_T c1_b_loop_ub;
  int32_T c1_i527;
  c1_emxArray_real32_T *c1_pt1h;
  int32_T c1_c_loop_ub;
  int32_T c1_d_result[2];
  int32_T c1_i528;
  int32_T c1_i529;
  int32_T c1_d_loop_ub;
  int32_T c1_i530;
  int32_T c1_e_loop_ub;
  int32_T c1_f_loop_ub;
  int32_T c1_i531;
  int32_T c1_i532;
  int32_T c1_g_loop_ub;
  int32_T c1_i533;
  c1_emxArray_real32_T *c1_b_pt1h;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  real_T c1_c_pt1h[2];
  int32_T c1_i534;
  int32_T c1_i535;
  int32_T c1_h_loop_ub;
  int32_T c1_i536;
  int32_T c1_i537;
  int32_T c1_i538;
  c1_emxArray_real32_T *c1_w;
  int32_T c1_i_loop_ub;
  int32_T c1_i539;
  int32_T c1_i540;
  int32_T c1_i541;
  int32_T c1_j_loop_ub;
  real32_T c1_alpha1;
  int32_T c1_i542;
  real32_T c1_beta1;
  char_T c1_TRANSB;
  int32_T c1_k_loop_ub;
  char_T c1_TRANSA;
  int32_T c1_i543;
  ptrdiff_t c1_m_t;
  ptrdiff_t c1_n_t;
  ptrdiff_t c1_k_t;
  c1_emxArray_real32_T *c1_delta;
  ptrdiff_t c1_lda_t;
  boolean_T c1_b22;
  ptrdiff_t c1_ldb_t;
  ptrdiff_t c1_ldc_t;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  int32_T c1_i544;
  int32_T c1_l_loop_ub;
  int32_T c1_i545;
  int32_T c1_m_loop_ub;
  int32_T c1_i546;
  int32_T c1_i547;
  real_T c1_a[2];
  int32_T c1_i548;
  boolean_T c1_p;
  real_T c1_b[2];
  boolean_T c1_b_p;
  int32_T c1_k;
  boolean_T c1_c_p;
  const mxArray *c1_g_y = NULL;
  c1_emxArray_real32_T *c1_pt;
  int32_T c1_i549;
  int32_T c1_i550;
  int32_T c1_i551;
  int32_T c1_i552;
  int32_T c1_n_loop_ub;
  int32_T c1_i553;
  int32_T c1_i554;
  int32_T c1_i555;
  int32_T c1_iv41[2];
  int32_T c1_b_pt[2];
  int32_T c1_i556;
  int32_T c1_i557;
  int32_T c1_i558;
  int32_T c1_i559;
  int32_T c1_o_loop_ub;
  c1_emxArray_real32_T *c1_r13;
  int32_T c1_i560;
  int32_T c1_i561;
  int32_T c1_i562;
  int32_T c1_i563;
  int32_T c1_i564;
  int32_T c1_c;
  c1_emxArray_real32_T *c1_b_delta;
  int32_T c1_csz[2];
  int32_T c1_i565;
  int32_T c1_iv42[1];
  int32_T c1_i566;
  int32_T c1_i567;
  int32_T c1_i568;
  int32_T c1_p_loop_ub;
  int32_T c1_i569;
  c1_emxArray_real32_T *c1_c_delta;
  int32_T c1_i570;
  int32_T c1_i571;
  int32_T c1_q_loop_ub;
  int32_T c1_i572;
  const mxArray *c1_h_y = NULL;
  int32_T c1_i573;
  boolean_T c1_overflow;
  int32_T c1_b_k;
  int32_T c1_i574;
  int32_T c1_i575;
  int32_T c1_i576;
  int32_T c1_nx;
  int32_T c1_i577;
  real_T c1_dv4[2];
  int32_T c1_i578;
  int32_T c1_i579;
  int32_T c1_i580;
  boolean_T c1_b_overflow;
  int32_T c1_c_k;
  int32_T c1_i581;
  c1_emxArray_boolean_T *c1_r14;
  int32_T c1_i582;
  int32_T c1_r_loop_ub;
  int32_T c1_i583;
  int32_T c1_end;
  int32_T c1_trueCount;
  int32_T c1_i;
  c1_emxArray_int32_T *c1_r15;
  int32_T c1_i584;
  int32_T c1_partialTrueCount;
  int32_T c1_b_i;
  int32_T c1_b_dis;
  int32_T c1_s_loop_ub;
  int32_T c1_i585;
  boolean_T guard1 = false;
  boolean_T exitg1;
  c1_i484 = c1_points->size[0];
  c1_i485 = c1_points->size[1];
  c1_iv22[0] = c1_i484;
  c1_iv22[1] = c1_i485;
  c1_numPoints = (real_T)c1_iv22[0];
  c1_i486 = c1_points->size[0];
  c1_i487 = c1_points->size[1];
  c1_i488 = c1_points->size[0];
  c1_i489 = c1_points->size[1];
  c1_iv23[0] = c1_i486;
  c1_iv23[1] = c1_i487;
  c1_iv24[0] = c1_i488;
  c1_iv24[1] = c1_i489;
  if (!((c1_iv23[0] == 0) || (c1_iv24[1] == 0))) {
    c1_i491 = c1_points->size[0];
    c1_i493 = c1_points->size[1];
    c1_iv26[0] = c1_i491;
    c1_iv26[1] = c1_i493;
    c1_result = c1_iv26[0];
  } else {
    c1_i490 = c1_points->size[0];
    c1_i492 = c1_points->size[1];
    c1_iv25[0] = c1_i490;
    c1_iv25[1] = c1_i492;
    if (!(c1_iv25[0] == 0)) {
      c1_i495 = c1_points->size[0];
      c1_i497 = c1_points->size[1];
      c1_iv28[0] = c1_i495;
      c1_iv28[1] = c1_i497;
      c1_result = c1_iv28[0];
    } else {
      c1_i494 = c1_points->size[0];
      c1_i496 = c1_points->size[1];
      c1_iv27[0] = c1_i494;
      c1_iv27[1] = c1_i496;
      if (c1_iv27[0] > 0) {
        c1_i500 = c1_points->size[0];
        c1_i501 = c1_points->size[1];
        c1_iv30[0] = c1_i500;
        c1_iv30[1] = c1_i501;
        c1_result = c1_iv30[0];
      } else {
        c1_result = 0;
      }

      c1_i502 = c1_points->size[0];
      c1_i504 = c1_points->size[1];
      c1_iv31[0] = c1_i502;
      c1_iv31[1] = c1_i504;
      if (c1_iv31[0] > c1_result) {
        c1_i508 = c1_points->size[0];
        c1_i510 = c1_points->size[1];
        c1_iv34[0] = c1_i508;
        c1_iv34[1] = c1_i510;
        c1_result = c1_iv34[0];
      }
    }
  }

  c1_i498 = c1_points->size[0];
  c1_i499 = c1_points->size[1];
  c1_iv29[0] = c1_i498;
  c1_iv29[1] = c1_i499;
  if (c1_iv29[0] == c1_result) {
    c1_b21 = true;
  } else {
    c1_i503 = c1_points->size[0];
    c1_i505 = c1_points->size[1];
    c1_i506 = c1_points->size[0];
    c1_i507 = c1_points->size[1];
    c1_iv32[0] = c1_i503;
    c1_iv32[1] = c1_i505;
    c1_iv33[0] = c1_i506;
    c1_iv33[1] = c1_i507;
    if ((c1_iv32[0] == 0) || (c1_iv33[1] == 0)) {
      c1_b21 = true;
    } else {
      c1_b21 = false;
    }
  }

  if (c1_b21) {
  } else {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv10, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_y));
  }

  c1_i509 = c1_points->size[0];
  c1_i511 = c1_points->size[1];
  c1_iv35[0] = c1_i509;
  c1_iv35[1] = c1_i511;
  if (c1_iv35[0] == c1_result) {
    c1_b21 = true;
  } else {
    c1_i512 = c1_points->size[0];
    c1_i513 = c1_points->size[1];
    c1_iv36[0] = c1_i512;
    c1_iv36[1] = c1_i513;
    if (c1_iv36[0] == 0) {
      c1_b21 = true;
    } else {
      c1_b21 = false;
    }
  }

  if (c1_b21) {
  } else {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv10, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_b_y));
  }

  c1_empty_non_axis_sizes = (c1_result == 0);
  guard1 = false;
  if (c1_empty_non_axis_sizes) {
    guard1 = true;
  } else {
    c1_i514 = c1_points->size[0];
    c1_i515 = c1_points->size[1];
    c1_i517 = c1_points->size[0];
    c1_i519 = c1_points->size[1];
    c1_iv38[0] = c1_i514;
    c1_iv38[1] = c1_i515;
    c1_iv39[0] = c1_i517;
    c1_iv39[1] = c1_i519;
    if (!((c1_iv38[0] == 0) || (c1_iv39[1] == 0))) {
      guard1 = true;
    } else {
      c1_b_result = 0;
    }
  }

  if (guard1) {
    c1_i516 = c1_points->size[0];
    c1_i518 = c1_points->size[1];
    c1_iv37[0] = c1_i516;
    c1_iv37[1] = c1_i518;
    c1_b_result = c1_iv37[1];
  }

  if (c1_empty_non_axis_sizes) {
    c1_c_result = 1;
  } else {
    c1_i520 = c1_points->size[0];
    c1_i521 = c1_points->size[1];
    c1_iv40[0] = c1_i520;
    c1_iv40[1] = c1_i521;
    if (!(c1_iv40[0] == 0)) {
      c1_c_result = 1;
    } else {
      c1_c_result = 0;
    }
  }

  c1_emxInitMatrix_cell_wrap_20(chartInstance, c1_reshapes, &c1_gf_emlrtRTEI);
  c1_i522 = c1_reshapes[1].f1->size[0] * c1_reshapes[1].f1->size[1];
  c1_reshapes[1].f1->size[0] = c1_result;
  c1_reshapes[1].f1->size[1] = c1_c_result;
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_reshapes[1].f1, c1_i522,
    &c1_gg_emlrtRTEI);
  c1_b_reshapes = c1_reshapes[1].f1->size[0];
  c1_c_reshapes = c1_reshapes[1].f1->size[1];
  c1_loop_ub = c1_result * c1_c_result - 1;
  for (c1_i523 = 0; c1_i523 <= c1_loop_ub; c1_i523++) {
    c1_reshapes[1].f1->data[c1_i523] = 1.0F;
  }

  c1_emxInit_real32_T(chartInstance, &c1_b_points, 2, &c1_hg_emlrtRTEI);
  c1_i524 = c1_points->size[0];
  c1_i525 = c1_points->size[1];
  c1_i526 = c1_b_points->size[0] * c1_b_points->size[1];
  c1_b_points->size[0] = c1_i524;
  c1_b_points->size[1] = c1_i525;
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_b_points, c1_i526,
    &c1_hg_emlrtRTEI);
  c1_b_loop_ub = c1_i525 - 1;
  for (c1_i527 = 0; c1_i527 <= c1_b_loop_ub; c1_i527++) {
    c1_c_loop_ub = c1_i524 - 1;
    for (c1_i528 = 0; c1_i528 <= c1_c_loop_ub; c1_i528++) {
      c1_b_points->data[c1_i528 + c1_b_points->size[0] * c1_i527] =
        c1_points->data[c1_i528 + c1_points->size[0] * c1_i527];
    }
  }

  c1_emxInit_real32_T(chartInstance, &c1_pt1h, 2, &c1_ig_emlrtRTEI);
  c1_d_result[0] = c1_result;
  c1_d_result[1] = c1_b_result;
  c1_i529 = c1_pt1h->size[0] * c1_pt1h->size[1];
  c1_pt1h->size[0] = c1_d_result[0];
  c1_pt1h->size[1] = c1_d_result[1] + c1_reshapes[1].f1->size[1];
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_pt1h, c1_i529,
    &c1_ig_emlrtRTEI);
  c1_d_loop_ub = c1_d_result[1] - 1;
  for (c1_i530 = 0; c1_i530 <= c1_d_loop_ub; c1_i530++) {
    c1_e_loop_ub = c1_d_result[0] - 1;
    for (c1_i531 = 0; c1_i531 <= c1_e_loop_ub; c1_i531++) {
      c1_pt1h->data[c1_i531 + c1_pt1h->size[0] * c1_i530] = c1_b_points->
        data[c1_i531 + c1_d_result[0] * c1_i530];
    }
  }

  c1_emxFree_real32_T(chartInstance, &c1_b_points);
  c1_f_loop_ub = c1_reshapes[1].f1->size[1] - 1;
  for (c1_i532 = 0; c1_i532 <= c1_f_loop_ub; c1_i532++) {
    c1_g_loop_ub = c1_reshapes[1].f1->size[0] - 1;
    for (c1_i533 = 0; c1_i533 <= c1_g_loop_ub; c1_i533++) {
      c1_pt1h->data[c1_i533 + c1_pt1h->size[0] * (c1_i532 + c1_d_result[1])] =
        c1_reshapes[1].f1->data[c1_i533 + c1_reshapes[1].f1->size[0] * c1_i532];
    }
  }

  c1_emxFreeMatrix_cell_wrap_20(chartInstance, c1_reshapes);
  if (!((real_T)c1_pt1h->size[1] == 3.0)) {
    if ((c1_pt1h->size[0] == 1) && (c1_pt1h->size[1] == 1)) {
      c1_d_y = NULL;
      sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_cv2, 10, 0U, 1U, 0U, 2, 1, 45),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c1_d_y));
    } else {
      c1_c_y = NULL;
      sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv1, 10, 0U, 1U, 0U, 2, 1, 21),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c1_c_y));
    }
  }

  c1_emxInit_real32_T(chartInstance, &c1_b_pt1h, 2, &c1_ig_emlrtRTEI);
  if ((real_T)c1_pt1h->size[1] == 1.0) {
    c1_i534 = c1_b_pt1h->size[0] * c1_b_pt1h->size[1];
    c1_b_pt1h->size[0] = c1_pt1h->size[0];
    c1_b_pt1h->size[1] = 3;
    c1_emxEnsureCapacity_real32_T(chartInstance, c1_b_pt1h, c1_i534,
      &c1_jg_emlrtRTEI);
    c1_h_loop_ub = c1_pt1h->size[0] - 1;
    for (c1_i536 = 0; c1_i536 <= c1_h_loop_ub; c1_i536++) {
      for (c1_i538 = 0; c1_i538 < 3; c1_i538++) {
        c1_b_pt1h->data[c1_i536 + c1_b_pt1h->size[0] * c1_i538] = 0.0F;
        c1_j_loop_ub = c1_pt1h->size[1] - 1;
        for (c1_i542 = 0; c1_i542 <= c1_j_loop_ub; c1_i542++) {
          c1_b_pt1h->data[c1_i536 + c1_b_pt1h->size[0] * c1_i538] +=
            c1_pt1h->data[c1_i536 + c1_pt1h->size[0] * c1_i542] *
            c1_tform[c1_i542 + 3 * c1_i538];
        }
      }
    }
  } else {
    c1_c_pt1h[0] = (real_T)c1_pt1h->size[0];
    c1_c_pt1h[1] = 3.0;
    c1_i535 = c1_b_pt1h->size[0] * c1_b_pt1h->size[1];
    c1_b_pt1h->size[0] = (int32_T)c1_c_pt1h[0];
    c1_b_pt1h->size[1] = 3;
    c1_b_pt1h->size[0];
    c1_b_pt1h->size[1] = 3;
    c1_emxEnsureCapacity_real32_T(chartInstance, c1_b_pt1h, c1_i535,
      &c1_jg_emlrtRTEI);
    for (c1_i537 = 0; c1_i537 < 3; c1_i537++) {
      c1_i_loop_ub = c1_b_pt1h->size[0] - 1;
      for (c1_i540 = 0; c1_i540 <= c1_i_loop_ub; c1_i540++) {
        c1_b_pt1h->data[c1_i540 + c1_b_pt1h->size[0] * c1_i537] = 0.0F;
      }
    }

    if ((c1_pt1h->size[0] < 1) || (c1_pt1h->size[1] < 1)) {
    } else {
      c1_alpha1 = 1.0F;
      c1_beta1 = 0.0F;
      c1_TRANSB = 'N';
      c1_TRANSA = 'N';
      c1_m_t = (ptrdiff_t)c1_pt1h->size[0];
      c1_n_t = (ptrdiff_t)3;
      c1_k_t = (ptrdiff_t)c1_pt1h->size[1];
      c1_lda_t = (ptrdiff_t)c1_pt1h->size[0];
      c1_ldb_t = (ptrdiff_t)c1_pt1h->size[1];
      c1_ldc_t = (ptrdiff_t)c1_pt1h->size[0];
      sgemm(&c1_TRANSA, &c1_TRANSB, &c1_m_t, &c1_n_t, &c1_k_t, &c1_alpha1,
            &c1_pt1h->data[0], &c1_lda_t, &c1_tform[0], &c1_ldb_t, &c1_beta1,
            &c1_b_pt1h->data[0], &c1_ldc_t);
    }
  }

  c1_emxFree_real32_T(chartInstance, &c1_pt1h);
  c1_emxInit_real32_T1(chartInstance, &c1_w, 1, &c1_kg_emlrtRTEI);
  c1_i539 = c1_b_pt1h->size[0];
  c1_i541 = c1_w->size[0];
  c1_w->size[0] = c1_i539;
  c1_emxEnsureCapacity_real32_T1(chartInstance, c1_w, c1_i541, &c1_kg_emlrtRTEI);
  c1_k_loop_ub = c1_i539 - 1;
  for (c1_i543 = 0; c1_i543 <= c1_k_loop_ub; c1_i543++) {
    c1_w->data[c1_i543] = c1_b_pt1h->data[c1_i543 + (c1_b_pt1h->size[0] << 1)];
  }

  c1_emxInit_real32_T(chartInstance, &c1_delta, 2, &c1_ng_emlrtRTEI);
  c1_b22 = true;
  if (c1_b22) {
  } else {
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_cv10, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_e_y));
  }

  if (c1_b22) {
  } else {
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_cv10, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_f_y));
  }

  c1_i544 = c1_delta->size[0] * c1_delta->size[1];
  c1_delta->size[0] = c1_w->size[0];
  c1_delta->size[1] = 2;
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_delta, c1_i544,
    &c1_lg_emlrtRTEI);
  c1_l_loop_ub = c1_w->size[0] - 1;
  for (c1_i545 = 0; c1_i545 <= c1_l_loop_ub; c1_i545++) {
    c1_delta->data[c1_i545] = c1_w->data[c1_i545];
  }

  c1_m_loop_ub = c1_w->size[0] - 1;
  for (c1_i546 = 0; c1_i546 <= c1_m_loop_ub; c1_i546++) {
    c1_delta->data[c1_i546 + c1_delta->size[0]] = c1_w->data[c1_i546];
  }

  c1_i547 = c1_b_pt1h->size[0];
  c1_a[0] = (real_T)c1_i547;
  c1_a[1] = 2.0;
  for (c1_i548 = 0; c1_i548 < 2; c1_i548++) {
    c1_b[c1_i548] = (real_T)c1_delta->size[c1_i548];
  }

  c1_p = false;
  c1_b_p = true;
  c1_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c1_k < 2)) {
    if (!(c1_a[c1_k] == c1_b[c1_k])) {
      c1_b_p = false;
      exitg1 = true;
    } else {
      c1_k++;
    }
  }

  if (!c1_b_p) {
  } else {
    c1_p = true;
  }

  c1_c_p = c1_p;
  if (c1_c_p) {
  } else {
    c1_g_y = NULL;
    sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_cv11, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_g_y));
  }

  c1_emxInit_real32_T(chartInstance, &c1_pt, 2, &c1_mg_emlrtRTEI);
  c1_i549 = c1_b_pt1h->size[0];
  c1_i550 = c1_pt->size[0] * c1_pt->size[1];
  c1_pt->size[0] = c1_i549;
  c1_pt->size[1] = 2;
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_pt, c1_i550, &c1_mg_emlrtRTEI);
  for (c1_i551 = 0; c1_i551 < 2; c1_i551++) {
    c1_n_loop_ub = c1_i549 - 1;
    for (c1_i554 = 0; c1_i554 <= c1_n_loop_ub; c1_i554++) {
      c1_pt->data[c1_i554 + c1_pt->size[0] * c1_i551] = c1_b_pt1h->data[c1_i554
        + c1_b_pt1h->size[0] * c1_i551] / c1_delta->data[c1_i554 +
        c1_delta->size[0] * c1_i551];
    }
  }

  c1_i552 = c1_points->size[0];
  c1_i553 = c1_points->size[1];
  for (c1_i555 = 0; c1_i555 < 2; c1_i555++) {
    c1_b_pt[c1_i555] = c1_pt->size[c1_i555];
  }

  c1_iv41[0] = c1_i552;
  c1_iv41[1] = c1_i553;
  _SFD_SIZE_EQ_CHECK_ND(c1_b_pt, c1_iv41, 2);
  c1_i556 = c1_points->size[0];
  c1_i557 = c1_points->size[1];
  c1_i558 = c1_delta->size[0] * c1_delta->size[1];
  c1_delta->size[0] = c1_pt->size[0];
  c1_delta->size[1] = 2;
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_delta, c1_i558,
    &c1_ng_emlrtRTEI);
  for (c1_i559 = 0; c1_i559 < 2; c1_i559++) {
    c1_o_loop_ub = c1_pt->size[0] - 1;
    for (c1_i560 = 0; c1_i560 <= c1_o_loop_ub; c1_i560++) {
      c1_delta->data[c1_i560 + c1_delta->size[0] * c1_i559] = c1_pt->
        data[c1_i560 + c1_pt->size[0] * c1_i559] - c1_points->data[(c1_i560 +
        c1_points->size[0] * c1_i559) + c1_points->size[0] * c1_points->size[1]];
    }
  }

  c1_emxFree_real32_T(chartInstance, &c1_pt);
  c1_emxInit_real32_T1(chartInstance, &c1_r13, 1, &c1_og_emlrtRTEI);
  c1_i561 = c1_delta->size[0];
  c1_i562 = c1_delta->size[0];
  if (c1_i561 <= c1_i562) {
    c1_i564 = c1_delta->size[0];
    c1_c = c1_i564;
  } else {
    c1_i563 = c1_delta->size[0];
    c1_c = c1_i563;
  }

  c1_emxInit_real32_T1(chartInstance, &c1_b_delta, 1, &c1_pg_emlrtRTEI);
  c1_csz[0] = c1_c;
  c1_i565 = c1_r13->size[0];
  c1_r13->size[0] = c1_csz[0];
  c1_emxEnsureCapacity_real32_T1(chartInstance, c1_r13, c1_i565,
    &c1_og_emlrtRTEI);
  c1_iv42[0] = c1_csz[0];
  c1_i566 = c1_w->size[0];
  c1_w->size[0] = c1_csz[0];
  c1_emxEnsureCapacity_real32_T1(chartInstance, c1_w, c1_i566, &c1_qf_emlrtRTEI);
  c1_i567 = c1_delta->size[0];
  c1_i568 = c1_b_delta->size[0];
  c1_b_delta->size[0] = c1_i567;
  c1_emxEnsureCapacity_real32_T1(chartInstance, c1_b_delta, c1_i568,
    &c1_pg_emlrtRTEI);
  c1_p_loop_ub = c1_i567 - 1;
  for (c1_i569 = 0; c1_i569 <= c1_p_loop_ub; c1_i569++) {
    c1_b_delta->data[c1_i569] = c1_delta->data[c1_i569];
  }

  c1_emxInit_real32_T1(chartInstance, &c1_c_delta, 1, &c1_qg_emlrtRTEI);
  c1_i570 = c1_delta->size[0];
  c1_i571 = c1_c_delta->size[0];
  c1_c_delta->size[0] = c1_i570;
  c1_emxEnsureCapacity_real32_T1(chartInstance, c1_c_delta, c1_i571,
    &c1_qg_emlrtRTEI);
  c1_q_loop_ub = c1_i570 - 1;
  for (c1_i572 = 0; c1_i572 <= c1_q_loop_ub; c1_i572++) {
    c1_c_delta->data[c1_i572] = c1_delta->data[c1_i572 + c1_delta->size[0]];
  }

  if (c1_b_dimagree(chartInstance, c1_w, c1_b_delta, c1_c_delta)) {
  } else {
    c1_h_y = NULL;
    sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_cv11, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_h_y));
  }

  c1_emxFree_real32_T(chartInstance, &c1_c_delta);
  c1_emxFree_real32_T(chartInstance, &c1_b_delta);
  c1_i573 = c1_dis->size[0];
  c1_dis->size[0] = c1_csz[0];
  c1_emxEnsureCapacity_real32_T1(chartInstance, c1_dis, c1_i573,
    &c1_rg_emlrtRTEI);
  c1_overflow = ((!(1 > c1_r13->size[0])) && (c1_r13->size[0] > 2147483646));
  c1_emxFree_real32_T(chartInstance, &c1_r13);
  if (c1_overflow) {
    c1_check_forloop_overflow_error(chartInstance, true);
  }

  for (c1_b_k = 0; c1_b_k + 1 <= c1_iv42[0]; c1_b_k++) {
    c1_i574 = c1_delta->size[0];
    c1_i576 = c1_delta->size[0];
    c1_dis->data[c1_b_k] = muSingleScalarHypot(c1_delta->data[c1_b_k],
      c1_delta->data[c1_b_k + c1_delta->size[0]]);
  }

  c1_emxFree_real32_T(chartInstance, &c1_delta);
  c1_i575 = c1_b_pt1h->size[0];
  c1_nx = c1_i575;
  c1_i577 = c1_b_pt1h->size[0];
  c1_dv4[0] = (real_T)c1_i577;
  c1_dv4[1] = 1.0;
  c1_i578 = c1_w->size[0];
  c1_w->size[0] = (int32_T)c1_dv4[0];
  c1_emxEnsureCapacity_real32_T1(chartInstance, c1_w, c1_i578, &c1_sg_emlrtRTEI);
  c1_i579 = c1_b_pt1h->size[0];
  if (1 > c1_i579) {
    c1_b_overflow = false;
  } else {
    c1_i580 = c1_b_pt1h->size[0];
    c1_b_overflow = (c1_i580 > 2147483646);
  }

  if (c1_b_overflow) {
    c1_check_forloop_overflow_error(chartInstance, true);
  }

  for (c1_c_k = 0; c1_c_k + 1 <= c1_nx; c1_c_k++) {
    c1_i581 = c1_b_pt1h->size[0];
    c1_w->data[c1_c_k] = muSingleScalarAbs(c1_b_pt1h->data[c1_c_k +
      (c1_b_pt1h->size[0] << 1)]);
  }

  c1_emxFree_real32_T(chartInstance, &c1_b_pt1h);
  c1_emxInit_boolean_T(chartInstance, &c1_r14, 1, &c1_tg_emlrtRTEI);
  c1_i582 = c1_r14->size[0];
  c1_r14->size[0] = c1_w->size[0];
  c1_emxEnsureCapacity_boolean_T(chartInstance, c1_r14, c1_i582,
    &c1_tg_emlrtRTEI);
  c1_r_loop_ub = c1_w->size[0] - 1;
  for (c1_i583 = 0; c1_i583 <= c1_r_loop_ub; c1_i583++) {
    c1_r14->data[c1_i583] = (c1_w->data[c1_i583] < 1.1920929E-7F);
  }

  c1_emxFree_real32_T(chartInstance, &c1_w);
  c1_end = c1_r14->size[0] - 1;
  c1_trueCount = 0;
  for (c1_i = 0; c1_i <= c1_end; c1_i++) {
    if (c1_r14->data[c1_i]) {
      c1_trueCount++;
    }
  }

  c1_emxInit_int32_T(chartInstance, &c1_r15, 1, &c1_ug_emlrtRTEI);
  c1_i584 = c1_r15->size[0];
  c1_r15->size[0] = c1_trueCount;
  c1_emxEnsureCapacity_int32_T(chartInstance, c1_r15, c1_i584, &c1_ug_emlrtRTEI);
  c1_partialTrueCount = 0;
  for (c1_b_i = 0; c1_b_i <= c1_end; c1_b_i++) {
    if (c1_r14->data[c1_b_i]) {
      c1_r15->data[c1_partialTrueCount] = c1_b_i + 1;
      c1_partialTrueCount++;
    }
  }

  c1_emxFree_boolean_T(chartInstance, &c1_r14);
  c1_b_dis = c1_dis->size[0];
  c1_s_loop_ub = c1_r15->size[0] - 1;
  for (c1_i585 = 0; c1_i585 <= c1_s_loop_ub; c1_i585++) {
    c1_dis->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c1_r15->data[c1_i585], 1,
      c1_b_dis) - 1] = ((real32_T)rtInf);
  }

  c1_emxFree_int32_T(chartInstance, &c1_r15);
}

static boolean_T c1_b_dimagree(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T *c1_z, c1_emxArray_real32_T
  *c1_varargin_1, c1_emxArray_real32_T *c1_varargin_2)
{
  boolean_T c1_p;
  boolean_T c1_b_p;
  int32_T c1_k;
  real_T c1_d17;
  boolean_T c1_c_p;
  int32_T c1_b_k;
  real_T c1_d18;
  real_T c1_d19;
  real_T c1_d20;
  boolean_T exitg1;
  (void)chartInstance;
  c1_p = true;
  c1_b_p = true;
  c1_k = 1;
  exitg1 = false;
  while ((!exitg1) && (c1_k < 3)) {
    if (c1_k <= 1) {
      c1_d17 = (real_T)c1_z->size[0];
    } else {
      c1_d17 = 1.0;
    }

    if (c1_k <= 1) {
      c1_d18 = (real_T)c1_varargin_1->size[0];
    } else {
      c1_d18 = 1.0;
    }

    if ((int32_T)c1_d17 != (int32_T)c1_d18) {
      c1_b_p = false;
      exitg1 = true;
    } else {
      c1_k++;
    }
  }

  if (c1_b_p) {
    c1_c_p = true;
    c1_b_k = 1;
    exitg1 = false;
    while ((!exitg1) && (c1_b_k < 3)) {
      if (c1_b_k <= 1) {
        c1_d19 = (real_T)c1_z->size[0];
      } else {
        c1_d19 = 1.0;
      }

      if (c1_b_k <= 1) {
        c1_d20 = (real_T)c1_varargin_2->size[0];
      } else {
        c1_d20 = 1.0;
      }

      if ((int32_T)c1_d19 != (int32_T)c1_d20) {
        c1_c_p = false;
        exitg1 = true;
      } else {
        c1_b_k++;
      }
    }

    if (c1_c_p) {
    } else {
      c1_p = false;
    }
  } else {
    c1_p = false;
  }

  return c1_p;
}

static real32_T c1_sum(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  c1_emxArray_real32_T *c1_x)
{
  real32_T c1_y;
  boolean_T c1_b23;
  const mxArray *c1_b_y = NULL;
  int32_T c1_firstBlockLength;
  int32_T c1_nblocks;
  int32_T c1_lastBlockLength;
  boolean_T c1_overflow;
  int32_T c1_k;
  boolean_T c1_b_overflow;
  int32_T c1_ib;
  int32_T c1_xblockoffset;
  real32_T c1_bsum;
  int32_T c1_hi;
  boolean_T c1_c_overflow;
  int32_T c1_b_k;
  if ((c1_x->size[0] == 1) || ((real_T)c1_x->size[0] != 1.0)) {
    c1_b23 = true;
  } else {
    c1_b23 = false;
  }

  if (c1_b23) {
  } else {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv12, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_b_y));
  }

  if ((c1_x->size[0] == 0) || (c1_x->size[0] == 0)) {
    c1_y = 0.0F;
  } else {
    if (c1_x->size[0] <= 1024) {
      c1_firstBlockLength = c1_x->size[0];
      c1_lastBlockLength = 0;
      c1_nblocks = 1;
    } else {
      c1_firstBlockLength = 1024;
      c1_nblocks = c1_div_nzp_s32(chartInstance, c1_x->size[0], 1024, 1U, 0U, 0U);
      c1_lastBlockLength = c1_x->size[0] - (c1_nblocks << 10);
      if (c1_lastBlockLength > 0) {
        c1_nblocks++;
      } else {
        c1_lastBlockLength = 1024;
      }
    }

    c1_y = c1_x->data[0];
    c1_overflow = ((!(2 > c1_firstBlockLength)) && (c1_firstBlockLength >
      2147483646));
    if (c1_overflow) {
      c1_check_forloop_overflow_error(chartInstance, true);
    }

    for (c1_k = 1; c1_k + 1 <= c1_firstBlockLength; c1_k++) {
      c1_y += c1_x->data[c1_k];
    }

    c1_b_overflow = ((!(2 > c1_nblocks)) && (c1_nblocks > 2147483646));
    if (c1_b_overflow) {
      c1_check_forloop_overflow_error(chartInstance, true);
    }

    for (c1_ib = 2; c1_ib <= c1_nblocks; c1_ib++) {
      c1_xblockoffset = (c1_ib - 1) << 10;
      c1_bsum = c1_x->data[c1_xblockoffset];
      if (c1_ib == c1_nblocks) {
        c1_hi = c1_lastBlockLength;
      } else {
        c1_hi = 1024;
      }

      c1_c_overflow = ((!(2 > c1_hi)) && (c1_hi > 2147483646));
      if (c1_c_overflow) {
        c1_check_forloop_overflow_error(chartInstance, true);
      }

      for (c1_b_k = 1; c1_b_k + 1 <= c1_hi; c1_b_k++) {
        c1_bsum += c1_x->data[c1_xblockoffset + c1_b_k];
      }

      c1_y += c1_bsum;
    }
  }

  return c1_y;
}

static real_T c1_b_sum(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  c1_emxArray_boolean_T *c1_x)
{
  real_T c1_y;
  boolean_T c1_b24;
  const mxArray *c1_b_y = NULL;
  boolean_T c1_overflow;
  int32_T c1_k;
  if ((c1_x->size[0] == 1) || ((real_T)c1_x->size[0] != 1.0)) {
    c1_b24 = true;
  } else {
    c1_b24 = false;
  }

  if (c1_b24) {
  } else {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv12, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_b_y));
  }

  if ((c1_x->size[0] == 0) || (c1_x->size[0] == 0)) {
    c1_y = 0.0;
  } else {
    c1_y = (real_T)c1_x->data[0];
    c1_overflow = ((!(2 > c1_x->size[0])) && (c1_x->size[0] > 2147483646));
    if (c1_overflow) {
      c1_check_forloop_overflow_error(chartInstance, true);
    }

    for (c1_k = 1; c1_k + 1 <= c1_x->size[0]; c1_k++) {
      c1_y += (real_T)c1_x->data[c1_k];
    }
  }

  return c1_y;
}

static void c1_i_error(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  const mxArray *c1_y = NULL;
  const mxArray *c1_b_y = NULL;
  static char_T c1_cv64[5] = { 'l', 'o', 'g', '1', '0' };

  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv6, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv64, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c1_y, 14, c1_b_y));
}

static boolean_T c1_checkTForm(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, real32_T c1_tform_data[], int32_T c1_tform_size[2])
{
  boolean_T c1_tf;
  int32_T c1_b_size[1];
  int32_T c1_loop_ub;
  int32_T c1_i586;
  int32_T c1_tmp_size[1];
  boolean_T c1_b_data[9];
  int32_T c1_b_loop_ub;
  int32_T c1_i587;
  boolean_T c1_tmp_data[9];
  int32_T c1_c_loop_ub;
  int32_T c1_i588;
  boolean_T c1_b25;
  const mxArray *c1_y = NULL;
  boolean_T c1_overflow;
  int32_T c1_ix;
  boolean_T exitg1;
  c1_b_size[0] = c1_tform_size[0] * c1_tform_size[1];
  c1_loop_ub = c1_tform_size[0] * c1_tform_size[1] - 1;
  for (c1_i586 = 0; c1_i586 <= c1_loop_ub; c1_i586++) {
    c1_b_data[c1_i586] = muSingleScalarIsInf(c1_tform_data[c1_i586]);
  }

  c1_tmp_size[0] = c1_tform_size[0] * c1_tform_size[1];
  c1_b_loop_ub = c1_tform_size[0] * c1_tform_size[1] - 1;
  for (c1_i587 = 0; c1_i587 <= c1_b_loop_ub; c1_i587++) {
    c1_tmp_data[c1_i587] = muSingleScalarIsNaN(c1_tform_data[c1_i587]);
  }

  c1_b_size[0];
  c1_c_loop_ub = c1_b_size[0] - 1;
  for (c1_i588 = 0; c1_i588 <= c1_c_loop_ub; c1_i588++) {
    c1_b_data[c1_i588] = ((!c1_b_data[c1_i588]) && (!c1_tmp_data[c1_i588]));
  }

  if ((c1_b_size[0] == 1) || ((real_T)c1_b_size[0] != 1.0)) {
    c1_b25 = true;
  } else {
    c1_b25 = false;
  }

  if (c1_b25) {
  } else {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv14, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_y));
  }

  c1_tf = true;
  c1_overflow = ((!(1 > c1_b_size[0])) && (c1_b_size[0] > 2147483646));
  if (c1_overflow) {
    c1_check_forloop_overflow_error(chartInstance, true);
  }

  c1_ix = 0;
  exitg1 = false;
  while ((!exitg1) && (c1_ix + 1 <= c1_b_size[0])) {
    if (!c1_b_data[c1_ix]) {
      c1_tf = false;
      exitg1 = true;
    } else {
      c1_ix++;
    }
  }

  return c1_tf;
}

static boolean_T c1_any(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  c1_emxArray_boolean_T *c1_x)
{
  boolean_T c1_y;
  boolean_T c1_b26;
  const mxArray *c1_b_y = NULL;
  boolean_T c1_overflow;
  int32_T c1_ix;
  boolean_T c1_b27;
  boolean_T exitg1;
  if ((c1_x->size[0] == 1) || ((real_T)c1_x->size[0] != 1.0)) {
    c1_b26 = true;
  } else {
    c1_b26 = false;
  }

  if (c1_b26) {
  } else {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv14, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_b_y));
  }

  c1_y = false;
  c1_overflow = ((!(1 > c1_x->size[0])) && (c1_x->size[0] > 2147483646));
  if (c1_overflow) {
    c1_check_forloop_overflow_error(chartInstance, true);
  }

  c1_ix = 0;
  exitg1 = false;
  while ((!exitg1) && (c1_ix + 1 <= c1_x->size[0])) {
    c1_b27 = !c1_x->data[c1_ix];
    if (!c1_b27) {
      c1_y = true;
      exitg1 = true;
    } else {
      c1_ix++;
    }
  }

  return c1_y;
}

static real32_T c1_det(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  real32_T c1_x_data[], int32_T c1_x_size[2])
{
  real32_T c1_y;
  boolean_T c1_b28;
  const mxArray *c1_b_y = NULL;
  static char_T c1_cv65[19] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'q', 'u', 'a', 'r', 'e' };

  int32_T c1_b_x_size[2];
  int32_T c1_x;
  int32_T c1_b_x;
  int32_T c1_loop_ub;
  int32_T c1_i589;
  real32_T c1_b_x_data[9];
  int32_T c1_ipiv_data[3];
  int32_T c1_ipiv_size[2];
  int32_T c1_k;
  boolean_T c1_isodd;
  int32_T c1_b_k;
  c1_b28 = ((real_T)c1_x_size[0] == (real_T)c1_x_size[1]);
  if (c1_b28) {
  } else {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv65, 10, 0U, 1U, 0U, 2, 1, 19),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_b_y));
  }

  if ((c1_x_size[0] == 0) || (c1_x_size[1] == 0)) {
    c1_y = 1.0F;
  } else {
    c1_b_x_size[0] = c1_x_size[0];
    c1_b_x_size[1] = c1_x_size[1];
    c1_x = c1_b_x_size[0];
    c1_b_x = c1_b_x_size[1];
    c1_loop_ub = c1_x_size[0] * c1_x_size[1] - 1;
    for (c1_i589 = 0; c1_i589 <= c1_loop_ub; c1_i589++) {
      c1_b_x_data[c1_i589] = c1_x_data[c1_i589];
    }

    c1_b_xgetrf(chartInstance, c1_x_size[0], c1_x_size[1], c1_b_x_data,
                c1_b_x_size, c1_x_size[0], c1_ipiv_data, c1_ipiv_size);
    c1_y = c1_b_x_data[0];
    for (c1_k = 1; c1_k - 1 < (int32_T)((real_T)c1_b_x_size[0] + -1.0); c1_k++)
    {
      c1_y *= c1_b_x_data[c1_k + c1_b_x_size[0] * c1_k];
    }

    c1_isodd = false;
    for (c1_b_k = 0; c1_b_k < (int32_T)((real_T)c1_ipiv_size[1] - 1.0); c1_b_k++)
    {
      if ((real_T)c1_ipiv_data[c1_b_k] > 1.0 + (real_T)c1_b_k) {
        c1_isodd = !c1_isodd;
      }
    }

    if (c1_isodd) {
      c1_y = -c1_y;
    }
  }

  return c1_y;
}

static void c1_xgetrf(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
                      int32_T c1_m, int32_T c1_n, real32_T c1_A_data[], int32_T
                      c1_A_size[2], int32_T c1_lda, real32_T c1_b_A_data[],
                      int32_T c1_b_A_size[2], int32_T c1_ipiv_data[], int32_T
                      c1_ipiv_size[2])
{
  int32_T c1_A;
  int32_T c1_b_A;
  int32_T c1_loop_ub;
  int32_T c1_i590;
  c1_b_A_size[0] = c1_A_size[0];
  c1_b_A_size[1] = c1_A_size[1];
  c1_A = c1_b_A_size[0];
  c1_b_A = c1_b_A_size[1];
  c1_loop_ub = c1_A_size[0] * c1_A_size[1] - 1;
  for (c1_i590 = 0; c1_i590 <= c1_loop_ub; c1_i590++) {
    c1_b_A_data[c1_i590] = c1_A_data[c1_i590];
  }

  c1_b_xgetrf(chartInstance, c1_m, c1_n, c1_b_A_data, c1_b_A_size, c1_lda,
              c1_ipiv_data, c1_ipiv_size);
}

static void c1_j_error(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  int32_T c1_varargin_2)
{
  const mxArray *c1_y = NULL;
  const mxArray *c1_b_y = NULL;
  static char_T c1_cv66[19] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 's', 'g',
    'e', 't', 'r', 'f', '_', 'w', 'o', 'r', 'k' };

  const mxArray *c1_c_y = NULL;
  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv13, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv66, 10, 0U, 1U, 0U, 2, 1, 19),
                false);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_varargin_2, 6, 0U, 0U, 0U, 0),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    3U, 14, c1_y, 14, c1_b_y, 14, c1_c_y));
}

static const mxArray *c1_m_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_b_u;
  const mxArray *c1_y = NULL;
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_b_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_r_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i591;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_i591, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i591;
  sf_mex_destroy(&c1_b_u);
  return c1_y;
}

static void c1_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_thisId.fIdentifier = (const char *)c1_varName;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_n_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[16], int32_T c1_inData_sizes[2])
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_u_size[2];
  int32_T c1_b_u;
  int32_T c1_c_u;
  int32_T c1_loop_ub;
  int32_T c1_i592;
  const mxArray *c1_y = NULL;
  real_T c1_u_data[16];
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u_size[0] = c1_inData_sizes[0];
  c1_u_size[1] = c1_inData_sizes[1];
  c1_b_u = c1_u_size[0];
  c1_c_u = c1_u_size[1];
  c1_loop_ub = c1_inData_sizes[0] * c1_inData_sizes[1] - 1;
  for (c1_i592 = 0; c1_i592 <= c1_loop_ub; c1_i592++) {
    c1_u_data[c1_i592] = c1_inData_data[c1_i592];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", (void *)&c1_u_data, 0, 0U, 1U, 0U, 2,
    c1_u_size[0], c1_u_size[1]), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_o_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[8], int32_T c1_inData_sizes[2])
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_u_size[2];
  int32_T c1_b_u;
  int32_T c1_c_u;
  int32_T c1_loop_ub;
  int32_T c1_i593;
  const mxArray *c1_y = NULL;
  real_T c1_u_data[8];
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u_size[0] = c1_inData_sizes[0];
  c1_u_size[1] = c1_inData_sizes[1];
  c1_b_u = c1_u_size[0];
  c1_c_u = c1_u_size[1];
  c1_loop_ub = c1_inData_sizes[0] * c1_inData_sizes[1] - 1;
  for (c1_i593 = 0; c1_i593 <= c1_loop_ub; c1_i593++) {
    c1_u_data[c1_i593] = c1_inData_data[c1_i593];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", (void *)&c1_u_data, 0, 0U, 1U, 0U, 2,
    c1_u_size[0], c1_u_size[1]), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[8],
  int32_T c1_outData_sizes[2])
{
  const mxArray *c1_bBoxCornerPts;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y_data[8];
  int32_T c1_y_size[2];
  int32_T c1_loop_ub;
  int32_T c1_i594;
  int32_T c1_b_loop_ub;
  int32_T c1_i595;
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_bBoxCornerPts = sf_mex_dup(c1_mxArrayInData);
  c1_thisId.fIdentifier = (const char *)c1_varName;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_bBoxCornerPts), &c1_thisId,
                        c1_y_data, c1_y_size);
  sf_mex_destroy(&c1_bBoxCornerPts);
  c1_outData_sizes[0] = c1_y_size[0];
  c1_outData_sizes[1] = c1_y_size[1];
  c1_loop_ub = c1_y_size[1] - 1;
  for (c1_i594 = 0; c1_i594 <= c1_loop_ub; c1_i594++) {
    c1_b_loop_ub = c1_y_size[0] - 1;
    for (c1_i595 = 0; c1_i595 <= c1_b_loop_ub; c1_i595++) {
      c1_outData_data[c1_i595 + c1_outData_sizes[0] * c1_i594] =
        c1_y_data[c1_i595 + c1_y_size[0] * c1_i594];
    }
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_p_sf_marshallOut(void *chartInstanceVoid, real32_T
  c1_inData_data[1000], int32_T c1_inData_sizes[2])
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_u_size[2];
  int32_T c1_b_u;
  int32_T c1_c_u;
  int32_T c1_loop_ub;
  int32_T c1_i596;
  const mxArray *c1_y = NULL;
  real32_T c1_u_data[1000];
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u_size[0] = c1_inData_sizes[0];
  c1_u_size[1] = c1_inData_sizes[1];
  c1_b_u = c1_u_size[0];
  c1_c_u = c1_u_size[1];
  c1_loop_ub = c1_inData_sizes[0] * c1_inData_sizes[1] - 1;
  for (c1_i596 = 0; c1_i596 <= c1_loop_ub; c1_i596++) {
    c1_u_data[c1_i596] = c1_inData_data[c1_i596];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", (void *)&c1_u_data, 1, 0U, 1U, 0U, 2,
    c1_u_size[0], c1_u_size[1]), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real32_T c1_outData_data[1000],
  int32_T c1_outData_sizes[2])
{
  const mxArray *c1_newFeaturePointLocations;
  emlrtMsgIdentifier c1_thisId;
  real32_T c1_y_data[1000];
  int32_T c1_y_size[2];
  int32_T c1_loop_ub;
  int32_T c1_i597;
  int32_T c1_b_loop_ub;
  int32_T c1_i598;
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c1_newFeaturePointLocations = sf_mex_dup(c1_mxArrayInData);
  c1_thisId.fIdentifier = (const char *)c1_varName;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_newFeaturePointLocations),
                        &c1_thisId, c1_y_data, c1_y_size);
  sf_mex_destroy(&c1_newFeaturePointLocations);
  c1_outData_sizes[0] = c1_y_size[0];
  c1_outData_sizes[1] = c1_y_size[1];
  c1_loop_ub = c1_y_size[1] - 1;
  for (c1_i597 = 0; c1_i597 <= c1_loop_ub; c1_i597++) {
    c1_b_loop_ub = c1_y_size[0] - 1;
    for (c1_i598 = 0; c1_i598 <= c1_b_loop_ub; c1_i598++) {
      c1_outData_data[c1_i598 + c1_outData_sizes[0] * c1_i597] =
        c1_y_data[c1_i598 + c1_y_size[0] * c1_i597];
    }
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static uint32_T c1_s_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_method, const char_T *c1_identifier,
  boolean_T *c1_svPtr)
{
  uint32_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_method),
    &c1_thisId, c1_svPtr);
  sf_mex_destroy(&c1_b_method);
  return c1_y;
}

static uint32_T c1_t_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T *c1_svPtr)
{
  uint32_T c1_y;
  uint32_T c1_u6;
  (void)chartInstance;
  if (mxIsEmpty(c1_b_u)) {
    *c1_svPtr = false;
  } else {
    *c1_svPtr = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_u6, 1, 7, 0U, 0, 0U, 0);
    c1_y = c1_u6;
  }

  sf_mex_destroy(&c1_b_u);
  return c1_y;
}

static void c1_u_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_d_state, const char_T *c1_identifier,
  boolean_T *c1_svPtr, uint32_T c1_y[625])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_v_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_d_state), &c1_thisId,
                        c1_svPtr, c1_y);
  sf_mex_destroy(&c1_d_state);
}

static void c1_v_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T *c1_svPtr, uint32_T c1_y[625])
{
  uint32_T c1_uv11[625];
  int32_T c1_i599;
  (void)chartInstance;
  if (mxIsEmpty(c1_b_u)) {
    *c1_svPtr = false;
  } else {
    *c1_svPtr = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_uv11, 1, 7, 0U, 1, 0U, 1,
                  625);
    for (c1_i599 = 0; c1_i599 < 625; c1_i599++) {
      c1_y[c1_i599] = c1_uv11[c1_i599];
    }
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_w_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_d_state, const char_T *c1_identifier,
  boolean_T *c1_svPtr, uint32_T c1_y[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_x_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_d_state), &c1_thisId,
                        c1_svPtr, c1_y);
  sf_mex_destroy(&c1_d_state);
}

static void c1_x_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T *c1_svPtr, uint32_T c1_y[2])
{
  uint32_T c1_uv12[2];
  int32_T c1_i600;
  (void)chartInstance;
  if (mxIsEmpty(c1_b_u)) {
    *c1_svPtr = false;
  } else {
    *c1_svPtr = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_uv12, 1, 7, 0U, 1, 0U, 1,
                  2);
    for (c1_i600 = 0; c1_i600 < 2; c1_i600++) {
      c1_y[c1_i600] = c1_uv12[c1_i600];
    }
  }

  sf_mex_destroy(&c1_b_u);
}

static uint8_T c1_y_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_DetectAndTrackFace, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_ab_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_DetectAndTrackFace), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_DetectAndTrackFace);
  return c1_y;
}

static uint8_T c1_ab_emlrt_marshallIn(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u7;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_u7, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u7;
  sf_mex_destroy(&c1_b_u);
  return c1_y;
}

static void c1_b_PointTracker_normalizeScores
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance, c1_vision_PointTracker *
   c1_obj, c1_emxArray_real_T *c1_scores, c1_emxArray_boolean_T *c1_validity)
{
  int32_T c1_i601;
  int32_T c1_loop_ub;
  int32_T c1_i602;
  c1_emxArray_boolean_T *c1_r16;
  int32_T c1_i603;
  int32_T c1_b_loop_ub;
  int32_T c1_i604;
  int32_T c1_i;
  (void)c1_obj;
  c1_i601 = c1_scores->size[0];
  c1_scores->size[0];
  c1_emxEnsureCapacity_real_T1(chartInstance, c1_scores, c1_i601,
    &c1_yg_emlrtRTEI);
  c1_loop_ub = c1_scores->size[0] - 1;
  for (c1_i602 = 0; c1_i602 <= c1_loop_ub; c1_i602++) {
    c1_scores->data[c1_i602] = 1.0 - c1_scores->data[c1_i602] / 7905.0;
  }

  c1_emxInit_boolean_T(chartInstance, &c1_r16, 1, &c1_ah_emlrtRTEI);
  c1_i603 = c1_r16->size[0];
  c1_r16->size[0] = c1_validity->size[0];
  c1_emxEnsureCapacity_boolean_T(chartInstance, c1_r16, c1_i603,
    &c1_ah_emlrtRTEI);
  c1_b_loop_ub = c1_validity->size[0] - 1;
  for (c1_i604 = 0; c1_i604 <= c1_b_loop_ub; c1_i604++) {
    c1_r16->data[c1_i604] = !c1_validity->data[c1_i604];
  }

  for (c1_i = 0; c1_i < c1_r16->size[0]; c1_i++) {
    if (!c1_validity->data[c1_i]) {
      c1_scores->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, c1_i + 1, 1, c1_scores->size[0])
        - 1] = 0.0;
    }
  }

  c1_emxFree_boolean_T(chartInstance, &c1_r16);
}

static real_T c1_b_eml_rand_mt19937ar(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, uint32_T c1_d_state[625])
{
  int32_T c1_j;
  real_T c1_b_r;
  uint32_T c1_b_u[2];
  uint32_T c1_mti;
  int32_T c1_kk;
  uint32_T c1_y;
  boolean_T c1_isvalid;
  int32_T c1_b_kk;
  boolean_T c1_b_isvalid;
  uint32_T c1_b_y;
  int32_T c1_k;
  uint32_T c1_c_y;
  uint32_T c1_d_y;
  int32_T exitg1;
  boolean_T exitg2;

  /* ========================= COPYRIGHT NOTICE ============================ */
  /*  This is a uniform (0,1) pseudorandom number generator based on:        */
  /*                                                                         */
  /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
  /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
  /*                                                                         */
  /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
  /*  All rights reserved.                                                   */
  /*                                                                         */
  /*  Redistribution and use in source and binary forms, with or without     */
  /*  modification, are permitted provided that the following conditions     */
  /*  are met:                                                               */
  /*                                                                         */
  /*    1. Redistributions of source code must retain the above copyright    */
  /*       notice, this list of conditions and the following disclaimer.     */
  /*                                                                         */
  /*    2. Redistributions in binary form must reproduce the above copyright */
  /*       notice, this list of conditions and the following disclaimer      */
  /*       in the documentation and/or other materials provided with the     */
  /*       distribution.                                                     */
  /*                                                                         */
  /*    3. The names of its contributors may not be used to endorse or       */
  /*       promote products derived from this software without specific      */
  /*       prior written permission.                                         */
  /*                                                                         */
  /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
  /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
  /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
  /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
  /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
  /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
  /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
  /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
  /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
  /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
  /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
  /*                                                                         */
  /* =============================   END   ================================= */
  do {
    exitg1 = 0;
    for (c1_j = 0; c1_j < 2; c1_j++) {
      c1_mti = c1_d_state[624] + 1U;
      if ((real_T)c1_mti >= 625.0) {
        for (c1_kk = 0; c1_kk < 227; c1_kk++) {
          c1_y = (c1_d_state[c1_kk] & 2147483648U) | (c1_d_state[(int32_T)((1.0
            + (real_T)c1_kk) + 1.0) - 1] & 2147483647U);
          if ((real_T)(c1_y & 1U) == 0.0) {
            c1_b_y = c1_y >> 1U;
          } else {
            c1_b_y = c1_y >> 1U ^ 2567483615U;
          }

          c1_d_state[c1_kk] = c1_d_state[(int32_T)((1.0 + (real_T)c1_kk) + 397.0)
            - 1] ^ c1_b_y;
        }

        for (c1_b_kk = 0; c1_b_kk < 396; c1_b_kk++) {
          c1_y = (c1_d_state[c1_b_kk + 227] & 2147483648U) | (c1_d_state
            [(int32_T)((228.0 + (real_T)c1_b_kk) + 1.0) - 1] & 2147483647U);
          if ((real_T)(c1_y & 1U) == 0.0) {
            c1_d_y = c1_y >> 1U;
          } else {
            c1_d_y = c1_y >> 1U ^ 2567483615U;
          }

          c1_d_state[c1_b_kk + 227] = c1_d_state[(int32_T)(((228.0 + (real_T)
            c1_b_kk) + 1.0) - 228.0) - 1] ^ c1_d_y;
        }

        c1_y = (c1_d_state[623] & 2147483648U) | (c1_d_state[0] & 2147483647U);
        if ((real_T)(c1_y & 1U) == 0.0) {
          c1_c_y = c1_y >> 1U;
        } else {
          c1_c_y = c1_y >> 1U ^ 2567483615U;
        }

        c1_d_state[623] = c1_d_state[396] ^ c1_c_y;
        c1_mti = 1U;
      }

      c1_y = c1_d_state[(int32_T)c1_mti - 1];
      c1_d_state[624] = c1_mti;
      c1_y ^= c1_y >> 11U;
      c1_y ^= c1_y << 7U & 2636928640U;
      c1_y ^= c1_y << 15U & 4022730752U;
      c1_y ^= c1_y >> 18U;
      c1_b_u[c1_j] = c1_y;
    }

    c1_b_r = 1.1102230246251565E-16 * ((real_T)(c1_b_u[0] >> 5U) * 6.7108864E+7
      + (real_T)(c1_b_u[1] >> 6U));
    if (c1_b_r == 0.0) {
      if (((real_T)c1_d_state[624] >= 1.0) && ((real_T)c1_d_state[624] < 625.0))
      {
        c1_isvalid = true;
      } else {
        c1_isvalid = false;
      }

      c1_b_isvalid = c1_isvalid;
      if (c1_isvalid) {
        c1_b_isvalid = false;
        c1_k = 0;
        exitg2 = false;
        while ((!exitg2) && (c1_k + 1 < 625)) {
          if ((real_T)c1_d_state[c1_k] == 0.0) {
            c1_k++;
          } else {
            c1_b_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!c1_b_isvalid) {
        c1_d_error(chartInstance);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c1_b_r;
}

static void c1_b_xgetrf(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  int32_T c1_m, int32_T c1_n, real32_T c1_A_data[], int32_T c1_A_size[2],
  int32_T c1_lda, int32_T c1_ipiv_data[], int32_T c1_ipiv_size[2])
{
  int32_T c1_minval;
  int32_T c1_maxval;
  int32_T c1_ipiv;
  int32_T c1_b_ipiv;
  ptrdiff_t c1_a;
  int32_T c1_outsize[2];
  const mxArray *c1_y = NULL;
  static char_T c1_cv67[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a',
    'x', 's', 'i', 'z', 'e' };

  int32_T c1_ipiv_t_size[1];
  int32_T c1_A[1];
  ptrdiff_t c1_info_t;
  ptrdiff_t c1_ipiv_t_data[3];
  int32_T c1_info;
  int32_T c1_NPIV;
  int32_T c1_k;
  if ((c1_A_size[0] == 0) || (c1_A_size[1] == 0)) {
    c1_ipiv_size[0] = 1;
    c1_ipiv_size[1] = 0;
    c1_ipiv = c1_ipiv_size[0];
    c1_b_ipiv = c1_ipiv_size[1];
  } else {
    c1_minval = muIntScalarMin_sint32(c1_m, c1_n);
    if ((real_T)c1_minval > 1.0) {
      c1_maxval = c1_minval;
    } else {
      c1_maxval = 1;
    }

    c1_a = 0;
    c1_outsize[0] = c1_maxval;
    if ((real_T)c1_outsize[0] == (real_T)c1_maxval) {
    } else {
      c1_y = NULL;
      sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv67, 10, 0U, 1U, 0U, 2, 1, 15),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14, c1_y);
    }

    c1_ipiv_t_size[0] = c1_outsize[0];
    c1_A[0] = c1_A_size[0] * c1_A_size[1];
    c1_info_t = LAPACKE_sgetrf_work(102, (ptrdiff_t)c1_m, (ptrdiff_t)c1_n,
      &c1_A_data[0], (ptrdiff_t)c1_lda, &c1_ipiv_t_data[0]);
    c1_info = (int32_T)c1_info_t;
    c1_ipiv_size[0] = 1;
    c1_ipiv_size[1] = c1_ipiv_t_size[0];
    c1_NPIV = c1_ipiv_size[1] - 1;
    if (c1_info < 0) {
      if (c1_info == -1010) {
        c1_e_error(chartInstance);
      } else {
        c1_j_error(chartInstance, c1_info);
      }
    }

    for (c1_k = 0; c1_k <= c1_NPIV; c1_k++) {
      c1_ipiv_data[c1_k] = (int32_T)c1_ipiv_t_data[c1_k];
    }
  }
}

static void c1_emxEnsureCapacity_real_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real_T *c1_emxArray, int32_T c1_oldNumel, const
  emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_newNumel;
  int32_T c1_i;
  int32_T c1_newCapacity;
  void *c1_newData;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(real_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, (void *)c1_emxArray->data, sizeof(real_T) * (uint32_T)
             c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex((void *)c1_emxArray->data);
      }
    }

    c1_emxArray->data = (real_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxEnsureCapacity_boolean_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_boolean_T *c1_emxArray, int32_T c1_oldNumel, const
  emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_newNumel;
  int32_T c1_i;
  int32_T c1_newCapacity;
  void *c1_newData;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(boolean_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, (void *)c1_emxArray->data, sizeof(boolean_T)
             * (uint32_T)c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex((void *)c1_emxArray->data);
      }
    }

    c1_emxArray->data = (boolean_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxEnsureCapacity_int32_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_int32_T *c1_emxArray, int32_T c1_oldNumel, const
  emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_newNumel;
  int32_T c1_i;
  int32_T c1_newCapacity;
  void *c1_newData;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(int32_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, (void *)c1_emxArray->data, sizeof(int32_T) * (uint32_T)
             c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex((void *)c1_emxArray->data);
      }
    }

    c1_emxArray->data = (int32_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxEnsureCapacity_real32_T(SFc1_DetectAndTrackFaceInstanceStruct *
  chartInstance, c1_emxArray_real32_T *c1_emxArray, int32_T c1_oldNumel, const
  emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_newNumel;
  int32_T c1_i;
  int32_T c1_newCapacity;
  void *c1_newData;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(real32_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, (void *)c1_emxArray->data, sizeof(real32_T) * (uint32_T)
             c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex((void *)c1_emxArray->data);
      }
    }

    c1_emxArray->data = (real32_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxInit_boolean_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_boolean_T **c1_pEmxArray, int32_T c1_numDimensions,
  const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_boolean_T *c1_emxArray;
  int32_T c1_i;
  *c1_pEmxArray = (c1_emxArray_boolean_T *)emlrtMallocMex(sizeof
    (c1_emxArray_boolean_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (boolean_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * c1_numDimensions));
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxInit_real32_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T **c1_pEmxArray, int32_T c1_numDimensions,
  const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_real32_T *c1_emxArray;
  int32_T c1_i;
  *c1_pEmxArray = (c1_emxArray_real32_T *)emlrtMallocMex(sizeof
    (c1_emxArray_real32_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (real32_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * c1_numDimensions));
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxInit_real_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real_T **c1_pEmxArray, int32_T c1_numDimensions,
  const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_real_T *c1_emxArray;
  int32_T c1_i;
  *c1_pEmxArray = (c1_emxArray_real_T *)emlrtMallocMex(sizeof(c1_emxArray_real_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (real_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * c1_numDimensions));
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxInit_int32_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_int32_T **c1_pEmxArray, int32_T c1_numDimensions,
  const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_int32_T *c1_emxArray;
  int32_T c1_i;
  *c1_pEmxArray = (c1_emxArray_int32_T *)emlrtMallocMex(sizeof
    (c1_emxArray_int32_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (int32_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * c1_numDimensions));
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxFree_boolean_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_boolean_T **c1_pEmxArray)
{
  (void)chartInstance;
  if (*c1_pEmxArray != (c1_emxArray_boolean_T *)NULL) {
    if (((*c1_pEmxArray)->data != (boolean_T *)NULL) && (*c1_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((void *)(*c1_pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*c1_pEmxArray)->size);
    emlrtFreeMex((void *)*c1_pEmxArray);
    *c1_pEmxArray = (c1_emxArray_boolean_T *)NULL;
  }
}

static void c1_emxFree_real32_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T **c1_pEmxArray)
{
  (void)chartInstance;
  if (*c1_pEmxArray != (c1_emxArray_real32_T *)NULL) {
    if (((*c1_pEmxArray)->data != (real32_T *)NULL) && (*c1_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((void *)(*c1_pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*c1_pEmxArray)->size);
    emlrtFreeMex((void *)*c1_pEmxArray);
    *c1_pEmxArray = (c1_emxArray_real32_T *)NULL;
  }
}

static void c1_emxFree_real_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real_T **c1_pEmxArray)
{
  (void)chartInstance;
  if (*c1_pEmxArray != (c1_emxArray_real_T *)NULL) {
    if (((*c1_pEmxArray)->data != (real_T *)NULL) && (*c1_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((void *)(*c1_pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*c1_pEmxArray)->size);
    emlrtFreeMex((void *)*c1_pEmxArray);
    *c1_pEmxArray = (c1_emxArray_real_T *)NULL;
  }
}

static void c1_emxFree_int32_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_int32_T **c1_pEmxArray)
{
  (void)chartInstance;
  if (*c1_pEmxArray != (c1_emxArray_int32_T *)NULL) {
    if (((*c1_pEmxArray)->data != (int32_T *)NULL) && (*c1_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((void *)(*c1_pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*c1_pEmxArray)->size);
    emlrtFreeMex((void *)*c1_pEmxArray);
    *c1_pEmxArray = (c1_emxArray_int32_T *)NULL;
  }
}

static void c1_emxEnsureCapacity_uint8_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_uint8_T *c1_emxArray, int32_T c1_oldNumel, const
  emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_newNumel;
  int32_T c1_i;
  int32_T c1_newCapacity;
  void *c1_newData;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(uint8_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, (void *)c1_emxArray->data, sizeof(uint8_T) * (uint32_T)
             c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex((void *)c1_emxArray->data);
      }
    }

    c1_emxArray->data = (uint8_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxInit_uint8_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_uint8_T **c1_pEmxArray, int32_T c1_numDimensions,
  const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_uint8_T *c1_emxArray;
  int32_T c1_i;
  *c1_pEmxArray = (c1_emxArray_uint8_T *)emlrtMallocMex(sizeof
    (c1_emxArray_uint8_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (uint8_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * c1_numDimensions));
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxFree_uint8_T(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_uint8_T **c1_pEmxArray)
{
  (void)chartInstance;
  if (*c1_pEmxArray != (c1_emxArray_uint8_T *)NULL) {
    if (((*c1_pEmxArray)->data != (uint8_T *)NULL) && (*c1_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((void *)(*c1_pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*c1_pEmxArray)->size);
    emlrtFreeMex((void *)*c1_pEmxArray);
    *c1_pEmxArray = (c1_emxArray_uint8_T *)NULL;
  }
}

static void c1_emxEnsureCapacity_real_T1(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real_T *c1_emxArray, int32_T c1_oldNumel, const
  emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_newNumel;
  int32_T c1_i;
  int32_T c1_newCapacity;
  void *c1_newData;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(real_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, (void *)c1_emxArray->data, sizeof(real_T) * (uint32_T)
             c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex((void *)c1_emxArray->data);
      }
    }

    c1_emxArray->data = (real_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxInit_real_T1(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real_T **c1_pEmxArray, int32_T c1_numDimensions,
  const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_real_T *c1_emxArray;
  int32_T c1_i;
  *c1_pEmxArray = (c1_emxArray_real_T *)emlrtMallocMex(sizeof(c1_emxArray_real_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (real_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * c1_numDimensions));
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxEnsureCapacity_real32_T1(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T *c1_emxArray, int32_T c1_oldNumel, const
  emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_newNumel;
  int32_T c1_i;
  int32_T c1_newCapacity;
  void *c1_newData;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(real32_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, (void *)c1_emxArray->data, sizeof(real32_T) * (uint32_T)
             c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex((void *)c1_emxArray->data);
      }
    }

    c1_emxArray->data = (real32_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxInit_real32_T1(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T **c1_pEmxArray, int32_T c1_numDimensions,
  const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_real32_T *c1_emxArray;
  int32_T c1_i;
  *c1_pEmxArray = (c1_emxArray_real32_T *)emlrtMallocMex(sizeof
    (c1_emxArray_real32_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (real32_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * c1_numDimensions));
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxEnsureCapacity_boolean_T1
  (SFc1_DetectAndTrackFaceInstanceStruct *chartInstance, c1_emxArray_boolean_T
   *c1_emxArray, int32_T c1_oldNumel, const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_newNumel;
  int32_T c1_i;
  int32_T c1_newCapacity;
  void *c1_newData;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(boolean_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, (void *)c1_emxArray->data, sizeof(boolean_T)
             * (uint32_T)c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex((void *)c1_emxArray->data);
      }
    }

    c1_emxArray->data = (boolean_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxEnsureCapacity_real32_T2(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T *c1_emxArray, int32_T c1_oldNumel, const
  emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_newNumel;
  int32_T c1_i;
  int32_T c1_newCapacity;
  void *c1_newData;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(real32_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, (void *)c1_emxArray->data, sizeof(real32_T) * (uint32_T)
             c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex((void *)c1_emxArray->data);
      }
    }

    c1_emxArray->data = (real32_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxInit_real32_T2(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_real32_T **c1_pEmxArray, int32_T c1_numDimensions,
  const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_real32_T *c1_emxArray;
  int32_T c1_i;
  *c1_pEmxArray = (c1_emxArray_real32_T *)emlrtMallocMex(sizeof
    (c1_emxArray_real32_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (real32_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * c1_numDimensions));
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxInit_boolean_T1(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_emxArray_boolean_T **c1_pEmxArray, int32_T c1_numDimensions,
  const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_boolean_T *c1_emxArray;
  int32_T c1_i;
  *c1_pEmxArray = (c1_emxArray_boolean_T *)emlrtMallocMex(sizeof
    (c1_emxArray_boolean_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (boolean_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * c1_numDimensions));
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, chartInstance->c1_fEmlrtCtx);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxInitStruct_cell_19(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_cell_19 *c1_pStruct, const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxInit_real32_T(chartInstance, &c1_pStruct->f1, 2, c1_srcLocation);
  c1_emxInit_real_T(chartInstance, &c1_pStruct->f2, 2, c1_srcLocation);
  c1_emxInit_real_T(chartInstance, &c1_pStruct->f3, 2, c1_srcLocation);
  c1_emxInit_real32_T(chartInstance, &c1_pStruct->f4, 2, c1_srcLocation);
}

static void c1_emxFreeStruct_cell_19(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, c1_cell_19 *c1_pStruct)
{
  c1_emxFree_real32_T(chartInstance, &c1_pStruct->f1);
  c1_emxFree_real_T(chartInstance, &c1_pStruct->f2);
  c1_emxFree_real_T(chartInstance, &c1_pStruct->f3);
  c1_emxFree_real32_T(chartInstance, &c1_pStruct->f4);
}

static void c1_emxInitMatrix_cell_wrap_20(SFc1_DetectAndTrackFaceInstanceStruct *
  chartInstance, c1_cell_wrap_20 c1_pMatrix[2], const emlrtRTEInfo
  *c1_srcLocation)
{
  int32_T c1_i;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_emxInitStruct_cell_wrap_20(chartInstance, &c1_pMatrix[c1_i],
      c1_srcLocation);
  }
}

static void c1_emxInitStruct_cell_wrap_20(SFc1_DetectAndTrackFaceInstanceStruct *
  chartInstance, c1_cell_wrap_20 *c1_pStruct, const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxInit_real32_T(chartInstance, &c1_pStruct->f1, 2, c1_srcLocation);
}

static void c1_emxFreeMatrix_cell_wrap_20(SFc1_DetectAndTrackFaceInstanceStruct *
  chartInstance, c1_cell_wrap_20 c1_pMatrix[2])
{
  int32_T c1_i;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_emxFreeStruct_cell_wrap_20(chartInstance, &c1_pMatrix[c1_i]);
  }
}

static void c1_emxFreeStruct_cell_wrap_20(SFc1_DetectAndTrackFaceInstanceStruct *
  chartInstance, c1_cell_wrap_20 *c1_pStruct)
{
  c1_emxFree_real32_T(chartInstance, &c1_pStruct->f1);
}

static int32_T c1_div_s32_floor(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, int32_T c1_numerator, int32_T c1_denominator, uint32_T
  c1_ssid_src_loc, int32_T c1_offset_src_loc, int32_T c1_length_src_loc)
{
  int32_T c1_quotient;
  uint32_T c1_absNumerator;
  uint32_T c1_absDenominator;
  boolean_T c1_quotientNeedsNegation;
  uint32_T c1_tempAbsQuotient;
  (void)chartInstance;
  if (c1_denominator == 0) {
    if (c1_numerator >= 0) {
      c1_quotient = MAX_int32_T;
    } else {
      c1_quotient = MIN_int32_T;
    }

    _SFD_OVERFLOW_DETECTION(SFDB_DIVIDE_BY_ZERO, c1_ssid_src_loc,
      c1_offset_src_loc, c1_length_src_loc);
  } else {
    if (c1_numerator < 0) {
      c1_absNumerator = ~(uint32_T)c1_numerator + 1U;
    } else {
      c1_absNumerator = (uint32_T)c1_numerator;
    }

    if (c1_denominator < 0) {
      c1_absDenominator = ~(uint32_T)c1_denominator + 1U;
    } else {
      c1_absDenominator = (uint32_T)c1_denominator;
    }

    c1_quotientNeedsNegation = ((c1_numerator < 0) != (c1_denominator < 0));
    c1_tempAbsQuotient = c1_absNumerator / c1_absDenominator;
    if (c1_quotientNeedsNegation) {
      c1_absNumerator %= c1_absDenominator;
      if (c1_absNumerator > 0U) {
        c1_tempAbsQuotient++;
      }
    }

    if (c1_quotientNeedsNegation) {
      c1_quotient = -(int32_T)c1_tempAbsQuotient;
    } else {
      c1_quotient = (int32_T)c1_tempAbsQuotient;
    }
  }

  return c1_quotient;
}

static int32_T c1_div_nzp_s32(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance, int32_T c1_numerator, int32_T c1_denominator, uint32_T
  c1_ssid_src_loc, int32_T c1_offset_src_loc, int32_T c1_length_src_loc)
{
  int32_T c1_quotient;
  uint32_T c1_absNumerator;
  uint32_T c1_absDenominator;
  boolean_T c1_quotientNeedsNegation;
  uint32_T c1_tempAbsQuotient;
  (void)chartInstance;
  (void)c1_ssid_src_loc;
  (void)c1_offset_src_loc;
  (void)c1_length_src_loc;
  if (c1_numerator < 0) {
    c1_absNumerator = ~(uint32_T)c1_numerator + 1U;
  } else {
    c1_absNumerator = (uint32_T)c1_numerator;
  }

  if (c1_denominator < 0) {
    c1_absDenominator = ~(uint32_T)c1_denominator + 1U;
  } else {
    c1_absDenominator = (uint32_T)c1_denominator;
  }

  c1_quotientNeedsNegation = ((c1_numerator < 0) != (c1_denominator < 0));
  c1_tempAbsQuotient = c1_absNumerator / c1_absDenominator;
  if (c1_quotientNeedsNegation) {
    c1_quotient = -(int32_T)c1_tempAbsQuotient;
  } else {
    c1_quotient = (int32_T)c1_tempAbsQuotient;
  }

  return c1_quotient;
}

static int32_T c1__s32_d_(SFc1_DetectAndTrackFaceInstanceStruct *chartInstance,
  real_T c1_b, uint32_T c1_ssid_src_loc, int32_T c1_offset_src_loc, int32_T
  c1_length_src_loc)
{
  int32_T c1_a;
  real_T c1_b_b;
  (void)chartInstance;
  c1_a = (int32_T)c1_b;
  if (c1_b < 0.0) {
    c1_b_b = muDoubleScalarCeil(c1_b);
  } else {
    c1_b_b = muDoubleScalarFloor(c1_b);
  }

  if ((real_T)c1_a != c1_b_b) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW, c1_ssid_src_loc, c1_offset_src_loc,
      c1_length_src_loc);
  }

  return c1_a;
}

static void init_dsm_address_info(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_DetectAndTrackFaceInstanceStruct
  *chartInstance)
{
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_b_videoFrameGray = (real_T (*)[1048576])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c1_decimationFactor = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_bBox_data = (real_T (*)[16])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_bBox_sizes = (int32_T (*)[2])
    ssGetCurrentInputPortDimensions_wrapper(chartInstance->S, 2);
  chartInstance->c1_bBoxCornerPts_data = (real_T (*)[8])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c1_bBoxCornerPts_sizes = (int32_T (*)[2])
    ssGetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1);
  chartInstance->c1_featurePointLocations_data = (real32_T (*)[1000])
    ssGetInputPortSignal_wrapper(chartInstance->S, 3);
  chartInstance->c1_featurePointLocations_sizes = (int32_T (*)[2])
    ssGetCurrentInputPortDimensions_wrapper(chartInstance->S, 3);
  chartInstance->c1_newFeaturePointLocations_data = (real32_T (*)[1000])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c1_newFeaturePointLocations_sizes = (int32_T (*)[2])
    ssGetCurrentOutputPortDimensions_wrapper(chartInstance->S, 2);
  chartInstance->c1_numberOfFeaturePoints = (real_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 3);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c1_DetectAndTrackFace_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3237499174U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(674911648U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1854589310U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2001736077U);
}

mxArray* sf_c1_DetectAndTrackFace_get_post_codegen_info(void);
mxArray *sf_c1_DetectAndTrackFace_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("0X2sTJlJJosOjPnFqVxYIB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1024);
      pr[1] = (double)(1024);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(8);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(500);
      pr[1] = (double)(2);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(2);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(500);
      pr[1] = (double)(2);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c1_DetectAndTrackFace_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_DetectAndTrackFace_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,4);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "vision.internal.buildable.pointTrackerBuildable"));
  mxSetCell(mxcell3p, 1, mxCreateString(
             "images.internal.coder.buildable.Grayto8Buildable"));
  mxSetCell(mxcell3p, 2, mxCreateString("coder.internal.blas.BLASApi"));
  mxSetCell(mxcell3p, 3, mxCreateString("coder.internal.lapack.LAPACKApi"));
  return(mxcell3p);
}

mxArray *sf_c1_DetectAndTrackFace_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_functions");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString(
    "pointTrackerBuildable_pointTracker_construct");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_DetectAndTrackFace_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_DetectAndTrackFace_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c1_DetectAndTrackFace(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[5],T\"bBoxCornerPts\",},{M[1],M[8],T\"newFeaturePointLocations\",},{M[1],M[11],T\"numberOfFeaturePoints\",},{M[4],M[0],T\"bboxPoints\",S'l','i','p'{{M1x2[296 306],M[0],}}},{M[4],M[0],T\"first_time\",S'l','i','p'{{M1x2[318 328],M[0],}}},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[523 529],M[1],T\"/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/randfun/private/eml_rand.m\"}}},{M[4],M[0],T\"numPts\",S'l','i','p'{{M1x2[340 346],M[0],}}},{M[4],M[0],T\"oldPoints\",S'l','i','p'{{M1x2[275 284],M[0],}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/randfun/private/eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/randfun/private/eml_rand_mt19937ar_stateful.m\"}}}}",
    "100 S1x2'type','srcId','name','auxInfo'{{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/randfun/private/eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c1_DetectAndTrackFace\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 12, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_DetectAndTrackFace_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_DetectAndTrackFaceInstanceStruct *chartInstance =
      (SFc1_DetectAndTrackFaceInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DetectAndTrackFaceMachineNumber_,
           1,
           1,
           1,
           0,
           7,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_DetectAndTrackFaceMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_DetectAndTrackFaceMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DetectAndTrackFaceMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"videoFrameGray");
          _SFD_SET_DATA_PROPS(1,1,1,0,"decimationFactor");
          _SFD_SET_DATA_PROPS(2,1,1,0,"bBox");
          _SFD_SET_DATA_PROPS(3,1,1,0,"featurePointLocations");
          _SFD_SET_DATA_PROPS(4,2,0,1,"bBoxCornerPts");
          _SFD_SET_DATA_PROPS(5,2,0,1,"newFeaturePointLocations");
          _SFD_SET_DATA_PROPS(6,2,0,1,"numberOfFeaturePoints");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,9,0,0,0,0,0,2,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",87,-1,3039);
        _SFD_CV_INIT_EML_IF(0,1,0,383,407,-1,479);
        _SFD_CV_INIT_EML_IF(0,1,1,481,503,-1,531);
        _SFD_CV_INIT_EML_IF(0,1,2,534,555,-1,590);
        _SFD_CV_INIT_EML_IF(0,1,3,598,616,-1,636);
        _SFD_CV_INIT_EML_IF(0,1,4,773,795,-1,880);
        _SFD_CV_INIT_EML_IF(0,1,5,882,896,1918,3003);
        _SFD_CV_INIT_EML_IF(0,1,6,901,935,1829,1916);
        _SFD_CV_INIT_EML_IF(0,1,7,1171,1196,-1,1288);
        _SFD_CV_INIT_EML_IF(0,1,8,2217,2232,2899,2998);

        {
          static int condStart[] = { 905 };

          static int condEnd[] = { 935 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,904,935,1,0,&(condStart[0]),&(condEnd[0]),
                                2,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1175 };

          static int condEnd[] = { 1196 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,1174,1196,1,1,&(condStart[0]),&(condEnd[0]),
                                2,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,885,896,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,2220,2232,-1,5);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1024U;
          dimVector[1]= 1024U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_h_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2U;
          dimVector[1]= 8U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_n_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 500U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_p_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_o_sf_marshallOut,(MexInFcnForType)
            c1_l_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 500U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_p_sf_marshallOut,(MexInFcnForType)
            c1_m_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DetectAndTrackFaceMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_DetectAndTrackFaceInstanceStruct *chartInstance =
      (SFc1_DetectAndTrackFaceInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c1_b_videoFrameGray);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c1_decimationFactor);
        _SFD_SET_DATA_VALUE_PTR_VAR_DIM(2U, (void *)chartInstance->c1_bBox_data,
          (void *)chartInstance->c1_bBox_sizes);
        _SFD_SET_DATA_VALUE_PTR_VAR_DIM(4U, (void *)
          chartInstance->c1_bBoxCornerPts_data, (void *)
          chartInstance->c1_bBoxCornerPts_sizes);
        _SFD_SET_DATA_VALUE_PTR_VAR_DIM(3U, (void *)
          chartInstance->c1_featurePointLocations_data, (void *)
          chartInstance->c1_featurePointLocations_sizes);
        _SFD_SET_DATA_VALUE_PTR_VAR_DIM(5U, (void *)
          chartInstance->c1_newFeaturePointLocations_data, (void *)
          chartInstance->c1_newFeaturePointLocations_sizes);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)
          chartInstance->c1_numberOfFeaturePoints);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sIsP9toTX8dPy9PDnhTIqUB";
}

static void sf_opaque_initialize_c1_DetectAndTrackFace(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_DetectAndTrackFaceInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_DetectAndTrackFace((SFc1_DetectAndTrackFaceInstanceStruct*)
    chartInstanceVar);
  initialize_c1_DetectAndTrackFace((SFc1_DetectAndTrackFaceInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_DetectAndTrackFace(void *chartInstanceVar)
{
  enable_c1_DetectAndTrackFace((SFc1_DetectAndTrackFaceInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_DetectAndTrackFace(void *chartInstanceVar)
{
  disable_c1_DetectAndTrackFace((SFc1_DetectAndTrackFaceInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_DetectAndTrackFace(void *chartInstanceVar)
{
  sf_gateway_c1_DetectAndTrackFace((SFc1_DetectAndTrackFaceInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_DetectAndTrackFace(SimStruct* S)
{
  return get_sim_state_c1_DetectAndTrackFace
    ((SFc1_DetectAndTrackFaceInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_DetectAndTrackFace(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c1_DetectAndTrackFace((SFc1_DetectAndTrackFaceInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c1_DetectAndTrackFace(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_DetectAndTrackFaceInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DetectAndTrackFace_optimization_info();
    }

    finalize_c1_DetectAndTrackFace((SFc1_DetectAndTrackFaceInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_DetectAndTrackFace((SFc1_DetectAndTrackFaceInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_DetectAndTrackFace(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_DetectAndTrackFace
      ((SFc1_DetectAndTrackFaceInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c1_DetectAndTrackFace(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetInputPortDirectFeedThrough(S, 2, 1);
  ssSetInputPortDirectFeedThrough(S, 3, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DetectAndTrackFace_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 1);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2957901837U));
  ssSetChecksum1(S,(3990956039U));
  ssSetChecksum2(S,(226692490U));
  ssSetChecksum3(S,(230246818U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetSimStateCompliance(S, DISALLOW_SIM_STATE);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_DetectAndTrackFace(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_DetectAndTrackFace(SimStruct *S)
{
  SFc1_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc1_DetectAndTrackFaceInstanceStruct *)utMalloc(sizeof
    (SFc1_DetectAndTrackFaceInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_DetectAndTrackFaceInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  if (ssGetSampleTime(S, 0) == CONTINUOUS_SAMPLE_TIME && ssGetOffsetTime(S, 0) ==
      0 && ssGetNumContStates(ssGetRootSS(S)) > 0) {
    sf_error_out_about_continuous_sample_time_with_persistent_vars(S);
  }

  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_DetectAndTrackFace;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_DetectAndTrackFace;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_DetectAndTrackFace;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_DetectAndTrackFace;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_DetectAndTrackFace;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_DetectAndTrackFace;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_DetectAndTrackFace;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_DetectAndTrackFace;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_DetectAndTrackFace;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_DetectAndTrackFace;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_DetectAndTrackFace;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c1_DetectAndTrackFace(chartInstance);
}

void c1_DetectAndTrackFace_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_DetectAndTrackFace(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_DetectAndTrackFace(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_DetectAndTrackFace(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_DetectAndTrackFace_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
