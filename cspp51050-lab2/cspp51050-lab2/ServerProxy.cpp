//
//  ServerProxy.cpp
//  cspp51050-lab2
//
//  Created by Min on 5/9/13.
//  Copyright (c) 2013 cspp51050. All rights reserved.
//

#include "ServerProxy.h"
#include "Broker.h"

//receive callMessage, unmarshall callMessage, call appropriate service on server
//marshall service, handle exceptions

int ServerProxy::callServer(CallMessage msg, Broker & b){
    Server servant;
    
    std::string callOne = "addIntegers";
    std::string callTwo = "getLength";
    
    if (msg.getCallName().compare(callOne) == 0){
        std::cout<<"running addIntegers\n";
        std::string result = longToString(servant.addIntegers(msg.getParamOne(),
                                                              msg.getParamTwo()));
        msg.setResult(result);
        proxyToBroker(msg, b);
        return 0;
        
    }
    if (msg.getCallName().compare(callTwo) == 0){
        std::cout<<"running getLength\n";
        std::string result = longToString(servant.getLength(msg.getParamOne()));
        msg.setResult(result);
        proxyToBroker(msg, b);
        return 0;
    }
    else{
        std::string result = "Call failed";
        std::cout<<result<<std::endl;
        msg.setResult(result);
        proxyToBroker(msg, b);
        return 0;
    }
}

void ServerProxy::proxyToBroker(CallMessage msg, Broker & b){
    b.receiveCall(msg);
}

//From http://stackoverflow.com/a/947636
std::string ServerProxy::longToString(long n){
    std::string number;
    std::stringstream strstream;
    strstream << n;
    strstream >> number;
    return number;
}
