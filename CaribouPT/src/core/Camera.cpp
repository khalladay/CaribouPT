//
//  Camera.cpp
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-17.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#include "Camera.h"

 Camera::Camera(glm::vec3 position, glm::vec3 lookPoint,
               double fieldOfView, double n,
               double f) : fov(fieldOfView), near(n), far(f)
{
  using namespace glm;

  //todo - fix up vector so it isn't hard coded.
  transform = inverse(glm::lookAt(position, lookPoint, vec3(0.0,1.0,0.0)));
}
