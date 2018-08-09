using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace net_containers
{
    class Class1
    {
        public void ArrayExample(int size)
        {
            int[] array = new int[size];
            foreach(int index in array)
            {
                Console.WriteLine(array[index]);
            }
           
        }

    }
}
