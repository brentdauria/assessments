using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace intro_to_c
{
    class Program
    {
        public static float val2 = 3;
        static void Main(string[] args)
        {
            // player.player p = new player.player("bob");
            // p.Setname("bob");

            // string name;
            // name = Console.ReadLine();
            // Console.WriteLine("hello " + name);
            // Console.ReadLine();

            calculator calculator = new calculator();

            Console.WriteLine(calculator.Adding(3, 4));
            Console.WriteLine(calculator.Subtract(3, 4));
            Console.WriteLine(calculator.Multiply(3, 4));
            Console.WriteLine(calculator.Divide(3, 4));
            Console.ReadKey();
        }
    }
}
