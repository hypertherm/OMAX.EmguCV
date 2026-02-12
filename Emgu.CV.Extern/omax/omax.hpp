#pragma once
#ifndef EMGU_OMAX_HPP
#define EMGU_OMAX_HPP

#include "opencv2/gapi.hpp"
#include <opencv2/imgproc.hpp>
#include <opencv2/gapi/gscalar.hpp>
#include <opencv2/gapi/gmat.hpp>
#include <opencv2/gapi/gkernel.hpp>

#include <utility> // std::tuple

namespace omax {
    G_TYPED_KERNEL(GBayerGR2BGR, <cv::GMat(cv::GMat)>, "omax.gapi.bayergr2bgr") {
        static cv::GMatDesc outMeta(cv::GMatDesc in) {
            return in.withType(CV_8U, 3);
        }
    };

    G_TYPED_KERNEL(GBayerBG2BGR, <cv::GMat(cv::GMat)>, "omax.gapi.bayerbg2bgr") {
        static cv::GMatDesc outMeta(cv::GMatDesc in) {
            return in.withType(CV_8U, 3);
        }
    };

    G_TYPED_KERNEL(GBGR2RGBA, <cv::GMat(cv::GMat)>, "omax.gapi.gbgr2rgba") {
        static cv::GMatDesc outMeta(cv::GMatDesc in) {
            return in.withType(CV_8U, 4);
        }
    };
    GAPI_EXPORTS_W cv::GMat BayerGR2BGR(const cv::GMat& src_gr);

    GAPI_EXPORTS_W cv::GMat BayerBG2BGR(const cv::GMat& src_bg);

    GAPI_EXPORTS_W cv::GMat BGR2RGBA(const cv::GMat& src);

    namespace ocl
    {
        cv::GKernelPackage kernels();
    }
    namespace ocv
    {
        cv::GKernelPackage kernels();
    }
}
#endif
