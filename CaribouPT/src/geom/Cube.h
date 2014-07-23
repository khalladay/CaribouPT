//
//  Cube.h
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-18.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#ifndef CaribouPT_Cube_h
#define CaribouPT_Cube_h

#include "Intersectable.h"

class Cube : public Intersectable
{
public:
  glm::vec3 bounds[2];

  Cube(glm::vec3 _min, glm::vec3 _max) : Intersectable()
  {
    bounds[0] = _min;
    bounds[1] = _max;
  }

  ~Cube(){}

  virtual bool intersect(const Ray* ray)
  {
    double tmin; //t value in O + rt to reach box minimum
    double tmax; //largest t value that will hit box

    double tymin, tymax, tzmin, tzmax;

    //the following uses the sign to determine which
    //bound is min/max. Normally this is done by checking
    //if the ray's direction is negative and then choosing
    //a bound but this is faster.
    //truesculpt.googlecode.com/hg-history/Release%25200.8/Doc/ray_box_intersect.pdf

    tmin = (bounds[ray->sign[0]].x - ray->o.x) * ray->invd.x;
    tmax = (bounds[1 - ray->sign[0]].x - ray->o.x) * ray->invd.x;

    tymin = (bounds[ray->sign[1]].y - ray->o.y) * ray->invd.y;
    tymax = (bounds[1 - ray->sign[1]].y - ray->o.y) * ray->invd.y;


    //once we define which is the min and the max, we can
    //check for the t value to intersect with the faces that touch
    //the min and max point.
    //because all of the dimensions of the max are > than the dimensions
    //of the min, if any tmin values are > than a tmax value, no collision
    //negative values occur when a collision is behind the ray.

    if (tmin > tymax || tmax < tymin)
    {
        return false;
    }

    if (tymin > tmin) tmin = tymin;
    if (tymax < tmax) tmax = tymax;

    tzmin = (bounds[ray->sign[2]].z - ray->o.z) * ray->invd.z;
    tzmax = (bounds[1 - ray->sign[2]].z - ray->o.z) * ray->invd.z;

    if (tmin > tzmax || tmax < tzmin)
    {
      return false;
    }

    if (tzmin > tmin) tmin = tzmin;
    if (tzmax < tmax) tmax = tzmax;

    if ( (tmin < ray->maxt) && (tmax > ray->mint) )
    {
      return true;
    }

    return false;
  }

};


#endif
