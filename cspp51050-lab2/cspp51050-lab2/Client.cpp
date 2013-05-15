//
//  Client.cpp
//  cspp51050-lab2
//
//  Created by Min on 5/9/13.
//  Copyright (c) 2013 cspp51050. All rights reserved.
//

#include "Client.h"

Client::Client(){
    callName = "";
    paramOne = "";
    paramTwo = "";
    result = "";
    
    Client * clientPointer = this;
    long longPointer=reinterpret_cast<long>(clientPointer);
    clientAddr = std::to_string(longPointer);
}

long Client::query(int x, int y){
    callName = "addIntegers";
    paramOne = std::to_string(x);
    paramTwo = std::to_string(y);
}

long Client::query(std::string s){
    callName = "getLength";
    paramOne = s;
}

CallMessage Client::sendToProxy(ClientProxy cProxy){
    return cProxy.marshallCall(callName, paramOne, paramTwo, result, clientAddr);
}

void Client::setCallName(std::string s){
    result = s;
}
void Client::setParamOne(std::string s){
    result = s;
}
void Client::setParamTwo(std::string s){
    result = s;
}
void Client::setResult(std::string s){
    result = s;
}
std::string Client::getCallName(){
    return callName;
}
std::string Client::getParamOne(){
    return paramOne;
}
std::string Client::getParamTwo(){
    return paramTwo;
}
std::string Client::getResult(){
    return result;
}
