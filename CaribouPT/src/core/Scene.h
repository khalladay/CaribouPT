//
//  Scene.h
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-16.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#ifndef __CaribouPT__Scene__
#define __CaribouPT__Scene__

#include "glm.hpp"
#include "Camera.h"
#include "Intersection.h"
#include <tr1/memory>
#include <vector>

class Primitive;
class Ray;

using namespace std::tr1;

class Scene
{
public:

    Scene(std::vector<shared_ptr<Primitive> > sceneObjects);
    ~Scene(){}

    bool intersect(const Ray* r, double& t, Intersection* isectData);

    const Camera* cam()
    {
        return _cam;
    }

private:
    
    std::vector<shared_ptr<Primitive> > _objects;
    Camera* _cam;
};

#endif /* defined(__CaribouPT__Scene__) */
