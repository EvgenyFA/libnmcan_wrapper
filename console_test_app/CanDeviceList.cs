using System;
using System.Runtime.InteropServices;

namespace console_test_app
{
    [StructLayout(LayoutKind.Sequential)]
    public struct CanDeviceList
    {
        public byte count;
        public IntPtr device;
    }
}
