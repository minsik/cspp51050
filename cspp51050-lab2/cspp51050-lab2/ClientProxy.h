//
//  ClientProxy.h
//  cspp51050-lab2
//
//  Created by Min on 5/9/13.
//  Copyright (c) 2013 cspp51050. All rights reserved.
//

#ifndef __cspp51050_lab2__ClientProxy__
#define __cspp51050_lab2__ClientProxy__

#include <iostream>
#include "CallMessage.h"
#include <cstdlib>

class Client;
class Broker;
class ClientProxy {
private:
public:
    CallMessage marshallCall(std::string,std::string,std::string,std::string,std::string);
    void proxyToBroker(CallMessage, Broker &);
    void receiveCall(CallMessage);
    void proxyToClient(Client *, std::string);
};

#endif /* defined(__cspp51050_lab2__ClientProxy__) */
