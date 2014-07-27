//
//  LambertBRDF.h
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-24.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#ifndef CaribouPT_LambertBRDF_h
#define CaribouPT_LambertBRDF_h

#include "BDF.h"
#define INV_PI 0.31830988618f

class LambertBRDF : public BDF
{
public:
    glm::vec3 R;
    
    LambertBRDF(){}
    LambertBRDF(glm::vec3 reflectCol) : R(reflectCol){}
    ~LambertBRDF(){}
    
    
    virtual glm::vec3 eval(const glm::vec3& w0, const glm::vec3& wi)
    {
        glm::vec3 r = R * INV_PI;
        return r;
    }

private:
    virtual glm::vec3 sample(const glm::vec3& w0, const glm::vec3& wi){}
};

#endif
