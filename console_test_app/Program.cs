using System;
using System.Runtime.InteropServices;

namespace console_test_app
{
    internal class Program
    {
        static void Main(string[] args)
        {
            try
            {
                var deviceList = new CanDeviceList();
                deviceList = Marshal.PtrToStructure<CanDeviceList>(LibnmcanWrapper.CanEnumerate());
                Console.WriteLine($"CanEnumerator().count: {deviceList.count}");

                //var device = new CanDeviceInfo();
                //device = Marshal.PtrToStructure<CanDeviceInfo>(deviceList.device);
                //Console.WriteLine($"CAN_device_info.device_name: {device.device_name}");
            }
            catch (Exception ex) 
            {
                Console.WriteLine(ex);
            }

            Console.WriteLine("Press any key...");
            Console.ReadKey();
        }
    }
}
