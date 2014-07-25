//
//  Renderer.cpp
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-18.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#include "Renderer.h"
#include <omp.h>
#include <stdio.h>
#include <math.h>
#include "Scene.h"
#include "Image.h"
#include "Ray.h"
#include "Intersection.h"

void Renderer::render(shared_ptr<Scene> scene, shared_ptr<Image> target)
{
  _scene = scene;

  const double deg2rad = 0.0174532925;

  double fov = tan( (_scene->cam()->fov/ 2.0) * deg2rad);
  double aspect;

  if (target->w >= target->h)
  {
    aspect = ((double)target->w/(double)target->h);
  }
  else
  {
    aspect = ((double)target->h/(double)target->w);
  }

  //parallelize this loop, 1 iteration per thread
  //division of work done at runtime since image size isn't known
  #pragma omp parallel for schedule(dynamic, 1) collapse(2)
  for (int y = 0; y < target->h; y++)
  {
    for (int x = 0; x < target->w; x++)
    {
      double pixX =  (x + 0.5);
      double pixY =  (y + 0.5);

      pixX = (2 * pixX / (double)target->w - 1) * aspect * fov;
      pixY = (1 - 2 * pixY / (double)target->h) * fov;

      int i = y * target->w + x;

      Ray r = rayForPixel(pixX, pixY);
      glm::vec3 col = traceRay(&r);

      target->pixels[i*3] = col.x;
      target->pixels[i*3+1] = col.y;
      target->pixels[i*3+2] = col.z;
    }
  }
}

glm::vec3 Renderer::traceRay(Ray* r)
{
  double t = r->maxt;

  Intersection isect;

  if (!_scene->intersect(r, t, &isect))
  {
      glm::vec3(0.0);
  }

  return glm::vec3(isect.normal.x, isect.normal.y, isect.normal.z);
}

Ray Renderer::rayForPixel(double ndcX, double ndcY)
{
  using namespace glm;

  //camera looks down the cam space -z
  //cam is 1 unit away from the cam plane (at z -1)

  vec4 origin = _scene->cam()->transform * vec4(0.0f, 0.0f, 0.0f, 1.0f);
  vec4 camSpacePixel = _scene->cam()->transform * vec4(ndcX, ndcY, -1.0f, 1.0f);

  vec4 dir = normalize(camSpacePixel - origin);

  Ray r ( vec3(origin.x, origin.y, origin.z), vec3(dir.x, dir.y, dir.z));

  r.mint = _scene->cam()->near;
  r.maxt = _scene->cam()->far;

  return r;
}
