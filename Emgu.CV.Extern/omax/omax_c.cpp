#include "omax_c.h"
#include "omax.hpp"

cv::GMat* cveGapiBayerGR2BGR(cv::GMat* srcGR)
{
#ifdef HAVE_OPENCV_GAPI
	cv::GMat* result = new cv::GMat();
	*result = omax::BayerGR2BGR(*srcGR);
	return result;
#else
	throw_no_gapi();
#endif
}
cv::GMat* cveGapiBayerBG2BGR(cv::GMat* srcBG)
{
#ifdef HAVE_OPENCV_GAPI
	cv::GMat* result = new cv::GMat();
	*result = omax::BayerBG2BGR(*srcBG);
	return result;
#else
	throw_no_gapi();
#endif
}
cv::GMat* cveGapiBGR2RGBA(cv::GMat* src)
{
#ifdef HAVE_OPENCV_GAPI
	cv::GMat* result = new cv::GMat();
	*result = omax::BGR2RGBA(*src);
	return result;
#else
	throw_no_gapi();
#endif
}

cv::GKernelPackage* cveOmaxGetOcvKernelPackage()
{
#ifdef HAVE_OPENCV_GAPI
	cv::GKernelPackage* result = new cv::GKernelPackage();
	*result = omax::ocv::kernels();
	return result;
#else
	throw_no_gapi();
#endif
}

cv::GKernelPackage* cveOmaxGetOclKernelPackage()
{
#ifdef HAVE_OPENCV_GAPI
	cv::GKernelPackage* result = new cv::GKernelPackage();
	*result = omax::ocl::kernels();
	return result;
#else
	throw_no_gapi();
#endif
}