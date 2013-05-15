//
//  ServerProxy.h
//  cspp51050-lab2
//
//  Created by Min on 5/9/13.
//  Copyright (c) 2013 cspp51050. All rights reserved.
//

#ifndef __cspp51050_lab2__ServerProxy__
#define __cspp51050_lab2__ServerProxy__

#include <iostream>
#include "CallMessage.h"
#include "Server.h"

class Broker;
class ServerProxy{
private:
public:
    int callServer(CallMessage, Broker &);
    void proxyToBroker(CallMessage, Broker &);
    
    //From http://stackoverflow.com/a/947636
    std::string longToString(long);
};
#endif /* defined(__cspp51050_lab2__ServerProxy__) */
