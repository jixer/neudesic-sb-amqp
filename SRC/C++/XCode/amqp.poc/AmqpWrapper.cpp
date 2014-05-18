//
//  AmqpWrapper.cpp
//  amqp.poc
//
//  Created by Chris' Mac on 5/17/14.
//
//

#include "AmqpWrapper.h"
#include "proton/message.h"
#include "proton/messenger.h"

//#include "pncompat/misc_funcs.inc"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

AmqpWrapper::AmqpWrapper() {
    amqpAddress = (char *) "amqp://0.0.0.0";
}

void AmqpWrapper::SendMessage(char * msgtext) {
    
    pn_message_t * message;
    pn_messenger_t * messenger;
    pn_data_t * body;
        
    message = pn_message();
    messenger = pn_messenger(NULL);
        
    pn_messenger_start(messenger);
    
    pn_message_set_address(message, amqpAddress);
    body = pn_message_body(message);
    pn_data_put_string(body, pn_bytes(strlen(msgtext), msgtext));
    pn_messenger_put(messenger, message);
    
    pn_messenger_send(messenger, 0);
    
    pn_messenger_stop(messenger);
    pn_messenger_free(messenger);
    pn_message_free(message);
}