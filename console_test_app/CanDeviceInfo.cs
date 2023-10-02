using System;
using System.Runtime.InteropServices;
using System.Text;

namespace console_test_app
{
    [StructLayout(LayoutKind.Sequential)]
    public struct CanDeviceInfo
    {
        public string device_name;
        public UInt32 device_status;
    }
}
