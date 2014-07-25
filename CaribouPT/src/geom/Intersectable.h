//
//  Intersectable.h
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-17.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#ifndef CaribouPT_Intersectable_h
#define CaribouPT_Intersectable_h

#include "Ray.h"
#include "Intersection.h"
#include "BDF.h"

class Intersectable
{
public:
    virtual bool intersect(const Ray* ray) = 0;
    virtual glm::vec3 normalAtPoint(const glm::vec3 point) = 0;
};

#endif
