//
//  Client.h
//  cspp51050-lab2
//
//  Created by Min on 5/9/13.
//  Copyright (c) 2013 cspp51050. All rights reserved.
//

#ifndef __cspp51050_lab2__Client__
#define __cspp51050_lab2__Client__

#include <iostream>
#include <sstream>
#include <string>
#include <cstdarg>
#include "ClientProxy.h"

class Client{
private:
    std::string callName;
    std::string paramOne;
    std::string paramTwo;
    std::string result;
    std::string clientAddr;
public:
    Client();
    
    //create separate constructor for each server function call
    long query(int,int);
    long query(std::string);

    CallMessage sendToProxy(ClientProxy);
    void setCallName(std::string);
    void setParamOne(std::string);
    void setParamTwo(std::string);
    void setResult(std::string);
    std::string getCallName();
    std::string getParamOne();
    std::string getParamTwo();
    std::string getResult();
    
//    void getInput(int num, ...);
};

#endif /* defined(__cspp51050_lab2__Client__) */