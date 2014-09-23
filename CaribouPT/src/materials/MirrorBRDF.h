//
//  MirrorBRDF.h
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-09-21.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#ifndef CaribouPT_MirrorBRDF_h
#define CaribouPT_MirrorBRDF_h

#include "BDF.h"

class MirrorBRDF : public BDF
{
public:
    glm::vec3 R;
    
    MirrorBRDF(){}
    MirrorBRDF(glm::vec3 reflectCol) : R(reflectCol){}
    ~MirrorBRDF(){}
    
    
    virtual glm::vec3 eval(const glm::vec3& w0, const glm::vec3& wi)
    {
        glm::vec3 r = R * INV_PI;
        return r;
    }
    
    virtual int getReflType()
    {
        return kReflTypeMirror;
    }
    
private:
    virtual glm::vec3 sample(const glm::vec3& w0, const glm::vec3& wi){}
};

#endif