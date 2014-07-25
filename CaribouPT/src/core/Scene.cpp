//
//  Scene.cpp
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-16.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#include "Scene.h"
#include "Intersectable.h"

bool Scene::intersect(const Ray* r, double& t, Intersection* isectData)
{

  if (_objectCount == 0) return false;

  double d;
  double inf = t = 1e20;

  for (int i = _objectCount-1; i > -1; i--)
  {
      d = _objects[i]->intersect(r);
      if (d > 0 && d < t)
      {
        t = d;
        isectData->normal = _objects[i]->normalAtPoint(r->o + r->d * r->t);
        isectData->hitObj = _objects[i];
      }
  }

  return t < inf;
}
