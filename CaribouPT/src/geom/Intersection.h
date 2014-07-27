//
//  Intersection.h
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-24.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#ifndef CaribouPT_Intersection_h
#define CaribouPT_Intersection_h
#include <tr1/memory>
#include "Primitive.h"
class Primitive;

struct Intersection
{
public:
    glm::vec3 normal;
    std::tr1::shared_ptr<Primitive> hitObj;
};

#endif
