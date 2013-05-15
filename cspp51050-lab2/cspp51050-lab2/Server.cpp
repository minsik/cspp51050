//
//  Server.cpp
//  cspp51050-lab2
//
//  Created by Min on 5/9/13.
//  Copyright (c) 2013 cspp51050. All rights reserved.
//

#include "Server.h"

//after creation, must tell server of its location0

long Server::addIntegers(std::string x, std::string y){
    return std::stol(x)+std::stol(y);
}

long Server::getLength(std::string s){
    return s.length();
}