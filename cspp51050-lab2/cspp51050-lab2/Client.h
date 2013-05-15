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
    bool setCallName(long);
    void setResult(std::string);
    CallMessage sendToProxy(ClientProxy);
    std::string getResult();
};

#endif /* defined(__cspp51050_lab2__Client__) */
