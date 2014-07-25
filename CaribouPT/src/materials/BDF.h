//
//  BDF.h
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-24.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#ifndef CaribouPT_BDF_h
#define CaribouPT_BDF_h

#include "glm.hpp"

class BDF
{
public:
    virtual glm::vec3 eval(const glm::vec3& w0, const glm::vec3& wi) = 0;
    virtual glm::vec3 sample(const glm::vec3& w0, const glm::vec3& wi) = 0;
    ~BDF(){}

};

#endif
