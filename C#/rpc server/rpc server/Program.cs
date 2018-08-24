using System;
using System.Runtime.Remoting;
using System.Runtime.Remoting.Channels.Tcp;using System.Runtime.Remoting.Channels;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//namespace rpc_server

    class Program
    {
        static void Main(string[] args)
        {
            //creating a server
            TcpServerChannel channel = new TcpServerChannel(8080);
            ChannelServices.RegisterChannel(channel, false);

            //registering player
            RemotingConfiguration.RegisterWellKnownServiceType(typeof(Player), "Player", WellKnownObjectMode.SingleCall);

            Console.WriteLine("Listening for requests.\nPress enter to exit...\n");
            Console.ReadLine();
        }
    }

