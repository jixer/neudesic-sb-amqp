//
//  main.cpp
//  amqp.poc
//
//  Created by Chris' Mac on 5/17/14.
//
//

#include <proton/message.h>
#include <proton/messenger.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>

#include "AmqpWrapper.h"

#define check(messenger)                                                     \
{                                                                          \
    if(pn_messenger_errno(messenger))                                        \
    {                                                                        \
        die(__FILE__, __LINE__, pn_error_text(pn_messenger_error(messenger))); \
    }                                                                        \
}


int main(int argc, const char * argv[])
{
    AmqpWrapper* wrapper = new AmqpWrapper();
    char * msgtext = (char *) argv[0];
    
    wrapper->SendMessage(msgtext);
    
    delete wrapper;
    return 0;
}

