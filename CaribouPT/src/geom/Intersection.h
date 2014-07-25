//
//  Intersection.h
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-24.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#ifndef CaribouPT_Intersection_h
#define CaribouPT_Intersection_h

class Intersectable;

struct Intersection
{
public:
    float theta;
    Intersectable* hitObj;
};

#endif
