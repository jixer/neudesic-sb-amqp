using Microsoft.ServiceBus.Messaging;
using Microsoft.WindowsAzure;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Neudesic.Demo.SBAMQP.App.MessageReceive
{
    class Program
    {
        static void Main(string[] args)
        {
            string connectionString = CloudConfigurationManager.GetSetting("Microsoft.ServiceBus.ConnectionString");

            var client = QueueClient.CreateFromConnectionString(connectionString, "amqp_test");

            Console.WriteLine("Waiting for a message on the queue...");

            BrokeredMessage msg = client.Receive();

            string subject = msg.Label;
            object testProp1 = msg.Properties["TestProp1"];
            object testProp2 = msg.Properties["TestProp2"];
            string body = msg.GetBody<string>();

            Console.WriteLine("Received a message on the queue");
            Console.WriteLine("Message Subject: {0}", subject);
            Console.WriteLine("Message Properties => TestProp1: {0} ({1})", testProp1, testProp1.GetType());
            Console.WriteLine("Message Properties => TestProp2: {0} ({1})", testProp2, testProp2.GetType());
            Console.WriteLine("Message Body: {0}", body);
            
            msg.Complete();

            Console.WriteLine();
            Console.Write("Press any key to continue...");
            Console.ReadKey();
        }
    }
}
