//
//  Material.cpp
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-25.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#include "Material.h"
#include "LambertBRDF.h"

shared_ptr<Material> Material::makeLambert(glm::vec3 color, glm::vec3 eCol)
{
  shared_ptr<BDF> brdf(new LambertBRDF(color));
  shared_ptr<Material> rMat(new Material(brdf, eCol));
  return rMat;
}
