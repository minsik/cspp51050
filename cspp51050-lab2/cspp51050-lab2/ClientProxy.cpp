//
//  ClientProxy.cpp
//  cspp51050-lab2
//
//  Created by Min on 5/9/13.
//  Copyright (c) 2013 cspp51050. All rights reserved.
//

#include "ClientProxy.h"
#include "Client.h"
#include "Broker.h"

//marshall input into callMessage

void ClientProxy::proxyToBroker(CallMessage msg, Broker & b){
    b.receiveCall(msg);
//    b.callToString(msg);
};

CallMessage ClientProxy::marshallCall(std::string a,std::string b,std::string c,std::string d,std::string e){
    CallMessage msg;
    msg.setCallName(a);
    msg.setParamOne(b);
    msg.setParamTwo(c);
    msg.setResult(d);
    msg.setClientAddr(e);

    return msg;
}

void ClientProxy::receiveCall(CallMessage msg){
    CallMessage callToClient;
    callToClient.setCallName(msg.getCallName());
    callToClient.setParamOne(msg.getParamOne());
    callToClient.setParamTwo(msg.getParamTwo());
    callToClient.setResult(msg.getResult());
    callToClient.setClientAddr(msg.getClientAddr());
    
    long clientPointer = std::stol(msg.getClientAddr(), NULL, 0);
    Client * clientPt = reinterpret_cast<Client *>(clientPointer);
    
    proxyToClient(clientPt, msg.getResult());
}

void ClientProxy::proxyToClient(Client * c, std::string s){
    c->setResult(s);
}


//const void * address = static_cast<const void*>(this);
//std::stringstream ss;
//ss << address;
//clientAddr = ss.str();


