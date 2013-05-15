//
//  CallMessage.cpp
//  cspp51050-lab2
//
//  Created by Min on 5/13/13.
//  Copyright (c) 2013 cspp51050. All rights reserved.
//

#include "CallMessage.h"

CallMessage::CallMessage() : callName(""), paramOne(""), paramTwo(""), result(""), clientAddr(""){};

std::string CallMessage::getCallName(){
    return callName;
}
std::string CallMessage::getParamOne(){
    return paramOne;
}
std::string CallMessage::getParamTwo(){
    return paramTwo;
}
std::string CallMessage::getResult(){
    return result;
}
std::string CallMessage::getClientAddr(){
    return clientAddr;
}
void CallMessage::setCallName(std::string s){
    callName = s;
}
void CallMessage::setParamOne(std::string s){
    paramOne = s;
}
void CallMessage::setParamTwo(std::string s){
    paramTwo = s;
}
void CallMessage::setResult(std::string s){
    result = s;
}
void CallMessage::setClientAddr(std::string s){
    clientAddr = s;
}

//void CallMessage::setParamOne(long n){
//    paramOne = longToString(n);
//}
////From http://stackoverflow.com/a/947636
//std::string CallMessage::longToString(long n){
//std::string number;
//std::stringstream strstream;
//strstream << n;
//strstream >> number;
//    return number;
//}
