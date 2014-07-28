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
    Ray(glm::vec3 origin,glm::vec3 direction)
        {
          mint = 0.0;
          maxt = 100.0;
          o = origin;
          d = glm::normalize(direction);


          invd = glm::vec3(1.0/d.x, 1.0/d.y, 1.0/d.z);
          sign[0] = invd.x < 0;
          sign[1] = invd.y < 0;
          sign[2] = invd.z < 0;
        }

    void setDirection(glm::vec3 direction)
    {
        d = glm::normalize(direction);
        invd = glm::vec3(1.0/d.x, 1.0/d.y, 1.0/d.z);
        sign[0] = invd.x < 0;
        sign[1] = invd.y < 0;
        sign[2] = invd.z < 0;
    }
    ~Ray(){}

    glm::vec3 o;
    glm::vec3 d;

    //for speeding up collision tests
    glm::vec3 invd;
    int sign[3]; //sign is 1 if negative

    mutable float t;
    mutable float mint;
    mutable float maxt;
};

#endif /* defined(__CaribouPT__Ray__) */
