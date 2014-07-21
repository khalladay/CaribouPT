//
//  Scene.h
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-16.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#ifndef __CaribouPT__Scene__
#define __CaribouPT__Scene__

#include "Ray.h"
#include "glm.hpp"

#include "Intersectable.h"
#include "Sphere.h"
#include "Camera.h"

class Scene
{
public:

    Scene(Intersectable* sceneObjects) : objects(sceneObjects)
    {
      cam = new Camera(glm::vec3(0.0), glm::vec3(1.0), 60.0);
    }
    ~Scene(){}

    bool intersect(const Ray& r);
    const Camera* cameraPointer()
    {
      return cam;
    }

private:
    Intersectable* objects;
    Camera* cam;
};

#endif /* defined(__CaribouPT__Scene__) */
