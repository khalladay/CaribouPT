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
    glm::mat4 transform;

    double fov;

    Camera(glm::vec3 position, glm::vec3 lookAt, double fieldOfView = 60.0)
          : fov(fieldOfView){}

    ~Camera(){}
};
#endif /* defined(__CaribouPT__Camera__) */
