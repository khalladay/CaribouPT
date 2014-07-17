//
//  Scene.h
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-16.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#ifndef __CaribouPT__Scene__
#define __CaribouPT__Scene__
#include <stdio.h>
#include "glm.hpp"
class Scene 
{
public:
    
    Scene()
    {
        glm::vec3 v(0.5f, 0.0f,0.0f);
        printf("Scene vec x: %f\n", v.x);
    }
    ~Scene(){}
};

#endif /* defined(__CaribouPT__Scene__) */
