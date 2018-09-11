﻿using System;
using System.Runtime.Remoting;
using System.Runtime.Remoting.Channels.Tcp;
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
            TcpClientChannel channel = new TcpClientChannel();
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
