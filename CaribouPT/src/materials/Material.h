//
//  Material.h
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-25.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//


/* this class will eventually provide an interface
 * for accessing multiple BSDFs, for now it just holds
 * an object's BRDF */

#ifndef __CaribouPT__Material__
#define __CaribouPT__Material__

#include "BDF.h"
#include <tr1/memory>
#include "glm.hpp"

using namespace std::tr1;

class Material
{
public:
    Material(shared_ptr<BDF> brdf, glm::vec3 eCol) : _brdf(brdf), _eCol(eCol){}

    const shared_ptr<BDF> getBRDF()
    {
        return _brdf;
    }

    static shared_ptr<Material> makeLambert(glm::vec3 color, glm::vec3 eColor);

    shared_ptr<BDF> _brdf;
    glm::vec3 _eCol;

};
#endif /* defined(__CaribouPT__Material__) */
