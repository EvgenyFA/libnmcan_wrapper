using System;

namespace console_test_app
{
    internal class Program
    {
        static void Main(string[] args)
        {
            try
            {
                Console.WriteLine($"CanEnumerator(): {LibnmcanWrapper.CanEnumerate()}");
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
