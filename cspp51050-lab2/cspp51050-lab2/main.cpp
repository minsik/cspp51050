//
//  main.cpp
//  cspp51050-lab2
//
//  Created by Min on 5/9/13.
//  Copyright (c) 2013 cspp51050. All rights reserved.
//

#include <iostream>
#include "Client.h"
#include "Broker.h"
#include "ServerProxy.h"

int clientQuery(){
    Broker clientBroker;
    Broker serverBroker;
    Client client;
    ClientProxy cProxy;
    ServerProxy sProxy;
    cProxy.proxyToBroker(client.sendToProxy(cProxy), clientBroker);
    clientBroker.sendToBroker(serverBroker, clientBroker.getString());
    serverBroker.brokerToProxy(sProxy);
    serverBroker.sendToBroker(clientBroker, serverBroker.getString());
    clientBroker.brokerToProxy(cProxy);
    std::cout<<"ANSWER:"<<client.getResult();
    return stoi(client.getResult());
}

int main(int argc, const char * argv[])
{
    clientQuery();
//    clientQuery(std::string a, std::string b, std::string c);
    

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
    
    return 0;
}

/*
1. broker starts
2. server starts and sends registration to broker
3. broker receives and registers server

4. client starts and invokes func on server via client proxy
5. client proxy takes data and marshals data
6. client proxy transmits data to broker
7. broker forwards data to server proxy
8. server proxy demarshalls data and calls func on server
9. server sends answer to server proxy
10. server proxy marshals data and sends to broker
11. broker forwards data to client proxy
12. client proxy demarshalls data and sends to client. 
*/