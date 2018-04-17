/* Include files */

#include "DetectAndTrackFace_sfun.h"
#include "c2_DetectAndTrackFace.h"
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
static const mxArray *c2_eml_mx;
static const mxArray *c2_b_eml_mx;
static const char * c2_debug_family_names[8] = { "points", "videoFrameGray",
  "nargin", "nargout", "decimationFactor", "numberOfFeaturePoints", "bBox",
  "featurePointLocations" };

static emlrtRTEInfo c2_emlrtRTEI = { 11,/* lineNo */
  1,                                   /* colNo */
  "Detection and Tracking/Detection",  /* fName */
  "#DetectAndTrackFace:3"              /* pName */
};

static emlrtRTEInfo c2_b_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "Detection and Tracking/Detection",  /* fName */
  "#DetectAndTrackFace:3"              /* pName */
};

static emlrtRTEInfo c2_c_emlrtRTEI = { 38,/* lineNo */
  5,                                   /* colNo */
  "Detection and Tracking/Detection",  /* fName */
  "#DetectAndTrackFace:3"              /* pName */
};

static emlrtRTEInfo c2_d_emlrtRTEI = { 23,/* lineNo */
  30,                                  /* colNo */
  "Detection and Tracking/Detection",  /* fName */
  "#DetectAndTrackFace:3"              /* pName */
};

static emlrtRTEInfo c2_e_emlrtRTEI = { 359,/* lineNo */
  13,                                  /* colNo */
  "CascadeObjectDetector",             /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/CascadeObjectDetector.m"/* pName */
};

static emlrtRTEInfo c2_f_emlrtRTEI = { 23,/* lineNo */
  12,                                  /* colNo */
  "Detection and Tracking/Detection",  /* fName */
  "#DetectAndTrackFace:3"              /* pName */
};

static emlrtRTEInfo c2_g_emlrtRTEI = { 105,/* lineNo */
  25,                                  /* colNo */
  "cascadeClassifierBuildable",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+buildable/cascadeClassifierBuildable.m"/* pName */
};

static emlrtRTEInfo c2_h_emlrtRTEI = { 389,/* lineNo */
  20,                                  /* colNo */
  "CascadeObjectDetector",             /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/CascadeObjectDetector.m"/* pName */
};

static emlrtRTEInfo c2_i_emlrtRTEI = { 381,/* lineNo */
  26,                                  /* colNo */
  "CascadeObjectDetector",             /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/CascadeObjectDetector.m"/* pName */
};

static emlrtRTEInfo c2_j_emlrtRTEI = { 389,/* lineNo */
  70,                                  /* colNo */
  "CascadeObjectDetector",             /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/CascadeObjectDetector.m"/* pName */
};

static emlrtRTEInfo c2_k_emlrtRTEI = { 23,/* lineNo */
  5,                                   /* colNo */
  "Detection and Tracking/Detection",  /* fName */
  "#DetectAndTrackFace:3"              /* pName */
};

static emlrtRTEInfo c2_l_emlrtRTEI = { 33,/* lineNo */
  9,                                   /* colNo */
  "Detection and Tracking/Detection",  /* fName */
  "#DetectAndTrackFace:3"              /* pName */
};

static emlrtRTEInfo c2_m_emlrtRTEI = { 29,/* lineNo */
  41,                                  /* colNo */
  "Detection and Tracking/Detection",  /* fName */
  "#DetectAndTrackFace:3"              /* pName */
};

static emlrtRTEInfo c2_n_emlrtRTEI = { 29,/* lineNo */
  64,                                  /* colNo */
  "Detection and Tracking/Detection",  /* fName */
  "#DetectAndTrackFace:3"              /* pName */
};

static emlrtRTEInfo c2_o_emlrtRTEI = { 58,/* lineNo */
  59,                                  /* colNo */
  "detectMinEigenFeatures",            /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/detectMinEigenFeatures.m"/* pName */
};

static emlrtRTEInfo c2_p_emlrtRTEI = { 57,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_q_emlrtRTEI = { 68,/* lineNo */
  9,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_r_emlrtRTEI = { 69,/* lineNo */
  48,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_s_emlrtRTEI = { 80,/* lineNo */
  39,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_t_emlrtRTEI = { 81,/* lineNo */
  30,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_u_emlrtRTEI = { 84,/* lineNo */
  44,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_v_emlrtRTEI = { 29,/* lineNo */
  9,                                   /* colNo */
  "Detection and Tracking/Detection",  /* fName */
  "#DetectAndTrackFace:3"              /* pName */
};

static emlrtRTEInfo c2_w_emlrtRTEI = { 30,/* lineNo */
  33,                                  /* colNo */
  "Detection and Tracking/Detection",  /* fName */
  "#DetectAndTrackFace:3"              /* pName */
};

static emlrtRTEInfo c2_x_emlrtRTEI = { 30,/* lineNo */
  9,                                   /* colNo */
  "Detection and Tracking/Detection",  /* fName */
  "#DetectAndTrackFace:3"              /* pName */
};

static emlrtRTEInfo c2_y_emlrtRTEI = { 5,/* lineNo */
  5,                                   /* colNo */
  "Detection and Tracking/Detection",  /* fName */
  "#DetectAndTrackFace:3"              /* pName */
};

static emlrtRTEInfo c2_ab_emlrtRTEI = { 115,/* lineNo */
  17,                                  /* colNo */
  "cascadeClassifierBuildable",        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+buildable/cascadeClassifierBuildable.m"/* pName */
};

static emlrtRTEInfo c2_bb_emlrtRTEI = { 69,/* lineNo */
  5,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_cb_emlrtRTEI = { 78,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_db_emlrtRTEI = { 80,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_eb_emlrtRTEI = { 84,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_fb_emlrtRTEI = { 1,/* lineNo */
  43,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_gb_emlrtRTEI = { 95,/* lineNo */
  11,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_hb_emlrtRTEI = { 19,/* lineNo */
  5,                                   /* colNo */
  "checkROI",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/checkROI.m"/* pName */
};

static emlrtRTEInfo c2_ib_emlrtRTEI = { 294,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_jb_emlrtRTEI = { 15,/* lineNo */
  5,                                   /* colNo */
  "expandROI",                         /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/expandROI.m"/* pName */
};

static emlrtRTEInfo c2_kb_emlrtRTEI = { 28,/* lineNo */
  5,                                   /* colNo */
  "cropImage",                         /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/cropImage.m"/* pName */
};

static emlrtRTEInfo c2_lb_emlrtRTEI = { 118,/* lineNo */
  5,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_mb_emlrtRTEI = { 118,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_nb_emlrtRTEI = { 119,/* lineNo */
  5,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ob_emlrtRTEI = { 119,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_pb_emlrtRTEI = { 122,/* lineNo */
  5,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_qb_emlrtRTEI = { 122,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_rb_emlrtRTEI = { 123,/* lineNo */
  5,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_sb_emlrtRTEI = { 123,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_tb_emlrtRTEI = { 126,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ub_emlrtRTEI = { 127,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_vb_emlrtRTEI = { 128,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_wb_emlrtRTEI = { 131,/* lineNo */
  14,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_xb_emlrtRTEI = { 132,/* lineNo */
  14,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_yb_emlrtRTEI = { 133,/* lineNo */
  14,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ac_emlrtRTEI = { 137,/* lineNo */
  5,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_bc_emlrtRTEI = { 137,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_cc_emlrtRTEI = { 138,/* lineNo */
  5,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_dc_emlrtRTEI = { 138,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ec_emlrtRTEI = { 139,/* lineNo */
  5,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_fc_emlrtRTEI = { 139,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_gc_emlrtRTEI = { 146,/* lineNo */
  31,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_hc_emlrtRTEI = { 146,/* lineNo */
  49,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ic_emlrtRTEI = { 146,/* lineNo */
  45,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_jc_emlrtRTEI = { 146,/* lineNo */
  25,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_kc_emlrtRTEI = { 146,/* lineNo */
  5,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_lc_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c2_mc_emlrtRTEI = { 484,/* lineNo */
  12,                                  /* colNo */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/eml/padarray.m"/* pName */
};

static emlrtRTEInfo c2_nc_emlrtRTEI = { 584,/* lineNo */
  5,                                   /* colNo */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/eml/padarray.m"/* pName */
};

static emlrtRTEInfo c2_oc_emlrtRTEI = { 25,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

static emlrtRTEInfo c2_pc_emlrtRTEI = { 593,/* lineNo */
  9,                                   /* colNo */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/eml/padarray.m"/* pName */
};

static emlrtRTEInfo c2_qc_emlrtRTEI = { 594,/* lineNo */
  14,                                  /* colNo */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/eml/padarray.m"/* pName */
};

static emlrtRTEInfo c2_rc_emlrtRTEI = { 594,/* lineNo */
  36,                                  /* colNo */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/eml/padarray.m"/* pName */
};

static emlrtRTEInfo c2_sc_emlrtRTEI = { 767,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c2_tc_emlrtRTEI = { 41,/* lineNo */
  5,                                   /* colNo */
  "repmat",                            /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elmat/repmat.m"/* pName */
};

static emlrtRTEInfo c2_uc_emlrtRTEI = { 104,/* lineNo */
  26,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c2_vc_emlrtRTEI = { 32,/* lineNo */
  5,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c2_wc_emlrtRTEI = { 901,/* lineNo */
  11,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c2_xc_emlrtRTEI = { 57,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c2_yc_emlrtRTEI = { 19,/* lineNo */
  24,                                  /* colNo */
  "scalexpAllocNoCheck",               /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/eml/+coder/+internal/scalexpAllocNoCheck.m"/* pName */
};

static emlrtRTEInfo c2_ad_emlrtRTEI = { 45,/* lineNo */
  6,                                   /* colNo */
  "applyBinaryScalarFunction",         /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"/* pName */
};

static emlrtRTEInfo c2_bd_emlrtRTEI = { 49,/* lineNo */
  18,                                  /* colNo */
  "power",                             /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/ops/power.m"/* pName */
};

static emlrtRTEInfo c2_cd_emlrtRTEI = { 58,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/ops/power.m"/* pName */
};

static emlrtRTEInfo c2_dd_emlrtRTEI = { 35,/* lineNo */
  9,                                   /* colNo */
  "scalexpAllocNoCheck",               /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/eml/+coder/+internal/scalexpAllocNoCheck.m"/* pName */
};

static emlrtRTEInfo c2_ed_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "sqrt",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtRTEInfo c2_fd_emlrtRTEI = { 8,/* lineNo */
  5,                                   /* colNo */
  "findPeaks",                         /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/findPeaks.m"/* pName */
};

static emlrtRTEInfo c2_gd_emlrtRTEI = { 11,/* lineNo */
  24,                                  /* colNo */
  "findPeaks",                         /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/findPeaks.m"/* pName */
};

static emlrtRTEInfo c2_hd_emlrtRTEI = { 1,/* lineNo */
  16,                                  /* colNo */
  "findPeaks",                         /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/findPeaks.m"/* pName */
};

static emlrtRTEInfo c2_id_emlrtRTEI = { 44,/* lineNo */
  10,                                  /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c2_jd_emlrtRTEI = { 44,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c2_kd_emlrtRTEI = { 24,/* lineNo */
  5,                                   /* colNo */
  "findPeaks",                         /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/findPeaks.m"/* pName */
};

static emlrtRTEInfo c2_ld_emlrtRTEI = { 25,/* lineNo */
  5,                                   /* colNo */
  "findPeaks",                         /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/findPeaks.m"/* pName */
};

static emlrtRTEInfo c2_md_emlrtRTEI = { 30,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_nd_emlrtRTEI = { 38,/* lineNo */
  26,                                  /* colNo */
  "ind2sub",                           /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_od_emlrtRTEI = { 40,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_pd_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_qd_emlrtRTEI = { 44,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_rd_emlrtRTEI = { 21,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_sd_emlrtRTEI = { 26,/* lineNo */
  10,                                  /* colNo */
  "findPeaks",                         /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/findPeaks.m"/* pName */
};

static emlrtRTEInfo c2_td_emlrtRTEI = { 26,/* lineNo */
  21,                                  /* colNo */
  "findPeaks",                         /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/findPeaks.m"/* pName */
};

static emlrtRTEInfo c2_ud_emlrtRTEI = { 11,/* lineNo */
  5,                                   /* colNo */
  "findPeaks",                         /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/findPeaks.m"/* pName */
};

static emlrtRTEInfo c2_vd_emlrtRTEI = { 36,/* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c2_wd_emlrtRTEI = { 14,/* lineNo */
  20,                                  /* colNo */
  "imregionalmax",                     /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/eml/imregionalmax.m"/* pName */
};

static emlrtRTEInfo c2_xd_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "imregionalmax",                     /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/eml/imregionalmax.m"/* pName */
};

static emlrtRTEInfo c2_yd_emlrtRTEI = { 1,/* lineNo */
  15,                                  /* colNo */
  "imregionalmax",                     /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/eml/imregionalmax.m"/* pName */
};

static emlrtRTEInfo c2_ae_emlrtRTEI = { 1,/* lineNo */
  15,                                  /* colNo */
  "bwmorph",                           /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/eml/bwmorph.m"/* pName */
};

static emlrtRTEInfo c2_be_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "bwlookup",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/eml/bwlookup.m"/* pName */
};

static emlrtRTEInfo c2_ce_emlrtRTEI = { 151,/* lineNo */
  16,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_de_emlrtRTEI = { 162,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ee_emlrtRTEI = { 163,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_fe_emlrtRTEI = { 164,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ge_emlrtRTEI = { 165,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_he_emlrtRTEI = { 166,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ie_emlrtRTEI = { 167,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_je_emlrtRTEI = { 30,/* lineNo */
  5,                                   /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo c2_ke_emlrtRTEI = { 168,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_le_emlrtRTEI = { 171,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_me_emlrtRTEI = { 174,/* lineNo */
  32,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ne_emlrtRTEI = { 174,/* lineNo */
  42,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_oe_emlrtRTEI = { 48,/* lineNo */
  5,                                   /* colNo */
  "sub2ind",                           /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c2_pe_emlrtRTEI = { 175,/* lineNo */
  12,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_qe_emlrtRTEI = { 177,/* lineNo */
  24,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_re_emlrtRTEI = { 177,/* lineNo */
  9,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_se_emlrtRTEI = { 177,/* lineNo */
  43,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_te_emlrtRTEI = { 178,/* lineNo */
  7,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ue_emlrtRTEI = { 178,/* lineNo */
  24,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ve_emlrtRTEI = { 178,/* lineNo */
  41,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_we_emlrtRTEI = { 179,/* lineNo */
  9,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_xe_emlrtRTEI = { 179,/* lineNo */
  24,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ye_emlrtRTEI = { 179,/* lineNo */
  43,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_af_emlrtRTEI = { 177,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_bf_emlrtRTEI = { 181,/* lineNo */
  26,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_cf_emlrtRTEI = { 181,/* lineNo */
  11,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_df_emlrtRTEI = { 181,/* lineNo */
  43,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ef_emlrtRTEI = { 182,/* lineNo */
  26,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ff_emlrtRTEI = { 182,/* lineNo */
  11,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_gf_emlrtRTEI = { 182,/* lineNo */
  43,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_hf_emlrtRTEI = { 182,/* lineNo */
  7,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_if_emlrtRTEI = { 183,/* lineNo */
  26,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_jf_emlrtRTEI = { 183,/* lineNo */
  11,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_kf_emlrtRTEI = { 183,/* lineNo */
  43,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_lf_emlrtRTEI = { 181,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_mf_emlrtRTEI = { 185,/* lineNo */
  11,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_nf_emlrtRTEI = { 185,/* lineNo */
  26,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_of_emlrtRTEI = { 186,/* lineNo */
  11,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_pf_emlrtRTEI = { 186,/* lineNo */
  26,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_qf_emlrtRTEI = { 185,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_rf_emlrtRTEI = { 188,/* lineNo */
  8,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_sf_emlrtRTEI = { 188,/* lineNo */
  25,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_tf_emlrtRTEI = { 188,/* lineNo */
  42,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_uf_emlrtRTEI = { 189,/* lineNo */
  10,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_vf_emlrtRTEI = { 189,/* lineNo */
  25,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_wf_emlrtRTEI = { 189,/* lineNo */
  42,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_xf_emlrtRTEI = { 188,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_yf_emlrtRTEI = { 191,/* lineNo */
  8,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ag_emlrtRTEI = { 191,/* lineNo */
  25,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_bg_emlrtRTEI = { 191,/* lineNo */
  42,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_cg_emlrtRTEI = { 192,/* lineNo */
  10,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_dg_emlrtRTEI = { 192,/* lineNo */
  25,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_eg_emlrtRTEI = { 192,/* lineNo */
  42,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_fg_emlrtRTEI = { 191,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_gg_emlrtRTEI = { 194,/* lineNo */
  27,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_hg_emlrtRTEI = { 194,/* lineNo */
  16,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ig_emlrtRTEI = { 194,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_jg_emlrtRTEI = { 197,/* lineNo */
  23,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_kg_emlrtRTEI = { 197,/* lineNo */
  13,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_lg_emlrtRTEI = { 197,/* lineNo */
  5,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_mg_emlrtRTEI = { 197,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ng_emlrtRTEI = { 198,/* lineNo */
  23,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_og_emlrtRTEI = { 198,/* lineNo */
  13,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_pg_emlrtRTEI = { 198,/* lineNo */
  5,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_qg_emlrtRTEI = { 198,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_rg_emlrtRTEI = { 202,/* lineNo */
  16,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_sg_emlrtRTEI = { 202,/* lineNo */
  12,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_tg_emlrtRTEI = { 202,/* lineNo */
  31,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ug_emlrtRTEI = { 202,/* lineNo */
  27,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_vg_emlrtRTEI = { 203,/* lineNo */
  3,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_wg_emlrtRTEI = { 204,/* lineNo */
  3,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_xg_emlrtRTEI = { 205,/* lineNo */
  15,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_yg_emlrtRTEI = { 205,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ah_emlrtRTEI = { 158,/* lineNo */
  24,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_bh_emlrtRTEI = { 168,/* lineNo */
  10,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ch_emlrtRTEI = { 169,/* lineNo */
  10,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_dh_emlrtRTEI = { 170,/* lineNo */
  10,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_eh_emlrtRTEI = { 16,/* lineNo */
  14,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c2_fh_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "abs",                               /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elfun/abs.m"/* pName */
};

static emlrtRTEInfo c2_gh_emlrtRTEI = { 101,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_hh_emlrtRTEI = { 102,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ih_emlrtRTEI = { 103,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_jh_emlrtRTEI = { 104,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_kh_emlrtRTEI = { 105,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_lh_emlrtRTEI = { 106,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_mh_emlrtRTEI = { 109,/* lineNo */
  28,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_nh_emlrtRTEI = { 109,/* lineNo */
  31,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_oh_emlrtRTEI = { 16,/* lineNo */
  1,                                   /* colNo */
  "sub2ind",                           /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c2_ph_emlrtRTEI = { 109,/* lineNo */
  10,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_qh_emlrtRTEI = { 110,/* lineNo */
  30,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_rh_emlrtRTEI = { 110,/* lineNo */
  33,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_sh_emlrtRTEI = { 110,/* lineNo */
  12,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_th_emlrtRTEI = { 111,/* lineNo */
  30,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_uh_emlrtRTEI = { 111,/* lineNo */
  33,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_vh_emlrtRTEI = { 111,/* lineNo */
  12,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_wh_emlrtRTEI = { 112,/* lineNo */
  30,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_xh_emlrtRTEI = { 112,/* lineNo */
  33,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_yh_emlrtRTEI = { 112,/* lineNo */
  12,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ai_emlrtRTEI = { 109,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_bi_emlrtRTEI = { 100,/* lineNo */
  19,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ci_emlrtRTEI = { 109,/* lineNo */
  17,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_di_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "floor",                             /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elfun/floor.m"/* pName */
};

static emlrtRTEInfo c2_ei_emlrtRTEI = { 22,/* lineNo */
  39,                                  /* colNo */
  "excludePointsOutsideROI",           /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/excludePointsOutsideROI.m"/* pName */
};

static emlrtRTEInfo c2_fi_emlrtRTEI = { 24,/* lineNo */
  18,                                  /* colNo */
  "excludePointsOutsideROI",           /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/excludePointsOutsideROI.m"/* pName */
};

static emlrtRTEInfo c2_gi_emlrtRTEI = { 24,/* lineNo */
  40,                                  /* colNo */
  "excludePointsOutsideROI",           /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/excludePointsOutsideROI.m"/* pName */
};

static emlrtRTEInfo c2_hi_emlrtRTEI = { 25,/* lineNo */
  11,                                  /* colNo */
  "excludePointsOutsideROI",           /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/excludePointsOutsideROI.m"/* pName */
};

static emlrtRTEInfo c2_ii_emlrtRTEI = { 25,/* lineNo */
  33,                                  /* colNo */
  "excludePointsOutsideROI",           /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/excludePointsOutsideROI.m"/* pName */
};

static emlrtRTEInfo c2_ji_emlrtRTEI = { 1,/* lineNo */
  41,                                  /* colNo */
  "excludePointsOutsideROI",           /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/excludePointsOutsideROI.m"/* pName */
};

static emlrtRTEInfo c2_ki_emlrtRTEI = { 27,/* lineNo */
  5,                                   /* colNo */
  "excludePointsOutsideROI",           /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/excludePointsOutsideROI.m"/* pName */
};

static emlrtRTEInfo c2_li_emlrtRTEI = { 28,/* lineNo */
  5,                                   /* colNo */
  "excludePointsOutsideROI",           /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/excludePointsOutsideROI.m"/* pName */
};

static emlrtRTEInfo c2_mi_emlrtRTEI = { 22,/* lineNo */
  5,                                   /* colNo */
  "excludePointsOutsideROI",           /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/excludePointsOutsideROI.m"/* pName */
};

static emlrtRTEInfo c2_ni_emlrtRTEI = { 27,/* lineNo */
  32,                                  /* colNo */
  "excludePointsOutsideROI",           /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/excludePointsOutsideROI.m"/* pName */
};

static emlrtRTEInfo c2_oi_emlrtRTEI = { 28,/* lineNo */
  26,                                  /* colNo */
  "excludePointsOutsideROI",           /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/excludePointsOutsideROI.m"/* pName */
};

static emlrtRTEInfo c2_pi_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "bsxfun",                            /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elmat/bsxfun.m"/* pName */
};

static emlrtRTEInfo c2_qi_emlrtRTEI = { 14,/* lineNo */
  24,                                  /* colNo */
  "cornerPoints_cg",                   /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/cornerPoints_cg.m"/* pName */
};

static emlrtRTEInfo c2_ri_emlrtRTEI = { 16,/* lineNo */
  58,                                  /* colNo */
  "cornerPoints_cg",                   /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/cornerPoints_cg.m"/* pName */
};

static emlrtRTEInfo c2_si_emlrtRTEI = { 23,/* lineNo */
  25,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/FeaturePointsImpl.m"/* pName */
};

static emlrtRTEInfo c2_ti_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "repmat",                            /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/eml/lib/matlab/elmat/repmat.m"/* pName */
};

static emlrtRTEInfo c2_ui_emlrtRTEI = { 15,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c2_vi_emlrtRTEI = { 104,/* lineNo */
  13,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c2_wi_emlrtRTEI = { 104,/* lineNo */
  17,                                  /* colNo */
  "imfilter",                          /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo c2_xi_emlrtRTEI = { 32,/* lineNo */
  9,                                   /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_yi_emlrtRTEI = { 33,/* lineNo */
  40,                                  /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_aj_emlrtRTEI = { 231,/* lineNo */
  20,                                  /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_bj_emlrtRTEI = { 231,/* lineNo */
  9,                                   /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_cj_emlrtRTEI = { 232,/* lineNo */
  12,                                  /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_dj_emlrtRTEI = { 232,/* lineNo */
  20,                                  /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_ej_emlrtRTEI = { 235,/* lineNo */
  24,                                  /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_fj_emlrtRTEI = { 236,/* lineNo */
  20,                                  /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_gj_emlrtRTEI = { 236,/* lineNo */
  9,                                   /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_hj_emlrtRTEI = { 237,/* lineNo */
  12,                                  /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_ij_emlrtRTEI = { 237,/* lineNo */
  20,                                  /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_jj_emlrtRTEI = { 240,/* lineNo */
  24,                                  /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_kj_emlrtRTEI = { 241,/* lineNo */
  20,                                  /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_lj_emlrtRTEI = { 241,/* lineNo */
  9,                                   /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_mj_emlrtRTEI = { 242,/* lineNo */
  12,                                  /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_nj_emlrtRTEI = { 242,/* lineNo */
  20,                                  /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_oj_emlrtRTEI = { 245,/* lineNo */
  24,                                  /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_pj_emlrtRTEI = { 246,/* lineNo */
  20,                                  /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_qj_emlrtRTEI = { 246,/* lineNo */
  9,                                   /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_rj_emlrtRTEI = { 247,/* lineNo */
  12,                                  /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_sj_emlrtRTEI = { 247,/* lineNo */
  20,                                  /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_tj_emlrtRTEI = { 33,/* lineNo */
  10,                                  /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_uj_emlrtRTEI = { 230,/* lineNo */
  9,                                   /* colNo */
  "algbwmorph",                        /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pName */
};

static emlrtRTEInfo c2_vj_emlrtRTEI = { 152,/* lineNo */
  44,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_wj_emlrtRTEI = { 152,/* lineNo */
  28,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_xj_emlrtRTEI = { 153,/* lineNo */
  7,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_yj_emlrtRTEI = { 153,/* lineNo */
  1,                                   /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_ak_emlrtRTEI = { 151,/* lineNo */
  10,                                  /* colNo */
  "harrisMinEigen",                    /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/+detector/harrisMinEigen.m"/* pName */
};

static emlrtRTEInfo c2_bk_emlrtRTEI = { 226,/* lineNo */
  17,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/FeaturePointsImpl.m"/* pName */
};

static emlrtRTEInfo c2_ck_emlrtRTEI = { 25,/* lineNo */
  17,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/FeaturePointsImpl.m"/* pName */
};

static emlrtRTEInfo c2_dk_emlrtRTEI = { 278,/* lineNo */
  13,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/FeaturePointsImpl.m"/* pName */
};

static emlrtRTEInfo c2_ek_emlrtRTEI = { 27,/* lineNo */
  24,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/FeaturePointsImpl.m"/* pName */
};

static emlrtRTEInfo c2_fk_emlrtRTEI = { 283,/* lineNo */
  17,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/FeaturePointsImpl.m"/* pName */
};

static emlrtRTEInfo c2_gk_emlrtRTEI = { 343,/* lineNo */
  28,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/FeaturePointsImpl.m"/* pName */
};

static emlrtRTEInfo c2_hk_emlrtRTEI = { 27,/* lineNo */
  17,                                  /* colNo */
  "FeaturePointsImpl",                 /* fName */
  "/usr/local/MATLAB/R2017b/toolbox/vision/vision/+vision/+internal/FeaturePointsImpl.m"/* pName */
};

static const char_T c2_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i',
  'l', 't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F',
  'a', 'i', 'l', 'e', 'd' };

static const char_T c2_cv1[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm',
  'a', 'x', 's', 'i', 'z', 'e' };

static const char_T c2_cv2[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
  'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

static const char_T c2_cv3[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
  'b', '2', 'i', 'n', 'd', ':', 'I', 'n', 'd', 'e', 'x', 'O', 'u', 't', 'O', 'f',
  'R', 'a', 'n', 'g', 'e' };

static const char_T c2_cv4[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
  'b', '2', 'i', 'n', 'd', ':', 'S', 'u', 'b', 's', 'c', 'r', 'i', 'p', 't', 'V',
  'e', 'c', 't', 'o', 'r', 'S', 'i', 'z', 'e' };

/* Function Declarations */
static void initialize_c2_DetectAndTrackFace
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance);
static void initialize_params_c2_DetectAndTrackFace
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance);
static void enable_c2_DetectAndTrackFace(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance);
static void disable_c2_DetectAndTrackFace(SFc2_DetectAndTrackFaceInstanceStruct *
  chartInstance);
static void c2_update_debugger_state_c2_DetectAndTrackFace
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_DetectAndTrackFace
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance);
static void set_sim_state_c2_DetectAndTrackFace
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance, const mxArray *c2_st);
static void finalize_c2_DetectAndTrackFace(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance);
static void sf_gateway_c2_DetectAndTrackFace
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance);
static void mdl_start_c2_DetectAndTrackFace
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance);
static void c2_chartstep_c2_DetectAndTrackFace
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance);
static void initSimStructsc2_DetectAndTrackFace
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static void c2_eML_blk_kernel_free(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, real32_T
  c2_inData_data[], int32_T c2_inData_size[2]);
static void c2_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_featurePointLocations, const char_T
  *c2_identifier, real32_T c2_y_data[], int32_T c2_y_size[2]);
static void c2_b_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real32_T c2_y_data[], int32_T c2_y_size[2]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, real32_T c2_outData_data[],
  int32_T c2_outData_size[2]);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, real_T
  c2_inData_data[], int32_T c2_inData_size[2]);
static void c2_c_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_bBox, const char_T *c2_identifier, real_T
  c2_y_data[], int32_T c2_y_size[2]);
static void c2_d_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y_data[], int32_T c2_y_size[2]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, real_T c2_outData_data[], int32_T
  c2_outData_size[2]);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_e_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid,
  c2_emxArray_real_T *c2_inData);
static void c2_f_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_emxArray_real_T *c2_y);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, c2_emxArray_real_T *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid,
  c2_vision_internal_cornerPoints_cg *c2_inData);
static void c2_g_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_vision_internal_cornerPoints_cg *c2_y);
static void c2_h_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_emxArray_real32_T *c2_y);
static void c2_i_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_emxArray_real32_T *c2_y);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName,
  c2_vision_internal_cornerPoints_cg *c2_outData);
static void c2_parseInputs(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_real_T *c2_I, real_T c2_varargin_2_data[], int32_T
  c2_varargin_2_size[2], c2_swtWcLs9dbtZb7aBThYWFXD *c2_params);
static void c2_expandROI(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  real_T c2_imageSize[2], int32_T c2_originalROI_data[], int32_T
  c2_originalROI_size[2], real_T c2_expandSize, int32_T c2_expandedROI_data[],
  int32_T c2_expandedROI_size[2]);
static void c2_cropImage(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_real32_T *c2_I, int32_T c2_roi_data[], int32_T c2_roi_size[2],
  c2_emxArray_real32_T *c2_Iroi);
static void c2_cornerMetric(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_real32_T *c2_I, c2_emxArray_real32_T *c2_metric);
static void c2_imfilter(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_real32_T *c2_varargin_1, c2_emxArray_real32_T *c2_b);
static void c2_padImage(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_real32_T *c2_a_tmp, real_T c2_pad[2], c2_emxArray_real32_T *c2_a);
static void c2_validateattributes(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, real_T c2_a[2]);
static void c2_repmat(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
                      real_T c2_varargin_1[2], c2_emxArray_real32_T *c2_b);
static void c2_assertValidSizeArg(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, real_T c2_varargin_1[2]);
static void c2_b_imfilter(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_real32_T *c2_varargin_1, c2_emxArray_real32_T *c2_b);
static void c2_c_imfilter(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_real32_T *c2_varargin_1, c2_emxArray_real32_T *c2_b);
static void c2_power(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
                     c2_emxArray_real32_T *c2_a, c2_emxArray_real32_T *c2_y);
static boolean_T c2_dimagree(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_z, c2_emxArray_real32_T
  *c2_varargin_1);
static void c2_sqrt(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
                    c2_emxArray_real32_T *c2_x, c2_emxArray_real32_T *c2_b_x);
static void c2_error(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance);
static void c2_findPeaks(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_real32_T *c2_metric, real32_T c2_quality, c2_emxArray_real32_T
  *c2_loc);
static void c2_imregionalmax(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_varargin_1, c2_emxArray_boolean_T
  *c2_BW);
static void c2_b_validateattributes(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_a);
static void c2_b_error(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance);
static void c2_toLogicalCheck(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_x);
static void c2_bwmorph(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_boolean_T *c2_bwin, c2_emxArray_boolean_T *c2_bw);
static void c2_bwlookup(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_boolean_T *c2_bwin, c2_emxArray_boolean_T *c2_B);
static boolean_T c2_isequal(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_boolean_T *c2_varargin_1, c2_emxArray_boolean_T *c2_varargin_2);
static boolean_T c2_allinrange(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_int32_T *c2_x, real_T c2_lo, int32_T c2_hi);
static void c2_subPixelLocation(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_metric, c2_emxArray_real32_T *c2_loc,
  c2_emxArray_real32_T *c2_b_loc);
static void c2_c_error(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance);
static void c2_subPixelLocationImpl(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_metric, c2_emxArray_real32_T *c2_loc,
  c2_emxArray_real32_T *c2_subPixelLoc);
static boolean_T c2_b_allinrange(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_x, real_T c2_lo, int32_T c2_hi);
static boolean_T c2_b_isequal(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, real_T c2_varargin_1[2], real_T c2_varargin_2[2]);
static int32_T c2_prodsub(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  int32_T c2_x[2], int32_T c2_lo, int32_T c2_hi);
static void c2_abs(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
                   c2_emxArray_real32_T *c2_x, c2_emxArray_real32_T *c2_y);
static void c2_computeMetric(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_metric, c2_emxArray_real32_T *c2_loc,
  c2_emxArray_real32_T *c2_values);
static void c2_floor(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
                     c2_emxArray_real32_T *c2_x, c2_emxArray_real32_T *c2_b_x);
static void c2_indexShapeCheck(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, int32_T c2_matrixSize[2], int32_T c2_indexSize);
static void c2_excludePointsOutsideROI(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, int32_T c2_originalROI_data[], int32_T c2_originalROI_size[2],
  int32_T c2_expandedROI_data[], int32_T c2_expandedROI_size[2],
  c2_emxArray_real32_T *c2_locInExpandedROI, c2_emxArray_real32_T *c2_metric,
  c2_emxArray_real32_T *c2_validLocation, c2_emxArray_real32_T *c2_validMetric);
static void c2_b_indexShapeCheck(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, int32_T c2_matrixSize[2]);
static void c2_bsxfun(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
                      c2_emxArray_real32_T *c2_a, real32_T c2_b[2],
                      c2_emxArray_real32_T *c2_c);
static void c2_cornerPoints_cg_cornerPoints_cg
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance, c2_emxArray_real32_T
   *c2_varargin_1, c2_emxArray_real32_T *c2_varargin_3,
   c2_vision_internal_cornerPoints_cg *c2_this);
static void c2_FeaturePointsImpl_FeaturePointsImpl
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
   c2_vision_internal_cornerPoints_cg c2_this, c2_emxArray_real32_T
   *c2_varargin_1, c2_emxArray_real32_T *c2_varargin_3,
   c2_vision_internal_cornerPoints_cg *c2_b_this);
static void c2_FeaturePointsImpl_validate(SFc2_DetectAndTrackFaceInstanceStruct *
  chartInstance, c2_sjeQsvJNEhdsHQhIigwA2FF c2_inputs);
static void c2_b_repmat(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  real32_T c2_a_data[], int32_T c2_a_size[1], real_T c2_varargin_1,
  c2_emxArray_real32_T *c2_b);
static void c2_b_assertValidSizeArg(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, real_T c2_varargin_1);
static boolean_T c2_j_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_feval, const char_T *c2_identifier);
static boolean_T c2_k_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static const mxArray *c2_emlrt_marshallOut(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const char_T c2_b_u[30]);
static const mxArray *c2_b_emlrt_marshallOut
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance, const char_T c2_b_u[34]);
static const mxArray *c2_c_emlrt_marshallOut
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance, const char_T c2_b_u[36]);
static const mxArray *c2_d_emlrt_marshallOut
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance, const char_T c2_b_u[15]);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_l_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, real_T
  c2_inData_data[16], int32_T c2_inData_sizes[2]);
static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, real_T c2_outData_data[16],
  int32_T c2_outData_sizes[2]);
static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, real32_T
  c2_inData_data[1000], int32_T c2_inData_sizes[2]);
static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, real32_T c2_outData_data[1000],
  int32_T c2_outData_sizes[2]);
static uint8_T c2_m_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_DetectAndTrackFace, const
  char_T *c2_identifier);
static uint8_T c2_n_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_imfilter(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_real32_T *c2_varargin_1);
static void c2_e_imfilter(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_real32_T *c2_varargin_1);
static void c2_b_sqrt(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
                      c2_emxArray_real32_T *c2_x);
static void c2_b_bwmorph(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_boolean_T *c2_bwin);
static void c2_b_subPixelLocation(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_metric, c2_emxArray_real32_T *c2_loc);
static void c2_b_floor(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_real32_T *c2_x);
static void c2_b_FeaturePointsImpl_FeaturePointsImpl
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
   c2_vision_internal_cornerPoints_cg *c2_this, c2_emxArray_real32_T
   *c2_varargin_1, c2_emxArray_real32_T *c2_varargin_3);
static void c2_emxEnsureCapacity_real_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_uint8_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_uint8_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_int32_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_int32_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_int32_T1(SFc2_DetectAndTrackFaceInstanceStruct *
  chartInstance, c2_emxArray_int32_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_real32_T(SFc2_DetectAndTrackFaceInstanceStruct *
  chartInstance, c2_emxArray_real32_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation);
static void c2_emxCopyStruct_vision_internal_c
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
   c2_vision_internal_cornerPoints_cg *c2_dst, const
   c2_vision_internal_cornerPoints_cg *c2_src, const emlrtRTEInfo
   *c2_srcLocation);
static void c2_emxCopy_real32_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T **c2_dst, c2_emxArray_real32_T * const
  *c2_src, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxCopy_real32_T1(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T **c2_dst, c2_emxArray_real32_T * const
  *c2_src, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_real32_T1(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation);
static void c2_emxInitStruct_vision_internal_c
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
   c2_vision_internal_cornerPoints_cg *c2_pStruct, const emlrtRTEInfo
   *c2_srcLocation);
static void c2_emxInit_real32_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_real32_T1(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_real_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_uint8_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_uint8_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_int32_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_int32_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_int32_T1(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_int32_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation);
static void c2_emxFree_real32_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T **c2_pEmxArray);
static void c2_emxFreeStruct_vision_internal_c
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
   c2_vision_internal_cornerPoints_cg *c2_pStruct);
static void c2_emxFree_real_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real_T **c2_pEmxArray);
static void c2_emxFree_uint8_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_uint8_T **c2_pEmxArray);
static void c2_emxFree_int32_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_int32_T **c2_pEmxArray);
static void c2_emxEnsureCapacity_real_T1(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_boolean_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_boolean_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_real_T1(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation);
static void c2_emxFree_boolean_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_boolean_T **c2_pEmxArray);
static void c2_emxEnsureCapacity_boolean_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_boolean_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_real32_T2(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_boolean_T1
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance, c2_emxArray_boolean_T
   *c2_emxArray, int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_real32_T2(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_boolean_T1(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_boolean_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_boolean_T2
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance, c2_emxArray_boolean_T
   *c2_emxArray, int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_boolean_T2(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_boolean_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInitStruct_sjeQsvJNEhdsHQhIi
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
   c2_sjeQsvJNEhdsHQhIigwA2FF *c2_pStruct, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxFreeStruct_sjeQsvJNEhdsHQhIi
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
   c2_sjeQsvJNEhdsHQhIigwA2FF *c2_pStruct);
static int32_T c2_div_s32_floor(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, int32_T c2_numerator, int32_T c2_denominator, uint32_T
  c2_ssid_src_loc, int32_T c2_offset_src_loc, int32_T c2_length_src_loc);
static int32_T c2_div_s32(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  int32_T c2_numerator, int32_T c2_denominator, uint32_T c2_ssid_src_loc,
  int32_T c2_offset_src_loc, int32_T c2_length_src_loc);
static int32_T c2_div_nzp_s32(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, int32_T c2_numerator, int32_T c2_denominator, uint32_T
  c2_ssid_src_loc, int32_T c2_offset_src_loc, int32_T c2_length_src_loc);
static int32_T c2__s32_d_(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  real_T c2_b, uint32_T c2_ssid_src_loc, int32_T c2_offset_src_loc, int32_T
  c2_length_src_loc);
static void init_dsm_address_info(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_DetectAndTrackFace
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  emlrtLicenseCheckR2012b(chartInstance->c2_fEmlrtCtx,
    "Video_and_Image_Blockset", 2);
  emlrtLicenseCheckR2012b(chartInstance->c2_fEmlrtCtx, "Image_Toolbox", 2);
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_DetectAndTrackFace(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_faceDetector_not_empty = false;
  chartInstance->c2_is_active_c2_DetectAndTrackFace = 0U;
  sf_mex_assign(&c2_b_eml_mx, sf_mex_create("eml_mx", NULL, 0, 0U, 1U, 0U, 2, 0,
    0), true);
  sf_mex_assign(&c2_eml_mx, sf_mex_create("eml_mx", NULL, 10, 0U, 1U, 0U, 2, 0,
    0), true);
}

static void initialize_params_c2_DetectAndTrackFace
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_DetectAndTrackFace(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_DetectAndTrackFace(SFc2_DetectAndTrackFaceInstanceStruct *
  chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_DetectAndTrackFace
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_DetectAndTrackFace
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_hoistedGlobal;
  const mxArray *c2_d_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(3, 1), false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", (void *)chartInstance->c2_bBox_data,
    0, 0U, 1U, 0U, 2, (*chartInstance->c2_bBox_sizes)[0],
    (*chartInstance->c2_bBox_sizes)[1]), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", (void *)
    chartInstance->c2_featurePointLocations_data, 1, 0U, 1U, 0U, 2,
    (*chartInstance->c2_featurePointLocations_sizes)[0],
    (*chartInstance->c2_featurePointLocations_sizes)[1]), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_DetectAndTrackFace;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_DetectAndTrackFace
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_b_u;
  real_T c2_tmp_data[16];
  int32_T c2_tmp_size[2];
  int32_T c2_i0;
  int32_T c2_i1;
  int32_T c2_loop_ub;
  int32_T c2_i2;
  real32_T c2_b_tmp_data[1000];
  int32_T c2_b_tmp_size[2];
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_b_loop_ub;
  int32_T c2_i5;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_b_u = sf_mex_dup(c2_st);
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_b_u, 0)),
                        "bBox", c2_tmp_data, c2_tmp_size);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 0, c2_tmp_size[0]);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 1, c2_tmp_size[1]);
  c2_i0 = (*chartInstance->c2_bBox_sizes)[0];
  c2_i1 = (*chartInstance->c2_bBox_sizes)[1];
  c2_loop_ub = c2_tmp_size[0] * c2_tmp_size[1] - 1;
  for (c2_i2 = 0; c2_i2 <= c2_loop_ub; c2_i2++) {
    (*chartInstance->c2_bBox_data)[c2_i2] = c2_tmp_data[c2_i2];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_b_u, 1)),
                      "featurePointLocations", c2_b_tmp_data, c2_b_tmp_size);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 2, 0,
    c2_b_tmp_size[0]);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 2, 1,
    c2_b_tmp_size[1]);
  c2_i3 = (*chartInstance->c2_featurePointLocations_sizes)[0];
  c2_i4 = (*chartInstance->c2_featurePointLocations_sizes)[1];
  c2_b_loop_ub = c2_b_tmp_size[0] * c2_b_tmp_size[1] - 1;
  for (c2_i5 = 0; c2_i5 <= c2_b_loop_ub; c2_i5++) {
    (*chartInstance->c2_featurePointLocations_data)[c2_i5] = c2_b_tmp_data[c2_i5];
  }

  chartInstance->c2_is_active_c2_DetectAndTrackFace = c2_m_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_b_u, 2)),
     "is_active_c2_DetectAndTrackFace");
  sf_mex_destroy(&c2_b_u);
  c2_update_debugger_state_c2_DetectAndTrackFace(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_DetectAndTrackFace(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance)
{
  c2_eML_blk_kernel_free(chartInstance);
  sf_mex_destroy(&c2_eml_mx);
  sf_mex_destroy(&c2_b_eml_mx);
}

static void sf_gateway_c2_DetectAndTrackFace
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  int32_T c2_i6;
  int32_T c2_loop_ub;
  int32_T c2_i7;
  int32_T c2_b_loop_ub;
  int32_T c2_i8;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_numberOfFeaturePoints, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_decimationFactor, 1U);
  for (c2_i6 = 0; c2_i6 < 1048576; c2_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_b_videoFrameGray)[c2_i6], 0U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_DetectAndTrackFace(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DetectAndTrackFaceMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  c2_loop_ub = (*chartInstance->c2_bBox_sizes)[0] *
    (*chartInstance->c2_bBox_sizes)[1] - 1;
  for (c2_i7 = 0; c2_i7 <= c2_loop_ub; c2_i7++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_bBox_data)[c2_i7], 3U);
  }

  c2_b_loop_ub = (*chartInstance->c2_featurePointLocations_sizes)[0] *
    (*chartInstance->c2_featurePointLocations_sizes)[1] - 1;
  for (c2_i8 = 0; c2_i8 <= c2_b_loop_ub; c2_i8++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_featurePointLocations_data)
                          [c2_i8], 4U);
  }
}

static void mdl_start_c2_DetectAndTrackFace
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void c2_chartstep_c2_DetectAndTrackFace
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  c2_vision_internal_cornerPoints_cg c2_points;
  c2_emxArray_real_T *c2_c_videoFrameGray;
  c2_vision_internal_cornerPoints_cg c2_r0;
  int32_T c2_i9;
  real_T c2_b_decimationFactor;
  real_T c2_b_numberOfFeaturePoints;
  uint32_T c2_inSize[8];
  real_T c2_nargin = 3.0;
  real_T c2_nargout = 2.0;
  real_T c2_b_bBox_data[16];
  int32_T c2_bBox_size[2];
  real32_T c2_b_featurePointLocations_data[1000];
  int32_T c2_featurePointLocations_size[2];
  boolean_T c2_b0;
  boolean_T c2_b1;
  int32_T c2_i10;
  int32_T c2_i11;
  boolean_T c2_b2;
  boolean_T c2_b3;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_loop_ub;
  int32_T c2_i15;
  int32_T c2_b_loop_ub;
  int32_T c2_i16;
  int32_T c2_bBox;
  c2_emxArray_real_T *c2_varargin_1;
  c2_vision_CascadeObjectDetector *c2_obj;
  int32_T c2_b_bBox;
  c2_vision_CascadeObjectDetector *c2_b_obj;
  int32_T c2_i17;
  int32_T c2_featurePointLocations;
  int32_T c2_b_featurePointLocations;
  int32_T c2_i18;
  int32_T c2_b_varargin_1;
  int32_T c2_c_varargin_1;
  int32_T c2_c_loop_ub;
  void * c2_ptrObj;
  int32_T c2_i19;
  int32_T c2_i20;
  const mxArray *c2_y = NULL;
  int32_T c2_i21;
  static char_T c2_cv5[10] = { 'i', 's', 'd', 'e', 'p', 'l', 'o', 'y', 'e', 'd'
  };

  int32_T c2_d_loop_ub;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i22;
  static char_T c2_cv6[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  void * c2_b_ptrObj;
  const mxArray *c2_c_y = NULL;
  int32_T c2_i23;
  static char_T c2_cv7[4] = { 's', 't', 'e', 'p' };

  const mxArray *c2_d_y = NULL;
  static char_T c2_cv8[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  int32_T c2_i24;
  int32_T c2_i25;
  const mxArray *c2_e_y = NULL;
  int32_T c2_i26;
  char_T c2_ClassificationModel[117];
  static char_T c2_b_ClassificationModel[117] = { '/', 'u', 's', 'r', '/', 'l',
    'o', 'c', 'a', 'l', '/', 'M', 'A', 'T', 'L', 'A', 'B', '/', 'R', '2', '0',
    '1', '7', 'b', '/', 't', 'o', 'o', 'l', 'b', 'o', 'x', '/', 'v', 'i', 's',
    'i', 'o', 'n', '/', 'v', 'i', 's', 'i', 'o', 'n', 'u', 't', 'i', 'l', 'i',
    't', 'i', 'e', 's', '/', 'c', 'l', 'a', 's', 's', 'i', 'f', 'i', 'e', 'r',
    'd', 'a', 't', 'a', '/', 'c', 'a', 's', 'c', 'a', 'd', 'e', '/', 'h', 'a',
    'a', 'r', '/', 'h', 'a', 'a', 'r', 'c', 'a', 's', 'c', 'a', 'd', 'e', '_',
    'f', 'r', 'o', 'n', 't', 'a', 'l', 'f', 'a', 'c', 'e', '_', 'a', 'l', 't',
    '2', '.', 'x', 'm', 'l', '\x00' };

  int32_T c2_i27;
  static char_T c2_cv9[5] = { 's', 'e', 't', 'u', 'p' };

  int32_T c2_i28;
  int32_T c2_e_loop_ub;
  int32_T c2_i29;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_k;
  real_T c2_d0;
  c2_cell_wrap_2 c2_varSizes[1];
  real_T c2_d1;
  uint32_T c2_u0;
  uint32_T c2_u1;
  c2_emxArray_uint8_T *c2_Iu8;
  int32_T c2_i34;
  int32_T c2_i35;
  void * c2_c_ptrObj;
  real_T c2_ScaleFactor;
  real_T c2_d2;
  uint32_T c2_u2;
  uint32_T c2_MergeThreshold;
  c2_emxArray_real_T *c2_c_bBox;
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_MinSize_[2];
  int32_T c2_d_bBox;
  int32_T c2_e_bBox;
  c2_emxArray_uint8_T *c2_r1;
  int32_T c2_MaxSize_[2];
  void * c2_ptrDetectedObj;
  int32_T c2_i39;
  c2_emxArray_int32_T *c2_r2;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_f_loop_ub;
  int32_T c2_i42;
  int32_T c2_g_loop_ub;
  int32_T c2_i43;
  c2_emxArray_int32_T *c2_bboxes_;
  int32_T c2_h_loop_ub;
  int32_T c2_num_bboxes;
  int32_T c2_i44;
  c2_emxArray_real_T *c2_f_bBox;
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_iv0[2];
  int32_T c2_iv1[2];
  int32_T c2_i47;
  int32_T c2_g_bBox;
  int32_T c2_i48;
  int32_T c2_h_bBox;
  int32_T c2_i_bBox;
  int32_T c2_i49;
  int32_T c2_i_loop_ub;
  int32_T c2_i50;
  int32_T c2_i51;
  int32_T c2_j_loop_ub;
  int32_T c2_i52;
  int32_T c2_k_loop_ub;
  int32_T c2_i53;
  int32_T c2_j_bBox;
  int32_T c2_k_bBox;
  int32_T c2_l_loop_ub;
  int32_T c2_i54;
  boolean_T c2_b4;
  int32_T c2_i55;
  int32_T c2_c_featurePointLocations;
  int32_T c2_d_featurePointLocations;
  int32_T c2_d_varargin_1;
  int32_T c2_e_varargin_1;
  int32_T c2_m_loop_ub;
  int32_T c2_i56;
  int32_T c2_varargin_2_size[2];
  int32_T c2_i57;
  c2_emxArray_real_T *c2_f_varargin_1;
  real_T c2_varargin_2_data[4];
  int32_T c2_i58;
  int32_T c2_g_varargin_1;
  int32_T c2_h_varargin_1;
  int32_T c2_n_loop_ub;
  int32_T c2_i59;
  c2_emxArray_real32_T *c2_I;
  c2_swtWcLs9dbtZb7aBThYWFXD c2_params;
  int32_T c2_i60;
  int32_T c2_b_I;
  int32_T c2_c_I;
  int32_T c2_o_loop_ub;
  int32_T c2_i61;
  int32_T c2_i62;
  int32_T c2_params_size[2];
  real_T c2_d_I[2];
  int32_T c2_b_params;
  int32_T c2_c_params;
  int32_T c2_i63;
  int32_T c2_params_data[4];
  int32_T c2_expandedROI_data[4];
  int32_T c2_expandedROI_size[2];
  int32_T c2_b_expandedROI_size[2];
  int32_T c2_expandedROI;
  int32_T c2_b_expandedROI;
  int32_T c2_i64;
  c2_emxArray_real32_T *c2_Ic;
  int32_T c2_b_expandedROI_data[4];
  c2_emxArray_real32_T *c2_metricMatrix;
  c2_emxArray_real32_T *c2_b_metricMatrix;
  int32_T c2_i65;
  int32_T c2_c_metricMatrix;
  int32_T c2_d_metricMatrix;
  int32_T c2_p_loop_ub;
  int32_T c2_i66;
  c2_emxArray_real32_T *c2_locations;
  c2_emxArray_real32_T *c2_e_metricMatrix;
  int32_T c2_i67;
  int32_T c2_f_metricMatrix;
  int32_T c2_g_metricMatrix;
  int32_T c2_q_loop_ub;
  int32_T c2_i68;
  c2_emxArray_real32_T *c2_b_locations;
  int32_T c2_i69;
  int32_T c2_c_locations;
  int32_T c2_d_locations;
  int32_T c2_r_loop_ub;
  int32_T c2_i70;
  c2_emxArray_real32_T *c2_metricValues;
  c2_emxArray_real32_T *c2_e_locations;
  c2_emxArray_real32_T *c2_b_metricValues;
  c2_vision_internal_cornerPoints_cg c2_this;
  int32_T c2_e_featurePointLocations;
  int32_T c2_f_featurePointLocations;
  int32_T c2_s_loop_ub;
  int32_T c2_i71;
  boolean_T exitg1;
  c2_emxInitStruct_vision_internal_c(chartInstance, &c2_points, &c2_v_emlrtRTEI);
  c2_emxInit_real_T(chartInstance, &c2_c_videoFrameGray, 2, &c2_y_emlrtRTEI);
  c2_emxInitStruct_vision_internal_c(chartInstance, &c2_r0, &c2_gb_emlrtRTEI);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i9 = 0; c2_i9 < 1048576; c2_i9++) {
    chartInstance->c2_videoFrameGray[c2_i9] =
      (*chartInstance->c2_b_videoFrameGray)[c2_i9];
  }

  c2_b_decimationFactor = *chartInstance->c2_decimationFactor;
  c2_b_numberOfFeaturePoints = *chartInstance->c2_numberOfFeaturePoints;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 9U, c2_debug_family_names, c2_inSize);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(&c2_points, NULL,
    c2_points.pLocation->size, 0, 0, (void *)c2_f_sf_marshallOut, (void *)
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE(c2_c_videoFrameGray->data, (const
    int32_T *)c2_c_videoFrameGray->size, NULL, 0, -1, (void *)
    c2_e_sf_marshallOut, (void *)c2_d_sf_marshallIn, (void *)c2_c_videoFrameGray,
    true);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 2U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 3U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c2_videoFrameGray, 1U,
    c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_decimationFactor, 4U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_numberOfFeaturePoints, 5U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)&c2_b_bBox_data, (const
    int32_T *)&c2_bBox_size, NULL, 0, 6, (void *)c2_b_sf_marshallOut, (void *)
    c2_b_sf_marshallIn, (void *)&c2_b_bBox_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)
    &c2_b_featurePointLocations_data, (const int32_T *)
    &c2_featurePointLocations_size, NULL, 0, 7, (void *)c2_sf_marshallOut, (void
    *)c2_sf_marshallIn, (void *)&c2_b_featurePointLocations_data, false);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_b0 = (c2_b_decimationFactor == 0.0);
  c2_b1 = (0.0 > c2_b_decimationFactor);
  if (c2_b0 || c2_b1) {
    c2_i10 = 1;
    c2_i11 = 0;
  } else {
    c2_i10 = c2__s32_d_(chartInstance, sf_integer_check(chartInstance->S, 1U,
      305U, 16U, c2_b_decimationFactor), 1U, 303U, 22U);
    c2_i11 = 1024;
  }

  c2_b2 = (c2_b_decimationFactor == 0.0);
  c2_b3 = (0.0 > c2_b_decimationFactor);
  if (c2_b2 || c2_b3) {
    c2_i12 = 1;
    c2_i13 = 0;
  } else {
    c2_i12 = c2__s32_d_(chartInstance, sf_integer_check(chartInstance->S, 1U,
      328U, 16U, c2_b_decimationFactor), 1U, 326U, 22U);
    c2_i13 = 1024;
  }

  c2_i14 = c2_c_videoFrameGray->size[0] * c2_c_videoFrameGray->size[1];
  c2_c_videoFrameGray->size[0] = c2_div_s32_floor(chartInstance, c2_i11 - 1,
    c2_i10, 1U, 271U, 78U) + 1;
  c2_c_videoFrameGray->size[1] = c2_div_s32_floor(chartInstance, c2_i13 - 1,
    c2_i12, 1U, 271U, 78U) + 1;
  c2_emxEnsureCapacity_real_T(chartInstance, c2_c_videoFrameGray, c2_i14,
    &c2_emlrtRTEI);
  c2_loop_ub = c2_div_s32_floor(chartInstance, c2_i13 - 1, c2_i12, 1U, 271U, 78U);
  for (c2_i15 = 0; c2_i15 <= c2_loop_ub; c2_i15++) {
    c2_b_loop_ub = c2_div_s32_floor(chartInstance, c2_i11 - 1, c2_i10, 1U, 271U,
      78U);
    for (c2_i16 = 0; c2_i16 <= c2_b_loop_ub; c2_i16++) {
      c2_c_videoFrameGray->data[c2_i16 + c2_c_videoFrameGray->size[0] * c2_i15] =
        chartInstance->c2_videoFrameGray[c2_i10 * c2_i16 + ((c2_i12 * c2_i15) <<
        10)];
    }
  }

  _SFD_SYMBOL_SWITCH(1U, 1U);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0,
        c2_b_numberOfFeaturePoints, 10.0, -1, 2U, c2_b_numberOfFeaturePoints <
        10.0))) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
    if (CV_EML_IF(0, 1, 1, !chartInstance->c2_faceDetector_not_empty)) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
      c2_obj = &chartInstance->c2_faceDetector;
      chartInstance->c2_faceDetector.ScaleFactor = 1.1;
      chartInstance->c2_faceDetector.MergeThreshold = 4.0;
      chartInstance->c2_faceDetector.matlabCodegenIsDeleted = false;
      chartInstance->c2_faceDetector.isInitialized = 0;
      chartInstance->c2_faceDetector.matlabCodegenIsDeleted = false;
      for (c2_i18 = 0; c2_i18 < 4; c2_i18++) {
        chartInstance->c2_faceDetector.tunablePropertyChanged[c2_i18] = false;
      }

      c2_ptrObj = NULL;
      cascadeClassifier_construct(&c2_ptrObj);
      c2_obj->pCascadeClassifier = c2_ptrObj;
      c2_y = NULL;
      sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv5, 10, 0U, 1U, 0U, 2, 1, 10),
                    false);
      c2_j_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                            (sfGlobalDebugInstanceStruct, "feval", 1U, 1U, 14,
        c2_y), "feval");
      c2_b_ptrObj = c2_obj->pCascadeClassifier;
      for (c2_i23 = 0; c2_i23 < 117; c2_i23++) {
        c2_ClassificationModel[c2_i23] = c2_b_ClassificationModel[c2_i23];
      }

      cascadeClassifier_load(c2_b_ptrObj, c2_ClassificationModel);
      chartInstance->c2_faceDetector_not_empty = true;
    }

    c2_emxInit_real_T(chartInstance, &c2_varargin_1, 2, &c2_d_emlrtRTEI);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
    c2_b_obj = &chartInstance->c2_faceDetector;
    c2_i17 = c2_varargin_1->size[0] * c2_varargin_1->size[1];
    c2_varargin_1->size[0] = c2_c_videoFrameGray->size[0];
    c2_varargin_1->size[1] = c2_c_videoFrameGray->size[1];
    c2_emxEnsureCapacity_real_T(chartInstance, c2_varargin_1, c2_i17,
      &c2_d_emlrtRTEI);
    c2_b_varargin_1 = c2_varargin_1->size[0];
    c2_c_varargin_1 = c2_varargin_1->size[1];
    c2_c_loop_ub = c2_c_videoFrameGray->size[0] * c2_c_videoFrameGray->size[1] -
      1;
    for (c2_i19 = 0; c2_i19 <= c2_c_loop_ub; c2_i19++) {
      c2_varargin_1->data[c2_i19] = c2_c_videoFrameGray->data[c2_i19];
    }

    if (chartInstance->c2_faceDetector.isInitialized != 2) {
    } else {
      c2_b_y = NULL;
      sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv6, 10, 0U, 1U, 0U, 2, 1, 45),
                    false);
      c2_c_y = NULL;
      sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv7, 10, 0U, 1U, 0U, 2, 1, 4),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 2U, 14, c2_b_y, 14, c2_c_y));
    }

    if (c2_b_obj->isInitialized != 1) {
      if (c2_b_obj->isInitialized == 0) {
      } else {
        c2_d_y = NULL;
        sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv8, 10, 0U, 1U, 0U, 2, 1,
          51), false);
        c2_e_y = NULL;
        sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv9, 10, 0U, 1U, 0U, 2, 1,
          5), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "message", 1U, 2U, 14, c2_d_y, 14, c2_e_y));
      }

      c2_b_obj->isInitialized = 1;
      for (c2_i26 = 0; c2_i26 < 2; c2_i26++) {
        c2_i32 = c2_varargin_1->size[c2_i26];
        if (CV_SATURATION_EVAL(4, 0, 0, 0, c2_i32 < 0)) {
          c2_i32 = 0;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 680U, 33U);
        }

        c2_varSizes[0].f1[c2_i26] = (uint32_T)c2_i32;
      }

      for (c2_i31 = 0; c2_i31 < 6; c2_i31++) {
        c2_d1 = muDoubleScalarRound(1.0);
        if (c2_d1 < 4.294967296E+9) {
          if (CV_SATURATION_EVAL(4, 0, 0, 1, c2_d1 >= 0.0)) {
            c2_u1 = (uint32_T)c2_d1;
          } else {
            c2_u1 = 0U;
            _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 680U, 33U);
          }
        } else if (CV_SATURATION_EVAL(4, 0, 0, 0, c2_d1 >= 4.294967296E+9)) {
          c2_u1 = MAX_uint32_T;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 680U, 33U);
        } else {
          c2_u1 = 0U;
        }

        c2_varSizes[0].f1[c2_i31 + 2] = c2_u1;
      }

      c2_b_obj->inputVarSize[0] = c2_varSizes[0];
      c2_b_obj->TunablePropsChanged = false;
    }

    if (c2_b_obj->TunablePropsChanged) {
      c2_b_obj->TunablePropsChanged = false;
      for (c2_i25 = 0; c2_i25 < 4; c2_i25++) {
        c2_b_obj->tunablePropertyChanged[c2_i25] = false;
      }
    }

    for (c2_i24 = 0; c2_i24 < 2; c2_i24++) {
      c2_i30 = c2_varargin_1->size[c2_i24];
      if (CV_SATURATION_EVAL(4, 0, 0, 0, c2_i30 < 0)) {
        c2_i30 = 0;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 680U, 33U);
      }

      c2_inSize[c2_i24] = (uint32_T)c2_i30;
    }

    for (c2_i29 = 0; c2_i29 < 6; c2_i29++) {
      c2_d0 = muDoubleScalarRound(1.0);
      if (c2_d0 < 4.294967296E+9) {
        if (CV_SATURATION_EVAL(4, 0, 0, 1, c2_d0 >= 0.0)) {
          c2_u0 = (uint32_T)c2_d0;
        } else {
          c2_u0 = 0U;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 680U, 33U);
        }
      } else if (CV_SATURATION_EVAL(4, 0, 0, 0, c2_d0 >= 4.294967296E+9)) {
        c2_u0 = MAX_uint32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 680U, 33U);
      } else {
        c2_u0 = 0U;
      }

      c2_inSize[c2_i29 + 2] = c2_u0;
    }

    c2_k = 0;
    exitg1 = false;
    while ((!exitg1) && (c2_k < 8)) {
      if (c2_b_obj->inputVarSize[0].f1[c2__s32_d_(chartInstance, 1.0 + (real_T)
           c2_k, 1U, 680U, 33U) - 1] != c2_inSize[c2__s32_d_(chartInstance, 1.0
           + (real_T)c2_k, 1U, 680U, 33U) - 1]) {
        for (c2_i34 = 0; c2_i34 < 8; c2_i34++) {
          c2_b_obj->inputVarSize[0].f1[c2_i34] = c2_inSize[c2_i34];
        }

        exitg1 = true;
      } else {
        c2_k++;
      }
    }

    c2_emxInit_uint8_T(chartInstance, &c2_Iu8, 2, &c2_e_emlrtRTEI);
    c2_i35 = c2_Iu8->size[0] * c2_Iu8->size[1];
    c2_Iu8->size[0] = c2_varargin_1->size[0];
    c2_Iu8->size[1] = c2_varargin_1->size[1];
    c2_emxEnsureCapacity_uint8_T(chartInstance, c2_Iu8, c2_i35, &c2_e_emlrtRTEI);
    grayto8_real64(&c2_varargin_1->data[0], &c2_Iu8->data[0], (real_T)
                   (c2_varargin_1->size[0] * c2_varargin_1->size[1]));
    c2_c_ptrObj = c2_b_obj->pCascadeClassifier;
    c2_ScaleFactor = c2_b_obj->ScaleFactor;
    c2_d2 = muDoubleScalarRound(c2_b_obj->MergeThreshold);
    if (c2_d2 < 4.294967296E+9) {
      if (CV_SATURATION_EVAL(4, 0, 0, 1, c2_d2 >= 0.0)) {
        c2_u2 = (uint32_T)c2_d2;
      } else {
        c2_u2 = 0U;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 680U, 33U);
      }
    } else if (CV_SATURATION_EVAL(4, 0, 0, 0, c2_d2 >= 4.294967296E+9)) {
      c2_u2 = MAX_uint32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 680U, 33U);
    } else {
      c2_u2 = 0U;
    }

    c2_MergeThreshold = c2_u2;
    c2_emxInit_real_T(chartInstance, &c2_c_bBox, 2, (emlrtRTEInfo *)NULL);
    if ((c2_Iu8->size[0] == 0) || (c2_Iu8->size[1] == 0)) {
      c2_i37 = c2_c_bBox->size[0] * c2_c_bBox->size[1];
      c2_c_bBox->size[0] = 0;
      c2_c_bBox->size[1] = 4;
      c2_emxEnsureCapacity_real_T(chartInstance, c2_c_bBox, c2_i37,
        &c2_f_emlrtRTEI);
      c2_d_bBox = c2_c_bBox->size[0];
      c2_e_bBox = c2_c_bBox->size[1];
    } else {
      for (c2_i36 = 0; c2_i36 < 2; c2_i36++) {
        c2_MinSize_[c2_i36] = 0;
      }

      for (c2_i38 = 0; c2_i38 < 2; c2_i38++) {
        c2_MaxSize_[c2_i38] = 0;
      }

      c2_emxInit_uint8_T(chartInstance, &c2_r1, 2, (emlrtRTEInfo *)NULL);
      c2_ptrDetectedObj = NULL;
      c2_i39 = c2_r1->size[0] * c2_r1->size[1];
      c2_r1->size[0] = c2_Iu8->size[1];
      c2_r1->size[1] = c2_Iu8->size[0];
      c2_emxEnsureCapacity_uint8_T(chartInstance, c2_r1, c2_i39, &c2_g_emlrtRTEI);
      c2_f_loop_ub = c2_Iu8->size[0] - 1;
      for (c2_i42 = 0; c2_i42 <= c2_f_loop_ub; c2_i42++) {
        c2_h_loop_ub = c2_Iu8->size[1] - 1;
        for (c2_i44 = 0; c2_i44 <= c2_h_loop_ub; c2_i44++) {
          c2_r1->data[c2_i44 + c2_r1->size[0] * c2_i42] = c2_Iu8->data[c2_i42 +
            c2_Iu8->size[0] * c2_i44];
        }
      }

      c2_emxInit_int32_T1(chartInstance, &c2_bboxes_, 2, &c2_ab_emlrtRTEI);
      c2_num_bboxes = cascadeClassifier_detectMultiScale(c2_c_ptrObj,
        &c2_ptrDetectedObj, &c2_r1->data[0], c2_Iu8->size[0], c2_Iu8->size[1],
        c2_ScaleFactor, c2_MergeThreshold, c2_MinSize_, c2_MaxSize_);
      _SFD_NON_NEGATIVE_CHECK("", (real_T)c2_num_bboxes);
      c2_i46 = c2_bboxes_->size[0] * c2_bboxes_->size[1];
      c2_bboxes_->size[0] = c2_num_bboxes;
      c2_bboxes_->size[1] = 4;
      c2_emxEnsureCapacity_int32_T1(chartInstance, c2_bboxes_, c2_i46,
        &c2_i_emlrtRTEI);
      cascadeClassifier_assignOutputDeleteBbox(c2_ptrDetectedObj,
        &c2_bboxes_->data[0]);
      c2_i47 = c2_c_bBox->size[0] * c2_c_bBox->size[1];
      c2_c_bBox->size[0] = c2_bboxes_->size[0];
      c2_c_bBox->size[1] = c2_bboxes_->size[1];
      c2_emxEnsureCapacity_real_T(chartInstance, c2_c_bBox, c2_i47,
        &c2_f_emlrtRTEI);
      c2_h_bBox = c2_c_bBox->size[0];
      c2_i_bBox = c2_c_bBox->size[1];
      c2_i_loop_ub = c2_bboxes_->size[0] * c2_bboxes_->size[1] - 1;
      c2_emxFree_uint8_T(chartInstance, &c2_r1);
      for (c2_i50 = 0; c2_i50 <= c2_i_loop_ub; c2_i50++) {
        c2_c_bBox->data[c2_i50] = (real_T)c2_bboxes_->data[c2_i50];
      }

      c2_emxFree_int32_T(chartInstance, &c2_bboxes_);
    }

    c2_emxFree_uint8_T(chartInstance, &c2_Iu8);
    c2_emxInit_int32_T(chartInstance, &c2_r2, 1, (emlrtRTEInfo *)NULL);
    c2_i40 = c2_c_bBox->size[0];
    c2_i41 = c2_r2->size[0];
    c2_r2->size[0] = c2_i40;
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_r2, c2_i41, &c2_h_emlrtRTEI);
    c2_g_loop_ub = c2_i40 - 1;
    for (c2_i43 = 0; c2_i43 <= c2_g_loop_ub; c2_i43++) {
      c2_r2->data[c2_i43] = c2_i43;
    }

    c2_emxInit_real_T(chartInstance, &c2_f_bBox, 2, &c2_j_emlrtRTEI);
    c2_i45 = c2_c_bBox->size[0];
    c2_iv0[0] = c2_r2->size[0];
    c2_iv0[1] = 2;
    c2_iv1[0] = c2_i45;
    c2_iv1[1] = 2;
    _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c2_iv0, 2, c2_iv1, 2);
    c2_g_bBox = c2_c_bBox->size[0];
    c2_i48 = c2_f_bBox->size[0] * c2_f_bBox->size[1];
    c2_f_bBox->size[0] = c2_g_bBox;
    c2_f_bBox->size[1] = 2;
    c2_emxEnsureCapacity_real_T(chartInstance, c2_f_bBox, c2_i48,
      &c2_j_emlrtRTEI);
    for (c2_i49 = 0; c2_i49 < 2; c2_i49++) {
      c2_j_loop_ub = c2_g_bBox - 1;
      for (c2_i52 = 0; c2_i52 <= c2_j_loop_ub; c2_i52++) {
        c2_f_bBox->data[c2_i52 + c2_f_bBox->size[0] * c2_i49] = c2_c_bBox->
          data[c2_i52 + c2_c_bBox->size[0] * c2_i49];
      }
    }

    for (c2_i51 = 0; c2_i51 < 2; c2_i51++) {
      c2_k_loop_ub = c2_f_bBox->size[0] - 1;
      for (c2_i53 = 0; c2_i53 <= c2_k_loop_ub; c2_i53++) {
        c2_c_bBox->data[c2_r2->data[c2_i53] + c2_c_bBox->size[0] * c2_i51] =
          c2_f_bBox->data[c2_i53 + c2_f_bBox->size[0] * c2_i51];
      }
    }

    c2_emxFree_real_T(chartInstance, &c2_f_bBox);
    c2_emxFree_int32_T(chartInstance, &c2_r2);
    _SFD_DIM_SIZE_GEQ_CHECK(2, c2_c_bBox->size[0], 1);
    _SFD_DIM_SIZE_GEQ_CHECK(8, 4, 2);
    c2_bBox_size[0] = c2_c_bBox->size[0];
    c2_bBox_size[1] = 4;
    c2_j_bBox = c2_bBox_size[0];
    c2_k_bBox = c2_bBox_size[1];
    c2_l_loop_ub = c2_c_bBox->size[0] * c2_c_bBox->size[1] - 1;
    for (c2_i54 = 0; c2_i54 <= c2_l_loop_ub; c2_i54++) {
      c2_b_bBox_data[c2_i54] = c2_c_bBox->data[c2_i54];
    }

    c2_emxFree_real_T(chartInstance, &c2_c_bBox);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
    c2_b4 = (c2_bBox_size[0] == 0);
    if (CV_EML_IF(0, 1, 2, CV_EML_MCDC(0, 1, 0, !CV_EML_COND(0, 1, 0, c2_b4))))
    {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
      (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 938, 1, MAX_uint32_T, 1, 1, c2_bBox_size[0]);
      c2_i55 = c2_varargin_1->size[0] * c2_varargin_1->size[1];
      c2_varargin_1->size[0] = c2_c_videoFrameGray->size[0];
      c2_varargin_1->size[1] = c2_c_videoFrameGray->size[1];
      c2_emxEnsureCapacity_real_T(chartInstance, c2_varargin_1, c2_i55,
        &c2_m_emlrtRTEI);
      c2_d_varargin_1 = c2_varargin_1->size[0];
      c2_e_varargin_1 = c2_varargin_1->size[1];
      c2_m_loop_ub = c2_c_videoFrameGray->size[0] * c2_c_videoFrameGray->size[1]
        - 1;
      for (c2_i56 = 0; c2_i56 <= c2_m_loop_ub; c2_i56++) {
        c2_varargin_1->data[c2_i56] = c2_c_videoFrameGray->data[c2_i56];
      }

      c2_varargin_2_size[0] = 1;
      c2_varargin_2_size[1] = 4;
      for (c2_i57 = 0; c2_i57 < 4; c2_i57++) {
        c2_varargin_2_data[c2_varargin_2_size[0] * c2_i57] =
          c2_b_bBox_data[c2_bBox_size[0] * c2_i57];
      }

      c2_emxInit_real_T(chartInstance, &c2_f_varargin_1, 2, &c2_o_emlrtRTEI);
      c2_i58 = c2_f_varargin_1->size[0] * c2_f_varargin_1->size[1];
      c2_f_varargin_1->size[0] = c2_varargin_1->size[0];
      c2_f_varargin_1->size[1] = c2_varargin_1->size[1];
      c2_emxEnsureCapacity_real_T(chartInstance, c2_f_varargin_1, c2_i58,
        &c2_o_emlrtRTEI);
      c2_g_varargin_1 = c2_f_varargin_1->size[0];
      c2_h_varargin_1 = c2_f_varargin_1->size[1];
      c2_n_loop_ub = c2_varargin_1->size[0] * c2_varargin_1->size[1] - 1;
      for (c2_i59 = 0; c2_i59 <= c2_n_loop_ub; c2_i59++) {
        c2_f_varargin_1->data[c2_i59] = c2_varargin_1->data[c2_i59];
      }

      c2_emxInit_real32_T(chartInstance, &c2_I, 2, &c2_fb_emlrtRTEI);
      c2_parseInputs(chartInstance, c2_f_varargin_1, c2_varargin_2_data,
                     c2_varargin_2_size, &c2_params);
      c2_i60 = c2_I->size[0] * c2_I->size[1];
      c2_I->size[0] = c2_varargin_1->size[0];
      c2_I->size[1] = c2_varargin_1->size[1];
      c2_emxEnsureCapacity_real32_T(chartInstance, c2_I, c2_i60, &c2_p_emlrtRTEI);
      c2_b_I = c2_I->size[0];
      c2_c_I = c2_I->size[1];
      c2_o_loop_ub = c2_varargin_1->size[0] * c2_varargin_1->size[1] - 1;
      c2_emxFree_real_T(chartInstance, &c2_f_varargin_1);
      for (c2_i61 = 0; c2_i61 <= c2_o_loop_ub; c2_i61++) {
        c2_I->data[c2_i61] = (real32_T)c2_varargin_1->data[c2_i61];
      }

      for (c2_i62 = 0; c2_i62 < 2; c2_i62++) {
        c2_d_I[c2_i62] = (real_T)c2_I->size[c2_i62];
      }

      c2_params_size[0] = 1;
      c2_params_size[1] = 4;
      c2_b_params = c2_params_size[0];
      c2_c_params = c2_params_size[1];
      for (c2_i63 = 0; c2_i63 < 4; c2_i63++) {
        c2_params_data[c2_i63] = c2_params.ROI.data[c2_i63];
      }

      c2_expandROI(chartInstance, c2_d_I, c2_params_data, c2_params_size, 2.0,
                   c2_expandedROI_data, c2_expandedROI_size);
      c2_b_expandedROI_size[0] = 1;
      c2_b_expandedROI_size[1] = 4;
      c2_expandedROI = c2_b_expandedROI_size[0];
      c2_b_expandedROI = c2_b_expandedROI_size[1];
      for (c2_i64 = 0; c2_i64 < 4; c2_i64++) {
        c2_b_expandedROI_data[c2_i64] = c2_expandedROI_data[c2_i64];
      }

      c2_emxInit_real32_T(chartInstance, &c2_Ic, 2, &c2_bb_emlrtRTEI);
      c2_emxInit_real32_T(chartInstance, &c2_metricMatrix, 2, &c2_cb_emlrtRTEI);
      c2_emxInit_real32_T(chartInstance, &c2_b_metricMatrix, 2, &c2_s_emlrtRTEI);
      c2_cropImage(chartInstance, c2_I, c2_b_expandedROI_data,
                   c2_b_expandedROI_size, c2_Ic);
      c2_cornerMetric(chartInstance, c2_Ic, c2_metricMatrix);
      c2_i65 = c2_b_metricMatrix->size[0] * c2_b_metricMatrix->size[1];
      c2_b_metricMatrix->size[0] = c2_metricMatrix->size[0];
      c2_b_metricMatrix->size[1] = c2_metricMatrix->size[1];
      c2_emxEnsureCapacity_real32_T(chartInstance, c2_b_metricMatrix, c2_i65,
        &c2_s_emlrtRTEI);
      c2_c_metricMatrix = c2_b_metricMatrix->size[0];
      c2_d_metricMatrix = c2_b_metricMatrix->size[1];
      c2_p_loop_ub = c2_metricMatrix->size[0] * c2_metricMatrix->size[1] - 1;
      c2_emxFree_real32_T(chartInstance, &c2_I);
      c2_emxFree_real32_T(chartInstance, &c2_Ic);
      for (c2_i66 = 0; c2_i66 <= c2_p_loop_ub; c2_i66++) {
        c2_b_metricMatrix->data[c2_i66] = c2_metricMatrix->data[c2_i66];
      }

      c2_emxInit_real32_T(chartInstance, &c2_locations, 2, &c2_db_emlrtRTEI);
      c2_emxInit_real32_T(chartInstance, &c2_e_metricMatrix, 2, &c2_t_emlrtRTEI);
      c2_findPeaks(chartInstance, c2_b_metricMatrix, c2_params.MinQuality,
                   c2_locations);
      c2_i67 = c2_e_metricMatrix->size[0] * c2_e_metricMatrix->size[1];
      c2_e_metricMatrix->size[0] = c2_metricMatrix->size[0];
      c2_e_metricMatrix->size[1] = c2_metricMatrix->size[1];
      c2_emxEnsureCapacity_real32_T(chartInstance, c2_e_metricMatrix, c2_i67,
        &c2_t_emlrtRTEI);
      c2_f_metricMatrix = c2_e_metricMatrix->size[0];
      c2_g_metricMatrix = c2_e_metricMatrix->size[1];
      c2_q_loop_ub = c2_metricMatrix->size[0] * c2_metricMatrix->size[1] - 1;
      c2_emxFree_real32_T(chartInstance, &c2_b_metricMatrix);
      for (c2_i68 = 0; c2_i68 <= c2_q_loop_ub; c2_i68++) {
        c2_e_metricMatrix->data[c2_i68] = c2_metricMatrix->data[c2_i68];
      }

      c2_emxInit_real32_T(chartInstance, &c2_b_locations, 2, &c2_u_emlrtRTEI);
      c2_b_subPixelLocation(chartInstance, c2_e_metricMatrix, c2_locations);
      c2_i69 = c2_b_locations->size[0] * c2_b_locations->size[1];
      c2_b_locations->size[0] = c2_locations->size[0];
      c2_b_locations->size[1] = 2;
      c2_emxEnsureCapacity_real32_T(chartInstance, c2_b_locations, c2_i69,
        &c2_u_emlrtRTEI);
      c2_c_locations = c2_b_locations->size[0];
      c2_d_locations = c2_b_locations->size[1];
      c2_r_loop_ub = c2_locations->size[0] * c2_locations->size[1] - 1;
      c2_emxFree_real32_T(chartInstance, &c2_e_metricMatrix);
      for (c2_i70 = 0; c2_i70 <= c2_r_loop_ub; c2_i70++) {
        c2_b_locations->data[c2_i70] = c2_locations->data[c2_i70];
      }

      c2_emxInit_real32_T1(chartInstance, &c2_metricValues, 1, &c2_eb_emlrtRTEI);
      c2_emxInit_real32_T(chartInstance, &c2_e_locations, 2, (emlrtRTEInfo *)
                          NULL);
      c2_emxInit_real32_T1(chartInstance, &c2_b_metricValues, 1, (emlrtRTEInfo *)
                           NULL);
      c2_emxInitStruct_vision_internal_c(chartInstance, &c2_this,
        &c2_w_emlrtRTEI);
      c2_computeMetric(chartInstance, c2_metricMatrix, c2_b_locations,
                       c2_metricValues);
      c2_excludePointsOutsideROI(chartInstance, c2_params.ROI.data,
        c2_params.ROI.size, c2_expandedROI_data, c2_expandedROI_size,
        c2_locations, c2_metricValues, c2_e_locations, c2_b_metricValues);
      c2_cornerPoints_cg_cornerPoints_cg(chartInstance, c2_e_locations,
        c2_b_metricValues, &c2_r0);
      c2_emxCopyStruct_vision_internal_c(chartInstance, &c2_points, &c2_r0,
        &c2_v_emlrtRTEI);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 30);
      c2_emxCopyStruct_vision_internal_c(chartInstance, &c2_this, &c2_points,
        &c2_w_emlrtRTEI);
      _SFD_DIM_SIZE_GEQ_CHECK(500, c2_this.pLocation->size[0], 1);
      c2_featurePointLocations_size[0] = c2_this.pLocation->size[0];
      c2_featurePointLocations_size[1] = 2;
      c2_e_featurePointLocations = c2_featurePointLocations_size[0];
      c2_f_featurePointLocations = c2_featurePointLocations_size[1];
      c2_s_loop_ub = c2_this.pLocation->size[0] * c2_this.pLocation->size[1] - 1;
      c2_emxFree_real32_T(chartInstance, &c2_b_locations);
      c2_emxFree_real32_T(chartInstance, &c2_b_metricValues);
      c2_emxFree_real32_T(chartInstance, &c2_e_locations);
      c2_emxFree_real32_T(chartInstance, &c2_metricValues);
      c2_emxFree_real32_T(chartInstance, &c2_locations);
      c2_emxFree_real32_T(chartInstance, &c2_metricMatrix);
      for (c2_i71 = 0; c2_i71 <= c2_s_loop_ub; c2_i71++) {
        c2_b_featurePointLocations_data[c2_i71] = c2_this.pLocation->data[c2_i71];
      }

      c2_emxFreeStruct_vision_internal_c(chartInstance, &c2_this);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
      c2_featurePointLocations_size[0] = 0;
      c2_featurePointLocations_size[1] = 0;
      c2_c_featurePointLocations = c2_featurePointLocations_size[0];
      c2_d_featurePointLocations = c2_featurePointLocations_size[1];
    }

    c2_emxFree_real_T(chartInstance, &c2_varargin_1);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 37);
    c2_bBox_size[0] = 0;
    c2_bBox_size[1] = 0;
    c2_bBox = c2_bBox_size[0];
    c2_b_bBox = c2_bBox_size[1];
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 38);
    c2_featurePointLocations_size[0] = 0;
    c2_featurePointLocations_size[1] = 0;
    c2_featurePointLocations = c2_featurePointLocations_size[0];
    c2_b_featurePointLocations = c2_featurePointLocations_size[1];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -38);
  _SFD_SYMBOL_SCOPE_POP();
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 0, c2_bBox_size
    [0]);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 1, c2_bBox_size
    [1]);
  c2_i20 = (*chartInstance->c2_bBox_sizes)[0];
  c2_i21 = (*chartInstance->c2_bBox_sizes)[1];
  c2_d_loop_ub = c2_bBox_size[0] * c2_bBox_size[1] - 1;
  for (c2_i22 = 0; c2_i22 <= c2_d_loop_ub; c2_i22++) {
    (*chartInstance->c2_bBox_data)[c2_i22] = c2_b_bBox_data[c2_i22];
  }

  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 2, 0,
    c2_featurePointLocations_size[0]);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 2, 1,
    c2_featurePointLocations_size[1]);
  c2_i27 = (*chartInstance->c2_featurePointLocations_sizes)[0];
  c2_i28 = (*chartInstance->c2_featurePointLocations_sizes)[1];
  c2_e_loop_ub = c2_featurePointLocations_size[0] *
    c2_featurePointLocations_size[1] - 1;
  for (c2_i33 = 0; c2_i33 <= c2_e_loop_ub; c2_i33++) {
    (*chartInstance->c2_featurePointLocations_data)[c2_i33] =
      c2_b_featurePointLocations_data[c2_i33];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_emxFreeStruct_vision_internal_c(chartInstance, &c2_r0);
  c2_emxFree_real_T(chartInstance, &c2_c_videoFrameGray);
  c2_emxFreeStruct_vision_internal_c(chartInstance, &c2_points);
}

static void initSimStructsc2_DetectAndTrackFace
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)(c2_machineNumber);
  (void)(c2_chartNumber);
  (void)(c2_instanceNumber);
}

static void c2_eML_blk_kernel_free(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, real32_T
  c2_inData_data[], int32_T c2_inData_size[2])
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_u_size[2];
  int32_T c2_b_u;
  int32_T c2_c_u;
  int32_T c2_loop_ub;
  int32_T c2_i72;
  const mxArray *c2_y = NULL;
  real32_T c2_u_data[1000];
  SFc2_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc2_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u_size[0] = c2_inData_size[0];
  c2_u_size[1] = c2_inData_size[1];
  c2_b_u = c2_u_size[0];
  c2_c_u = c2_u_size[1];
  c2_loop_ub = c2_inData_size[0] * c2_inData_size[1] - 1;
  for (c2_i72 = 0; c2_i72 <= c2_loop_ub; c2_i72++) {
    c2_u_data[c2_i72] = c2_inData_data[c2_i72];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", (void *)&c2_u_data, 1, 0U, 1U, 0U, 2,
    c2_u_size[0], c2_u_size[1]), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_featurePointLocations, const char_T
  *c2_identifier, real32_T c2_y_data[], int32_T c2_y_size[2])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_featurePointLocations),
                        &c2_thisId, c2_y_data, c2_y_size);
  sf_mex_destroy(&c2_featurePointLocations);
}

static void c2_b_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real32_T c2_y_data[], int32_T c2_y_size[2])
{
  int32_T c2_i73;
  int32_T c2_tmp_size[2];
  uint32_T c2_uv0[2];
  int32_T c2_i74;
  real32_T c2_tmp_data[1000];
  boolean_T c2_bv0[2];
  int32_T c2_y;
  int32_T c2_b_y;
  int32_T c2_loop_ub;
  int32_T c2_i75;
  (void)chartInstance;
  for (c2_i73 = 0; c2_i73 < 2; c2_i73++) {
    c2_uv0[c2_i73] = 500U + (uint32_T)(-498 * c2_i73);
  }

  c2_tmp_size[0] = sf_mex_get_dimension(c2_b_u, 0);
  c2_tmp_size[1] = sf_mex_get_dimension(c2_b_u, 1);
  for (c2_i74 = 0; c2_i74 < 2; c2_i74++) {
    c2_bv0[c2_i74] = true;
  }

  sf_mex_import_vs(c2_parentId, sf_mex_dup(c2_b_u), (void *)&c2_tmp_data, 1, 1,
                   0U, 1, 0U, 2, c2_bv0, c2_uv0, c2_tmp_size);
  c2_y_size[0] = c2_tmp_size[0];
  c2_y_size[1] = c2_tmp_size[1];
  c2_y = c2_y_size[0];
  c2_b_y = c2_y_size[1];
  c2_loop_ub = c2_tmp_size[0] * c2_tmp_size[1] - 1;
  for (c2_i75 = 0; c2_i75 <= c2_loop_ub; c2_i75++) {
    c2_y_data[c2_i75] = c2_tmp_data[c2_i75];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, real32_T c2_outData_data[],
  int32_T c2_outData_size[2])
{
  const mxArray *c2_featurePointLocations;
  emlrtMsgIdentifier c2_thisId;
  real32_T c2_y_data[1000];
  int32_T c2_y_size[2];
  int32_T c2_loop_ub;
  int32_T c2_i76;
  int32_T c2_b_loop_ub;
  int32_T c2_i77;
  SFc2_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc2_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c2_featurePointLocations = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_featurePointLocations),
                        &c2_thisId, c2_y_data, c2_y_size);
  sf_mex_destroy(&c2_featurePointLocations);
  c2_outData_size[0] = c2_y_size[0];
  c2_outData_size[1] = c2_y_size[1];
  c2_loop_ub = c2_y_size[1] - 1;
  for (c2_i76 = 0; c2_i76 <= c2_loop_ub; c2_i76++) {
    c2_b_loop_ub = c2_y_size[0] - 1;
    for (c2_i77 = 0; c2_i77 <= c2_b_loop_ub; c2_i77++) {
      c2_outData_data[c2_i77 + c2_outData_size[0] * c2_i76] = c2_y_data[c2_i77 +
        c2_y_size[0] * c2_i76];
    }
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, real_T
  c2_inData_data[], int32_T c2_inData_size[2])
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_u_size[2];
  int32_T c2_b_u;
  int32_T c2_c_u;
  int32_T c2_loop_ub;
  int32_T c2_i78;
  const mxArray *c2_y = NULL;
  real_T c2_u_data[16];
  SFc2_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc2_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u_size[0] = c2_inData_size[0];
  c2_u_size[1] = c2_inData_size[1];
  c2_b_u = c2_u_size[0];
  c2_c_u = c2_u_size[1];
  c2_loop_ub = c2_inData_size[0] * c2_inData_size[1] - 1;
  for (c2_i78 = 0; c2_i78 <= c2_loop_ub; c2_i78++) {
    c2_u_data[c2_i78] = c2_inData_data[c2_i78];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", (void *)&c2_u_data, 0, 0U, 1U, 0U, 2,
    c2_u_size[0], c2_u_size[1]), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_bBox, const char_T *c2_identifier, real_T
  c2_y_data[], int32_T c2_y_size[2])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_bBox), &c2_thisId,
                        c2_y_data, c2_y_size);
  sf_mex_destroy(&c2_bBox);
}

static void c2_d_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y_data[], int32_T c2_y_size[2])
{
  int32_T c2_i79;
  int32_T c2_tmp_size[2];
  uint32_T c2_uv1[2];
  int32_T c2_i80;
  real_T c2_tmp_data[16];
  boolean_T c2_bv1[2];
  int32_T c2_y;
  int32_T c2_b_y;
  int32_T c2_loop_ub;
  int32_T c2_i81;
  (void)chartInstance;
  for (c2_i79 = 0; c2_i79 < 2; c2_i79++) {
    c2_uv1[c2_i79] = 2U + 6U * (uint32_T)c2_i79;
  }

  c2_tmp_size[0] = sf_mex_get_dimension(c2_b_u, 0);
  c2_tmp_size[1] = sf_mex_get_dimension(c2_b_u, 1);
  for (c2_i80 = 0; c2_i80 < 2; c2_i80++) {
    c2_bv1[c2_i80] = true;
  }

  sf_mex_import_vs(c2_parentId, sf_mex_dup(c2_b_u), (void *)&c2_tmp_data, 1, 0,
                   0U, 1, 0U, 2, c2_bv1, c2_uv1, c2_tmp_size);
  c2_y_size[0] = c2_tmp_size[0];
  c2_y_size[1] = c2_tmp_size[1];
  c2_y = c2_y_size[0];
  c2_b_y = c2_y_size[1];
  c2_loop_ub = c2_tmp_size[0] * c2_tmp_size[1] - 1;
  for (c2_i81 = 0; c2_i81 <= c2_loop_ub; c2_i81++) {
    c2_y_data[c2_i81] = c2_tmp_data[c2_i81];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, real_T c2_outData_data[], int32_T
  c2_outData_size[2])
{
  const mxArray *c2_bBox;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y_data[16];
  int32_T c2_y_size[2];
  int32_T c2_loop_ub;
  int32_T c2_i82;
  int32_T c2_b_loop_ub;
  int32_T c2_i83;
  SFc2_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc2_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c2_bBox = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_bBox), &c2_thisId,
                        c2_y_data, c2_y_size);
  sf_mex_destroy(&c2_bBox);
  c2_outData_size[0] = c2_y_size[0];
  c2_outData_size[1] = c2_y_size[1];
  c2_loop_ub = c2_y_size[1] - 1;
  for (c2_i82 = 0; c2_i82 <= c2_loop_ub; c2_i82++) {
    c2_b_loop_ub = c2_y_size[0] - 1;
    for (c2_i83 = 0; c2_i83 <= c2_b_loop_ub; c2_i83++) {
      c2_outData_data[c2_i83 + c2_outData_size[0] * c2_i82] = c2_y_data[c2_i83 +
        c2_y_size[0] * c2_i82];
    }
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  real_T c2_b_u;
  const mxArray *c2_y = NULL;
  SFc2_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc2_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i84;
  int32_T c2_i85;
  const mxArray *c2_y = NULL;
  int32_T c2_i86;
  SFc2_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc2_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i84 = 0;
  for (c2_i85 = 0; c2_i85 < 1024; c2_i85++) {
    for (c2_i86 = 0; c2_i86 < 1024; c2_i86++) {
      chartInstance->c2_u[c2_i86 + c2_i84] = (*(real_T (*)[1048576])c2_inData)
        [c2_i86 + c2_i84];
    }

    c2_i84 += 1024;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", chartInstance->c2_u, 0, 0U, 1U, 0U, 2,
    1024, 1024), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_e_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d3;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_d3, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d3;
  sf_mex_destroy(&c2_b_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc2_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid,
  c2_emxArray_real_T *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_emxArray_real_T *c2_b_u;
  int32_T c2_i87;
  int32_T c2_c_u;
  int32_T c2_d_u;
  int32_T c2_loop_ub;
  int32_T c2_i88;
  const mxArray *c2_y = NULL;
  SFc2_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc2_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c2_emxInit_real_T(chartInstance, &c2_b_u, 2, (emlrtRTEInfo *)NULL);
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i87 = c2_b_u->size[0] * c2_b_u->size[1];
  c2_b_u->size[0] = c2_inData->size[0];
  c2_b_u->size[1] = c2_inData->size[1];
  c2_emxEnsureCapacity_real_T(chartInstance, c2_b_u, c2_i87, (emlrtRTEInfo *)
    NULL);
  c2_c_u = c2_b_u->size[0];
  c2_d_u = c2_b_u->size[1];
  c2_loop_ub = c2_inData->size[0] * c2_inData->size[1] - 1;
  for (c2_i88 = 0; c2_i88 <= c2_loop_ub; c2_i88++) {
    c2_b_u->data[c2_i88] = c2_inData->data[c2_i88];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u->data, 0, 0U, 1U, 0U, 2,
    c2_b_u->size[0], c2_b_u->size[1]), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  c2_emxFree_real_T(chartInstance, &c2_b_u);
  return c2_mxArrayOutData;
}

static void c2_f_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_emxArray_real_T *c2_y)
{
  c2_emxArray_real_T *c2_r3;
  int32_T c2_i89;
  int32_T c2_i90;
  uint32_T c2_uv2[2];
  int32_T c2_i91;
  boolean_T c2_bv2[2];
  int32_T c2_i92;
  int32_T c2_b_y;
  int32_T c2_c_y;
  int32_T c2_loop_ub;
  int32_T c2_i93;
  c2_emxInit_real_T(chartInstance, &c2_r3, 2, (emlrtRTEInfo *)NULL);
  for (c2_i89 = 0; c2_i89 < 2; c2_i89++) {
    c2_uv2[c2_i89] = 1024U;
  }

  c2_i90 = c2_r3->size[0] * c2_r3->size[1];
  c2_r3->size[0] = sf_mex_get_dimension(c2_b_u, 0);
  c2_r3->size[1] = sf_mex_get_dimension(c2_b_u, 1);
  c2_emxEnsureCapacity_real_T(chartInstance, c2_r3, c2_i90, (emlrtRTEInfo *)NULL);
  for (c2_i91 = 0; c2_i91 < 2; c2_i91++) {
    c2_bv2[c2_i91] = true;
  }

  sf_mex_import_vs(c2_parentId, sf_mex_dup(c2_b_u), c2_r3->data, 1, 0, 0U, 1, 0U,
                   2, c2_bv2, c2_uv2, c2_r3->size);
  c2_i92 = c2_y->size[0] * c2_y->size[1];
  c2_y->size[0] = c2_r3->size[0];
  c2_y->size[1] = c2_r3->size[1];
  c2_emxEnsureCapacity_real_T(chartInstance, c2_y, c2_i92, (emlrtRTEInfo *)NULL);
  c2_b_y = c2_y->size[0];
  c2_c_y = c2_y->size[1];
  c2_loop_ub = c2_r3->size[0] * c2_r3->size[1] - 1;
  for (c2_i93 = 0; c2_i93 <= c2_loop_ub; c2_i93++) {
    c2_y->data[c2_i93] = c2_r3->data[c2_i93];
  }

  sf_mex_destroy(&c2_b_u);
  c2_emxFree_real_T(chartInstance, &c2_r3);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, c2_emxArray_real_T *c2_outData)
{
  c2_emxArray_real_T *c2_y;
  const mxArray *c2_c_videoFrameGray;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_i94;
  int32_T c2_loop_ub;
  int32_T c2_i95;
  int32_T c2_b_loop_ub;
  int32_T c2_i96;
  SFc2_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc2_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c2_emxInit_real_T(chartInstance, &c2_y, 2, (emlrtRTEInfo *)NULL);
  c2_c_videoFrameGray = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_c_videoFrameGray),
                        &c2_thisId, c2_y);
  sf_mex_destroy(&c2_c_videoFrameGray);
  c2_i94 = c2_outData->size[0] * c2_outData->size[1];
  c2_outData->size[0] = c2_y->size[0];
  c2_outData->size[1] = c2_y->size[1];
  c2_emxEnsureCapacity_real_T(chartInstance, c2_outData, c2_i94, (emlrtRTEInfo *)
    NULL);
  c2_loop_ub = c2_y->size[1] - 1;
  for (c2_i95 = 0; c2_i95 <= c2_loop_ub; c2_i95++) {
    c2_b_loop_ub = c2_y->size[0] - 1;
    for (c2_i96 = 0; c2_i96 <= c2_b_loop_ub; c2_i96++) {
      c2_outData->data[c2_i96 + c2_outData->size[0] * c2_i95] = c2_y->
        data[c2_i96 + c2_y->size[0] * c2_i95];
    }
  }

  c2_emxFree_real_T(chartInstance, &c2_y);
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid,
  c2_vision_internal_cornerPoints_cg *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_vision_internal_cornerPoints_cg c2_b_u;
  c2_emxArray_real32_T *c2_c_u;
  const mxArray *c2_y = NULL;
  int32_T c2_i97;
  int32_T c2_d_u;
  int32_T c2_e_u;
  int32_T c2_loop_ub;
  int32_T c2_i98;
  c2_emxArray_real32_T *c2_f_u;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_propValues[2];
  int32_T c2_i99;
  int32_T c2_b_loop_ub;
  int32_T c2_i100;
  const mxArray *c2_c_y = NULL;
  const char * c2_propNames[2] = { "pLocation", "pMetric" };

  const char * c2_propClasses[2] = { "vision.internal.FeaturePointsImpl",
    "vision.internal.FeaturePointsImpl" };

  SFc2_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc2_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c2_emxInitStruct_vision_internal_c(chartInstance, &c2_b_u, (emlrtRTEInfo *)
    NULL);
  c2_emxInit_real32_T(chartInstance, &c2_c_u, 2, (emlrtRTEInfo *)NULL);
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_emxCopyStruct_vision_internal_c(chartInstance, &c2_b_u, c2_inData,
    (emlrtRTEInfo *)NULL);
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create_class_instance(
    "vision.internal.cornerPoints_cg"), false);
  c2_i97 = c2_c_u->size[0] * c2_c_u->size[1];
  c2_c_u->size[0] = c2_b_u.pLocation->size[0];
  c2_c_u->size[1] = 2;
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_c_u, c2_i97, (emlrtRTEInfo *)
    NULL);
  c2_d_u = c2_c_u->size[0];
  c2_e_u = c2_c_u->size[1];
  c2_loop_ub = c2_b_u.pLocation->size[0] * c2_b_u.pLocation->size[1] - 1;
  for (c2_i98 = 0; c2_i98 <= c2_loop_ub; c2_i98++) {
    c2_c_u->data[c2_i98] = c2_b_u.pLocation->data[c2_i98];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_f_u, 1, (emlrtRTEInfo *)NULL);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_c_u->data, 1, 0U, 1U, 0U, 2,
    c2_b_u.pLocation->size[0], c2_b_u.pLocation->size[1]), false);
  c2_propValues[0] = c2_b_y;
  c2_i99 = c2_f_u->size[0];
  c2_f_u->size[0] = c2_b_u.pMetric->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_f_u, c2_i99, (emlrtRTEInfo *)
    NULL);
  c2_b_loop_ub = c2_b_u.pMetric->size[0] - 1;
  c2_emxFree_real32_T(chartInstance, &c2_c_u);
  for (c2_i100 = 0; c2_i100 <= c2_b_loop_ub; c2_i100++) {
    c2_f_u->data[c2_i100] = c2_b_u.pMetric->data[c2_i100];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_f_u->data, 1, 0U, 1U, 0U, 1,
    c2_b_u.pMetric->size[0]), false);
  c2_propValues[1] = c2_c_y;
  sf_mex_set_all_properties(&c2_y, 0, 2, c2_propNames, c2_propClasses,
    c2_propValues);
  sf_mex_assign(&c2_y, sf_mex_convert_to_redirect_source(c2_y, 0,
    "vision.internal.cornerPoints_cg"), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  c2_emxFree_real32_T(chartInstance, &c2_f_u);
  c2_emxFreeStruct_vision_internal_c(chartInstance, &c2_b_u);
  return c2_mxArrayOutData;
}

static void c2_g_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_vision_internal_cornerPoints_cg *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  const char * c2_propNames[2] = { "pLocation", "pMetric" };

  const char * c2_propClasses[2] = { "vision.internal.FeaturePointsImpl",
    "vision.internal.FeaturePointsImpl" };

  const mxArray *c2_propValues[2];
  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_mcos_class(c2_parentId, c2_b_u, "cornerPoints");
  sf_mex_assign(&c2_b_u, sf_mex_convert_to_redirect_target(c2_b_u, 0,
    "vision.internal.cornerPoints_cg"), false);
  sf_mex_check_mcos_class(c2_parentId, c2_b_u, "vision.internal.cornerPoints_cg");
  sf_mex_get_all_properties(c2_b_u, 0, 2, c2_propNames, c2_propClasses,
    c2_propValues);
  c2_thisId.fIdentifier = "pLocation";
  c2_h_emlrt_marshallIn(chartInstance, c2_propValues[0], &c2_thisId,
                        c2_y->pLocation);
  c2_thisId.fIdentifier = "pMetric";
  c2_i_emlrt_marshallIn(chartInstance, c2_propValues[1], &c2_thisId,
                        c2_y->pMetric);
  sf_mex_destroy(&c2_b_u);
}

static void c2_h_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_emxArray_real32_T *c2_y)
{
  c2_emxArray_real32_T *c2_r4;
  int32_T c2_i101;
  int32_T c2_i102;
  uint32_T c2_uv3[2];
  int32_T c2_i103;
  boolean_T c2_bv3[2];
  static boolean_T c2_bv4[2] = { true, false };

  int32_T c2_i104;
  int32_T c2_b_y;
  int32_T c2_c_y;
  int32_T c2_loop_ub;
  int32_T c2_i105;
  c2_emxInit_real32_T(chartInstance, &c2_r4, 2, (emlrtRTEInfo *)NULL);
  for (c2_i101 = 0; c2_i101 < 2; c2_i101++) {
    c2_uv3[c2_i101] = 1050625U + (uint32_T)(-1050623 * c2_i101);
  }

  c2_i102 = c2_r4->size[0] * c2_r4->size[1];
  c2_r4->size[0] = sf_mex_get_dimension(c2_b_u, 0);
  c2_r4->size[1] = sf_mex_get_dimension(c2_b_u, 1);
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_r4, c2_i102, (emlrtRTEInfo *)
    NULL);
  for (c2_i103 = 0; c2_i103 < 2; c2_i103++) {
    c2_bv3[c2_i103] = c2_bv4[c2_i103];
  }

  sf_mex_import_vs(c2_parentId, sf_mex_dup(c2_b_u), c2_r4->data, 1, 1, 0U, 1, 0U,
                   2, c2_bv3, c2_uv3, c2_r4->size);
  c2_i104 = c2_y->size[0] * c2_y->size[1];
  c2_y->size[0] = c2_r4->size[0];
  c2_y->size[1] = 2;
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_y, c2_i104, (emlrtRTEInfo *)
    NULL);
  c2_b_y = c2_y->size[0];
  c2_c_y = c2_y->size[1];
  c2_loop_ub = c2_r4->size[0] * c2_r4->size[1] - 1;
  for (c2_i105 = 0; c2_i105 <= c2_loop_ub; c2_i105++) {
    c2_y->data[c2_i105] = c2_r4->data[c2_i105];
  }

  sf_mex_destroy(&c2_b_u);
  c2_emxFree_real32_T(chartInstance, &c2_r4);
}

static void c2_i_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_emxArray_real32_T *c2_y)
{
  c2_emxArray_real32_T *c2_r5;
  uint32_T c2_uv4[1];
  int32_T c2_i106;
  boolean_T c2_bv5[1];
  int32_T c2_i107;
  int32_T c2_loop_ub;
  int32_T c2_i108;
  c2_emxInit_real32_T1(chartInstance, &c2_r5, 1, (emlrtRTEInfo *)NULL);
  c2_uv4[0] = 1050625U;
  c2_i106 = c2_r5->size[0];
  c2_r5->size[0] = sf_mex_get_dimension(c2_b_u, 0);
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_r5, c2_i106, (emlrtRTEInfo *)
    NULL);
  c2_bv5[0] = true;
  sf_mex_import_vs(c2_parentId, sf_mex_dup(c2_b_u), c2_r5->data, 1, 1, 0U, 1, 0U,
                   1, c2_bv5, c2_uv4, c2_r5->size);
  c2_i107 = c2_y->size[0];
  c2_y->size[0] = c2_r5->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_y, c2_i107, (emlrtRTEInfo *)
    NULL);
  c2_loop_ub = c2_r5->size[0] - 1;
  for (c2_i108 = 0; c2_i108 <= c2_loop_ub; c2_i108++) {
    c2_y->data[c2_i108] = c2_r5->data[c2_i108];
  }

  sf_mex_destroy(&c2_b_u);
  c2_emxFree_real32_T(chartInstance, &c2_r5);
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName,
  c2_vision_internal_cornerPoints_cg *c2_outData)
{
  c2_vision_internal_cornerPoints_cg c2_y;
  const mxArray *c2_points;
  emlrtMsgIdentifier c2_thisId;
  SFc2_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc2_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c2_emxInitStruct_vision_internal_c(chartInstance, &c2_y, (emlrtRTEInfo *)NULL);
  c2_points = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_points), &c2_thisId, &c2_y);
  sf_mex_destroy(&c2_points);
  c2_emxCopyStruct_vision_internal_c(chartInstance, c2_outData, &c2_y,
    (emlrtRTEInfo *)NULL);
  sf_mex_destroy(&c2_mxArrayInData);
  c2_emxFreeStruct_vision_internal_c(chartInstance, &c2_y);
}

const mxArray *sf_c2_DetectAndTrackFace_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static void c2_parseInputs(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_real_T *c2_I, real_T c2_varargin_2_data[], int32_T
  c2_varargin_2_size[2], c2_swtWcLs9dbtZb7aBThYWFXD *c2_params)
{
  const mxArray *c2_y = NULL;
  static char_T c2_cv10[37] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'v', 'a', 'l',
    'i', 'd', 'a', 't', 'e', 'I', 'm', 'a', 'g', 'e', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'N', 'o', 'n', 'e', 'm', 'p', 't', 'y' };

  int32_T c2_i109;
  const mxArray *c2_b_y = NULL;
  static char_T c2_cv11[26] = { 'E', 'x', 'p', 'e', 'c', 't', 'e', 'd', ' ', 'I',
    ' ', 't', 'o', ' ', 'b', 'e', ' ', 'n', 'o', 'n', 'e', 'm', 'p', 't', 'y',
    '.' };

  real_T c2_b_I[2];
  int32_T c2_roi_size[2];
  int32_T c2_roi;
  int32_T c2_b_roi;
  int32_T c2_i110;
  int32_T c2_roi_data[4];
  real_T c2_d4;
  boolean_T c2_b5;
  int32_T c2_i111;
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv12[39] = { 'v', 'i', 's', 'i', 'o', 'n', ':', 'v', 'a', 'l',
    'i', 'd', 'a', 't', 'i', 'o', 'n', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'R', 'O', 'I', 'W', 'i', 'd', 't', 'h', 'H', 'e', 'i', 'g', 'h', 't' };

  int32_T c2_q0;
  int32_T c2_q1;
  boolean_T c2_b6;
  int32_T c2_qY;
  const mxArray *c2_d_y = NULL;
  static char_T c2_cv13[33] = { 'v', 'i', 's', 'i', 'o', 'n', ':', 'v', 'a', 'l',
    'i', 'd', 'a', 't', 'i', 'o', 'n', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'R', 'O', 'I', 'V', 'a', 'l', 'u', 'e' };

  int32_T c2_b_q0;
  int32_T c2_b_q1;
  int32_T c2_b_params;
  int32_T c2_c_params;
  int32_T c2_b_qY;
  int32_T c2_i112;
  real_T c2_mtmp;
  real_T c2_d5;
  int32_T c2_i113;
  const mxArray *c2_e_y = NULL;
  static char_T c2_cv14[39] = { 'v', 'i', 's', 'i', 'o', 'n', ':', 'h', 'a', 'r',
    'r', 'i', 's', 'M', 'i', 'n', 'E', 'i', 'g', 'e', 'n', ':', 'f', 'i', 'l',
    't', 'e', 'r', 'S', 'i', 'z', 'e', 'G', 'T', 'I', 'm', 'a', 'g', 'e' };

  real_T c2_b_u;
  const mxArray *c2_f_y = NULL;
  (void)chartInstance;
  (void)c2_varargin_2_size;
  if (!((c2_I->size[0] == 0) || (c2_I->size[1] == 0))) {
  } else {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv10, 10, 0U, 1U, 0U, 2, 1, 37),
                  false);
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv11, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_y, 14,
                      c2_b_y);
  }

  for (c2_i109 = 0; c2_i109 < 2; c2_i109++) {
    c2_b_I[c2_i109] = (real_T)c2_I->size[c2_i109];
  }

  c2_params->MinQuality = 0.01F;
  c2_params->FilterSize = 5.0;
  c2_params->usingROI = true;
  c2_roi_size[0] = 1;
  c2_roi_size[1] = 4;
  c2_roi = c2_roi_size[0];
  c2_b_roi = c2_roi_size[1];
  for (c2_i110 = 0; c2_i110 < 4; c2_i110++) {
    c2_d4 = muDoubleScalarRound(c2_varargin_2_data[c2_i110]);
    if (c2_d4 < 2.147483648E+9) {
      if (c2_d4 >= -2.147483648E+9) {
        c2_i111 = (int32_T)c2_d4;
      } else {
        c2_i111 = MIN_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      }
    } else if (c2_d4 >= 2.147483648E+9) {
      c2_i111 = MAX_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
    } else {
      c2_i111 = 0;
    }

    c2_roi_data[c2_i110] = c2_i111;
  }

  if (((real_T)c2_roi_data[2] < 0.0) || ((real_T)c2_roi_data[3] < 0.0)) {
    c2_b5 = true;
  } else {
    c2_b5 = false;
  }

  if (!c2_b5) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv12, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_c_y));
  }

  if (((real_T)c2_roi_data[0] < 1.0) || ((real_T)c2_roi_data[1] < 1.0)) {
    c2_b6 = true;
  } else {
    c2_q0 = c2_roi_data[0];
    c2_q1 = c2_roi_data[2];
    if ((c2_q0 < 0) && (c2_q1 < MIN_int32_T - c2_q0)) {
      c2_qY = MIN_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
    } else if ((c2_q0 > 0) && (c2_q1 > MAX_int32_T - c2_q0)) {
      c2_qY = MAX_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
    } else {
      c2_qY = c2_q0 + c2_q1;
    }

    if ((real_T)c2_qY > c2_b_I[1] + 1.0) {
      c2_b6 = true;
    } else {
      c2_b_q0 = c2_roi_data[1];
      c2_b_q1 = c2_roi_data[3];
      if ((c2_b_q0 < 0) && (c2_b_q1 < MIN_int32_T - c2_b_q0)) {
        c2_b_qY = MIN_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      } else if ((c2_b_q0 > 0) && (c2_b_q1 > MAX_int32_T - c2_b_q0)) {
        c2_b_qY = MAX_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      } else {
        c2_b_qY = c2_b_q0 + c2_b_q1;
      }

      if ((real_T)c2_b_qY > c2_b_I[0] + 1.0) {
        c2_b6 = true;
      } else {
        c2_b6 = false;
      }
    }
  }

  if (!c2_b6) {
  } else {
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv13, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_d_y));
  }

  c2_params->ROI.size[0] = 1;
  c2_params->ROI.size[1] = 4;
  c2_b_params = c2_params->ROI.size[0];
  c2_c_params = c2_params->ROI.size[1];
  for (c2_i112 = 0; c2_i112 < 4; c2_i112++) {
    c2_d5 = muDoubleScalarRound(c2_varargin_2_data[c2_i112]);
    if (c2_d5 < 2.147483648E+9) {
      if (c2_d5 >= -2.147483648E+9) {
        c2_i113 = (int32_T)c2_d5;
      } else {
        c2_i113 = MIN_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      }
    } else if (c2_d5 >= 2.147483648E+9) {
      c2_i113 = MAX_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
    } else {
      c2_i113 = 0;
    }

    c2_params->ROI.data[c2_i112] = c2_i113;
  }

  c2_mtmp = c2_b_I[0];
  if (c2_b_I[1] < c2_b_I[0]) {
    c2_mtmp = c2_b_I[1];
  }

  if (!(5.0 > c2_mtmp)) {
  } else {
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv14, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c2_b_u = 5.0;
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c2_e_y, 14, c2_f_y));
  }
}

static void c2_expandROI(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  real_T c2_imageSize[2], int32_T c2_originalROI_data[], int32_T
  c2_originalROI_size[2], real_T c2_expandSize, int32_T c2_expandedROI_data[],
  int32_T c2_expandedROI_size[2])
{
  real_T c2_d6;
  int32_T c2_i114;
  int32_T c2_varargin_2;
  int32_T c2_x1;
  real_T c2_d7;
  int32_T c2_i115;
  int32_T c2_b_varargin_2;
  int32_T c2_y1;
  int32_T c2_q0;
  int32_T c2_q1;
  int32_T c2_qY;
  int32_T c2_b_q0;
  int32_T c2_b_q1;
  int32_T c2_b_qY;
  real_T c2_d8;
  int32_T c2_i116;
  int32_T c2_c_varargin_2;
  int32_T c2_x2;
  real_T c2_d9;
  int32_T c2_c_q0;
  int32_T c2_c_q1;
  int32_T c2_i117;
  int32_T c2_c_qY;
  int32_T c2_d_q0;
  int32_T c2_d_q1;
  int32_T c2_d_qY;
  real_T c2_d10;
  int32_T c2_i118;
  int32_T c2_d_varargin_2;
  int32_T c2_y2;
  real_T c2_d11;
  int32_T c2_b_x1[4];
  int32_T c2_i119;
  int32_T c2_e_q0;
  int32_T c2_e_q1;
  int32_T c2_e_qY;
  int32_T c2_f_q0;
  int32_T c2_f_q1;
  int32_T c2_f_qY;
  int32_T c2_g_q0;
  int32_T c2_g_q1;
  int32_T c2_g_qY;
  int32_T c2_h_q0;
  int32_T c2_h_q1;
  int32_T c2_h_qY;
  int32_T c2_i120;
  (void)chartInstance;
  (void)c2_expandSize;
  c2_d6 = muDoubleScalarRound((real_T)c2_originalROI_data[0] - 2.0);
  if (c2_d6 < 2.147483648E+9) {
    if (c2_d6 >= -2.147483648E+9) {
      c2_i114 = (int32_T)c2_d6;
    } else {
      c2_i114 = MIN_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
    }
  } else if (c2_d6 >= 2.147483648E+9) {
    c2_i114 = MAX_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else {
    c2_i114 = 0;
  }

  c2_varargin_2 = c2_i114;
  if (1.0 > (real_T)c2_varargin_2) {
    c2_x1 = 1;
  } else {
    c2_x1 = c2_varargin_2;
  }

  c2_d7 = muDoubleScalarRound((real_T)c2_originalROI_data[c2_originalROI_size[0]]
    - 2.0);
  if (c2_d7 < 2.147483648E+9) {
    if (c2_d7 >= -2.147483648E+9) {
      c2_i115 = (int32_T)c2_d7;
    } else {
      c2_i115 = MIN_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
    }
  } else if (c2_d7 >= 2.147483648E+9) {
    c2_i115 = MAX_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else {
    c2_i115 = 0;
  }

  c2_b_varargin_2 = c2_i115;
  if (1.0 > (real_T)c2_b_varargin_2) {
    c2_y1 = 1;
  } else {
    c2_y1 = c2_b_varargin_2;
  }

  c2_q0 = c2_originalROI_data[0];
  c2_q1 = c2_originalROI_data[c2_originalROI_size[0] << 1];
  if ((c2_q0 < 0) && (c2_q1 < MIN_int32_T - c2_q0)) {
    c2_qY = MIN_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else if ((c2_q0 > 0) && (c2_q1 > MAX_int32_T - c2_q0)) {
    c2_qY = MAX_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else {
    c2_qY = c2_q0 + c2_q1;
  }

  c2_b_q0 = c2_qY;
  c2_b_q1 = 1;
  if ((c2_b_q1 < 0) && (c2_b_q0 > c2_b_q1 + MAX_int32_T)) {
    c2_b_qY = MAX_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else if ((c2_b_q1 > 0) && (c2_b_q0 < c2_b_q1 + MIN_int32_T)) {
    c2_b_qY = MIN_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else {
    c2_b_qY = c2_b_q0 - c2_b_q1;
  }

  c2_d8 = muDoubleScalarRound((real_T)c2_b_qY + 2.0);
  if (c2_d8 < 2.147483648E+9) {
    if (c2_d8 >= -2.147483648E+9) {
      c2_i116 = (int32_T)c2_d8;
    } else {
      c2_i116 = MIN_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
    }
  } else if (c2_d8 >= 2.147483648E+9) {
    c2_i116 = MAX_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else {
    c2_i116 = 0;
  }

  c2_c_varargin_2 = c2_i116;
  if (c2_imageSize[1] < (real_T)c2_c_varargin_2) {
    c2_d9 = muDoubleScalarRound(c2_imageSize[1]);
    if (c2_d9 < 2.147483648E+9) {
      if (c2_d9 >= -2.147483648E+9) {
        c2_i117 = (int32_T)c2_d9;
      } else {
        c2_i117 = MIN_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      }
    } else if (c2_d9 >= 2.147483648E+9) {
      c2_i117 = MAX_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
    } else {
      c2_i117 = 0;
    }

    c2_x2 = c2_i117;
  } else {
    c2_x2 = c2_c_varargin_2;
  }

  c2_c_q0 = c2_originalROI_data[c2_originalROI_size[0]];
  c2_c_q1 = c2_originalROI_data[c2_originalROI_size[0] * 3];
  if ((c2_c_q0 < 0) && (c2_c_q1 < MIN_int32_T - c2_c_q0)) {
    c2_c_qY = MIN_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else if ((c2_c_q0 > 0) && (c2_c_q1 > MAX_int32_T - c2_c_q0)) {
    c2_c_qY = MAX_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else {
    c2_c_qY = c2_c_q0 + c2_c_q1;
  }

  c2_d_q0 = c2_c_qY;
  c2_d_q1 = 1;
  if ((c2_d_q1 < 0) && (c2_d_q0 > c2_d_q1 + MAX_int32_T)) {
    c2_d_qY = MAX_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else if ((c2_d_q1 > 0) && (c2_d_q0 < c2_d_q1 + MIN_int32_T)) {
    c2_d_qY = MIN_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else {
    c2_d_qY = c2_d_q0 - c2_d_q1;
  }

  c2_d10 = muDoubleScalarRound((real_T)c2_d_qY + 2.0);
  if (c2_d10 < 2.147483648E+9) {
    if (c2_d10 >= -2.147483648E+9) {
      c2_i118 = (int32_T)c2_d10;
    } else {
      c2_i118 = MIN_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
    }
  } else if (c2_d10 >= 2.147483648E+9) {
    c2_i118 = MAX_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else {
    c2_i118 = 0;
  }

  c2_d_varargin_2 = c2_i118;
  if (c2_imageSize[0] < (real_T)c2_d_varargin_2) {
    c2_d11 = muDoubleScalarRound(c2_imageSize[0]);
    if (c2_d11 < 2.147483648E+9) {
      if (c2_d11 >= -2.147483648E+9) {
        c2_i119 = (int32_T)c2_d11;
      } else {
        c2_i119 = MIN_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      }
    } else if (c2_d11 >= 2.147483648E+9) {
      c2_i119 = MAX_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
    } else {
      c2_i119 = 0;
    }

    c2_y2 = c2_i119;
  } else {
    c2_y2 = c2_d_varargin_2;
  }

  c2_b_x1[0] = c2_x1;
  c2_b_x1[1] = c2_y1;
  c2_e_q0 = c2_x2;
  c2_e_q1 = c2_x1;
  if ((c2_e_q0 >= 0) && (c2_e_q1 < c2_e_q0 - MAX_int32_T)) {
    c2_e_qY = MAX_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else if ((c2_e_q0 < 0) && (c2_e_q1 > c2_e_q0 - MIN_int32_T)) {
    c2_e_qY = MIN_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else {
    c2_e_qY = c2_e_q0 - c2_e_q1;
  }

  c2_f_q0 = c2_e_qY;
  c2_f_q1 = 1;
  if ((c2_f_q1 < 0) && (c2_f_q0 < MIN_int32_T - c2_f_q1)) {
    c2_f_qY = MIN_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else if ((c2_f_q1 > 0) && (c2_f_q0 > MAX_int32_T - c2_f_q1)) {
    c2_f_qY = MAX_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else {
    c2_f_qY = c2_f_q0 + c2_f_q1;
  }

  c2_b_x1[2] = c2_f_qY;
  c2_g_q0 = c2_y2;
  c2_g_q1 = c2_y1;
  if ((c2_g_q0 >= 0) && (c2_g_q1 < c2_g_q0 - MAX_int32_T)) {
    c2_g_qY = MAX_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else if ((c2_g_q0 < 0) && (c2_g_q1 > c2_g_q0 - MIN_int32_T)) {
    c2_g_qY = MIN_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else {
    c2_g_qY = c2_g_q0 - c2_g_q1;
  }

  c2_h_q0 = c2_g_qY;
  c2_h_q1 = 1;
  if ((c2_h_q1 < 0) && (c2_h_q0 < MIN_int32_T - c2_h_q1)) {
    c2_h_qY = MIN_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else if ((c2_h_q1 > 0) && (c2_h_q0 > MAX_int32_T - c2_h_q1)) {
    c2_h_qY = MAX_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else {
    c2_h_qY = c2_h_q0 + c2_h_q1;
  }

  c2_b_x1[3] = c2_h_qY;
  c2_expandedROI_size[0] = 1;
  c2_expandedROI_size[1] = 4;
  for (c2_i120 = 0; c2_i120 < 4; c2_i120++) {
    c2_expandedROI_data[c2_expandedROI_size[0] * c2_i120] = c2_b_x1[c2_i120];
  }
}

static void c2_cropImage(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_real32_T *c2_I, int32_T c2_roi_data[], int32_T c2_roi_size[2],
  c2_emxArray_real32_T *c2_Iroi)
{
  const mxArray *c2_y = NULL;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  int32_T c2_q0;
  int32_T c2_q1;
  int32_T c2_qY;
  int32_T c2_b_q0;
  int32_T c2_b_q1;
  int32_T c2_b_qY;
  int32_T c2_r2;
  int32_T c2_c_q0;
  int32_T c2_c_q1;
  int32_T c2_c_qY;
  int32_T c2_d_q0;
  int32_T c2_d_q1;
  int32_T c2_d_qY;
  int32_T c2_c2;
  int32_T c2_i121;
  int32_T c2_i122;
  int32_T c2_i123;
  int32_T c2_i124;
  int32_T c2_b_I[2];
  int32_T c2_i125;
  int32_T c2_loop_ub;
  int32_T c2_i126;
  int32_T c2_b_loop_ub;
  int32_T c2_i127;
  (void)c2_roi_size;
  if ((real_T)c2_roi_data[2] <= (real_T)c2_I->size[1]) {
  } else {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_y));
  }

  if ((real_T)c2_roi_data[3] <= (real_T)c2_I->size[0]) {
  } else {
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_b_y));
  }

  if ((real_T)c2_roi_data[0] <= (real_T)c2_I->size[1]) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_c_y));
  }

  if ((real_T)c2_roi_data[1] <= (real_T)c2_I->size[0]) {
  } else {
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_d_y));
  }

  c2_q0 = c2_roi_data[3];
  c2_q1 = c2_roi_data[1];
  if ((c2_q0 < 0) && (c2_q1 < MIN_int32_T - c2_q0)) {
    c2_qY = MIN_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else if ((c2_q0 > 0) && (c2_q1 > MAX_int32_T - c2_q0)) {
    c2_qY = MAX_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else {
    c2_qY = c2_q0 + c2_q1;
  }

  c2_b_q0 = c2_qY;
  c2_b_q1 = 1;
  if ((c2_b_q1 < 0) && (c2_b_q0 > c2_b_q1 + MAX_int32_T)) {
    c2_b_qY = MAX_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else if ((c2_b_q1 > 0) && (c2_b_q0 < c2_b_q1 + MIN_int32_T)) {
    c2_b_qY = MIN_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else {
    c2_b_qY = c2_b_q0 - c2_b_q1;
  }

  c2_r2 = c2_b_qY;
  c2_c_q0 = c2_roi_data[2];
  c2_c_q1 = c2_roi_data[0];
  if ((c2_c_q0 < 0) && (c2_c_q1 < MIN_int32_T - c2_c_q0)) {
    c2_c_qY = MIN_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else if ((c2_c_q0 > 0) && (c2_c_q1 > MAX_int32_T - c2_c_q0)) {
    c2_c_qY = MAX_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else {
    c2_c_qY = c2_c_q0 + c2_c_q1;
  }

  c2_d_q0 = c2_c_qY;
  c2_d_q1 = 1;
  if ((c2_d_q1 < 0) && (c2_d_q0 > c2_d_q1 + MAX_int32_T)) {
    c2_d_qY = MAX_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else if ((c2_d_q1 > 0) && (c2_d_q0 < c2_d_q1 + MIN_int32_T)) {
    c2_d_qY = MIN_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else {
    c2_d_qY = c2_d_q0 - c2_d_q1;
  }

  c2_c2 = c2_d_qY;
  if (c2_roi_data[1] > c2_r2) {
    c2_i121 = 1;
    c2_i122 = 0;
  } else {
    c2_i121 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_roi_data[1], 1, c2_I->size[0]);
    c2_i122 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_r2, 1, c2_I->size[0]);
  }

  if (c2_roi_data[0] > c2_c2) {
    c2_i123 = 1;
    c2_i124 = 0;
  } else {
    c2_i123 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_roi_data[0], 1, c2_I->size[1]);
    c2_i124 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_c2, 1, c2_I->size[1]);
  }

  c2_b_I[0] = c2_I->size[0];
  c2_b_I[1] = c2_I->size[1];
  c2_i125 = c2_Iroi->size[0] * c2_Iroi->size[1];
  c2_Iroi->size[0] = (c2_i122 - c2_i121) + 1;
  c2_Iroi->size[1] = (c2_i124 - c2_i123) + 1;
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_Iroi, c2_i125,
    &c2_kb_emlrtRTEI);
  c2_loop_ub = c2_i124 - c2_i123;
  for (c2_i126 = 0; c2_i126 <= c2_loop_ub; c2_i126++) {
    c2_b_loop_ub = c2_i122 - c2_i121;
    for (c2_i127 = 0; c2_i127 <= c2_b_loop_ub; c2_i127++) {
      c2_Iroi->data[c2_i127 + c2_Iroi->size[0] * c2_i126] = c2_I->data[((c2_i121
        + c2_i127) + c2_b_I[0] * ((c2_i123 + c2_i126) - 1)) - 1];
    }
  }
}

static void c2_cornerMetric(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_real32_T *c2_I, c2_emxArray_real32_T *c2_metric)
{
  c2_emxArray_real32_T *c2_r6;
  int32_T c2_i128;
  int32_T c2_i129;
  int32_T c2_i130;
  int32_T c2_loop_ub;
  int32_T c2_i131;
  c2_emxArray_real32_T *c2_A;
  int32_T c2_i132;
  int32_T c2_b_A;
  int32_T c2_c_A;
  int32_T c2_b_loop_ub;
  int32_T c2_i133;
  int32_T c2_i134;
  int32_T c2_i135;
  int32_T c2_i136;
  int32_T c2_c_loop_ub;
  int32_T c2_i137;
  c2_emxArray_real32_T *c2_B;
  int32_T c2_i138;
  int32_T c2_b_B;
  int32_T c2_c_B;
  int32_T c2_d_loop_ub;
  int32_T c2_i139;
  int32_T c2_i140;
  int32_T c2_i141;
  int32_T c2_i142;
  int32_T c2_i143;
  c2_emxArray_real32_T *c2_d_A;
  int32_T c2_i144;
  int32_T c2_e_loop_ub;
  int32_T c2_i145;
  int32_T c2_i146;
  int32_T c2_f_loop_ub;
  int32_T c2_i147;
  int32_T c2_g_loop_ub;
  int32_T c2_i148;
  int32_T c2_h_loop_ub;
  int32_T c2_i149;
  int32_T c2_i150;
  int32_T c2_i151;
  int32_T c2_i152;
  int32_T c2_i153;
  c2_emxArray_real32_T *c2_d_B;
  int32_T c2_i154;
  int32_T c2_i_loop_ub;
  int32_T c2_i155;
  int32_T c2_i156;
  int32_T c2_j_loop_ub;
  int32_T c2_i157;
  int32_T c2_k_loop_ub;
  int32_T c2_i158;
  int32_T c2_l_loop_ub;
  int32_T c2_i159;
  int32_T c2_i160;
  int32_T c2_i161;
  int32_T c2_e_A[2];
  c2_emxArray_real32_T *c2_C;
  int32_T c2_e_B[2];
  int32_T c2_i162;
  int32_T c2_b_C;
  int32_T c2_c_C;
  int32_T c2_m_loop_ub;
  int32_T c2_i163;
  int32_T c2_i164;
  int32_T c2_f_A;
  int32_T c2_g_A;
  int32_T c2_h_A;
  int32_T c2_i_A;
  int32_T c2_j_A;
  int32_T c2_k_A;
  int32_T c2_n_loop_ub;
  int32_T c2_i165;
  int32_T c2_i166;
  int32_T c2_f_B;
  int32_T c2_g_B;
  int32_T c2_h_B;
  int32_T c2_i_B;
  int32_T c2_j_B;
  int32_T c2_k_B;
  int32_T c2_o_loop_ub;
  int32_T c2_i167;
  c2_emxArray_real32_T *c2_l_A;
  int32_T c2_i168;
  int32_T c2_m_A;
  int32_T c2_n_A;
  int32_T c2_p_loop_ub;
  int32_T c2_i169;
  c2_emxArray_real32_T *c2_l_B;
  int32_T c2_i170;
  int32_T c2_m_B;
  int32_T c2_n_B;
  int32_T c2_q_loop_ub;
  int32_T c2_i171;
  c2_emxArray_real32_T *c2_d_C;
  int32_T c2_i172;
  int32_T c2_e_C;
  int32_T c2_f_C;
  int32_T c2_r_loop_ub;
  int32_T c2_i173;
  c2_emxArray_real32_T *c2_o_A;
  real_T c2_p_A;
  int32_T c2_i174;
  real_T c2_q_A;
  int32_T c2_i175;
  int32_T c2_i176;
  int32_T c2_s_loop_ub;
  int32_T c2_i177;
  int32_T c2_i178;
  int32_T c2_t_loop_ub;
  int32_T c2_i179;
  int32_T c2_u_loop_ub;
  int32_T c2_i180;
  int32_T c2_v_loop_ub;
  c2_emxArray_real32_T *c2_o_B;
  int32_T c2_i181;
  real_T c2_p_B;
  int32_T c2_i182;
  real_T c2_q_B;
  int32_T c2_i183;
  int32_T c2_i184;
  int32_T c2_w_loop_ub;
  int32_T c2_i185;
  int32_T c2_i186;
  int32_T c2_x_loop_ub;
  int32_T c2_i187;
  int32_T c2_y_loop_ub;
  int32_T c2_i188;
  int32_T c2_ab_loop_ub;
  c2_emxArray_real32_T *c2_g_C;
  int32_T c2_i189;
  real_T c2_h_C;
  int32_T c2_i190;
  real_T c2_i_C;
  int32_T c2_i191;
  int32_T c2_i192;
  int32_T c2_bb_loop_ub;
  int32_T c2_i193;
  int32_T c2_i194;
  int32_T c2_cb_loop_ub;
  int32_T c2_i195;
  int32_T c2_db_loop_ub;
  int32_T c2_i196;
  int32_T c2_eb_loop_ub;
  int32_T c2_i197;
  int32_T c2_i198;
  int32_T c2_i199;
  int32_T c2_r_A[2];
  int32_T c2_r_B[2];
  int32_T c2_i200;
  int32_T c2_i201;
  int32_T c2_s_A[2];
  c2_emxArray_real32_T *c2_t_A;
  int32_T c2_s_B[2];
  int32_T c2_i202;
  int32_T c2_u_A;
  int32_T c2_v_A;
  int32_T c2_fb_loop_ub;
  int32_T c2_i203;
  c2_emxArray_real32_T *c2_b;
  c2_emxArray_real32_T *c2_j_C;
  int32_T c2_i204;
  int32_T c2_k_C;
  int32_T c2_l_C;
  int32_T c2_gb_loop_ub;
  int32_T c2_i205;
  int32_T c2_i206;
  int32_T c2_b_b;
  int32_T c2_c_b;
  int32_T c2_d_b;
  int32_T c2_e_b;
  int32_T c2_hb_loop_ub;
  int32_T c2_i207;
  int32_T c2_i208;
  int32_T c2_i209;
  int32_T c2_b_metric[2];
  int32_T c2_f_b[2];
  int32_T c2_i210;
  int32_T c2_c_metric;
  int32_T c2_d_metric;
  int32_T c2_e_metric;
  int32_T c2_f_metric;
  int32_T c2_ib_loop_ub;
  int32_T c2_i211;
  int32_T c2_i212;
  int32_T c2_i213;
  int32_T c2_w_A[2];
  int32_T c2_g_metric[2];
  int32_T c2_i214;
  int32_T c2_h_metric;
  int32_T c2_i_metric;
  int32_T c2_j_metric;
  int32_T c2_k_metric;
  int32_T c2_jb_loop_ub;
  int32_T c2_i215;
  c2_emxInit_real32_T(chartInstance, &c2_r6, 2, &c2_lb_emlrtRTEI);
  c2_i128 = c2_r6->size[0] * c2_r6->size[1];
  c2_r6->size[0] = c2_I->size[0];
  c2_r6->size[1] = c2_I->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_r6, c2_i128, &c2_lb_emlrtRTEI);
  c2_i129 = c2_r6->size[0];
  c2_i130 = c2_r6->size[1];
  c2_loop_ub = c2_I->size[0] * c2_I->size[1] - 1;
  for (c2_i131 = 0; c2_i131 <= c2_loop_ub; c2_i131++) {
    c2_r6->data[c2_i131] = c2_I->data[c2_i131];
  }

  c2_emxInit_real32_T(chartInstance, &c2_A, 2, &c2_mb_emlrtRTEI);
  c2_d_imfilter(chartInstance, c2_r6);
  c2_i132 = c2_A->size[0] * c2_A->size[1];
  c2_A->size[0] = c2_r6->size[0];
  c2_A->size[1] = c2_r6->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_A, c2_i132, &c2_mb_emlrtRTEI);
  c2_b_A = c2_A->size[0];
  c2_c_A = c2_A->size[1];
  c2_b_loop_ub = c2_r6->size[0] * c2_r6->size[1] - 1;
  for (c2_i133 = 0; c2_i133 <= c2_b_loop_ub; c2_i133++) {
    c2_A->data[c2_i133] = c2_r6->data[c2_i133];
  }

  c2_i134 = c2_r6->size[0] * c2_r6->size[1];
  c2_r6->size[0] = c2_I->size[0];
  c2_r6->size[1] = c2_I->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_r6, c2_i134, &c2_nb_emlrtRTEI);
  c2_i135 = c2_r6->size[0];
  c2_i136 = c2_r6->size[1];
  c2_c_loop_ub = c2_I->size[0] * c2_I->size[1] - 1;
  for (c2_i137 = 0; c2_i137 <= c2_c_loop_ub; c2_i137++) {
    c2_r6->data[c2_i137] = c2_I->data[c2_i137];
  }

  c2_emxInit_real32_T(chartInstance, &c2_B, 2, &c2_ob_emlrtRTEI);
  c2_e_imfilter(chartInstance, c2_r6);
  c2_i138 = c2_B->size[0] * c2_B->size[1];
  c2_B->size[0] = c2_r6->size[0];
  c2_B->size[1] = c2_r6->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_B, c2_i138, &c2_ob_emlrtRTEI);
  c2_b_B = c2_B->size[0];
  c2_c_B = c2_B->size[1];
  c2_d_loop_ub = c2_r6->size[0] * c2_r6->size[1] - 1;
  for (c2_i139 = 0; c2_i139 <= c2_d_loop_ub; c2_i139++) {
    c2_B->data[c2_i139] = c2_r6->data[c2_i139];
  }

  c2_emxFree_real32_T(chartInstance, &c2_r6);
  if (2.0 > (real_T)c2_A->size[0] - 1.0) {
    c2_i140 = 1;
    c2_i141 = 0;
  } else {
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, 2, 1, c2_A->size[0]);
    c2_i140 = 2;
    c2_i141 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)((real_T)c2_A->size[0]
      - 1.0), 1, c2_A->size[0]);
  }

  if (2.0 > (real_T)c2_A->size[1] - 1.0) {
    c2_i142 = 1;
    c2_i143 = 0;
  } else {
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, 2, 1, c2_A->size[1]);
    c2_i142 = 2;
    c2_i143 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)((real_T)c2_A->size[1]
      - 1.0), 1, c2_A->size[1]);
  }

  c2_emxInit_real32_T(chartInstance, &c2_d_A, 2, &c2_pb_emlrtRTEI);
  c2_i144 = c2_d_A->size[0] * c2_d_A->size[1];
  c2_d_A->size[0] = (c2_i141 - c2_i140) + 1;
  c2_d_A->size[1] = (c2_i143 - c2_i142) + 1;
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_d_A, c2_i144, &c2_pb_emlrtRTEI);
  c2_e_loop_ub = c2_i143 - c2_i142;
  for (c2_i145 = 0; c2_i145 <= c2_e_loop_ub; c2_i145++) {
    c2_f_loop_ub = c2_i141 - c2_i140;
    for (c2_i147 = 0; c2_i147 <= c2_f_loop_ub; c2_i147++) {
      c2_d_A->data[c2_i147 + c2_d_A->size[0] * c2_i145] = c2_A->data[((c2_i140 +
        c2_i147) + c2_A->size[0] * ((c2_i142 + c2_i145) - 1)) - 1];
    }
  }

  c2_i146 = c2_A->size[0] * c2_A->size[1];
  c2_A->size[0] = c2_d_A->size[0];
  c2_A->size[1] = c2_d_A->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_A, c2_i146, &c2_qb_emlrtRTEI);
  c2_g_loop_ub = c2_d_A->size[1] - 1;
  for (c2_i148 = 0; c2_i148 <= c2_g_loop_ub; c2_i148++) {
    c2_h_loop_ub = c2_d_A->size[0] - 1;
    for (c2_i149 = 0; c2_i149 <= c2_h_loop_ub; c2_i149++) {
      c2_A->data[c2_i149 + c2_A->size[0] * c2_i148] = c2_d_A->data[c2_i149 +
        c2_d_A->size[0] * c2_i148];
    }
  }

  c2_emxFree_real32_T(chartInstance, &c2_d_A);
  if (2.0 > (real_T)c2_B->size[0] - 1.0) {
    c2_i150 = 1;
    c2_i151 = 0;
  } else {
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, 2, 1, c2_B->size[0]);
    c2_i150 = 2;
    c2_i151 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)((real_T)c2_B->size[0]
      - 1.0), 1, c2_B->size[0]);
  }

  if (2.0 > (real_T)c2_B->size[1] - 1.0) {
    c2_i152 = 1;
    c2_i153 = 0;
  } else {
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, 2, 1, c2_B->size[1]);
    c2_i152 = 2;
    c2_i153 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)((real_T)c2_B->size[1]
      - 1.0), 1, c2_B->size[1]);
  }

  c2_emxInit_real32_T(chartInstance, &c2_d_B, 2, &c2_rb_emlrtRTEI);
  c2_i154 = c2_d_B->size[0] * c2_d_B->size[1];
  c2_d_B->size[0] = (c2_i151 - c2_i150) + 1;
  c2_d_B->size[1] = (c2_i153 - c2_i152) + 1;
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_d_B, c2_i154, &c2_rb_emlrtRTEI);
  c2_i_loop_ub = c2_i153 - c2_i152;
  for (c2_i155 = 0; c2_i155 <= c2_i_loop_ub; c2_i155++) {
    c2_j_loop_ub = c2_i151 - c2_i150;
    for (c2_i157 = 0; c2_i157 <= c2_j_loop_ub; c2_i157++) {
      c2_d_B->data[c2_i157 + c2_d_B->size[0] * c2_i155] = c2_B->data[((c2_i150 +
        c2_i157) + c2_B->size[0] * ((c2_i152 + c2_i155) - 1)) - 1];
    }
  }

  c2_i156 = c2_B->size[0] * c2_B->size[1];
  c2_B->size[0] = c2_d_B->size[0];
  c2_B->size[1] = c2_d_B->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_B, c2_i156, &c2_sb_emlrtRTEI);
  c2_k_loop_ub = c2_d_B->size[1] - 1;
  for (c2_i158 = 0; c2_i158 <= c2_k_loop_ub; c2_i158++) {
    c2_l_loop_ub = c2_d_B->size[0] - 1;
    for (c2_i160 = 0; c2_i160 <= c2_l_loop_ub; c2_i160++) {
      c2_B->data[c2_i160 + c2_B->size[0] * c2_i158] = c2_d_B->data[c2_i160 +
        c2_d_B->size[0] * c2_i158];
    }
  }

  c2_emxFree_real32_T(chartInstance, &c2_d_B);
  for (c2_i159 = 0; c2_i159 < 2; c2_i159++) {
    c2_e_A[c2_i159] = c2_A->size[c2_i159];
  }

  for (c2_i161 = 0; c2_i161 < 2; c2_i161++) {
    c2_e_B[c2_i161] = c2_B->size[c2_i161];
  }

  c2_emxInit_real32_T(chartInstance, &c2_C, 2, &c2_tb_emlrtRTEI);
  _SFD_SIZE_EQ_CHECK_ND(c2_e_A, c2_e_B, 2);
  c2_i162 = c2_C->size[0] * c2_C->size[1];
  c2_C->size[0] = c2_A->size[0];
  c2_C->size[1] = c2_A->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_C, c2_i162, &c2_tb_emlrtRTEI);
  c2_b_C = c2_C->size[0];
  c2_c_C = c2_C->size[1];
  c2_m_loop_ub = c2_A->size[0] * c2_A->size[1] - 1;
  for (c2_i163 = 0; c2_i163 <= c2_m_loop_ub; c2_i163++) {
    c2_C->data[c2_i163] = c2_A->data[c2_i163] * c2_B->data[c2_i163];
  }

  c2_i164 = c2_A->size[0] * c2_A->size[1];
  c2_A->size[0];
  c2_A->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_A, c2_i164, &c2_ub_emlrtRTEI);
  c2_f_A = c2_A->size[0];
  c2_g_A = c2_A->size[1];
  c2_h_A = c2_A->size[0];
  c2_i_A = c2_A->size[1];
  c2_j_A = c2_A->size[0];
  c2_k_A = c2_A->size[1];
  c2_n_loop_ub = c2_f_A * c2_g_A - 1;
  for (c2_i165 = 0; c2_i165 <= c2_n_loop_ub; c2_i165++) {
    c2_A->data[c2_i165] *= c2_A->data[c2_i165];
  }

  c2_i166 = c2_B->size[0] * c2_B->size[1];
  c2_B->size[0];
  c2_B->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_B, c2_i166, &c2_vb_emlrtRTEI);
  c2_f_B = c2_B->size[0];
  c2_g_B = c2_B->size[1];
  c2_h_B = c2_B->size[0];
  c2_i_B = c2_B->size[1];
  c2_j_B = c2_B->size[0];
  c2_k_B = c2_B->size[1];
  c2_o_loop_ub = c2_f_B * c2_g_B - 1;
  for (c2_i167 = 0; c2_i167 <= c2_o_loop_ub; c2_i167++) {
    c2_B->data[c2_i167] *= c2_B->data[c2_i167];
  }

  c2_emxInit_real32_T(chartInstance, &c2_l_A, 2, &c2_wb_emlrtRTEI);
  c2_i168 = c2_l_A->size[0] * c2_l_A->size[1];
  c2_l_A->size[0] = c2_A->size[0];
  c2_l_A->size[1] = c2_A->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_l_A, c2_i168, &c2_wb_emlrtRTEI);
  c2_m_A = c2_l_A->size[0];
  c2_n_A = c2_l_A->size[1];
  c2_p_loop_ub = c2_A->size[0] * c2_A->size[1] - 1;
  for (c2_i169 = 0; c2_i169 <= c2_p_loop_ub; c2_i169++) {
    c2_l_A->data[c2_i169] = c2_A->data[c2_i169];
  }

  c2_emxInit_real32_T(chartInstance, &c2_l_B, 2, &c2_xb_emlrtRTEI);
  c2_c_imfilter(chartInstance, c2_l_A, c2_A);
  c2_i170 = c2_l_B->size[0] * c2_l_B->size[1];
  c2_l_B->size[0] = c2_B->size[0];
  c2_l_B->size[1] = c2_B->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_l_B, c2_i170, &c2_xb_emlrtRTEI);
  c2_m_B = c2_l_B->size[0];
  c2_n_B = c2_l_B->size[1];
  c2_q_loop_ub = c2_B->size[0] * c2_B->size[1] - 1;
  c2_emxFree_real32_T(chartInstance, &c2_l_A);
  for (c2_i171 = 0; c2_i171 <= c2_q_loop_ub; c2_i171++) {
    c2_l_B->data[c2_i171] = c2_B->data[c2_i171];
  }

  c2_emxInit_real32_T(chartInstance, &c2_d_C, 2, &c2_yb_emlrtRTEI);
  c2_c_imfilter(chartInstance, c2_l_B, c2_B);
  c2_i172 = c2_d_C->size[0] * c2_d_C->size[1];
  c2_d_C->size[0] = c2_C->size[0];
  c2_d_C->size[1] = c2_C->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_d_C, c2_i172, &c2_yb_emlrtRTEI);
  c2_e_C = c2_d_C->size[0];
  c2_f_C = c2_d_C->size[1];
  c2_r_loop_ub = c2_C->size[0] * c2_C->size[1] - 1;
  c2_emxFree_real32_T(chartInstance, &c2_l_B);
  for (c2_i173 = 0; c2_i173 <= c2_r_loop_ub; c2_i173++) {
    c2_d_C->data[c2_i173] = c2_C->data[c2_i173];
  }

  c2_emxInit_real32_T(chartInstance, &c2_o_A, 2, &c2_ac_emlrtRTEI);
  c2_c_imfilter(chartInstance, c2_d_C, c2_C);
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)((real_T)c2_A->size[0] -
    1.0), 1, c2_A->size[0]);
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)((real_T)c2_A->size[1] -
    1.0), 1, c2_A->size[1]);
  c2_p_A = (real_T)c2_A->size[0];
  c2_i174 = (int32_T)(c2_p_A - 1.0);
  c2_q_A = (real_T)c2_A->size[1];
  c2_i175 = (int32_T)(c2_q_A - 1.0);
  c2_i176 = c2_o_A->size[0] * c2_o_A->size[1];
  c2_o_A->size[0] = c2_i174 - 1;
  c2_o_A->size[1] = c2_i175 - 1;
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_o_A, c2_i176, &c2_ac_emlrtRTEI);
  c2_s_loop_ub = c2_i175 - 2;
  c2_emxFree_real32_T(chartInstance, &c2_d_C);
  for (c2_i177 = 0; c2_i177 <= c2_s_loop_ub; c2_i177++) {
    c2_t_loop_ub = c2_i174 - 2;
    for (c2_i179 = 0; c2_i179 <= c2_t_loop_ub; c2_i179++) {
      c2_o_A->data[c2_i179 + c2_o_A->size[0] * c2_i177] = c2_A->data[(c2_i179 +
        c2_A->size[0] * (c2_i177 + 1)) + 1];
    }
  }

  c2_i178 = c2_A->size[0] * c2_A->size[1];
  c2_A->size[0] = c2_o_A->size[0];
  c2_A->size[1] = c2_o_A->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_A, c2_i178, &c2_bc_emlrtRTEI);
  c2_u_loop_ub = c2_o_A->size[1] - 1;
  for (c2_i180 = 0; c2_i180 <= c2_u_loop_ub; c2_i180++) {
    c2_v_loop_ub = c2_o_A->size[0] - 1;
    for (c2_i181 = 0; c2_i181 <= c2_v_loop_ub; c2_i181++) {
      c2_A->data[c2_i181 + c2_A->size[0] * c2_i180] = c2_o_A->data[c2_i181 +
        c2_o_A->size[0] * c2_i180];
    }
  }

  c2_emxFree_real32_T(chartInstance, &c2_o_A);
  c2_emxInit_real32_T(chartInstance, &c2_o_B, 2, &c2_cc_emlrtRTEI);
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)((real_T)c2_B->size[0] -
    1.0), 1, c2_B->size[0]);
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)((real_T)c2_B->size[1] -
    1.0), 1, c2_B->size[1]);
  c2_p_B = (real_T)c2_B->size[0];
  c2_i182 = (int32_T)(c2_p_B - 1.0);
  c2_q_B = (real_T)c2_B->size[1];
  c2_i183 = (int32_T)(c2_q_B - 1.0);
  c2_i184 = c2_o_B->size[0] * c2_o_B->size[1];
  c2_o_B->size[0] = c2_i182 - 1;
  c2_o_B->size[1] = c2_i183 - 1;
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_o_B, c2_i184, &c2_cc_emlrtRTEI);
  c2_w_loop_ub = c2_i183 - 2;
  for (c2_i185 = 0; c2_i185 <= c2_w_loop_ub; c2_i185++) {
    c2_x_loop_ub = c2_i182 - 2;
    for (c2_i187 = 0; c2_i187 <= c2_x_loop_ub; c2_i187++) {
      c2_o_B->data[c2_i187 + c2_o_B->size[0] * c2_i185] = c2_B->data[(c2_i187 +
        c2_B->size[0] * (c2_i185 + 1)) + 1];
    }
  }

  c2_i186 = c2_B->size[0] * c2_B->size[1];
  c2_B->size[0] = c2_o_B->size[0];
  c2_B->size[1] = c2_o_B->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_B, c2_i186, &c2_dc_emlrtRTEI);
  c2_y_loop_ub = c2_o_B->size[1] - 1;
  for (c2_i188 = 0; c2_i188 <= c2_y_loop_ub; c2_i188++) {
    c2_ab_loop_ub = c2_o_B->size[0] - 1;
    for (c2_i189 = 0; c2_i189 <= c2_ab_loop_ub; c2_i189++) {
      c2_B->data[c2_i189 + c2_B->size[0] * c2_i188] = c2_o_B->data[c2_i189 +
        c2_o_B->size[0] * c2_i188];
    }
  }

  c2_emxFree_real32_T(chartInstance, &c2_o_B);
  c2_emxInit_real32_T(chartInstance, &c2_g_C, 2, &c2_ec_emlrtRTEI);
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)((real_T)c2_C->size[0] -
    1.0), 1, c2_C->size[0]);
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)((real_T)c2_C->size[1] -
    1.0), 1, c2_C->size[1]);
  c2_h_C = (real_T)c2_C->size[0];
  c2_i190 = (int32_T)(c2_h_C - 1.0);
  c2_i_C = (real_T)c2_C->size[1];
  c2_i191 = (int32_T)(c2_i_C - 1.0);
  c2_i192 = c2_g_C->size[0] * c2_g_C->size[1];
  c2_g_C->size[0] = c2_i190 - 1;
  c2_g_C->size[1] = c2_i191 - 1;
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_g_C, c2_i192, &c2_ec_emlrtRTEI);
  c2_bb_loop_ub = c2_i191 - 2;
  for (c2_i193 = 0; c2_i193 <= c2_bb_loop_ub; c2_i193++) {
    c2_cb_loop_ub = c2_i190 - 2;
    for (c2_i195 = 0; c2_i195 <= c2_cb_loop_ub; c2_i195++) {
      c2_g_C->data[c2_i195 + c2_g_C->size[0] * c2_i193] = c2_C->data[(c2_i195 +
        c2_C->size[0] * (c2_i193 + 1)) + 1];
    }
  }

  c2_i194 = c2_C->size[0] * c2_C->size[1];
  c2_C->size[0] = c2_g_C->size[0];
  c2_C->size[1] = c2_g_C->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_C, c2_i194, &c2_fc_emlrtRTEI);
  c2_db_loop_ub = c2_g_C->size[1] - 1;
  for (c2_i196 = 0; c2_i196 <= c2_db_loop_ub; c2_i196++) {
    c2_eb_loop_ub = c2_g_C->size[0] - 1;
    for (c2_i198 = 0; c2_i198 <= c2_eb_loop_ub; c2_i198++) {
      c2_C->data[c2_i198 + c2_C->size[0] * c2_i196] = c2_g_C->data[c2_i198 +
        c2_g_C->size[0] * c2_i196];
    }
  }

  c2_emxFree_real32_T(chartInstance, &c2_g_C);
  for (c2_i197 = 0; c2_i197 < 2; c2_i197++) {
    c2_r_A[c2_i197] = c2_A->size[c2_i197];
  }

  for (c2_i199 = 0; c2_i199 < 2; c2_i199++) {
    c2_r_B[c2_i199] = c2_B->size[c2_i199];
  }

  _SFD_SIZE_EQ_CHECK_ND(c2_r_A, c2_r_B, 2);
  for (c2_i200 = 0; c2_i200 < 2; c2_i200++) {
    c2_s_A[c2_i200] = c2_A->size[c2_i200];
  }

  for (c2_i201 = 0; c2_i201 < 2; c2_i201++) {
    c2_s_B[c2_i201] = c2_B->size[c2_i201];
  }

  c2_emxInit_real32_T(chartInstance, &c2_t_A, 2, &c2_gc_emlrtRTEI);
  _SFD_SIZE_EQ_CHECK_ND(c2_s_A, c2_s_B, 2);
  c2_i202 = c2_t_A->size[0] * c2_t_A->size[1];
  c2_t_A->size[0] = c2_A->size[0];
  c2_t_A->size[1] = c2_A->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_t_A, c2_i202, &c2_gc_emlrtRTEI);
  c2_u_A = c2_t_A->size[0];
  c2_v_A = c2_t_A->size[1];
  c2_fb_loop_ub = c2_A->size[0] * c2_A->size[1] - 1;
  for (c2_i203 = 0; c2_i203 <= c2_fb_loop_ub; c2_i203++) {
    c2_t_A->data[c2_i203] = c2_A->data[c2_i203] - c2_B->data[c2_i203];
  }

  c2_emxInit_real32_T(chartInstance, &c2_b, 2, &c2_hc_emlrtRTEI);
  c2_emxInit_real32_T(chartInstance, &c2_j_C, 2, &c2_hc_emlrtRTEI);
  c2_power(chartInstance, c2_t_A, c2_metric);
  c2_i204 = c2_j_C->size[0] * c2_j_C->size[1];
  c2_j_C->size[0] = c2_C->size[0];
  c2_j_C->size[1] = c2_C->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_j_C, c2_i204, &c2_hc_emlrtRTEI);
  c2_k_C = c2_j_C->size[0];
  c2_l_C = c2_j_C->size[1];
  c2_gb_loop_ub = c2_C->size[0] * c2_C->size[1] - 1;
  c2_emxFree_real32_T(chartInstance, &c2_t_A);
  for (c2_i205 = 0; c2_i205 <= c2_gb_loop_ub; c2_i205++) {
    c2_j_C->data[c2_i205] = c2_C->data[c2_i205];
  }

  c2_emxFree_real32_T(chartInstance, &c2_C);
  c2_power(chartInstance, c2_j_C, c2_b);
  c2_i206 = c2_b->size[0] * c2_b->size[1];
  c2_b->size[0];
  c2_b->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_b, c2_i206, &c2_ic_emlrtRTEI);
  c2_b_b = c2_b->size[0];
  c2_c_b = c2_b->size[1];
  c2_d_b = c2_b->size[0];
  c2_e_b = c2_b->size[1];
  c2_hb_loop_ub = c2_b_b * c2_c_b - 1;
  c2_emxFree_real32_T(chartInstance, &c2_j_C);
  for (c2_i207 = 0; c2_i207 <= c2_hb_loop_ub; c2_i207++) {
    c2_b->data[c2_i207] *= 4.0F;
  }

  for (c2_i208 = 0; c2_i208 < 2; c2_i208++) {
    c2_b_metric[c2_i208] = c2_metric->size[c2_i208];
  }

  for (c2_i209 = 0; c2_i209 < 2; c2_i209++) {
    c2_f_b[c2_i209] = c2_b->size[c2_i209];
  }

  _SFD_SIZE_EQ_CHECK_ND(c2_b_metric, c2_f_b, 2);
  c2_i210 = c2_metric->size[0] * c2_metric->size[1];
  c2_metric->size[0];
  c2_metric->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_metric, c2_i210,
    &c2_jc_emlrtRTEI);
  c2_c_metric = c2_metric->size[0];
  c2_d_metric = c2_metric->size[1];
  c2_e_metric = c2_metric->size[0];
  c2_f_metric = c2_metric->size[1];
  c2_ib_loop_ub = c2_c_metric * c2_d_metric - 1;
  for (c2_i211 = 0; c2_i211 <= c2_ib_loop_ub; c2_i211++) {
    c2_metric->data[c2_i211] += c2_b->data[c2_i211];
  }

  c2_emxFree_real32_T(chartInstance, &c2_b);
  c2_b_sqrt(chartInstance, c2_metric);
  for (c2_i212 = 0; c2_i212 < 2; c2_i212++) {
    c2_w_A[c2_i212] = c2_A->size[c2_i212];
  }

  for (c2_i213 = 0; c2_i213 < 2; c2_i213++) {
    c2_g_metric[c2_i213] = c2_metric->size[c2_i213];
  }

  _SFD_SIZE_EQ_CHECK_ND(c2_w_A, c2_g_metric, 2);
  c2_i214 = c2_metric->size[0] * c2_metric->size[1];
  c2_metric->size[0] = c2_A->size[0];
  c2_metric->size[1] = c2_A->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_metric, c2_i214,
    &c2_kc_emlrtRTEI);
  c2_h_metric = c2_metric->size[0];
  c2_i_metric = c2_metric->size[1];
  c2_j_metric = c2_metric->size[0];
  c2_k_metric = c2_metric->size[1];
  c2_jb_loop_ub = c2_A->size[0] * c2_A->size[1] - 1;
  for (c2_i215 = 0; c2_i215 <= c2_jb_loop_ub; c2_i215++) {
    c2_metric->data[c2_i215] = ((c2_A->data[c2_i215] + c2_B->data[c2_i215]) -
      c2_metric->data[c2_i215]) / 2.0F;
  }

  c2_emxFree_real32_T(chartInstance, &c2_B);
  c2_emxFree_real32_T(chartInstance, &c2_A);
}

static void c2_imfilter(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_real32_T *c2_varargin_1, c2_emxArray_real32_T *c2_b)
{
  int32_T c2_i216;
  int32_T c2_b_b;
  int32_T c2_c_b;
  int32_T c2_loop_ub;
  int32_T c2_i217;
  c2_i216 = c2_b->size[0] * c2_b->size[1];
  c2_b->size[0] = c2_varargin_1->size[0];
  c2_b->size[1] = c2_varargin_1->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_b, c2_i216, &c2_lc_emlrtRTEI);
  c2_b_b = c2_b->size[0];
  c2_c_b = c2_b->size[1];
  c2_loop_ub = c2_varargin_1->size[0] * c2_varargin_1->size[1] - 1;
  for (c2_i217 = 0; c2_i217 <= c2_loop_ub; c2_i217++) {
    c2_b->data[c2_i217] = c2_varargin_1->data[c2_i217];
  }

  c2_d_imfilter(chartInstance, c2_b);
}

static void c2_padImage(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_real32_T *c2_a_tmp, real_T c2_pad[2], c2_emxArray_real32_T *c2_a)
{
  int32_T c2_i218;
  real_T c2_b_pad[2];
  int32_T c2_i219;
  int32_T c2_i220;
  int32_T c2_i221;
  real_T c2_sizeB[2];
  real_T c2_b_sizeB[2];
  real_T c2_dv0[2];
  real_T c2_sizeA[2];
  real_T c2_c_sizeB[2];
  int32_T c2_i222;
  real_T c2_mtmp;
  real_T c2_varargin_1[2];
  int32_T c2_iv2[2];
  int32_T c2_idxA_size[2];
  int32_T c2_onesVector_size[2];
  int32_T c2_onesVector;
  int32_T c2_b_onesVector;
  int32_T c2_loop_ub;
  int32_T c2_i223;
  real_T c2_d12;
  int32_T c2_y_size[2];
  int32_T c2_b_loop_ub;
  int32_T c2_y;
  uint32_T c2_u3;
  int32_T c2_i224;
  int32_T c2_b_y;
  real_T c2_d_sizeB;
  uint32_T c2_onesVector_data[4];
  real_T c2_y_data[1024];
  int32_T c2_idxDir_size[2];
  int32_T c2_c_loop_ub;
  int32_T c2_i225;
  int32_T c2_d_loop_ub;
  uint32_T c2_idxDir_data[1032];
  int32_T c2_i226;
  int32_T c2_e_loop_ub;
  real_T c2_d13;
  int32_T c2_i227;
  uint32_T c2_u4;
  real_T c2_d14;
  int32_T c2_i228;
  int32_T c2_tmp_size[1];
  uint32_T c2_u5;
  int32_T c2_f_loop_ub;
  int32_T c2_i229;
  int32_T c2_iv3[1];
  int32_T c2_tmp_data[1032];
  int32_T c2_b_idxDir_size[2];
  int32_T c2_g_loop_ub;
  int32_T c2_i230;
  int32_T c2_iv4[1];
  int32_T c2_b_idxDir_data[1032];
  int32_T c2_h_loop_ub;
  int32_T c2_i231;
  int32_T c2_idxA_data[2064];
  int32_T c2_c_onesVector;
  int32_T c2_d_onesVector;
  int32_T c2_i_loop_ub;
  int32_T c2_i232;
  real_T c2_d15;
  int32_T c2_j_loop_ub;
  int32_T c2_c_y;
  uint32_T c2_u6;
  int32_T c2_i233;
  int32_T c2_d_y;
  real_T c2_e_sizeB;
  int32_T c2_k_loop_ub;
  int32_T c2_i234;
  int32_T c2_l_loop_ub;
  int32_T c2_i235;
  int32_T c2_m_loop_ub;
  real_T c2_d16;
  int32_T c2_i236;
  uint32_T c2_u7;
  real_T c2_d17;
  int32_T c2_i237;
  uint32_T c2_u8;
  int32_T c2_n_loop_ub;
  int32_T c2_i238;
  int32_T c2_iv5[1];
  int32_T c2_c_idxDir_size[2];
  int32_T c2_o_loop_ub;
  int32_T c2_i239;
  int32_T c2_iv6[1];
  int32_T c2_c_idxDir_data[1032];
  int32_T c2_p_loop_ub;
  int32_T c2_i240;
  int32_T c2_i241;
  int32_T c2_i242;
  real_T c2_d18;
  int32_T c2_j;
  real_T c2_d19;
  int32_T c2_i;
  for (c2_i218 = 0; c2_i218 < 2; c2_i218++) {
    c2_b_pad[c2_i218] = c2_pad[c2_i218];
  }

  c2_validateattributes(chartInstance, c2_b_pad);
  if ((c2_a_tmp->size[0] == 0) || (c2_a_tmp->size[1] == 0)) {
    for (c2_i220 = 0; c2_i220 < 2; c2_i220++) {
      c2_sizeB[c2_i220] = (real_T)c2_a_tmp->size[c2_i220] + 2.0 * c2_pad[c2_i220];
    }

    c2_b_sizeB[0] = c2_sizeB[0];
    c2_b_sizeB[1] = c2_sizeB[1];
    c2_repmat(chartInstance, c2_b_sizeB, c2_a);
  } else {
    for (c2_i219 = 0; c2_i219 < 2; c2_i219++) {
      c2_sizeB[c2_i219] = (real_T)c2_a_tmp->size[c2_i219];
    }

    for (c2_i221 = 0; c2_i221 < 2; c2_i221++) {
      c2_sizeA[c2_i221] = (real_T)c2_a_tmp->size[c2_i221];
    }

    c2_dv0[0] = 2.0 * c2_pad[0];
    c2_dv0[1] = 2.0 * c2_pad[1];
    c2_c_sizeB[0] = c2_sizeB[0];
    c2_c_sizeB[1] = c2_sizeB[1];
    for (c2_i222 = 0; c2_i222 < 2; c2_i222++) {
      c2_varargin_1[c2_i222] = c2_dv0[c2_i222] + c2_c_sizeB[c2_i222];
    }

    c2_mtmp = c2_varargin_1[0];
    if (c2_varargin_1[1] > c2_varargin_1[0]) {
      c2_mtmp = c2_varargin_1[1];
    }

    c2_iv2[0] = (int32_T)c2_mtmp;
    c2_iv2[1] = 2;
    c2_idxA_size[0] = (int32_T)c2_mtmp;
    c2_idxA_size[1] = 2;
    c2_onesVector_size[0] = 1;
    c2_onesVector_size[1] = (int32_T)c2_pad[0];
    c2_onesVector = c2_onesVector_size[0];
    c2_b_onesVector = c2_onesVector_size[1];
    c2_loop_ub = (int32_T)c2_pad[0] - 1;
    for (c2_i223 = 0; c2_i223 <= c2_loop_ub; c2_i223++) {
      c2_d12 = muDoubleScalarRound(1.0);
      if (c2_d12 < 4.294967296E+9) {
        if (c2_d12 >= 0.0) {
          c2_u3 = (uint32_T)c2_d12;
        } else {
          c2_u3 = 0U;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
        }
      } else if (c2_d12 >= 4.294967296E+9) {
        c2_u3 = MAX_uint32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      } else {
        c2_u3 = 0U;
      }

      c2_onesVector_data[c2_i223] = c2_u3;
    }

    if (c2_sizeA[0] < 1.0) {
      c2_y_size[0] = 1;
      c2_y_size[1] = 0;
      c2_y = c2_y_size[0];
      c2_b_y = c2_y_size[1];
    } else {
      c2_y_size[0] = 1;
      c2_y_size[1] = (int32_T)muDoubleScalarFloor(c2_sizeA[0] - 1.0) + 1;
      c2_b_loop_ub = (int32_T)muDoubleScalarFloor(c2_sizeA[0] - 1.0);
      for (c2_i224 = 0; c2_i224 <= c2_b_loop_ub; c2_i224++) {
        c2_y_data[c2_y_size[0] * c2_i224] = 1.0 + (real_T)c2_i224;
      }
    }

    c2_d_sizeB = c2_sizeB[0];
    c2_idxDir_size[0] = 1;
    c2_idxDir_size[1] = (c2_onesVector_size[1] + c2_y_size[1]) +
      c2_onesVector_size[1];
    c2_c_loop_ub = c2_onesVector_size[1] - 1;
    for (c2_i225 = 0; c2_i225 <= c2_c_loop_ub; c2_i225++) {
      c2_idxDir_data[c2_idxDir_size[0] * c2_i225] =
        c2_onesVector_data[c2_onesVector_size[0] * c2_i225];
    }

    c2_d_loop_ub = c2_y_size[1] - 1;
    for (c2_i226 = 0; c2_i226 <= c2_d_loop_ub; c2_i226++) {
      c2_d13 = muDoubleScalarRound(c2_y_data[c2_y_size[0] * c2_i226]);
      if (c2_d13 < 4.294967296E+9) {
        if (c2_d13 >= 0.0) {
          c2_u4 = (uint32_T)c2_d13;
        } else {
          c2_u4 = 0U;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
        }
      } else if (c2_d13 >= 4.294967296E+9) {
        c2_u4 = MAX_uint32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      } else {
        c2_u4 = 0U;
      }

      c2_idxDir_data[c2_idxDir_size[0] * (c2_i226 + c2_onesVector_size[1])] =
        c2_u4;
    }

    c2_e_loop_ub = c2_onesVector_size[1] - 1;
    for (c2_i227 = 0; c2_i227 <= c2_e_loop_ub; c2_i227++) {
      c2_d14 = muDoubleScalarRound(c2_d_sizeB * (real_T)
        c2_onesVector_data[c2_onesVector_size[0] * c2_i227]);
      if (c2_d14 < 4.294967296E+9) {
        if (c2_d14 >= 0.0) {
          c2_u5 = (uint32_T)c2_d14;
        } else {
          c2_u5 = 0U;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
        }
      } else if (c2_d14 >= 4.294967296E+9) {
        c2_u5 = MAX_uint32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      } else {
        c2_u5 = 0U;
      }

      c2_idxDir_data[c2_idxDir_size[0] * ((c2_i227 + c2_onesVector_size[1]) +
        c2_y_size[1])] = c2_u5;
    }

    if (1.0 > (real_T)c2_idxDir_size[1]) {
      c2_i228 = 0;
    } else {
      (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c2_iv2[0]);
      c2_i228 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_idxDir_size[1], 1, c2_iv2[0]);
    }

    c2_tmp_size[0] = c2_i228;
    c2_f_loop_ub = c2_i228 - 1;
    for (c2_i229 = 0; c2_i229 <= c2_f_loop_ub; c2_i229++) {
      c2_tmp_data[c2_i229] = c2_i229;
    }

    c2_iv3[0] = c2_tmp_size[0];
    _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c2_iv3, 1, c2_idxDir_size, 2);
    c2_b_idxDir_size[0] = 1;
    c2_b_idxDir_size[1] = c2_idxDir_size[1];
    c2_g_loop_ub = c2_idxDir_size[1] - 1;
    for (c2_i230 = 0; c2_i230 <= c2_g_loop_ub; c2_i230++) {
      c2_b_idxDir_data[c2_b_idxDir_size[0] * c2_i230] = (int32_T)
        c2_idxDir_data[c2_idxDir_size[0] * c2_i230];
    }

    c2_iv4[0] = c2_tmp_size[0];
    c2_h_loop_ub = c2_iv4[0] - 1;
    for (c2_i231 = 0; c2_i231 <= c2_h_loop_ub; c2_i231++) {
      c2_idxA_data[c2_tmp_data[c2_i231]] = c2_b_idxDir_data[c2_i231];
    }

    c2_onesVector_size[0] = 1;
    c2_onesVector_size[1] = (int32_T)c2_pad[1];
    c2_c_onesVector = c2_onesVector_size[0];
    c2_d_onesVector = c2_onesVector_size[1];
    c2_i_loop_ub = (int32_T)c2_pad[1] - 1;
    for (c2_i232 = 0; c2_i232 <= c2_i_loop_ub; c2_i232++) {
      c2_d15 = muDoubleScalarRound(1.0);
      if (c2_d15 < 4.294967296E+9) {
        if (c2_d15 >= 0.0) {
          c2_u6 = (uint32_T)c2_d15;
        } else {
          c2_u6 = 0U;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
        }
      } else if (c2_d15 >= 4.294967296E+9) {
        c2_u6 = MAX_uint32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      } else {
        c2_u6 = 0U;
      }

      c2_onesVector_data[c2_i232] = c2_u6;
    }

    if (c2_sizeA[1] < 1.0) {
      c2_y_size[0] = 1;
      c2_y_size[1] = 0;
      c2_c_y = c2_y_size[0];
      c2_d_y = c2_y_size[1];
    } else {
      c2_y_size[0] = 1;
      c2_y_size[1] = (int32_T)muDoubleScalarFloor(c2_sizeA[1] - 1.0) + 1;
      c2_j_loop_ub = (int32_T)muDoubleScalarFloor(c2_sizeA[1] - 1.0);
      for (c2_i233 = 0; c2_i233 <= c2_j_loop_ub; c2_i233++) {
        c2_y_data[c2_y_size[0] * c2_i233] = 1.0 + (real_T)c2_i233;
      }
    }

    c2_e_sizeB = c2_sizeB[1];
    c2_idxDir_size[0] = 1;
    c2_idxDir_size[1] = (c2_onesVector_size[1] + c2_y_size[1]) +
      c2_onesVector_size[1];
    c2_k_loop_ub = c2_onesVector_size[1] - 1;
    for (c2_i234 = 0; c2_i234 <= c2_k_loop_ub; c2_i234++) {
      c2_idxDir_data[c2_idxDir_size[0] * c2_i234] =
        c2_onesVector_data[c2_onesVector_size[0] * c2_i234];
    }

    c2_l_loop_ub = c2_y_size[1] - 1;
    for (c2_i235 = 0; c2_i235 <= c2_l_loop_ub; c2_i235++) {
      c2_d16 = muDoubleScalarRound(c2_y_data[c2_y_size[0] * c2_i235]);
      if (c2_d16 < 4.294967296E+9) {
        if (c2_d16 >= 0.0) {
          c2_u7 = (uint32_T)c2_d16;
        } else {
          c2_u7 = 0U;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
        }
      } else if (c2_d16 >= 4.294967296E+9) {
        c2_u7 = MAX_uint32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      } else {
        c2_u7 = 0U;
      }

      c2_idxDir_data[c2_idxDir_size[0] * (c2_i235 + c2_onesVector_size[1])] =
        c2_u7;
    }

    c2_m_loop_ub = c2_onesVector_size[1] - 1;
    for (c2_i236 = 0; c2_i236 <= c2_m_loop_ub; c2_i236++) {
      c2_d17 = muDoubleScalarRound(c2_e_sizeB * (real_T)
        c2_onesVector_data[c2_onesVector_size[0] * c2_i236]);
      if (c2_d17 < 4.294967296E+9) {
        if (c2_d17 >= 0.0) {
          c2_u8 = (uint32_T)c2_d17;
        } else {
          c2_u8 = 0U;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
        }
      } else if (c2_d17 >= 4.294967296E+9) {
        c2_u8 = MAX_uint32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      } else {
        c2_u8 = 0U;
      }

      c2_idxDir_data[c2_idxDir_size[0] * ((c2_i236 + c2_onesVector_size[1]) +
        c2_y_size[1])] = c2_u8;
    }

    if (1.0 > (real_T)c2_idxDir_size[1]) {
      c2_i237 = 0;
    } else {
      (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c2_idxA_size[0]);
      c2_i237 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_idxDir_size[1], 1,
        c2_idxA_size[0]);
    }

    c2_tmp_size[0] = c2_i237;
    c2_n_loop_ub = c2_i237 - 1;
    for (c2_i238 = 0; c2_i238 <= c2_n_loop_ub; c2_i238++) {
      c2_tmp_data[c2_i238] = c2_i238;
    }

    c2_iv5[0] = c2_tmp_size[0];
    _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c2_iv5, 1, c2_idxDir_size, 2);
    c2_c_idxDir_size[0] = 1;
    c2_c_idxDir_size[1] = c2_idxDir_size[1];
    c2_o_loop_ub = c2_idxDir_size[1] - 1;
    for (c2_i239 = 0; c2_i239 <= c2_o_loop_ub; c2_i239++) {
      c2_c_idxDir_data[c2_c_idxDir_size[0] * c2_i239] = (int32_T)
        c2_idxDir_data[c2_idxDir_size[0] * c2_i239];
    }

    c2_iv6[0] = c2_tmp_size[0];
    c2_p_loop_ub = c2_iv6[0] - 1;
    for (c2_i240 = 0; c2_i240 <= c2_p_loop_ub; c2_i240++) {
      c2_idxA_data[c2_tmp_data[c2_i240] + c2_idxA_size[0]] =
        c2_c_idxDir_data[c2_i240];
    }

    for (c2_i241 = 0; c2_i241 < 2; c2_i241++) {
      c2_sizeB[c2_i241] = (real_T)c2_a_tmp->size[c2_i241] + 2.0 * c2_pad[c2_i241];
    }

    c2_i242 = c2_a->size[0] * c2_a->size[1];
    c2_a->size[0] = (int32_T)c2_sizeB[0];
    c2_a->size[1] = (int32_T)c2_sizeB[1];
    c2_emxEnsureCapacity_real32_T(chartInstance, c2_a, c2_i242, &c2_sc_emlrtRTEI);
    c2_d18 = (real_T)c2_a->size[1];
    for (c2_j = 0; c2_j < (int32_T)c2_d18; c2_j++) {
      c2_d19 = (real_T)c2_a->size[0];
      for (c2_i = 0; c2_i < (int32_T)c2_d19; c2_i++) {
        c2_a->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_i + 1, 1, c2_a->size[0])
                    + c2_a->size[0] * (sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c2_j + 1, 1, c2_a->size[1]) - 1)) - 1] = c2_a_tmp->data
          [(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
             chartInstance->S, 1U, 0, 0, MAX_uint32_T,
             c2_idxA_data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_i + 1, 1,
              c2_idxA_size[0]) - 1], 1, c2_a_tmp->size[0]) + c2_a_tmp->size[0] *
            (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_idxA_data
              [(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_j + 1, 1,
                c2_idxA_size[0]) + c2_idxA_size[0]) - 1], 1, c2_a_tmp->size[1])
             - 1)) - 1];
      }
    }
  }
}

static void c2_validateattributes(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, real_T c2_a[2])
{
  boolean_T c2_p;
  int32_T c2_k;
  boolean_T c2_b_p;
  boolean_T c2_b7;
  const mxArray *c2_y = NULL;
  static char_T c2_cv15[31] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'a', 'd',
    'a', 'r', 'r', 'a', 'y', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'I',
    'n', 't', 'e', 'g', 'e', 'r' };

  const mxArray *c2_b_y = NULL;
  static char_T c2_cv16[55] = { 'E', 'x', 'p', 'e', 'c', 't', 'e', 'd', ' ', 'i',
    'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', '2', ',', ' ',
    'P', 'A', 'D', 'S', 'I', 'Z', 'E', ',', ' ', 't', 'o', ' ', 'b', 'e', ' ',
    'i', 'n', 't', 'e', 'g', 'e', 'r', '-', 'v', 'a', 'l', 'u', 'e', 'd', '.' };

  boolean_T exitg1;
  (void)chartInstance;
  c2_p = true;
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k < 2)) {
    c2_b_p = (muDoubleScalarFloor(c2_a[c2_k]) == c2_a[c2_k]);
    if (c2_b_p) {
      c2_k++;
    } else {
      c2_p = false;
      exitg1 = true;
    }
  }

  c2_b7 = c2_p;
  if (c2_b7) {
  } else {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv15, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv16, 10, 0U, 1U, 0U, 2, 1, 55),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_y, 14,
                      c2_b_y);
  }
}

static void c2_repmat(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
                      real_T c2_varargin_1[2], c2_emxArray_real32_T *c2_b)
{
  int32_T c2_i243;
  real_T c2_b_varargin_1[2];
  int32_T c2_c_varargin_1[2];
  int32_T c2_outsize[2];
  int32_T c2_d_varargin_1[2];
  int32_T c2_e_varargin_1[2];
  int32_T c2_f_varargin_1[2];
  int32_T c2_i244;
  int32_T c2_b_b;
  int32_T c2_c_b;
  int32_T c2_loop_ub;
  int32_T c2_i245;
  for (c2_i243 = 0; c2_i243 < 2; c2_i243++) {
    c2_b_varargin_1[c2_i243] = c2_varargin_1[c2_i243];
  }

  c2_assertValidSizeArg(chartInstance, c2_b_varargin_1);
  c2_c_varargin_1[0] = (int32_T)c2_varargin_1[0];
  c2_c_varargin_1[1] = (int32_T)c2_varargin_1[1];
  c2_outsize[0] = c2_c_varargin_1[0];
  c2_d_varargin_1[0] = (int32_T)c2_varargin_1[0];
  c2_d_varargin_1[1] = (int32_T)c2_varargin_1[1];
  if ((real_T)c2_outsize[0] == (real_T)c2_d_varargin_1[0]) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      c2_d_emlrt_marshallOut(chartInstance, c2_cv1));
  }

  c2_e_varargin_1[0] = (int32_T)c2_varargin_1[0];
  c2_e_varargin_1[1] = (int32_T)c2_varargin_1[1];
  c2_outsize[1] = c2_e_varargin_1[1];
  c2_f_varargin_1[0] = (int32_T)c2_varargin_1[0];
  c2_f_varargin_1[1] = (int32_T)c2_varargin_1[1];
  if ((real_T)c2_outsize[1] == (real_T)c2_f_varargin_1[1]) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      c2_d_emlrt_marshallOut(chartInstance, c2_cv1));
  }

  c2_i244 = c2_b->size[0] * c2_b->size[1];
  c2_b->size[0] = c2_outsize[0];
  c2_b->size[1] = c2_outsize[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_b, c2_i244, &c2_tc_emlrtRTEI);
  c2_b_b = c2_b->size[0];
  c2_c_b = c2_b->size[1];
  c2_loop_ub = c2_outsize[0] * c2_outsize[1] - 1;
  for (c2_i245 = 0; c2_i245 <= c2_loop_ub; c2_i245++) {
    c2_b->data[c2_i245] = 0.0F;
  }
}

static void c2_assertValidSizeArg(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, real_T c2_varargin_1[2])
{
  int32_T c2_k;
  boolean_T c2_p;
  boolean_T c2_b8;
  const mxArray *c2_y = NULL;
  static char_T c2_cv17[57] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 's', 's', 'e', 'r', 't', '_',
    'v', 'a', 'l', 'i', 'd', '_', 's', 'i', 'z', 'e', '_', 'a', 'r', 'g', '_',
    'i', 'n', 'v', 'a', 'l', 'i', 'd', 'S', 'i', 'z', 'e', 'V', 'e', 'c', 't',
    'o', 'r' };

  real_T c2_n;
  int32_T c2_b_u;
  int32_T c2_b_k;
  const mxArray *c2_b_y = NULL;
  int32_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  int32_T exitg1;
  (void)chartInstance;
  c2_k = 0;
  do {
    exitg1 = 0;
    if (c2_k < 2) {
      if (c2_varargin_1[c2_k] != c2_varargin_1[c2_k]) {
        c2_p = false;
        exitg1 = 1;
      } else {
        c2_k++;
      }
    } else {
      c2_p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  c2_b8 = c2_p;
  if (c2_b8) {
  } else {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv17, 10, 0U, 1U, 0U, 2, 1, 57),
                  false);
    c2_b_u = MIN_int32_T;
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 6, 0U, 0U, 0U, 0), false);
    c2_c_u = MAX_int32_T;
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 6, 0U, 0U, 0U, 0), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 3U, 14, c2_y, 14, c2_b_y, 14, c2_c_y));
  }

  c2_n = 1.0;
  for (c2_b_k = 0; c2_b_k < 2; c2_b_k++) {
    if (c2_varargin_1[c2_b_k] <= 0.0) {
      c2_n = 0.0;
    } else {
      c2_n *= c2_varargin_1[c2_b_k];
    }
  }

  if (2.147483647E+9 >= c2_n) {
  } else {
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_d_y));
  }
}

static void c2_b_imfilter(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_real32_T *c2_varargin_1, c2_emxArray_real32_T *c2_b)
{
  int32_T c2_i246;
  int32_T c2_b_b;
  int32_T c2_c_b;
  int32_T c2_loop_ub;
  int32_T c2_i247;
  c2_i246 = c2_b->size[0] * c2_b->size[1];
  c2_b->size[0] = c2_varargin_1->size[0];
  c2_b->size[1] = c2_varargin_1->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_b, c2_i246, &c2_lc_emlrtRTEI);
  c2_b_b = c2_b->size[0];
  c2_c_b = c2_b->size[1];
  c2_loop_ub = c2_varargin_1->size[0] * c2_varargin_1->size[1] - 1;
  for (c2_i247 = 0; c2_i247 <= c2_loop_ub; c2_i247++) {
    c2_b->data[c2_i247] = c2_varargin_1->data[c2_i247];
  }

  c2_e_imfilter(chartInstance, c2_b);
}

static void c2_c_imfilter(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_real32_T *c2_varargin_1, c2_emxArray_real32_T *c2_b)
{
  real_T c2_finalSize[2];
  real_T c2_pad[2];
  c2_emxArray_real32_T *c2_b_varargin_1;
  boolean_T c2_y;
  int32_T c2_i248;
  int32_T c2_k;
  int32_T c2_c_varargin_1;
  int32_T c2_d_varargin_1;
  boolean_T c2_b_y;
  int32_T c2_i249;
  int32_T c2_loop_ub;
  int32_T c2_b_k;
  int32_T c2_i250;
  int32_T c2_b_b;
  int32_T c2_i251;
  int32_T c2_c_b;
  const mxArray *c2_c_y = NULL;
  int32_T c2_b_loop_ub;
  static char_T c2_cv18[41] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm', 'f',
    'i', 'l', 't', 'e', 'r', ':', 'n', 'e', 'g', 'a', 't', 'i', 'v', 'e', 'D',
    'i', 'm', 'e', 'n', 's', 'i', 'o', 'n', 'B', 'a', 'd', 'S', 'i', 'z', 'e',
    'B' };

  int32_T c2_i252;
  int32_T c2_i253;
  c2_emxArray_real32_T *c2_a;
  real_T c2_b_pad[2];
  boolean_T c2_tooBig;
  int32_T c2_d_b;
  int32_T c2_i;
  int32_T c2_e_b;
  int32_T c2_c_loop_ub;
  int32_T c2_i254;
  boolean_T c2_modeFlag;
  int32_T c2_i255;
  int32_T c2_i256;
  int32_T c2_i257;
  int32_T c2_i258;
  real_T c2_padSize[2];
  int32_T c2_i259;
  int32_T c2_i260;
  boolean_T c2_conn[25];
  static real_T c2_kernel[25] = { 0.017842203926833885, 0.03061734437494857,
    0.036655616298368318, 0.03061734437494857, 0.017842203926833885,
    0.03061734437494857, 0.052539573049288711, 0.062901289105615155,
    0.052539573049288711, 0.03061734437494857, 0.036655616298368318,
    0.062901289105615155, 0.075306515479987221, 0.062901289105615155,
    0.036655616298368318, 0.03061734437494857, 0.052539573049288711,
    0.062901289105615155, 0.052539573049288711, 0.03061734437494857,
    0.017842203926833885, 0.03061734437494857, 0.036655616298368318,
    0.03061734437494857, 0.017842203926833885 };

  static real_T c2_nonZeroKernel[25] = { 0.017842203926833885,
    0.03061734437494857, 0.036655616298368318, 0.03061734437494857,
    0.017842203926833885, 0.03061734437494857, 0.052539573049288711,
    0.062901289105615155, 0.052539573049288711, 0.03061734437494857,
    0.036655616298368318, 0.062901289105615155, 0.075306515479987221,
    0.062901289105615155, 0.036655616298368318, 0.03061734437494857,
    0.052539573049288711, 0.062901289105615155, 0.052539573049288711,
    0.03061734437494857, 0.017842203926833885, 0.03061734437494857,
    0.036655616298368318, 0.03061734437494857, 0.017842203926833885 };

  real_T c2_connDims[2];
  boolean_T exitg1;
  c2_finalSize[0] = ((real_T)c2_varargin_1->size[0] + 5.0) - 1.0;
  c2_pad[0] = 4.0;
  c2_finalSize[1] = ((real_T)c2_varargin_1->size[1] + 5.0) - 1.0;
  c2_pad[1] = 4.0;
  if ((c2_varargin_1->size[0] == 0) || (c2_varargin_1->size[1] == 0)) {
    c2_y = true;
    c2_k = 0;
    exitg1 = false;
    while ((!exitg1) && (c2_k < 2)) {
      if (!(c2_finalSize[c2_k] >= 0.0)) {
        c2_y = false;
        exitg1 = true;
      } else {
        c2_k++;
      }
    }

    if (c2_y) {
      c2_i249 = c2_b->size[0] * c2_b->size[1];
      c2_b->size[0] = (int32_T)c2_finalSize[0];
      c2_b->size[1] = (int32_T)c2_finalSize[1];
      c2_emxEnsureCapacity_real32_T(chartInstance, c2_b, c2_i249,
        &c2_vc_emlrtRTEI);
      c2_b_b = c2_b->size[0];
      c2_c_b = c2_b->size[1];
      c2_b_loop_ub = (int32_T)c2_finalSize[0] * (int32_T)c2_finalSize[1] - 1;
      for (c2_i253 = 0; c2_i253 <= c2_b_loop_ub; c2_i253++) {
        c2_b->data[c2_i253] = 0.0F;
      }
    } else {
      c2_b_y = true;
      c2_b_k = 0;
      exitg1 = false;
      while ((!exitg1) && (c2_b_k < 2)) {
        if (!(c2_finalSize[c2_b_k] < 0.0)) {
          c2_b_y = false;
          exitg1 = true;
        } else {
          c2_b_k++;
        }
      }

      if (c2_b_y) {
      } else {
        c2_c_y = NULL;
        sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv18, 10, 0U, 1U, 0U, 2, 1,
          41), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "message", 1U, 1U, 14, c2_c_y));
      }

      c2_i252 = c2_b->size[0] * c2_b->size[1];
      c2_b->size[0] = (int32_T)c2_finalSize[0];
      c2_b->size[1] = (int32_T)c2_finalSize[1];
      c2_emxEnsureCapacity_real32_T(chartInstance, c2_b, c2_i252,
        &c2_vc_emlrtRTEI);
      c2_d_b = c2_b->size[0];
      c2_e_b = c2_b->size[1];
      c2_c_loop_ub = (int32_T)c2_finalSize[0] * (int32_T)c2_finalSize[1] - 1;
      for (c2_i254 = 0; c2_i254 <= c2_c_loop_ub; c2_i254++) {
        c2_b->data[c2_i254] = 0.0F;
      }
    }
  } else {
    c2_emxInit_real32_T(chartInstance, &c2_b_varargin_1, 2, &c2_uc_emlrtRTEI);
    c2_i248 = c2_b_varargin_1->size[0] * c2_b_varargin_1->size[1];
    c2_b_varargin_1->size[0] = c2_varargin_1->size[0];
    c2_b_varargin_1->size[1] = c2_varargin_1->size[1];
    c2_emxEnsureCapacity_real32_T(chartInstance, c2_b_varargin_1, c2_i248,
      &c2_uc_emlrtRTEI);
    c2_c_varargin_1 = c2_b_varargin_1->size[0];
    c2_d_varargin_1 = c2_b_varargin_1->size[1];
    c2_loop_ub = c2_varargin_1->size[0] * c2_varargin_1->size[1] - 1;
    for (c2_i250 = 0; c2_i250 <= c2_loop_ub; c2_i250++) {
      c2_b_varargin_1->data[c2_i250] = c2_varargin_1->data[c2_i250];
    }

    for (c2_i251 = 0; c2_i251 < 2; c2_i251++) {
      c2_b_pad[c2_i251] = c2_pad[c2_i251];
    }

    c2_emxInit_real32_T(chartInstance, &c2_a, 2, &c2_xc_emlrtRTEI);
    c2_padImage(chartInstance, c2_b_varargin_1, c2_b_pad, c2_a);
    c2_tooBig = true;
    c2_emxFree_real32_T(chartInstance, &c2_b_varargin_1);
    for (c2_i = 0; c2_i < 2; c2_i++) {
      c2_tooBig = false;
    }

    c2_modeFlag = !c2_tooBig;
    c2_i255 = c2_b->size[0] * c2_b->size[1];
    c2_b->size[0] = (int32_T)c2_finalSize[0];
    c2_b->size[1] = (int32_T)c2_finalSize[1];
    c2_emxEnsureCapacity_real32_T(chartInstance, c2_b, c2_i255, &c2_wc_emlrtRTEI);
    if (c2_modeFlag) {
      for (c2_i257 = 0; c2_i257 < 2; c2_i257++) {
        c2_padSize[c2_i257] = (real_T)c2_a->size[c2_i257];
      }

      for (c2_i259 = 0; c2_i259 < 2; c2_i259++) {
        c2_pad[c2_i259] = 5.0;
      }

      ippfilter_real32(&c2_a->data[0], &c2_b->data[0], c2_finalSize, 2.0,
                       c2_padSize, c2_kernel, c2_pad, true);
    } else {
      for (c2_i256 = 0; c2_i256 < 2; c2_i256++) {
        c2_padSize[c2_i256] = (real_T)c2_a->size[c2_i256];
      }

      for (c2_i258 = 0; c2_i258 < 25; c2_i258++) {
        c2_conn[c2_i258] = true;
      }

      for (c2_i260 = 0; c2_i260 < 2; c2_i260++) {
        c2_connDims[c2_i260] = 5.0;
      }

      imfilter_real32(&c2_a->data[0], &c2_b->data[0], 2.0, c2_finalSize, 2.0,
                      c2_padSize, c2_nonZeroKernel, 25.0, c2_conn, 2.0,
                      c2_connDims, c2_pad, 2.0, false, true);
    }

    c2_emxFree_real32_T(chartInstance, &c2_a);
  }
}

static void c2_power(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
                     c2_emxArray_real32_T *c2_a, c2_emxArray_real32_T *c2_y)
{
  c2_emxArray_real32_T *c2_r7;
  int32_T c2_i261;
  int32_T c2_i262;
  real_T c2_varargin_1[2];
  c2_emxArray_real32_T *c2_ztemp;
  real_T c2_dv1[2];
  c2_emxArray_real32_T *c2_b_a;
  int32_T c2_i263;
  int32_T c2_i264;
  int32_T c2_i265;
  int32_T c2_c_a;
  int32_T c2_d_a;
  int32_T c2_loop_ub;
  int32_T c2_i266;
  static char_T c2_cv19[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'm',
    'a', 'g', 'r', 'e', 'e' };

  int32_T c2_i267;
  int32_T c2_nx;
  int32_T c2_k;
  c2_emxInit_real32_T(chartInstance, &c2_r7, 2, &c2_ad_emlrtRTEI);
  for (c2_i261 = 0; c2_i261 < 2; c2_i261++) {
    c2_varargin_1[c2_i261] = (real_T)c2_a->size[c2_i261];
  }

  for (c2_i262 = 0; c2_i262 < 2; c2_i262++) {
    c2_dv1[c2_i262] = (real_T)c2_a->size[c2_i262];
  }

  c2_emxInit_real32_T(chartInstance, &c2_ztemp, 2, &c2_dd_emlrtRTEI);
  c2_emxInit_real32_T(chartInstance, &c2_b_a, 2, &c2_bd_emlrtRTEI);
  c2_i263 = c2_ztemp->size[0] * c2_ztemp->size[1];
  c2_ztemp->size[0] = (int32_T)c2_varargin_1[0];
  c2_ztemp->size[1] = (int32_T)c2_varargin_1[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_ztemp, c2_i263,
    &c2_yc_emlrtRTEI);
  c2_i264 = c2_r7->size[0] * c2_r7->size[1];
  c2_r7->size[0] = (int32_T)c2_dv1[0];
  c2_r7->size[1] = (int32_T)c2_dv1[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_r7, c2_i264, &c2_ad_emlrtRTEI);
  c2_i265 = c2_b_a->size[0] * c2_b_a->size[1];
  c2_b_a->size[0] = c2_a->size[0];
  c2_b_a->size[1] = c2_a->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_b_a, c2_i265, &c2_bd_emlrtRTEI);
  c2_c_a = c2_b_a->size[0];
  c2_d_a = c2_b_a->size[1];
  c2_loop_ub = c2_a->size[0] * c2_a->size[1] - 1;
  for (c2_i266 = 0; c2_i266 <= c2_loop_ub; c2_i266++) {
    c2_b_a->data[c2_i266] = c2_a->data[c2_i266];
  }

  if (c2_dimagree(chartInstance, c2_r7, c2_b_a)) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_d_emlrt_marshallOut(chartInstance, c2_cv19)));
  }

  c2_emxFree_real32_T(chartInstance, &c2_b_a);
  c2_emxFree_real32_T(chartInstance, &c2_r7);
  c2_i267 = c2_y->size[0] * c2_y->size[1];
  c2_y->size[0] = (int32_T)c2_dv1[0];
  c2_y->size[1] = (int32_T)c2_dv1[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_y, c2_i267, &c2_cd_emlrtRTEI);
  c2_nx = c2_ztemp->size[0] * c2_ztemp->size[1];
  c2_k = 0;
  c2_emxFree_real32_T(chartInstance, &c2_ztemp);
  while (c2_k + 1 <= c2_nx) {
    c2_y->data[c2_k] = c2_a->data[c2_k] * c2_a->data[c2_k];
    c2_k++;
  }
}

static boolean_T c2_dimagree(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_z, c2_emxArray_real32_T
  *c2_varargin_1)
{
  boolean_T c2_p;
  boolean_T c2_b_p;
  int32_T c2_k;
  boolean_T exitg1;
  (void)chartInstance;
  c2_p = true;
  c2_b_p = true;
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k + 1 < 3)) {
    if (c2_z->size[c2_k] != c2_varargin_1->size[c2_k]) {
      c2_b_p = false;
      exitg1 = true;
    } else {
      c2_k++;
    }
  }

  if (c2_b_p) {
  } else {
    c2_p = false;
  }

  return c2_p;
}

static void c2_sqrt(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
                    c2_emxArray_real32_T *c2_x, c2_emxArray_real32_T *c2_b_x)
{
  int32_T c2_i268;
  int32_T c2_c_x;
  int32_T c2_d_x;
  int32_T c2_loop_ub;
  int32_T c2_i269;
  c2_i268 = c2_b_x->size[0] * c2_b_x->size[1];
  c2_b_x->size[0] = c2_x->size[0];
  c2_b_x->size[1] = c2_x->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_b_x, c2_i268, &c2_ed_emlrtRTEI);
  c2_c_x = c2_b_x->size[0];
  c2_d_x = c2_b_x->size[1];
  c2_loop_ub = c2_x->size[0] * c2_x->size[1] - 1;
  for (c2_i269 = 0; c2_i269 <= c2_loop_ub; c2_i269++) {
    c2_b_x->data[c2_i269] = c2_x->data[c2_i269];
  }

  c2_b_sqrt(chartInstance, c2_b_x);
}

static void c2_error(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  const mxArray *c2_y = NULL;
  static char_T c2_cv20[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  const mxArray *c2_b_y = NULL;
  static char_T c2_cv21[4] = { 's', 'q', 'r', 't' };

  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv20, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv21, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c2_y, 14, c2_b_y));
}

static void c2_findPeaks(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_real32_T *c2_metric, real32_T c2_quality, c2_emxArray_real32_T
  *c2_loc)
{
  int32_T c2_ixstart;
  int32_T c2_n;
  real32_T c2_mtmp;
  int32_T c2_ix;
  int32_T c2_b_ix;
  c2_emxArray_real32_T *c2_b_metric;
  int32_T c2_i270;
  int32_T c2_i271;
  int32_T c2_b_loc;
  int32_T c2_c_metric;
  int32_T c2_c_loc;
  int32_T c2_d_metric;
  int32_T c2_loop_ub;
  int32_T c2_i272;
  c2_emxArray_boolean_T *c2_bw;
  int32_T c2_end;
  int32_T c2_trueCount;
  int32_T c2_i;
  c2_emxArray_int32_T *c2_ii;
  int32_T c2_i273;
  int32_T c2_partialTrueCount;
  int32_T c2_b_i;
  int32_T c2_b_bw;
  int32_T c2_c_bw;
  int32_T c2_d_bw;
  int32_T c2_e_bw;
  int32_T c2_f_bw;
  int32_T c2_b_loop_ub;
  int32_T c2_i274;
  int32_T c2_i275;
  int32_T c2_iv7[2];
  int32_T c2_g_bw;
  int32_T c2_c_loop_ub;
  int32_T c2_i276;
  int32_T c2_i277;
  int32_T c2_iv8[2];
  real_T c2_h_bw;
  int32_T c2_i_bw;
  int32_T c2_j_bw;
  int32_T c2_k_bw;
  int32_T c2_d_loop_ub;
  int32_T c2_i278;
  int32_T c2_i279;
  int32_T c2_iv9[1];
  int32_T c2_l_bw;
  int32_T c2_e_loop_ub;
  int32_T c2_i280;
  int32_T c2_i281;
  int32_T c2_iv10[1];
  int32_T c2_m_bw;
  real_T c2_n_bw;
  int32_T c2_o_bw;
  int32_T c2_p_bw;
  int32_T c2_f_loop_ub;
  int32_T c2_i282;
  int32_T c2_nx;
  int32_T c2_idx;
  int32_T c2_i283;
  int32_T c2_b_ii;
  int32_T c2_i284;
  c2_emxArray_real_T *c2_b_idx;
  int32_T c2_i285;
  int32_T c2_i286;
  int32_T c2_g_loop_ub;
  int32_T c2_i287;
  real_T c2_dv2[2];
  int32_T c2_i288;
  int32_T c2_d_loc;
  int32_T c2_e_loc;
  int32_T c2_h_loop_ub;
  int32_T c2_i289;
  int32_T c2_i290;
  int32_T c2_i291;
  real_T c2_e_metric[2];
  int32_T c2_i292;
  real_T c2_siz[2];
  int32_T c2_i_loop_ub;
  int32_T c2_i293;
  c2_emxArray_int32_T *c2_c_ii;
  int32_T c2_i294;
  int32_T c2_j_loop_ub;
  int32_T c2_i295;
  static char_T c2_cv22[36] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'i', 'n', 'd', '2', 's', 'u', 'b', '_', 'I', 'n', 'd', 'e',
    'x', 'O', 'u', 't', 'O', 'f', 'R', 'a', 'n', 'g', 'e' };

  int32_T c2_i296;
  int32_T c2_k_loop_ub;
  int32_T c2_i297;
  c2_emxArray_int32_T *c2_vk;
  int32_T c2_b_siz;
  int32_T c2_i298;
  int32_T c2_l_loop_ub;
  int32_T c2_i299;
  int32_T c2_f_metric;
  int32_T c2_i300;
  int32_T c2_m_loop_ub;
  int32_T c2_i301;
  int32_T c2_i302;
  int32_T c2_n_loop_ub;
  int32_T c2_i303;
  c2_emxArray_real_T *c2_r8;
  int32_T c2_i304;
  int32_T c2_o_loop_ub;
  int32_T c2_i305;
  int32_T c2_iv11[2];
  int32_T c2_i306;
  int32_T c2_p_loop_ub;
  int32_T c2_i307;
  int32_T c2_d_ii[1];
  int32_T c2_q_loop_ub;
  int32_T c2_i308;
  int32_T c2_i309;
  int32_T c2_i310;
  int32_T c2_r_loop_ub;
  int32_T c2_i311;
  int32_T c2_e_ii[1];
  int32_T c2_s_loop_ub;
  int32_T c2_i312;
  boolean_T exitg1;
  c2_ixstart = 1;
  c2_n = c2_metric->size[0] * c2_metric->size[1];
  c2_mtmp = c2_metric->data[0];
  if (muSingleScalarIsNaN(c2_metric->data[0])) {
    c2_ix = 1;
    exitg1 = false;
    while ((!exitg1) && (c2_ix + 1 <= c2_n)) {
      c2_ixstart = c2_ix + 1;
      if (!muSingleScalarIsNaN(c2_metric->data[c2_ix])) {
        c2_mtmp = c2_metric->data[c2_ix];
        exitg1 = true;
      } else {
        c2_ix++;
      }
    }
  }

  if (c2_ixstart < c2_metric->size[0] * c2_metric->size[1]) {
    for (c2_b_ix = c2_ixstart; c2_b_ix + 1 <= c2_n; c2_b_ix++) {
      if (c2_metric->data[c2_b_ix] > c2_mtmp) {
        c2_mtmp = c2_metric->data[c2_b_ix];
      }
    }
  }

  if ((real_T)c2_mtmp <= 4.94065645841247E-324) {
    c2_i270 = c2_loc->size[0] * c2_loc->size[1];
    c2_loc->size[0] = 0;
    c2_loc->size[1] = 2;
    c2_emxEnsureCapacity_real32_T(chartInstance, c2_loc, c2_i270,
      &c2_fd_emlrtRTEI);
    c2_b_loc = c2_loc->size[0];
    c2_c_loc = c2_loc->size[1];
  } else {
    c2_emxInit_real32_T(chartInstance, &c2_b_metric, 2, &c2_gd_emlrtRTEI);
    c2_i271 = c2_b_metric->size[0] * c2_b_metric->size[1];
    c2_b_metric->size[0] = c2_metric->size[0];
    c2_b_metric->size[1] = c2_metric->size[1];
    c2_emxEnsureCapacity_real32_T(chartInstance, c2_b_metric, c2_i271,
      &c2_gd_emlrtRTEI);
    c2_c_metric = c2_b_metric->size[0];
    c2_d_metric = c2_b_metric->size[1];
    c2_loop_ub = c2_metric->size[0] * c2_metric->size[1] - 1;
    for (c2_i272 = 0; c2_i272 <= c2_loop_ub; c2_i272++) {
      c2_b_metric->data[c2_i272] = c2_metric->data[c2_i272];
    }

    c2_emxInit_boolean_T(chartInstance, &c2_bw, 2, &c2_ud_emlrtRTEI);
    c2_imregionalmax(chartInstance, c2_b_metric, c2_bw);
    c2_end = c2_metric->size[0] * c2_metric->size[1] - 1;
    c2_trueCount = 0;
    c2_i = 0;
    c2_emxFree_real32_T(chartInstance, &c2_b_metric);
    while (c2_i <= c2_end) {
      if (c2_metric->data[c2_i] < c2_quality * c2_mtmp) {
        c2_trueCount++;
      }

      c2_i++;
    }

    c2_emxInit_int32_T(chartInstance, &c2_ii, 1, &c2_vd_emlrtRTEI);
    c2_i273 = c2_ii->size[0];
    c2_ii->size[0] = c2_trueCount;
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_ii, c2_i273, &c2_hd_emlrtRTEI);
    c2_partialTrueCount = 0;
    for (c2_b_i = 0; c2_b_i <= c2_end; c2_b_i++) {
      if (c2_metric->data[c2_b_i] < c2_quality * c2_mtmp) {
        c2_ii->data[c2_partialTrueCount] = c2_b_i + 1;
        c2_partialTrueCount++;
      }
    }

    c2_b_bw = c2_bw->size[0];
    c2_c_bw = c2_bw->size[1];
    c2_d_bw = c2_bw->size[0];
    c2_e_bw = c2_bw->size[1];
    c2_f_bw = c2_d_bw * c2_e_bw;
    c2_b_loop_ub = c2_ii->size[0] - 1;
    for (c2_i274 = 0; c2_i274 <= c2_b_loop_ub; c2_i274++) {
      c2_bw->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_ii->data[c2_i274], 1,
        c2_f_bw) - 1] = false;
    }

    c2_b_bwmorph(chartInstance, c2_bw);
    c2_i275 = c2_bw->size[1];
    c2_iv7[0] = 1;
    c2_iv7[1] = c2_i275;
    c2_g_bw = c2_bw->size[1];
    c2_c_loop_ub = c2_iv7[1] - 1;
    for (c2_i276 = 0; c2_i276 <= c2_c_loop_ub; c2_i276++) {
      c2_bw->data[c2_bw->size[0] * c2_i276] = false;
    }

    c2_i277 = c2_bw->size[1];
    c2_iv8[0] = 1;
    c2_iv8[1] = c2_i277;
    c2_h_bw = (real_T)c2_bw->size[0];
    c2_i_bw = c2_bw->size[0];
    c2_j_bw = c2_bw->size[1];
    c2_k_bw = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_h_bw, 1, c2_i_bw) -
      1;
    c2_d_loop_ub = c2_iv8[1] - 1;
    for (c2_i278 = 0; c2_i278 <= c2_d_loop_ub; c2_i278++) {
      c2_bw->data[c2_k_bw + c2_bw->size[0] * c2_i278] = false;
    }

    c2_i279 = c2_bw->size[0];
    c2_iv9[0] = c2_i279;
    c2_l_bw = c2_bw->size[0];
    c2_e_loop_ub = c2_iv9[0] - 1;
    for (c2_i280 = 0; c2_i280 <= c2_e_loop_ub; c2_i280++) {
      c2_bw->data[c2_i280] = false;
    }

    c2_i281 = c2_bw->size[0];
    c2_iv10[0] = c2_i281;
    c2_m_bw = c2_bw->size[0];
    c2_n_bw = (real_T)c2_bw->size[1];
    c2_o_bw = c2_bw->size[1];
    c2_p_bw = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_n_bw, 1, c2_o_bw) -
      1;
    c2_f_loop_ub = c2_iv10[0] - 1;
    for (c2_i282 = 0; c2_i282 <= c2_f_loop_ub; c2_i282++) {
      c2_bw->data[c2_i282 + c2_bw->size[0] * c2_p_bw] = false;
    }

    c2_nx = c2_bw->size[0] * c2_bw->size[1];
    c2_idx = 0;
    c2_i283 = c2_ii->size[0];
    c2_ii->size[0] = c2_nx;
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_ii, c2_i283, &c2_id_emlrtRTEI);
    c2_b_ii = 1;
    exitg1 = false;
    while ((!exitg1) && (c2_b_ii <= c2_nx)) {
      if (c2_bw->data[c2_b_ii - 1]) {
        c2_idx++;
        c2_ii->data[c2_idx - 1] = c2_b_ii;
        if (c2_idx >= c2_nx) {
          exitg1 = true;
        } else {
          c2_b_ii++;
        }
      } else {
        c2_b_ii++;
      }
    }

    c2_emxFree_boolean_T(chartInstance, &c2_bw);
    if (c2_idx <= c2_nx) {
    } else {
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c2_emlrt_marshallOut(chartInstance, c2_cv0)));
    }

    if (1 > c2_idx) {
      c2_i284 = 0;
    } else {
      c2_i284 = c2_idx;
    }

    c2_emxInit_real_T1(chartInstance, &c2_b_idx, 1, &c2_kd_emlrtRTEI);
    c2_i285 = c2_ii->size[0];
    c2_ii->size[0] = c2_i284;
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_ii, c2_i285, &c2_jd_emlrtRTEI);
    c2_i286 = c2_b_idx->size[0];
    c2_b_idx->size[0] = c2_ii->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_b_idx, c2_i286,
      &c2_kd_emlrtRTEI);
    c2_g_loop_ub = c2_ii->size[0] - 1;
    for (c2_i287 = 0; c2_i287 <= c2_g_loop_ub; c2_i287++) {
      c2_b_idx->data[c2_i287] = (real_T)c2_ii->data[c2_i287];
    }

    c2_dv2[0] = (real_T)c2_b_idx->size[0];
    c2_dv2[1] = 2.0;
    c2_i288 = c2_loc->size[0] * c2_loc->size[1];
    c2_loc->size[0] = (int32_T)c2_dv2[0];
    c2_loc->size[1] = 2;
    c2_emxEnsureCapacity_real32_T(chartInstance, c2_loc, c2_i288,
      &c2_ld_emlrtRTEI);
    c2_d_loc = c2_loc->size[0];
    c2_e_loc = c2_loc->size[1];
    c2_h_loop_ub = ((int32_T)c2_dv2[0] << 1) - 1;
    for (c2_i289 = 0; c2_i289 <= c2_h_loop_ub; c2_i289++) {
      c2_loc->data[c2_i289] = 0.0F;
    }

    for (c2_i290 = 0; c2_i290 < 2; c2_i290++) {
      c2_e_metric[c2_i290] = (real_T)c2_metric->size[c2_i290];
    }

    for (c2_i291 = 0; c2_i291 < 2; c2_i291++) {
      c2_siz[c2_i291] = (real_T)c2_metric->size[c2_i291];
    }

    c2_i292 = c2_ii->size[0];
    c2_ii->size[0] = c2_b_idx->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_ii, c2_i292, &c2_md_emlrtRTEI);
    c2_i_loop_ub = c2_b_idx->size[0] - 1;
    for (c2_i293 = 0; c2_i293 <= c2_i_loop_ub; c2_i293++) {
      c2_ii->data[c2_i293] = (int32_T)c2_b_idx->data[c2_i293];
    }

    c2_emxInit_int32_T(chartInstance, &c2_c_ii, 1, &c2_nd_emlrtRTEI);
    c2_i294 = c2_c_ii->size[0];
    c2_c_ii->size[0] = c2_ii->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_c_ii, c2_i294,
      &c2_nd_emlrtRTEI);
    c2_j_loop_ub = c2_ii->size[0] - 1;
    for (c2_i295 = 0; c2_i295 <= c2_j_loop_ub; c2_i295++) {
      c2_c_ii->data[c2_i295] = c2_ii->data[c2_i295];
    }

    if (c2_allinrange(chartInstance, c2_c_ii, 1.0, (int32_T)c2_e_metric[0] *
                      (int32_T)c2_siz[1])) {
    } else {
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c2_c_emlrt_marshallOut(chartInstance, c2_cv22)));
    }

    c2_emxFree_int32_T(chartInstance, &c2_c_ii);
    c2_i296 = c2_ii->size[0];
    c2_ii->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_ii, c2_i296, &c2_od_emlrtRTEI);
    c2_k_loop_ub = c2_ii->size[0] - 1;
    for (c2_i297 = 0; c2_i297 <= c2_k_loop_ub; c2_i297++) {
      c2_ii->data[c2_i297]--;
    }

    c2_emxInit_int32_T(chartInstance, &c2_vk, 1, &c2_pd_emlrtRTEI);
    c2_b_siz = (int32_T)c2_siz[0];
    c2_i298 = c2_vk->size[0];
    c2_vk->size[0] = c2_ii->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_vk, c2_i298, &c2_pd_emlrtRTEI);
    c2_l_loop_ub = c2_ii->size[0] - 1;
    for (c2_i299 = 0; c2_i299 <= c2_l_loop_ub; c2_i299++) {
      c2_vk->data[c2_i299] = c2_div_s32(chartInstance, c2_ii->data[c2_i299],
        c2_b_siz, 1U, 0U, 0U);
    }

    c2_f_metric = (int32_T)c2_e_metric[0];
    c2_i300 = c2_ii->size[0];
    c2_ii->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_ii, c2_i300, &c2_qd_emlrtRTEI);
    c2_m_loop_ub = c2_ii->size[0] - 1;
    for (c2_i301 = 0; c2_i301 <= c2_m_loop_ub; c2_i301++) {
      c2_ii->data[c2_i301] -= c2_vk->data[c2_i301] * c2_f_metric;
    }

    c2_i302 = c2_b_idx->size[0];
    c2_b_idx->size[0] = c2_ii->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_b_idx, c2_i302,
      &c2_rd_emlrtRTEI);
    c2_n_loop_ub = c2_ii->size[0] - 1;
    for (c2_i303 = 0; c2_i303 <= c2_n_loop_ub; c2_i303++) {
      c2_b_idx->data[c2_i303] = (real_T)(c2_ii->data[c2_i303] + 1);
    }

    c2_emxInit_real_T1(chartInstance, &c2_r8, 1, &c2_hd_emlrtRTEI);
    c2_i304 = c2_r8->size[0];
    c2_r8->size[0] = c2_vk->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_r8, c2_i304, &c2_rd_emlrtRTEI);
    c2_o_loop_ub = c2_vk->size[0] - 1;
    for (c2_i305 = 0; c2_i305 <= c2_o_loop_ub; c2_i305++) {
      c2_r8->data[c2_i305] = (real_T)(c2_vk->data[c2_i305] + 1);
    }

    c2_emxFree_int32_T(chartInstance, &c2_vk);
    c2_iv11[0] = (int32_T)c2_dv2[0];
    c2_iv11[1] = 2;
    c2_i306 = c2_ii->size[0];
    c2_ii->size[0] = c2_iv11[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_ii, c2_i306, &c2_sd_emlrtRTEI);
    c2_p_loop_ub = c2_iv11[0] - 1;
    for (c2_i307 = 0; c2_i307 <= c2_p_loop_ub; c2_i307++) {
      c2_ii->data[c2_i307] = c2_i307;
    }

    c2_d_ii[0] = c2_ii->size[0];
    _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c2_d_ii, 1, *(int32_T (*)[1])c2_b_idx->size, 1);
    c2_q_loop_ub = c2_b_idx->size[0] - 1;
    for (c2_i308 = 0; c2_i308 <= c2_q_loop_ub; c2_i308++) {
      c2_loc->data[c2_ii->data[c2_i308] + c2_loc->size[0]] = (real32_T)
        c2_b_idx->data[c2_i308];
    }

    c2_emxFree_real_T(chartInstance, &c2_b_idx);
    c2_i309 = c2_loc->size[0];
    c2_i310 = c2_ii->size[0];
    c2_ii->size[0] = c2_i309;
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_ii, c2_i310, &c2_td_emlrtRTEI);
    c2_r_loop_ub = c2_i309 - 1;
    for (c2_i311 = 0; c2_i311 <= c2_r_loop_ub; c2_i311++) {
      c2_ii->data[c2_i311] = c2_i311;
    }

    c2_e_ii[0] = c2_ii->size[0];
    _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c2_e_ii, 1, *(int32_T (*)[1])c2_r8->size, 1);
    c2_s_loop_ub = c2_r8->size[0] - 1;
    for (c2_i312 = 0; c2_i312 <= c2_s_loop_ub; c2_i312++) {
      c2_loc->data[c2_ii->data[c2_i312]] = (real32_T)c2_r8->data[c2_i312];
    }

    c2_emxFree_int32_T(chartInstance, &c2_ii);
    c2_emxFree_real_T(chartInstance, &c2_r8);
  }
}

static void c2_imregionalmax(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_varargin_1, c2_emxArray_boolean_T
  *c2_BW)
{
  c2_emxArray_real32_T *c2_b_varargin_1;
  int32_T c2_i313;
  int32_T c2_c_varargin_1;
  int32_T c2_d_varargin_1;
  int32_T c2_loop_ub;
  int32_T c2_i314;
  c2_emxArray_real32_T *c2_e_varargin_1;
  int32_T c2_i315;
  int32_T c2_f_varargin_1;
  int32_T c2_g_varargin_1;
  int32_T c2_b_loop_ub;
  int32_T c2_i316;
  int32_T c2_i317;
  int32_T c2_i318;
  int32_T c2_i319;
  real_T c2_imSize[2];
  int32_T c2_i320;
  boolean_T c2_conn[9];
  real_T c2_connSize[2];
  c2_emxInit_real32_T(chartInstance, &c2_b_varargin_1, 2, &c2_wd_emlrtRTEI);
  c2_i313 = c2_b_varargin_1->size[0] * c2_b_varargin_1->size[1];
  c2_b_varargin_1->size[0] = c2_varargin_1->size[0];
  c2_b_varargin_1->size[1] = c2_varargin_1->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_b_varargin_1, c2_i313,
    &c2_wd_emlrtRTEI);
  c2_c_varargin_1 = c2_b_varargin_1->size[0];
  c2_d_varargin_1 = c2_b_varargin_1->size[1];
  c2_loop_ub = c2_varargin_1->size[0] * c2_varargin_1->size[1] - 1;
  for (c2_i314 = 0; c2_i314 <= c2_loop_ub; c2_i314++) {
    c2_b_varargin_1->data[c2_i314] = c2_varargin_1->data[c2_i314];
  }

  c2_emxInit_real32_T(chartInstance, &c2_e_varargin_1, 2, &c2_xd_emlrtRTEI);
  c2_b_validateattributes(chartInstance, c2_b_varargin_1);
  c2_i315 = c2_e_varargin_1->size[0] * c2_e_varargin_1->size[1];
  c2_e_varargin_1->size[0] = c2_varargin_1->size[0];
  c2_e_varargin_1->size[1] = c2_varargin_1->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_e_varargin_1, c2_i315,
    &c2_xd_emlrtRTEI);
  c2_f_varargin_1 = c2_e_varargin_1->size[0];
  c2_g_varargin_1 = c2_e_varargin_1->size[1];
  c2_b_loop_ub = c2_varargin_1->size[0] * c2_varargin_1->size[1] - 1;
  c2_emxFree_real32_T(chartInstance, &c2_b_varargin_1);
  for (c2_i316 = 0; c2_i316 <= c2_b_loop_ub; c2_i316++) {
    c2_e_varargin_1->data[c2_i316] = c2_varargin_1->data[c2_i316];
  }

  c2_toLogicalCheck(chartInstance, c2_e_varargin_1);
  c2_i317 = c2_BW->size[0] * c2_BW->size[1];
  c2_BW->size[0] = c2_varargin_1->size[0];
  c2_BW->size[1] = c2_varargin_1->size[1];
  c2_emxEnsureCapacity_boolean_T(chartInstance, c2_BW, c2_i317, &c2_yd_emlrtRTEI);
  c2_emxFree_real32_T(chartInstance, &c2_e_varargin_1);
  for (c2_i318 = 0; c2_i318 < 2; c2_i318++) {
    c2_imSize[c2_i318] = (real_T)c2_varargin_1->size[c2_i318];
  }

  for (c2_i319 = 0; c2_i319 < 9; c2_i319++) {
    c2_conn[c2_i319] = true;
  }

  for (c2_i320 = 0; c2_i320 < 2; c2_i320++) {
    c2_connSize[c2_i320] = 3.0;
  }

  imregionalmax_real32(&c2_varargin_1->data[0], &c2_BW->data[0], 2.0, c2_imSize,
                       c2_conn, 2.0, c2_connSize);
}

static void c2_b_validateattributes(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_a)
{
  boolean_T c2_p;
  real_T c2_d20;
  int32_T c2_k;
  boolean_T c2_b9;
  const mxArray *c2_y = NULL;
  static char_T c2_cv23[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'r',
    'e', 'g', 'i', 'o', 'n', 'a', 'l', 'm', 'a', 'x', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  const mxArray *c2_b_y = NULL;
  static char_T c2_cv24[42] = { 'E', 'x', 'p', 'e', 'c', 't', 'e', 'd', ' ', 'i',
    'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', '1', ',', ' ',
    'I', ',', ' ', 't', 'o', ' ', 'b', 'e', ' ', 'n', 'o', 'n', '-', 'N', 'a',
    'N', '.' };

  boolean_T exitg1;
  (void)chartInstance;
  c2_p = true;
  c2_d20 = (real_T)(c2_a->size[0] * c2_a->size[1]);
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k <= (int32_T)c2_d20 - 1)) {
    if (!muSingleScalarIsNaN(c2_a->data[c2_k])) {
      c2_k++;
    } else {
      c2_p = false;
      exitg1 = true;
    }
  }

  c2_b9 = c2_p;
  if (c2_b9) {
  } else {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv23, 10, 0U, 1U, 0U, 2, 1, 35),
                  false);
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv24, 10, 0U, 1U, 0U, 2, 1, 42),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_y, 14,
                      c2_b_y);
  }
}

static void c2_b_error(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  const mxArray *c2_y = NULL;
  static char_T c2_cv25[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv25, 10, 0U, 1U, 0U, 2, 1, 19),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c2_y));
}

static void c2_toLogicalCheck(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_x)
{
  real_T c2_d21;
  int32_T c2_k;
  c2_d21 = (real_T)(c2_x->size[0] * c2_x->size[1]);
  for (c2_k = 0; c2_k < (int32_T)c2_d21; c2_k++) {
    if (muSingleScalarIsNaN(c2_x->data[c2_k])) {
      c2_b_error(chartInstance);
    }
  }
}

static void c2_bwmorph(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_boolean_T *c2_bwin, c2_emxArray_boolean_T *c2_bw)
{
  int32_T c2_i321;
  int32_T c2_b_bw;
  int32_T c2_c_bw;
  int32_T c2_loop_ub;
  int32_T c2_i322;
  c2_i321 = c2_bw->size[0] * c2_bw->size[1];
  c2_bw->size[0] = c2_bwin->size[0];
  c2_bw->size[1] = c2_bwin->size[1];
  c2_emxEnsureCapacity_boolean_T(chartInstance, c2_bw, c2_i321, &c2_ae_emlrtRTEI);
  c2_b_bw = c2_bw->size[0];
  c2_c_bw = c2_bw->size[1];
  c2_loop_ub = c2_bwin->size[0] * c2_bwin->size[1] - 1;
  for (c2_i322 = 0; c2_i322 <= c2_loop_ub; c2_i322++) {
    c2_bw->data[c2_i322] = c2_bwin->data[c2_i322];
  }

  c2_b_bwmorph(chartInstance, c2_bw);
}

static void c2_bwlookup(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_boolean_T *c2_bwin, c2_emxArray_boolean_T *c2_B)
{
  int32_T c2_i323;
  int32_T c2_i324;
  real_T c2_b_bwin[2];
  int32_T c2_i325;
  real_T c2_c_bwin[2];
  static boolean_T c2_lut[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, true, true, true, false, true, true, true, true, true, true, false,
    false, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, false, true,
    true, true, false, true, true, false, false, true, true, false, false, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, false, false, false,
    false, false, false, true, true, true, true, false, false, true, true, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, true, true, false, false, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, true, false, false, false, false, false, false, false,
    true, true, true, true, false, false, true, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, false, true, true, true, false, true, true, true, true, false,
    false, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    false, false, false, false, false, false, false, true, true, true, true,
    false, false, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, false,
    true, true, true, false, true, true, true, true, false, false, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, true, true, true,
    false, true, true, false, false, true, true, false, false, true, true, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, false, false, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, false, false, false, false, false, false, false, true,
    true, true, true, false, false, true, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, false, true, true, true, false, true, true, true, true, false,
    false, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    false, false, false, false, false, false, false, true, true, true, true,
    false, false, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, false,
    true, true, true, false, true, true, true, true, false, false, true, true,
    false, false };

  for (c2_i323 = 0; c2_i323 < 2; c2_i323++) {
    c2_b_bwin[c2_i323] = (real_T)c2_bwin->size[c2_i323];
  }

  c2_i324 = c2_B->size[0] * c2_B->size[1];
  c2_B->size[0] = (int32_T)c2_b_bwin[0];
  c2_B->size[1] = (int32_T)c2_b_bwin[1];
  c2_emxEnsureCapacity_boolean_T(chartInstance, c2_B, c2_i324, &c2_be_emlrtRTEI);
  for (c2_i325 = 0; c2_i325 < 2; c2_i325++) {
    c2_c_bwin[c2_i325] = (real_T)c2_bwin->size[c2_i325];
  }

  bwlookup_tbb_boolean(&c2_bwin->data[0], c2_c_bwin, 2.0, c2_lut, 512.0,
                       &c2_B->data[0]);
}

static boolean_T c2_isequal(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_boolean_T *c2_varargin_1, c2_emxArray_boolean_T *c2_varargin_2)
{
  boolean_T c2_p;
  boolean_T c2_b_p;
  boolean_T c2_c_p;
  boolean_T c2_d_p;
  int32_T c2_k;
  boolean_T exitg1;
  (void)chartInstance;
  c2_p = false;
  c2_b_p = false;
  if (((real_T)c2_varargin_1->size[0] != (real_T)c2_varargin_2->size[0]) ||
      ((real_T)c2_varargin_1->size[1] != (real_T)c2_varargin_2->size[1])) {
  } else {
    c2_b_p = true;
  }

  c2_c_p = c2_b_p;
  c2_d_p = c2_c_p;
  if (c2_c_p) {
    c2_k = 0;
    exitg1 = false;
    while ((!exitg1) && (c2_k <= c2_varargin_2->size[0] * c2_varargin_2->size[1]
                         - 1)) {
      if ((int32_T)c2_varargin_1->data[c2_k] != (int32_T)c2_varargin_2->
          data[c2_k]) {
        c2_d_p = false;
        exitg1 = true;
      } else {
        c2_k++;
      }
    }
  }

  if (!c2_d_p) {
  } else {
    c2_p = true;
  }

  return c2_p;
}

static boolean_T c2_allinrange(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_int32_T *c2_x, real_T c2_lo, int32_T c2_hi)
{
  boolean_T c2_p;
  int32_T c2_k;
  boolean_T c2_b10;
  int32_T exitg1;
  (void)chartInstance;
  (void)c2_lo;
  c2_k = 0;
  do {
    exitg1 = 0;
    if (c2_k <= c2_x->size[0] - 1) {
      if (((real_T)c2_x->data[c2_k] >= 1.0) && (c2_x->data[c2_k] <= c2_hi)) {
        c2_b10 = true;
      } else {
        c2_b10 = false;
      }

      if (!c2_b10) {
        c2_p = false;
        exitg1 = 1;
      } else {
        c2_k++;
      }
    } else {
      c2_p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c2_p;
}

static void c2_subPixelLocation(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_metric, c2_emxArray_real32_T *c2_loc,
  c2_emxArray_real32_T *c2_b_loc)
{
  int32_T c2_i326;
  int32_T c2_c_loc;
  int32_T c2_d_loc;
  int32_T c2_loop_ub;
  int32_T c2_i327;
  c2_emxArray_real32_T *c2_b_metric;
  int32_T c2_i328;
  int32_T c2_c_metric;
  int32_T c2_d_metric;
  int32_T c2_b_loop_ub;
  int32_T c2_i329;
  c2_i326 = c2_b_loc->size[0] * c2_b_loc->size[1];
  c2_b_loc->size[0] = c2_loc->size[0];
  c2_b_loc->size[1] = 2;
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_b_loc, c2_i326,
    &c2_ce_emlrtRTEI);
  c2_c_loc = c2_b_loc->size[0];
  c2_d_loc = c2_b_loc->size[1];
  c2_loop_ub = c2_loc->size[0] * c2_loc->size[1] - 1;
  for (c2_i327 = 0; c2_i327 <= c2_loop_ub; c2_i327++) {
    c2_b_loc->data[c2_i327] = c2_loc->data[c2_i327];
  }

  c2_emxInit_real32_T(chartInstance, &c2_b_metric, 2, &c2_ce_emlrtRTEI);
  c2_i328 = c2_b_metric->size[0] * c2_b_metric->size[1];
  c2_b_metric->size[0] = c2_metric->size[0];
  c2_b_metric->size[1] = c2_metric->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_b_metric, c2_i328,
    &c2_ce_emlrtRTEI);
  c2_c_metric = c2_b_metric->size[0];
  c2_d_metric = c2_b_metric->size[1];
  c2_b_loop_ub = c2_metric->size[0] * c2_metric->size[1] - 1;
  for (c2_i329 = 0; c2_i329 <= c2_b_loop_ub; c2_i329++) {
    c2_b_metric->data[c2_i329] = c2_metric->data[c2_i329];
  }

  c2_b_subPixelLocation(chartInstance, c2_b_metric, c2_b_loc);
  c2_emxFree_real32_T(chartInstance, &c2_b_metric);
}

static void c2_c_error(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance)
{
  const mxArray *c2_y = NULL;
  static char_T c2_cv26[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'r', 'e', 's', 'h', 'a', 'p', 'e', '_', 'e', 'm', 'p',
    't', 'y', 'R', 'e', 's', 'h', 'a', 'p', 'e', 'L', 'i', 'm', 'i', 't' };

  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv26, 10, 0U, 1U, 0U, 2, 1, 39),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c2_y));
}

static void c2_subPixelLocationImpl(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_metric, c2_emxArray_real32_T *c2_loc,
  c2_emxArray_real32_T *c2_subPixelLoc)
{
  c2_emxArray_real32_T *c2_dy2;
  real_T c2_dv3[3];
  int32_T c2_i330;
  int32_T c2_i331;
  int32_T c2_loop_ub;
  int32_T c2_i332;
  c2_emxArray_real32_T *c2_dx2;
  int32_T c2_i333;
  int32_T c2_i334;
  int32_T c2_b_loop_ub;
  int32_T c2_i335;
  c2_emxArray_real32_T *c2_xm1;
  int32_T c2_i336;
  int32_T c2_b_xm1;
  int32_T c2_c_xm1;
  int32_T c2_d_xm1;
  int32_T c2_c_loop_ub;
  int32_T c2_i337;
  c2_emxArray_real32_T *c2_xp1;
  int32_T c2_i338;
  int32_T c2_b_xp1;
  int32_T c2_c_xp1;
  int32_T c2_d_xp1;
  int32_T c2_d_loop_ub;
  int32_T c2_i339;
  c2_emxArray_real32_T *c2_ym1;
  int32_T c2_i340;
  int32_T c2_b_ym1;
  int32_T c2_c_ym1;
  int32_T c2_d_ym1;
  int32_T c2_e_loop_ub;
  int32_T c2_i341;
  c2_emxArray_real32_T *c2_yp1;
  int32_T c2_i342;
  int32_T c2_b_yp1;
  int32_T c2_c_yp1;
  int32_T c2_d_yp1;
  int32_T c2_f_loop_ub;
  int32_T c2_i343;
  c2_emxArray_real32_T *c2_result;
  boolean_T c2_b11;
  const mxArray *c2_y = NULL;
  static char_T c2_cv27[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a', 't',
    'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i', 'm',
    'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  int32_T c2_i344;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  int32_T c2_i345;
  int32_T c2_g_loop_ub;
  int32_T c2_i346;
  int32_T c2_h_loop_ub;
  int32_T c2_i347;
  int32_T c2_i_loop_ub;
  int32_T c2_i348;
  c2_emxArray_real32_T *c2_b_result;
  boolean_T c2_b12;
  const mxArray *c2_d_y = NULL;
  static char_T c2_cv28[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a', 't',
    'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i', 'm',
    'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  int32_T c2_i349;
  const mxArray *c2_e_y = NULL;
  const mxArray *c2_f_y = NULL;
  int32_T c2_i350;
  int32_T c2_j_loop_ub;
  int32_T c2_i351;
  int32_T c2_k_loop_ub;
  int32_T c2_i352;
  int32_T c2_l_loop_ub;
  int32_T c2_i353;
  c2_emxArray_real32_T *c2_c_result;
  boolean_T c2_b13;
  const mxArray *c2_g_y = NULL;
  static char_T c2_cv29[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a', 't',
    'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i', 'm',
    'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  int32_T c2_i354;
  const mxArray *c2_h_y = NULL;
  const mxArray *c2_i_y = NULL;
  int32_T c2_i355;
  int32_T c2_m_loop_ub;
  int32_T c2_i356;
  int32_T c2_n_loop_ub;
  int32_T c2_i357;
  int32_T c2_o_loop_ub;
  int32_T c2_i358;
  boolean_T c2_b14;
  const mxArray *c2_j_y = NULL;
  static char_T c2_cv30[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a', 't',
    'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i', 'm',
    'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  const mxArray *c2_k_y = NULL;
  const mxArray *c2_l_y = NULL;
  c2_emxArray_real32_T *c2_xsubs;
  int32_T c2_i359;
  int32_T c2_p_loop_ub;
  int32_T c2_i360;
  int32_T c2_q_loop_ub;
  int32_T c2_i361;
  int32_T c2_i362;
  int32_T c2_r_loop_ub;
  int32_T c2_i363;
  int32_T c2_i364;
  boolean_T c2_b15;
  int32_T c2_i365;
  const mxArray *c2_m_y = NULL;
  static char_T c2_cv31[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a', 't',
    'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i', 'm',
    'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  const mxArray *c2_n_y = NULL;
  const mxArray *c2_o_y = NULL;
  int32_T c2_i366;
  int32_T c2_s_loop_ub;
  int32_T c2_i367;
  int32_T c2_t_loop_ub;
  int32_T c2_i368;
  int32_T c2_u_loop_ub;
  int32_T c2_i369;
  boolean_T c2_b16;
  const mxArray *c2_p_y = NULL;
  static char_T c2_cv32[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a', 't',
    'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i', 'm',
    'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  const mxArray *c2_q_y = NULL;
  const mxArray *c2_r_y = NULL;
  int32_T c2_i370;
  int32_T c2_v_loop_ub;
  int32_T c2_i371;
  int32_T c2_w_loop_ub;
  int32_T c2_i372;
  int32_T c2_x_loop_ub;
  int32_T c2_i373;
  boolean_T c2_b17;
  const mxArray *c2_s_y = NULL;
  static char_T c2_cv33[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a', 't',
    'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i', 'm',
    'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  const mxArray *c2_t_y = NULL;
  const mxArray *c2_u_y = NULL;
  int32_T c2_i374;
  int32_T c2_y_loop_ub;
  int32_T c2_i375;
  int32_T c2_ab_loop_ub;
  int32_T c2_i376;
  int32_T c2_bb_loop_ub;
  int32_T c2_i377;
  boolean_T c2_b18;
  const mxArray *c2_v_y = NULL;
  static char_T c2_cv34[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a', 't',
    'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i', 'm',
    'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  const mxArray *c2_w_y = NULL;
  const mxArray *c2_x_y = NULL;
  c2_emxArray_real32_T *c2_ysubs;
  int32_T c2_i378;
  int32_T c2_cb_loop_ub;
  int32_T c2_i379;
  int32_T c2_i380;
  int32_T c2_db_loop_ub;
  int32_T c2_i381;
  int32_T c2_i382;
  int32_T c2_eb_loop_ub;
  int32_T c2_i383;
  int32_T c2_i384;
  c2_emxArray_int32_T *c2_idx;
  int32_T c2_i385;
  c2_emxArray_real32_T *c2_b_ysubs;
  int32_T c2_siz[2];
  int32_T c2_i386;
  int32_T c2_fb_loop_ub;
  int32_T c2_i387;
  real_T c2_dv4[2];
  real_T c2_dv5[2];
  int32_T c2_i388;
  c2_emxArray_real32_T *c2_b_xsubs;
  int32_T c2_b_siz[2];
  int32_T c2_i389;
  int32_T c2_gb_loop_ub;
  int32_T c2_i390;
  int32_T c2_c_siz;
  int32_T c2_i391;
  int32_T c2_hb_loop_ub;
  int32_T c2_i392;
  c2_emxArray_real32_T *c2_patch;
  int32_T c2_b_metric;
  int32_T c2_i393;
  int32_T c2_ib_loop_ub;
  int32_T c2_i394;
  c2_emxArray_real32_T *c2_r9;
  int32_T c2_iv12[3];
  int32_T c2_iv13[3];
  int32_T c2_iv14[3];
  int32_T c2_i395;
  int32_T c2_jb_loop_ub;
  int32_T c2_i396;
  c2_emxArray_real32_T *c2_c_metric;
  int32_T c2_d_metric[1];
  int32_T c2_i397;
  int32_T c2_kb_loop_ub;
  int32_T c2_i398;
  c2_emxArray_real32_T *c2_e_metric;
  int32_T c2_iv15[3];
  int32_T c2_iv16[3];
  int32_T c2_i399;
  int32_T c2_lb_loop_ub;
  int32_T c2_i400;
  int32_T c2_i401;
  int32_T c2_f_metric[3];
  int32_T c2_i402;
  c2_emxArray_real32_T *c2_g_metric;
  int32_T c2_iv17[3];
  int32_T c2_h_metric[1];
  int32_T c2_i403;
  int32_T c2_mb_loop_ub;
  int32_T c2_i404;
  c2_emxArray_real32_T *c2_i_metric;
  int32_T c2_iv18[3];
  int32_T c2_iv19[3];
  int32_T c2_i405;
  int32_T c2_nb_loop_ub;
  int32_T c2_i406;
  int32_T c2_i407;
  int32_T c2_j_metric[3];
  c2_emxArray_real32_T *c2_k_metric;
  int32_T c2_l_metric[1];
  int32_T c2_i408;
  int32_T c2_ob_loop_ub;
  int32_T c2_i409;
  c2_emxArray_real32_T *c2_m_metric;
  int32_T c2_iv20[3];
  int32_T c2_iv21[3];
  int32_T c2_i410;
  int32_T c2_pb_loop_ub;
  int32_T c2_i411;
  int32_T c2_i412;
  int32_T c2_n_metric[3];
  c2_emxArray_real32_T *c2_r10;
  int32_T c2_iv22[3];
  int32_T c2_iv23[3];
  int32_T c2_i413;
  int32_T c2_qb_loop_ub;
  int32_T c2_i414;
  c2_emxArray_real32_T *c2_o_metric;
  int32_T c2_p_metric[1];
  int32_T c2_i415;
  int32_T c2_rb_loop_ub;
  int32_T c2_i416;
  c2_emxArray_real32_T *c2_q_metric;
  int32_T c2_iv24[3];
  int32_T c2_iv25[3];
  int32_T c2_i417;
  int32_T c2_sb_loop_ub;
  int32_T c2_i418;
  int32_T c2_i419;
  int32_T c2_r_metric[3];
  int32_T c2_i420;
  c2_emxArray_real32_T *c2_r11;
  int32_T c2_iv26[3];
  int32_T c2_iv27[3];
  int32_T c2_iv28[3];
  int32_T c2_i421;
  int32_T c2_tb_loop_ub;
  int32_T c2_i422;
  c2_emxArray_real32_T *c2_s_metric;
  int32_T c2_t_metric[1];
  int32_T c2_i423;
  int32_T c2_ub_loop_ub;
  int32_T c2_i424;
  c2_emxArray_real32_T *c2_u_metric;
  int32_T c2_iv29[3];
  int32_T c2_iv30[3];
  int32_T c2_i425;
  int32_T c2_vb_loop_ub;
  int32_T c2_i426;
  int32_T c2_i427;
  int32_T c2_v_metric[3];
  int32_T c2_i428;
  int32_T c2_iv31[3];
  int32_T c2_iv32[3];
  int32_T c2_iv33[3];
  int32_T c2_i429;
  int32_T c2_wb_loop_ub;
  int32_T c2_i430;
  c2_emxArray_real32_T *c2_w_metric;
  int32_T c2_x_metric[1];
  int32_T c2_i431;
  int32_T c2_xb_loop_ub;
  int32_T c2_i432;
  c2_emxArray_real32_T *c2_y_metric;
  int32_T c2_iv34[3];
  int32_T c2_iv35[3];
  int32_T c2_i433;
  int32_T c2_yb_loop_ub;
  int32_T c2_i434;
  int32_T c2_i435;
  int32_T c2_ab_metric[3];
  int32_T c2_i436;
  c2_emxArray_real32_T *c2_bb_metric;
  int32_T c2_e_xm1[3];
  int32_T c2_cb_metric[1];
  int32_T c2_i437;
  int32_T c2_ac_loop_ub;
  int32_T c2_i438;
  c2_emxArray_real32_T *c2_db_metric;
  int32_T c2_iv36[3];
  int32_T c2_iv37[3];
  int32_T c2_i439;
  int32_T c2_bc_loop_ub;
  int32_T c2_i440;
  int32_T c2_i441;
  int32_T c2_eb_metric[3];
  c2_emxArray_real32_T *c2_fb_metric;
  int32_T c2_gb_metric[1];
  int32_T c2_i442;
  int32_T c2_cc_loop_ub;
  int32_T c2_i443;
  c2_emxArray_real32_T *c2_hb_metric;
  int32_T c2_iv38[3];
  int32_T c2_iv39[3];
  int32_T c2_i444;
  int32_T c2_dc_loop_ub;
  int32_T c2_i445;
  int32_T c2_i446;
  int32_T c2_ib_metric[3];
  int32_T c2_iv40[3];
  int32_T c2_iv41[3];
  int32_T c2_i447;
  int32_T c2_ec_loop_ub;
  int32_T c2_i448;
  c2_emxArray_real32_T *c2_jb_metric;
  int32_T c2_kb_metric[1];
  int32_T c2_i449;
  int32_T c2_fc_loop_ub;
  int32_T c2_i450;
  c2_emxArray_real32_T *c2_lb_metric;
  int32_T c2_iv42[3];
  int32_T c2_iv43[3];
  int32_T c2_i451;
  int32_T c2_gc_loop_ub;
  int32_T c2_i452;
  int32_T c2_i453;
  int32_T c2_mb_metric[3];
  int32_T c2_i454;
  c2_emxArray_real32_T *c2_nb_metric;
  int32_T c2_e_xp1[3];
  int32_T c2_ob_metric[1];
  int32_T c2_i455;
  int32_T c2_hc_loop_ub;
  int32_T c2_i456;
  c2_emxArray_real32_T *c2_pb_metric;
  int32_T c2_iv44[3];
  int32_T c2_iv45[3];
  int32_T c2_i457;
  int32_T c2_ic_loop_ub;
  int32_T c2_i458;
  int32_T c2_i459;
  int32_T c2_qb_metric[3];
  c2_emxArray_real32_T *c2_rb_metric;
  int32_T c2_sb_metric[1];
  int32_T c2_i460;
  int32_T c2_jc_loop_ub;
  int32_T c2_i461;
  c2_emxArray_real32_T *c2_tb_metric;
  int32_T c2_iv46[3];
  int32_T c2_iv47[3];
  int32_T c2_i462;
  int32_T c2_kc_loop_ub;
  int32_T c2_i463;
  int32_T c2_i464;
  int32_T c2_ub_metric[3];
  int32_T c2_iv48[3];
  int32_T c2_iv49[3];
  int32_T c2_iv50[3];
  int32_T c2_iv51[3];
  int32_T c2_iv52[3];
  int32_T c2_iv53[3];
  int32_T c2_iv54[3];
  int32_T c2_iv55[3];
  int32_T c2_i465;
  int32_T c2_lc_loop_ub;
  int32_T c2_i466;
  int32_T c2_iv56[3];
  int32_T c2_iv57[3];
  int32_T c2_i467;
  int32_T c2_mc_loop_ub;
  int32_T c2_i468;
  c2_emxArray_real32_T *c2_vb_metric;
  int32_T c2_wb_metric[1];
  int32_T c2_i469;
  int32_T c2_nc_loop_ub;
  int32_T c2_i470;
  c2_emxArray_real32_T *c2_xb_metric;
  int32_T c2_iv58[3];
  int32_T c2_iv59[3];
  int32_T c2_i471;
  int32_T c2_oc_loop_ub;
  int32_T c2_i472;
  int32_T c2_i473;
  int32_T c2_yb_metric[3];
  int32_T c2_i474;
  c2_emxArray_real32_T *c2_ac_metric;
  int32_T c2_iv60[3];
  int32_T c2_bc_metric[1];
  int32_T c2_i475;
  int32_T c2_pc_loop_ub;
  int32_T c2_i476;
  c2_emxArray_real32_T *c2_cc_metric;
  int32_T c2_iv61[3];
  int32_T c2_iv62[3];
  int32_T c2_i477;
  int32_T c2_qc_loop_ub;
  int32_T c2_i478;
  int32_T c2_i479;
  int32_T c2_dc_metric[3];
  c2_emxArray_real32_T *c2_ec_metric;
  int32_T c2_fc_metric[1];
  int32_T c2_i480;
  int32_T c2_rc_loop_ub;
  int32_T c2_i481;
  c2_emxArray_real32_T *c2_gc_metric;
  int32_T c2_iv63[3];
  int32_T c2_iv64[3];
  int32_T c2_i482;
  int32_T c2_sc_loop_ub;
  int32_T c2_i483;
  int32_T c2_i484;
  int32_T c2_hc_metric[3];
  int32_T c2_iv65[3];
  int32_T c2_iv66[3];
  int32_T c2_i485;
  int32_T c2_tc_loop_ub;
  int32_T c2_i486;
  c2_emxArray_real32_T *c2_ic_metric;
  int32_T c2_jc_metric[1];
  int32_T c2_i487;
  int32_T c2_uc_loop_ub;
  int32_T c2_i488;
  c2_emxArray_real32_T *c2_kc_metric;
  int32_T c2_iv67[3];
  int32_T c2_iv68[3];
  int32_T c2_i489;
  int32_T c2_vc_loop_ub;
  int32_T c2_i490;
  int32_T c2_i491;
  int32_T c2_lc_metric[3];
  int32_T c2_i492;
  c2_emxArray_real32_T *c2_mc_metric;
  int32_T c2_iv69[3];
  int32_T c2_nc_metric[1];
  int32_T c2_i493;
  int32_T c2_wc_loop_ub;
  int32_T c2_i494;
  c2_emxArray_real32_T *c2_oc_metric;
  int32_T c2_iv70[3];
  int32_T c2_iv71[3];
  int32_T c2_i495;
  int32_T c2_xc_loop_ub;
  int32_T c2_i496;
  int32_T c2_i497;
  int32_T c2_pc_metric[3];
  c2_emxArray_real32_T *c2_qc_metric;
  int32_T c2_rc_metric[1];
  int32_T c2_i498;
  int32_T c2_yc_loop_ub;
  int32_T c2_i499;
  c2_emxArray_real32_T *c2_sc_metric;
  int32_T c2_iv72[3];
  int32_T c2_iv73[3];
  int32_T c2_i500;
  int32_T c2_ad_loop_ub;
  int32_T c2_i501;
  int32_T c2_i502;
  int32_T c2_tc_metric[3];
  int32_T c2_iv74[3];
  int32_T c2_iv75[3];
  int32_T c2_iv76[3];
  int32_T c2_iv77[3];
  int32_T c2_i503;
  int32_T c2_bd_loop_ub;
  int32_T c2_i504;
  c2_emxArray_real32_T *c2_uc_metric;
  int32_T c2_vc_metric[1];
  int32_T c2_i505;
  int32_T c2_cd_loop_ub;
  int32_T c2_i506;
  c2_emxArray_real32_T *c2_wc_metric;
  int32_T c2_iv78[3];
  int32_T c2_iv79[3];
  int32_T c2_i507;
  int32_T c2_dd_loop_ub;
  int32_T c2_i508;
  int32_T c2_i509;
  int32_T c2_xc_metric[3];
  int32_T c2_i510;
  int32_T c2_iv80[3];
  int32_T c2_iv81[3];
  int32_T c2_iv82[3];
  int32_T c2_i511;
  int32_T c2_ed_loop_ub;
  int32_T c2_i512;
  c2_emxArray_real32_T *c2_yc_metric;
  int32_T c2_ad_metric[1];
  int32_T c2_i513;
  int32_T c2_fd_loop_ub;
  int32_T c2_i514;
  c2_emxArray_real32_T *c2_bd_metric;
  int32_T c2_iv83[3];
  int32_T c2_iv84[3];
  int32_T c2_i515;
  int32_T c2_gd_loop_ub;
  int32_T c2_i516;
  int32_T c2_i517;
  int32_T c2_cd_metric[3];
  int32_T c2_i518;
  c2_emxArray_real32_T *c2_dd_metric;
  int32_T c2_iv85[3];
  int32_T c2_ed_metric[1];
  int32_T c2_i519;
  int32_T c2_hd_loop_ub;
  int32_T c2_i520;
  c2_emxArray_real32_T *c2_fd_metric;
  int32_T c2_iv86[3];
  int32_T c2_iv87[3];
  int32_T c2_i521;
  int32_T c2_id_loop_ub;
  int32_T c2_i522;
  int32_T c2_i523;
  int32_T c2_gd_metric[3];
  c2_emxArray_real32_T *c2_hd_metric;
  int32_T c2_id_metric[1];
  int32_T c2_i524;
  int32_T c2_jd_loop_ub;
  int32_T c2_i525;
  c2_emxArray_real32_T *c2_jd_metric;
  int32_T c2_iv88[3];
  int32_T c2_iv89[3];
  int32_T c2_i526;
  int32_T c2_kd_loop_ub;
  int32_T c2_i527;
  int32_T c2_i528;
  int32_T c2_kd_metric[3];
  c2_emxArray_real32_T *c2_ld_metric;
  int32_T c2_md_metric[1];
  int32_T c2_i529;
  int32_T c2_ld_loop_ub;
  int32_T c2_i530;
  c2_emxArray_real32_T *c2_nd_metric;
  int32_T c2_iv90[3];
  int32_T c2_iv91[3];
  int32_T c2_i531;
  int32_T c2_md_loop_ub;
  int32_T c2_i532;
  int32_T c2_i533;
  int32_T c2_od_metric[3];
  c2_emxArray_real32_T *c2_pd_metric;
  int32_T c2_qd_metric[1];
  int32_T c2_i534;
  int32_T c2_nd_loop_ub;
  int32_T c2_i535;
  c2_emxArray_real32_T *c2_rd_metric;
  int32_T c2_iv92[3];
  int32_T c2_iv93[3];
  int32_T c2_i536;
  int32_T c2_od_loop_ub;
  int32_T c2_i537;
  int32_T c2_i538;
  int32_T c2_sd_metric[3];
  int32_T c2_iv94[3];
  int32_T c2_iv95[3];
  int32_T c2_iv96[3];
  int32_T c2_iv97[3];
  int32_T c2_iv98[3];
  int32_T c2_iv99[3];
  int32_T c2_iv100[3];
  int32_T c2_iv101[3];
  int32_T c2_i539;
  int32_T c2_pd_loop_ub;
  int32_T c2_i540;
  c2_emxArray_real32_T *c2_td_metric;
  int32_T c2_ud_metric[1];
  int32_T c2_i541;
  int32_T c2_qd_loop_ub;
  int32_T c2_i542;
  c2_emxArray_real32_T *c2_vd_metric;
  int32_T c2_iv102[3];
  int32_T c2_iv103[3];
  int32_T c2_i543;
  int32_T c2_rd_loop_ub;
  int32_T c2_i544;
  int32_T c2_i545;
  int32_T c2_wd_metric[3];
  c2_emxArray_real32_T *c2_xd_metric;
  int32_T c2_yd_metric[1];
  int32_T c2_i546;
  int32_T c2_sd_loop_ub;
  int32_T c2_i547;
  c2_emxArray_real32_T *c2_ae_metric;
  int32_T c2_iv104[3];
  int32_T c2_iv105[3];
  int32_T c2_i548;
  int32_T c2_td_loop_ub;
  int32_T c2_i549;
  int32_T c2_i550;
  int32_T c2_be_metric[3];
  c2_emxArray_real32_T *c2_ce_metric;
  int32_T c2_de_metric[1];
  int32_T c2_i551;
  int32_T c2_ud_loop_ub;
  int32_T c2_i552;
  c2_emxArray_real32_T *c2_ee_metric;
  int32_T c2_iv106[3];
  int32_T c2_iv107[3];
  int32_T c2_i553;
  int32_T c2_vd_loop_ub;
  int32_T c2_i554;
  int32_T c2_i555;
  int32_T c2_fe_metric[3];
  c2_emxArray_real32_T *c2_ge_metric;
  int32_T c2_he_metric[1];
  int32_T c2_i556;
  int32_T c2_wd_loop_ub;
  int32_T c2_i557;
  c2_emxArray_real32_T *c2_ie_metric;
  int32_T c2_iv108[3];
  int32_T c2_iv109[3];
  int32_T c2_i558;
  int32_T c2_xd_loop_ub;
  int32_T c2_i559;
  int32_T c2_i560;
  int32_T c2_je_metric[3];
  c2_emxArray_real32_T *c2_ke_metric;
  int32_T c2_le_metric[1];
  int32_T c2_i561;
  int32_T c2_yd_loop_ub;
  int32_T c2_i562;
  c2_emxArray_real32_T *c2_me_metric;
  int32_T c2_iv110[3];
  int32_T c2_iv111[3];
  int32_T c2_i563;
  int32_T c2_ae_loop_ub;
  int32_T c2_i564;
  int32_T c2_i565;
  int32_T c2_ne_metric[3];
  c2_emxArray_real32_T *c2_oe_metric;
  int32_T c2_pe_metric[1];
  int32_T c2_i566;
  int32_T c2_be_loop_ub;
  int32_T c2_i567;
  c2_emxArray_real32_T *c2_qe_metric;
  int32_T c2_iv112[3];
  int32_T c2_iv113[3];
  int32_T c2_i568;
  int32_T c2_ce_loop_ub;
  int32_T c2_i569;
  int32_T c2_i570;
  int32_T c2_re_metric[3];
  int32_T c2_iv114[3];
  int32_T c2_iv115[3];
  int32_T c2_iv116[3];
  int32_T c2_iv117[3];
  int32_T c2_iv118[3];
  int32_T c2_iv119[3];
  int32_T c2_iv120[3];
  int32_T c2_iv121[3];
  int32_T c2_i571;
  int32_T c2_de_loop_ub;
  int32_T c2_i572;
  int32_T c2_iv122[3];
  int32_T c2_iv123[3];
  int32_T c2_i573;
  int32_T c2_ee_loop_ub;
  int32_T c2_i574;
  int32_T c2_iv124[3];
  int32_T c2_iv125[3];
  int32_T c2_i575;
  int32_T c2_fe_loop_ub;
  int32_T c2_i576;
  int32_T c2_i577;
  int32_T c2_i578;
  int32_T c2_iv126[3];
  int32_T c2_iv127[3];
  int32_T c2_i579;
  c2_emxArray_real32_T *c2_se_metric;
  int32_T c2_iv128[3];
  int32_T c2_te_metric[1];
  int32_T c2_i580;
  int32_T c2_ge_loop_ub;
  int32_T c2_i581;
  c2_emxArray_real32_T *c2_ue_metric;
  int32_T c2_iv129[3];
  int32_T c2_iv130[3];
  int32_T c2_i582;
  int32_T c2_he_loop_ub;
  int32_T c2_i583;
  int32_T c2_i584;
  int32_T c2_ve_metric[3];
  int32_T c2_i585;
  c2_emxArray_real32_T *c2_we_metric;
  int32_T c2_iv131[3];
  int32_T c2_xe_metric[1];
  int32_T c2_i586;
  int32_T c2_ie_loop_ub;
  int32_T c2_i587;
  c2_emxArray_real32_T *c2_ye_metric;
  int32_T c2_iv132[3];
  int32_T c2_iv133[3];
  int32_T c2_i588;
  int32_T c2_je_loop_ub;
  int32_T c2_i589;
  int32_T c2_i590;
  int32_T c2_af_metric[3];
  int32_T c2_iv134[3];
  int32_T c2_iv135[3];
  int32_T c2_i591;
  int32_T c2_ke_loop_ub;
  int32_T c2_i592;
  int32_T c2_i593;
  int32_T c2_i594;
  int32_T c2_iv136[3];
  int32_T c2_iv137[3];
  int32_T c2_i595;
  c2_emxArray_real32_T *c2_bf_metric;
  int32_T c2_iv138[3];
  int32_T c2_cf_metric[1];
  int32_T c2_i596;
  int32_T c2_le_loop_ub;
  int32_T c2_i597;
  c2_emxArray_real32_T *c2_df_metric;
  int32_T c2_iv139[3];
  int32_T c2_iv140[3];
  int32_T c2_i598;
  int32_T c2_me_loop_ub;
  int32_T c2_i599;
  int32_T c2_i600;
  int32_T c2_ef_metric[3];
  int32_T c2_iv141[3];
  int32_T c2_iv142[3];
  int32_T c2_iv143[3];
  int32_T c2_iv144[3];
  int32_T c2_iv145[3];
  int32_T c2_iv146[3];
  int32_T c2_i601;
  int32_T c2_ne_loop_ub;
  int32_T c2_i602;
  int32_T c2_iv147[3];
  int32_T c2_iv148[3];
  int32_T c2_i603;
  int32_T c2_oe_loop_ub;
  int32_T c2_i604;
  int32_T c2_iv149[3];
  int32_T c2_iv150[3];
  int32_T c2_i605;
  int32_T c2_pe_loop_ub;
  int32_T c2_i606;
  int32_T c2_i607;
  int32_T c2_i608;
  int32_T c2_iv151[3];
  int32_T c2_iv152[3];
  int32_T c2_i609;
  c2_emxArray_real32_T *c2_ff_metric;
  int32_T c2_iv153[3];
  int32_T c2_gf_metric[1];
  int32_T c2_i610;
  int32_T c2_qe_loop_ub;
  int32_T c2_i611;
  c2_emxArray_real32_T *c2_hf_metric;
  int32_T c2_iv154[3];
  int32_T c2_iv155[3];
  int32_T c2_i612;
  int32_T c2_re_loop_ub;
  int32_T c2_i613;
  int32_T c2_i614;
  int32_T c2_if_metric[3];
  int32_T c2_i615;
  c2_emxArray_real32_T *c2_jf_metric;
  int32_T c2_iv156[3];
  int32_T c2_kf_metric[1];
  int32_T c2_i616;
  int32_T c2_se_loop_ub;
  int32_T c2_i617;
  c2_emxArray_real32_T *c2_lf_metric;
  int32_T c2_iv157[3];
  int32_T c2_iv158[3];
  int32_T c2_i618;
  int32_T c2_te_loop_ub;
  int32_T c2_i619;
  int32_T c2_i620;
  int32_T c2_mf_metric[3];
  int32_T c2_iv159[3];
  int32_T c2_iv160[3];
  int32_T c2_i621;
  int32_T c2_ue_loop_ub;
  int32_T c2_i622;
  int32_T c2_i623;
  int32_T c2_i624;
  int32_T c2_iv161[3];
  int32_T c2_iv162[3];
  int32_T c2_i625;
  c2_emxArray_real32_T *c2_nf_metric;
  int32_T c2_iv163[3];
  int32_T c2_of_metric[1];
  int32_T c2_i626;
  int32_T c2_ve_loop_ub;
  int32_T c2_i627;
  c2_emxArray_real32_T *c2_pf_metric;
  int32_T c2_iv164[3];
  int32_T c2_iv165[3];
  int32_T c2_i628;
  int32_T c2_we_loop_ub;
  int32_T c2_i629;
  int32_T c2_i630;
  int32_T c2_qf_metric[3];
  int32_T c2_iv166[3];
  int32_T c2_iv167[3];
  int32_T c2_iv168[3];
  int32_T c2_iv169[3];
  int32_T c2_iv170[3];
  int32_T c2_iv171[3];
  int32_T c2_i631;
  int32_T c2_xe_loop_ub;
  int32_T c2_i632;
  int32_T c2_i633;
  int32_T c2_i634;
  int32_T c2_b_dx2[3];
  int32_T c2_b_dy2[3];
  int32_T c2_i635;
  int32_T c2_i636;
  int32_T c2_i637;
  int32_T c2_i638;
  int32_T c2_ye_loop_ub;
  int32_T c2_i639;
  int32_T c2_i640;
  int32_T c2_i641;
  int32_T c2_iv172[3];
  int32_T c2_f_xp1[3];
  int32_T c2_i642;
  int32_T c2_f_xm1;
  int32_T c2_g_xm1;
  int32_T c2_h_xm1;
  int32_T c2_af_loop_ub;
  int32_T c2_i643;
  int32_T c2_i644;
  int32_T c2_i645;
  int32_T c2_i646;
  int32_T c2_i647;
  int32_T c2_i648;
  int32_T c2_i649;
  int32_T c2_i650;
  int32_T c2_bf_loop_ub;
  int32_T c2_i651;
  int32_T c2_i652;
  int32_T c2_i653;
  int32_T c2_i_xm1[3];
  int32_T c2_iv173[3];
  int32_T c2_i654;
  int32_T c2_j_xm1;
  int32_T c2_k_xm1;
  int32_T c2_l_xm1;
  int32_T c2_m_xm1;
  int32_T c2_n_xm1;
  int32_T c2_o_xm1;
  int32_T c2_cf_loop_ub;
  int32_T c2_i655;
  int32_T c2_i656;
  int32_T c2_i657;
  int32_T c2_c_dy2[3];
  int32_T c2_e_ym1[3];
  int32_T c2_i658;
  int32_T c2_i659;
  int32_T c2_i660;
  int32_T c2_i661;
  int32_T c2_df_loop_ub;
  int32_T c2_i662;
  int32_T c2_i663;
  int32_T c2_i664;
  int32_T c2_iv174[3];
  int32_T c2_e_yp1[3];
  int32_T c2_i665;
  int32_T c2_d_dy2;
  int32_T c2_e_dy2;
  int32_T c2_f_dy2;
  int32_T c2_g_dy2;
  int32_T c2_h_dy2;
  int32_T c2_i_dy2;
  int32_T c2_ef_loop_ub;
  int32_T c2_i666;
  int32_T c2_i667;
  int32_T c2_i668;
  int32_T c2_i669;
  int32_T c2_i670;
  int32_T c2_i671;
  int32_T c2_i672;
  int32_T c2_i673;
  int32_T c2_ff_loop_ub;
  int32_T c2_i674;
  int32_T c2_i675;
  int32_T c2_i676;
  int32_T c2_j_dy2[3];
  int32_T c2_iv175[3];
  int32_T c2_i677;
  int32_T c2_k_dy2;
  int32_T c2_l_dy2;
  int32_T c2_m_dy2;
  int32_T c2_n_dy2;
  int32_T c2_o_dy2;
  int32_T c2_p_dy2;
  int32_T c2_gf_loop_ub;
  int32_T c2_i678;
  int32_T c2_i679;
  int32_T c2_i680;
  int32_T c2_q_dy2[3];
  int32_T c2_p_xm1[3];
  int32_T c2_i681;
  int32_T c2_r_dy2;
  int32_T c2_s_dy2;
  int32_T c2_t_dy2;
  int32_T c2_u_dy2;
  int32_T c2_v_dy2;
  int32_T c2_w_dy2;
  int32_T c2_hf_loop_ub;
  int32_T c2_i682;
  int32_T c2_i683;
  int32_T c2_i684;
  int32_T c2_c_dx2[3];
  int32_T c2_f_yp1[3];
  int32_T c2_i685;
  int32_T c2_g_xp1;
  int32_T c2_h_xp1;
  int32_T c2_i_xp1;
  int32_T c2_j_xp1;
  int32_T c2_k_xp1;
  int32_T c2_l_xp1;
  int32_T c2_if_loop_ub;
  int32_T c2_i686;
  int32_T c2_i687;
  int32_T c2_i688;
  int32_T c2_m_xp1[3];
  int32_T c2_f_ym1[3];
  int32_T c2_i689;
  int32_T c2_d_dx2;
  int32_T c2_e_dx2;
  int32_T c2_f_dx2;
  int32_T c2_g_dx2;
  int32_T c2_h_dx2;
  int32_T c2_i_dx2;
  int32_T c2_jf_loop_ub;
  int32_T c2_i690;
  int32_T c2_i691;
  int32_T c2_n_xp1;
  int32_T c2_o_xp1;
  int32_T c2_p_xp1;
  int32_T c2_q_xp1;
  int32_T c2_r_xp1;
  int32_T c2_s_xp1;
  int32_T c2_kf_loop_ub;
  int32_T c2_i692;
  int32_T c2_i693;
  int32_T c2_i694;
  int32_T c2_j_dx2[3];
  int32_T c2_t_xp1[3];
  int32_T c2_i695;
  int32_T c2_k_dx2;
  int32_T c2_l_dx2;
  int32_T c2_m_dx2;
  int32_T c2_n_dx2;
  int32_T c2_o_dx2;
  int32_T c2_p_dx2;
  int32_T c2_lf_loop_ub;
  int32_T c2_i696;
  int32_T c2_i697;
  int32_T c2_i698;
  int32_T c2_q_dx2[3];
  int32_T c2_q_xm1[3];
  int32_T c2_i699;
  int32_T c2_r_dx2;
  int32_T c2_s_dx2;
  int32_T c2_t_dx2;
  int32_T c2_u_dx2;
  int32_T c2_v_dx2;
  int32_T c2_w_dx2;
  int32_T c2_mf_loop_ub;
  int32_T c2_i700;
  c2_emxArray_real32_T *c2_x_dy2;
  int32_T c2_i701;
  int32_T c2_y_dy2;
  int32_T c2_ab_dy2;
  int32_T c2_bb_dy2;
  int32_T c2_nf_loop_ub;
  int32_T c2_i702;
  c2_emxArray_boolean_T *c2_r12;
  int32_T c2_i703;
  int32_T c2_i704;
  int32_T c2_i705;
  int32_T c2_i706;
  int32_T c2_of_loop_ub;
  int32_T c2_i707;
  c2_emxArray_real32_T *c2_x_dx2;
  int32_T c2_i708;
  int32_T c2_y_dx2;
  int32_T c2_ab_dx2;
  int32_T c2_bb_dx2;
  int32_T c2_pf_loop_ub;
  int32_T c2_i709;
  c2_emxArray_boolean_T *c2_r13;
  int32_T c2_i710;
  int32_T c2_i711;
  int32_T c2_i712;
  int32_T c2_i713;
  int32_T c2_qf_loop_ub;
  int32_T c2_i714;
  int32_T c2_i715;
  int32_T c2_i716;
  int32_T c2_iv176[3];
  c2_emxArray_boolean_T *c2_r14;
  int32_T c2_iv177[3];
  int32_T c2_i717;
  int32_T c2_i718;
  int32_T c2_i719;
  int32_T c2_i720;
  int32_T c2_rf_loop_ub;
  int32_T c2_i721;
  int32_T c2_i;
  int32_T c2_i722;
  int32_T c2_i723;
  int32_T c2_i724;
  int32_T c2_i725;
  int32_T c2_sf_loop_ub;
  int32_T c2_i726;
  int32_T c2_b_i;
  boolean_T c2_b19;
  const mxArray *c2_y_y = NULL;
  static char_T c2_cv35[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a', 't',
    'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i', 'm',
    'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  const mxArray *c2_ab_y = NULL;
  int32_T c2_i727;
  int32_T c2_tf_loop_ub;
  int32_T c2_i728;
  int32_T c2_uf_loop_ub;
  int32_T c2_i729;
  int32_T c2_i730;
  int32_T c2_i731;
  int32_T c2_b_subPixelLoc[3];
  int32_T c2_b_loc[3];
  int32_T c2_i732;
  int32_T c2_c_subPixelLoc;
  int32_T c2_d_subPixelLoc;
  int32_T c2_e_subPixelLoc;
  int32_T c2_f_subPixelLoc;
  int32_T c2_g_subPixelLoc;
  int32_T c2_h_subPixelLoc;
  int32_T c2_vf_loop_ub;
  int32_T c2_i733;
  c2_emxInit_real32_T2(chartInstance, &c2_dy2, 3, &c2_lf_emlrtRTEI);
  c2_dv3[0] = 3.0;
  c2_dv3[1] = 3.0;
  c2_dv3[2] = (real_T)c2_loc->size[2];
  c2_i330 = c2_loc->size[2];
  c2_i331 = c2_dy2->size[0] * c2_dy2->size[1] * c2_dy2->size[2];
  c2_dy2->size[0] = 1;
  c2_dy2->size[1] = 1;
  c2_dy2->size[2] = c2_i330;
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_dy2, c2_i331,
    &c2_de_emlrtRTEI);
  c2_loop_ub = c2_i330 - 1;
  for (c2_i332 = 0; c2_i332 <= c2_loop_ub; c2_i332++) {
    c2_dy2->data[c2_dy2->size[0] * c2_dy2->size[1] * c2_i332] = c2_loc->
      data[c2_loc->size[0] * c2_loc->size[1] * c2_i332];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_dx2, 3, &c2_af_emlrtRTEI);
  c2_i333 = c2_loc->size[2];
  c2_i334 = c2_dx2->size[0] * c2_dx2->size[1] * c2_dx2->size[2];
  c2_dx2->size[0] = 1;
  c2_dx2->size[1] = 1;
  c2_dx2->size[2] = c2_i333;
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_dx2, c2_i334,
    &c2_ee_emlrtRTEI);
  c2_b_loop_ub = c2_i333 - 1;
  for (c2_i335 = 0; c2_i335 <= c2_b_loop_ub; c2_i335++) {
    c2_dx2->data[c2_dx2->size[0] * c2_dx2->size[1] * c2_i335] = c2_loc->data[1 +
      c2_loc->size[0] * c2_loc->size[1] * c2_i335];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_xm1, 3, &c2_fe_emlrtRTEI);
  c2_i336 = c2_xm1->size[0] * c2_xm1->size[1] * c2_xm1->size[2];
  c2_xm1->size[0] = 1;
  c2_xm1->size[1] = 1;
  c2_xm1->size[2] = c2_dy2->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_xm1, c2_i336,
    &c2_fe_emlrtRTEI);
  c2_b_xm1 = c2_xm1->size[0];
  c2_c_xm1 = c2_xm1->size[1];
  c2_d_xm1 = c2_xm1->size[2];
  c2_c_loop_ub = c2_dy2->size[0] * c2_dy2->size[1] * c2_dy2->size[2] - 1;
  for (c2_i337 = 0; c2_i337 <= c2_c_loop_ub; c2_i337++) {
    c2_xm1->data[c2_i337] = c2_dy2->data[c2_i337] - 1.0F;
  }

  c2_emxInit_real32_T2(chartInstance, &c2_xp1, 3, &c2_ge_emlrtRTEI);
  c2_i338 = c2_xp1->size[0] * c2_xp1->size[1] * c2_xp1->size[2];
  c2_xp1->size[0] = 1;
  c2_xp1->size[1] = 1;
  c2_xp1->size[2] = c2_dy2->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_xp1, c2_i338,
    &c2_ge_emlrtRTEI);
  c2_b_xp1 = c2_xp1->size[0];
  c2_c_xp1 = c2_xp1->size[1];
  c2_d_xp1 = c2_xp1->size[2];
  c2_d_loop_ub = c2_dy2->size[0] * c2_dy2->size[1] * c2_dy2->size[2] - 1;
  for (c2_i339 = 0; c2_i339 <= c2_d_loop_ub; c2_i339++) {
    c2_xp1->data[c2_i339] = c2_dy2->data[c2_i339] + 1.0F;
  }

  c2_emxInit_real32_T2(chartInstance, &c2_ym1, 3, &c2_he_emlrtRTEI);
  c2_i340 = c2_ym1->size[0] * c2_ym1->size[1] * c2_ym1->size[2];
  c2_ym1->size[0] = 1;
  c2_ym1->size[1] = 1;
  c2_ym1->size[2] = c2_dx2->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_ym1, c2_i340,
    &c2_he_emlrtRTEI);
  c2_b_ym1 = c2_ym1->size[0];
  c2_c_ym1 = c2_ym1->size[1];
  c2_d_ym1 = c2_ym1->size[2];
  c2_e_loop_ub = c2_dx2->size[0] * c2_dx2->size[1] * c2_dx2->size[2] - 1;
  for (c2_i341 = 0; c2_i341 <= c2_e_loop_ub; c2_i341++) {
    c2_ym1->data[c2_i341] = c2_dx2->data[c2_i341] - 1.0F;
  }

  c2_emxInit_real32_T2(chartInstance, &c2_yp1, 3, &c2_ie_emlrtRTEI);
  c2_i342 = c2_yp1->size[0] * c2_yp1->size[1] * c2_yp1->size[2];
  c2_yp1->size[0] = 1;
  c2_yp1->size[1] = 1;
  c2_yp1->size[2] = c2_dx2->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_yp1, c2_i342,
    &c2_ie_emlrtRTEI);
  c2_b_yp1 = c2_yp1->size[0];
  c2_c_yp1 = c2_yp1->size[1];
  c2_d_yp1 = c2_yp1->size[2];
  c2_f_loop_ub = c2_dx2->size[0] * c2_dx2->size[1] * c2_dx2->size[2] - 1;
  for (c2_i343 = 0; c2_i343 <= c2_f_loop_ub; c2_i343++) {
    c2_yp1->data[c2_i343] = c2_dx2->data[c2_i343] + 1.0F;
  }

  c2_emxInit_real32_T2(chartInstance, &c2_result, 3, &c2_bh_emlrtRTEI);
  c2_b11 = true;
  if (c2_b11) {
  } else {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv27, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_y));
  }

  c2_i344 = c2_loc->size[2];
  if (c2_i344 == c2_xm1->size[2]) {
  } else {
    c2_b11 = false;
  }

  if (c2_b11) {
  } else {
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv27, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_b_y));
  }

  c2_b11 = (c2_xp1->size[2] == c2_xm1->size[2]);
  if (c2_b11) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv27, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_c_y));
  }

  c2_i345 = c2_result->size[0] * c2_result->size[1] * c2_result->size[2];
  c2_result->size[0] = 1;
  c2_result->size[1] = 3;
  c2_result->size[2] = c2_xm1->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_result, c2_i345,
    &c2_je_emlrtRTEI);
  c2_g_loop_ub = c2_xm1->size[2] - 1;
  for (c2_i346 = 0; c2_i346 <= c2_g_loop_ub; c2_i346++) {
    c2_result->data[c2_result->size[0] * c2_result->size[1] * c2_i346] =
      c2_xm1->data[c2_xm1->size[0] * c2_xm1->size[1] * c2_i346];
  }

  c2_h_loop_ub = c2_dy2->size[2] - 1;
  for (c2_i347 = 0; c2_i347 <= c2_h_loop_ub; c2_i347++) {
    c2_result->data[c2_result->size[0] + c2_result->size[0] * c2_result->size[1]
      * c2_i347] = c2_dy2->data[c2_dy2->size[0] * c2_dy2->size[1] * c2_i347];
  }

  c2_i_loop_ub = c2_xp1->size[2] - 1;
  for (c2_i348 = 0; c2_i348 <= c2_i_loop_ub; c2_i348++) {
    c2_result->data[(c2_result->size[0] << 1) + c2_result->size[0] *
      c2_result->size[1] * c2_i348] = c2_xp1->data[c2_xp1->size[0] *
      c2_xp1->size[1] * c2_i348];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_b_result, 3, &c2_ch_emlrtRTEI);
  c2_b12 = true;
  if (c2_b12) {
  } else {
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv28, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_d_y));
  }

  c2_i349 = c2_loc->size[2];
  if (c2_i349 == c2_xm1->size[2]) {
  } else {
    c2_b12 = false;
  }

  if (c2_b12) {
  } else {
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv28, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_e_y));
  }

  c2_b12 = (c2_xp1->size[2] == c2_xm1->size[2]);
  if (c2_b12) {
  } else {
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv28, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_f_y));
  }

  c2_i350 = c2_b_result->size[0] * c2_b_result->size[1] * c2_b_result->size[2];
  c2_b_result->size[0] = 1;
  c2_b_result->size[1] = 3;
  c2_b_result->size[2] = c2_xm1->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_b_result, c2_i350,
    &c2_je_emlrtRTEI);
  c2_j_loop_ub = c2_xm1->size[2] - 1;
  for (c2_i351 = 0; c2_i351 <= c2_j_loop_ub; c2_i351++) {
    c2_b_result->data[c2_b_result->size[0] * c2_b_result->size[1] * c2_i351] =
      c2_xm1->data[c2_xm1->size[0] * c2_xm1->size[1] * c2_i351];
  }

  c2_k_loop_ub = c2_dy2->size[2] - 1;
  for (c2_i352 = 0; c2_i352 <= c2_k_loop_ub; c2_i352++) {
    c2_b_result->data[c2_b_result->size[0] + c2_b_result->size[0] *
      c2_b_result->size[1] * c2_i352] = c2_dy2->data[c2_dy2->size[0] *
      c2_dy2->size[1] * c2_i352];
  }

  c2_l_loop_ub = c2_xp1->size[2] - 1;
  for (c2_i353 = 0; c2_i353 <= c2_l_loop_ub; c2_i353++) {
    c2_b_result->data[(c2_b_result->size[0] << 1) + c2_b_result->size[0] *
      c2_b_result->size[1] * c2_i353] = c2_xp1->data[c2_xp1->size[0] *
      c2_xp1->size[1] * c2_i353];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_c_result, 3, &c2_dh_emlrtRTEI);
  c2_b13 = true;
  if (c2_b13) {
  } else {
    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_cv29, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_g_y));
  }

  c2_i354 = c2_loc->size[2];
  if (c2_i354 == c2_xm1->size[2]) {
  } else {
    c2_b13 = false;
  }

  if (c2_b13) {
  } else {
    c2_h_y = NULL;
    sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_cv29, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_h_y));
  }

  c2_b13 = (c2_xp1->size[2] == c2_xm1->size[2]);
  if (c2_b13) {
  } else {
    c2_i_y = NULL;
    sf_mex_assign(&c2_i_y, sf_mex_create("y", c2_cv29, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_i_y));
  }

  c2_i355 = c2_c_result->size[0] * c2_c_result->size[1] * c2_c_result->size[2];
  c2_c_result->size[0] = 1;
  c2_c_result->size[1] = 3;
  c2_c_result->size[2] = c2_xm1->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_c_result, c2_i355,
    &c2_je_emlrtRTEI);
  c2_m_loop_ub = c2_xm1->size[2] - 1;
  for (c2_i356 = 0; c2_i356 <= c2_m_loop_ub; c2_i356++) {
    c2_c_result->data[c2_c_result->size[0] * c2_c_result->size[1] * c2_i356] =
      c2_xm1->data[c2_xm1->size[0] * c2_xm1->size[1] * c2_i356];
  }

  c2_n_loop_ub = c2_dy2->size[2] - 1;
  for (c2_i357 = 0; c2_i357 <= c2_n_loop_ub; c2_i357++) {
    c2_c_result->data[c2_c_result->size[0] + c2_c_result->size[0] *
      c2_c_result->size[1] * c2_i357] = c2_dy2->data[c2_dy2->size[0] *
      c2_dy2->size[1] * c2_i357];
  }

  c2_o_loop_ub = c2_xp1->size[2] - 1;
  for (c2_i358 = 0; c2_i358 <= c2_o_loop_ub; c2_i358++) {
    c2_c_result->data[(c2_c_result->size[0] << 1) + c2_c_result->size[0] *
      c2_c_result->size[1] * c2_i358] = c2_xp1->data[c2_xp1->size[0] *
      c2_xp1->size[1] * c2_i358];
  }

  c2_b14 = true;
  if (c2_b14) {
  } else {
    c2_j_y = NULL;
    sf_mex_assign(&c2_j_y, sf_mex_create("y", c2_cv30, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_j_y));
  }

  if (c2_b_result->size[2] == c2_result->size[2]) {
  } else {
    c2_b14 = false;
  }

  if (c2_b14) {
  } else {
    c2_k_y = NULL;
    sf_mex_assign(&c2_k_y, sf_mex_create("y", c2_cv30, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_k_y));
  }

  c2_b14 = (c2_c_result->size[2] == c2_result->size[2]);
  if (c2_b14) {
  } else {
    c2_l_y = NULL;
    sf_mex_assign(&c2_l_y, sf_mex_create("y", c2_cv30, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_l_y));
  }

  c2_emxInit_real32_T2(chartInstance, &c2_xsubs, 3, &c2_ke_emlrtRTEI);
  c2_i359 = c2_xsubs->size[0] * c2_xsubs->size[1] * c2_xsubs->size[2];
  c2_xsubs->size[0] = 3;
  c2_xsubs->size[1] = 3;
  c2_xsubs->size[2] = c2_result->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_xsubs, c2_i359,
    &c2_ke_emlrtRTEI);
  c2_p_loop_ub = c2_result->size[2] - 1;
  for (c2_i360 = 0; c2_i360 <= c2_p_loop_ub; c2_i360++) {
    for (c2_i361 = 0; c2_i361 < 3; c2_i361++) {
      c2_xsubs->data[c2_xsubs->size[0] * c2_i361 + c2_xsubs->size[0] *
        c2_xsubs->size[1] * c2_i360] = c2_result->data[c2_result->size[0] *
        c2_i361 + c2_result->size[0] * c2_result->size[1] * c2_i360];
    }
  }

  c2_q_loop_ub = c2_b_result->size[2] - 1;
  for (c2_i362 = 0; c2_i362 <= c2_q_loop_ub; c2_i362++) {
    for (c2_i363 = 0; c2_i363 < 3; c2_i363++) {
      c2_xsubs->data[(c2_xsubs->size[0] * c2_i363 + c2_xsubs->size[0] *
                      c2_xsubs->size[1] * c2_i362) + 1] = c2_b_result->
        data[c2_b_result->size[0] * c2_i363 + c2_b_result->size[0] *
        c2_b_result->size[1] * c2_i362];
    }
  }

  c2_r_loop_ub = c2_c_result->size[2] - 1;
  for (c2_i364 = 0; c2_i364 <= c2_r_loop_ub; c2_i364++) {
    for (c2_i365 = 0; c2_i365 < 3; c2_i365++) {
      c2_xsubs->data[(c2_xsubs->size[0] * c2_i365 + c2_xsubs->size[0] *
                      c2_xsubs->size[1] * c2_i364) + 2] = c2_c_result->
        data[c2_c_result->size[0] * c2_i365 + c2_c_result->size[0] *
        c2_c_result->size[1] * c2_i364];
    }
  }

  c2_b15 = true;
  if (c2_b15) {
  } else {
    c2_m_y = NULL;
    sf_mex_assign(&c2_m_y, sf_mex_create("y", c2_cv31, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_m_y));
  }

  if (c2_b15) {
  } else {
    c2_n_y = NULL;
    sf_mex_assign(&c2_n_y, sf_mex_create("y", c2_cv31, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_n_y));
  }

  if (c2_b15) {
  } else {
    c2_o_y = NULL;
    sf_mex_assign(&c2_o_y, sf_mex_create("y", c2_cv31, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_o_y));
  }

  c2_i366 = c2_result->size[0] * c2_result->size[1] * c2_result->size[2];
  c2_result->size[0] = 1;
  c2_result->size[1] = 3;
  c2_result->size[2] = c2_ym1->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_result, c2_i366,
    &c2_je_emlrtRTEI);
  c2_s_loop_ub = c2_ym1->size[2] - 1;
  for (c2_i367 = 0; c2_i367 <= c2_s_loop_ub; c2_i367++) {
    c2_result->data[c2_result->size[0] * c2_result->size[1] * c2_i367] =
      c2_ym1->data[c2_ym1->size[0] * c2_ym1->size[1] * c2_i367];
  }

  c2_t_loop_ub = c2_ym1->size[2] - 1;
  for (c2_i368 = 0; c2_i368 <= c2_t_loop_ub; c2_i368++) {
    c2_result->data[c2_result->size[0] + c2_result->size[0] * c2_result->size[1]
      * c2_i368] = c2_ym1->data[c2_ym1->size[0] * c2_ym1->size[1] * c2_i368];
  }

  c2_u_loop_ub = c2_ym1->size[2] - 1;
  for (c2_i369 = 0; c2_i369 <= c2_u_loop_ub; c2_i369++) {
    c2_result->data[(c2_result->size[0] << 1) + c2_result->size[0] *
      c2_result->size[1] * c2_i369] = c2_ym1->data[c2_ym1->size[0] *
      c2_ym1->size[1] * c2_i369];
  }

  c2_b16 = true;
  if (c2_b16) {
  } else {
    c2_p_y = NULL;
    sf_mex_assign(&c2_p_y, sf_mex_create("y", c2_cv32, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_p_y));
  }

  if (c2_b16) {
  } else {
    c2_q_y = NULL;
    sf_mex_assign(&c2_q_y, sf_mex_create("y", c2_cv32, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_q_y));
  }

  if (c2_b16) {
  } else {
    c2_r_y = NULL;
    sf_mex_assign(&c2_r_y, sf_mex_create("y", c2_cv32, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_r_y));
  }

  c2_i370 = c2_b_result->size[0] * c2_b_result->size[1] * c2_b_result->size[2];
  c2_b_result->size[0] = 1;
  c2_b_result->size[1] = 3;
  c2_b_result->size[2] = c2_dx2->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_b_result, c2_i370,
    &c2_je_emlrtRTEI);
  c2_v_loop_ub = c2_dx2->size[2] - 1;
  for (c2_i371 = 0; c2_i371 <= c2_v_loop_ub; c2_i371++) {
    c2_b_result->data[c2_b_result->size[0] * c2_b_result->size[1] * c2_i371] =
      c2_dx2->data[c2_dx2->size[0] * c2_dx2->size[1] * c2_i371];
  }

  c2_w_loop_ub = c2_dx2->size[2] - 1;
  for (c2_i372 = 0; c2_i372 <= c2_w_loop_ub; c2_i372++) {
    c2_b_result->data[c2_b_result->size[0] + c2_b_result->size[0] *
      c2_b_result->size[1] * c2_i372] = c2_dx2->data[c2_dx2->size[0] *
      c2_dx2->size[1] * c2_i372];
  }

  c2_x_loop_ub = c2_dx2->size[2] - 1;
  for (c2_i373 = 0; c2_i373 <= c2_x_loop_ub; c2_i373++) {
    c2_b_result->data[(c2_b_result->size[0] << 1) + c2_b_result->size[0] *
      c2_b_result->size[1] * c2_i373] = c2_dx2->data[c2_dx2->size[0] *
      c2_dx2->size[1] * c2_i373];
  }

  c2_b17 = true;
  if (c2_b17) {
  } else {
    c2_s_y = NULL;
    sf_mex_assign(&c2_s_y, sf_mex_create("y", c2_cv33, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_s_y));
  }

  if (c2_b17) {
  } else {
    c2_t_y = NULL;
    sf_mex_assign(&c2_t_y, sf_mex_create("y", c2_cv33, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_t_y));
  }

  if (c2_b17) {
  } else {
    c2_u_y = NULL;
    sf_mex_assign(&c2_u_y, sf_mex_create("y", c2_cv33, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_u_y));
  }

  c2_i374 = c2_c_result->size[0] * c2_c_result->size[1] * c2_c_result->size[2];
  c2_c_result->size[0] = 1;
  c2_c_result->size[1] = 3;
  c2_c_result->size[2] = c2_yp1->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_c_result, c2_i374,
    &c2_je_emlrtRTEI);
  c2_y_loop_ub = c2_yp1->size[2] - 1;
  for (c2_i375 = 0; c2_i375 <= c2_y_loop_ub; c2_i375++) {
    c2_c_result->data[c2_c_result->size[0] * c2_c_result->size[1] * c2_i375] =
      c2_yp1->data[c2_yp1->size[0] * c2_yp1->size[1] * c2_i375];
  }

  c2_ab_loop_ub = c2_yp1->size[2] - 1;
  for (c2_i376 = 0; c2_i376 <= c2_ab_loop_ub; c2_i376++) {
    c2_c_result->data[c2_c_result->size[0] + c2_c_result->size[0] *
      c2_c_result->size[1] * c2_i376] = c2_yp1->data[c2_yp1->size[0] *
      c2_yp1->size[1] * c2_i376];
  }

  c2_bb_loop_ub = c2_yp1->size[2] - 1;
  for (c2_i377 = 0; c2_i377 <= c2_bb_loop_ub; c2_i377++) {
    c2_c_result->data[(c2_c_result->size[0] << 1) + c2_c_result->size[0] *
      c2_c_result->size[1] * c2_i377] = c2_yp1->data[c2_yp1->size[0] *
      c2_yp1->size[1] * c2_i377];
  }

  c2_b18 = true;
  if (c2_b18) {
  } else {
    c2_v_y = NULL;
    sf_mex_assign(&c2_v_y, sf_mex_create("y", c2_cv34, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_v_y));
  }

  if (c2_b_result->size[2] == c2_result->size[2]) {
  } else {
    c2_b18 = false;
  }

  if (c2_b18) {
  } else {
    c2_w_y = NULL;
    sf_mex_assign(&c2_w_y, sf_mex_create("y", c2_cv34, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_w_y));
  }

  c2_b18 = (c2_c_result->size[2] == c2_result->size[2]);
  if (c2_b18) {
  } else {
    c2_x_y = NULL;
    sf_mex_assign(&c2_x_y, sf_mex_create("y", c2_cv34, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_x_y));
  }

  c2_emxInit_real32_T2(chartInstance, &c2_ysubs, 3, &c2_le_emlrtRTEI);
  c2_i378 = c2_ysubs->size[0] * c2_ysubs->size[1] * c2_ysubs->size[2];
  c2_ysubs->size[0] = 3;
  c2_ysubs->size[1] = 3;
  c2_ysubs->size[2] = c2_result->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_ysubs, c2_i378,
    &c2_le_emlrtRTEI);
  c2_cb_loop_ub = c2_result->size[2] - 1;
  for (c2_i379 = 0; c2_i379 <= c2_cb_loop_ub; c2_i379++) {
    for (c2_i380 = 0; c2_i380 < 3; c2_i380++) {
      c2_ysubs->data[c2_ysubs->size[0] * c2_i380 + c2_ysubs->size[0] *
        c2_ysubs->size[1] * c2_i379] = c2_result->data[c2_result->size[0] *
        c2_i380 + c2_result->size[0] * c2_result->size[1] * c2_i379];
    }
  }

  c2_emxFree_real32_T(chartInstance, &c2_result);
  c2_db_loop_ub = c2_b_result->size[2] - 1;
  for (c2_i381 = 0; c2_i381 <= c2_db_loop_ub; c2_i381++) {
    for (c2_i382 = 0; c2_i382 < 3; c2_i382++) {
      c2_ysubs->data[(c2_ysubs->size[0] * c2_i382 + c2_ysubs->size[0] *
                      c2_ysubs->size[1] * c2_i381) + 1] = c2_b_result->
        data[c2_b_result->size[0] * c2_i382 + c2_b_result->size[0] *
        c2_b_result->size[1] * c2_i381];
    }
  }

  c2_emxFree_real32_T(chartInstance, &c2_b_result);
  c2_eb_loop_ub = c2_c_result->size[2] - 1;
  for (c2_i383 = 0; c2_i383 <= c2_eb_loop_ub; c2_i383++) {
    for (c2_i384 = 0; c2_i384 < 3; c2_i384++) {
      c2_ysubs->data[(c2_ysubs->size[0] * c2_i384 + c2_ysubs->size[0] *
                      c2_ysubs->size[1] * c2_i383) + 2] = c2_c_result->
        data[c2_c_result->size[0] * c2_i384 + c2_c_result->size[0] *
        c2_c_result->size[1] * c2_i383];
    }
  }

  c2_emxFree_real32_T(chartInstance, &c2_c_result);
  c2_emxInit_int32_T(chartInstance, &c2_idx, 1, &c2_eh_emlrtRTEI);
  for (c2_i385 = 0; c2_i385 < 2; c2_i385++) {
    c2_siz[c2_i385] = c2_metric->size[c2_i385];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_b_ysubs, 1, &c2_me_emlrtRTEI);
  c2_i386 = c2_b_ysubs->size[0];
  c2_b_ysubs->size[0] = 9 * c2_ysubs->size[2];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_b_ysubs, c2_i386,
    &c2_me_emlrtRTEI);
  c2_fb_loop_ub = 9 * c2_ysubs->size[2] - 1;
  for (c2_i387 = 0; c2_i387 <= c2_fb_loop_ub; c2_i387++) {
    c2_b_ysubs->data[c2_i387] = c2_ysubs->data[c2_i387];
  }

  if (c2_b_allinrange(chartInstance, c2_b_ysubs, 1.0, c2_siz[0])) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_emlrt_marshallOut(chartInstance, c2_cv3)));
  }

  c2_emxFree_real32_T(chartInstance, &c2_b_ysubs);
  c2_dv4[0] = (real_T)(9 * c2_ysubs->size[2]);
  c2_dv4[1] = 1.0;
  c2_dv5[0] = (real_T)(9 * c2_xsubs->size[2]);
  c2_dv5[1] = 1.0;
  if (c2_b_isequal(chartInstance, c2_dv4, c2_dv5)) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_b_emlrt_marshallOut(chartInstance, c2_cv4)));
  }

  for (c2_i388 = 0; c2_i388 < 2; c2_i388++) {
    c2_b_siz[c2_i388] = c2_siz[c2_i388];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_b_xsubs, 1, &c2_ne_emlrtRTEI);
  c2_i389 = c2_b_xsubs->size[0];
  c2_b_xsubs->size[0] = 9 * c2_xsubs->size[2];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_b_xsubs, c2_i389,
    &c2_ne_emlrtRTEI);
  c2_gb_loop_ub = 9 * c2_xsubs->size[2] - 1;
  for (c2_i390 = 0; c2_i390 <= c2_gb_loop_ub; c2_i390++) {
    c2_b_xsubs->data[c2_i390] = c2_xsubs->data[c2_i390];
  }

  if (c2_b_allinrange(chartInstance, c2_b_xsubs, 1.0, c2_prodsub(chartInstance,
        c2_b_siz, 2, 2))) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_emlrt_marshallOut(chartInstance, c2_cv3)));
  }

  c2_emxFree_real32_T(chartInstance, &c2_b_xsubs);
  c2_c_siz = c2_siz[0];
  c2_i391 = c2_idx->size[0];
  c2_idx->size[0] = 9 * c2_ysubs->size[2];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_idx, c2_i391, &c2_oe_emlrtRTEI);
  c2_hb_loop_ub = 9 * c2_ysubs->size[2] - 1;
  for (c2_i392 = 0; c2_i392 <= c2_hb_loop_ub; c2_i392++) {
    c2_idx->data[c2_i392] = (int32_T)c2_ysubs->data[c2_i392] + c2_c_siz *
      ((int32_T)c2_xsubs->data[c2_i392] - 1);
  }

  c2_emxFree_real32_T(chartInstance, &c2_ysubs);
  c2_emxFree_real32_T(chartInstance, &c2_xsubs);
  c2_emxInit_real32_T1(chartInstance, &c2_patch, 1, &c2_ah_emlrtRTEI);
  c2_b_metric = c2_metric->size[0] * c2_metric->size[1];
  c2_i393 = c2_patch->size[0];
  c2_patch->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_patch, c2_i393,
    &c2_pe_emlrtRTEI);
  c2_ib_loop_ub = c2_idx->size[0] - 1;
  for (c2_i394 = 0; c2_i394 <= c2_ib_loop_ub; c2_i394++) {
    c2_patch->data[c2_i394] = c2_metric->data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       c2_idx->data[c2_i394], 1, c2_b_metric) - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_r9, 3, &c2_sg_emlrtRTEI);
  c2_iv12[0] = 3;
  c2_iv12[1] = 3;
  c2_iv12[2] = (int32_T)c2_dv3[2];
  _SFD_SUB_ASSIGN_SIZE_CHECK_1D(9 * c2_iv12[2], c2_idx->size[0]);
  c2_iv13[0] = 3;
  c2_iv13[1] = 3;
  c2_iv13[2] = (int32_T)c2_dv3[2];
  c2_iv14[0] = 3;
  c2_iv14[1] = 3;
  c2_iv14[2] = (int32_T)c2_dv3[2];
  c2_i395 = c2_r9->size[0] * c2_r9->size[1] * c2_r9->size[2];
  c2_r9->size[0] = 1;
  c2_r9->size[1] = 1;
  c2_r9->size[2] = c2_iv14[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_r9, c2_i395, &c2_qe_emlrtRTEI);
  c2_jb_loop_ub = c2_iv14[2] - 1;
  for (c2_i396 = 0; c2_i396 <= c2_jb_loop_ub; c2_i396++) {
    c2_r9->data[c2_r9->size[0] * c2_r9->size[1] * c2_i396] = 2.0F *
      c2_patch->data[c2_iv13[0] + c2_iv13[0] * c2_iv13[1] * c2_i396];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_c_metric, 1, &c2_pe_emlrtRTEI);
  c2_d_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i397 = c2_c_metric->size[0];
  c2_c_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_c_metric, c2_i397,
    &c2_pe_emlrtRTEI);
  c2_kb_loop_ub = c2_idx->size[0] - 1;
  for (c2_i398 = 0; c2_i398 <= c2_kb_loop_ub; c2_i398++) {
    c2_c_metric->data[c2_i398] = c2_metric->data[c2_idx->data[c2_i398] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_e_metric, 3, &c2_re_emlrtRTEI);
  c2_iv15[0] = 3;
  c2_iv15[1] = 3;
  c2_iv15[2] = (int32_T)c2_dv3[2];
  c2_iv16[0] = 3;
  c2_iv16[1] = 3;
  c2_iv16[2] = (int32_T)c2_dv3[2];
  c2_i399 = c2_e_metric->size[0] * c2_e_metric->size[1] * c2_e_metric->size[2];
  c2_e_metric->size[0] = 1;
  c2_e_metric->size[1] = 1;
  c2_e_metric->size[2] = c2_iv16[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_e_metric, c2_i399,
    &c2_re_emlrtRTEI);
  c2_lb_loop_ub = c2_iv16[2] - 1;
  for (c2_i400 = 0; c2_i400 <= c2_lb_loop_ub; c2_i400++) {
    c2_e_metric->data[c2_e_metric->size[0] * c2_e_metric->size[1] * c2_i400] =
      c2_c_metric->data[c2_iv15[0] * c2_iv15[1] * c2_i400];
  }

  c2_emxFree_real32_T(chartInstance, &c2_c_metric);
  for (c2_i401 = 0; c2_i401 < 3; c2_i401++) {
    c2_f_metric[c2_i401] = c2_e_metric->size[c2_i401];
  }

  c2_emxFree_real32_T(chartInstance, &c2_e_metric);
  for (c2_i402 = 0; c2_i402 < 3; c2_i402++) {
    c2_iv17[c2_i402] = c2_r9->size[c2_i402];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_g_metric, 1, &c2_pe_emlrtRTEI);
  _SFD_SIZE_EQ_CHECK_ND(c2_f_metric, c2_iv17, 3);
  c2_h_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i403 = c2_g_metric->size[0];
  c2_g_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_g_metric, c2_i403,
    &c2_pe_emlrtRTEI);
  c2_mb_loop_ub = c2_idx->size[0] - 1;
  for (c2_i404 = 0; c2_i404 <= c2_mb_loop_ub; c2_i404++) {
    c2_g_metric->data[c2_i404] = c2_metric->data[c2_idx->data[c2_i404] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_i_metric, 3, &c2_re_emlrtRTEI);
  c2_iv18[0] = 3;
  c2_iv18[1] = 3;
  c2_iv18[2] = (int32_T)c2_dv3[2];
  c2_iv19[0] = 3;
  c2_iv19[1] = 3;
  c2_iv19[2] = (int32_T)c2_dv3[2];
  c2_i405 = c2_i_metric->size[0] * c2_i_metric->size[1] * c2_i_metric->size[2];
  c2_i_metric->size[0] = 1;
  c2_i_metric->size[1] = 1;
  c2_i_metric->size[2] = c2_iv19[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_i_metric, c2_i405,
    &c2_re_emlrtRTEI);
  c2_nb_loop_ub = c2_iv19[2] - 1;
  for (c2_i406 = 0; c2_i406 <= c2_nb_loop_ub; c2_i406++) {
    c2_i_metric->data[c2_i_metric->size[0] * c2_i_metric->size[1] * c2_i406] =
      c2_g_metric->data[c2_iv18[0] * c2_iv18[1] * c2_i406];
  }

  c2_emxFree_real32_T(chartInstance, &c2_g_metric);
  for (c2_i407 = 0; c2_i407 < 3; c2_i407++) {
    c2_j_metric[c2_i407] = c2_i_metric->size[c2_i407];
  }

  c2_emxFree_real32_T(chartInstance, &c2_i_metric);
  c2_emxInit_real32_T1(chartInstance, &c2_k_metric, 1, &c2_pe_emlrtRTEI);
  c2_l_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i408 = c2_k_metric->size[0];
  c2_k_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_k_metric, c2_i408,
    &c2_pe_emlrtRTEI);
  c2_ob_loop_ub = c2_idx->size[0] - 1;
  for (c2_i409 = 0; c2_i409 <= c2_ob_loop_ub; c2_i409++) {
    c2_k_metric->data[c2_i409] = c2_metric->data[c2_idx->data[c2_i409] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_m_metric, 3, &c2_se_emlrtRTEI);
  c2_iv20[0] = 3;
  c2_iv20[1] = 3;
  c2_iv20[2] = (int32_T)c2_dv3[2];
  c2_iv21[0] = 3;
  c2_iv21[1] = 3;
  c2_iv21[2] = (int32_T)c2_dv3[2];
  c2_i410 = c2_m_metric->size[0] * c2_m_metric->size[1] * c2_m_metric->size[2];
  c2_m_metric->size[0] = 1;
  c2_m_metric->size[1] = 1;
  c2_m_metric->size[2] = c2_iv21[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_m_metric, c2_i410,
    &c2_se_emlrtRTEI);
  c2_pb_loop_ub = c2_iv21[2] - 1;
  for (c2_i411 = 0; c2_i411 <= c2_pb_loop_ub; c2_i411++) {
    c2_m_metric->data[c2_m_metric->size[0] * c2_m_metric->size[1] * c2_i411] =
      c2_k_metric->data[(c2_iv20[0] << 1) + c2_iv20[0] * c2_iv20[1] * c2_i411];
  }

  c2_emxFree_real32_T(chartInstance, &c2_k_metric);
  for (c2_i412 = 0; c2_i412 < 3; c2_i412++) {
    c2_n_metric[c2_i412] = c2_m_metric->size[c2_i412];
  }

  c2_emxFree_real32_T(chartInstance, &c2_m_metric);
  c2_emxInit_real32_T2(chartInstance, &c2_r10, 3, &c2_ah_emlrtRTEI);
  _SFD_SIZE_EQ_CHECK_ND(c2_j_metric, c2_n_metric, 3);
  c2_iv22[0] = 3;
  c2_iv22[1] = 3;
  c2_iv22[2] = (int32_T)c2_dv3[2];
  c2_iv23[0] = 3;
  c2_iv23[1] = 3;
  c2_iv23[2] = (int32_T)c2_dv3[2];
  c2_i413 = c2_r10->size[0] * c2_r10->size[1] * c2_r10->size[2];
  c2_r10->size[0] = 1;
  c2_r10->size[1] = 1;
  c2_r10->size[2] = c2_iv23[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_r10, c2_i413,
    &c2_te_emlrtRTEI);
  c2_qb_loop_ub = c2_iv23[2] - 1;
  for (c2_i414 = 0; c2_i414 <= c2_qb_loop_ub; c2_i414++) {
    c2_r10->data[c2_r10->size[0] * c2_r10->size[1] * c2_i414] = 2.0F *
      c2_patch->data[1 + c2_iv22[0] * c2_iv22[1] * c2_i414];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_o_metric, 1, &c2_pe_emlrtRTEI);
  c2_p_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i415 = c2_o_metric->size[0];
  c2_o_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_o_metric, c2_i415,
    &c2_pe_emlrtRTEI);
  c2_rb_loop_ub = c2_idx->size[0] - 1;
  for (c2_i416 = 0; c2_i416 <= c2_rb_loop_ub; c2_i416++) {
    c2_o_metric->data[c2_i416] = c2_metric->data[c2_idx->data[c2_i416] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_q_metric, 3, &c2_re_emlrtRTEI);
  c2_iv24[0] = 3;
  c2_iv24[1] = 3;
  c2_iv24[2] = (int32_T)c2_dv3[2];
  c2_iv25[0] = 3;
  c2_iv25[1] = 3;
  c2_iv25[2] = (int32_T)c2_dv3[2];
  c2_i417 = c2_q_metric->size[0] * c2_q_metric->size[1] * c2_q_metric->size[2];
  c2_q_metric->size[0] = 1;
  c2_q_metric->size[1] = 1;
  c2_q_metric->size[2] = c2_iv25[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_q_metric, c2_i417,
    &c2_re_emlrtRTEI);
  c2_sb_loop_ub = c2_iv25[2] - 1;
  for (c2_i418 = 0; c2_i418 <= c2_sb_loop_ub; c2_i418++) {
    c2_q_metric->data[c2_q_metric->size[0] * c2_q_metric->size[1] * c2_i418] =
      c2_o_metric->data[c2_iv24[0] * c2_iv24[1] * c2_i418];
  }

  c2_emxFree_real32_T(chartInstance, &c2_o_metric);
  for (c2_i419 = 0; c2_i419 < 3; c2_i419++) {
    c2_r_metric[c2_i419] = c2_q_metric->size[c2_i419];
  }

  c2_emxFree_real32_T(chartInstance, &c2_q_metric);
  for (c2_i420 = 0; c2_i420 < 3; c2_i420++) {
    c2_iv26[c2_i420] = c2_r10->size[c2_i420];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_r11, 3, &c2_ah_emlrtRTEI);
  _SFD_SIZE_EQ_CHECK_ND(c2_r_metric, c2_iv26, 3);
  c2_iv27[0] = 3;
  c2_iv27[1] = 3;
  c2_iv27[2] = (int32_T)c2_dv3[2];
  c2_iv28[0] = 3;
  c2_iv28[1] = 3;
  c2_iv28[2] = (int32_T)c2_dv3[2];
  c2_i421 = c2_r11->size[0] * c2_r11->size[1] * c2_r11->size[2];
  c2_r11->size[0] = 1;
  c2_r11->size[1] = 1;
  c2_r11->size[2] = c2_iv28[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_r11, c2_i421,
    &c2_ue_emlrtRTEI);
  c2_tb_loop_ub = c2_iv28[2] - 1;
  for (c2_i422 = 0; c2_i422 <= c2_tb_loop_ub; c2_i422++) {
    c2_r11->data[c2_r11->size[0] * c2_r11->size[1] * c2_i422] = 4.0F *
      c2_patch->data[(c2_iv27[0] + c2_iv27[0] * c2_iv27[1] * c2_i422) + 1];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_s_metric, 1, &c2_pe_emlrtRTEI);
  c2_t_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i423 = c2_s_metric->size[0];
  c2_s_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_s_metric, c2_i423,
    &c2_pe_emlrtRTEI);
  c2_ub_loop_ub = c2_idx->size[0] - 1;
  for (c2_i424 = 0; c2_i424 <= c2_ub_loop_ub; c2_i424++) {
    c2_s_metric->data[c2_i424] = c2_metric->data[c2_idx->data[c2_i424] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_u_metric, 3, &c2_re_emlrtRTEI);
  c2_iv29[0] = 3;
  c2_iv29[1] = 3;
  c2_iv29[2] = (int32_T)c2_dv3[2];
  c2_iv30[0] = 3;
  c2_iv30[1] = 3;
  c2_iv30[2] = (int32_T)c2_dv3[2];
  c2_i425 = c2_u_metric->size[0] * c2_u_metric->size[1] * c2_u_metric->size[2];
  c2_u_metric->size[0] = 1;
  c2_u_metric->size[1] = 1;
  c2_u_metric->size[2] = c2_iv30[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_u_metric, c2_i425,
    &c2_re_emlrtRTEI);
  c2_vb_loop_ub = c2_iv30[2] - 1;
  for (c2_i426 = 0; c2_i426 <= c2_vb_loop_ub; c2_i426++) {
    c2_u_metric->data[c2_u_metric->size[0] * c2_u_metric->size[1] * c2_i426] =
      c2_s_metric->data[c2_iv29[0] * c2_iv29[1] * c2_i426];
  }

  c2_emxFree_real32_T(chartInstance, &c2_s_metric);
  for (c2_i427 = 0; c2_i427 < 3; c2_i427++) {
    c2_v_metric[c2_i427] = c2_u_metric->size[c2_i427];
  }

  c2_emxFree_real32_T(chartInstance, &c2_u_metric);
  for (c2_i428 = 0; c2_i428 < 3; c2_i428++) {
    c2_iv31[c2_i428] = c2_r11->size[c2_i428];
  }

  _SFD_SIZE_EQ_CHECK_ND(c2_v_metric, c2_iv31, 3);
  c2_iv32[0] = 3;
  c2_iv32[1] = 3;
  c2_iv32[2] = (int32_T)c2_dv3[2];
  c2_iv33[0] = 3;
  c2_iv33[1] = 3;
  c2_iv33[2] = (int32_T)c2_dv3[2];
  c2_i429 = c2_xm1->size[0] * c2_xm1->size[1] * c2_xm1->size[2];
  c2_xm1->size[0] = 1;
  c2_xm1->size[1] = 1;
  c2_xm1->size[2] = c2_iv33[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_xm1, c2_i429,
    &c2_ve_emlrtRTEI);
  c2_wb_loop_ub = c2_iv33[2] - 1;
  for (c2_i430 = 0; c2_i430 <= c2_wb_loop_ub; c2_i430++) {
    c2_xm1->data[c2_xm1->size[0] * c2_xm1->size[1] * c2_i430] = 2.0F *
      c2_patch->data[((c2_iv32[0] << 1) + c2_iv32[0] * c2_iv32[1] * c2_i430) + 1];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_w_metric, 1, &c2_pe_emlrtRTEI);
  c2_x_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i431 = c2_w_metric->size[0];
  c2_w_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_w_metric, c2_i431,
    &c2_pe_emlrtRTEI);
  c2_xb_loop_ub = c2_idx->size[0] - 1;
  for (c2_i432 = 0; c2_i432 <= c2_xb_loop_ub; c2_i432++) {
    c2_w_metric->data[c2_i432] = c2_metric->data[c2_idx->data[c2_i432] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_y_metric, 3, &c2_re_emlrtRTEI);
  c2_iv34[0] = 3;
  c2_iv34[1] = 3;
  c2_iv34[2] = (int32_T)c2_dv3[2];
  c2_iv35[0] = 3;
  c2_iv35[1] = 3;
  c2_iv35[2] = (int32_T)c2_dv3[2];
  c2_i433 = c2_y_metric->size[0] * c2_y_metric->size[1] * c2_y_metric->size[2];
  c2_y_metric->size[0] = 1;
  c2_y_metric->size[1] = 1;
  c2_y_metric->size[2] = c2_iv35[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_y_metric, c2_i433,
    &c2_re_emlrtRTEI);
  c2_yb_loop_ub = c2_iv35[2] - 1;
  for (c2_i434 = 0; c2_i434 <= c2_yb_loop_ub; c2_i434++) {
    c2_y_metric->data[c2_y_metric->size[0] * c2_y_metric->size[1] * c2_i434] =
      c2_w_metric->data[c2_iv34[0] * c2_iv34[1] * c2_i434];
  }

  c2_emxFree_real32_T(chartInstance, &c2_w_metric);
  for (c2_i435 = 0; c2_i435 < 3; c2_i435++) {
    c2_ab_metric[c2_i435] = c2_y_metric->size[c2_i435];
  }

  c2_emxFree_real32_T(chartInstance, &c2_y_metric);
  for (c2_i436 = 0; c2_i436 < 3; c2_i436++) {
    c2_e_xm1[c2_i436] = c2_xm1->size[c2_i436];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_bb_metric, 1, &c2_pe_emlrtRTEI);
  _SFD_SIZE_EQ_CHECK_ND(c2_ab_metric, c2_e_xm1, 3);
  c2_cb_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i437 = c2_bb_metric->size[0];
  c2_bb_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_bb_metric, c2_i437,
    &c2_pe_emlrtRTEI);
  c2_ac_loop_ub = c2_idx->size[0] - 1;
  for (c2_i438 = 0; c2_i438 <= c2_ac_loop_ub; c2_i438++) {
    c2_bb_metric->data[c2_i438] = c2_metric->data[c2_idx->data[c2_i438] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_db_metric, 3, &c2_re_emlrtRTEI);
  c2_iv36[0] = 3;
  c2_iv36[1] = 3;
  c2_iv36[2] = (int32_T)c2_dv3[2];
  c2_iv37[0] = 3;
  c2_iv37[1] = 3;
  c2_iv37[2] = (int32_T)c2_dv3[2];
  c2_i439 = c2_db_metric->size[0] * c2_db_metric->size[1] * c2_db_metric->size[2];
  c2_db_metric->size[0] = 1;
  c2_db_metric->size[1] = 1;
  c2_db_metric->size[2] = c2_iv37[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_db_metric, c2_i439,
    &c2_re_emlrtRTEI);
  c2_bc_loop_ub = c2_iv37[2] - 1;
  for (c2_i440 = 0; c2_i440 <= c2_bc_loop_ub; c2_i440++) {
    c2_db_metric->data[c2_db_metric->size[0] * c2_db_metric->size[1] * c2_i440] =
      c2_bb_metric->data[c2_iv36[0] * c2_iv36[1] * c2_i440];
  }

  c2_emxFree_real32_T(chartInstance, &c2_bb_metric);
  for (c2_i441 = 0; c2_i441 < 3; c2_i441++) {
    c2_eb_metric[c2_i441] = c2_db_metric->size[c2_i441];
  }

  c2_emxFree_real32_T(chartInstance, &c2_db_metric);
  c2_emxInit_real32_T1(chartInstance, &c2_fb_metric, 1, &c2_pe_emlrtRTEI);
  c2_gb_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i442 = c2_fb_metric->size[0];
  c2_fb_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_fb_metric, c2_i442,
    &c2_pe_emlrtRTEI);
  c2_cc_loop_ub = c2_idx->size[0] - 1;
  for (c2_i443 = 0; c2_i443 <= c2_cc_loop_ub; c2_i443++) {
    c2_fb_metric->data[c2_i443] = c2_metric->data[c2_idx->data[c2_i443] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_hb_metric, 3, &c2_we_emlrtRTEI);
  c2_iv38[0] = 3;
  c2_iv38[1] = 3;
  c2_iv38[2] = (int32_T)c2_dv3[2];
  c2_iv39[0] = 3;
  c2_iv39[1] = 3;
  c2_iv39[2] = (int32_T)c2_dv3[2];
  c2_i444 = c2_hb_metric->size[0] * c2_hb_metric->size[1] * c2_hb_metric->size[2];
  c2_hb_metric->size[0] = 1;
  c2_hb_metric->size[1] = 1;
  c2_hb_metric->size[2] = c2_iv39[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_hb_metric, c2_i444,
    &c2_we_emlrtRTEI);
  c2_dc_loop_ub = c2_iv39[2] - 1;
  for (c2_i445 = 0; c2_i445 <= c2_dc_loop_ub; c2_i445++) {
    c2_hb_metric->data[c2_hb_metric->size[0] * c2_hb_metric->size[1] * c2_i445] =
      c2_fb_metric->data[2 + c2_iv38[0] * c2_iv38[1] * c2_i445];
  }

  c2_emxFree_real32_T(chartInstance, &c2_fb_metric);
  for (c2_i446 = 0; c2_i446 < 3; c2_i446++) {
    c2_ib_metric[c2_i446] = c2_hb_metric->size[c2_i446];
  }

  c2_emxFree_real32_T(chartInstance, &c2_hb_metric);
  _SFD_SIZE_EQ_CHECK_ND(c2_eb_metric, c2_ib_metric, 3);
  c2_iv40[0] = 3;
  c2_iv40[1] = 3;
  c2_iv40[2] = (int32_T)c2_dv3[2];
  c2_iv41[0] = 3;
  c2_iv41[1] = 3;
  c2_iv41[2] = (int32_T)c2_dv3[2];
  c2_i447 = c2_xp1->size[0] * c2_xp1->size[1] * c2_xp1->size[2];
  c2_xp1->size[0] = 1;
  c2_xp1->size[1] = 1;
  c2_xp1->size[2] = c2_iv41[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_xp1, c2_i447,
    &c2_xe_emlrtRTEI);
  c2_ec_loop_ub = c2_iv41[2] - 1;
  for (c2_i448 = 0; c2_i448 <= c2_ec_loop_ub; c2_i448++) {
    c2_xp1->data[c2_xp1->size[0] * c2_xp1->size[1] * c2_i448] = 2.0F *
      c2_patch->data[(c2_iv40[0] + c2_iv40[0] * c2_iv40[1] * c2_i448) + 2];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_jb_metric, 1, &c2_pe_emlrtRTEI);
  c2_kb_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i449 = c2_jb_metric->size[0];
  c2_jb_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_jb_metric, c2_i449,
    &c2_pe_emlrtRTEI);
  c2_fc_loop_ub = c2_idx->size[0] - 1;
  for (c2_i450 = 0; c2_i450 <= c2_fc_loop_ub; c2_i450++) {
    c2_jb_metric->data[c2_i450] = c2_metric->data[c2_idx->data[c2_i450] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_lb_metric, 3, &c2_re_emlrtRTEI);
  c2_iv42[0] = 3;
  c2_iv42[1] = 3;
  c2_iv42[2] = (int32_T)c2_dv3[2];
  c2_iv43[0] = 3;
  c2_iv43[1] = 3;
  c2_iv43[2] = (int32_T)c2_dv3[2];
  c2_i451 = c2_lb_metric->size[0] * c2_lb_metric->size[1] * c2_lb_metric->size[2];
  c2_lb_metric->size[0] = 1;
  c2_lb_metric->size[1] = 1;
  c2_lb_metric->size[2] = c2_iv43[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_lb_metric, c2_i451,
    &c2_re_emlrtRTEI);
  c2_gc_loop_ub = c2_iv43[2] - 1;
  for (c2_i452 = 0; c2_i452 <= c2_gc_loop_ub; c2_i452++) {
    c2_lb_metric->data[c2_lb_metric->size[0] * c2_lb_metric->size[1] * c2_i452] =
      c2_jb_metric->data[c2_iv42[0] * c2_iv42[1] * c2_i452];
  }

  c2_emxFree_real32_T(chartInstance, &c2_jb_metric);
  for (c2_i453 = 0; c2_i453 < 3; c2_i453++) {
    c2_mb_metric[c2_i453] = c2_lb_metric->size[c2_i453];
  }

  c2_emxFree_real32_T(chartInstance, &c2_lb_metric);
  for (c2_i454 = 0; c2_i454 < 3; c2_i454++) {
    c2_e_xp1[c2_i454] = c2_xp1->size[c2_i454];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_nb_metric, 1, &c2_pe_emlrtRTEI);
  _SFD_SIZE_EQ_CHECK_ND(c2_mb_metric, c2_e_xp1, 3);
  c2_ob_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i455 = c2_nb_metric->size[0];
  c2_nb_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_nb_metric, c2_i455,
    &c2_pe_emlrtRTEI);
  c2_hc_loop_ub = c2_idx->size[0] - 1;
  for (c2_i456 = 0; c2_i456 <= c2_hc_loop_ub; c2_i456++) {
    c2_nb_metric->data[c2_i456] = c2_metric->data[c2_idx->data[c2_i456] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_pb_metric, 3, &c2_re_emlrtRTEI);
  c2_iv44[0] = 3;
  c2_iv44[1] = 3;
  c2_iv44[2] = (int32_T)c2_dv3[2];
  c2_iv45[0] = 3;
  c2_iv45[1] = 3;
  c2_iv45[2] = (int32_T)c2_dv3[2];
  c2_i457 = c2_pb_metric->size[0] * c2_pb_metric->size[1] * c2_pb_metric->size[2];
  c2_pb_metric->size[0] = 1;
  c2_pb_metric->size[1] = 1;
  c2_pb_metric->size[2] = c2_iv45[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_pb_metric, c2_i457,
    &c2_re_emlrtRTEI);
  c2_ic_loop_ub = c2_iv45[2] - 1;
  for (c2_i458 = 0; c2_i458 <= c2_ic_loop_ub; c2_i458++) {
    c2_pb_metric->data[c2_pb_metric->size[0] * c2_pb_metric->size[1] * c2_i458] =
      c2_nb_metric->data[c2_iv44[0] * c2_iv44[1] * c2_i458];
  }

  c2_emxFree_real32_T(chartInstance, &c2_nb_metric);
  for (c2_i459 = 0; c2_i459 < 3; c2_i459++) {
    c2_qb_metric[c2_i459] = c2_pb_metric->size[c2_i459];
  }

  c2_emxFree_real32_T(chartInstance, &c2_pb_metric);
  c2_emxInit_real32_T1(chartInstance, &c2_rb_metric, 1, &c2_pe_emlrtRTEI);
  c2_sb_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i460 = c2_rb_metric->size[0];
  c2_rb_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_rb_metric, c2_i460,
    &c2_pe_emlrtRTEI);
  c2_jc_loop_ub = c2_idx->size[0] - 1;
  for (c2_i461 = 0; c2_i461 <= c2_jc_loop_ub; c2_i461++) {
    c2_rb_metric->data[c2_i461] = c2_metric->data[c2_idx->data[c2_i461] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_tb_metric, 3, &c2_ye_emlrtRTEI);
  c2_iv46[0] = 3;
  c2_iv46[1] = 3;
  c2_iv46[2] = (int32_T)c2_dv3[2];
  c2_iv47[0] = 3;
  c2_iv47[1] = 3;
  c2_iv47[2] = (int32_T)c2_dv3[2];
  c2_i462 = c2_tb_metric->size[0] * c2_tb_metric->size[1] * c2_tb_metric->size[2];
  c2_tb_metric->size[0] = 1;
  c2_tb_metric->size[1] = 1;
  c2_tb_metric->size[2] = c2_iv47[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_tb_metric, c2_i462,
    &c2_ye_emlrtRTEI);
  c2_kc_loop_ub = c2_iv47[2] - 1;
  for (c2_i463 = 0; c2_i463 <= c2_kc_loop_ub; c2_i463++) {
    c2_tb_metric->data[c2_tb_metric->size[0] * c2_tb_metric->size[1] * c2_i463] =
      c2_rb_metric->data[((c2_iv46[0] << 1) + c2_iv46[0] * c2_iv46[1] * c2_i463)
      + 2];
  }

  c2_emxFree_real32_T(chartInstance, &c2_rb_metric);
  for (c2_i464 = 0; c2_i464 < 3; c2_i464++) {
    c2_ub_metric[c2_i464] = c2_tb_metric->size[c2_i464];
  }

  c2_emxFree_real32_T(chartInstance, &c2_tb_metric);
  _SFD_SIZE_EQ_CHECK_ND(c2_qb_metric, c2_ub_metric, 3);
  c2_iv48[0] = 3;
  c2_iv48[1] = 3;
  c2_iv48[2] = (int32_T)c2_dv3[2];
  c2_iv49[0] = 3;
  c2_iv49[1] = 3;
  c2_iv49[2] = (int32_T)c2_dv3[2];
  c2_iv50[0] = 3;
  c2_iv50[1] = 3;
  c2_iv50[2] = (int32_T)c2_dv3[2];
  c2_iv51[0] = 3;
  c2_iv51[1] = 3;
  c2_iv51[2] = (int32_T)c2_dv3[2];
  c2_iv52[0] = 3;
  c2_iv52[1] = 3;
  c2_iv52[2] = (int32_T)c2_dv3[2];
  c2_iv53[0] = 3;
  c2_iv53[1] = 3;
  c2_iv53[2] = (int32_T)c2_dv3[2];
  c2_iv54[0] = 3;
  c2_iv54[1] = 3;
  c2_iv54[2] = (int32_T)c2_dv3[2];
  c2_iv55[0] = 3;
  c2_iv55[1] = 3;
  c2_iv55[2] = (int32_T)c2_dv3[2];
  c2_i465 = c2_dx2->size[0] * c2_dx2->size[1] * c2_dx2->size[2];
  c2_dx2->size[0] = 1;
  c2_dx2->size[1] = 1;
  c2_dx2->size[2] = c2_iv49[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_dx2, c2_i465,
    &c2_af_emlrtRTEI);
  c2_lc_loop_ub = c2_iv49[2] - 1;
  for (c2_i466 = 0; c2_i466 <= c2_lc_loop_ub; c2_i466++) {
    c2_dx2->data[c2_dx2->size[0] * c2_dx2->size[1] * c2_i466] =
      ((((((((c2_patch->data[c2_iv48[0] * c2_iv48[1] * c2_i466] - c2_r9->
              data[c2_r9->size[0] * c2_r9->size[1] * c2_i466]) + c2_patch->data
             [(c2_iv50[0] << 1) + c2_iv50[0] * c2_iv50[1] * c2_i466]) +
            c2_r10->data[c2_r10->size[0] * c2_r10->size[1] * c2_i466]) -
           c2_r11->data[c2_r11->size[0] * c2_r11->size[1] * c2_i466]) +
          c2_xm1->data[c2_xm1->size[0] * c2_xm1->size[1] * c2_i466]) +
         c2_patch->data[2 + c2_iv52[0] * c2_iv52[1] * c2_i466]) - c2_xp1->
        data[c2_xp1->size[0] * c2_xp1->size[1] * c2_i466]) + c2_patch->data
       [((c2_iv54[0] << 1) + c2_iv54[0] * c2_iv54[1] * c2_i466) + 2]) / 8.0F;
  }

  c2_iv56[0] = 3;
  c2_iv56[1] = 3;
  c2_iv56[2] = (int32_T)c2_dv3[2];
  c2_iv57[0] = 3;
  c2_iv57[1] = 3;
  c2_iv57[2] = (int32_T)c2_dv3[2];
  c2_i467 = c2_r9->size[0] * c2_r9->size[1] * c2_r9->size[2];
  c2_r9->size[0] = 1;
  c2_r9->size[1] = 1;
  c2_r9->size[2] = c2_iv57[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_r9, c2_i467, &c2_bf_emlrtRTEI);
  c2_mc_loop_ub = c2_iv57[2] - 1;
  for (c2_i468 = 0; c2_i468 <= c2_mc_loop_ub; c2_i468++) {
    c2_r9->data[c2_r9->size[0] * c2_r9->size[1] * c2_i468] = 2.0F *
      c2_patch->data[c2_iv56[0] + c2_iv56[0] * c2_iv56[1] * c2_i468];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_vb_metric, 1, &c2_pe_emlrtRTEI);
  c2_wb_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i469 = c2_vb_metric->size[0];
  c2_vb_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_vb_metric, c2_i469,
    &c2_pe_emlrtRTEI);
  c2_nc_loop_ub = c2_idx->size[0] - 1;
  for (c2_i470 = 0; c2_i470 <= c2_nc_loop_ub; c2_i470++) {
    c2_vb_metric->data[c2_i470] = c2_metric->data[c2_idx->data[c2_i470] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_xb_metric, 3, &c2_cf_emlrtRTEI);
  c2_iv58[0] = 3;
  c2_iv58[1] = 3;
  c2_iv58[2] = (int32_T)c2_dv3[2];
  c2_iv59[0] = 3;
  c2_iv59[1] = 3;
  c2_iv59[2] = (int32_T)c2_dv3[2];
  c2_i471 = c2_xb_metric->size[0] * c2_xb_metric->size[1] * c2_xb_metric->size[2];
  c2_xb_metric->size[0] = 1;
  c2_xb_metric->size[1] = 1;
  c2_xb_metric->size[2] = c2_iv59[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_xb_metric, c2_i471,
    &c2_cf_emlrtRTEI);
  c2_oc_loop_ub = c2_iv59[2] - 1;
  for (c2_i472 = 0; c2_i472 <= c2_oc_loop_ub; c2_i472++) {
    c2_xb_metric->data[c2_xb_metric->size[0] * c2_xb_metric->size[1] * c2_i472] =
      c2_vb_metric->data[c2_iv58[0] * c2_iv58[1] * c2_i472];
  }

  c2_emxFree_real32_T(chartInstance, &c2_vb_metric);
  for (c2_i473 = 0; c2_i473 < 3; c2_i473++) {
    c2_yb_metric[c2_i473] = c2_xb_metric->size[c2_i473];
  }

  c2_emxFree_real32_T(chartInstance, &c2_xb_metric);
  for (c2_i474 = 0; c2_i474 < 3; c2_i474++) {
    c2_iv60[c2_i474] = c2_r9->size[c2_i474];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_ac_metric, 1, &c2_pe_emlrtRTEI);
  _SFD_SIZE_EQ_CHECK_ND(c2_yb_metric, c2_iv60, 3);
  c2_bc_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i475 = c2_ac_metric->size[0];
  c2_ac_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_ac_metric, c2_i475,
    &c2_pe_emlrtRTEI);
  c2_pc_loop_ub = c2_idx->size[0] - 1;
  for (c2_i476 = 0; c2_i476 <= c2_pc_loop_ub; c2_i476++) {
    c2_ac_metric->data[c2_i476] = c2_metric->data[c2_idx->data[c2_i476] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_cc_metric, 3, &c2_cf_emlrtRTEI);
  c2_iv61[0] = 3;
  c2_iv61[1] = 3;
  c2_iv61[2] = (int32_T)c2_dv3[2];
  c2_iv62[0] = 3;
  c2_iv62[1] = 3;
  c2_iv62[2] = (int32_T)c2_dv3[2];
  c2_i477 = c2_cc_metric->size[0] * c2_cc_metric->size[1] * c2_cc_metric->size[2];
  c2_cc_metric->size[0] = 1;
  c2_cc_metric->size[1] = 1;
  c2_cc_metric->size[2] = c2_iv62[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_cc_metric, c2_i477,
    &c2_cf_emlrtRTEI);
  c2_qc_loop_ub = c2_iv62[2] - 1;
  for (c2_i478 = 0; c2_i478 <= c2_qc_loop_ub; c2_i478++) {
    c2_cc_metric->data[c2_cc_metric->size[0] * c2_cc_metric->size[1] * c2_i478] =
      c2_ac_metric->data[c2_iv61[0] * c2_iv61[1] * c2_i478];
  }

  c2_emxFree_real32_T(chartInstance, &c2_ac_metric);
  for (c2_i479 = 0; c2_i479 < 3; c2_i479++) {
    c2_dc_metric[c2_i479] = c2_cc_metric->size[c2_i479];
  }

  c2_emxFree_real32_T(chartInstance, &c2_cc_metric);
  c2_emxInit_real32_T1(chartInstance, &c2_ec_metric, 1, &c2_pe_emlrtRTEI);
  c2_fc_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i480 = c2_ec_metric->size[0];
  c2_ec_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_ec_metric, c2_i480,
    &c2_pe_emlrtRTEI);
  c2_rc_loop_ub = c2_idx->size[0] - 1;
  for (c2_i481 = 0; c2_i481 <= c2_rc_loop_ub; c2_i481++) {
    c2_ec_metric->data[c2_i481] = c2_metric->data[c2_idx->data[c2_i481] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_gc_metric, 3, &c2_df_emlrtRTEI);
  c2_iv63[0] = 3;
  c2_iv63[1] = 3;
  c2_iv63[2] = (int32_T)c2_dv3[2];
  c2_iv64[0] = 3;
  c2_iv64[1] = 3;
  c2_iv64[2] = (int32_T)c2_dv3[2];
  c2_i482 = c2_gc_metric->size[0] * c2_gc_metric->size[1] * c2_gc_metric->size[2];
  c2_gc_metric->size[0] = 1;
  c2_gc_metric->size[1] = 1;
  c2_gc_metric->size[2] = c2_iv64[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_gc_metric, c2_i482,
    &c2_df_emlrtRTEI);
  c2_sc_loop_ub = c2_iv64[2] - 1;
  for (c2_i483 = 0; c2_i483 <= c2_sc_loop_ub; c2_i483++) {
    c2_gc_metric->data[c2_gc_metric->size[0] * c2_gc_metric->size[1] * c2_i483] =
      c2_ec_metric->data[(c2_iv63[0] << 1) + c2_iv63[0] * c2_iv63[1] * c2_i483];
  }

  c2_emxFree_real32_T(chartInstance, &c2_ec_metric);
  for (c2_i484 = 0; c2_i484 < 3; c2_i484++) {
    c2_hc_metric[c2_i484] = c2_gc_metric->size[c2_i484];
  }

  c2_emxFree_real32_T(chartInstance, &c2_gc_metric);
  _SFD_SIZE_EQ_CHECK_ND(c2_dc_metric, c2_hc_metric, 3);
  c2_iv65[0] = 3;
  c2_iv65[1] = 3;
  c2_iv65[2] = (int32_T)c2_dv3[2];
  c2_iv66[0] = 3;
  c2_iv66[1] = 3;
  c2_iv66[2] = (int32_T)c2_dv3[2];
  c2_i485 = c2_r10->size[0] * c2_r10->size[1] * c2_r10->size[2];
  c2_r10->size[0] = 1;
  c2_r10->size[1] = 1;
  c2_r10->size[2] = c2_iv66[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_r10, c2_i485,
    &c2_ef_emlrtRTEI);
  c2_tc_loop_ub = c2_iv66[2] - 1;
  for (c2_i486 = 0; c2_i486 <= c2_tc_loop_ub; c2_i486++) {
    c2_r10->data[c2_r10->size[0] * c2_r10->size[1] * c2_i486] = 2.0F *
      c2_patch->data[(c2_iv65[0] + c2_iv65[0] * c2_iv65[1] * c2_i486) + 1];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_ic_metric, 1, &c2_pe_emlrtRTEI);
  c2_jc_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i487 = c2_ic_metric->size[0];
  c2_ic_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_ic_metric, c2_i487,
    &c2_pe_emlrtRTEI);
  c2_uc_loop_ub = c2_idx->size[0] - 1;
  for (c2_i488 = 0; c2_i488 <= c2_uc_loop_ub; c2_i488++) {
    c2_ic_metric->data[c2_i488] = c2_metric->data[c2_idx->data[c2_i488] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_kc_metric, 3, &c2_ff_emlrtRTEI);
  c2_iv67[0] = 3;
  c2_iv67[1] = 3;
  c2_iv67[2] = (int32_T)c2_dv3[2];
  c2_iv68[0] = 3;
  c2_iv68[1] = 3;
  c2_iv68[2] = (int32_T)c2_dv3[2];
  c2_i489 = c2_kc_metric->size[0] * c2_kc_metric->size[1] * c2_kc_metric->size[2];
  c2_kc_metric->size[0] = 1;
  c2_kc_metric->size[1] = 1;
  c2_kc_metric->size[2] = c2_iv68[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_kc_metric, c2_i489,
    &c2_ff_emlrtRTEI);
  c2_vc_loop_ub = c2_iv68[2] - 1;
  for (c2_i490 = 0; c2_i490 <= c2_vc_loop_ub; c2_i490++) {
    c2_kc_metric->data[c2_kc_metric->size[0] * c2_kc_metric->size[1] * c2_i490] =
      c2_ic_metric->data[1 + c2_iv67[0] * c2_iv67[1] * c2_i490];
  }

  c2_emxFree_real32_T(chartInstance, &c2_ic_metric);
  for (c2_i491 = 0; c2_i491 < 3; c2_i491++) {
    c2_lc_metric[c2_i491] = c2_kc_metric->size[c2_i491];
  }

  c2_emxFree_real32_T(chartInstance, &c2_kc_metric);
  for (c2_i492 = 0; c2_i492 < 3; c2_i492++) {
    c2_iv69[c2_i492] = c2_r10->size[c2_i492];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_mc_metric, 1, &c2_pe_emlrtRTEI);
  _SFD_SIZE_EQ_CHECK_ND(c2_lc_metric, c2_iv69, 3);
  c2_nc_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i493 = c2_mc_metric->size[0];
  c2_mc_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_mc_metric, c2_i493,
    &c2_pe_emlrtRTEI);
  c2_wc_loop_ub = c2_idx->size[0] - 1;
  for (c2_i494 = 0; c2_i494 <= c2_wc_loop_ub; c2_i494++) {
    c2_mc_metric->data[c2_i494] = c2_metric->data[c2_idx->data[c2_i494] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_oc_metric, 3, &c2_ff_emlrtRTEI);
  c2_iv70[0] = 3;
  c2_iv70[1] = 3;
  c2_iv70[2] = (int32_T)c2_dv3[2];
  c2_iv71[0] = 3;
  c2_iv71[1] = 3;
  c2_iv71[2] = (int32_T)c2_dv3[2];
  c2_i495 = c2_oc_metric->size[0] * c2_oc_metric->size[1] * c2_oc_metric->size[2];
  c2_oc_metric->size[0] = 1;
  c2_oc_metric->size[1] = 1;
  c2_oc_metric->size[2] = c2_iv71[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_oc_metric, c2_i495,
    &c2_ff_emlrtRTEI);
  c2_xc_loop_ub = c2_iv71[2] - 1;
  for (c2_i496 = 0; c2_i496 <= c2_xc_loop_ub; c2_i496++) {
    c2_oc_metric->data[c2_oc_metric->size[0] * c2_oc_metric->size[1] * c2_i496] =
      c2_mc_metric->data[1 + c2_iv70[0] * c2_iv70[1] * c2_i496];
  }

  c2_emxFree_real32_T(chartInstance, &c2_mc_metric);
  for (c2_i497 = 0; c2_i497 < 3; c2_i497++) {
    c2_pc_metric[c2_i497] = c2_oc_metric->size[c2_i497];
  }

  c2_emxFree_real32_T(chartInstance, &c2_oc_metric);
  c2_emxInit_real32_T1(chartInstance, &c2_qc_metric, 1, &c2_pe_emlrtRTEI);
  c2_rc_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i498 = c2_qc_metric->size[0];
  c2_qc_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_qc_metric, c2_i498,
    &c2_pe_emlrtRTEI);
  c2_yc_loop_ub = c2_idx->size[0] - 1;
  for (c2_i499 = 0; c2_i499 <= c2_yc_loop_ub; c2_i499++) {
    c2_qc_metric->data[c2_i499] = c2_metric->data[c2_idx->data[c2_i499] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_sc_metric, 3, &c2_gf_emlrtRTEI);
  c2_iv72[0] = 3;
  c2_iv72[1] = 3;
  c2_iv72[2] = (int32_T)c2_dv3[2];
  c2_iv73[0] = 3;
  c2_iv73[1] = 3;
  c2_iv73[2] = (int32_T)c2_dv3[2];
  c2_i500 = c2_sc_metric->size[0] * c2_sc_metric->size[1] * c2_sc_metric->size[2];
  c2_sc_metric->size[0] = 1;
  c2_sc_metric->size[1] = 1;
  c2_sc_metric->size[2] = c2_iv73[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_sc_metric, c2_i500,
    &c2_gf_emlrtRTEI);
  c2_ad_loop_ub = c2_iv73[2] - 1;
  for (c2_i501 = 0; c2_i501 <= c2_ad_loop_ub; c2_i501++) {
    c2_sc_metric->data[c2_sc_metric->size[0] * c2_sc_metric->size[1] * c2_i501] =
      c2_qc_metric->data[((c2_iv72[0] << 1) + c2_iv72[0] * c2_iv72[1] * c2_i501)
      + 1];
  }

  c2_emxFree_real32_T(chartInstance, &c2_qc_metric);
  for (c2_i502 = 0; c2_i502 < 3; c2_i502++) {
    c2_tc_metric[c2_i502] = c2_sc_metric->size[c2_i502];
  }

  c2_emxFree_real32_T(chartInstance, &c2_sc_metric);
  _SFD_SIZE_EQ_CHECK_ND(c2_pc_metric, c2_tc_metric, 3);
  c2_iv74[0] = 3;
  c2_iv74[1] = 3;
  c2_iv74[2] = (int32_T)c2_dv3[2];
  c2_iv75[0] = 3;
  c2_iv75[1] = 3;
  c2_iv75[2] = (int32_T)c2_dv3[2];
  c2_iv76[0] = 3;
  c2_iv76[1] = 3;
  c2_iv76[2] = (int32_T)c2_dv3[2];
  c2_iv77[0] = 3;
  c2_iv77[1] = 3;
  c2_iv77[2] = (int32_T)c2_dv3[2];
  c2_i503 = c2_r11->size[0] * c2_r11->size[1] * c2_r11->size[2];
  c2_r11->size[0] = 1;
  c2_r11->size[1] = 1;
  c2_r11->size[2] = c2_iv75[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_r11, c2_i503,
    &c2_hf_emlrtRTEI);
  c2_bd_loop_ub = c2_iv75[2] - 1;
  for (c2_i504 = 0; c2_i504 <= c2_bd_loop_ub; c2_i504++) {
    c2_r11->data[c2_r11->size[0] * c2_r11->size[1] * c2_i504] = 2.0F *
      ((c2_patch->data[1 + c2_iv74[0] * c2_iv74[1] * c2_i504] + c2_r10->
        data[c2_r10->size[0] * c2_r10->size[1] * c2_i504]) + c2_patch->data
       [((c2_iv76[0] << 1) + c2_iv76[0] * c2_iv76[1] * c2_i504) + 1]);
  }

  c2_emxInit_real32_T1(chartInstance, &c2_uc_metric, 1, &c2_pe_emlrtRTEI);
  c2_vc_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i505 = c2_uc_metric->size[0];
  c2_uc_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_uc_metric, c2_i505,
    &c2_pe_emlrtRTEI);
  c2_cd_loop_ub = c2_idx->size[0] - 1;
  for (c2_i506 = 0; c2_i506 <= c2_cd_loop_ub; c2_i506++) {
    c2_uc_metric->data[c2_i506] = c2_metric->data[c2_idx->data[c2_i506] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_wc_metric, 3, &c2_cf_emlrtRTEI);
  c2_iv78[0] = 3;
  c2_iv78[1] = 3;
  c2_iv78[2] = (int32_T)c2_dv3[2];
  c2_iv79[0] = 3;
  c2_iv79[1] = 3;
  c2_iv79[2] = (int32_T)c2_dv3[2];
  c2_i507 = c2_wc_metric->size[0] * c2_wc_metric->size[1] * c2_wc_metric->size[2];
  c2_wc_metric->size[0] = 1;
  c2_wc_metric->size[1] = 1;
  c2_wc_metric->size[2] = c2_iv79[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_wc_metric, c2_i507,
    &c2_cf_emlrtRTEI);
  c2_dd_loop_ub = c2_iv79[2] - 1;
  for (c2_i508 = 0; c2_i508 <= c2_dd_loop_ub; c2_i508++) {
    c2_wc_metric->data[c2_wc_metric->size[0] * c2_wc_metric->size[1] * c2_i508] =
      c2_uc_metric->data[c2_iv78[0] * c2_iv78[1] * c2_i508];
  }

  c2_emxFree_real32_T(chartInstance, &c2_uc_metric);
  for (c2_i509 = 0; c2_i509 < 3; c2_i509++) {
    c2_xc_metric[c2_i509] = c2_wc_metric->size[c2_i509];
  }

  c2_emxFree_real32_T(chartInstance, &c2_wc_metric);
  for (c2_i510 = 0; c2_i510 < 3; c2_i510++) {
    c2_iv80[c2_i510] = c2_r11->size[c2_i510];
  }

  _SFD_SIZE_EQ_CHECK_ND(c2_xc_metric, c2_iv80, 3);
  c2_iv81[0] = 3;
  c2_iv81[1] = 3;
  c2_iv81[2] = (int32_T)c2_dv3[2];
  c2_iv82[0] = 3;
  c2_iv82[1] = 3;
  c2_iv82[2] = (int32_T)c2_dv3[2];
  c2_i511 = c2_r10->size[0] * c2_r10->size[1] * c2_r10->size[2];
  c2_r10->size[0] = 1;
  c2_r10->size[1] = 1;
  c2_r10->size[2] = c2_iv82[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_r10, c2_i511,
    &c2_if_emlrtRTEI);
  c2_ed_loop_ub = c2_iv82[2] - 1;
  for (c2_i512 = 0; c2_i512 <= c2_ed_loop_ub; c2_i512++) {
    c2_r10->data[c2_r10->size[0] * c2_r10->size[1] * c2_i512] = 2.0F *
      c2_patch->data[(c2_iv81[0] + c2_iv81[0] * c2_iv81[1] * c2_i512) + 2];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_yc_metric, 1, &c2_pe_emlrtRTEI);
  c2_ad_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i513 = c2_yc_metric->size[0];
  c2_yc_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_yc_metric, c2_i513,
    &c2_pe_emlrtRTEI);
  c2_fd_loop_ub = c2_idx->size[0] - 1;
  for (c2_i514 = 0; c2_i514 <= c2_fd_loop_ub; c2_i514++) {
    c2_yc_metric->data[c2_i514] = c2_metric->data[c2_idx->data[c2_i514] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_bd_metric, 3, &c2_jf_emlrtRTEI);
  c2_iv83[0] = 3;
  c2_iv83[1] = 3;
  c2_iv83[2] = (int32_T)c2_dv3[2];
  c2_iv84[0] = 3;
  c2_iv84[1] = 3;
  c2_iv84[2] = (int32_T)c2_dv3[2];
  c2_i515 = c2_bd_metric->size[0] * c2_bd_metric->size[1] * c2_bd_metric->size[2];
  c2_bd_metric->size[0] = 1;
  c2_bd_metric->size[1] = 1;
  c2_bd_metric->size[2] = c2_iv84[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_bd_metric, c2_i515,
    &c2_jf_emlrtRTEI);
  c2_gd_loop_ub = c2_iv84[2] - 1;
  for (c2_i516 = 0; c2_i516 <= c2_gd_loop_ub; c2_i516++) {
    c2_bd_metric->data[c2_bd_metric->size[0] * c2_bd_metric->size[1] * c2_i516] =
      c2_yc_metric->data[2 + c2_iv83[0] * c2_iv83[1] * c2_i516];
  }

  c2_emxFree_real32_T(chartInstance, &c2_yc_metric);
  for (c2_i517 = 0; c2_i517 < 3; c2_i517++) {
    c2_cd_metric[c2_i517] = c2_bd_metric->size[c2_i517];
  }

  c2_emxFree_real32_T(chartInstance, &c2_bd_metric);
  for (c2_i518 = 0; c2_i518 < 3; c2_i518++) {
    c2_iv85[c2_i518] = c2_r10->size[c2_i518];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_dd_metric, 1, &c2_pe_emlrtRTEI);
  _SFD_SIZE_EQ_CHECK_ND(c2_cd_metric, c2_iv85, 3);
  c2_ed_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i519 = c2_dd_metric->size[0];
  c2_dd_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_dd_metric, c2_i519,
    &c2_pe_emlrtRTEI);
  c2_hd_loop_ub = c2_idx->size[0] - 1;
  for (c2_i520 = 0; c2_i520 <= c2_hd_loop_ub; c2_i520++) {
    c2_dd_metric->data[c2_i520] = c2_metric->data[c2_idx->data[c2_i520] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_fd_metric, 3, &c2_jf_emlrtRTEI);
  c2_iv86[0] = 3;
  c2_iv86[1] = 3;
  c2_iv86[2] = (int32_T)c2_dv3[2];
  c2_iv87[0] = 3;
  c2_iv87[1] = 3;
  c2_iv87[2] = (int32_T)c2_dv3[2];
  c2_i521 = c2_fd_metric->size[0] * c2_fd_metric->size[1] * c2_fd_metric->size[2];
  c2_fd_metric->size[0] = 1;
  c2_fd_metric->size[1] = 1;
  c2_fd_metric->size[2] = c2_iv87[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_fd_metric, c2_i521,
    &c2_jf_emlrtRTEI);
  c2_id_loop_ub = c2_iv87[2] - 1;
  for (c2_i522 = 0; c2_i522 <= c2_id_loop_ub; c2_i522++) {
    c2_fd_metric->data[c2_fd_metric->size[0] * c2_fd_metric->size[1] * c2_i522] =
      c2_dd_metric->data[2 + c2_iv86[0] * c2_iv86[1] * c2_i522];
  }

  c2_emxFree_real32_T(chartInstance, &c2_dd_metric);
  for (c2_i523 = 0; c2_i523 < 3; c2_i523++) {
    c2_gd_metric[c2_i523] = c2_fd_metric->size[c2_i523];
  }

  c2_emxFree_real32_T(chartInstance, &c2_fd_metric);
  c2_emxInit_real32_T1(chartInstance, &c2_hd_metric, 1, &c2_pe_emlrtRTEI);
  c2_id_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i524 = c2_hd_metric->size[0];
  c2_hd_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_hd_metric, c2_i524,
    &c2_pe_emlrtRTEI);
  c2_jd_loop_ub = c2_idx->size[0] - 1;
  for (c2_i525 = 0; c2_i525 <= c2_jd_loop_ub; c2_i525++) {
    c2_hd_metric->data[c2_i525] = c2_metric->data[c2_idx->data[c2_i525] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_jd_metric, 3, &c2_kf_emlrtRTEI);
  c2_iv88[0] = 3;
  c2_iv88[1] = 3;
  c2_iv88[2] = (int32_T)c2_dv3[2];
  c2_iv89[0] = 3;
  c2_iv89[1] = 3;
  c2_iv89[2] = (int32_T)c2_dv3[2];
  c2_i526 = c2_jd_metric->size[0] * c2_jd_metric->size[1] * c2_jd_metric->size[2];
  c2_jd_metric->size[0] = 1;
  c2_jd_metric->size[1] = 1;
  c2_jd_metric->size[2] = c2_iv89[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_jd_metric, c2_i526,
    &c2_kf_emlrtRTEI);
  c2_kd_loop_ub = c2_iv89[2] - 1;
  for (c2_i527 = 0; c2_i527 <= c2_kd_loop_ub; c2_i527++) {
    c2_jd_metric->data[c2_jd_metric->size[0] * c2_jd_metric->size[1] * c2_i527] =
      c2_hd_metric->data[((c2_iv88[0] << 1) + c2_iv88[0] * c2_iv88[1] * c2_i527)
      + 2];
  }

  c2_emxFree_real32_T(chartInstance, &c2_hd_metric);
  for (c2_i528 = 0; c2_i528 < 3; c2_i528++) {
    c2_kd_metric[c2_i528] = c2_jd_metric->size[c2_i528];
  }

  c2_emxFree_real32_T(chartInstance, &c2_jd_metric);
  c2_emxInit_real32_T1(chartInstance, &c2_ld_metric, 1, &c2_pe_emlrtRTEI);
  _SFD_SIZE_EQ_CHECK_ND(c2_gd_metric, c2_kd_metric, 3);
  c2_md_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i529 = c2_ld_metric->size[0];
  c2_ld_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_ld_metric, c2_i529,
    &c2_pe_emlrtRTEI);
  c2_ld_loop_ub = c2_idx->size[0] - 1;
  for (c2_i530 = 0; c2_i530 <= c2_ld_loop_ub; c2_i530++) {
    c2_ld_metric->data[c2_i530] = c2_metric->data[c2_idx->data[c2_i530] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_nd_metric, 3, &c2_cf_emlrtRTEI);
  c2_iv90[0] = 3;
  c2_iv90[1] = 3;
  c2_iv90[2] = (int32_T)c2_dv3[2];
  c2_iv91[0] = 3;
  c2_iv91[1] = 3;
  c2_iv91[2] = (int32_T)c2_dv3[2];
  c2_i531 = c2_nd_metric->size[0] * c2_nd_metric->size[1] * c2_nd_metric->size[2];
  c2_nd_metric->size[0] = 1;
  c2_nd_metric->size[1] = 1;
  c2_nd_metric->size[2] = c2_iv91[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_nd_metric, c2_i531,
    &c2_cf_emlrtRTEI);
  c2_md_loop_ub = c2_iv91[2] - 1;
  for (c2_i532 = 0; c2_i532 <= c2_md_loop_ub; c2_i532++) {
    c2_nd_metric->data[c2_nd_metric->size[0] * c2_nd_metric->size[1] * c2_i532] =
      c2_ld_metric->data[c2_iv90[0] * c2_iv90[1] * c2_i532];
  }

  c2_emxFree_real32_T(chartInstance, &c2_ld_metric);
  for (c2_i533 = 0; c2_i533 < 3; c2_i533++) {
    c2_od_metric[c2_i533] = c2_nd_metric->size[c2_i533];
  }

  c2_emxFree_real32_T(chartInstance, &c2_nd_metric);
  c2_emxInit_real32_T1(chartInstance, &c2_pd_metric, 1, &c2_pe_emlrtRTEI);
  c2_qd_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i534 = c2_pd_metric->size[0];
  c2_pd_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_pd_metric, c2_i534,
    &c2_pe_emlrtRTEI);
  c2_nd_loop_ub = c2_idx->size[0] - 1;
  for (c2_i535 = 0; c2_i535 <= c2_nd_loop_ub; c2_i535++) {
    c2_pd_metric->data[c2_i535] = c2_metric->data[c2_idx->data[c2_i535] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_rd_metric, 3, &c2_jf_emlrtRTEI);
  c2_iv92[0] = 3;
  c2_iv92[1] = 3;
  c2_iv92[2] = (int32_T)c2_dv3[2];
  c2_iv93[0] = 3;
  c2_iv93[1] = 3;
  c2_iv93[2] = (int32_T)c2_dv3[2];
  c2_i536 = c2_rd_metric->size[0] * c2_rd_metric->size[1] * c2_rd_metric->size[2];
  c2_rd_metric->size[0] = 1;
  c2_rd_metric->size[1] = 1;
  c2_rd_metric->size[2] = c2_iv93[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_rd_metric, c2_i536,
    &c2_jf_emlrtRTEI);
  c2_od_loop_ub = c2_iv93[2] - 1;
  for (c2_i537 = 0; c2_i537 <= c2_od_loop_ub; c2_i537++) {
    c2_rd_metric->data[c2_rd_metric->size[0] * c2_rd_metric->size[1] * c2_i537] =
      c2_pd_metric->data[2 + c2_iv92[0] * c2_iv92[1] * c2_i537];
  }

  c2_emxFree_real32_T(chartInstance, &c2_pd_metric);
  for (c2_i538 = 0; c2_i538 < 3; c2_i538++) {
    c2_sd_metric[c2_i538] = c2_rd_metric->size[c2_i538];
  }

  c2_emxFree_real32_T(chartInstance, &c2_rd_metric);
  _SFD_SIZE_EQ_CHECK_ND(c2_od_metric, c2_sd_metric, 3);
  c2_iv94[0] = 3;
  c2_iv94[1] = 3;
  c2_iv94[2] = (int32_T)c2_dv3[2];
  c2_iv95[0] = 3;
  c2_iv95[1] = 3;
  c2_iv95[2] = (int32_T)c2_dv3[2];
  c2_iv96[0] = 3;
  c2_iv96[1] = 3;
  c2_iv96[2] = (int32_T)c2_dv3[2];
  c2_iv97[0] = 3;
  c2_iv97[1] = 3;
  c2_iv97[2] = (int32_T)c2_dv3[2];
  c2_iv98[0] = 3;
  c2_iv98[1] = 3;
  c2_iv98[2] = (int32_T)c2_dv3[2];
  c2_iv99[0] = 3;
  c2_iv99[1] = 3;
  c2_iv99[2] = (int32_T)c2_dv3[2];
  c2_iv100[0] = 3;
  c2_iv100[1] = 3;
  c2_iv100[2] = (int32_T)c2_dv3[2];
  c2_iv101[0] = 3;
  c2_iv101[1] = 3;
  c2_iv101[2] = (int32_T)c2_dv3[2];
  c2_i539 = c2_dy2->size[0] * c2_dy2->size[1] * c2_dy2->size[2];
  c2_dy2->size[0] = 1;
  c2_dy2->size[1] = 1;
  c2_dy2->size[2] = c2_iv95[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_dy2, c2_i539,
    &c2_lf_emlrtRTEI);
  c2_pd_loop_ub = c2_iv95[2] - 1;
  for (c2_i540 = 0; c2_i540 <= c2_pd_loop_ub; c2_i540++) {
    c2_dy2->data[c2_dy2->size[0] * c2_dy2->size[1] * c2_i540] =
      ((((c2_patch->data[c2_iv94[0] * c2_iv94[1] * c2_i540] + c2_r9->data
          [c2_r9->size[0] * c2_r9->size[1] * c2_i540]) + c2_patch->data
         [(c2_iv96[0] << 1) + c2_iv96[0] * c2_iv96[1] * c2_i540]) - c2_r11->
        data[c2_r11->size[0] * c2_r11->size[1] * c2_i540]) + ((c2_patch->data[2
         + c2_iv98[0] * c2_iv98[1] * c2_i540] + c2_r10->data[c2_r10->size[0] *
         c2_r10->size[1] * c2_i540]) + c2_patch->data[((c2_iv100[0] << 1) +
         c2_iv100[0] * c2_iv100[1] * c2_i540) + 2])) / 8.0F;
  }

  c2_emxInit_real32_T1(chartInstance, &c2_td_metric, 1, &c2_pe_emlrtRTEI);
  c2_ud_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i541 = c2_td_metric->size[0];
  c2_td_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_td_metric, c2_i541,
    &c2_pe_emlrtRTEI);
  c2_qd_loop_ub = c2_idx->size[0] - 1;
  for (c2_i542 = 0; c2_i542 <= c2_qd_loop_ub; c2_i542++) {
    c2_td_metric->data[c2_i542] = c2_metric->data[c2_idx->data[c2_i542] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_vd_metric, 3, &c2_mf_emlrtRTEI);
  c2_iv102[0] = 3;
  c2_iv102[1] = 3;
  c2_iv102[2] = (int32_T)c2_dv3[2];
  c2_iv103[0] = 3;
  c2_iv103[1] = 3;
  c2_iv103[2] = (int32_T)c2_dv3[2];
  c2_i543 = c2_vd_metric->size[0] * c2_vd_metric->size[1] * c2_vd_metric->size[2];
  c2_vd_metric->size[0] = 1;
  c2_vd_metric->size[1] = 1;
  c2_vd_metric->size[2] = c2_iv103[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_vd_metric, c2_i543,
    &c2_mf_emlrtRTEI);
  c2_rd_loop_ub = c2_iv103[2] - 1;
  for (c2_i544 = 0; c2_i544 <= c2_rd_loop_ub; c2_i544++) {
    c2_vd_metric->data[c2_vd_metric->size[0] * c2_vd_metric->size[1] * c2_i544] =
      c2_td_metric->data[c2_iv102[0] * c2_iv102[1] * c2_i544];
  }

  c2_emxFree_real32_T(chartInstance, &c2_td_metric);
  for (c2_i545 = 0; c2_i545 < 3; c2_i545++) {
    c2_wd_metric[c2_i545] = c2_vd_metric->size[c2_i545];
  }

  c2_emxFree_real32_T(chartInstance, &c2_vd_metric);
  c2_emxInit_real32_T1(chartInstance, &c2_xd_metric, 1, &c2_pe_emlrtRTEI);
  c2_yd_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i546 = c2_xd_metric->size[0];
  c2_xd_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_xd_metric, c2_i546,
    &c2_pe_emlrtRTEI);
  c2_sd_loop_ub = c2_idx->size[0] - 1;
  for (c2_i547 = 0; c2_i547 <= c2_sd_loop_ub; c2_i547++) {
    c2_xd_metric->data[c2_i547] = c2_metric->data[c2_idx->data[c2_i547] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_ae_metric, 3, &c2_nf_emlrtRTEI);
  c2_iv104[0] = 3;
  c2_iv104[1] = 3;
  c2_iv104[2] = (int32_T)c2_dv3[2];
  c2_iv105[0] = 3;
  c2_iv105[1] = 3;
  c2_iv105[2] = (int32_T)c2_dv3[2];
  c2_i548 = c2_ae_metric->size[0] * c2_ae_metric->size[1] * c2_ae_metric->size[2];
  c2_ae_metric->size[0] = 1;
  c2_ae_metric->size[1] = 1;
  c2_ae_metric->size[2] = c2_iv105[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_ae_metric, c2_i548,
    &c2_nf_emlrtRTEI);
  c2_td_loop_ub = c2_iv105[2] - 1;
  for (c2_i549 = 0; c2_i549 <= c2_td_loop_ub; c2_i549++) {
    c2_ae_metric->data[c2_ae_metric->size[0] * c2_ae_metric->size[1] * c2_i549] =
      c2_xd_metric->data[(c2_iv104[0] << 1) + c2_iv104[0] * c2_iv104[1] *
      c2_i549];
  }

  c2_emxFree_real32_T(chartInstance, &c2_xd_metric);
  for (c2_i550 = 0; c2_i550 < 3; c2_i550++) {
    c2_be_metric[c2_i550] = c2_ae_metric->size[c2_i550];
  }

  c2_emxFree_real32_T(chartInstance, &c2_ae_metric);
  c2_emxInit_real32_T1(chartInstance, &c2_ce_metric, 1, &c2_pe_emlrtRTEI);
  _SFD_SIZE_EQ_CHECK_ND(c2_wd_metric, c2_be_metric, 3);
  c2_de_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i551 = c2_ce_metric->size[0];
  c2_ce_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_ce_metric, c2_i551,
    &c2_pe_emlrtRTEI);
  c2_ud_loop_ub = c2_idx->size[0] - 1;
  for (c2_i552 = 0; c2_i552 <= c2_ud_loop_ub; c2_i552++) {
    c2_ce_metric->data[c2_i552] = c2_metric->data[c2_idx->data[c2_i552] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_ee_metric, 3, &c2_mf_emlrtRTEI);
  c2_iv106[0] = 3;
  c2_iv106[1] = 3;
  c2_iv106[2] = (int32_T)c2_dv3[2];
  c2_iv107[0] = 3;
  c2_iv107[1] = 3;
  c2_iv107[2] = (int32_T)c2_dv3[2];
  c2_i553 = c2_ee_metric->size[0] * c2_ee_metric->size[1] * c2_ee_metric->size[2];
  c2_ee_metric->size[0] = 1;
  c2_ee_metric->size[1] = 1;
  c2_ee_metric->size[2] = c2_iv107[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_ee_metric, c2_i553,
    &c2_mf_emlrtRTEI);
  c2_vd_loop_ub = c2_iv107[2] - 1;
  for (c2_i554 = 0; c2_i554 <= c2_vd_loop_ub; c2_i554++) {
    c2_ee_metric->data[c2_ee_metric->size[0] * c2_ee_metric->size[1] * c2_i554] =
      c2_ce_metric->data[c2_iv106[0] * c2_iv106[1] * c2_i554];
  }

  c2_emxFree_real32_T(chartInstance, &c2_ce_metric);
  for (c2_i555 = 0; c2_i555 < 3; c2_i555++) {
    c2_fe_metric[c2_i555] = c2_ee_metric->size[c2_i555];
  }

  c2_emxFree_real32_T(chartInstance, &c2_ee_metric);
  c2_emxInit_real32_T1(chartInstance, &c2_ge_metric, 1, &c2_pe_emlrtRTEI);
  c2_he_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i556 = c2_ge_metric->size[0];
  c2_ge_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_ge_metric, c2_i556,
    &c2_pe_emlrtRTEI);
  c2_wd_loop_ub = c2_idx->size[0] - 1;
  for (c2_i557 = 0; c2_i557 <= c2_wd_loop_ub; c2_i557++) {
    c2_ge_metric->data[c2_i557] = c2_metric->data[c2_idx->data[c2_i557] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_ie_metric, 3, &c2_of_emlrtRTEI);
  c2_iv108[0] = 3;
  c2_iv108[1] = 3;
  c2_iv108[2] = (int32_T)c2_dv3[2];
  c2_iv109[0] = 3;
  c2_iv109[1] = 3;
  c2_iv109[2] = (int32_T)c2_dv3[2];
  c2_i558 = c2_ie_metric->size[0] * c2_ie_metric->size[1] * c2_ie_metric->size[2];
  c2_ie_metric->size[0] = 1;
  c2_ie_metric->size[1] = 1;
  c2_ie_metric->size[2] = c2_iv109[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_ie_metric, c2_i558,
    &c2_of_emlrtRTEI);
  c2_xd_loop_ub = c2_iv109[2] - 1;
  for (c2_i559 = 0; c2_i559 <= c2_xd_loop_ub; c2_i559++) {
    c2_ie_metric->data[c2_ie_metric->size[0] * c2_ie_metric->size[1] * c2_i559] =
      c2_ge_metric->data[2 + c2_iv108[0] * c2_iv108[1] * c2_i559];
  }

  c2_emxFree_real32_T(chartInstance, &c2_ge_metric);
  for (c2_i560 = 0; c2_i560 < 3; c2_i560++) {
    c2_je_metric[c2_i560] = c2_ie_metric->size[c2_i560];
  }

  c2_emxFree_real32_T(chartInstance, &c2_ie_metric);
  c2_emxInit_real32_T1(chartInstance, &c2_ke_metric, 1, &c2_pe_emlrtRTEI);
  _SFD_SIZE_EQ_CHECK_ND(c2_fe_metric, c2_je_metric, 3);
  c2_le_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i561 = c2_ke_metric->size[0];
  c2_ke_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_ke_metric, c2_i561,
    &c2_pe_emlrtRTEI);
  c2_yd_loop_ub = c2_idx->size[0] - 1;
  for (c2_i562 = 0; c2_i562 <= c2_yd_loop_ub; c2_i562++) {
    c2_ke_metric->data[c2_i562] = c2_metric->data[c2_idx->data[c2_i562] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_me_metric, 3, &c2_mf_emlrtRTEI);
  c2_iv110[0] = 3;
  c2_iv110[1] = 3;
  c2_iv110[2] = (int32_T)c2_dv3[2];
  c2_iv111[0] = 3;
  c2_iv111[1] = 3;
  c2_iv111[2] = (int32_T)c2_dv3[2];
  c2_i563 = c2_me_metric->size[0] * c2_me_metric->size[1] * c2_me_metric->size[2];
  c2_me_metric->size[0] = 1;
  c2_me_metric->size[1] = 1;
  c2_me_metric->size[2] = c2_iv111[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_me_metric, c2_i563,
    &c2_mf_emlrtRTEI);
  c2_ae_loop_ub = c2_iv111[2] - 1;
  for (c2_i564 = 0; c2_i564 <= c2_ae_loop_ub; c2_i564++) {
    c2_me_metric->data[c2_me_metric->size[0] * c2_me_metric->size[1] * c2_i564] =
      c2_ke_metric->data[c2_iv110[0] * c2_iv110[1] * c2_i564];
  }

  c2_emxFree_real32_T(chartInstance, &c2_ke_metric);
  for (c2_i565 = 0; c2_i565 < 3; c2_i565++) {
    c2_ne_metric[c2_i565] = c2_me_metric->size[c2_i565];
  }

  c2_emxFree_real32_T(chartInstance, &c2_me_metric);
  c2_emxInit_real32_T1(chartInstance, &c2_oe_metric, 1, &c2_pe_emlrtRTEI);
  c2_pe_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i566 = c2_oe_metric->size[0];
  c2_oe_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_oe_metric, c2_i566,
    &c2_pe_emlrtRTEI);
  c2_be_loop_ub = c2_idx->size[0] - 1;
  for (c2_i567 = 0; c2_i567 <= c2_be_loop_ub; c2_i567++) {
    c2_oe_metric->data[c2_i567] = c2_metric->data[c2_idx->data[c2_i567] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_qe_metric, 3, &c2_pf_emlrtRTEI);
  c2_iv112[0] = 3;
  c2_iv112[1] = 3;
  c2_iv112[2] = (int32_T)c2_dv3[2];
  c2_iv113[0] = 3;
  c2_iv113[1] = 3;
  c2_iv113[2] = (int32_T)c2_dv3[2];
  c2_i568 = c2_qe_metric->size[0] * c2_qe_metric->size[1] * c2_qe_metric->size[2];
  c2_qe_metric->size[0] = 1;
  c2_qe_metric->size[1] = 1;
  c2_qe_metric->size[2] = c2_iv113[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_qe_metric, c2_i568,
    &c2_pf_emlrtRTEI);
  c2_ce_loop_ub = c2_iv113[2] - 1;
  for (c2_i569 = 0; c2_i569 <= c2_ce_loop_ub; c2_i569++) {
    c2_qe_metric->data[c2_qe_metric->size[0] * c2_qe_metric->size[1] * c2_i569] =
      c2_oe_metric->data[((c2_iv112[0] << 1) + c2_iv112[0] * c2_iv112[1] *
                          c2_i569) + 2];
  }

  c2_emxFree_real32_T(chartInstance, &c2_oe_metric);
  for (c2_i570 = 0; c2_i570 < 3; c2_i570++) {
    c2_re_metric[c2_i570] = c2_qe_metric->size[c2_i570];
  }

  c2_emxFree_real32_T(chartInstance, &c2_qe_metric);
  _SFD_SIZE_EQ_CHECK_ND(c2_ne_metric, c2_re_metric, 3);
  c2_iv114[0] = 3;
  c2_iv114[1] = 3;
  c2_iv114[2] = (int32_T)c2_dv3[2];
  c2_iv115[0] = 3;
  c2_iv115[1] = 3;
  c2_iv115[2] = (int32_T)c2_dv3[2];
  c2_iv116[0] = 3;
  c2_iv116[1] = 3;
  c2_iv116[2] = (int32_T)c2_dv3[2];
  c2_iv117[0] = 3;
  c2_iv117[1] = 3;
  c2_iv117[2] = (int32_T)c2_dv3[2];
  c2_iv118[0] = 3;
  c2_iv118[1] = 3;
  c2_iv118[2] = (int32_T)c2_dv3[2];
  c2_iv119[0] = 3;
  c2_iv119[1] = 3;
  c2_iv119[2] = (int32_T)c2_dv3[2];
  c2_iv120[0] = 3;
  c2_iv120[1] = 3;
  c2_iv120[2] = (int32_T)c2_dv3[2];
  c2_iv121[0] = 3;
  c2_iv121[1] = 3;
  c2_iv121[2] = (int32_T)c2_dv3[2];
  c2_i571 = c2_xp1->size[0] * c2_xp1->size[1] * c2_xp1->size[2];
  c2_xp1->size[0] = 1;
  c2_xp1->size[1] = 1;
  c2_xp1->size[2] = c2_iv115[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_xp1, c2_i571,
    &c2_qf_emlrtRTEI);
  c2_de_loop_ub = c2_iv115[2] - 1;
  for (c2_i572 = 0; c2_i572 <= c2_de_loop_ub; c2_i572++) {
    c2_xp1->data[c2_xp1->size[0] * c2_xp1->size[1] * c2_i572] =
      (((c2_patch->data[c2_iv114[0] * c2_iv114[1] * c2_i572] - c2_patch->data
         [(c2_iv116[0] << 1) + c2_iv116[0] * c2_iv116[1] * c2_i572]) -
        c2_patch->data[2 + c2_iv118[0] * c2_iv118[1] * c2_i572]) +
       c2_patch->data[((c2_iv120[0] << 1) + c2_iv120[0] * c2_iv120[1] * c2_i572)
       + 2]) / 4.0F;
  }

  c2_iv122[0] = 3;
  c2_iv122[1] = 3;
  c2_iv122[2] = (int32_T)c2_dv3[2];
  c2_iv123[0] = 3;
  c2_iv123[1] = 3;
  c2_iv123[2] = (int32_T)c2_dv3[2];
  c2_i573 = c2_r9->size[0] * c2_r9->size[1] * c2_r9->size[2];
  c2_r9->size[0] = 1;
  c2_r9->size[1] = 1;
  c2_r9->size[2] = c2_iv123[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_r9, c2_i573, &c2_rf_emlrtRTEI);
  c2_ee_loop_ub = c2_iv123[2] - 1;
  for (c2_i574 = 0; c2_i574 <= c2_ee_loop_ub; c2_i574++) {
    c2_r9->data[c2_r9->size[0] * c2_r9->size[1] * c2_i574] = -c2_patch->
      data[c2_iv122[0] * c2_iv122[1] * c2_i574];
  }

  c2_iv124[0] = 3;
  c2_iv124[1] = 3;
  c2_iv124[2] = (int32_T)c2_dv3[2];
  c2_iv125[0] = 3;
  c2_iv125[1] = 3;
  c2_iv125[2] = (int32_T)c2_dv3[2];
  c2_i575 = c2_r10->size[0] * c2_r10->size[1] * c2_r10->size[2];
  c2_r10->size[0] = 1;
  c2_r10->size[1] = 1;
  c2_r10->size[2] = c2_iv125[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_r10, c2_i575,
    &c2_sf_emlrtRTEI);
  c2_fe_loop_ub = c2_iv125[2] - 1;
  for (c2_i576 = 0; c2_i576 <= c2_fe_loop_ub; c2_i576++) {
    c2_r10->data[c2_r10->size[0] * c2_r10->size[1] * c2_i576] = 2.0F *
      c2_patch->data[1 + c2_iv124[0] * c2_iv124[1] * c2_i576];
  }

  for (c2_i577 = 0; c2_i577 < 3; c2_i577++) {
    c2_iv126[c2_i577] = c2_r9->size[c2_i577];
  }

  for (c2_i578 = 0; c2_i578 < 3; c2_i578++) {
    c2_iv127[c2_i578] = c2_r10->size[c2_i578];
  }

  _SFD_SIZE_EQ_CHECK_ND(c2_iv126, c2_iv127, 3);
  for (c2_i579 = 0; c2_i579 < 3; c2_i579++) {
    c2_iv128[c2_i579] = c2_r9->size[c2_i579];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_se_metric, 1, &c2_pe_emlrtRTEI);
  c2_te_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i580 = c2_se_metric->size[0];
  c2_se_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_se_metric, c2_i580,
    &c2_pe_emlrtRTEI);
  c2_ge_loop_ub = c2_idx->size[0] - 1;
  for (c2_i581 = 0; c2_i581 <= c2_ge_loop_ub; c2_i581++) {
    c2_se_metric->data[c2_i581] = c2_metric->data[c2_idx->data[c2_i581] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_ue_metric, 3, &c2_tf_emlrtRTEI);
  c2_iv129[0] = 3;
  c2_iv129[1] = 3;
  c2_iv129[2] = (int32_T)c2_dv3[2];
  c2_iv130[0] = 3;
  c2_iv130[1] = 3;
  c2_iv130[2] = (int32_T)c2_dv3[2];
  c2_i582 = c2_ue_metric->size[0] * c2_ue_metric->size[1] * c2_ue_metric->size[2];
  c2_ue_metric->size[0] = 1;
  c2_ue_metric->size[1] = 1;
  c2_ue_metric->size[2] = c2_iv130[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_ue_metric, c2_i582,
    &c2_tf_emlrtRTEI);
  c2_he_loop_ub = c2_iv130[2] - 1;
  for (c2_i583 = 0; c2_i583 <= c2_he_loop_ub; c2_i583++) {
    c2_ue_metric->data[c2_ue_metric->size[0] * c2_ue_metric->size[1] * c2_i583] =
      c2_se_metric->data[2 + c2_iv129[0] * c2_iv129[1] * c2_i583];
  }

  c2_emxFree_real32_T(chartInstance, &c2_se_metric);
  for (c2_i584 = 0; c2_i584 < 3; c2_i584++) {
    c2_ve_metric[c2_i584] = c2_ue_metric->size[c2_i584];
  }

  c2_emxFree_real32_T(chartInstance, &c2_ue_metric);
  _SFD_SIZE_EQ_CHECK_ND(c2_iv128, c2_ve_metric, 3);
  for (c2_i585 = 0; c2_i585 < 3; c2_i585++) {
    c2_iv131[c2_i585] = c2_r9->size[c2_i585];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_we_metric, 1, &c2_pe_emlrtRTEI);
  c2_xe_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i586 = c2_we_metric->size[0];
  c2_we_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_we_metric, c2_i586,
    &c2_pe_emlrtRTEI);
  c2_ie_loop_ub = c2_idx->size[0] - 1;
  for (c2_i587 = 0; c2_i587 <= c2_ie_loop_ub; c2_i587++) {
    c2_we_metric->data[c2_i587] = c2_metric->data[c2_idx->data[c2_i587] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_ye_metric, 3, &c2_uf_emlrtRTEI);
  c2_iv132[0] = 3;
  c2_iv132[1] = 3;
  c2_iv132[2] = (int32_T)c2_dv3[2];
  c2_iv133[0] = 3;
  c2_iv133[1] = 3;
  c2_iv133[2] = (int32_T)c2_dv3[2];
  c2_i588 = c2_ye_metric->size[0] * c2_ye_metric->size[1] * c2_ye_metric->size[2];
  c2_ye_metric->size[0] = 1;
  c2_ye_metric->size[1] = 1;
  c2_ye_metric->size[2] = c2_iv133[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_ye_metric, c2_i588,
    &c2_uf_emlrtRTEI);
  c2_je_loop_ub = c2_iv133[2] - 1;
  for (c2_i589 = 0; c2_i589 <= c2_je_loop_ub; c2_i589++) {
    c2_ye_metric->data[c2_ye_metric->size[0] * c2_ye_metric->size[1] * c2_i589] =
      c2_we_metric->data[(c2_iv132[0] << 1) + c2_iv132[0] * c2_iv132[1] *
      c2_i589];
  }

  c2_emxFree_real32_T(chartInstance, &c2_we_metric);
  for (c2_i590 = 0; c2_i590 < 3; c2_i590++) {
    c2_af_metric[c2_i590] = c2_ye_metric->size[c2_i590];
  }

  c2_emxFree_real32_T(chartInstance, &c2_ye_metric);
  _SFD_SIZE_EQ_CHECK_ND(c2_iv131, c2_af_metric, 3);
  c2_iv134[0] = 3;
  c2_iv134[1] = 3;
  c2_iv134[2] = (int32_T)c2_dv3[2];
  c2_iv135[0] = 3;
  c2_iv135[1] = 3;
  c2_iv135[2] = (int32_T)c2_dv3[2];
  c2_i591 = c2_r11->size[0] * c2_r11->size[1] * c2_r11->size[2];
  c2_r11->size[0] = 1;
  c2_r11->size[1] = 1;
  c2_r11->size[2] = c2_iv135[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_r11, c2_i591,
    &c2_vf_emlrtRTEI);
  c2_ke_loop_ub = c2_iv135[2] - 1;
  for (c2_i592 = 0; c2_i592 <= c2_ke_loop_ub; c2_i592++) {
    c2_r11->data[c2_r11->size[0] * c2_r11->size[1] * c2_i592] = 2.0F *
      c2_patch->data[((c2_iv134[0] << 1) + c2_iv134[0] * c2_iv134[1] * c2_i592)
      + 1];
  }

  for (c2_i593 = 0; c2_i593 < 3; c2_i593++) {
    c2_iv136[c2_i593] = c2_r9->size[c2_i593];
  }

  for (c2_i594 = 0; c2_i594 < 3; c2_i594++) {
    c2_iv137[c2_i594] = c2_r11->size[c2_i594];
  }

  _SFD_SIZE_EQ_CHECK_ND(c2_iv136, c2_iv137, 3);
  for (c2_i595 = 0; c2_i595 < 3; c2_i595++) {
    c2_iv138[c2_i595] = c2_r9->size[c2_i595];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_bf_metric, 1, &c2_pe_emlrtRTEI);
  c2_cf_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i596 = c2_bf_metric->size[0];
  c2_bf_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_bf_metric, c2_i596,
    &c2_pe_emlrtRTEI);
  c2_le_loop_ub = c2_idx->size[0] - 1;
  for (c2_i597 = 0; c2_i597 <= c2_le_loop_ub; c2_i597++) {
    c2_bf_metric->data[c2_i597] = c2_metric->data[c2_idx->data[c2_i597] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_df_metric, 3, &c2_wf_emlrtRTEI);
  c2_iv139[0] = 3;
  c2_iv139[1] = 3;
  c2_iv139[2] = (int32_T)c2_dv3[2];
  c2_iv140[0] = 3;
  c2_iv140[1] = 3;
  c2_iv140[2] = (int32_T)c2_dv3[2];
  c2_i598 = c2_df_metric->size[0] * c2_df_metric->size[1] * c2_df_metric->size[2];
  c2_df_metric->size[0] = 1;
  c2_df_metric->size[1] = 1;
  c2_df_metric->size[2] = c2_iv140[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_df_metric, c2_i598,
    &c2_wf_emlrtRTEI);
  c2_me_loop_ub = c2_iv140[2] - 1;
  for (c2_i599 = 0; c2_i599 <= c2_me_loop_ub; c2_i599++) {
    c2_df_metric->data[c2_df_metric->size[0] * c2_df_metric->size[1] * c2_i599] =
      c2_bf_metric->data[((c2_iv139[0] << 1) + c2_iv139[0] * c2_iv139[1] *
                          c2_i599) + 2];
  }

  c2_emxFree_real32_T(chartInstance, &c2_bf_metric);
  for (c2_i600 = 0; c2_i600 < 3; c2_i600++) {
    c2_ef_metric[c2_i600] = c2_df_metric->size[c2_i600];
  }

  c2_emxFree_real32_T(chartInstance, &c2_df_metric);
  _SFD_SIZE_EQ_CHECK_ND(c2_iv138, c2_ef_metric, 3);
  c2_iv141[0] = 3;
  c2_iv141[1] = 3;
  c2_iv141[2] = (int32_T)c2_dv3[2];
  c2_iv142[0] = 3;
  c2_iv142[1] = 3;
  c2_iv142[2] = (int32_T)c2_dv3[2];
  c2_iv143[0] = 3;
  c2_iv143[1] = 3;
  c2_iv143[2] = (int32_T)c2_dv3[2];
  c2_iv144[0] = 3;
  c2_iv144[1] = 3;
  c2_iv144[2] = (int32_T)c2_dv3[2];
  c2_iv145[0] = 3;
  c2_iv145[1] = 3;
  c2_iv145[2] = (int32_T)c2_dv3[2];
  c2_iv146[0] = 3;
  c2_iv146[1] = 3;
  c2_iv146[2] = (int32_T)c2_dv3[2];
  c2_i601 = c2_ym1->size[0] * c2_ym1->size[1] * c2_ym1->size[2];
  c2_ym1->size[0] = 1;
  c2_ym1->size[1] = 1;
  c2_ym1->size[2] = c2_r9->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_ym1, c2_i601,
    &c2_xf_emlrtRTEI);
  c2_ne_loop_ub = c2_r9->size[2] - 1;
  for (c2_i602 = 0; c2_i602 <= c2_ne_loop_ub; c2_i602++) {
    c2_ym1->data[c2_ym1->size[0] * c2_ym1->size[1] * c2_i602] = (((((c2_r9->
      data[c2_r9->size[0] * c2_r9->size[1] * c2_i602] - c2_r10->data
      [c2_r10->size[0] * c2_r10->size[1] * c2_i602]) - c2_patch->data[2 +
      c2_iv141[0] * c2_iv141[1] * c2_i602]) + c2_patch->data[(c2_iv143[0] << 1)
      + c2_iv143[0] * c2_iv143[1] * c2_i602]) + c2_r11->data[c2_r11->size[0] *
      c2_r11->size[1] * c2_i602]) + c2_patch->data[((c2_iv145[0] << 1) +
      c2_iv145[0] * c2_iv145[1] * c2_i602) + 2]) / 8.0F;
  }

  c2_iv147[0] = 3;
  c2_iv147[1] = 3;
  c2_iv147[2] = (int32_T)c2_dv3[2];
  c2_iv148[0] = 3;
  c2_iv148[1] = 3;
  c2_iv148[2] = (int32_T)c2_dv3[2];
  c2_i603 = c2_r9->size[0] * c2_r9->size[1] * c2_r9->size[2];
  c2_r9->size[0] = 1;
  c2_r9->size[1] = 1;
  c2_r9->size[2] = c2_iv148[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_r9, c2_i603, &c2_yf_emlrtRTEI);
  c2_oe_loop_ub = c2_iv148[2] - 1;
  for (c2_i604 = 0; c2_i604 <= c2_oe_loop_ub; c2_i604++) {
    c2_r9->data[c2_r9->size[0] * c2_r9->size[1] * c2_i604] = -c2_patch->
      data[c2_iv147[0] * c2_iv147[1] * c2_i604];
  }

  c2_iv149[0] = 3;
  c2_iv149[1] = 3;
  c2_iv149[2] = (int32_T)c2_dv3[2];
  c2_iv150[0] = 3;
  c2_iv150[1] = 3;
  c2_iv150[2] = (int32_T)c2_dv3[2];
  c2_i605 = c2_r10->size[0] * c2_r10->size[1] * c2_r10->size[2];
  c2_r10->size[0] = 1;
  c2_r10->size[1] = 1;
  c2_r10->size[2] = c2_iv150[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_r10, c2_i605,
    &c2_ag_emlrtRTEI);
  c2_pe_loop_ub = c2_iv150[2] - 1;
  for (c2_i606 = 0; c2_i606 <= c2_pe_loop_ub; c2_i606++) {
    c2_r10->data[c2_r10->size[0] * c2_r10->size[1] * c2_i606] = 2.0F *
      c2_patch->data[c2_iv149[0] + c2_iv149[0] * c2_iv149[1] * c2_i606];
  }

  for (c2_i607 = 0; c2_i607 < 3; c2_i607++) {
    c2_iv151[c2_i607] = c2_r9->size[c2_i607];
  }

  for (c2_i608 = 0; c2_i608 < 3; c2_i608++) {
    c2_iv152[c2_i608] = c2_r10->size[c2_i608];
  }

  _SFD_SIZE_EQ_CHECK_ND(c2_iv151, c2_iv152, 3);
  for (c2_i609 = 0; c2_i609 < 3; c2_i609++) {
    c2_iv153[c2_i609] = c2_r9->size[c2_i609];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_ff_metric, 1, &c2_pe_emlrtRTEI);
  c2_gf_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i610 = c2_ff_metric->size[0];
  c2_ff_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_ff_metric, c2_i610,
    &c2_pe_emlrtRTEI);
  c2_qe_loop_ub = c2_idx->size[0] - 1;
  for (c2_i611 = 0; c2_i611 <= c2_qe_loop_ub; c2_i611++) {
    c2_ff_metric->data[c2_i611] = c2_metric->data[c2_idx->data[c2_i611] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_hf_metric, 3, &c2_bg_emlrtRTEI);
  c2_iv154[0] = 3;
  c2_iv154[1] = 3;
  c2_iv154[2] = (int32_T)c2_dv3[2];
  c2_iv155[0] = 3;
  c2_iv155[1] = 3;
  c2_iv155[2] = (int32_T)c2_dv3[2];
  c2_i612 = c2_hf_metric->size[0] * c2_hf_metric->size[1] * c2_hf_metric->size[2];
  c2_hf_metric->size[0] = 1;
  c2_hf_metric->size[1] = 1;
  c2_hf_metric->size[2] = c2_iv155[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_hf_metric, c2_i612,
    &c2_bg_emlrtRTEI);
  c2_re_loop_ub = c2_iv155[2] - 1;
  for (c2_i613 = 0; c2_i613 <= c2_re_loop_ub; c2_i613++) {
    c2_hf_metric->data[c2_hf_metric->size[0] * c2_hf_metric->size[1] * c2_i613] =
      c2_ff_metric->data[(c2_iv154[0] << 1) + c2_iv154[0] * c2_iv154[1] *
      c2_i613];
  }

  c2_emxFree_real32_T(chartInstance, &c2_ff_metric);
  for (c2_i614 = 0; c2_i614 < 3; c2_i614++) {
    c2_if_metric[c2_i614] = c2_hf_metric->size[c2_i614];
  }

  c2_emxFree_real32_T(chartInstance, &c2_hf_metric);
  _SFD_SIZE_EQ_CHECK_ND(c2_iv153, c2_if_metric, 3);
  for (c2_i615 = 0; c2_i615 < 3; c2_i615++) {
    c2_iv156[c2_i615] = c2_r9->size[c2_i615];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_jf_metric, 1, &c2_pe_emlrtRTEI);
  c2_kf_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i616 = c2_jf_metric->size[0];
  c2_jf_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_jf_metric, c2_i616,
    &c2_pe_emlrtRTEI);
  c2_se_loop_ub = c2_idx->size[0] - 1;
  for (c2_i617 = 0; c2_i617 <= c2_se_loop_ub; c2_i617++) {
    c2_jf_metric->data[c2_i617] = c2_metric->data[c2_idx->data[c2_i617] - 1];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_lf_metric, 3, &c2_cg_emlrtRTEI);
  c2_iv157[0] = 3;
  c2_iv157[1] = 3;
  c2_iv157[2] = (int32_T)c2_dv3[2];
  c2_iv158[0] = 3;
  c2_iv158[1] = 3;
  c2_iv158[2] = (int32_T)c2_dv3[2];
  c2_i618 = c2_lf_metric->size[0] * c2_lf_metric->size[1] * c2_lf_metric->size[2];
  c2_lf_metric->size[0] = 1;
  c2_lf_metric->size[1] = 1;
  c2_lf_metric->size[2] = c2_iv158[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_lf_metric, c2_i618,
    &c2_cg_emlrtRTEI);
  c2_te_loop_ub = c2_iv158[2] - 1;
  for (c2_i619 = 0; c2_i619 <= c2_te_loop_ub; c2_i619++) {
    c2_lf_metric->data[c2_lf_metric->size[0] * c2_lf_metric->size[1] * c2_i619] =
      c2_jf_metric->data[2 + c2_iv157[0] * c2_iv157[1] * c2_i619];
  }

  c2_emxFree_real32_T(chartInstance, &c2_jf_metric);
  for (c2_i620 = 0; c2_i620 < 3; c2_i620++) {
    c2_mf_metric[c2_i620] = c2_lf_metric->size[c2_i620];
  }

  c2_emxFree_real32_T(chartInstance, &c2_lf_metric);
  _SFD_SIZE_EQ_CHECK_ND(c2_iv156, c2_mf_metric, 3);
  c2_iv159[0] = 3;
  c2_iv159[1] = 3;
  c2_iv159[2] = (int32_T)c2_dv3[2];
  c2_iv160[0] = 3;
  c2_iv160[1] = 3;
  c2_iv160[2] = (int32_T)c2_dv3[2];
  c2_i621 = c2_r11->size[0] * c2_r11->size[1] * c2_r11->size[2];
  c2_r11->size[0] = 1;
  c2_r11->size[1] = 1;
  c2_r11->size[2] = c2_iv160[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_r11, c2_i621,
    &c2_dg_emlrtRTEI);
  c2_ue_loop_ub = c2_iv160[2] - 1;
  for (c2_i622 = 0; c2_i622 <= c2_ue_loop_ub; c2_i622++) {
    c2_r11->data[c2_r11->size[0] * c2_r11->size[1] * c2_i622] = 2.0F *
      c2_patch->data[(c2_iv159[0] + c2_iv159[0] * c2_iv159[1] * c2_i622) + 2];
  }

  for (c2_i623 = 0; c2_i623 < 3; c2_i623++) {
    c2_iv161[c2_i623] = c2_r9->size[c2_i623];
  }

  for (c2_i624 = 0; c2_i624 < 3; c2_i624++) {
    c2_iv162[c2_i624] = c2_r11->size[c2_i624];
  }

  _SFD_SIZE_EQ_CHECK_ND(c2_iv161, c2_iv162, 3);
  for (c2_i625 = 0; c2_i625 < 3; c2_i625++) {
    c2_iv163[c2_i625] = c2_r9->size[c2_i625];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_nf_metric, 1, &c2_pe_emlrtRTEI);
  c2_of_metric[0] = c2_metric->size[0] * c2_metric->size[1];
  c2_i626 = c2_nf_metric->size[0];
  c2_nf_metric->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_nf_metric, c2_i626,
    &c2_pe_emlrtRTEI);
  c2_ve_loop_ub = c2_idx->size[0] - 1;
  for (c2_i627 = 0; c2_i627 <= c2_ve_loop_ub; c2_i627++) {
    c2_nf_metric->data[c2_i627] = c2_metric->data[c2_idx->data[c2_i627] - 1];
  }

  c2_emxFree_int32_T(chartInstance, &c2_idx);
  c2_emxInit_real32_T2(chartInstance, &c2_pf_metric, 3, &c2_eg_emlrtRTEI);
  c2_iv164[0] = 3;
  c2_iv164[1] = 3;
  c2_iv164[2] = (int32_T)c2_dv3[2];
  c2_iv165[0] = 3;
  c2_iv165[1] = 3;
  c2_iv165[2] = (int32_T)c2_dv3[2];
  c2_i628 = c2_pf_metric->size[0] * c2_pf_metric->size[1] * c2_pf_metric->size[2];
  c2_pf_metric->size[0] = 1;
  c2_pf_metric->size[1] = 1;
  c2_pf_metric->size[2] = c2_iv165[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_pf_metric, c2_i628,
    &c2_eg_emlrtRTEI);
  c2_we_loop_ub = c2_iv165[2] - 1;
  for (c2_i629 = 0; c2_i629 <= c2_we_loop_ub; c2_i629++) {
    c2_pf_metric->data[c2_pf_metric->size[0] * c2_pf_metric->size[1] * c2_i629] =
      c2_nf_metric->data[((c2_iv164[0] << 1) + c2_iv164[0] * c2_iv164[1] *
                          c2_i629) + 2];
  }

  c2_emxFree_real32_T(chartInstance, &c2_nf_metric);
  for (c2_i630 = 0; c2_i630 < 3; c2_i630++) {
    c2_qf_metric[c2_i630] = c2_pf_metric->size[c2_i630];
  }

  c2_emxFree_real32_T(chartInstance, &c2_pf_metric);
  _SFD_SIZE_EQ_CHECK_ND(c2_iv163, c2_qf_metric, 3);
  c2_iv166[0] = 3;
  c2_iv166[1] = 3;
  c2_iv166[2] = (int32_T)c2_dv3[2];
  c2_iv167[0] = 3;
  c2_iv167[1] = 3;
  c2_iv167[2] = (int32_T)c2_dv3[2];
  c2_iv168[0] = 3;
  c2_iv168[1] = 3;
  c2_iv168[2] = (int32_T)c2_dv3[2];
  c2_iv169[0] = 3;
  c2_iv169[1] = 3;
  c2_iv169[2] = (int32_T)c2_dv3[2];
  c2_iv170[0] = 3;
  c2_iv170[1] = 3;
  c2_iv170[2] = (int32_T)c2_dv3[2];
  c2_iv171[0] = 3;
  c2_iv171[1] = 3;
  c2_iv171[2] = (int32_T)c2_dv3[2];
  c2_i631 = c2_yp1->size[0] * c2_yp1->size[1] * c2_yp1->size[2];
  c2_yp1->size[0] = 1;
  c2_yp1->size[1] = 1;
  c2_yp1->size[2] = c2_r9->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_yp1, c2_i631,
    &c2_fg_emlrtRTEI);
  c2_xe_loop_ub = c2_r9->size[2] - 1;
  for (c2_i632 = 0; c2_i632 <= c2_xe_loop_ub; c2_i632++) {
    c2_yp1->data[c2_yp1->size[0] * c2_yp1->size[1] * c2_i632] = (((((c2_r9->
      data[c2_r9->size[0] * c2_r9->size[1] * c2_i632] - c2_r10->data
      [c2_r10->size[0] * c2_r10->size[1] * c2_i632]) - c2_patch->data[(c2_iv166
      [0] << 1) + c2_iv166[0] * c2_iv166[1] * c2_i632]) + c2_patch->data[2 +
      c2_iv168[0] * c2_iv168[1] * c2_i632]) + c2_r11->data[c2_r11->size[0] *
      c2_r11->size[1] * c2_i632]) + c2_patch->data[((c2_iv170[0] << 1) +
      c2_iv170[0] * c2_iv170[1] * c2_i632) + 2]) / 8.0F;
  }

  c2_emxFree_real32_T(chartInstance, &c2_r11);
  c2_emxFree_real32_T(chartInstance, &c2_r10);
  c2_emxFree_real32_T(chartInstance, &c2_patch);
  for (c2_i633 = 0; c2_i633 < 3; c2_i633++) {
    c2_b_dx2[c2_i633] = c2_dx2->size[c2_i633];
  }

  for (c2_i634 = 0; c2_i634 < 3; c2_i634++) {
    c2_b_dy2[c2_i634] = c2_dy2->size[c2_i634];
  }

  _SFD_SIZE_EQ_CHECK_ND(c2_b_dx2, c2_b_dy2, 3);
  c2_i635 = c2_r9->size[0] * c2_r9->size[1] * c2_r9->size[2];
  c2_r9->size[0] = 1;
  c2_r9->size[1] = 1;
  c2_r9->size[2] = c2_xp1->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_r9, c2_i635, &c2_gg_emlrtRTEI);
  c2_i636 = c2_r9->size[0];
  c2_i637 = c2_r9->size[1];
  c2_i638 = c2_r9->size[2];
  c2_ye_loop_ub = c2_xp1->size[0] * c2_xp1->size[1] * c2_xp1->size[2] - 1;
  for (c2_i639 = 0; c2_i639 <= c2_ye_loop_ub; c2_i639++) {
    c2_r9->data[c2_i639] = 0.25F * c2_xp1->data[c2_i639];
  }

  for (c2_i640 = 0; c2_i640 < 3; c2_i640++) {
    c2_iv172[c2_i640] = c2_r9->size[c2_i640];
  }

  for (c2_i641 = 0; c2_i641 < 3; c2_i641++) {
    c2_f_xp1[c2_i641] = c2_xp1->size[c2_i641];
  }

  _SFD_SIZE_EQ_CHECK_ND(c2_iv172, c2_f_xp1, 3);
  c2_i642 = c2_xm1->size[0] * c2_xm1->size[1] * c2_xm1->size[2];
  c2_xm1->size[0] = 1;
  c2_xm1->size[1] = 1;
  c2_xm1->size[2] = c2_dx2->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_xm1, c2_i642,
    &c2_hg_emlrtRTEI);
  c2_f_xm1 = c2_xm1->size[0];
  c2_g_xm1 = c2_xm1->size[1];
  c2_h_xm1 = c2_xm1->size[2];
  c2_af_loop_ub = c2_dx2->size[0] * c2_dx2->size[1] * c2_dx2->size[2] - 1;
  for (c2_i643 = 0; c2_i643 <= c2_af_loop_ub; c2_i643++) {
    c2_xm1->data[c2_i643] = c2_dx2->data[c2_i643] * c2_dy2->data[c2_i643];
  }

  c2_i644 = c2_r9->size[0] * c2_r9->size[1] * c2_r9->size[2];
  c2_r9->size[0] = 1;
  c2_r9->size[1] = 1;
  c2_r9->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_r9, c2_i644, &c2_gg_emlrtRTEI);
  c2_i645 = c2_r9->size[0];
  c2_i646 = c2_r9->size[1];
  c2_i647 = c2_r9->size[2];
  c2_i648 = c2_r9->size[0];
  c2_i649 = c2_r9->size[1];
  c2_i650 = c2_r9->size[2];
  c2_bf_loop_ub = c2_i645 * c2_i646 * c2_i647 - 1;
  for (c2_i651 = 0; c2_i651 <= c2_bf_loop_ub; c2_i651++) {
    c2_r9->data[c2_i651] *= c2_xp1->data[c2_i651];
  }

  for (c2_i652 = 0; c2_i652 < 3; c2_i652++) {
    c2_i_xm1[c2_i652] = c2_xm1->size[c2_i652];
  }

  for (c2_i653 = 0; c2_i653 < 3; c2_i653++) {
    c2_iv173[c2_i653] = c2_r9->size[c2_i653];
  }

  _SFD_SIZE_EQ_CHECK_ND(c2_i_xm1, c2_iv173, 3);
  c2_i654 = c2_xm1->size[0] * c2_xm1->size[1] * c2_xm1->size[2];
  c2_xm1->size[0] = 1;
  c2_xm1->size[1] = 1;
  c2_xm1->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_xm1, c2_i654,
    &c2_ig_emlrtRTEI);
  c2_j_xm1 = c2_xm1->size[0];
  c2_k_xm1 = c2_xm1->size[1];
  c2_l_xm1 = c2_xm1->size[2];
  c2_m_xm1 = c2_xm1->size[0];
  c2_n_xm1 = c2_xm1->size[1];
  c2_o_xm1 = c2_xm1->size[2];
  c2_cf_loop_ub = c2_j_xm1 * c2_k_xm1 * c2_l_xm1 - 1;
  for (c2_i655 = 0; c2_i655 <= c2_cf_loop_ub; c2_i655++) {
    c2_xm1->data[c2_i655] = 1.0F / (c2_xm1->data[c2_i655] - c2_r9->data[c2_i655]);
  }

  for (c2_i656 = 0; c2_i656 < 3; c2_i656++) {
    c2_c_dy2[c2_i656] = c2_dy2->size[c2_i656];
  }

  for (c2_i657 = 0; c2_i657 < 3; c2_i657++) {
    c2_e_ym1[c2_i657] = c2_ym1->size[c2_i657];
  }

  _SFD_SIZE_EQ_CHECK_ND(c2_c_dy2, c2_e_ym1, 3);
  c2_i658 = c2_r9->size[0] * c2_r9->size[1] * c2_r9->size[2];
  c2_r9->size[0] = 1;
  c2_r9->size[1] = 1;
  c2_r9->size[2] = c2_xp1->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_r9, c2_i658, &c2_jg_emlrtRTEI);
  c2_i659 = c2_r9->size[0];
  c2_i660 = c2_r9->size[1];
  c2_i661 = c2_r9->size[2];
  c2_df_loop_ub = c2_xp1->size[0] * c2_xp1->size[1] * c2_xp1->size[2] - 1;
  for (c2_i662 = 0; c2_i662 <= c2_df_loop_ub; c2_i662++) {
    c2_r9->data[c2_i662] = 0.5F * c2_xp1->data[c2_i662];
  }

  for (c2_i663 = 0; c2_i663 < 3; c2_i663++) {
    c2_iv174[c2_i663] = c2_r9->size[c2_i663];
  }

  for (c2_i664 = 0; c2_i664 < 3; c2_i664++) {
    c2_e_yp1[c2_i664] = c2_yp1->size[c2_i664];
  }

  _SFD_SIZE_EQ_CHECK_ND(c2_iv174, c2_e_yp1, 3);
  c2_i665 = c2_dy2->size[0] * c2_dy2->size[1] * c2_dy2->size[2];
  c2_dy2->size[0] = 1;
  c2_dy2->size[1] = 1;
  c2_dy2->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_dy2, c2_i665,
    &c2_kg_emlrtRTEI);
  c2_d_dy2 = c2_dy2->size[0];
  c2_e_dy2 = c2_dy2->size[1];
  c2_f_dy2 = c2_dy2->size[2];
  c2_g_dy2 = c2_dy2->size[0];
  c2_h_dy2 = c2_dy2->size[1];
  c2_i_dy2 = c2_dy2->size[2];
  c2_ef_loop_ub = c2_d_dy2 * c2_e_dy2 * c2_f_dy2 - 1;
  for (c2_i666 = 0; c2_i666 <= c2_ef_loop_ub; c2_i666++) {
    c2_dy2->data[c2_i666] *= c2_ym1->data[c2_i666];
  }

  c2_i667 = c2_r9->size[0] * c2_r9->size[1] * c2_r9->size[2];
  c2_r9->size[0] = 1;
  c2_r9->size[1] = 1;
  c2_r9->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_r9, c2_i667, &c2_jg_emlrtRTEI);
  c2_i668 = c2_r9->size[0];
  c2_i669 = c2_r9->size[1];
  c2_i670 = c2_r9->size[2];
  c2_i671 = c2_r9->size[0];
  c2_i672 = c2_r9->size[1];
  c2_i673 = c2_r9->size[2];
  c2_ff_loop_ub = c2_i668 * c2_i669 * c2_i670 - 1;
  for (c2_i674 = 0; c2_i674 <= c2_ff_loop_ub; c2_i674++) {
    c2_r9->data[c2_i674] *= c2_yp1->data[c2_i674];
  }

  for (c2_i675 = 0; c2_i675 < 3; c2_i675++) {
    c2_j_dy2[c2_i675] = c2_dy2->size[c2_i675];
  }

  for (c2_i676 = 0; c2_i676 < 3; c2_i676++) {
    c2_iv175[c2_i676] = c2_r9->size[c2_i676];
  }

  _SFD_SIZE_EQ_CHECK_ND(c2_j_dy2, c2_iv175, 3);
  c2_i677 = c2_dy2->size[0] * c2_dy2->size[1] * c2_dy2->size[2];
  c2_dy2->size[0] = 1;
  c2_dy2->size[1] = 1;
  c2_dy2->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_dy2, c2_i677,
    &c2_lg_emlrtRTEI);
  c2_k_dy2 = c2_dy2->size[0];
  c2_l_dy2 = c2_dy2->size[1];
  c2_m_dy2 = c2_dy2->size[2];
  c2_n_dy2 = c2_dy2->size[0];
  c2_o_dy2 = c2_dy2->size[1];
  c2_p_dy2 = c2_dy2->size[2];
  c2_gf_loop_ub = c2_k_dy2 * c2_l_dy2 * c2_m_dy2 - 1;
  for (c2_i678 = 0; c2_i678 <= c2_gf_loop_ub; c2_i678++) {
    c2_dy2->data[c2_i678] = -0.5F * (c2_dy2->data[c2_i678] - c2_r9->data[c2_i678]);
  }

  for (c2_i679 = 0; c2_i679 < 3; c2_i679++) {
    c2_q_dy2[c2_i679] = c2_dy2->size[c2_i679];
  }

  for (c2_i680 = 0; c2_i680 < 3; c2_i680++) {
    c2_p_xm1[c2_i680] = c2_xm1->size[c2_i680];
  }

  _SFD_SIZE_EQ_CHECK_ND(c2_q_dy2, c2_p_xm1, 3);
  c2_i681 = c2_dy2->size[0] * c2_dy2->size[1] * c2_dy2->size[2];
  c2_dy2->size[0] = 1;
  c2_dy2->size[1] = 1;
  c2_dy2->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_dy2, c2_i681,
    &c2_mg_emlrtRTEI);
  c2_r_dy2 = c2_dy2->size[0];
  c2_s_dy2 = c2_dy2->size[1];
  c2_t_dy2 = c2_dy2->size[2];
  c2_u_dy2 = c2_dy2->size[0];
  c2_v_dy2 = c2_dy2->size[1];
  c2_w_dy2 = c2_dy2->size[2];
  c2_hf_loop_ub = c2_r_dy2 * c2_s_dy2 * c2_t_dy2 - 1;
  for (c2_i682 = 0; c2_i682 <= c2_hf_loop_ub; c2_i682++) {
    c2_dy2->data[c2_i682] *= c2_xm1->data[c2_i682];
  }

  for (c2_i683 = 0; c2_i683 < 3; c2_i683++) {
    c2_c_dx2[c2_i683] = c2_dx2->size[c2_i683];
  }

  for (c2_i684 = 0; c2_i684 < 3; c2_i684++) {
    c2_f_yp1[c2_i684] = c2_yp1->size[c2_i684];
  }

  _SFD_SIZE_EQ_CHECK_ND(c2_c_dx2, c2_f_yp1, 3);
  c2_i685 = c2_xp1->size[0] * c2_xp1->size[1] * c2_xp1->size[2];
  c2_xp1->size[0] = 1;
  c2_xp1->size[1] = 1;
  c2_xp1->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_xp1, c2_i685,
    &c2_ng_emlrtRTEI);
  c2_g_xp1 = c2_xp1->size[0];
  c2_h_xp1 = c2_xp1->size[1];
  c2_i_xp1 = c2_xp1->size[2];
  c2_j_xp1 = c2_xp1->size[0];
  c2_k_xp1 = c2_xp1->size[1];
  c2_l_xp1 = c2_xp1->size[2];
  c2_if_loop_ub = c2_g_xp1 * c2_h_xp1 * c2_i_xp1 - 1;
  for (c2_i686 = 0; c2_i686 <= c2_if_loop_ub; c2_i686++) {
    c2_xp1->data[c2_i686] *= 0.5F;
  }

  for (c2_i687 = 0; c2_i687 < 3; c2_i687++) {
    c2_m_xp1[c2_i687] = c2_xp1->size[c2_i687];
  }

  for (c2_i688 = 0; c2_i688 < 3; c2_i688++) {
    c2_f_ym1[c2_i688] = c2_ym1->size[c2_i688];
  }

  _SFD_SIZE_EQ_CHECK_ND(c2_m_xp1, c2_f_ym1, 3);
  c2_i689 = c2_dx2->size[0] * c2_dx2->size[1] * c2_dx2->size[2];
  c2_dx2->size[0] = 1;
  c2_dx2->size[1] = 1;
  c2_dx2->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_dx2, c2_i689,
    &c2_og_emlrtRTEI);
  c2_d_dx2 = c2_dx2->size[0];
  c2_e_dx2 = c2_dx2->size[1];
  c2_f_dx2 = c2_dx2->size[2];
  c2_g_dx2 = c2_dx2->size[0];
  c2_h_dx2 = c2_dx2->size[1];
  c2_i_dx2 = c2_dx2->size[2];
  c2_jf_loop_ub = c2_d_dx2 * c2_e_dx2 * c2_f_dx2 - 1;
  for (c2_i690 = 0; c2_i690 <= c2_jf_loop_ub; c2_i690++) {
    c2_dx2->data[c2_i690] *= c2_yp1->data[c2_i690];
  }

  c2_emxFree_real32_T(chartInstance, &c2_yp1);
  c2_i691 = c2_xp1->size[0] * c2_xp1->size[1] * c2_xp1->size[2];
  c2_xp1->size[0] = 1;
  c2_xp1->size[1] = 1;
  c2_xp1->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_xp1, c2_i691,
    &c2_ng_emlrtRTEI);
  c2_n_xp1 = c2_xp1->size[0];
  c2_o_xp1 = c2_xp1->size[1];
  c2_p_xp1 = c2_xp1->size[2];
  c2_q_xp1 = c2_xp1->size[0];
  c2_r_xp1 = c2_xp1->size[1];
  c2_s_xp1 = c2_xp1->size[2];
  c2_kf_loop_ub = c2_n_xp1 * c2_o_xp1 * c2_p_xp1 - 1;
  for (c2_i692 = 0; c2_i692 <= c2_kf_loop_ub; c2_i692++) {
    c2_xp1->data[c2_i692] *= c2_ym1->data[c2_i692];
  }

  c2_emxFree_real32_T(chartInstance, &c2_ym1);
  for (c2_i693 = 0; c2_i693 < 3; c2_i693++) {
    c2_j_dx2[c2_i693] = c2_dx2->size[c2_i693];
  }

  for (c2_i694 = 0; c2_i694 < 3; c2_i694++) {
    c2_t_xp1[c2_i694] = c2_xp1->size[c2_i694];
  }

  _SFD_SIZE_EQ_CHECK_ND(c2_j_dx2, c2_t_xp1, 3);
  c2_i695 = c2_dx2->size[0] * c2_dx2->size[1] * c2_dx2->size[2];
  c2_dx2->size[0] = 1;
  c2_dx2->size[1] = 1;
  c2_dx2->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_dx2, c2_i695,
    &c2_pg_emlrtRTEI);
  c2_k_dx2 = c2_dx2->size[0];
  c2_l_dx2 = c2_dx2->size[1];
  c2_m_dx2 = c2_dx2->size[2];
  c2_n_dx2 = c2_dx2->size[0];
  c2_o_dx2 = c2_dx2->size[1];
  c2_p_dx2 = c2_dx2->size[2];
  c2_lf_loop_ub = c2_k_dx2 * c2_l_dx2 * c2_m_dx2 - 1;
  for (c2_i696 = 0; c2_i696 <= c2_lf_loop_ub; c2_i696++) {
    c2_dx2->data[c2_i696] = -0.5F * (c2_dx2->data[c2_i696] - c2_xp1->
      data[c2_i696]);
  }

  c2_emxFree_real32_T(chartInstance, &c2_xp1);
  for (c2_i697 = 0; c2_i697 < 3; c2_i697++) {
    c2_q_dx2[c2_i697] = c2_dx2->size[c2_i697];
  }

  for (c2_i698 = 0; c2_i698 < 3; c2_i698++) {
    c2_q_xm1[c2_i698] = c2_xm1->size[c2_i698];
  }

  _SFD_SIZE_EQ_CHECK_ND(c2_q_dx2, c2_q_xm1, 3);
  c2_i699 = c2_dx2->size[0] * c2_dx2->size[1] * c2_dx2->size[2];
  c2_dx2->size[0] = 1;
  c2_dx2->size[1] = 1;
  c2_dx2->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_dx2, c2_i699,
    &c2_qg_emlrtRTEI);
  c2_r_dx2 = c2_dx2->size[0];
  c2_s_dx2 = c2_dx2->size[1];
  c2_t_dx2 = c2_dx2->size[2];
  c2_u_dx2 = c2_dx2->size[0];
  c2_v_dx2 = c2_dx2->size[1];
  c2_w_dx2 = c2_dx2->size[2];
  c2_mf_loop_ub = c2_r_dx2 * c2_s_dx2 * c2_t_dx2 - 1;
  for (c2_i700 = 0; c2_i700 <= c2_mf_loop_ub; c2_i700++) {
    c2_dx2->data[c2_i700] *= c2_xm1->data[c2_i700];
  }

  c2_emxFree_real32_T(chartInstance, &c2_xm1);
  c2_emxInit_real32_T2(chartInstance, &c2_x_dy2, 3, &c2_rg_emlrtRTEI);
  c2_i701 = c2_x_dy2->size[0] * c2_x_dy2->size[1] * c2_x_dy2->size[2];
  c2_x_dy2->size[0] = 1;
  c2_x_dy2->size[1] = 1;
  c2_x_dy2->size[2] = c2_dy2->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_x_dy2, c2_i701,
    &c2_rg_emlrtRTEI);
  c2_y_dy2 = c2_x_dy2->size[0];
  c2_ab_dy2 = c2_x_dy2->size[1];
  c2_bb_dy2 = c2_x_dy2->size[2];
  c2_nf_loop_ub = c2_dy2->size[0] * c2_dy2->size[1] * c2_dy2->size[2] - 1;
  for (c2_i702 = 0; c2_i702 <= c2_nf_loop_ub; c2_i702++) {
    c2_x_dy2->data[c2_i702] = c2_dy2->data[c2_i702];
  }

  c2_emxInit_boolean_T1(chartInstance, &c2_r12, 3, &c2_ah_emlrtRTEI);
  c2_abs(chartInstance, c2_x_dy2, c2_r9);
  c2_i703 = c2_r12->size[0] * c2_r12->size[1] * c2_r12->size[2];
  c2_r12->size[0] = 1;
  c2_r12->size[1] = 1;
  c2_r12->size[2] = c2_r9->size[2];
  c2_emxEnsureCapacity_boolean_T1(chartInstance, c2_r12, c2_i703,
    &c2_sg_emlrtRTEI);
  c2_i704 = c2_r12->size[0];
  c2_i705 = c2_r12->size[1];
  c2_i706 = c2_r12->size[2];
  c2_of_loop_ub = c2_r9->size[0] * c2_r9->size[1] * c2_r9->size[2] - 1;
  c2_emxFree_real32_T(chartInstance, &c2_x_dy2);
  for (c2_i707 = 0; c2_i707 <= c2_of_loop_ub; c2_i707++) {
    c2_r12->data[c2_i707] = (c2_r9->data[c2_i707] < 1.0F);
  }

  c2_emxInit_real32_T2(chartInstance, &c2_x_dx2, 3, &c2_tg_emlrtRTEI);
  c2_i708 = c2_x_dx2->size[0] * c2_x_dx2->size[1] * c2_x_dx2->size[2];
  c2_x_dx2->size[0] = 1;
  c2_x_dx2->size[1] = 1;
  c2_x_dx2->size[2] = c2_dx2->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_x_dx2, c2_i708,
    &c2_tg_emlrtRTEI);
  c2_y_dx2 = c2_x_dx2->size[0];
  c2_ab_dx2 = c2_x_dx2->size[1];
  c2_bb_dx2 = c2_x_dx2->size[2];
  c2_pf_loop_ub = c2_dx2->size[0] * c2_dx2->size[1] * c2_dx2->size[2] - 1;
  for (c2_i709 = 0; c2_i709 <= c2_pf_loop_ub; c2_i709++) {
    c2_x_dx2->data[c2_i709] = c2_dx2->data[c2_i709];
  }

  c2_emxInit_boolean_T1(chartInstance, &c2_r13, 3, &c2_ah_emlrtRTEI);
  c2_abs(chartInstance, c2_x_dx2, c2_r9);
  c2_i710 = c2_r13->size[0] * c2_r13->size[1] * c2_r13->size[2];
  c2_r13->size[0] = 1;
  c2_r13->size[1] = 1;
  c2_r13->size[2] = c2_r9->size[2];
  c2_emxEnsureCapacity_boolean_T1(chartInstance, c2_r13, c2_i710,
    &c2_ug_emlrtRTEI);
  c2_i711 = c2_r13->size[0];
  c2_i712 = c2_r13->size[1];
  c2_i713 = c2_r13->size[2];
  c2_qf_loop_ub = c2_r9->size[0] * c2_r9->size[1] * c2_r9->size[2] - 1;
  c2_emxFree_real32_T(chartInstance, &c2_x_dx2);
  for (c2_i714 = 0; c2_i714 <= c2_qf_loop_ub; c2_i714++) {
    c2_r13->data[c2_i714] = (c2_r9->data[c2_i714] < 1.0F);
  }

  c2_emxFree_real32_T(chartInstance, &c2_r9);
  for (c2_i715 = 0; c2_i715 < 3; c2_i715++) {
    c2_iv176[c2_i715] = c2_r12->size[c2_i715];
  }

  for (c2_i716 = 0; c2_i716 < 3; c2_i716++) {
    c2_iv177[c2_i716] = c2_r13->size[c2_i716];
  }

  c2_emxInit_boolean_T1(chartInstance, &c2_r14, 3, &c2_vg_emlrtRTEI);
  _SFD_SIZE_EQ_CHECK_ND(c2_iv176, c2_iv177, 3);
  c2_i717 = c2_r14->size[0] * c2_r14->size[1] * c2_r14->size[2];
  c2_r14->size[0] = 1;
  c2_r14->size[1] = 1;
  c2_r14->size[2] = c2_r12->size[2];
  c2_emxEnsureCapacity_boolean_T1(chartInstance, c2_r14, c2_i717,
    &c2_vg_emlrtRTEI);
  c2_i718 = c2_r14->size[0];
  c2_i719 = c2_r14->size[1];
  c2_i720 = c2_r14->size[2];
  c2_rf_loop_ub = c2_r12->size[0] * c2_r12->size[1] * c2_r12->size[2] - 1;
  for (c2_i721 = 0; c2_i721 <= c2_rf_loop_ub; c2_i721++) {
    c2_r14->data[c2_i721] = !(c2_r12->data[c2_i721] && c2_r13->data[c2_i721]);
  }

  for (c2_i = 0; c2_i < c2_r14->size[2]; c2_i++) {
    if (!(c2_r12->data[c2_i] && c2_r13->data[c2_i])) {
      c2_dy2->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_i + 1, 1, c2_dy2->size[2])
        - 1] = 0.0F;
    }
  }

  c2_i722 = c2_r14->size[0] * c2_r14->size[1] * c2_r14->size[2];
  c2_r14->size[0] = 1;
  c2_r14->size[1] = 1;
  c2_r14->size[2] = c2_r12->size[2];
  c2_emxEnsureCapacity_boolean_T1(chartInstance, c2_r14, c2_i722,
    &c2_wg_emlrtRTEI);
  c2_i723 = c2_r14->size[0];
  c2_i724 = c2_r14->size[1];
  c2_i725 = c2_r14->size[2];
  c2_sf_loop_ub = c2_r12->size[0] * c2_r12->size[1] * c2_r12->size[2] - 1;
  for (c2_i726 = 0; c2_i726 <= c2_sf_loop_ub; c2_i726++) {
    c2_r14->data[c2_i726] = !(c2_r12->data[c2_i726] && c2_r13->data[c2_i726]);
  }

  for (c2_b_i = 0; c2_b_i < c2_r14->size[2]; c2_b_i++) {
    if (!(c2_r12->data[c2_b_i] && c2_r13->data[c2_b_i])) {
      c2_dx2->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_b_i + 1, 1, c2_dx2->size[2])
        - 1] = 0.0F;
    }
  }

  c2_emxFree_boolean_T(chartInstance, &c2_r14);
  c2_emxFree_boolean_T(chartInstance, &c2_r13);
  c2_emxFree_boolean_T(chartInstance, &c2_r12);
  c2_b19 = true;
  if (c2_b19) {
  } else {
    c2_y_y = NULL;
    sf_mex_assign(&c2_y_y, sf_mex_create("y", c2_cv35, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_y_y));
  }

  if (c2_dx2->size[2] == c2_dy2->size[2]) {
  } else {
    c2_b19 = false;
  }

  if (c2_b19) {
  } else {
    c2_ab_y = NULL;
    sf_mex_assign(&c2_ab_y, sf_mex_create("y", c2_cv35, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_ab_y));
  }

  c2_i727 = c2_subPixelLoc->size[0] * c2_subPixelLoc->size[1] *
    c2_subPixelLoc->size[2];
  c2_subPixelLoc->size[0] = 2;
  c2_subPixelLoc->size[1] = 1;
  c2_subPixelLoc->size[2] = c2_dy2->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_subPixelLoc, c2_i727,
    &c2_xg_emlrtRTEI);
  c2_tf_loop_ub = c2_dy2->size[2] - 1;
  for (c2_i728 = 0; c2_i728 <= c2_tf_loop_ub; c2_i728++) {
    c2_subPixelLoc->data[c2_subPixelLoc->size[0] * c2_subPixelLoc->size[1] *
      c2_i728] = c2_dy2->data[c2_dy2->size[0] * c2_dy2->size[1] * c2_i728];
  }

  c2_emxFree_real32_T(chartInstance, &c2_dy2);
  c2_uf_loop_ub = c2_dx2->size[2] - 1;
  for (c2_i729 = 0; c2_i729 <= c2_uf_loop_ub; c2_i729++) {
    c2_subPixelLoc->data[1 + c2_subPixelLoc->size[0] * c2_subPixelLoc->size[1] *
      c2_i729] = c2_dx2->data[c2_dx2->size[0] * c2_dx2->size[1] * c2_i729];
  }

  c2_emxFree_real32_T(chartInstance, &c2_dx2);
  for (c2_i730 = 0; c2_i730 < 3; c2_i730++) {
    c2_b_subPixelLoc[c2_i730] = c2_subPixelLoc->size[c2_i730];
  }

  for (c2_i731 = 0; c2_i731 < 3; c2_i731++) {
    c2_b_loc[c2_i731] = c2_loc->size[c2_i731];
  }

  _SFD_SIZE_EQ_CHECK_ND(c2_b_subPixelLoc, c2_b_loc, 3);
  c2_i732 = c2_subPixelLoc->size[0] * c2_subPixelLoc->size[1] *
    c2_subPixelLoc->size[2];
  c2_subPixelLoc->size[0] = 2;
  c2_subPixelLoc->size[1] = 1;
  c2_subPixelLoc->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_subPixelLoc, c2_i732,
    &c2_yg_emlrtRTEI);
  c2_c_subPixelLoc = c2_subPixelLoc->size[0];
  c2_d_subPixelLoc = c2_subPixelLoc->size[1];
  c2_e_subPixelLoc = c2_subPixelLoc->size[2];
  c2_f_subPixelLoc = c2_subPixelLoc->size[0];
  c2_g_subPixelLoc = c2_subPixelLoc->size[1];
  c2_h_subPixelLoc = c2_subPixelLoc->size[2];
  c2_vf_loop_ub = c2_c_subPixelLoc * c2_d_subPixelLoc * c2_e_subPixelLoc - 1;
  for (c2_i733 = 0; c2_i733 <= c2_vf_loop_ub; c2_i733++) {
    c2_subPixelLoc->data[c2_i733] += c2_loc->data[c2_i733];
  }
}

static boolean_T c2_b_allinrange(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_x, real_T c2_lo, int32_T c2_hi)
{
  boolean_T c2_p;
  int32_T c2_k;
  boolean_T c2_b20;
  boolean_T c2_b_p;
  int32_T exitg1;
  (void)chartInstance;
  (void)c2_lo;
  c2_k = 0;
  do {
    exitg1 = 0;
    if (c2_k <= c2_x->size[0] - 1) {
      if (c2_x->data[c2_k] >= 1.0F) {
        if ((c2_x->data[c2_k] <= -2.14748365E+9F) || ((c2_x->data[c2_k] <
              2.14748365E+9F) && (c2_hi >= (int32_T)muSingleScalarCeil
              (c2_x->data[c2_k])))) {
          c2_b_p = true;
        } else {
          c2_b_p = false;
        }

        if (c2_b_p) {
          c2_b20 = true;
        } else {
          c2_b20 = false;
        }
      } else {
        c2_b20 = false;
      }

      if (!c2_b20) {
        c2_p = false;
        exitg1 = 1;
      } else {
        c2_k++;
      }
    } else {
      c2_p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c2_p;
}

static boolean_T c2_b_isequal(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, real_T c2_varargin_1[2], real_T c2_varargin_2[2])
{
  boolean_T c2_p;
  boolean_T c2_b_p;
  int32_T c2_k;
  boolean_T exitg1;
  (void)chartInstance;
  c2_p = false;
  c2_b_p = true;
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k < 2)) {
    if (!(c2_varargin_1[c2_k] == c2_varargin_2[c2_k])) {
      c2_b_p = false;
      exitg1 = true;
    } else {
      c2_k++;
    }
  }

  if (!c2_b_p) {
  } else {
    c2_p = true;
  }

  return c2_p;
}

static int32_T c2_prodsub(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  int32_T c2_x[2], int32_T c2_lo, int32_T c2_hi)
{
  (void)chartInstance;
  (void)c2_lo;
  (void)c2_hi;
  return c2_x[1];
}

static void c2_abs(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
                   c2_emxArray_real32_T *c2_x, c2_emxArray_real32_T *c2_y)
{
  int32_T c2_i734;
  int32_T c2_k;
  c2_i734 = c2_y->size[0] * c2_y->size[1] * c2_y->size[2];
  c2_y->size[0] = 1;
  c2_y->size[1] = 1;
  c2_y->size[2] = c2_x->size[2];
  c2_emxEnsureCapacity_real32_T2(chartInstance, c2_y, c2_i734, &c2_fh_emlrtRTEI);
  for (c2_k = 0; c2_k + 1 <= c2_x->size[2]; c2_k++) {
    c2_y->data[c2_k] = muSingleScalarAbs(c2_x->data[c2_k]);
  }
}

static void c2_computeMetric(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_metric, c2_emxArray_real32_T *c2_loc,
  c2_emxArray_real32_T *c2_values)
{
  c2_emxArray_real32_T *c2_x;
  int32_T c2_i735;
  int32_T c2_i736;
  int32_T c2_loop_ub;
  int32_T c2_i737;
  c2_emxArray_real32_T *c2_y;
  int32_T c2_i738;
  int32_T c2_i739;
  int32_T c2_b_loop_ub;
  int32_T c2_i740;
  c2_emxArray_real32_T *c2_x1;
  int32_T c2_i741;
  int32_T c2_c_loop_ub;
  int32_T c2_i742;
  c2_emxArray_real32_T *c2_y1;
  int32_T c2_i743;
  int32_T c2_d_loop_ub;
  int32_T c2_i744;
  c2_emxArray_real32_T *c2_x2;
  int32_T c2_i745;
  int32_T c2_e_loop_ub;
  int32_T c2_i746;
  c2_emxArray_real32_T *c2_y2;
  int32_T c2_i747;
  int32_T c2_f_loop_ub;
  int32_T c2_i748;
  int32_T c2_i749;
  c2_emxArray_real_T *c2_ndx;
  real_T c2_b_metric[2];
  c2_emxArray_int32_T *c2_idx;
  int32_T c2_i750;
  c2_emxArray_real32_T *c2_b_y1;
  int32_T c2_siz[2];
  int32_T c2_i751;
  int32_T c2_g_loop_ub;
  int32_T c2_i752;
  real_T c2_c_y1[2];
  real_T c2_b_x1[2];
  int32_T c2_i753;
  c2_emxArray_real32_T *c2_c_x1;
  int32_T c2_b_siz[2];
  int32_T c2_i754;
  int32_T c2_h_loop_ub;
  int32_T c2_i755;
  int32_T c2_c_siz;
  int32_T c2_i756;
  int32_T c2_i_loop_ub;
  int32_T c2_i757;
  int32_T c2_i758;
  int32_T c2_j_loop_ub;
  int32_T c2_i759;
  int32_T c2_i760;
  int32_T c2_c_metric[2];
  int32_T c2_i761;
  int32_T c2_d_metric;
  int32_T c2_k_loop_ub;
  int32_T c2_i762;
  int32_T c2_i763;
  int32_T c2_i764;
  int32_T c2_l_loop_ub;
  int32_T c2_i765;
  int32_T c2_i766;
  c2_emxArray_real32_T *c2_d_y1;
  int32_T c2_i767;
  int32_T c2_m_loop_ub;
  int32_T c2_i768;
  real_T c2_e_y1[2];
  real_T c2_b_x2[2];
  int32_T c2_i769;
  c2_emxArray_real32_T *c2_c_x2;
  int32_T c2_d_siz[2];
  int32_T c2_i770;
  int32_T c2_n_loop_ub;
  int32_T c2_i771;
  int32_T c2_e_siz;
  int32_T c2_i772;
  int32_T c2_o_loop_ub;
  int32_T c2_i773;
  int32_T c2_i774;
  int32_T c2_p_loop_ub;
  int32_T c2_i775;
  int32_T c2_i776;
  int32_T c2_e_metric[2];
  int32_T c2_i777;
  int32_T c2_f_metric;
  int32_T c2_q_loop_ub;
  int32_T c2_i778;
  c2_emxArray_real32_T *c2_r15;
  int32_T c2_i779;
  int32_T c2_i780;
  int32_T c2_i781;
  int32_T c2_r_loop_ub;
  int32_T c2_i782;
  int32_T c2_i783;
  int32_T c2_s_loop_ub;
  int32_T c2_i784;
  int32_T c2_i785;
  int32_T c2_t_loop_ub;
  int32_T c2_i786;
  int32_T c2_i787;
  c2_emxArray_real32_T *c2_b_y2;
  int32_T c2_i788;
  int32_T c2_u_loop_ub;
  int32_T c2_i789;
  real_T c2_c_y2[2];
  real_T c2_d_x1[2];
  int32_T c2_i790;
  c2_emxArray_real32_T *c2_e_x1;
  int32_T c2_f_siz[2];
  int32_T c2_i791;
  int32_T c2_v_loop_ub;
  int32_T c2_i792;
  int32_T c2_g_siz;
  int32_T c2_i793;
  int32_T c2_w_loop_ub;
  int32_T c2_i794;
  int32_T c2_i795;
  int32_T c2_x_loop_ub;
  int32_T c2_i796;
  int32_T c2_i797;
  int32_T c2_g_metric[2];
  int32_T c2_i798;
  int32_T c2_h_metric;
  int32_T c2_y_loop_ub;
  int32_T c2_i799;
  c2_emxArray_real32_T *c2_r16;
  int32_T c2_i800;
  int32_T c2_i801;
  int32_T c2_ab_loop_ub;
  int32_T c2_i802;
  int32_T c2_i803;
  int32_T c2_i804;
  int32_T c2_bb_loop_ub;
  int32_T c2_i805;
  int32_T c2_i806;
  c2_emxArray_real32_T *c2_d_y2;
  int32_T c2_i807;
  int32_T c2_cb_loop_ub;
  int32_T c2_i808;
  real_T c2_e_y2[2];
  real_T c2_d_x2[2];
  int32_T c2_i809;
  c2_emxArray_real32_T *c2_e_x2;
  int32_T c2_h_siz[2];
  int32_T c2_i810;
  int32_T c2_db_loop_ub;
  int32_T c2_i811;
  int32_T c2_i_siz;
  int32_T c2_i812;
  int32_T c2_eb_loop_ub;
  int32_T c2_i813;
  int32_T c2_i814;
  int32_T c2_fb_loop_ub;
  int32_T c2_i815;
  int32_T c2_i816;
  int32_T c2_i_metric[2];
  int32_T c2_i817;
  int32_T c2_j_metric;
  int32_T c2_gb_loop_ub;
  int32_T c2_i818;
  int32_T c2_i819;
  int32_T c2_i820;
  int32_T c2_i821;
  int32_T c2_hb_loop_ub;
  int32_T c2_i822;
  int32_T c2_i823;
  int32_T c2_i824;
  int32_T c2_ib_loop_ub;
  int32_T c2_i825;
  int32_T c2_i826;
  int32_T c2_jb_loop_ub;
  int32_T c2_i827;
  c2_emxInit_real32_T1(chartInstance, &c2_x, 1, &c2_gh_emlrtRTEI);
  c2_i735 = c2_loc->size[0];
  c2_i736 = c2_x->size[0];
  c2_x->size[0] = c2_i735;
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_x, c2_i736, &c2_gh_emlrtRTEI);
  c2_loop_ub = c2_i735 - 1;
  for (c2_i737 = 0; c2_i737 <= c2_loop_ub; c2_i737++) {
    c2_x->data[c2_i737] = c2_loc->data[c2_i737];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_y, 1, &c2_hh_emlrtRTEI);
  c2_i738 = c2_loc->size[0];
  c2_i739 = c2_y->size[0];
  c2_y->size[0] = c2_i738;
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_y, c2_i739, &c2_hh_emlrtRTEI);
  c2_b_loop_ub = c2_i738 - 1;
  for (c2_i740 = 0; c2_i740 <= c2_b_loop_ub; c2_i740++) {
    c2_y->data[c2_i740] = c2_loc->data[c2_i740 + c2_loc->size[0]];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_x1, 1, &c2_ih_emlrtRTEI);
  c2_i741 = c2_x1->size[0];
  c2_x1->size[0] = c2_x->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_x1, c2_i741, &c2_ih_emlrtRTEI);
  c2_c_loop_ub = c2_x->size[0] - 1;
  for (c2_i742 = 0; c2_i742 <= c2_c_loop_ub; c2_i742++) {
    c2_x1->data[c2_i742] = c2_x->data[c2_i742];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_y1, 1, &c2_jh_emlrtRTEI);
  c2_b_floor(chartInstance, c2_x1);
  c2_i743 = c2_y1->size[0];
  c2_y1->size[0] = c2_y->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_y1, c2_i743, &c2_jh_emlrtRTEI);
  c2_d_loop_ub = c2_y->size[0] - 1;
  for (c2_i744 = 0; c2_i744 <= c2_d_loop_ub; c2_i744++) {
    c2_y1->data[c2_i744] = c2_y->data[c2_i744];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_x2, 1, &c2_kh_emlrtRTEI);
  c2_b_floor(chartInstance, c2_y1);
  c2_i745 = c2_x2->size[0];
  c2_x2->size[0] = c2_x1->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_x2, c2_i745, &c2_kh_emlrtRTEI);
  c2_e_loop_ub = c2_x1->size[0] - 1;
  for (c2_i746 = 0; c2_i746 <= c2_e_loop_ub; c2_i746++) {
    c2_x2->data[c2_i746] = c2_x1->data[c2_i746] + 1.0F;
  }

  c2_emxInit_real32_T1(chartInstance, &c2_y2, 1, &c2_lh_emlrtRTEI);
  c2_i747 = c2_y2->size[0];
  c2_y2->size[0] = c2_y1->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_y2, c2_i747, &c2_lh_emlrtRTEI);
  c2_f_loop_ub = c2_y1->size[0] - 1;
  for (c2_i748 = 0; c2_i748 <= c2_f_loop_ub; c2_i748++) {
    c2_y2->data[c2_i748] = c2_y1->data[c2_i748] + 1.0F;
  }

  for (c2_i749 = 0; c2_i749 < 2; c2_i749++) {
    c2_b_metric[c2_i749] = (real_T)c2_metric->size[c2_i749];
  }

  c2_emxInit_real_T1(chartInstance, &c2_ndx, 1, &c2_ci_emlrtRTEI);
  c2_emxInit_int32_T(chartInstance, &c2_idx, 1, &c2_eh_emlrtRTEI);
  for (c2_i750 = 0; c2_i750 < 2; c2_i750++) {
    c2_siz[c2_i750] = (int32_T)c2_b_metric[c2_i750];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_b_y1, 1, &c2_mh_emlrtRTEI);
  c2_i751 = c2_b_y1->size[0];
  c2_b_y1->size[0] = c2_y1->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_b_y1, c2_i751,
    &c2_mh_emlrtRTEI);
  c2_g_loop_ub = c2_y1->size[0] - 1;
  for (c2_i752 = 0; c2_i752 <= c2_g_loop_ub; c2_i752++) {
    c2_b_y1->data[c2_i752] = c2_y1->data[c2_i752];
  }

  if (c2_b_allinrange(chartInstance, c2_b_y1, 1.0, c2_siz[0])) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_emlrt_marshallOut(chartInstance, c2_cv3)));
  }

  c2_emxFree_real32_T(chartInstance, &c2_b_y1);
  c2_c_y1[0] = (real_T)c2_y1->size[0];
  c2_c_y1[1] = 1.0;
  c2_b_x1[0] = (real_T)c2_x1->size[0];
  c2_b_x1[1] = 1.0;
  if (c2_b_isequal(chartInstance, c2_c_y1, c2_b_x1)) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_b_emlrt_marshallOut(chartInstance, c2_cv4)));
  }

  for (c2_i753 = 0; c2_i753 < 2; c2_i753++) {
    c2_b_siz[c2_i753] = c2_siz[c2_i753];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_c_x1, 1, &c2_nh_emlrtRTEI);
  c2_i754 = c2_c_x1->size[0];
  c2_c_x1->size[0] = c2_x1->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_c_x1, c2_i754,
    &c2_nh_emlrtRTEI);
  c2_h_loop_ub = c2_x1->size[0] - 1;
  for (c2_i755 = 0; c2_i755 <= c2_h_loop_ub; c2_i755++) {
    c2_c_x1->data[c2_i755] = c2_x1->data[c2_i755];
  }

  if (c2_b_allinrange(chartInstance, c2_c_x1, 1.0, c2_prodsub(chartInstance,
        c2_b_siz, 2, 2))) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_emlrt_marshallOut(chartInstance, c2_cv3)));
  }

  c2_emxFree_real32_T(chartInstance, &c2_c_x1);
  c2_c_siz = c2_siz[0];
  c2_i756 = c2_idx->size[0];
  c2_idx->size[0] = c2_y1->size[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_idx, c2_i756, &c2_oe_emlrtRTEI);
  c2_i_loop_ub = c2_y1->size[0] - 1;
  for (c2_i757 = 0; c2_i757 <= c2_i_loop_ub; c2_i757++) {
    c2_idx->data[c2_i757] = (int32_T)c2_y1->data[c2_i757] + c2_c_siz * ((int32_T)
      c2_x1->data[c2_i757] - 1);
  }

  c2_i758 = c2_ndx->size[0];
  c2_ndx->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_ndx, c2_i758, &c2_oh_emlrtRTEI);
  c2_j_loop_ub = c2_idx->size[0] - 1;
  for (c2_i759 = 0; c2_i759 <= c2_j_loop_ub; c2_i759++) {
    c2_ndx->data[c2_i759] = (real_T)c2_idx->data[c2_i759];
  }

  for (c2_i760 = 0; c2_i760 < 2; c2_i760++) {
    c2_c_metric[c2_i760] = c2_metric->size[c2_i760];
  }

  c2_indexShapeCheck(chartInstance, c2_c_metric, c2_ndx->size[0]);
  c2_i761 = c2_loc->size[0];
  _SFD_SIZE_EQ_CHECK_1D(c2_x2->size[0], c2_i761);
  c2_d_metric = c2_metric->size[0] * c2_metric->size[1];
  c2_k_loop_ub = c2_ndx->size[0] - 1;
  for (c2_i762 = 0; c2_i762 <= c2_k_loop_ub; c2_i762++) {
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_ndx->data[c2_i762],
      1, c2_d_metric);
  }

  _SFD_SIZE_EQ_CHECK_1D(c2_idx->size[0], c2_x2->size[0]);
  c2_i763 = c2_loc->size[0];
  _SFD_SIZE_EQ_CHECK_1D(c2_y2->size[0], c2_i763);
  c2_i764 = c2_values->size[0];
  c2_values->size[0] = c2_ndx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_values, c2_i764,
    &c2_ph_emlrtRTEI);
  c2_l_loop_ub = c2_ndx->size[0] - 1;
  for (c2_i765 = 0; c2_i765 <= c2_l_loop_ub; c2_i765++) {
    c2_values->data[c2_i765] = c2_metric->data[(int32_T)c2_ndx->data[c2_i765] -
      1] * (c2_x2->data[c2_i765] - c2_x->data[c2_i765]);
  }

  _SFD_SIZE_EQ_CHECK_1D(c2_values->size[0], c2_y2->size[0]);
  for (c2_i766 = 0; c2_i766 < 2; c2_i766++) {
    c2_siz[c2_i766] = (int32_T)c2_b_metric[c2_i766];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_d_y1, 1, &c2_qh_emlrtRTEI);
  c2_i767 = c2_d_y1->size[0];
  c2_d_y1->size[0] = c2_y1->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_d_y1, c2_i767,
    &c2_qh_emlrtRTEI);
  c2_m_loop_ub = c2_y1->size[0] - 1;
  for (c2_i768 = 0; c2_i768 <= c2_m_loop_ub; c2_i768++) {
    c2_d_y1->data[c2_i768] = c2_y1->data[c2_i768];
  }

  if (c2_b_allinrange(chartInstance, c2_d_y1, 1.0, c2_siz[0])) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_emlrt_marshallOut(chartInstance, c2_cv3)));
  }

  c2_emxFree_real32_T(chartInstance, &c2_d_y1);
  c2_e_y1[0] = (real_T)c2_y1->size[0];
  c2_e_y1[1] = 1.0;
  c2_b_x2[0] = (real_T)c2_x2->size[0];
  c2_b_x2[1] = 1.0;
  if (c2_b_isequal(chartInstance, c2_e_y1, c2_b_x2)) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_b_emlrt_marshallOut(chartInstance, c2_cv4)));
  }

  for (c2_i769 = 0; c2_i769 < 2; c2_i769++) {
    c2_d_siz[c2_i769] = c2_siz[c2_i769];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_c_x2, 1, &c2_rh_emlrtRTEI);
  c2_i770 = c2_c_x2->size[0];
  c2_c_x2->size[0] = c2_x2->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_c_x2, c2_i770,
    &c2_rh_emlrtRTEI);
  c2_n_loop_ub = c2_x2->size[0] - 1;
  for (c2_i771 = 0; c2_i771 <= c2_n_loop_ub; c2_i771++) {
    c2_c_x2->data[c2_i771] = c2_x2->data[c2_i771];
  }

  if (c2_b_allinrange(chartInstance, c2_c_x2, 1.0, c2_prodsub(chartInstance,
        c2_d_siz, 2, 2))) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_emlrt_marshallOut(chartInstance, c2_cv3)));
  }

  c2_emxFree_real32_T(chartInstance, &c2_c_x2);
  c2_e_siz = c2_siz[0];
  c2_i772 = c2_idx->size[0];
  c2_idx->size[0] = c2_y1->size[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_idx, c2_i772, &c2_oe_emlrtRTEI);
  c2_o_loop_ub = c2_y1->size[0] - 1;
  for (c2_i773 = 0; c2_i773 <= c2_o_loop_ub; c2_i773++) {
    c2_idx->data[c2_i773] = (int32_T)c2_y1->data[c2_i773] + c2_e_siz * ((int32_T)
      c2_x2->data[c2_i773] - 1);
  }

  c2_i774 = c2_ndx->size[0];
  c2_ndx->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_ndx, c2_i774, &c2_oh_emlrtRTEI);
  c2_p_loop_ub = c2_idx->size[0] - 1;
  for (c2_i775 = 0; c2_i775 <= c2_p_loop_ub; c2_i775++) {
    c2_ndx->data[c2_i775] = (real_T)c2_idx->data[c2_i775];
  }

  for (c2_i776 = 0; c2_i776 < 2; c2_i776++) {
    c2_e_metric[c2_i776] = c2_metric->size[c2_i776];
  }

  c2_indexShapeCheck(chartInstance, c2_e_metric, c2_ndx->size[0]);
  c2_i777 = c2_loc->size[0];
  _SFD_SIZE_EQ_CHECK_1D(c2_i777, c2_x1->size[0]);
  c2_f_metric = c2_metric->size[0] * c2_metric->size[1];
  c2_q_loop_ub = c2_ndx->size[0] - 1;
  for (c2_i778 = 0; c2_i778 <= c2_q_loop_ub; c2_i778++) {
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_ndx->data[c2_i778],
      1, c2_f_metric);
  }

  c2_emxInit_real32_T1(chartInstance, &c2_r15, 1, &c2_bi_emlrtRTEI);
  c2_i779 = c2_loc->size[0];
  _SFD_SIZE_EQ_CHECK_1D(c2_idx->size[0], c2_i779);
  c2_i780 = c2_loc->size[0];
  _SFD_SIZE_EQ_CHECK_1D(c2_y2->size[0], c2_i780);
  c2_i781 = c2_r15->size[0];
  c2_r15->size[0] = c2_ndx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_r15, c2_i781,
    &c2_sh_emlrtRTEI);
  c2_r_loop_ub = c2_ndx->size[0] - 1;
  for (c2_i782 = 0; c2_i782 <= c2_r_loop_ub; c2_i782++) {
    c2_r15->data[c2_i782] = c2_metric->data[(int32_T)c2_ndx->data[c2_i782] - 1] *
      (c2_x->data[c2_i782] - c2_x1->data[c2_i782]);
  }

  _SFD_SIZE_EQ_CHECK_1D(c2_r15->size[0], c2_y2->size[0]);
  c2_i783 = c2_values->size[0];
  c2_values->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_values, c2_i783,
    &c2_ph_emlrtRTEI);
  c2_s_loop_ub = c2_values->size[0] - 1;
  for (c2_i784 = 0; c2_i784 <= c2_s_loop_ub; c2_i784++) {
    c2_values->data[c2_i784] *= c2_y2->data[c2_i784] - c2_y->data[c2_i784];
  }

  c2_i785 = c2_r15->size[0];
  c2_r15->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_r15, c2_i785,
    &c2_sh_emlrtRTEI);
  c2_t_loop_ub = c2_r15->size[0] - 1;
  for (c2_i786 = 0; c2_i786 <= c2_t_loop_ub; c2_i786++) {
    c2_r15->data[c2_i786] *= c2_y2->data[c2_i786] - c2_y->data[c2_i786];
  }

  _SFD_SIZE_EQ_CHECK_1D(c2_values->size[0], c2_r15->size[0]);
  for (c2_i787 = 0; c2_i787 < 2; c2_i787++) {
    c2_siz[c2_i787] = (int32_T)c2_b_metric[c2_i787];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_b_y2, 1, &c2_th_emlrtRTEI);
  c2_i788 = c2_b_y2->size[0];
  c2_b_y2->size[0] = c2_y2->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_b_y2, c2_i788,
    &c2_th_emlrtRTEI);
  c2_u_loop_ub = c2_y2->size[0] - 1;
  for (c2_i789 = 0; c2_i789 <= c2_u_loop_ub; c2_i789++) {
    c2_b_y2->data[c2_i789] = c2_y2->data[c2_i789];
  }

  if (c2_b_allinrange(chartInstance, c2_b_y2, 1.0, c2_siz[0])) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_emlrt_marshallOut(chartInstance, c2_cv3)));
  }

  c2_emxFree_real32_T(chartInstance, &c2_b_y2);
  c2_c_y2[0] = (real_T)c2_y2->size[0];
  c2_c_y2[1] = 1.0;
  c2_d_x1[0] = (real_T)c2_x1->size[0];
  c2_d_x1[1] = 1.0;
  if (c2_b_isequal(chartInstance, c2_c_y2, c2_d_x1)) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_b_emlrt_marshallOut(chartInstance, c2_cv4)));
  }

  for (c2_i790 = 0; c2_i790 < 2; c2_i790++) {
    c2_f_siz[c2_i790] = c2_siz[c2_i790];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_e_x1, 1, &c2_uh_emlrtRTEI);
  c2_i791 = c2_e_x1->size[0];
  c2_e_x1->size[0] = c2_x1->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_e_x1, c2_i791,
    &c2_uh_emlrtRTEI);
  c2_v_loop_ub = c2_x1->size[0] - 1;
  for (c2_i792 = 0; c2_i792 <= c2_v_loop_ub; c2_i792++) {
    c2_e_x1->data[c2_i792] = c2_x1->data[c2_i792];
  }

  if (c2_b_allinrange(chartInstance, c2_e_x1, 1.0, c2_prodsub(chartInstance,
        c2_f_siz, 2, 2))) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_emlrt_marshallOut(chartInstance, c2_cv3)));
  }

  c2_emxFree_real32_T(chartInstance, &c2_e_x1);
  c2_g_siz = c2_siz[0];
  c2_i793 = c2_idx->size[0];
  c2_idx->size[0] = c2_y2->size[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_idx, c2_i793, &c2_oe_emlrtRTEI);
  c2_w_loop_ub = c2_y2->size[0] - 1;
  for (c2_i794 = 0; c2_i794 <= c2_w_loop_ub; c2_i794++) {
    c2_idx->data[c2_i794] = (int32_T)c2_y2->data[c2_i794] + c2_g_siz * ((int32_T)
      c2_x1->data[c2_i794] - 1);
  }

  c2_i795 = c2_ndx->size[0];
  c2_ndx->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_ndx, c2_i795, &c2_oh_emlrtRTEI);
  c2_x_loop_ub = c2_idx->size[0] - 1;
  for (c2_i796 = 0; c2_i796 <= c2_x_loop_ub; c2_i796++) {
    c2_ndx->data[c2_i796] = (real_T)c2_idx->data[c2_i796];
  }

  for (c2_i797 = 0; c2_i797 < 2; c2_i797++) {
    c2_g_metric[c2_i797] = c2_metric->size[c2_i797];
  }

  c2_indexShapeCheck(chartInstance, c2_g_metric, c2_ndx->size[0]);
  c2_i798 = c2_loc->size[0];
  _SFD_SIZE_EQ_CHECK_1D(c2_x2->size[0], c2_i798);
  c2_h_metric = c2_metric->size[0] * c2_metric->size[1];
  c2_y_loop_ub = c2_ndx->size[0] - 1;
  for (c2_i799 = 0; c2_i799 <= c2_y_loop_ub; c2_i799++) {
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_ndx->data[c2_i799],
      1, c2_h_metric);
  }

  c2_emxInit_real32_T1(chartInstance, &c2_r16, 1, &c2_bi_emlrtRTEI);
  _SFD_SIZE_EQ_CHECK_1D(c2_idx->size[0], c2_x2->size[0]);
  c2_i800 = c2_loc->size[0];
  _SFD_SIZE_EQ_CHECK_1D(c2_i800, c2_y1->size[0]);
  c2_i801 = c2_r16->size[0];
  c2_r16->size[0] = c2_ndx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_r16, c2_i801,
    &c2_vh_emlrtRTEI);
  c2_ab_loop_ub = c2_ndx->size[0] - 1;
  for (c2_i802 = 0; c2_i802 <= c2_ab_loop_ub; c2_i802++) {
    c2_r16->data[c2_i802] = c2_metric->data[(int32_T)c2_ndx->data[c2_i802] - 1] *
      (c2_x2->data[c2_i802] - c2_x->data[c2_i802]);
  }

  c2_i803 = c2_loc->size[0];
  _SFD_SIZE_EQ_CHECK_1D(c2_r16->size[0], c2_i803);
  c2_i804 = c2_r16->size[0];
  c2_r16->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_r16, c2_i804,
    &c2_vh_emlrtRTEI);
  c2_bb_loop_ub = c2_r16->size[0] - 1;
  for (c2_i805 = 0; c2_i805 <= c2_bb_loop_ub; c2_i805++) {
    c2_r16->data[c2_i805] *= c2_y->data[c2_i805] - c2_y1->data[c2_i805];
  }

  _SFD_SIZE_EQ_CHECK_1D(c2_values->size[0], c2_r16->size[0]);
  for (c2_i806 = 0; c2_i806 < 2; c2_i806++) {
    c2_siz[c2_i806] = (int32_T)c2_b_metric[c2_i806];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_d_y2, 1, &c2_wh_emlrtRTEI);
  c2_i807 = c2_d_y2->size[0];
  c2_d_y2->size[0] = c2_y2->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_d_y2, c2_i807,
    &c2_wh_emlrtRTEI);
  c2_cb_loop_ub = c2_y2->size[0] - 1;
  for (c2_i808 = 0; c2_i808 <= c2_cb_loop_ub; c2_i808++) {
    c2_d_y2->data[c2_i808] = c2_y2->data[c2_i808];
  }

  if (c2_b_allinrange(chartInstance, c2_d_y2, 1.0, c2_siz[0])) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_emlrt_marshallOut(chartInstance, c2_cv3)));
  }

  c2_emxFree_real32_T(chartInstance, &c2_d_y2);
  c2_e_y2[0] = (real_T)c2_y2->size[0];
  c2_e_y2[1] = 1.0;
  c2_d_x2[0] = (real_T)c2_x2->size[0];
  c2_d_x2[1] = 1.0;
  if (c2_b_isequal(chartInstance, c2_e_y2, c2_d_x2)) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_b_emlrt_marshallOut(chartInstance, c2_cv4)));
  }

  for (c2_i809 = 0; c2_i809 < 2; c2_i809++) {
    c2_h_siz[c2_i809] = c2_siz[c2_i809];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_e_x2, 1, &c2_xh_emlrtRTEI);
  c2_i810 = c2_e_x2->size[0];
  c2_e_x2->size[0] = c2_x2->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_e_x2, c2_i810,
    &c2_xh_emlrtRTEI);
  c2_db_loop_ub = c2_x2->size[0] - 1;
  for (c2_i811 = 0; c2_i811 <= c2_db_loop_ub; c2_i811++) {
    c2_e_x2->data[c2_i811] = c2_x2->data[c2_i811];
  }

  if (c2_b_allinrange(chartInstance, c2_e_x2, 1.0, c2_prodsub(chartInstance,
        c2_h_siz, 2, 2))) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_emlrt_marshallOut(chartInstance, c2_cv3)));
  }

  c2_emxFree_real32_T(chartInstance, &c2_e_x2);
  c2_i_siz = c2_siz[0];
  c2_i812 = c2_idx->size[0];
  c2_idx->size[0] = c2_y2->size[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_idx, c2_i812, &c2_oe_emlrtRTEI);
  c2_eb_loop_ub = c2_y2->size[0] - 1;
  for (c2_i813 = 0; c2_i813 <= c2_eb_loop_ub; c2_i813++) {
    c2_idx->data[c2_i813] = (int32_T)c2_y2->data[c2_i813] + c2_i_siz * ((int32_T)
      c2_x2->data[c2_i813] - 1);
  }

  c2_emxFree_real32_T(chartInstance, &c2_y2);
  c2_i814 = c2_ndx->size[0];
  c2_ndx->size[0] = c2_idx->size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_ndx, c2_i814, &c2_oh_emlrtRTEI);
  c2_fb_loop_ub = c2_idx->size[0] - 1;
  for (c2_i815 = 0; c2_i815 <= c2_fb_loop_ub; c2_i815++) {
    c2_ndx->data[c2_i815] = (real_T)c2_idx->data[c2_i815];
  }

  for (c2_i816 = 0; c2_i816 < 2; c2_i816++) {
    c2_i_metric[c2_i816] = c2_metric->size[c2_i816];
  }

  c2_indexShapeCheck(chartInstance, c2_i_metric, c2_ndx->size[0]);
  c2_i817 = c2_loc->size[0];
  _SFD_SIZE_EQ_CHECK_1D(c2_i817, c2_x1->size[0]);
  c2_j_metric = c2_metric->size[0] * c2_metric->size[1];
  c2_gb_loop_ub = c2_ndx->size[0] - 1;
  for (c2_i818 = 0; c2_i818 <= c2_gb_loop_ub; c2_i818++) {
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_ndx->data[c2_i818],
      1, c2_j_metric);
  }

  c2_i819 = c2_loc->size[0];
  _SFD_SIZE_EQ_CHECK_1D(c2_idx->size[0], c2_i819);
  c2_i820 = c2_loc->size[0];
  _SFD_SIZE_EQ_CHECK_1D(c2_i820, c2_y1->size[0]);
  c2_i821 = c2_x2->size[0];
  c2_x2->size[0] = c2_ndx->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_x2, c2_i821, &c2_yh_emlrtRTEI);
  c2_hb_loop_ub = c2_ndx->size[0] - 1;
  c2_emxFree_int32_T(chartInstance, &c2_idx);
  for (c2_i822 = 0; c2_i822 <= c2_hb_loop_ub; c2_i822++) {
    c2_x2->data[c2_i822] = c2_metric->data[(int32_T)c2_ndx->data[c2_i822] - 1] *
      (c2_x->data[c2_i822] - c2_x1->data[c2_i822]);
  }

  c2_emxFree_real_T(chartInstance, &c2_ndx);
  c2_emxFree_real32_T(chartInstance, &c2_x1);
  c2_emxFree_real32_T(chartInstance, &c2_x);
  c2_i823 = c2_loc->size[0];
  _SFD_SIZE_EQ_CHECK_1D(c2_x2->size[0], c2_i823);
  c2_i824 = c2_x2->size[0];
  c2_x2->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_x2, c2_i824, &c2_yh_emlrtRTEI);
  c2_ib_loop_ub = c2_x2->size[0] - 1;
  for (c2_i825 = 0; c2_i825 <= c2_ib_loop_ub; c2_i825++) {
    c2_x2->data[c2_i825] *= c2_y->data[c2_i825] - c2_y1->data[c2_i825];
  }

  c2_emxFree_real32_T(chartInstance, &c2_y1);
  c2_emxFree_real32_T(chartInstance, &c2_y);
  _SFD_SIZE_EQ_CHECK_1D(c2_values->size[0], c2_x2->size[0]);
  c2_i826 = c2_values->size[0];
  c2_values->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_values, c2_i826,
    &c2_ai_emlrtRTEI);
  c2_jb_loop_ub = c2_values->size[0] - 1;
  for (c2_i827 = 0; c2_i827 <= c2_jb_loop_ub; c2_i827++) {
    c2_values->data[c2_i827] = ((c2_values->data[c2_i827] + c2_r15->data[c2_i827])
      + c2_r16->data[c2_i827]) + c2_x2->data[c2_i827];
  }

  c2_emxFree_real32_T(chartInstance, &c2_r16);
  c2_emxFree_real32_T(chartInstance, &c2_r15);
  c2_emxFree_real32_T(chartInstance, &c2_x2);
}

static void c2_floor(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
                     c2_emxArray_real32_T *c2_x, c2_emxArray_real32_T *c2_b_x)
{
  int32_T c2_i828;
  int32_T c2_loop_ub;
  int32_T c2_i829;
  c2_i828 = c2_b_x->size[0];
  c2_b_x->size[0] = c2_x->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_b_x, c2_i828,
    &c2_di_emlrtRTEI);
  c2_loop_ub = c2_x->size[0] - 1;
  for (c2_i829 = 0; c2_i829 <= c2_loop_ub; c2_i829++) {
    c2_b_x->data[c2_i829] = c2_x->data[c2_i829];
  }

  c2_b_floor(chartInstance, c2_b_x);
}

static void c2_indexShapeCheck(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, int32_T c2_matrixSize[2], int32_T c2_indexSize)
{
  boolean_T c2_nonSingletonDimFound;
  boolean_T c2_b;
  boolean_T c2_b_nonSingletonDimFound;
  const mxArray *c2_y = NULL;
  static char_T c2_cv36[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':', 'P',
    'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'M', 'a', 't', 'r', 'i', 'x', 'M',
    'a', 't', 'r', 'i', 'x' };

  (void)chartInstance;
  c2_nonSingletonDimFound = false;
  if (c2_matrixSize[0] != 1) {
    c2_nonSingletonDimFound = true;
  }

  if (c2_matrixSize[1] != 1) {
    if (c2_nonSingletonDimFound) {
      c2_b = false;
    } else {
      c2_nonSingletonDimFound = true;
      c2_b = c2_nonSingletonDimFound;
    }
  } else {
    c2_b = c2_nonSingletonDimFound;
  }

  if (c2_b) {
    c2_b_nonSingletonDimFound = false;
    if (c2_indexSize != 1) {
      c2_b_nonSingletonDimFound = true;
    }

    if (c2_b_nonSingletonDimFound) {
      c2_y = NULL;
      sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv36, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c2_y));
    }
  }
}

static void c2_excludePointsOutsideROI(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, int32_T c2_originalROI_data[], int32_T c2_originalROI_size[2],
  int32_T c2_expandedROI_data[], int32_T c2_expandedROI_size[2],
  c2_emxArray_real32_T *c2_locInExpandedROI, c2_emxArray_real32_T *c2_metric,
  c2_emxArray_real32_T *c2_validLocation, c2_emxArray_real32_T *c2_validMetric)
{
  int32_T c2_q0;
  int32_T c2_q1;
  int32_T c2_qY;
  int32_T c2_b_q0;
  int32_T c2_b_q1;
  int32_T c2_b_qY;
  int32_T c2_x2;
  int32_T c2_c_q0;
  int32_T c2_c_q1;
  int32_T c2_c_qY;
  int32_T c2_d_q0;
  int32_T c2_d_q1;
  int32_T c2_d_qY;
  int32_T c2_y2;
  int32_T c2_i830;
  c2_emxArray_real32_T *c2_b_locInExpandedROI;
  int32_T c2_expandedROI[2];
  int32_T c2_i831;
  int32_T c2_c_locInExpandedROI;
  int32_T c2_d_locInExpandedROI;
  int32_T c2_loop_ub;
  int32_T c2_i832;
  int32_T c2_i833;
  c2_emxArray_real32_T *c2_locInImage;
  real32_T c2_b_expandedROI[2];
  c2_emxArray_boolean_T *c2_r17;
  int32_T c2_i834;
  real_T c2_originalROI;
  int32_T c2_i835;
  int32_T c2_b_loop_ub;
  int32_T c2_i836;
  c2_emxArray_boolean_T *c2_r18;
  int32_T c2_i837;
  real_T c2_b_originalROI;
  int32_T c2_i838;
  int32_T c2_c_loop_ub;
  int32_T c2_i839;
  int32_T c2_i840;
  int32_T c2_d_loop_ub;
  int32_T c2_i841;
  int32_T c2_i842;
  int32_T c2_i843;
  int32_T c2_e_loop_ub;
  int32_T c2_i844;
  int32_T c2_i845;
  int32_T c2_f_loop_ub;
  int32_T c2_i846;
  int32_T c2_i847;
  int32_T c2_i848;
  int32_T c2_g_loop_ub;
  int32_T c2_i849;
  int32_T c2_end;
  int32_T c2_trueCount;
  int32_T c2_i;
  c2_emxArray_int32_T *c2_r19;
  int32_T c2_i850;
  int32_T c2_partialTrueCount;
  int32_T c2_b_i;
  int32_T c2_b_locInImage;
  int32_T c2_i851;
  int32_T c2_i852;
  int32_T c2_h_loop_ub;
  int32_T c2_i853;
  int32_T c2_b_end;
  int32_T c2_b_trueCount;
  int32_T c2_c_i;
  c2_emxArray_int32_T *c2_r20;
  int32_T c2_i854;
  int32_T c2_b_partialTrueCount;
  int32_T c2_d_i;
  int32_T c2_b_metric[2];
  int32_T c2_c_metric;
  int32_T c2_i855;
  int32_T c2_i_loop_ub;
  int32_T c2_i856;
  (void)c2_originalROI_size;
  c2_q0 = c2_originalROI_data[0];
  c2_q1 = c2_originalROI_data[2];
  if ((c2_q0 < 0) && (c2_q1 < MIN_int32_T - c2_q0)) {
    c2_qY = MIN_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else if ((c2_q0 > 0) && (c2_q1 > MAX_int32_T - c2_q0)) {
    c2_qY = MAX_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else {
    c2_qY = c2_q0 + c2_q1;
  }

  c2_b_q0 = c2_qY;
  c2_b_q1 = 1;
  if ((c2_b_q1 < 0) && (c2_b_q0 > c2_b_q1 + MAX_int32_T)) {
    c2_b_qY = MAX_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else if ((c2_b_q1 > 0) && (c2_b_q0 < c2_b_q1 + MIN_int32_T)) {
    c2_b_qY = MIN_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else {
    c2_b_qY = c2_b_q0 - c2_b_q1;
  }

  c2_x2 = c2_b_qY;
  c2_c_q0 = c2_originalROI_data[1];
  c2_c_q1 = c2_originalROI_data[3];
  if ((c2_c_q0 < 0) && (c2_c_q1 < MIN_int32_T - c2_c_q0)) {
    c2_c_qY = MIN_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else if ((c2_c_q0 > 0) && (c2_c_q1 > MAX_int32_T - c2_c_q0)) {
    c2_c_qY = MAX_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else {
    c2_c_qY = c2_c_q0 + c2_c_q1;
  }

  c2_d_q0 = c2_c_qY;
  c2_d_q1 = 1;
  if ((c2_d_q1 < 0) && (c2_d_q0 > c2_d_q1 + MAX_int32_T)) {
    c2_d_qY = MAX_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else if ((c2_d_q1 > 0) && (c2_d_q0 < c2_d_q1 + MIN_int32_T)) {
    c2_d_qY = MIN_int32_T;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
  } else {
    c2_d_qY = c2_d_q0 - c2_d_q1;
  }

  c2_y2 = c2_d_qY;
  for (c2_i830 = 0; c2_i830 < 2; c2_i830++) {
    c2_expandedROI[c2_i830] = c2_expandedROI_size[c2_i830];
  }

  c2_emxInit_real32_T(chartInstance, &c2_b_locInExpandedROI, 2, &c2_ei_emlrtRTEI);
  c2_b_indexShapeCheck(chartInstance, c2_expandedROI);
  c2_i831 = c2_b_locInExpandedROI->size[0] * c2_b_locInExpandedROI->size[1];
  c2_b_locInExpandedROI->size[0] = c2_locInExpandedROI->size[0];
  c2_b_locInExpandedROI->size[1] = 2;
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_b_locInExpandedROI, c2_i831,
    &c2_ei_emlrtRTEI);
  c2_c_locInExpandedROI = c2_b_locInExpandedROI->size[0];
  c2_d_locInExpandedROI = c2_b_locInExpandedROI->size[1];
  c2_loop_ub = c2_locInExpandedROI->size[0] * c2_locInExpandedROI->size[1] - 1;
  for (c2_i832 = 0; c2_i832 <= c2_loop_ub; c2_i832++) {
    c2_b_locInExpandedROI->data[c2_i832] = c2_locInExpandedROI->data[c2_i832];
  }

  for (c2_i833 = 0; c2_i833 < 2; c2_i833++) {
    c2_b_expandedROI[c2_i833] = (real32_T)c2_expandedROI_data[c2_i833] - 1.0F;
  }

  c2_emxInit_real32_T(chartInstance, &c2_locInImage, 2, &c2_mi_emlrtRTEI);
  c2_emxInit_boolean_T2(chartInstance, &c2_r17, 1, &c2_ji_emlrtRTEI);
  c2_bsxfun(chartInstance, c2_b_locInExpandedROI, c2_b_expandedROI,
            c2_locInImage);
  c2_i834 = c2_locInImage->size[0];
  c2_originalROI = (real_T)c2_originalROI_data[0];
  c2_i835 = c2_r17->size[0];
  c2_r17->size[0] = c2_i834;
  c2_emxEnsureCapacity_boolean_T2(chartInstance, c2_r17, c2_i835,
    &c2_fi_emlrtRTEI);
  c2_b_loop_ub = c2_i834 - 1;
  c2_emxFree_real32_T(chartInstance, &c2_b_locInExpandedROI);
  for (c2_i836 = 0; c2_i836 <= c2_b_loop_ub; c2_i836++) {
    c2_r17->data[c2_i836] = ((real_T)c2_locInImage->data[c2_i836] >=
      c2_originalROI);
  }

  c2_emxInit_boolean_T2(chartInstance, &c2_r18, 1, &c2_ji_emlrtRTEI);
  c2_i837 = c2_locInImage->size[0];
  c2_b_originalROI = (real_T)c2_originalROI_data[1];
  c2_i838 = c2_r18->size[0];
  c2_r18->size[0] = c2_i837;
  c2_emxEnsureCapacity_boolean_T2(chartInstance, c2_r18, c2_i838,
    &c2_gi_emlrtRTEI);
  c2_c_loop_ub = c2_i837 - 1;
  for (c2_i839 = 0; c2_i839 <= c2_c_loop_ub; c2_i839++) {
    c2_r18->data[c2_i839] = ((real_T)c2_locInImage->data[c2_i839 +
      c2_locInImage->size[0]] >= c2_b_originalROI);
  }

  _SFD_SIZE_EQ_CHECK_1D(c2_r17->size[0], c2_r18->size[0]);
  c2_i840 = c2_r17->size[0];
  c2_r17->size[0];
  c2_emxEnsureCapacity_boolean_T2(chartInstance, c2_r17, c2_i840,
    &c2_fi_emlrtRTEI);
  c2_d_loop_ub = c2_r17->size[0] - 1;
  for (c2_i841 = 0; c2_i841 <= c2_d_loop_ub; c2_i841++) {
    c2_r17->data[c2_i841] = (c2_r17->data[c2_i841] && c2_r18->data[c2_i841]);
  }

  c2_i842 = c2_locInImage->size[0];
  c2_i843 = c2_r18->size[0];
  c2_r18->size[0] = c2_i842;
  c2_emxEnsureCapacity_boolean_T2(chartInstance, c2_r18, c2_i843,
    &c2_hi_emlrtRTEI);
  c2_e_loop_ub = c2_i842 - 1;
  for (c2_i844 = 0; c2_i844 <= c2_e_loop_ub; c2_i844++) {
    c2_r18->data[c2_i844] = ((real_T)c2_locInImage->data[c2_i844] <= (real_T)
      c2_x2);
  }

  _SFD_SIZE_EQ_CHECK_1D(c2_r17->size[0], c2_r18->size[0]);
  c2_i845 = c2_r17->size[0];
  c2_r17->size[0];
  c2_emxEnsureCapacity_boolean_T2(chartInstance, c2_r17, c2_i845,
    &c2_fi_emlrtRTEI);
  c2_f_loop_ub = c2_r17->size[0] - 1;
  for (c2_i846 = 0; c2_i846 <= c2_f_loop_ub; c2_i846++) {
    c2_r17->data[c2_i846] = (c2_r17->data[c2_i846] && c2_r18->data[c2_i846]);
  }

  c2_i847 = c2_locInImage->size[0];
  c2_i848 = c2_r18->size[0];
  c2_r18->size[0] = c2_i847;
  c2_emxEnsureCapacity_boolean_T2(chartInstance, c2_r18, c2_i848,
    &c2_ii_emlrtRTEI);
  c2_g_loop_ub = c2_i847 - 1;
  for (c2_i849 = 0; c2_i849 <= c2_g_loop_ub; c2_i849++) {
    c2_r18->data[c2_i849] = ((real_T)c2_locInImage->data[c2_i849 +
      c2_locInImage->size[0]] <= (real_T)c2_y2);
  }

  _SFD_SIZE_EQ_CHECK_1D(c2_r17->size[0], c2_r18->size[0]);
  c2_end = c2_r17->size[0] - 1;
  c2_trueCount = 0;
  for (c2_i = 0; c2_i <= c2_end; c2_i++) {
    if (c2_r17->data[c2_i] && c2_r18->data[c2_i]) {
      c2_trueCount++;
    }
  }

  c2_emxInit_int32_T(chartInstance, &c2_r19, 1, &c2_ni_emlrtRTEI);
  c2_i850 = c2_r19->size[0];
  c2_r19->size[0] = c2_trueCount;
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_r19, c2_i850, &c2_ji_emlrtRTEI);
  c2_partialTrueCount = 0;
  for (c2_b_i = 0; c2_b_i <= c2_end; c2_b_i++) {
    if (c2_r17->data[c2_b_i] && c2_r18->data[c2_b_i]) {
      c2_r19->data[c2_partialTrueCount] = c2_b_i + 1;
      c2_partialTrueCount++;
    }
  }

  c2_b_locInImage = c2_locInImage->size[0];
  c2_i851 = c2_validLocation->size[0] * c2_validLocation->size[1];
  c2_validLocation->size[0] = c2_r19->size[0];
  c2_validLocation->size[1] = 2;
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_validLocation, c2_i851,
    &c2_ki_emlrtRTEI);
  for (c2_i852 = 0; c2_i852 < 2; c2_i852++) {
    c2_h_loop_ub = c2_r19->size[0] - 1;
    for (c2_i853 = 0; c2_i853 <= c2_h_loop_ub; c2_i853++) {
      c2_validLocation->data[c2_i853 + c2_validLocation->size[0] * c2_i852] =
        c2_locInImage->data[(sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c2_r19->data[c2_i853], 1, c2_b_locInImage) + c2_locInImage->size[0] *
        c2_i852) - 1];
    }
  }

  c2_emxFree_int32_T(chartInstance, &c2_r19);
  c2_emxFree_real32_T(chartInstance, &c2_locInImage);
  c2_b_end = c2_r17->size[0] - 1;
  c2_b_trueCount = 0;
  for (c2_c_i = 0; c2_c_i <= c2_b_end; c2_c_i++) {
    if (c2_r17->data[c2_c_i] && c2_r18->data[c2_c_i]) {
      c2_b_trueCount++;
    }
  }

  c2_emxInit_int32_T(chartInstance, &c2_r20, 1, &c2_oi_emlrtRTEI);
  c2_i854 = c2_r20->size[0];
  c2_r20->size[0] = c2_b_trueCount;
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_r20, c2_i854, &c2_ji_emlrtRTEI);
  c2_b_partialTrueCount = 0;
  for (c2_d_i = 0; c2_d_i <= c2_b_end; c2_d_i++) {
    if (c2_r17->data[c2_d_i] && c2_r18->data[c2_d_i]) {
      c2_r20->data[c2_b_partialTrueCount] = c2_d_i + 1;
      c2_b_partialTrueCount++;
    }
  }

  c2_emxFree_boolean_T(chartInstance, &c2_r18);
  c2_emxFree_boolean_T(chartInstance, &c2_r17);
  c2_b_metric[0] = c2_metric->size[0];
  c2_b_metric[1] = 1;
  c2_c_metric = c2_metric->size[0];
  c2_i855 = c2_validMetric->size[0];
  c2_validMetric->size[0] = c2_r20->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_validMetric, c2_i855,
    &c2_li_emlrtRTEI);
  c2_i_loop_ub = c2_r20->size[0] - 1;
  for (c2_i856 = 0; c2_i856 <= c2_i_loop_ub; c2_i856++) {
    c2_validMetric->data[c2_i856] = c2_metric->data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       c2_r20->data[c2_i856], 1, c2_c_metric) - 1];
  }

  c2_emxFree_int32_T(chartInstance, &c2_r20);
}

static void c2_b_indexShapeCheck(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, int32_T c2_matrixSize[2])
{
  (void)chartInstance;
  (void)c2_matrixSize;
}

static void c2_bsxfun(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
                      c2_emxArray_real32_T *c2_a, real32_T c2_b[2],
                      c2_emxArray_real32_T *c2_c)
{
  int32_T c2_csz[2];
  int32_T c2_i857;
  int32_T c2_k;
  int32_T c2_szc;
  int32_T c2_acoef;
  int32_T c2_b_k;
  c2_csz[0] = c2_a->size[0];
  c2_i857 = c2_c->size[0] * c2_c->size[1];
  c2_c->size[0] = c2_csz[0];
  c2_c->size[1] = 2;
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_c, c2_i857, &c2_pi_emlrtRTEI);
  if (c2_c->size[0] == 0) {
  } else {
    for (c2_k = 0; c2_k < 2; c2_k++) {
      c2_szc = c2_c->size[0] - 1;
      c2_acoef = (c2_a->size[0] != 1);
      for (c2_b_k = 0; c2_b_k <= c2_szc; c2_b_k++) {
        c2_c->data[c2_b_k + c2_c->size[0] * c2_k] = c2_a->data[c2_acoef * c2_b_k
          + c2_a->size[0] * c2_k] + c2_b[c2_k];
      }
    }
  }
}

static void c2_cornerPoints_cg_cornerPoints_cg
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance, c2_emxArray_real32_T
   *c2_varargin_1, c2_emxArray_real32_T *c2_varargin_3,
   c2_vision_internal_cornerPoints_cg *c2_this)
{
  c2_emxArray_real32_T *c2_b_varargin_1;
  int32_T c2_i858;
  int32_T c2_i859;
  int32_T c2_i860;
  int32_T c2_c_varargin_1;
  int32_T c2_d_varargin_1;
  int32_T c2_loop_ub;
  int32_T c2_i861;
  c2_emxArray_real32_T *c2_b_varargin_3;
  int32_T c2_i862;
  int32_T c2_b_loop_ub;
  int32_T c2_i863;
  c2_emxInit_real32_T(chartInstance, &c2_b_varargin_1, 2, &c2_ri_emlrtRTEI);
  c2_i858 = c2_this->pLocation->size[0] * c2_this->pLocation->size[1];
  c2_this->pLocation->size[0] = 0;
  c2_this->pLocation->size[1] = 2;
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_this->pLocation, c2_i858,
    &c2_qi_emlrtRTEI);
  c2_i859 = c2_this->pMetric->size[0];
  c2_this->pMetric->size[0] = 0;
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_this->pMetric, c2_i859,
    &c2_qi_emlrtRTEI);
  c2_i860 = c2_b_varargin_1->size[0] * c2_b_varargin_1->size[1];
  c2_b_varargin_1->size[0] = c2_varargin_1->size[0];
  c2_b_varargin_1->size[1] = 2;
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_b_varargin_1, c2_i860,
    &c2_ri_emlrtRTEI);
  c2_c_varargin_1 = c2_b_varargin_1->size[0];
  c2_d_varargin_1 = c2_b_varargin_1->size[1];
  c2_loop_ub = c2_varargin_1->size[0] * c2_varargin_1->size[1] - 1;
  for (c2_i861 = 0; c2_i861 <= c2_loop_ub; c2_i861++) {
    c2_b_varargin_1->data[c2_i861] = c2_varargin_1->data[c2_i861];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_b_varargin_3, 1, &c2_ri_emlrtRTEI);
  c2_i862 = c2_b_varargin_3->size[0];
  c2_b_varargin_3->size[0] = c2_varargin_3->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_b_varargin_3, c2_i862,
    &c2_ri_emlrtRTEI);
  c2_b_loop_ub = c2_varargin_3->size[0] - 1;
  for (c2_i863 = 0; c2_i863 <= c2_b_loop_ub; c2_i863++) {
    c2_b_varargin_3->data[c2_i863] = c2_varargin_3->data[c2_i863];
  }

  c2_b_FeaturePointsImpl_FeaturePointsImpl(chartInstance, c2_this,
    c2_b_varargin_1, c2_b_varargin_3);
  c2_emxFree_real32_T(chartInstance, &c2_b_varargin_3);
  c2_emxFree_real32_T(chartInstance, &c2_b_varargin_1);
}

static void c2_FeaturePointsImpl_FeaturePointsImpl
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
   c2_vision_internal_cornerPoints_cg c2_this, c2_emxArray_real32_T
   *c2_varargin_1, c2_emxArray_real32_T *c2_varargin_3,
   c2_vision_internal_cornerPoints_cg *c2_b_this)
{
  c2_emxArray_real32_T *c2_b_varargin_1;
  int32_T c2_i864;
  int32_T c2_c_varargin_1;
  int32_T c2_d_varargin_1;
  int32_T c2_loop_ub;
  int32_T c2_i865;
  c2_emxArray_real32_T *c2_b_varargin_3;
  int32_T c2_i866;
  int32_T c2_b_loop_ub;
  int32_T c2_i867;
  c2_emxInit_real32_T(chartInstance, &c2_b_varargin_1, 2, &c2_si_emlrtRTEI);
  c2_emxCopyStruct_vision_internal_c(chartInstance, c2_b_this, &c2_this,
    &c2_si_emlrtRTEI);
  c2_i864 = c2_b_varargin_1->size[0] * c2_b_varargin_1->size[1];
  c2_b_varargin_1->size[0] = c2_varargin_1->size[0];
  c2_b_varargin_1->size[1] = 2;
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_b_varargin_1, c2_i864,
    &c2_si_emlrtRTEI);
  c2_c_varargin_1 = c2_b_varargin_1->size[0];
  c2_d_varargin_1 = c2_b_varargin_1->size[1];
  c2_loop_ub = c2_varargin_1->size[0] * c2_varargin_1->size[1] - 1;
  for (c2_i865 = 0; c2_i865 <= c2_loop_ub; c2_i865++) {
    c2_b_varargin_1->data[c2_i865] = c2_varargin_1->data[c2_i865];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_b_varargin_3, 1, &c2_si_emlrtRTEI);
  c2_i866 = c2_b_varargin_3->size[0];
  c2_b_varargin_3->size[0] = c2_varargin_3->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_b_varargin_3, c2_i866,
    &c2_si_emlrtRTEI);
  c2_b_loop_ub = c2_varargin_3->size[0] - 1;
  for (c2_i867 = 0; c2_i867 <= c2_b_loop_ub; c2_i867++) {
    c2_b_varargin_3->data[c2_i867] = c2_varargin_3->data[c2_i867];
  }

  c2_b_FeaturePointsImpl_FeaturePointsImpl(chartInstance, c2_b_this,
    c2_b_varargin_1, c2_b_varargin_3);
  c2_emxFree_real32_T(chartInstance, &c2_b_varargin_3);
  c2_emxFree_real32_T(chartInstance, &c2_b_varargin_1);
}

static void c2_FeaturePointsImpl_validate(SFc2_DetectAndTrackFaceInstanceStruct *
  chartInstance, c2_sjeQsvJNEhdsHQhIigwA2FF c2_inputs)
{
  static real_T c2_dv6[2] = { 0.0, 2.0 };

  boolean_T c2_p;
  real_T c2_d22;
  int32_T c2_k;
  boolean_T c2_b21;
  const mxArray *c2_y = NULL;
  static char_T c2_cv37[53] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'v', 'i', 's',
    'i', 'o', 'n', '.', 'i', 'n', 't', 'e', 'r', 'n', 'a', 'l', '.', 'c', 'o',
    'r', 'n', 'e', 'r', 'P', 'o', 'i', 'n', 't', 's', '_', 'c', 'g', ':', 'e',
    'x', 'p', 'e', 'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  boolean_T c2_b_p;
  const mxArray *c2_b_y = NULL;
  real_T c2_d23;
  static char_T c2_cv38[29] = { 'E', 'x', 'p', 'e', 'c', 't', 'e', 'd', ' ', 'i',
    'n', 'p', 'u', 't', ' ', 't', 'o', ' ', 'b', 'e', ' ', 'n', 'o', 'n', '-',
    'N', 'a', 'N', '.' };

  int32_T c2_b_k;
  boolean_T c2_b22;
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv39[53] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'v', 'i', 's',
    'i', 'o', 'n', '.', 'i', 'n', 't', 'e', 'r', 'n', 'a', 'l', '.', 'c', 'o',
    'r', 'n', 'e', 'r', 'P', 'o', 'i', 'n', 't', 's', '_', 'c', 'g', ':', 'e',
    'x', 'p', 'e', 'c', 't', 'e', 'd', 'F', 'i', 'n', 'i', 't', 'e' };

  boolean_T c2_c_p;
  const mxArray *c2_d_y = NULL;
  real_T c2_d24;
  static char_T c2_cv40[28] = { 'E', 'x', 'p', 'e', 'c', 't', 'e', 'd', ' ', 'i',
    'n', 'p', 'u', 't', ' ', 't', 'o', ' ', 'b', 'e', ' ', 'f', 'i', 'n', 'i',
    't', 'e', '.' };

  int32_T c2_c_k;
  boolean_T c2_b23;
  const mxArray *c2_e_y = NULL;
  static char_T c2_cv41[55] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'v', 'i', 's',
    'i', 'o', 'n', '.', 'i', 'n', 't', 'e', 'r', 'n', 'a', 'l', '.', 'c', 'o',
    'r', 'n', 'e', 'r', 'P', 'o', 'i', 'n', 't', 's', '_', 'c', 'g', ':', 'e',
    'x', 'p', 'e', 'c', 't', 'e', 'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  boolean_T c2_d_p;
  const mxArray *c2_f_y = NULL;
  int32_T c2_d_k;
  static char_T c2_cv42[30] = { 'E', 'x', 'p', 'e', 'c', 't', 'e', 'd', ' ', 'i',
    'n', 'p', 'u', 't', ' ', 't', 'o', ' ', 'b', 'e', ' ', 'p', 'o', 's', 'i',
    't', 'i', 'v', 'e', '.' };

  real_T c2_szk;
  const mxArray *c2_g_y = NULL;
  static char_T c2_cv43[52] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'v', 'i', 's',
    'i', 'o', 'n', '.', 'i', 'n', 't', 'e', 'r', 'n', 'a', 'l', '.', 'c', 'o',
    'r', 'n', 'e', 'r', 'P', 'o', 'i', 'n', 't', 's', '_', 'c', 'g', ':', 'i',
    'n', 'c', 'o', 'r', 'r', 'e', 'c', 't', 'S', 'i', 'z', 'e' };

  boolean_T c2_e_p;
  const mxArray *c2_h_y = NULL;
  int32_T c2_e_k;
  static char_T c2_b_u[38] = { 'I', 'n', 'p', 'u', 't', ' ', 'd', 'o', 'e', 's',
    ' ', 'n', 'o', 't', ' ', 'h', 'a', 'v', 'e', ' ', 't', 'h', 'e', ' ', 'e',
    'x', 'p', 'e', 'c', 't', 'e', 'd', ' ', 's', 'i', 'z', 'e', '.' };

  boolean_T c2_b24;
  const mxArray *c2_i_y = NULL;
  static char_T c2_cv44[53] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'v', 'i', 's',
    'i', 'o', 'n', '.', 'i', 'n', 't', 'e', 'r', 'n', 'a', 'l', '.', 'c', 'o',
    'r', 'n', 'e', 'r', 'P', 'o', 'i', 'n', 't', 's', '_', 'c', 'g', ':', 'e',
    'x', 'p', 'e', 'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  boolean_T c2_f_p;
  const mxArray *c2_j_y = NULL;
  int32_T c2_f_k;
  static char_T c2_cv45[30] = { 'E', 'x', 'p', 'e', 'c', 't', 'e', 'd', ' ', 'M',
    'e', 't', 'r', 'i', 'c', ' ', 't', 'o', ' ', 'b', 'e', ' ', 'n', 'o', 'n',
    '-', 'N', 'a', 'N', '.' };

  boolean_T c2_b25;
  const mxArray *c2_k_y = NULL;
  static char_T c2_cv46[53] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'v', 'i', 's',
    'i', 'o', 'n', '.', 'i', 'n', 't', 'e', 'r', 'n', 'a', 'l', '.', 'c', 'o',
    'r', 'n', 'e', 'r', 'P', 'o', 'i', 'n', 't', 's', '_', 'c', 'g', ':', 'e',
    'x', 'p', 'e', 'c', 't', 'e', 'd', 'F', 'i', 'n', 'i', 't', 'e' };

  const mxArray *c2_l_y = NULL;
  static char_T c2_cv47[29] = { 'E', 'x', 'p', 'e', 'c', 't', 'e', 'd', ' ', 'M',
    'e', 't', 'r', 'i', 'c', ' ', 't', 'o', ' ', 'b', 'e', ' ', 'f', 'i', 'n',
    'i', 't', 'e', '.' };

  boolean_T c2_b26;
  const mxArray *c2_m_y = NULL;
  static char_T c2_cv48[39] = { 'v', 'i', 's', 'i', 'o', 'n', ':', 'F', 'e', 'a',
    't', 'u', 'r', 'e', 'P', 'o', 'i', 'n', 't', 's', ':', 'i', 'n', 'v', 'a',
    'l', 'i', 'd', 'P', 'a', 'r', 'a', 'm', 'L', 'e', 'n', 'g', 't', 'h' };

  const mxArray *c2_n_y = NULL;
  static char_T c2_cv49[6] = { 'M', 'e', 't', 'r', 'i', 'c' };

  boolean_T exitg1;
  (void)chartInstance;
  c2_dv6[0U] = rtNaN;
  c2_p = true;
  c2_d22 = (real_T)(c2_inputs.Location->size[0] * c2_inputs.Location->size[1]);
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k <= (int32_T)c2_d22 - 1)) {
    if (!muSingleScalarIsNaN(c2_inputs.Location->data[c2_k])) {
      c2_k++;
    } else {
      c2_p = false;
      exitg1 = true;
    }
  }

  c2_b21 = c2_p;
  if (c2_b21) {
  } else {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv37, 10, 0U, 1U, 0U, 2, 1, 53),
                  false);
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv38, 10, 0U, 1U, 0U, 2, 1, 29),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_y, 14,
                      c2_b_y);
  }

  c2_b_p = true;
  c2_d23 = (real_T)(c2_inputs.Location->size[0] << 1);
  c2_b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_b_k <= (int32_T)c2_d23 - 1)) {
    if ((!muSingleScalarIsInf(c2_inputs.Location->data[c2_b_k])) &&
        (!muSingleScalarIsNaN(c2_inputs.Location->data[c2_b_k]))) {
      c2_b_k++;
    } else {
      c2_b_p = false;
      exitg1 = true;
    }
  }

  c2_b22 = c2_b_p;
  if (c2_b22) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv39, 10, 0U, 1U, 0U, 2, 1, 53),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv40, 10, 0U, 1U, 0U, 2, 1, 28),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_c_y,
                      14, c2_d_y);
  }

  c2_c_p = true;
  c2_d24 = (real_T)(c2_inputs.Location->size[0] << 1);
  c2_c_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_c_k <= (int32_T)c2_d24 - 1)) {
    if (!(c2_inputs.Location->data[c2_c_k] <= 0.0F)) {
      c2_c_k++;
    } else {
      c2_c_p = false;
      exitg1 = true;
    }
  }

  c2_b23 = c2_c_p;
  if (c2_b23) {
  } else {
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv41, 10, 0U, 1U, 0U, 2, 1, 55),
                  false);
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv42, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_e_y,
                      14, c2_f_y);
  }

  c2_d_p = true;
  c2_d_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_d_k < 2)) {
    c2_szk = c2_dv6[c2_d_k];
    if (muDoubleScalarIsNaN(c2_szk) || (c2_szk == (real_T)
         c2_inputs.Location->size[c2_d_k])) {
      c2_d_k++;
    } else {
      c2_d_p = false;
      exitg1 = true;
    }
  }

  if (c2_d_p) {
  } else {
    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_cv43, 10, 0U, 1U, 0U, 2, 1, 52),
                  false);
    c2_h_y = NULL;
    sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 38),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_g_y,
                      14, c2_h_y);
  }

  c2_e_p = true;
  c2_e_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_e_k <= c2_inputs.Metric->size[0] - 1)) {
    if (!muSingleScalarIsNaN(c2_inputs.Metric->data[c2_e_k])) {
      c2_e_k++;
    } else {
      c2_e_p = false;
      exitg1 = true;
    }
  }

  c2_b24 = c2_e_p;
  if (c2_b24) {
  } else {
    c2_i_y = NULL;
    sf_mex_assign(&c2_i_y, sf_mex_create("y", c2_cv44, 10, 0U, 1U, 0U, 2, 1, 53),
                  false);
    c2_j_y = NULL;
    sf_mex_assign(&c2_j_y, sf_mex_create("y", c2_cv45, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_i_y,
                      14, c2_j_y);
  }

  c2_f_p = true;
  c2_f_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_f_k <= c2_inputs.Metric->size[0] - 1)) {
    if ((!muSingleScalarIsInf(c2_inputs.Metric->data[c2_f_k])) &&
        (!muSingleScalarIsNaN(c2_inputs.Metric->data[c2_f_k]))) {
      c2_f_k++;
    } else {
      c2_f_p = false;
      exitg1 = true;
    }
  }

  c2_b25 = c2_f_p;
  if (c2_b25) {
  } else {
    c2_k_y = NULL;
    sf_mex_assign(&c2_k_y, sf_mex_create("y", c2_cv46, 10, 0U, 1U, 0U, 2, 1, 53),
                  false);
    c2_l_y = NULL;
    sf_mex_assign(&c2_l_y, sf_mex_create("y", c2_cv47, 10, 0U, 1U, 0U, 2, 1, 29),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_k_y,
                      14, c2_l_y);
  }

  if (((real_T)c2_inputs.Metric->size[0] == 1.0) || ((real_T)
       c2_inputs.Metric->size[0] == (real_T)c2_inputs.Location->size[0])) {
    c2_b26 = true;
  } else {
    c2_b26 = false;
  }

  if (c2_b26) {
  } else {
    c2_m_y = NULL;
    sf_mex_assign(&c2_m_y, sf_mex_create("y", c2_cv48, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c2_n_y = NULL;
    sf_mex_assign(&c2_n_y, sf_mex_create("y", c2_cv49, 10, 0U, 1U, 0U, 2, 1, 6),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c2_m_y, 14, c2_n_y));
  }
}

static void c2_b_repmat(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  real32_T c2_a_data[], int32_T c2_a_size[1], real_T c2_varargin_1,
  c2_emxArray_real32_T *c2_b)
{
  int32_T c2_outsize[2];
  int32_T c2_i868;
  boolean_T c2_p;
  int32_T c2_itilerow;
  (void)c2_a_size;
  c2_b_assertValidSizeArg(chartInstance, c2_varargin_1);
  c2_outsize[0] = (int32_T)c2_varargin_1;
  if ((real_T)c2_outsize[0] == (real_T)(int32_T)c2_varargin_1) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      c2_d_emlrt_marshallOut(chartInstance, c2_cv1));
  }

  c2_i868 = c2_b->size[0];
  c2_b->size[0] = c2_outsize[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_b, c2_i868, &c2_ti_emlrtRTEI);
  c2_p = (c2_outsize[0] == 0);
  if (!c2_p) {
    for (c2_itilerow = 0; c2_itilerow + 1 <= (int32_T)c2_varargin_1; c2_itilerow
         ++) {
      c2_b->data[c2_itilerow] = c2_a_data[0];
    }
  }
}

static void c2_b_assertValidSizeArg(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, real_T c2_varargin_1)
{
  boolean_T c2_p;
  boolean_T c2_b_p;
  boolean_T c2_b27;
  const mxArray *c2_y = NULL;
  static char_T c2_cv50[28] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'N', 'o', 'n', 'I', 'n', 't', 'e', 'g', 'e', 'r', 'I', 'n',
    'p', 'u', 't' };

  int32_T c2_b_u;
  real_T c2_n;
  const mxArray *c2_b_y = NULL;
  int32_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  (void)chartInstance;
  c2_p = !(c2_varargin_1 != c2_varargin_1);
  if (c2_p) {
    c2_b_p = !(-2.147483648E+9 > c2_varargin_1);
    if (c2_b_p) {
      c2_b27 = true;
    } else {
      c2_b27 = false;
    }
  } else {
    c2_b27 = false;
  }

  if (c2_b27) {
  } else {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv50, 10, 0U, 1U, 0U, 2, 1, 28),
                  false);
    c2_b_u = MIN_int32_T;
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 6, 0U, 0U, 0U, 0), false);
    c2_c_u = MAX_int32_T;
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 6, 0U, 0U, 0U, 0), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 3U, 14, c2_y, 14, c2_b_y, 14, c2_d_y));
  }

  if (c2_varargin_1 <= 0.0) {
    c2_n = 0.0;
  } else {
    c2_n = c2_varargin_1;
  }

  if (2.147483647E+9 >= c2_n) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_c_y));
  }
}

static boolean_T c2_j_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_feval, const char_T *c2_identifier)
{
  boolean_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_feval), &c2_thisId);
  sf_mex_destroy(&c2_feval);
  return c2_y;
}

static boolean_T c2_k_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  boolean_T c2_y;
  boolean_T c2_b28;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_b28, 1, 11, 0U, 0, 0U, 0);
  c2_y = c2_b28;
  sf_mex_destroy(&c2_b_u);
  return c2_y;
}

static const mxArray *c2_emlrt_marshallOut(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const char_T c2_b_u[30])
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  return c2_y;
}

static const mxArray *c2_b_emlrt_marshallOut
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance, const char_T c2_b_u[34])
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  return c2_y;
}

static const mxArray *c2_c_emlrt_marshallOut
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance, const char_T c2_b_u[36])
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 36),
                false);
  return c2_y;
}

static const mxArray *c2_d_emlrt_marshallOut
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance, const char_T c2_b_u[15])
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 15),
                false);
  return c2_y;
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_b_u;
  const mxArray *c2_y = NULL;
  SFc2_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc2_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_l_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i869;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_i869, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i869;
  sf_mex_destroy(&c2_b_u);
  return c2_y;
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc2_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, real_T
  c2_inData_data[16], int32_T c2_inData_sizes[2])
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_u_size[2];
  int32_T c2_b_u;
  int32_T c2_c_u;
  int32_T c2_loop_ub;
  int32_T c2_i870;
  const mxArray *c2_y = NULL;
  real_T c2_u_data[16];
  SFc2_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc2_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u_size[0] = c2_inData_sizes[0];
  c2_u_size[1] = c2_inData_sizes[1];
  c2_b_u = c2_u_size[0];
  c2_c_u = c2_u_size[1];
  c2_loop_ub = c2_inData_sizes[0] * c2_inData_sizes[1] - 1;
  for (c2_i870 = 0; c2_i870 <= c2_loop_ub; c2_i870++) {
    c2_u_data[c2_i870] = c2_inData_data[c2_i870];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", (void *)&c2_u_data, 0, 0U, 1U, 0U, 2,
    c2_u_size[0], c2_u_size[1]), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, real_T c2_outData_data[16],
  int32_T c2_outData_sizes[2])
{
  const mxArray *c2_bBox;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y_data[16];
  int32_T c2_y_size[2];
  int32_T c2_loop_ub;
  int32_T c2_i871;
  int32_T c2_b_loop_ub;
  int32_T c2_i872;
  SFc2_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc2_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c2_bBox = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_bBox), &c2_thisId,
                        c2_y_data, c2_y_size);
  sf_mex_destroy(&c2_bBox);
  c2_outData_sizes[0] = c2_y_size[0];
  c2_outData_sizes[1] = c2_y_size[1];
  c2_loop_ub = c2_y_size[1] - 1;
  for (c2_i871 = 0; c2_i871 <= c2_loop_ub; c2_i871++) {
    c2_b_loop_ub = c2_y_size[0] - 1;
    for (c2_i872 = 0; c2_i872 <= c2_b_loop_ub; c2_i872++) {
      c2_outData_data[c2_i872 + c2_outData_sizes[0] * c2_i871] =
        c2_y_data[c2_i872 + c2_y_size[0] * c2_i871];
    }
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, real32_T
  c2_inData_data[1000], int32_T c2_inData_sizes[2])
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_u_size[2];
  int32_T c2_b_u;
  int32_T c2_c_u;
  int32_T c2_loop_ub;
  int32_T c2_i873;
  const mxArray *c2_y = NULL;
  real32_T c2_u_data[1000];
  SFc2_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc2_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u_size[0] = c2_inData_sizes[0];
  c2_u_size[1] = c2_inData_sizes[1];
  c2_b_u = c2_u_size[0];
  c2_c_u = c2_u_size[1];
  c2_loop_ub = c2_inData_sizes[0] * c2_inData_sizes[1] - 1;
  for (c2_i873 = 0; c2_i873 <= c2_loop_ub; c2_i873++) {
    c2_u_data[c2_i873] = c2_inData_data[c2_i873];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", (void *)&c2_u_data, 1, 0U, 1U, 0U, 2,
    c2_u_size[0], c2_u_size[1]), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, real32_T c2_outData_data[1000],
  int32_T c2_outData_sizes[2])
{
  const mxArray *c2_featurePointLocations;
  emlrtMsgIdentifier c2_thisId;
  real32_T c2_y_data[1000];
  int32_T c2_y_size[2];
  int32_T c2_loop_ub;
  int32_T c2_i874;
  int32_T c2_b_loop_ub;
  int32_T c2_i875;
  SFc2_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc2_DetectAndTrackFaceInstanceStruct *)chartInstanceVoid;
  c2_featurePointLocations = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_featurePointLocations),
                        &c2_thisId, c2_y_data, c2_y_size);
  sf_mex_destroy(&c2_featurePointLocations);
  c2_outData_sizes[0] = c2_y_size[0];
  c2_outData_sizes[1] = c2_y_size[1];
  c2_loop_ub = c2_y_size[1] - 1;
  for (c2_i874 = 0; c2_i874 <= c2_loop_ub; c2_i874++) {
    c2_b_loop_ub = c2_y_size[0] - 1;
    for (c2_i875 = 0; c2_i875 <= c2_b_loop_ub; c2_i875++) {
      c2_outData_data[c2_i875 + c2_outData_sizes[0] * c2_i874] =
        c2_y_data[c2_i875 + c2_y_size[0] * c2_i874];
    }
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_m_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_DetectAndTrackFace, const
  char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_n_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_DetectAndTrackFace), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_DetectAndTrackFace);
  return c2_y;
}

static uint8_T c2_n_emlrt_marshallIn(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u9;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_u9, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u9;
  sf_mex_destroy(&c2_b_u);
  return c2_y;
}

static void c2_d_imfilter(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_real32_T *c2_varargin_1)
{
  real_T c2_finalSize[2];
  real_T c2_pad[2];
  c2_emxArray_real32_T *c2_b_varargin_1;
  int32_T c2_i876;
  int32_T c2_c_varargin_1;
  int32_T c2_d_varargin_1;
  int32_T c2_loop_ub;
  int32_T c2_i877;
  int32_T c2_i878;
  c2_emxArray_real32_T *c2_a;
  real_T c2_b_pad[2];
  c2_emxArray_real32_T *c2_r21;
  int32_T c2_i879;
  int32_T c2_b_a;
  int32_T c2_c_a;
  int32_T c2_b_loop_ub;
  int32_T c2_i880;
  boolean_T c2_tooBig;
  int32_T c2_i;
  boolean_T c2_modeFlag;
  int32_T c2_i881;
  int32_T c2_i882;
  int32_T c2_i883;
  int32_T c2_i884;
  real_T c2_padSize[2];
  int32_T c2_i885;
  int32_T c2_i886;
  real_T c2_nonZeroKernel[2];
  int32_T c2_i887;
  real_T c2_kernel[3];
  static boolean_T c2_conn[3] = { true, false, true };

  real_T c2_connDims[2];
  c2_finalSize[0] = (real_T)c2_varargin_1->size[0];
  c2_pad[0] = 0.0;
  c2_finalSize[1] = (real_T)c2_varargin_1->size[1];
  c2_pad[1] = 1.0;
  if ((c2_varargin_1->size[0] == 0) || (c2_varargin_1->size[1] == 0)) {
  } else {
    c2_emxInit_real32_T(chartInstance, &c2_b_varargin_1, 2, &c2_ui_emlrtRTEI);
    c2_i876 = c2_b_varargin_1->size[0] * c2_b_varargin_1->size[1];
    c2_b_varargin_1->size[0] = c2_varargin_1->size[0];
    c2_b_varargin_1->size[1] = c2_varargin_1->size[1];
    c2_emxEnsureCapacity_real32_T(chartInstance, c2_b_varargin_1, c2_i876,
      &c2_ui_emlrtRTEI);
    c2_c_varargin_1 = c2_b_varargin_1->size[0];
    c2_d_varargin_1 = c2_b_varargin_1->size[1];
    c2_loop_ub = c2_varargin_1->size[0] * c2_varargin_1->size[1] - 1;
    for (c2_i877 = 0; c2_i877 <= c2_loop_ub; c2_i877++) {
      c2_b_varargin_1->data[c2_i877] = c2_varargin_1->data[c2_i877];
    }

    for (c2_i878 = 0; c2_i878 < 2; c2_i878++) {
      c2_b_pad[c2_i878] = c2_pad[c2_i878];
    }

    c2_emxInit_real32_T(chartInstance, &c2_a, 2, &c2_xc_emlrtRTEI);
    c2_emxInit_real32_T(chartInstance, &c2_r21, 2, &c2_wi_emlrtRTEI);
    c2_padImage(chartInstance, c2_b_varargin_1, c2_b_pad, c2_r21);
    c2_i879 = c2_a->size[0] * c2_a->size[1];
    c2_a->size[0] = c2_r21->size[0];
    c2_a->size[1] = c2_r21->size[1];
    c2_emxEnsureCapacity_real32_T(chartInstance, c2_a, c2_i879, &c2_vi_emlrtRTEI);
    c2_b_a = c2_a->size[0];
    c2_c_a = c2_a->size[1];
    c2_b_loop_ub = c2_r21->size[0] * c2_r21->size[1] - 1;
    c2_emxFree_real32_T(chartInstance, &c2_b_varargin_1);
    for (c2_i880 = 0; c2_i880 <= c2_b_loop_ub; c2_i880++) {
      c2_a->data[c2_i880] = c2_r21->data[c2_i880];
    }

    c2_emxFree_real32_T(chartInstance, &c2_r21);
    c2_tooBig = true;
    for (c2_i = 0; c2_i < 2; c2_i++) {
      c2_tooBig = false;
    }

    c2_modeFlag = !c2_tooBig;
    c2_i881 = c2_varargin_1->size[0] * c2_varargin_1->size[1];
    c2_varargin_1->size[0] = (int32_T)c2_finalSize[0];
    c2_varargin_1->size[1] = (int32_T)c2_finalSize[1];
    c2_emxEnsureCapacity_real32_T(chartInstance, c2_varargin_1, c2_i881,
      &c2_wc_emlrtRTEI);
    if (c2_modeFlag) {
      for (c2_i883 = 0; c2_i883 < 2; c2_i883++) {
        c2_padSize[c2_i883] = (real_T)c2_a->size[c2_i883];
      }

      for (c2_i885 = 0; c2_i885 < 3; c2_i885++) {
        c2_kernel[c2_i885] = -1.0 + (real_T)c2_i885;
      }

      for (c2_i887 = 0; c2_i887 < 2; c2_i887++) {
        c2_pad[c2_i887] = 1.0 + 2.0 * (real_T)c2_i887;
      }

      ippfilter_real32(&c2_a->data[0], &c2_varargin_1->data[0], c2_finalSize,
                       2.0, c2_padSize, c2_kernel, c2_pad, true);
    } else {
      for (c2_i882 = 0; c2_i882 < 2; c2_i882++) {
        c2_padSize[c2_i882] = (real_T)c2_a->size[c2_i882];
      }

      for (c2_i884 = 0; c2_i884 < 2; c2_i884++) {
        c2_nonZeroKernel[c2_i884] = -1.0 + 2.0 * (real_T)c2_i884;
      }

      for (c2_i886 = 0; c2_i886 < 2; c2_i886++) {
        c2_connDims[c2_i886] = 1.0 + 2.0 * (real_T)c2_i886;
      }

      imfilter_real32(&c2_a->data[0], &c2_varargin_1->data[0], 2.0, c2_finalSize,
                      2.0, c2_padSize, c2_nonZeroKernel, 2.0, c2_conn, 2.0,
                      c2_connDims, c2_pad, 2.0, true, true);
    }

    c2_emxFree_real32_T(chartInstance, &c2_a);
  }
}

static void c2_e_imfilter(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_real32_T *c2_varargin_1)
{
  real_T c2_finalSize[2];
  real_T c2_pad[2];
  c2_emxArray_real32_T *c2_b_varargin_1;
  int32_T c2_i888;
  int32_T c2_c_varargin_1;
  int32_T c2_d_varargin_1;
  int32_T c2_loop_ub;
  int32_T c2_i889;
  int32_T c2_i890;
  c2_emxArray_real32_T *c2_a;
  real_T c2_b_pad[2];
  c2_emxArray_real32_T *c2_r22;
  int32_T c2_i891;
  int32_T c2_b_a;
  int32_T c2_c_a;
  int32_T c2_b_loop_ub;
  int32_T c2_i892;
  boolean_T c2_tooBig;
  int32_T c2_i;
  boolean_T c2_modeFlag;
  int32_T c2_i893;
  int32_T c2_i894;
  int32_T c2_i895;
  int32_T c2_i896;
  real_T c2_padSize[2];
  int32_T c2_i897;
  int32_T c2_i898;
  real_T c2_nonZeroKernel[2];
  int32_T c2_i899;
  real_T c2_kernel[3];
  static boolean_T c2_conn[3] = { true, false, true };

  real_T c2_connDims[2];
  c2_finalSize[0] = (real_T)c2_varargin_1->size[0];
  c2_pad[0] = 1.0;
  c2_finalSize[1] = (real_T)c2_varargin_1->size[1];
  c2_pad[1] = 0.0;
  if ((c2_varargin_1->size[0] == 0) || (c2_varargin_1->size[1] == 0)) {
  } else {
    c2_emxInit_real32_T(chartInstance, &c2_b_varargin_1, 2, &c2_ui_emlrtRTEI);
    c2_i888 = c2_b_varargin_1->size[0] * c2_b_varargin_1->size[1];
    c2_b_varargin_1->size[0] = c2_varargin_1->size[0];
    c2_b_varargin_1->size[1] = c2_varargin_1->size[1];
    c2_emxEnsureCapacity_real32_T(chartInstance, c2_b_varargin_1, c2_i888,
      &c2_ui_emlrtRTEI);
    c2_c_varargin_1 = c2_b_varargin_1->size[0];
    c2_d_varargin_1 = c2_b_varargin_1->size[1];
    c2_loop_ub = c2_varargin_1->size[0] * c2_varargin_1->size[1] - 1;
    for (c2_i889 = 0; c2_i889 <= c2_loop_ub; c2_i889++) {
      c2_b_varargin_1->data[c2_i889] = c2_varargin_1->data[c2_i889];
    }

    for (c2_i890 = 0; c2_i890 < 2; c2_i890++) {
      c2_b_pad[c2_i890] = c2_pad[c2_i890];
    }

    c2_emxInit_real32_T(chartInstance, &c2_a, 2, &c2_xc_emlrtRTEI);
    c2_emxInit_real32_T(chartInstance, &c2_r22, 2, &c2_wi_emlrtRTEI);
    c2_padImage(chartInstance, c2_b_varargin_1, c2_b_pad, c2_r22);
    c2_i891 = c2_a->size[0] * c2_a->size[1];
    c2_a->size[0] = c2_r22->size[0];
    c2_a->size[1] = c2_r22->size[1];
    c2_emxEnsureCapacity_real32_T(chartInstance, c2_a, c2_i891, &c2_vi_emlrtRTEI);
    c2_b_a = c2_a->size[0];
    c2_c_a = c2_a->size[1];
    c2_b_loop_ub = c2_r22->size[0] * c2_r22->size[1] - 1;
    c2_emxFree_real32_T(chartInstance, &c2_b_varargin_1);
    for (c2_i892 = 0; c2_i892 <= c2_b_loop_ub; c2_i892++) {
      c2_a->data[c2_i892] = c2_r22->data[c2_i892];
    }

    c2_emxFree_real32_T(chartInstance, &c2_r22);
    c2_tooBig = true;
    for (c2_i = 0; c2_i < 2; c2_i++) {
      c2_tooBig = false;
    }

    c2_modeFlag = !c2_tooBig;
    c2_i893 = c2_varargin_1->size[0] * c2_varargin_1->size[1];
    c2_varargin_1->size[0] = (int32_T)c2_finalSize[0];
    c2_varargin_1->size[1] = (int32_T)c2_finalSize[1];
    c2_emxEnsureCapacity_real32_T(chartInstance, c2_varargin_1, c2_i893,
      &c2_wc_emlrtRTEI);
    if (c2_modeFlag) {
      for (c2_i895 = 0; c2_i895 < 2; c2_i895++) {
        c2_padSize[c2_i895] = (real_T)c2_a->size[c2_i895];
      }

      for (c2_i897 = 0; c2_i897 < 3; c2_i897++) {
        c2_kernel[c2_i897] = -1.0 + (real_T)c2_i897;
      }

      for (c2_i899 = 0; c2_i899 < 2; c2_i899++) {
        c2_pad[c2_i899] = 3.0 + -2.0 * (real_T)c2_i899;
      }

      ippfilter_real32(&c2_a->data[0], &c2_varargin_1->data[0], c2_finalSize,
                       2.0, c2_padSize, c2_kernel, c2_pad, true);
    } else {
      for (c2_i894 = 0; c2_i894 < 2; c2_i894++) {
        c2_padSize[c2_i894] = (real_T)c2_a->size[c2_i894];
      }

      for (c2_i896 = 0; c2_i896 < 2; c2_i896++) {
        c2_nonZeroKernel[c2_i896] = -1.0 + 2.0 * (real_T)c2_i896;
      }

      for (c2_i898 = 0; c2_i898 < 2; c2_i898++) {
        c2_connDims[c2_i898] = 3.0 + -2.0 * (real_T)c2_i898;
      }

      imfilter_real32(&c2_a->data[0], &c2_varargin_1->data[0], 2.0, c2_finalSize,
                      2.0, c2_padSize, c2_nonZeroKernel, 2.0, c2_conn, 2.0,
                      c2_connDims, c2_pad, 2.0, true, true);
    }

    c2_emxFree_real32_T(chartInstance, &c2_a);
  }
}

static void c2_b_sqrt(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
                      c2_emxArray_real32_T *c2_x)
{
  boolean_T c2_p;
  real_T c2_d25;
  int32_T c2_k;
  int32_T c2_nx;
  boolean_T c2_b_p;
  int32_T c2_b_k;
  int32_T c2_b_x[1];
  c2_p = false;
  c2_d25 = (real_T)(c2_x->size[0] * c2_x->size[1]);
  for (c2_k = 0; c2_k < (int32_T)c2_d25; c2_k++) {
    if (c2_p || (c2_x->data[c2_k] < 0.0F)) {
      c2_b_p = true;
    } else {
      c2_b_p = false;
    }

    c2_p = c2_b_p;
  }

  if (c2_p) {
    c2_error(chartInstance);
  }

  c2_nx = c2_x->size[0] * c2_x->size[1];
  for (c2_b_k = 0; c2_b_k + 1 <= c2_nx; c2_b_k++) {
    c2_b_x[0] = c2_x->size[0] * c2_x->size[1];
    c2_x->data[c2_b_k] = muSingleScalarSqrt(c2_x->data[c2_b_k]);
  }
}

static void c2_b_bwmorph(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_boolean_T *c2_bwin)
{
  c2_emxArray_boolean_T *c2_last_aout;
  c2_emxArray_boolean_T *c2_m;
  c2_emxArray_boolean_T *c2_b_bwin;
  c2_emxArray_boolean_T *c2_c_bwin;
  c2_emxArray_boolean_T *c2_d_bwin;
  c2_emxArray_boolean_T *c2_e_bwin;
  c2_emxArray_boolean_T *c2_f_bwin;
  int32_T c2_i900;
  int32_T c2_b_last_aout;
  int32_T c2_c_last_aout;
  int32_T c2_loop_ub;
  int32_T c2_i901;
  int32_T c2_i902;
  int32_T c2_g_bwin;
  int32_T c2_h_bwin;
  int32_T c2_b_loop_ub;
  int32_T c2_i903;
  int32_T c2_i904;
  int32_T c2_b_m;
  int32_T c2_c_m;
  int32_T c2_d_m;
  int32_T c2_e_m;
  int32_T c2_c_loop_ub;
  int32_T c2_i905;
  int32_T c2_i906;
  int32_T c2_i907;
  int32_T c2_i_bwin[2];
  int32_T c2_f_m[2];
  int32_T c2_i908;
  int32_T c2_g_m;
  int32_T c2_h_m;
  int32_T c2_i_m;
  int32_T c2_j_m;
  int32_T c2_d_loop_ub;
  int32_T c2_i909;
  int32_T c2_i910;
  int32_T c2_tmp_size[1];
  int32_T c2_e_loop_ub;
  int32_T c2_i911;
  int32_T c2_i912;
  int32_T c2_tmp_data[513];
  int32_T c2_b_tmp_size[1];
  int32_T c2_f_loop_ub;
  int32_T c2_i913;
  int32_T c2_i914;
  int32_T c2_b_tmp_data[513];
  int32_T c2_i915;
  int32_T c2_iv178[2];
  int32_T c2_iv179[2];
  int32_T c2_i916;
  int32_T c2_i917;
  int32_T c2_g_loop_ub;
  int32_T c2_i918;
  int32_T c2_i919;
  int32_T c2_h_loop_ub;
  int32_T c2_i920;
  int32_T c2_j_bwin;
  int32_T c2_k_bwin;
  int32_T c2_i_loop_ub;
  int32_T c2_i921;
  int32_T c2_i922;
  int32_T c2_k_m;
  int32_T c2_l_m;
  int32_T c2_m_m;
  int32_T c2_n_m;
  int32_T c2_j_loop_ub;
  int32_T c2_i923;
  int32_T c2_i924;
  int32_T c2_i925;
  int32_T c2_l_bwin[2];
  int32_T c2_o_m[2];
  int32_T c2_i926;
  int32_T c2_p_m;
  int32_T c2_q_m;
  int32_T c2_r_m;
  int32_T c2_s_m;
  int32_T c2_k_loop_ub;
  int32_T c2_i927;
  int32_T c2_i928;
  int32_T c2_c_tmp_size[1];
  int32_T c2_l_loop_ub;
  int32_T c2_i929;
  int32_T c2_i930;
  int32_T c2_c_tmp_data[512];
  int32_T c2_d_tmp_size[1];
  int32_T c2_m_loop_ub;
  int32_T c2_i931;
  int32_T c2_i932;
  int32_T c2_d_tmp_data[512];
  int32_T c2_i933;
  int32_T c2_iv180[2];
  int32_T c2_iv181[2];
  int32_T c2_i934;
  int32_T c2_i935;
  int32_T c2_n_loop_ub;
  int32_T c2_i936;
  int32_T c2_i937;
  int32_T c2_o_loop_ub;
  int32_T c2_i938;
  int32_T c2_m_bwin;
  int32_T c2_n_bwin;
  int32_T c2_p_loop_ub;
  int32_T c2_i939;
  int32_T c2_i940;
  int32_T c2_t_m;
  int32_T c2_u_m;
  int32_T c2_v_m;
  int32_T c2_w_m;
  int32_T c2_q_loop_ub;
  int32_T c2_i941;
  int32_T c2_i942;
  int32_T c2_i943;
  int32_T c2_o_bwin[2];
  int32_T c2_x_m[2];
  int32_T c2_i944;
  int32_T c2_y_m;
  int32_T c2_ab_m;
  int32_T c2_bb_m;
  int32_T c2_cb_m;
  int32_T c2_r_loop_ub;
  int32_T c2_i945;
  int32_T c2_i946;
  int32_T c2_s_loop_ub;
  int32_T c2_i947;
  int32_T c2_i948;
  int32_T c2_t_loop_ub;
  int32_T c2_i949;
  int32_T c2_i950;
  int32_T c2_i951;
  int32_T c2_iv182[2];
  int32_T c2_iv183[2];
  int32_T c2_i952;
  int32_T c2_i953;
  int32_T c2_u_loop_ub;
  int32_T c2_i954;
  int32_T c2_i955;
  int32_T c2_v_loop_ub;
  int32_T c2_i956;
  int32_T c2_p_bwin;
  int32_T c2_q_bwin;
  int32_T c2_w_loop_ub;
  int32_T c2_i957;
  int32_T c2_i958;
  int32_T c2_db_m;
  int32_T c2_eb_m;
  int32_T c2_fb_m;
  int32_T c2_gb_m;
  int32_T c2_x_loop_ub;
  int32_T c2_i959;
  int32_T c2_i960;
  int32_T c2_i961;
  int32_T c2_r_bwin[2];
  int32_T c2_hb_m[2];
  int32_T c2_i962;
  int32_T c2_ib_m;
  int32_T c2_jb_m;
  int32_T c2_kb_m;
  int32_T c2_lb_m;
  int32_T c2_y_loop_ub;
  int32_T c2_i963;
  int32_T c2_i964;
  int32_T c2_ab_loop_ub;
  int32_T c2_i965;
  int32_T c2_i966;
  int32_T c2_bb_loop_ub;
  int32_T c2_i967;
  int32_T c2_i968;
  int32_T c2_i969;
  int32_T c2_iv184[2];
  int32_T c2_iv185[2];
  int32_T c2_i970;
  int32_T c2_i971;
  int32_T c2_cb_loop_ub;
  int32_T c2_i972;
  int32_T c2_i973;
  int32_T c2_db_loop_ub;
  int32_T c2_i974;
  int32_T c2_s_bwin;
  int32_T c2_t_bwin;
  int32_T c2_eb_loop_ub;
  int32_T c2_i975;
  c2_emxInit_boolean_T(chartInstance, &c2_last_aout, 2, &c2_xi_emlrtRTEI);
  c2_emxInit_boolean_T(chartInstance, &c2_m, 2, &c2_uj_emlrtRTEI);
  c2_emxInit_boolean_T(chartInstance, &c2_b_bwin, 2, &c2_tj_emlrtRTEI);
  c2_emxInit_boolean_T(chartInstance, &c2_c_bwin, 2, &c2_oj_emlrtRTEI);
  c2_emxInit_boolean_T(chartInstance, &c2_d_bwin, 2, &c2_jj_emlrtRTEI);
  c2_emxInit_boolean_T(chartInstance, &c2_e_bwin, 2, &c2_ej_emlrtRTEI);
  c2_emxInit_boolean_T(chartInstance, &c2_f_bwin, 2, &c2_yi_emlrtRTEI);
  do {
    c2_i900 = c2_last_aout->size[0] * c2_last_aout->size[1];
    c2_last_aout->size[0] = c2_bwin->size[0];
    c2_last_aout->size[1] = c2_bwin->size[1];
    c2_emxEnsureCapacity_boolean_T(chartInstance, c2_last_aout, c2_i900,
      &c2_xi_emlrtRTEI);
    c2_b_last_aout = c2_last_aout->size[0];
    c2_c_last_aout = c2_last_aout->size[1];
    c2_loop_ub = c2_bwin->size[0] * c2_bwin->size[1] - 1;
    for (c2_i901 = 0; c2_i901 <= c2_loop_ub; c2_i901++) {
      c2_last_aout->data[c2_i901] = c2_bwin->data[c2_i901];
    }

    c2_i902 = c2_f_bwin->size[0] * c2_f_bwin->size[1];
    c2_f_bwin->size[0] = c2_bwin->size[0];
    c2_f_bwin->size[1] = c2_bwin->size[1];
    c2_emxEnsureCapacity_boolean_T(chartInstance, c2_f_bwin, c2_i902,
      &c2_yi_emlrtRTEI);
    c2_g_bwin = c2_f_bwin->size[0];
    c2_h_bwin = c2_f_bwin->size[1];
    c2_b_loop_ub = c2_bwin->size[0] * c2_bwin->size[1] - 1;
    for (c2_i903 = 0; c2_i903 <= c2_b_loop_ub; c2_i903++) {
      c2_f_bwin->data[c2_i903] = c2_bwin->data[c2_i903];
    }

    c2_bwlookup(chartInstance, c2_f_bwin, c2_m);
    c2_i904 = c2_m->size[0] * c2_m->size[1];
    c2_m->size[0];
    c2_m->size[1];
    c2_emxEnsureCapacity_boolean_T(chartInstance, c2_m, c2_i904,
      &c2_aj_emlrtRTEI);
    c2_b_m = c2_m->size[0];
    c2_c_m = c2_m->size[1];
    c2_d_m = c2_m->size[0];
    c2_e_m = c2_m->size[1];
    c2_c_loop_ub = c2_b_m * c2_c_m - 1;
    for (c2_i905 = 0; c2_i905 <= c2_c_loop_ub; c2_i905++) {
      c2_m->data[c2_i905] = !c2_m->data[c2_i905];
    }

    for (c2_i906 = 0; c2_i906 < 2; c2_i906++) {
      c2_i_bwin[c2_i906] = c2_bwin->size[c2_i906];
    }

    for (c2_i907 = 0; c2_i907 < 2; c2_i907++) {
      c2_f_m[c2_i907] = c2_m->size[c2_i907];
    }

    _SFD_SIZE_EQ_CHECK_ND(c2_i_bwin, c2_f_m, 2);
    c2_i908 = c2_m->size[0] * c2_m->size[1];
    c2_m->size[0] = c2_bwin->size[0];
    c2_m->size[1] = c2_bwin->size[1];
    c2_emxEnsureCapacity_boolean_T(chartInstance, c2_m, c2_i908,
      &c2_bj_emlrtRTEI);
    c2_g_m = c2_m->size[0];
    c2_h_m = c2_m->size[1];
    c2_i_m = c2_m->size[0];
    c2_j_m = c2_m->size[1];
    c2_d_loop_ub = c2_bwin->size[0] * c2_bwin->size[1] - 1;
    for (c2_i909 = 0; c2_i909 <= c2_d_loop_ub; c2_i909++) {
      c2_m->data[c2_i909] = (c2_bwin->data[c2_i909] && c2_m->data[c2_i909]);
    }

    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_m->size[0], 1, c2_m->size[0]);
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_m->size[1], 1, c2_m->size[1]);
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_bwin->size[0], 1,
      c2_bwin->size[0]);
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_bwin->size[1], 1,
      c2_bwin->size[1]);
    c2_i910 = c2_bwin->size[0];
    c2_tmp_size[0] = ((c2_i910 - 1) >> 1) + 1;
    c2_e_loop_ub = (c2_i910 - 1) >> 1;
    for (c2_i911 = 0; c2_i911 <= c2_e_loop_ub; c2_i911++) {
      c2_tmp_data[c2_i911] = c2_i911 << 1;
    }

    c2_i912 = c2_bwin->size[1];
    c2_b_tmp_size[0] = ((c2_i912 - 1) >> 1) + 1;
    c2_f_loop_ub = (c2_i912 - 1) >> 1;
    for (c2_i913 = 0; c2_i913 <= c2_f_loop_ub; c2_i913++) {
      c2_b_tmp_data[c2_i913] = c2_i913 << 1;
    }

    c2_i914 = c2_m->size[0];
    c2_i915 = c2_m->size[1];
    c2_iv178[0] = c2_tmp_size[0];
    c2_iv178[1] = c2_b_tmp_size[0];
    c2_iv179[0] = ((c2_i914 - 1) >> 1) + 1;
    c2_iv179[1] = ((c2_i915 - 1) >> 1) + 1;
    _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c2_iv178, 2, c2_iv179, 2);
    c2_i916 = c2_m->size[0];
    c2_i917 = c2_m->size[1];
    c2_g_loop_ub = (c2_i917 - 1) >> 1;
    for (c2_i918 = 0; c2_i918 <= c2_g_loop_ub; c2_i918++) {
      c2_h_loop_ub = (c2_i916 - 1) >> 1;
      for (c2_i920 = 0; c2_i920 <= c2_h_loop_ub; c2_i920++) {
        c2_bwin->data[c2_tmp_data[c2_i920] + c2_bwin->size[0] *
          c2_b_tmp_data[c2_i918]] = c2_m->data[(c2_i920 << 1) + c2_m->size[0] *
          (c2_i918 << 1)];
      }
    }

    c2_i919 = c2_e_bwin->size[0] * c2_e_bwin->size[1];
    c2_e_bwin->size[0] = c2_bwin->size[0];
    c2_e_bwin->size[1] = c2_bwin->size[1];
    c2_emxEnsureCapacity_boolean_T(chartInstance, c2_e_bwin, c2_i919,
      &c2_ej_emlrtRTEI);
    c2_j_bwin = c2_e_bwin->size[0];
    c2_k_bwin = c2_e_bwin->size[1];
    c2_i_loop_ub = c2_bwin->size[0] * c2_bwin->size[1] - 1;
    for (c2_i921 = 0; c2_i921 <= c2_i_loop_ub; c2_i921++) {
      c2_e_bwin->data[c2_i921] = c2_bwin->data[c2_i921];
    }

    c2_bwlookup(chartInstance, c2_e_bwin, c2_m);
    c2_i922 = c2_m->size[0] * c2_m->size[1];
    c2_m->size[0];
    c2_m->size[1];
    c2_emxEnsureCapacity_boolean_T(chartInstance, c2_m, c2_i922,
      &c2_fj_emlrtRTEI);
    c2_k_m = c2_m->size[0];
    c2_l_m = c2_m->size[1];
    c2_m_m = c2_m->size[0];
    c2_n_m = c2_m->size[1];
    c2_j_loop_ub = c2_k_m * c2_l_m - 1;
    for (c2_i923 = 0; c2_i923 <= c2_j_loop_ub; c2_i923++) {
      c2_m->data[c2_i923] = !c2_m->data[c2_i923];
    }

    for (c2_i924 = 0; c2_i924 < 2; c2_i924++) {
      c2_l_bwin[c2_i924] = c2_bwin->size[c2_i924];
    }

    for (c2_i925 = 0; c2_i925 < 2; c2_i925++) {
      c2_o_m[c2_i925] = c2_m->size[c2_i925];
    }

    _SFD_SIZE_EQ_CHECK_ND(c2_l_bwin, c2_o_m, 2);
    c2_i926 = c2_m->size[0] * c2_m->size[1];
    c2_m->size[0] = c2_bwin->size[0];
    c2_m->size[1] = c2_bwin->size[1];
    c2_emxEnsureCapacity_boolean_T(chartInstance, c2_m, c2_i926,
      &c2_gj_emlrtRTEI);
    c2_p_m = c2_m->size[0];
    c2_q_m = c2_m->size[1];
    c2_r_m = c2_m->size[0];
    c2_s_m = c2_m->size[1];
    c2_k_loop_ub = c2_bwin->size[0] * c2_bwin->size[1] - 1;
    for (c2_i927 = 0; c2_i927 <= c2_k_loop_ub; c2_i927++) {
      c2_m->data[c2_i927] = (c2_bwin->data[c2_i927] && c2_m->data[c2_i927]);
    }

    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_m->size[0], 1, c2_m->size[0]);
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_m->size[1], 1, c2_m->size[1]);
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_bwin->size[0], 1,
      c2_bwin->size[0]);
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_bwin->size[1], 1,
      c2_bwin->size[1]);
    c2_i928 = c2_bwin->size[0];
    c2_c_tmp_size[0] = ((c2_i928 - 2) >> 1) + 1;
    c2_l_loop_ub = (c2_i928 - 2) >> 1;
    for (c2_i929 = 0; c2_i929 <= c2_l_loop_ub; c2_i929++) {
      c2_c_tmp_data[c2_i929] = (c2_i929 << 1) + 1;
    }

    c2_i930 = c2_bwin->size[1];
    c2_d_tmp_size[0] = ((c2_i930 - 2) >> 1) + 1;
    c2_m_loop_ub = (c2_i930 - 2) >> 1;
    for (c2_i931 = 0; c2_i931 <= c2_m_loop_ub; c2_i931++) {
      c2_d_tmp_data[c2_i931] = (c2_i931 << 1) + 1;
    }

    c2_i932 = c2_m->size[0];
    c2_i933 = c2_m->size[1];
    c2_iv180[0] = c2_c_tmp_size[0];
    c2_iv180[1] = c2_d_tmp_size[0];
    c2_iv181[0] = ((c2_i932 - 2) >> 1) + 1;
    c2_iv181[1] = ((c2_i933 - 2) >> 1) + 1;
    _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c2_iv180, 2, c2_iv181, 2);
    c2_i934 = c2_m->size[0];
    c2_i935 = c2_m->size[1];
    c2_n_loop_ub = (c2_i935 - 2) >> 1;
    for (c2_i936 = 0; c2_i936 <= c2_n_loop_ub; c2_i936++) {
      c2_o_loop_ub = (c2_i934 - 2) >> 1;
      for (c2_i938 = 0; c2_i938 <= c2_o_loop_ub; c2_i938++) {
        c2_bwin->data[c2_c_tmp_data[c2_i938] + c2_bwin->size[0] *
          c2_d_tmp_data[c2_i936]] = c2_m->data[((c2_i938 << 1) + c2_m->size[0] *
          ((c2_i936 << 1) + 1)) + 1];
      }
    }

    c2_i937 = c2_d_bwin->size[0] * c2_d_bwin->size[1];
    c2_d_bwin->size[0] = c2_bwin->size[0];
    c2_d_bwin->size[1] = c2_bwin->size[1];
    c2_emxEnsureCapacity_boolean_T(chartInstance, c2_d_bwin, c2_i937,
      &c2_jj_emlrtRTEI);
    c2_m_bwin = c2_d_bwin->size[0];
    c2_n_bwin = c2_d_bwin->size[1];
    c2_p_loop_ub = c2_bwin->size[0] * c2_bwin->size[1] - 1;
    for (c2_i939 = 0; c2_i939 <= c2_p_loop_ub; c2_i939++) {
      c2_d_bwin->data[c2_i939] = c2_bwin->data[c2_i939];
    }

    c2_bwlookup(chartInstance, c2_d_bwin, c2_m);
    c2_i940 = c2_m->size[0] * c2_m->size[1];
    c2_m->size[0];
    c2_m->size[1];
    c2_emxEnsureCapacity_boolean_T(chartInstance, c2_m, c2_i940,
      &c2_kj_emlrtRTEI);
    c2_t_m = c2_m->size[0];
    c2_u_m = c2_m->size[1];
    c2_v_m = c2_m->size[0];
    c2_w_m = c2_m->size[1];
    c2_q_loop_ub = c2_t_m * c2_u_m - 1;
    for (c2_i941 = 0; c2_i941 <= c2_q_loop_ub; c2_i941++) {
      c2_m->data[c2_i941] = !c2_m->data[c2_i941];
    }

    for (c2_i942 = 0; c2_i942 < 2; c2_i942++) {
      c2_o_bwin[c2_i942] = c2_bwin->size[c2_i942];
    }

    for (c2_i943 = 0; c2_i943 < 2; c2_i943++) {
      c2_x_m[c2_i943] = c2_m->size[c2_i943];
    }

    _SFD_SIZE_EQ_CHECK_ND(c2_o_bwin, c2_x_m, 2);
    c2_i944 = c2_m->size[0] * c2_m->size[1];
    c2_m->size[0] = c2_bwin->size[0];
    c2_m->size[1] = c2_bwin->size[1];
    c2_emxEnsureCapacity_boolean_T(chartInstance, c2_m, c2_i944,
      &c2_lj_emlrtRTEI);
    c2_y_m = c2_m->size[0];
    c2_ab_m = c2_m->size[1];
    c2_bb_m = c2_m->size[0];
    c2_cb_m = c2_m->size[1];
    c2_r_loop_ub = c2_bwin->size[0] * c2_bwin->size[1] - 1;
    for (c2_i945 = 0; c2_i945 <= c2_r_loop_ub; c2_i945++) {
      c2_m->data[c2_i945] = (c2_bwin->data[c2_i945] && c2_m->data[c2_i945]);
    }

    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_m->size[0], 1, c2_m->size[0]);
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_m->size[1], 1, c2_m->size[1]);
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_bwin->size[0], 1,
      c2_bwin->size[0]);
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_bwin->size[1], 1,
      c2_bwin->size[1]);
    c2_i946 = c2_bwin->size[0];
    c2_tmp_size[0] = ((c2_i946 - 1) >> 1) + 1;
    c2_s_loop_ub = (c2_i946 - 1) >> 1;
    for (c2_i947 = 0; c2_i947 <= c2_s_loop_ub; c2_i947++) {
      c2_tmp_data[c2_i947] = c2_i947 << 1;
    }

    c2_i948 = c2_bwin->size[1];
    c2_c_tmp_size[0] = ((c2_i948 - 2) >> 1) + 1;
    c2_t_loop_ub = (c2_i948 - 2) >> 1;
    for (c2_i949 = 0; c2_i949 <= c2_t_loop_ub; c2_i949++) {
      c2_c_tmp_data[c2_i949] = (c2_i949 << 1) + 1;
    }

    c2_i950 = c2_m->size[0];
    c2_i951 = c2_m->size[1];
    c2_iv182[0] = c2_tmp_size[0];
    c2_iv182[1] = c2_c_tmp_size[0];
    c2_iv183[0] = ((c2_i950 - 1) >> 1) + 1;
    c2_iv183[1] = ((c2_i951 - 2) >> 1) + 1;
    _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c2_iv182, 2, c2_iv183, 2);
    c2_i952 = c2_m->size[0];
    c2_i953 = c2_m->size[1];
    c2_u_loop_ub = (c2_i953 - 2) >> 1;
    for (c2_i954 = 0; c2_i954 <= c2_u_loop_ub; c2_i954++) {
      c2_v_loop_ub = (c2_i952 - 1) >> 1;
      for (c2_i956 = 0; c2_i956 <= c2_v_loop_ub; c2_i956++) {
        c2_bwin->data[c2_tmp_data[c2_i956] + c2_bwin->size[0] *
          c2_c_tmp_data[c2_i954]] = c2_m->data[(c2_i956 << 1) + c2_m->size[0] *
          ((c2_i954 << 1) + 1)];
      }
    }

    c2_i955 = c2_c_bwin->size[0] * c2_c_bwin->size[1];
    c2_c_bwin->size[0] = c2_bwin->size[0];
    c2_c_bwin->size[1] = c2_bwin->size[1];
    c2_emxEnsureCapacity_boolean_T(chartInstance, c2_c_bwin, c2_i955,
      &c2_oj_emlrtRTEI);
    c2_p_bwin = c2_c_bwin->size[0];
    c2_q_bwin = c2_c_bwin->size[1];
    c2_w_loop_ub = c2_bwin->size[0] * c2_bwin->size[1] - 1;
    for (c2_i957 = 0; c2_i957 <= c2_w_loop_ub; c2_i957++) {
      c2_c_bwin->data[c2_i957] = c2_bwin->data[c2_i957];
    }

    c2_bwlookup(chartInstance, c2_c_bwin, c2_m);
    c2_i958 = c2_m->size[0] * c2_m->size[1];
    c2_m->size[0];
    c2_m->size[1];
    c2_emxEnsureCapacity_boolean_T(chartInstance, c2_m, c2_i958,
      &c2_pj_emlrtRTEI);
    c2_db_m = c2_m->size[0];
    c2_eb_m = c2_m->size[1];
    c2_fb_m = c2_m->size[0];
    c2_gb_m = c2_m->size[1];
    c2_x_loop_ub = c2_db_m * c2_eb_m - 1;
    for (c2_i959 = 0; c2_i959 <= c2_x_loop_ub; c2_i959++) {
      c2_m->data[c2_i959] = !c2_m->data[c2_i959];
    }

    for (c2_i960 = 0; c2_i960 < 2; c2_i960++) {
      c2_r_bwin[c2_i960] = c2_bwin->size[c2_i960];
    }

    for (c2_i961 = 0; c2_i961 < 2; c2_i961++) {
      c2_hb_m[c2_i961] = c2_m->size[c2_i961];
    }

    _SFD_SIZE_EQ_CHECK_ND(c2_r_bwin, c2_hb_m, 2);
    c2_i962 = c2_m->size[0] * c2_m->size[1];
    c2_m->size[0] = c2_bwin->size[0];
    c2_m->size[1] = c2_bwin->size[1];
    c2_emxEnsureCapacity_boolean_T(chartInstance, c2_m, c2_i962,
      &c2_qj_emlrtRTEI);
    c2_ib_m = c2_m->size[0];
    c2_jb_m = c2_m->size[1];
    c2_kb_m = c2_m->size[0];
    c2_lb_m = c2_m->size[1];
    c2_y_loop_ub = c2_bwin->size[0] * c2_bwin->size[1] - 1;
    for (c2_i963 = 0; c2_i963 <= c2_y_loop_ub; c2_i963++) {
      c2_m->data[c2_i963] = (c2_bwin->data[c2_i963] && c2_m->data[c2_i963]);
    }

    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_m->size[0], 1, c2_m->size[0]);
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_m->size[1], 1, c2_m->size[1]);
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_bwin->size[0], 1,
      c2_bwin->size[0]);
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_bwin->size[1], 1,
      c2_bwin->size[1]);
    c2_i964 = c2_bwin->size[0];
    c2_c_tmp_size[0] = ((c2_i964 - 2) >> 1) + 1;
    c2_ab_loop_ub = (c2_i964 - 2) >> 1;
    for (c2_i965 = 0; c2_i965 <= c2_ab_loop_ub; c2_i965++) {
      c2_c_tmp_data[c2_i965] = (c2_i965 << 1) + 1;
    }

    c2_i966 = c2_bwin->size[1];
    c2_tmp_size[0] = ((c2_i966 - 1) >> 1) + 1;
    c2_bb_loop_ub = (c2_i966 - 1) >> 1;
    for (c2_i967 = 0; c2_i967 <= c2_bb_loop_ub; c2_i967++) {
      c2_tmp_data[c2_i967] = c2_i967 << 1;
    }

    c2_i968 = c2_m->size[0];
    c2_i969 = c2_m->size[1];
    c2_iv184[0] = c2_c_tmp_size[0];
    c2_iv184[1] = c2_tmp_size[0];
    c2_iv185[0] = ((c2_i968 - 2) >> 1) + 1;
    c2_iv185[1] = ((c2_i969 - 1) >> 1) + 1;
    _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c2_iv184, 2, c2_iv185, 2);
    c2_i970 = c2_m->size[0];
    c2_i971 = c2_m->size[1];
    c2_cb_loop_ub = (c2_i971 - 1) >> 1;
    for (c2_i972 = 0; c2_i972 <= c2_cb_loop_ub; c2_i972++) {
      c2_db_loop_ub = (c2_i970 - 2) >> 1;
      for (c2_i974 = 0; c2_i974 <= c2_db_loop_ub; c2_i974++) {
        c2_bwin->data[c2_c_tmp_data[c2_i974] + c2_bwin->size[0] *
          c2_tmp_data[c2_i972]] = c2_m->data[((c2_i974 << 1) + c2_m->size[0] *
          (c2_i972 << 1)) + 1];
      }
    }

    c2_i973 = c2_b_bwin->size[0] * c2_b_bwin->size[1];
    c2_b_bwin->size[0] = c2_bwin->size[0];
    c2_b_bwin->size[1] = c2_bwin->size[1];
    c2_emxEnsureCapacity_boolean_T(chartInstance, c2_b_bwin, c2_i973,
      &c2_tj_emlrtRTEI);
    c2_s_bwin = c2_b_bwin->size[0];
    c2_t_bwin = c2_b_bwin->size[1];
    c2_eb_loop_ub = c2_bwin->size[0] * c2_bwin->size[1] - 1;
    for (c2_i975 = 0; c2_i975 <= c2_eb_loop_ub; c2_i975++) {
      c2_b_bwin->data[c2_i975] = c2_bwin->data[c2_i975];
    }
  } while (!c2_isequal(chartInstance, c2_last_aout, c2_b_bwin));

  c2_emxFree_boolean_T(chartInstance, &c2_f_bwin);
  c2_emxFree_boolean_T(chartInstance, &c2_e_bwin);
  c2_emxFree_boolean_T(chartInstance, &c2_d_bwin);
  c2_emxFree_boolean_T(chartInstance, &c2_c_bwin);
  c2_emxFree_boolean_T(chartInstance, &c2_b_bwin);
  c2_emxFree_boolean_T(chartInstance, &c2_m);
  c2_emxFree_boolean_T(chartInstance, &c2_last_aout);
}

static void c2_b_subPixelLocation(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_metric, c2_emxArray_real32_T *c2_loc)
{
  c2_emxArray_real32_T *c2_x;
  int32_T c2_i976;
  int32_T c2_loop_ub;
  int32_T c2_i977;
  int32_T c2_nx;
  int32_T c2_i978;
  int32_T c2_calclen;
  const mxArray *c2_y = NULL;
  int32_T c2_i979;
  real_T c2_mtmp;
  real_T c2_b_x[2];
  int32_T c2_maxdimlen;
  const mxArray *c2_b_y = NULL;
  static char_T c2_cv51[40] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'g', 'e', 't', 'R', 'e', 's', 'h', 'a', 'p', 'e', 'D', 'i',
    'm', 's', '_', 'n', 'o', 't', 'S', 'a', 'm', 'e', 'N', 'u', 'm', 'e', 'l' };

  c2_emxArray_real32_T *c2_b_metric;
  int32_T c2_i980;
  int32_T c2_c_metric;
  int32_T c2_d_metric;
  int32_T c2_b_loop_ub;
  int32_T c2_i981;
  c2_emxArray_real32_T *c2_b_loc;
  int32_T c2_iv186[3];
  c2_emxArray_real32_T c2_c_x;
  int32_T c2_k;
  int32_T c2_i982;
  int32_T c2_i983;
  int32_T c2_sqsz[3];
  int32_T c2_i984;
  int32_T c2_i985;
  int32_T c2_b_k;
  int32_T c2_i986;
  int32_T c2_c_k;
  int32_T c2_i987;
  int32_T c2_i988;
  int32_T c2_c_loop_ub;
  int32_T c2_i989;
  c2_emxInit_real32_T(chartInstance, &c2_x, 2, &c2_vj_emlrtRTEI);
  c2_i976 = c2_x->size[0] * c2_x->size[1];
  c2_x->size[0] = 2;
  c2_x->size[1] = c2_loc->size[0];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_x, c2_i976, &c2_vj_emlrtRTEI);
  c2_loop_ub = c2_loc->size[0] - 1;
  for (c2_i977 = 0; c2_i977 <= c2_loop_ub; c2_i977++) {
    for (c2_i978 = 0; c2_i978 < 2; c2_i978++) {
      c2_x->data[c2_i978 + c2_x->size[0] * c2_i977] = c2_loc->data[c2_i977 +
        c2_loc->size[0] * c2_i978];
    }
  }

  c2_nx = c2_x->size[1] << 1;
  c2_calclen = c2_div_nzp_s32(chartInstance, c2_nx, 2, 1U, 0U, 0U);
  if (c2_calclen <= c2_nx) {
  } else {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_y));
  }

  for (c2_i979 = 0; c2_i979 < 2; c2_i979++) {
    c2_b_x[c2_i979] = (real_T)c2_x->size[c2_i979];
  }

  c2_mtmp = c2_b_x[0];
  if (c2_b_x[1] > c2_b_x[0]) {
    c2_mtmp = c2_b_x[1];
  }

  if ((real_T)c2_nx > c2_mtmp) {
    c2_maxdimlen = c2_nx;
  } else {
    c2_maxdimlen = (int32_T)c2_mtmp;
  }

  if (2 > c2_maxdimlen) {
    c2_c_error(chartInstance);
  }

  if (c2_calclen > c2_maxdimlen) {
    c2_c_error(chartInstance);
  }

  if (c2_calclen << 1 == c2_nx) {
  } else {
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv51, 10, 0U, 1U, 0U, 2, 1, 40),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_b_y));
  }

  c2_emxInit_real32_T(chartInstance, &c2_b_metric, 2, &c2_wj_emlrtRTEI);
  c2_i980 = c2_b_metric->size[0] * c2_b_metric->size[1];
  c2_b_metric->size[0] = c2_metric->size[0];
  c2_b_metric->size[1] = c2_metric->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_b_metric, c2_i980,
    &c2_wj_emlrtRTEI);
  c2_c_metric = c2_b_metric->size[0];
  c2_d_metric = c2_b_metric->size[1];
  c2_b_loop_ub = c2_metric->size[0] * c2_metric->size[1] - 1;
  for (c2_i981 = 0; c2_i981 <= c2_b_loop_ub; c2_i981++) {
    c2_b_metric->data[c2_i981] = c2_metric->data[c2_i981];
  }

  c2_emxInit_real32_T2(chartInstance, &c2_b_loc, 3, &c2_ak_emlrtRTEI);
  c2_iv186[0] = 2;
  c2_iv186[1] = 1;
  c2_iv186[2] = c2_calclen;
  c2_c_x = *c2_x;
  c2_c_x.size = (int32_T *)&c2_iv186;
  c2_c_x.numDimensions = 1;
  c2_subPixelLocationImpl(chartInstance, c2_b_metric, &c2_c_x, c2_b_loc);
  c2_k = 3;
  c2_emxFree_real32_T(chartInstance, &c2_b_metric);
  while ((c2_k > 2) && (c2_b_loc->size[2] == 1)) {
    c2_k = 2;
  }

  if ((real_T)c2_k <= 2.0) {
    c2_i983 = c2_x->size[0] * c2_x->size[1];
    c2_x->size[0] = 2;
    c2_x->size[1] = 1;
    c2_emxEnsureCapacity_real32_T(chartInstance, c2_x, c2_i983, &c2_xj_emlrtRTEI);
    c2_i984 = c2_b_loc->size[2] << 1;
    for (c2_b_k = 0; c2_b_k + 1 <= c2_i984; c2_b_k++) {
      c2_x->data[c2_b_k] = c2_b_loc->data[c2_b_k];
    }
  } else {
    for (c2_i982 = 0; c2_i982 < 3; c2_i982++) {
      c2_sqsz[c2_i982] = 1;
    }

    if ((real_T)c2_b_loc->size[2] != 1.0) {
      c2_sqsz[1] = c2_b_loc->size[2];
    }

    c2_i985 = c2_x->size[0] * c2_x->size[1];
    c2_x->size[0] = 2;
    c2_x->size[1] = c2_sqsz[1];
    c2_emxEnsureCapacity_real32_T(chartInstance, c2_x, c2_i985, &c2_xj_emlrtRTEI);
    c2_i986 = c2_b_loc->size[2] << 1;
    for (c2_c_k = 0; c2_c_k + 1 <= c2_i986; c2_c_k++) {
      c2_x->data[c2_c_k] = c2_b_loc->data[c2_c_k];
    }
  }

  c2_emxFree_real32_T(chartInstance, &c2_b_loc);
  c2_i987 = c2_loc->size[0] * c2_loc->size[1];
  c2_loc->size[0] = c2_x->size[1];
  c2_loc->size[1] = 2;
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_loc, c2_i987, &c2_yj_emlrtRTEI);
  for (c2_i988 = 0; c2_i988 < 2; c2_i988++) {
    c2_c_loop_ub = c2_x->size[1] - 1;
    for (c2_i989 = 0; c2_i989 <= c2_c_loop_ub; c2_i989++) {
      c2_loc->data[c2_i989 + c2_loc->size[0] * c2_i988] = c2_x->data[c2_i988 +
        c2_x->size[0] * c2_i989];
    }
  }

  c2_emxFree_real32_T(chartInstance, &c2_x);
}

static void c2_b_floor(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  c2_emxArray_real32_T *c2_x)
{
  int32_T c2_nx;
  int32_T c2_k;
  (void)chartInstance;
  c2_nx = c2_x->size[0];
  for (c2_k = 0; c2_k + 1 <= c2_nx; c2_k++) {
    c2_x->data[c2_k] = muSingleScalarFloor(c2_x->data[c2_k]);
  }
}

static void c2_b_FeaturePointsImpl_FeaturePointsImpl
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
   c2_vision_internal_cornerPoints_cg *c2_this, c2_emxArray_real32_T
   *c2_varargin_1, c2_emxArray_real32_T *c2_varargin_3)
{
  c2_sjeQsvJNEhdsHQhIigwA2FF c2_inputs;
  int32_T c2_i990;
  int32_T c2_b_inputs;
  int32_T c2_c_inputs;
  int32_T c2_loop_ub;
  int32_T c2_i991;
  int32_T c2_i992;
  int32_T c2_b_loop_ub;
  int32_T c2_i993;
  int32_T c2_i994;
  int32_T c2_b_this;
  int32_T c2_c_this;
  int32_T c2_c_loop_ub;
  int32_T c2_i995;
  int32_T c2_i996;
  c2_emxArray_real32_T *c2_r23;
  int32_T c2_i997;
  int32_T c2_varargin_3_size[1];
  real32_T c2_varargin_3_data[1];
  int32_T c2_d_loop_ub;
  int32_T c2_i998;
  int32_T c2_i999;
  int32_T c2_e_loop_ub;
  int32_T c2_i1000;
  c2_emxInitStruct_sjeQsvJNEhdsHQhIi(chartInstance, &c2_inputs, &c2_ck_emlrtRTEI);
  c2_i990 = c2_inputs.Location->size[0] * c2_inputs.Location->size[1];
  c2_inputs.Location->size[0] = c2_varargin_1->size[0];
  c2_inputs.Location->size[1] = 2;
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_inputs.Location, c2_i990,
    &c2_bk_emlrtRTEI);
  c2_b_inputs = c2_inputs.Location->size[0];
  c2_c_inputs = c2_inputs.Location->size[1];
  c2_loop_ub = c2_varargin_1->size[0] * c2_varargin_1->size[1] - 1;
  for (c2_i991 = 0; c2_i991 <= c2_loop_ub; c2_i991++) {
    c2_inputs.Location->data[c2_i991] = c2_varargin_1->data[c2_i991];
  }

  c2_i992 = c2_inputs.Metric->size[0];
  c2_inputs.Metric->size[0] = c2_varargin_3->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_inputs.Metric, c2_i992,
    &c2_ck_emlrtRTEI);
  c2_b_loop_ub = c2_varargin_3->size[0] - 1;
  for (c2_i993 = 0; c2_i993 <= c2_b_loop_ub; c2_i993++) {
    c2_inputs.Metric->data[c2_i993] = c2_varargin_3->data[c2_i993];
  }

  c2_FeaturePointsImpl_validate(chartInstance, c2_inputs);
  c2_i994 = c2_this->pLocation->size[0] * c2_this->pLocation->size[1];
  c2_this->pLocation->size[0] = c2_varargin_1->size[0];
  c2_this->pLocation->size[1] = 2;
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_this->pLocation, c2_i994,
    &c2_dk_emlrtRTEI);
  c2_b_this = c2_this->pLocation->size[0];
  c2_c_this = c2_this->pLocation->size[1];
  c2_c_loop_ub = c2_varargin_1->size[0] * c2_varargin_1->size[1] - 1;
  c2_emxFreeStruct_sjeQsvJNEhdsHQhIi(chartInstance, &c2_inputs);
  for (c2_i995 = 0; c2_i995 <= c2_c_loop_ub; c2_i995++) {
    c2_this->pLocation->data[c2_i995] = c2_varargin_1->data[c2_i995];
  }

  c2_i996 = c2_this->pMetric->size[0];
  c2_this->pMetric->size[0] = c2_varargin_1->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_this->pMetric, c2_i996,
    &c2_ek_emlrtRTEI);
  c2_emxInit_real32_T1(chartInstance, &c2_r23, 1, &c2_si_emlrtRTEI);
  if (c2_varargin_3->size[0] == 1) {
    c2_varargin_3_size[0] = 1;
    c2_varargin_3_data[0] = c2_varargin_3->data[0];
    c2_b_repmat(chartInstance, c2_varargin_3_data, c2_varargin_3_size, (real_T)
                c2_varargin_1->size[0], c2_r23);
  } else {
    c2_i997 = c2_r23->size[0];
    c2_r23->size[0] = c2_varargin_3->size[0];
    c2_emxEnsureCapacity_real32_T1(chartInstance, c2_r23, c2_i997,
      &c2_fk_emlrtRTEI);
    c2_d_loop_ub = c2_varargin_3->size[0] - 1;
    for (c2_i998 = 0; c2_i998 <= c2_d_loop_ub; c2_i998++) {
      c2_r23->data[c2_i998] = c2_varargin_3->data[c2_i998];
    }
  }

  _SFD_SUB_ASSIGN_SIZE_CHECK_1D(c2_this->pMetric->size[0], c2_r23->size[0]);
  c2_i999 = c2_this->pMetric->size[0];
  c2_this->pMetric->size[0] = c2_r23->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_this->pMetric, c2_i999,
    &c2_hk_emlrtRTEI);
  c2_e_loop_ub = c2_r23->size[0] - 1;
  for (c2_i1000 = 0; c2_i1000 <= c2_e_loop_ub; c2_i1000++) {
    c2_this->pMetric->data[c2_i1000] = c2_r23->data[c2_i1000];
  }

  c2_emxFree_real32_T(chartInstance, &c2_r23);
}

static void c2_emxEnsureCapacity_real_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(real_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, (void *)c2_emxArray->data, sizeof(real_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex((void *)c2_emxArray->data);
      }
    }

    c2_emxArray->data = (real_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxEnsureCapacity_uint8_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_uint8_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(uint8_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, (void *)c2_emxArray->data, sizeof(uint8_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex((void *)c2_emxArray->data);
      }
    }

    c2_emxArray->data = (uint8_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxEnsureCapacity_int32_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_int32_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(int32_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, (void *)c2_emxArray->data, sizeof(int32_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex((void *)c2_emxArray->data);
      }
    }

    c2_emxArray->data = (int32_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxEnsureCapacity_int32_T1(SFc2_DetectAndTrackFaceInstanceStruct *
  chartInstance, c2_emxArray_int32_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(int32_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, (void *)c2_emxArray->data, sizeof(int32_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex((void *)c2_emxArray->data);
      }
    }

    c2_emxArray->data = (int32_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxEnsureCapacity_real32_T(SFc2_DetectAndTrackFaceInstanceStruct *
  chartInstance, c2_emxArray_real32_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(real32_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, (void *)c2_emxArray->data, sizeof(real32_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex((void *)c2_emxArray->data);
      }
    }

    c2_emxArray->data = (real32_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxCopyStruct_vision_internal_c
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
   c2_vision_internal_cornerPoints_cg *c2_dst, const
   c2_vision_internal_cornerPoints_cg *c2_src, const emlrtRTEInfo
   *c2_srcLocation)
{
  c2_emxCopy_real32_T(chartInstance, &c2_dst->pLocation, &c2_src->pLocation,
                      c2_srcLocation);
  c2_emxCopy_real32_T1(chartInstance, &c2_dst->pMetric, &c2_src->pMetric,
                       c2_srcLocation);
}

static void c2_emxCopy_real32_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T **c2_dst, c2_emxArray_real32_T * const
  *c2_src, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_numElDst;
  int32_T c2_numElSrc;
  int32_T c2_i;
  c2_numElDst = 1;
  c2_numElSrc = 1;
  for (c2_i = 0; c2_i < (*c2_dst)->numDimensions; c2_i++) {
    c2_numElDst *= (*c2_dst)->size[c2_i];
    c2_numElSrc *= (*c2_src)->size[c2_i];
  }

  for (c2_i = 0; c2_i < (*c2_dst)->numDimensions; c2_i++) {
    (*c2_dst)->size[c2_i] = (*c2_src)->size[c2_i];
  }

  c2_emxEnsureCapacity_real32_T(chartInstance, *c2_dst, c2_numElDst,
    c2_srcLocation);
  for (c2_i = 0; c2_i < c2_numElSrc; c2_i++) {
    (*c2_dst)->data[c2_i] = (*c2_src)->data[c2_i];
  }
}

static void c2_emxCopy_real32_T1(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T **c2_dst, c2_emxArray_real32_T * const
  *c2_src, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_numElDst;
  int32_T c2_numElSrc;
  int32_T c2_i;
  c2_numElDst = 1;
  c2_numElSrc = 1;
  for (c2_i = 0; c2_i < (*c2_dst)->numDimensions; c2_i++) {
    c2_numElDst *= (*c2_dst)->size[c2_i];
    c2_numElSrc *= (*c2_src)->size[c2_i];
  }

  for (c2_i = 0; c2_i < (*c2_dst)->numDimensions; c2_i++) {
    (*c2_dst)->size[c2_i] = (*c2_src)->size[c2_i];
  }

  c2_emxEnsureCapacity_real32_T1(chartInstance, *c2_dst, c2_numElDst,
    c2_srcLocation);
  for (c2_i = 0; c2_i < c2_numElSrc; c2_i++) {
    (*c2_dst)->data[c2_i] = (*c2_src)->data[c2_i];
  }
}

static void c2_emxEnsureCapacity_real32_T1(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(real32_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, (void *)c2_emxArray->data, sizeof(real32_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex((void *)c2_emxArray->data);
      }
    }

    c2_emxArray->data = (real32_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxInitStruct_vision_internal_c
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
   c2_vision_internal_cornerPoints_cg *c2_pStruct, const emlrtRTEInfo
   *c2_srcLocation)
{
  c2_emxInit_real32_T(chartInstance, &c2_pStruct->pLocation, 2, c2_srcLocation);
  c2_emxInit_real32_T1(chartInstance, &c2_pStruct->pMetric, 1, c2_srcLocation);
}

static void c2_emxInit_real32_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_real32_T *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_real32_T *)emlrtMallocMex(sizeof
    (c2_emxArray_real32_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (real32_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * c2_numDimensions));
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_real32_T1(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_real32_T *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_real32_T *)emlrtMallocMex(sizeof
    (c2_emxArray_real32_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (real32_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * c2_numDimensions));
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_real_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_real_T *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_real_T *)emlrtMallocMex(sizeof(c2_emxArray_real_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (real_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * c2_numDimensions));
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_uint8_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_uint8_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_uint8_T *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_uint8_T *)emlrtMallocMex(sizeof
    (c2_emxArray_uint8_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (uint8_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * c2_numDimensions));
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_int32_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_int32_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_int32_T *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_int32_T *)emlrtMallocMex(sizeof
    (c2_emxArray_int32_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (int32_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * c2_numDimensions));
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_int32_T1(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_int32_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_int32_T *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_int32_T *)emlrtMallocMex(sizeof
    (c2_emxArray_int32_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (int32_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * c2_numDimensions));
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxFree_real32_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_real32_T *)NULL) {
    if (((*c2_pEmxArray)->data != (real32_T *)NULL) && (*c2_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((void *)(*c2_pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*c2_pEmxArray)->size);
    emlrtFreeMex((void *)*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_real32_T *)NULL;
  }
}

static void c2_emxFreeStruct_vision_internal_c
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
   c2_vision_internal_cornerPoints_cg *c2_pStruct)
{
  c2_emxFree_real32_T(chartInstance, &c2_pStruct->pLocation);
  c2_emxFree_real32_T(chartInstance, &c2_pStruct->pMetric);
}

static void c2_emxFree_real_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real_T **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_real_T *)NULL) {
    if (((*c2_pEmxArray)->data != (real_T *)NULL) && (*c2_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((void *)(*c2_pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*c2_pEmxArray)->size);
    emlrtFreeMex((void *)*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_real_T *)NULL;
  }
}

static void c2_emxFree_uint8_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_uint8_T **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_uint8_T *)NULL) {
    if (((*c2_pEmxArray)->data != (uint8_T *)NULL) && (*c2_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((void *)(*c2_pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*c2_pEmxArray)->size);
    emlrtFreeMex((void *)*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_uint8_T *)NULL;
  }
}

static void c2_emxFree_int32_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_int32_T **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_int32_T *)NULL) {
    if (((*c2_pEmxArray)->data != (int32_T *)NULL) && (*c2_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((void *)(*c2_pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*c2_pEmxArray)->size);
    emlrtFreeMex((void *)*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_int32_T *)NULL;
  }
}

static void c2_emxEnsureCapacity_real_T1(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(real_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, (void *)c2_emxArray->data, sizeof(real_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex((void *)c2_emxArray->data);
      }
    }

    c2_emxArray->data = (real_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxInit_boolean_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_boolean_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_boolean_T *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_boolean_T *)emlrtMallocMex(sizeof
    (c2_emxArray_boolean_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (boolean_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * c2_numDimensions));
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_real_T1(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_real_T *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_real_T *)emlrtMallocMex(sizeof(c2_emxArray_real_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (real_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * c2_numDimensions));
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxFree_boolean_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_boolean_T **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_boolean_T *)NULL) {
    if (((*c2_pEmxArray)->data != (boolean_T *)NULL) && (*c2_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((void *)(*c2_pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*c2_pEmxArray)->size);
    emlrtFreeMex((void *)*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_boolean_T *)NULL;
  }
}

static void c2_emxEnsureCapacity_boolean_T(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_boolean_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(boolean_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, (void *)c2_emxArray->data, sizeof(boolean_T)
             * (uint32_T)c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex((void *)c2_emxArray->data);
      }
    }

    c2_emxArray->data = (boolean_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxEnsureCapacity_real32_T2(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(real32_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, (void *)c2_emxArray->data, sizeof(real32_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex((void *)c2_emxArray->data);
      }
    }

    c2_emxArray->data = (real32_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxEnsureCapacity_boolean_T1
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance, c2_emxArray_boolean_T
   *c2_emxArray, int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(boolean_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, (void *)c2_emxArray->data, sizeof(boolean_T)
             * (uint32_T)c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex((void *)c2_emxArray->data);
      }
    }

    c2_emxArray->data = (boolean_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxInit_real32_T2(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_real32_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_real32_T *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_real32_T *)emlrtMallocMex(sizeof
    (c2_emxArray_real32_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (real32_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * c2_numDimensions));
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_boolean_T1(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_boolean_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_boolean_T *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_boolean_T *)emlrtMallocMex(sizeof
    (c2_emxArray_boolean_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (boolean_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * c2_numDimensions));
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxEnsureCapacity_boolean_T2
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance, c2_emxArray_boolean_T
   *c2_emxArray, int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(boolean_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, (void *)c2_emxArray->data, sizeof(boolean_T)
             * (uint32_T)c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex((void *)c2_emxArray->data);
      }
    }

    c2_emxArray->data = (boolean_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxInit_boolean_T2(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, c2_emxArray_boolean_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_boolean_T *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_boolean_T *)emlrtMallocMex(sizeof
    (c2_emxArray_boolean_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (boolean_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * c2_numDimensions));
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInitStruct_sjeQsvJNEhdsHQhIi
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
   c2_sjeQsvJNEhdsHQhIigwA2FF *c2_pStruct, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxInit_real32_T(chartInstance, &c2_pStruct->Location, 2, c2_srcLocation);
  c2_emxInit_real32_T1(chartInstance, &c2_pStruct->Metric, 1, c2_srcLocation);
}

static void c2_emxFreeStruct_sjeQsvJNEhdsHQhIi
  (SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
   c2_sjeQsvJNEhdsHQhIigwA2FF *c2_pStruct)
{
  c2_emxFree_real32_T(chartInstance, &c2_pStruct->Location);
  c2_emxFree_real32_T(chartInstance, &c2_pStruct->Metric);
}

static int32_T c2_div_s32_floor(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, int32_T c2_numerator, int32_T c2_denominator, uint32_T
  c2_ssid_src_loc, int32_T c2_offset_src_loc, int32_T c2_length_src_loc)
{
  int32_T c2_quotient;
  uint32_T c2_absNumerator;
  uint32_T c2_absDenominator;
  boolean_T c2_quotientNeedsNegation;
  uint32_T c2_tempAbsQuotient;
  (void)chartInstance;
  if (c2_denominator == 0) {
    if (c2_numerator >= 0) {
      c2_quotient = MAX_int32_T;
    } else {
      c2_quotient = MIN_int32_T;
    }

    _SFD_OVERFLOW_DETECTION(SFDB_DIVIDE_BY_ZERO, c2_ssid_src_loc,
      c2_offset_src_loc, c2_length_src_loc);
  } else {
    if (c2_numerator < 0) {
      c2_absNumerator = ~(uint32_T)c2_numerator + 1U;
    } else {
      c2_absNumerator = (uint32_T)c2_numerator;
    }

    if (c2_denominator < 0) {
      c2_absDenominator = ~(uint32_T)c2_denominator + 1U;
    } else {
      c2_absDenominator = (uint32_T)c2_denominator;
    }

    c2_quotientNeedsNegation = ((c2_numerator < 0) != (c2_denominator < 0));
    c2_tempAbsQuotient = c2_absNumerator / c2_absDenominator;
    if (c2_quotientNeedsNegation) {
      c2_absNumerator %= c2_absDenominator;
      if (c2_absNumerator > 0U) {
        c2_tempAbsQuotient++;
      }
    }

    if (c2_quotientNeedsNegation) {
      c2_quotient = -(int32_T)c2_tempAbsQuotient;
    } else {
      c2_quotient = (int32_T)c2_tempAbsQuotient;
    }
  }

  return c2_quotient;
}

static int32_T c2_div_s32(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  int32_T c2_numerator, int32_T c2_denominator, uint32_T c2_ssid_src_loc,
  int32_T c2_offset_src_loc, int32_T c2_length_src_loc)
{
  int32_T c2_quotient;
  uint32_T c2_absNumerator;
  uint32_T c2_absDenominator;
  boolean_T c2_quotientNeedsNegation;
  uint32_T c2_tempAbsQuotient;
  (void)chartInstance;
  if (c2_denominator == 0) {
    if (c2_numerator >= 0) {
      c2_quotient = MAX_int32_T;
    } else {
      c2_quotient = MIN_int32_T;
    }

    _SFD_OVERFLOW_DETECTION(SFDB_DIVIDE_BY_ZERO, c2_ssid_src_loc,
      c2_offset_src_loc, c2_length_src_loc);
  } else {
    if (c2_numerator < 0) {
      c2_absNumerator = ~(uint32_T)c2_numerator + 1U;
    } else {
      c2_absNumerator = (uint32_T)c2_numerator;
    }

    if (c2_denominator < 0) {
      c2_absDenominator = ~(uint32_T)c2_denominator + 1U;
    } else {
      c2_absDenominator = (uint32_T)c2_denominator;
    }

    c2_quotientNeedsNegation = ((c2_numerator < 0) != (c2_denominator < 0));
    c2_tempAbsQuotient = c2_absNumerator / c2_absDenominator;
    if (c2_quotientNeedsNegation) {
      c2_quotient = -(int32_T)c2_tempAbsQuotient;
    } else {
      c2_quotient = (int32_T)c2_tempAbsQuotient;
    }
  }

  return c2_quotient;
}

static int32_T c2_div_nzp_s32(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance, int32_T c2_numerator, int32_T c2_denominator, uint32_T
  c2_ssid_src_loc, int32_T c2_offset_src_loc, int32_T c2_length_src_loc)
{
  int32_T c2_quotient;
  uint32_T c2_absNumerator;
  uint32_T c2_absDenominator;
  boolean_T c2_quotientNeedsNegation;
  uint32_T c2_tempAbsQuotient;
  (void)chartInstance;
  (void)c2_ssid_src_loc;
  (void)c2_offset_src_loc;
  (void)c2_length_src_loc;
  if (c2_numerator < 0) {
    c2_absNumerator = ~(uint32_T)c2_numerator + 1U;
  } else {
    c2_absNumerator = (uint32_T)c2_numerator;
  }

  if (c2_denominator < 0) {
    c2_absDenominator = ~(uint32_T)c2_denominator + 1U;
  } else {
    c2_absDenominator = (uint32_T)c2_denominator;
  }

  c2_quotientNeedsNegation = ((c2_numerator < 0) != (c2_denominator < 0));
  c2_tempAbsQuotient = c2_absNumerator / c2_absDenominator;
  if (c2_quotientNeedsNegation) {
    c2_quotient = -(int32_T)c2_tempAbsQuotient;
  } else {
    c2_quotient = (int32_T)c2_tempAbsQuotient;
  }

  return c2_quotient;
}

static int32_T c2__s32_d_(SFc2_DetectAndTrackFaceInstanceStruct *chartInstance,
  real_T c2_b, uint32_T c2_ssid_src_loc, int32_T c2_offset_src_loc, int32_T
  c2_length_src_loc)
{
  int32_T c2_a;
  real_T c2_b_b;
  (void)chartInstance;
  c2_a = (int32_T)c2_b;
  if (c2_b < 0.0) {
    c2_b_b = muDoubleScalarCeil(c2_b);
  } else {
    c2_b_b = muDoubleScalarFloor(c2_b);
  }

  if ((real_T)c2_a != c2_b_b) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW, c2_ssid_src_loc, c2_offset_src_loc,
      c2_length_src_loc);
  }

  return c2_a;
}

static void init_dsm_address_info(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_DetectAndTrackFaceInstanceStruct
  *chartInstance)
{
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_bBox_data = (real_T (*)[16])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_bBox_sizes = (int32_T (*)[2])
    ssGetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1);
  chartInstance->c2_b_videoFrameGray = (real_T (*)[1048576])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c2_featurePointLocations_data = (real32_T (*)[1000])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c2_featurePointLocations_sizes = (int32_T (*)[2])
    ssGetCurrentOutputPortDimensions_wrapper(chartInstance->S, 2);
  chartInstance->c2_decimationFactor = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_numberOfFeaturePoints = (real_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 2);
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

void sf_c2_DetectAndTrackFace_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4171747919U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2624552967U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(315420819U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2913133627U);
}

mxArray* sf_c2_DetectAndTrackFace_get_post_codegen_info(void);
mxArray *sf_c2_DetectAndTrackFace_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("rkeCrnzyYuv8cwyCmDdiPD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(8);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c2_DetectAndTrackFace_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_DetectAndTrackFace_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,6);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "vision.internal.buildable.cascadeClassifierBuildable"));
  mxSetCell(mxcell3p, 1, mxCreateString(
             "images.internal.coder.buildable.Grayto8Buildable"));
  mxSetCell(mxcell3p, 2, mxCreateString(
             "images.internal.coder.buildable.IppfilterBuildable"));
  mxSetCell(mxcell3p, 3, mxCreateString(
             "images.internal.coder.buildable.ImfilterBuildable"));
  mxSetCell(mxcell3p, 4, mxCreateString(
             "images.internal.coder.buildable.ImregionalmaxBuildable"));
  mxSetCell(mxcell3p, 5, mxCreateString(
             "images.internal.coder.buildable.Bwlookup_tbb_Buildable"));
  return(mxcell3p);
}

mxArray *sf_c2_DetectAndTrackFace_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_functions");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString(
    "cascadeClassifierBuildable_cascadeClassifier_construct");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_DetectAndTrackFace_updateBuildInfo_args_info(void)
{
  const char *infoEncStr[] = {
    "100 C{C1x2{T\"addNonBuildFiles\",C1x3{T\"/usr/local/MATLAB/R2017b/toolbox/vision/visionutilities/classifierdata/cascade/haar/haarcascade_frontalface_alt2.xml\",T\"\",T\"BlockModules\"}}}"
  };

  mxArray *mxBIArgs = sf_mex_decode_encoded_mx_cell_array(infoEncStr, 1, 10);
  return mxBIArgs;
}

mxArray* sf_c2_DetectAndTrackFace_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c2_DetectAndTrackFace(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[6],T\"bBox\",},{M[1],M[11],T\"featurePointLocations\",},{M[8],M[0],T\"is_active_c2_DetectAndTrackFace\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_DetectAndTrackFace_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_DetectAndTrackFaceInstanceStruct *chartInstance =
      (SFc2_DetectAndTrackFaceInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DetectAndTrackFaceMachineNumber_,
           2,
           1,
           1,
           0,
           5,
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
          _SFD_SET_DATA_PROPS(2,1,1,0,"numberOfFeaturePoints");
          _SFD_SET_DATA_PROPS(3,2,0,1,"bBox");
          _SFD_SET_DATA_PROPS(4,2,0,1,"featurePointLocations");
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
        _SFD_CV_INIT_EML(0,1,1,0,3,0,1,0,0,0,1,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",91,-1,1224);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,680,-1,713);
        _SFD_CV_INIT_EML_IF(0,1,0,481,510,1105,1223);
        _SFD_CV_INIT_EML_IF(0,1,1,580,604,-1,667);
        _SFD_CV_INIT_EML_IF(0,1,2,795,812,1003,1104);

        {
          static int condStart[] = { 799 };

          static int condEnd[] = { 812 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,798,812,1,0,&(condStart[0]),&(condEnd[0]),
                                2,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,484,510,-1,2);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1024U;
          dimVector[1]= 1024U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2U;
          dimVector[1]= 8U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_h_sf_marshallOut,(MexInFcnForType)
            c2_g_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 500U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_i_sf_marshallOut,(MexInFcnForType)
            c2_h_sf_marshallIn);
        }
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
    SFc2_DetectAndTrackFaceInstanceStruct *chartInstance =
      (SFc2_DetectAndTrackFaceInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR_VAR_DIM(3U, (void *)chartInstance->c2_bBox_data,
          (void *)chartInstance->c2_bBox_sizes);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c2_b_videoFrameGray);
        _SFD_SET_DATA_VALUE_PTR_VAR_DIM(4U, (void *)
          chartInstance->c2_featurePointLocations_data, (void *)
          chartInstance->c2_featurePointLocations_sizes);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c2_decimationFactor);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)
          chartInstance->c2_numberOfFeaturePoints);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sMo4nouOik8x2YV4kgxDZp";
}

static void sf_opaque_initialize_c2_DetectAndTrackFace(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_DetectAndTrackFaceInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_DetectAndTrackFace((SFc2_DetectAndTrackFaceInstanceStruct*)
    chartInstanceVar);
  initialize_c2_DetectAndTrackFace((SFc2_DetectAndTrackFaceInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_DetectAndTrackFace(void *chartInstanceVar)
{
  enable_c2_DetectAndTrackFace((SFc2_DetectAndTrackFaceInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_DetectAndTrackFace(void *chartInstanceVar)
{
  disable_c2_DetectAndTrackFace((SFc2_DetectAndTrackFaceInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_DetectAndTrackFace(void *chartInstanceVar)
{
  sf_gateway_c2_DetectAndTrackFace((SFc2_DetectAndTrackFaceInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_DetectAndTrackFace(SimStruct* S)
{
  return get_sim_state_c2_DetectAndTrackFace
    ((SFc2_DetectAndTrackFaceInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_DetectAndTrackFace(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c2_DetectAndTrackFace((SFc2_DetectAndTrackFaceInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c2_DetectAndTrackFace(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_DetectAndTrackFaceInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DetectAndTrackFace_optimization_info();
    }

    finalize_c2_DetectAndTrackFace((SFc2_DetectAndTrackFaceInstanceStruct*)
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
  initSimStructsc2_DetectAndTrackFace((SFc2_DetectAndTrackFaceInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_DetectAndTrackFace(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_DetectAndTrackFace
      ((SFc2_DetectAndTrackFaceInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c2_DetectAndTrackFace(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetInputPortDirectFeedThrough(S, 2, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DetectAndTrackFace_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 2);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1075479384U));
  ssSetChecksum1(S,(1111565992U));
  ssSetChecksum2(S,(754605986U));
  ssSetChecksum3(S,(1896496400U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetSimStateCompliance(S, DISALLOW_SIM_STATE);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_DetectAndTrackFace(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_DetectAndTrackFace(SimStruct *S)
{
  SFc2_DetectAndTrackFaceInstanceStruct *chartInstance;
  chartInstance = (SFc2_DetectAndTrackFaceInstanceStruct *)utMalloc(sizeof
    (SFc2_DetectAndTrackFaceInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_DetectAndTrackFaceInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  if (ssGetSampleTime(S, 0) == CONTINUOUS_SAMPLE_TIME && ssGetOffsetTime(S, 0) ==
      0 && ssGetNumContStates(ssGetRootSS(S)) > 0) {
    sf_error_out_about_continuous_sample_time_with_persistent_vars(S);
  }

  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_DetectAndTrackFace;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_DetectAndTrackFace;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_DetectAndTrackFace;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_DetectAndTrackFace;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_DetectAndTrackFace;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_DetectAndTrackFace;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_DetectAndTrackFace;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_DetectAndTrackFace;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_DetectAndTrackFace;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_DetectAndTrackFace;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_DetectAndTrackFace;
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
  mdl_start_c2_DetectAndTrackFace(chartInstance);
}

void c2_DetectAndTrackFace_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_DetectAndTrackFace(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_DetectAndTrackFace(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_DetectAndTrackFace(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_DetectAndTrackFace_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
