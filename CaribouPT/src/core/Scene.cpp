//
//  Scene.cpp
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-16.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#include "Scene.h"
#include "Intersectable.h"
#include "Primitive.h"

Scene::Scene(std::vector<shared_ptr<Primitive> > sceneObjects)
: _objects(sceneObjects)
{
    _cam = new Camera(glm::vec3(10.0,0.0,10.0), glm::vec3(0.0,0.0,-15.0), 60.0);
}

bool Scene::intersect(const Ray* r, double& t, Intersection* isectData)
{
    if (_objects.size() == 0) return false;

    double d;
    double inf = t = 1e20;

    for (int i = _objects.size()-1; i > -1; i--)
    {
        if (_objects[i]->_shape->intersect(r))
        {
            if (r->t > 0 && r->t < t)
            {
                t = r->t;
                isectData->normal = _objects[i]->_shape->normalAtPoint(r->o + r->d * r->t);
                isectData->hitObj = _objects[i];
            }
        }
    }

    return t < inf;
}
