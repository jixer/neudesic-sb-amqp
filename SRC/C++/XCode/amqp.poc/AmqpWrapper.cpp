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
    amqpAddress = (char *) "amqps://<user_name>:<password>@neudesic-amqp-demo.servicebus.windows.net/amqp_test";
}

void AmqpWrapper::SendMessage(char * msgtext) {
    pn_message_t * message;
    pn_messenger_t * messenger;
    pn_data_t * body;
    pn_data_t * props;
    
    int err = 0;
        
    message = pn_message();
    messenger = pn_messenger(NULL);
        
    pn_messenger_start(messenger);
    configureAzureSbMessage(message, "Test message from Mac");
    
    body = pn_message_body(message);
    pn_data_put_string(body, pn_bytes(strlen(msgtext), msgtext));
    
    props = setProperties(message, (char *)"TestProp text value", 10);
    
    err = pn_messenger_put(messenger, message);
    if (err != 0) {
        printf("put error code: %d\r\n", err);
    }
    
    
    err = pn_messenger_send(messenger, -1);
    if (err != 0) {
        printf("send error code: %d\r\n", err);
    }
    
    pn_messenger_stop(messenger);
    pn_messenger_free(messenger);
    pn_message_free(message);
}

pn_data_t * AmqpWrapper::setProperties(pn_message_t *message, char *stringProp, int intProp) {
    // initialize
    pn_data_t * props = pn_message_properties(message);
    pn_data_put_map(props);
    pn_data_enter(props);
    
    // set prop1
    pn_data_put_string(props, pn_bytes(9, (char *)"TestProp1"));
    pn_data_put_string(props, pn_bytes(strlen(stringProp), stringProp));
    
    // set prop2
    pn_data_put_string(props, pn_bytes(9, (char *)"TestProp2"));
    pn_data_put_int(props, intProp);
    
    // exit and return
    pn_data_exit(props);
    return props;
}

void AmqpWrapper::configureAzureSbMessage(pn_message_t *message, const char *label) {
    pn_message_set_subject(message, label);
    pn_message_set_ttl(message, PN_TTL);
    pn_message_set_address(message, amqpAddress);
}
