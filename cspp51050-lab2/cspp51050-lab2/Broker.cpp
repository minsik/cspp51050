//
//  Broker.cpp
//  cspp51050-lab2
//
//  Created by Min on 5/9/13.
//  Copyright (c) 2013 cspp51050. All rights reserved.
//

#include "Broker.h"

//checks to see if server is running, if not, start it.
//maintain calls so it knows where to send replies

std::string Broker::getString(){
//    std::cout<<str;
    return str;
}

void Broker::setString(std::string s){
    str = s;
}

std::string Broker::callToString(CallMessage msg){
    str = "";
    str.append(msg.getCallName());
    str.append("###ENDATTR1###");
    str.append(msg.getParamOne());
    str.append("###ENDATTR2###");
    str.append(msg.getParamTwo());
    str.append("###ENDATTR3###");
    str.append(msg.getResult());
    str.append("###ENDATTR4###");
    str.append(msg.getClientAddr());
    return str;
}

CallMessage Broker::stringToCall(std::string s){
    int markStart = 0;
    int markEnd = 0;
    
    markStart = s.find("###ENDATTR1###", 0);
    callInRoute.setCallName(s.substr(0, markStart));
    markEnd = markStart + 14;
    markStart = s.find("###ENDATTR2###", 0);
    callInRoute.setParamOne(s.substr(markEnd, markStart-markEnd));
    markEnd = markStart + 14;
    markStart = s.find("###ENDATTR3###", 0);
    callInRoute.setParamTwo(s.substr(markEnd, markStart-markEnd));
    markEnd = markStart + 14;
    markStart = s.find("###ENDATTR4###", 0);
    callInRoute.setResult(s.substr(markEnd, markStart-markEnd));
    markEnd = markStart + 14;
    callInRoute.setClientAddr(s.substr(markEnd, s.length()-1));
    return callInRoute;
}

void Broker::sendToBroker(Broker & targetBroker, std::string s){
    targetBroker.receiveFromBroker(s);
}
void Broker::receiveFromBroker(std::string s){
    setString(s);
    stringToCall(s);
}

void Broker::brokerToProxy(ServerProxy sProxy){
    sProxy.callServer(callInRoute, *this);
}

void Broker::brokerToProxy(ClientProxy cProxy){
    cProxy.receiveCall(callInRoute);
}
void Broker::receiveCall(CallMessage msg){
    callInRoute.setCallName(msg.getCallName());
    callInRoute.setParamOne(msg.getParamOne());
    callInRoute.setParamTwo(msg.getParamTwo());
    callInRoute.setResult(msg.getResult());
    callInRoute.setClientAddr(msg.getClientAddr());
    callToString(msg);
}

std::string Broker::getCallName(){
    return callInRoute.getCallName();
}
std::string Broker::getParamOne(){
    return callInRoute.getParamOne();
}
std::string Broker::getParamTwo(){
    return callInRoute.getParamTwo();
}
std::string Broker::getResult(){
    return callInRoute.getResult();
}
std::string Broker::getClientAddr(){
    return callInRoute.getClientAddr();
}














