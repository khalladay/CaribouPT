//
//  Primitive.h
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-26.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#ifndef __CaribouPT__Primitive__
#define __CaribouPT__Primitive__

#include "Intersectable.h"
#include "Material.h"

class Primitive
{
public:
    Primitive(shared_ptr<Intersectable> shape, shared_ptr<Material> mat)
            :_shape(shape), _mat(mat){}
    ~Primitive(){}
    
    static shared_ptr<Primitive> makeLambertSphere(double radius, glm::vec3 position, glm::vec3 rColor, glm::vec3 eColor = glm::vec3(0.0));
    static shared_ptr<Primitive> makeMirrorSphere(double radius, glm::vec3 position, glm::vec3 rColor, glm::vec3 eColor = glm::vec3(0.0));

    static shared_ptr<Primitive> makeLambertCube(glm::vec3 min, glm::vec3 max, glm::vec3 rColor, glm::vec3 eColor = glm::vec3(0.0));
    
    shared_ptr<Intersectable> _shape;
    shared_ptr<Material> _mat;
};

#endif /* defined(__CaribouPT__Primitive__) */
