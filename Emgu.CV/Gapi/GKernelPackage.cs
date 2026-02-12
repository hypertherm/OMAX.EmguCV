using System;
using System.Diagnostics;
using System.Drawing;
using System.Runtime.InteropServices;
using System.Runtime.Serialization;
using Emgu.CV.CvEnum;
using Emgu.CV.Structure;
using Emgu.CV.Util;
using Emgu.Util;
using System.IO;

namespace Emgu.CV
{
    public partial class GKernelPackage : UnmanagedObject
    {
        public GKernelPackage(GKernelPkgType type)
        {
            switch (type)
            {
                case GKernelPkgType.CoreCpu:
                    _ptr = GapiInvoke.cveGKernelPackageCoreCpuGet();
                    break;
                case GKernelPkgType.ImgProcCpu:
                    _ptr = GapiInvoke.cveGKernelPackageImgProcCpuGet();
                    break;
                case GKernelPkgType.CoreOcl:
                    _ptr = GapiInvoke.cveGKernelPackageCoreOclGet();
                    break;
                case GKernelPkgType.ImgProcOcl:
                    _ptr = GapiInvoke.cveGKernelPackageImgProcOclGet();
                    break;
                case GKernelPkgType.OmaxCpu:
                    _ptr = GapiInvoke.cveOmaxGetOcvKernelPackage();
                    break;
                case GKernelPkgType.OmaxOcl:
                    _ptr = GapiInvoke.cveOmaxGetOclKernelPackage();
                    break;
            }
        }
        public GKernelPackage(IntPtr ptr)
        {
            _ptr = ptr;
        }
        protected override void DisposeObject()
        {
            if (IntPtr.Zero != _ptr)
            {
                GapiInvoke.cveGKernelPackageRelease(ref _ptr);
            }
        }
    }

    public static partial class GapiInvoke
    {
        [DllImport(CvInvoke.ExternLibrary, CallingConvention = CvInvoke.CvCallingConvention)]
        internal static extern IntPtr cveGKernelPackageCoreCpuGet();

        [DllImport(CvInvoke.ExternLibrary, CallingConvention = CvInvoke.CvCallingConvention)]
        internal static extern IntPtr cveGKernelPackageImgProcCpuGet();

        [DllImport(CvInvoke.ExternLibrary, CallingConvention = CvInvoke.CvCallingConvention)]
        internal static extern IntPtr cveGKernelPackageCoreOclGet();

        [DllImport(CvInvoke.ExternLibrary, CallingConvention = CvInvoke.CvCallingConvention)]
        internal static extern IntPtr cveGKernelPackageImgProcOclGet();

        [DllImport(CvInvoke.ExternLibrary, CallingConvention = CvInvoke.CvCallingConvention)]
        internal static extern IntPtr cveOmaxGetOcvKernelPackage();

        [DllImport(CvInvoke.ExternLibrary, CallingConvention = CvInvoke.CvCallingConvention)]
        internal static extern IntPtr cveOmaxGetOclKernelPackage();

        [DllImport(CvInvoke.ExternLibrary, CallingConvention = CvInvoke.CvCallingConvention)]
        internal static extern void cveGKernelPackageRelease(ref IntPtr ptr);
    }

    public enum GKernelPkgType
    {
        CoreCpu = 0,
        ImgProcCpu,
        CoreOcl,
        ImgProcOcl,
        OmaxCpu,
        OmaxOcl
    }
}