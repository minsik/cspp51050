//
//  Proxy.cpp
//  cspp51050-lab2
//
//  Created by Min on 5/14/13.
//  Copyright (c) 2013 cspp51050. All rights reserved.
//

#include "Proxy.h"
#include "Broker.h"

void Proxy::proxyToBroker(CallMessage msg, Broker & b){
    b.receiveCall(msg);
}