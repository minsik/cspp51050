//
//  Broker.h
//  cspp51050-lab2
//
//  Created by Min on 5/9/13.
//  Copyright (c) 2013 cspp51050. All rights reserved.
//

#ifndef __cspp51050_lab2__Broker__
#define __cspp51050_lab2__Broker__

#include <iostream>
#include "CallMessage.h"
#include "ServerProxy.h"
#include "ClientProxy.h"

class Broker{
private:
    std::string str;
    CallMessage callInRoute;
public:
    std::string getString();
    void setString(std::string);
    std::string callToString(CallMessage);
    CallMessage stringToCall(std::string);
    void sendToBroker(Broker &, std::string);
    void receiveFromBroker(std::string);
    void brokerToProxy(ServerProxy);
    void brokerToProxy(ClientProxy);
    CallMessage * getCall();
    void receiveCall(CallMessage);
    
    //check data in call
    std::string getCallName();
    std::string getParamOne();
    std::string getParamTwo();
    std::string getResult();
    std::string getClientAddr();

};

#endif /* defined(__cspp51050_lab2__Broker__) */

//Proxy -> [CallMessage] -> Broker -> [string] -> transport -> [string] -> Broker -> [CallMessage] -> Proxy

