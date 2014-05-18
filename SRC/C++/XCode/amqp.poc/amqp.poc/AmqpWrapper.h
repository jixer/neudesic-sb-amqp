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

#endif /* defined(__amqp_poc__AmqpWrapper__) */

class AmqpWrapper {
public:
    AmqpWrapper();
    void SendMessage(char* message);
private:
    char * amqpAddress;
};