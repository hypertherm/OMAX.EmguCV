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
    public partial class GCompileArgs : UnmanagedObject
    {
        public GCompileArgs(GKernelPackage pkg)
        {
            _ptr = GapiInvoke.cveGCompileArgsCreate(pkg);
        }
        protected override void DisposeObject()
        {
            if (IntPtr.Zero != _ptr)
            {
                GapiInvoke.cveGCompileArgsRelease(ref _ptr);
            }
        }
    }

    public static partial class GapiInvoke
    {
        [DllImport(CvInvoke.ExternLibrary, CallingConvention = CvInvoke.CvCallingConvention)]
        internal static extern IntPtr cveGCompileArgsCreate(IntPtr ptr);
        
        [DllImport(CvInvoke.ExternLibrary, CallingConvention = CvInvoke.CvCallingConvention)]
        internal static extern void cveGCompileArgsRelease(ref IntPtr ptr);
    }
}