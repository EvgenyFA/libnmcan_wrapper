using System;
using System.Runtime.InteropServices;

namespace console_test_app
{
    public static class LibnmcanWrapper
    {
        private const string LIB_NAME = "libnmcan_dotnet_wrapper.dll";

        [DllImport(LIB_NAME, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr CanEnumerate();
    }
}
