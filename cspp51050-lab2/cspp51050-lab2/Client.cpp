//
//  Client.cpp
//  cspp51050-lab2
//
//  Created by Min on 5/9/13.
//  Copyright (c) 2013 cspp51050. All rights reserved.
//

#include "Client.h"

Client::Client(){
    //test code with hardcoded input
    callName = "getLength";
    paramOne = "hello";
    paramTwo = "";
    
    Client * clientPointer = this;
    long longPointer=reinterpret_cast<long>(clientPointer);
    clientAddr = std::to_string(longPointer);
    
//    Client * orig = reinterpret_cast<Client *>(longPointer);

//    std::cout<<longPointer<<std::endl;
//    std::cout<<clientAddr<<std::endl;
//    std::cout<<orig<<std::endl;

}

void Client::setResult(std::string s){
    result = s;
}

std::string Client::getResult(){
    return result;
}
CallMessage Client::sendToProxy(ClientProxy cProxy){
    result = "";
    return cProxy.marshallCall(callName, paramOne, paramTwo, result, clientAddr);
}


bool Client::setCallName(long n){
    if (n == 1) {
        callName = "addIntegers";
        return 1;
    }
    if (n == 2) {
        callName = "getLength";
        return 1;
    }
    else {
        std::cout<<"Invalid entry. Please enter 1 or 2.: ";
        return 0;
    }
}

//void Client::run(){
//    std::cout<<"Please choose a function to run:\n1. add two integers 2. calculate the length of a string"<<std::endl;
//    int n = -1;
//    std::cin>>n;
//    while (!setCallName(n)){
//        run();
//    }
//}

/*
 
 bool Client::setCallName(std::string s){
 std::string one = "1";
 std::string two = "1";
 
 if (one.compare(s) == 0){
 callName = "addIntegers";
 return 1;
 }
 if (two.compare(s) == 0){
 callName = "getLength";
 return 1;
 }
 else {
 std::cout<<"Invalid entry. Please enter 1 or 2. ";
 return 0;
 }
 }
 
 void Client::run(){
 std::cout<<"Please choose a function to run:\n1. add two integers 2. calculate the length of a string"<<std::endl;
 int n = -1;
 char * c = NULL;
 std::cin.get(c);
 while (!setCallName(n)){
 run();
 }
 }
 */