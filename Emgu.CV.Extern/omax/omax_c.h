#pragma once
#ifndef EMGU_OMAX_C_H
#define EMGU_OMAX_C_H

#include "opencv2/core/core_c.h"

#ifdef HAVE_OPENCV_GAPI
#include "opencv2/gapi.hpp"
#include "opencv2/gapi/core.hpp"
#include "opencv2/gapi/imgproc.hpp"
#else
static inline CV_NORETURN void throw_no_gapi() { CV_Error(cv::Error::StsBadFunc, "The library is compiled without gapi support. To use this module, please switch to the full Emgu CV runtime."); }
namespace cv {
	class GMat {};
	class GScalar {};
	class GComputation {};
	namespace gapi {

	}
}
#endif

CVAPI(cv::GMat*) cveGapiBayerGR2BGR(cv::GMat* src_gr);
CVAPI(cv::GMat*) cveGapiBayerBG2BGR(cv::GMat* src_bg);
CVAPI(cv::GMat*) cveGapiBGR2RGBA(cv::GMat* src);
CVAPI(cv::GKernelPackage*) cveOmaxGetOcvKernelPackage();
CVAPI(cv::GKernelPackage*) cveOmaxGetOclKernelPackage();
#endif
