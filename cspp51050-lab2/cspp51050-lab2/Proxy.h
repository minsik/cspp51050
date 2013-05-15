//
//  Proxy.h
//  cspp51050-lab2
//
//  Created by Min on 5/14/13.
//  Copyright (c) 2013 cspp51050. All rights reserved.
//

#ifndef __cspp51050_lab2__Proxy__
#define __cspp51050_lab2__Proxy__

#include <iostream>
#include "CallMessage.h"

class Broker;
class Proxy{
private:
public:
    virtual void proxyToBroker(CallMessage, Broker &);

#endif /* defined(__cspp51050_lab2__Proxy__) */
