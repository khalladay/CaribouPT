//
//  Sphere.h
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-17.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#ifndef CaribouPT_Sphere_h
#define CaribouPT_Sphere_h

#include "Intersectable.h"
#include "glm.hpp"

class Sphere: public Intersectable
{
public:
    Sphere(double radius, glm::vec3 position) : rad(radius), rad2(radius*radius), pos(position), Intersectable(){}
    
    virtual bool intersect(const Ray* ray)
    {
        using namespace glm;
    
        vec3 L = pos - ray->o;
        double t2 = dot(L, ray->d);
        
        if (t2 < 0.0f) return false;
        
        double d2 = dot(L,L) - t2*t2;
        if (d2 > rad2) return false;
        
        double t3 = glm::sqrt(rad2 - d2);
        double t0 = t2-t3;
        
        if (t0 > ray->maxt) return false;
        
        return true;
    }
    
private:
    double rad;
    double rad2;
    glm::vec3 pos;
};

#endif
