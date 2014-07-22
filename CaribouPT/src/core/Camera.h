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
#define GLM_FORCE_RADIANS
#include "ext.hpp"

class Camera
{
public:
    glm::mat4 transform;

    double fov;
    double near;
    double far;

    Camera(glm::vec3 position, glm::vec3 lookAt,
          double fieldOfView = 60.0, double near = 0.1, double far = 1000.0);

    ~Camera(){}
};
#endif /* defined(__CaribouPT__Camera__) */
