using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace intro_to_c.player
{
    class player
    {
         string name = "";

        public player(string name)
        {
            this.name = name;
        }
        public void Setname(string name)
        {
            this.name = name;
        }
    }
}
