//
//  CallMessage.h
//  cspp51050-lab2
//
//  Created by Min on 5/13/13.
//  Copyright (c) 2013 cspp51050. All rights reserved.
//

#ifndef __cspp51050_lab2__CallMessage__
#define __cspp51050_lab2__CallMessage__

#include <iostream>
#include <string>
#include <sstream>

class CallMessage{
private:
    std::string callName;
    std::string paramOne;
    std::string paramTwo;
    std::string result;
    std::string clientAddr;
public:
    CallMessage();
    std::string getCallName();
    std::string getParamOne();
    std::string getParamTwo();
    std::string getResult();
    std::string getClientAddr();
    void setCallName(std::string);
    void setParamOne(std::string);
    void setParamTwo(std::string);
    void setResult(std::string);
    void setClientAddr(std::string);
    
//    //From http://stackoverflow.com/a/947636
//    std::string longToString(long);
};

#endif /* defined(__cspp51050_lab2__CallMessage__) */
