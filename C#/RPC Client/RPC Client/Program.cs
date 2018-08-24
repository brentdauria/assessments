using System;
using System.Runtime.Remoting;
using System.Runtime.Remoting.Channels.Tcp;using System.Runtime.Remoting.Channels;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//namespace RPC_Client

    class Program
    {
        static void Main(string[] args)
        {
            //create client
            TcpClientChannel channel = new TcpClientChannel();            ChannelServices.RegisterChannel(channel, false);            //get a referfence to the player on the server             string playerURL = "tcp://localhost:" + 8080 + "/Player";            Player player = (Player)Activator.GetObject(typeof(Player), playerURL);            while (true)
            {
                Console.Write("Type a message to the server or type 'quit' to exit\n");
                string text = Console.ReadLine();

                if (text == "quit")
                    break;

                //Rpc call function on the server
                player.SayHello(text);
            }
        }
    }

