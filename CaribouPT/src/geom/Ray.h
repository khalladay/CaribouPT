//
//  Ray.h
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-17.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#ifndef __CaribouPT__Ray__
#define __CaribouPT__Ray__

#include "glm.hpp"

class Ray
{
public:
    Ray(glm::vec3 origin = glm::vec3(0.0),
        glm::vec3 direction = glm::vec3(0.0))
        : o(origin), d(direction){ mint = 0.0; maxt = 100.0;}
    ~Ray(){}

    glm::vec3 o;
    glm::vec3 d;
    mutable float mint;
    mutable float maxt;
};

#endif /* defined(__CaribouPT__Ray__) */
