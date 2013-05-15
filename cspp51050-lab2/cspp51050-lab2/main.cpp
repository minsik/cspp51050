//
//  main.cpp
//  cspp51050-lab2
//
//  Created by Min on 5/9/13.
//  Copyright (c) 2013 cspp51050. All rights reserved.
//

#include <iostream>
#include <cstdarg>
#include "Client.h"
#include "Broker.h"
#include "ServerProxy.h"


void query(int, int);
void query(std::string);

int main(int argc, const char * argv[])
{
    query(5,5);
    query("this lab is hard");
    
    return 0;
}

void query(int x, int y){
    Broker clientBroker;
    Broker serverBroker;
    Client client;
    ClientProxy cProxy;
    ServerProxy sProxy;
    client.query(x, y);
    cProxy.proxyToBroker(client.sendToProxy(cProxy), clientBroker);
    clientBroker.sendToBroker(serverBroker, clientBroker.getString());
    serverBroker.brokerToProxy(sProxy);
    serverBroker.sendToBroker(clientBroker, serverBroker.getString());
    clientBroker.brokerToProxy(cProxy);
    std::cout<<"Result:"<<client.getResult()<<std::endl;
}

void query(std::string x){
    Broker clientBroker;
    Broker serverBroker;
    Client client;
    ClientProxy cProxy;
    ServerProxy sProxy;
    client.query(x);
    cProxy.proxyToBroker(client.sendToProxy(cProxy), clientBroker);
    clientBroker.sendToBroker(serverBroker, clientBroker.getString());
    serverBroker.brokerToProxy(sProxy);
    serverBroker.sendToBroker(clientBroker, serverBroker.getString());
    clientBroker.brokerToProxy(cProxy);
    std::cout<<"Result:"<<client.getResult()<<std::endl;
}
    
    //prints values during each step

    //sending client data to proxy which marshalls data
    //and sends it to the client broker
//**********
//    cProxy.proxyToBroker(client.sendToProxy(cProxy), clientBroker);
//**********
    
    //client broker sending converted string to server broker and
    //server broker converts it to call
//**********
//    clientBroker.sendToBroker(serverBroker, clientBroker.getString());
//**********
    
    //debugging
//    std::cout<<clientBroker.getString()<<std::endl;
//    std::cout<<serverBroker.getString()<<std::endl;
//    std::cout<<serverBroker.getCallName()<<std::endl;
//    std::cout<<serverBroker.getParamOne()<<std::endl;
//    std::cout<<serverBroker.getParamTwo()<<std::endl;
//    std::cout<<serverBroker.getResult()<<std::endl;
    
    //server broker calls server proxy, creates server, server runs,
    //server returns result to proxy and proxy marshalls,
    //sends call to server proxy, and converts call to string
//**********
//    serverBroker.brokerToProxy(sProxy);
//**********
    
    //send string to client broker and converts it into a call
//**********
//    serverBroker.sendToBroker(clientBroker, serverBroker.getString());
//**********
    
//    std::cout<<clientBroker.getResult()<<std::endl;
    
    //client broker sends call to proxy
//**********
//    clientBroker.brokerToProxy(cProxy);
//**********
    
    //client proxy sends result to client
//**********
//    std::cout<<"ANSWER:"<<client.getResult();
//**********
    
