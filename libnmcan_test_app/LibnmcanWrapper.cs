using System.Runtime.InteropServices;

namespace libnmcan_test_app;

public static class LibnmcanWrapper
{
    private const string LIB_NAME = "libnmcan.so";

    [DllImport(LIB_NAME, CallingConvention = CallingConvention.Cdecl)]
    public static extern IntPtr CanEnumerator();
}
