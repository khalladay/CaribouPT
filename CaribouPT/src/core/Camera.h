//
//  Camera.h
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-17.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#ifndef __CaribouPT__Camera__
#define __CaribouPT__Camera__

#include "glm.hpp"

class Camera
{
public:
    glm::vec3 pos;
    glm::vec3 look;
    
    glm::vec3 right;
    glm::vec3 up;
    
    Camera(glm::vec3 position, glm::vec3 direction) : pos(position), look(direction){}
    ~Camera(){}
};
#endif /* defined(__CaribouPT__Camera__) */
