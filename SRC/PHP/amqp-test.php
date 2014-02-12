<?php 
	include("proton.php");
	
	$username = "<user_snipped>";
	$password = "<key_snipped>";
	$namespace = "neudesic-amqp-demo.servicebus";
	$topic = "amqp_test";

	$messenger = new Messenger();
	$messenger->start();

	$message = new Message();
	$message->address = "amqps://$username:$password@$namespace.windows.net/$topic";
	$message->subject = "This is a subject";
	$message->properties["TestProp1"] = "TestProp1 text value";
	$message->properties["TestProp2"] = 10;
	$message->body = "This is a text string";

	$messenger->put($message);
	$messenger->send();

	$messenger->stop();

	echo("Message successfully sent!\r\n");
?>