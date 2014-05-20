//
//  AmqpWrapper.h
//  amqp.poc
//
//  Created by Chris' Mac on 5/17/14.
//
//

#ifndef __amqp_poc__AmqpWrapper__
#define __amqp_poc__AmqpWrapper__

#include <iostream>
#include "proton/message.h"

#endif /* defined(__amqp_poc__AmqpWrapper__) */

class AmqpWrapper {
public:
    AmqpWrapper();
    void SendMessage(char* message);
private:
    char * amqpAddress;
    const pn_millis_t PN_TTL = 86400000;
    pn_data_t * setProperties(pn_message_t * message, char * stringProp, int intProp);
    void configureAzureSbMessage(pn_message_t * message, const char * label);
};