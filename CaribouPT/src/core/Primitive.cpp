//
//  Primitive.cpp
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-26.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#include "Primitive.h"
#include "Sphere.h"
#include "Cube.h"
#include "Material.h"

shared_ptr<Primitive> Primitive::makeLambertSphere(double radius, glm::vec3 position, glm::vec3 rColor, glm::vec3 eColor)
{
    shared_ptr<Sphere> shape(new Sphere(radius, position));
    printf("%f %f %f\n", rColor.x, rColor.y, rColor.z);
    shared_ptr<Primitive> prim(new Primitive(shape, Material::makeLambert(rColor, eColor)));
    return prim;
}

shared_ptr<Primitive> Primitive::makeLambertCube(glm::vec3 min, glm::vec3 max, glm::vec3 rColor, glm::vec3 eColor)
{
    shared_ptr<Cube> shape(new Cube(min, max));
    shared_ptr<Primitive> prim(new Primitive(shape, Material::makeLambert(rColor, eColor)));
    return prim;
}