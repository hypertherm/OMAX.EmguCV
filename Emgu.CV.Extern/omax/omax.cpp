#include "omax.hpp"

#include <opencv2/gapi/cpu/gcpukernel.hpp>
#include <opencv2/gapi/ocl/goclkernel.hpp>

namespace omax {
    cv::GMat BayerGR2BGR(const cv::GMat& src_gr)
    {
        return GBayerGR2BGR::on(src_gr);
    }

    cv::GMat BayerBG2BGR(const cv::GMat& src_bg)
    {
        return GBayerBG2BGR::on(src_bg);
    }

    cv::GMat BGR2RGBA(const cv::GMat& src)
    {
        return GBGR2RGBA::on(src);
    }

    namespace ocv {
        GAPI_OCV_KERNEL(GCPUBayerGR2BGR, omax::GBayerGR2BGR)
        {
            static void run(const cv::Mat & in, cv::Mat & out)
            {
                cv::cvtColor(in, out, cv::COLOR_BayerGR2BGR);
            }
        };

        GAPI_OCV_KERNEL(GCPUBayerBG2BGR, omax::GBayerBG2BGR)
        {
            static void run(const cv::Mat & in, cv::Mat & out)
            {
                cv::cvtColor(in, out, cv::COLOR_BayerBG2BGR);
            }
        };

        GAPI_OCV_KERNEL(GCPUBGR2RGBA, omax::GBGR2RGBA)
        {
            static void run(const cv::Mat & in, cv::Mat & out)
            {
                cv::cvtColor(in, out, cv::COLOR_BGR2RGBA);
            }
        };
        cv::gapi::GKernelPackage kernels()
        {
            return cv::gapi::kernels
                < GCPUBayerGR2BGR
                , GCPUBayerBG2BGR
                , GCPUBGR2RGBA
                >();
        }
    }

    namespace ocl {
        GAPI_OCL_KERNEL(GOCLBayerGR2BGR, omax::GBayerGR2BGR)
        {
            static void run(const cv::UMat & in, cv::UMat & out)
            {
                cv::cvtColor(in, out, cv::COLOR_BayerGR2BGR);
            }
        };

        GAPI_OCL_KERNEL(GOCLBayerBG2BGR, omax::GBayerBG2BGR)
        {
            static void run(const cv::UMat & in, cv::UMat & out)
            {
                cv::cvtColor(in, out, cv::COLOR_BayerBG2BGR);
            }
        };

        GAPI_OCL_KERNEL(GOCLBGR2RGBA, omax::GBGR2RGBA)
        {
            static void run(const cv::UMat & in, cv::UMat & out)
            {
                cv::cvtColor(in, out, cv::COLOR_BGR2RGBA);
            }
        };
        cv::gapi::GKernelPackage kernels()
        {
            return cv::gapi::kernels
                < GOCLBayerGR2BGR
                , GOCLBayerBG2BGR
                , GOCLBGR2RGBA
                >();
        }
    }
}

