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

void Renderer::render(shared_ptr<Scene> scene, shared_ptr<Image> target)
{
  _scene = scene;
  double fov = tan(_scene->cam()->fov / 2.0);

  //parallelize this loop, 1 iteration per thread
  //division of work done at runtime since image size isn't known
  #pragma omp parallel for schedule(dynamic, 1) collapse(2)
  for (int y = 0; y < target->h; y++)
  {
    for (int x = 0; x < target->w; x++)
    {
      double ssX =  (x + 0.5) / (float)target->w;
      double ssY =  (y + 0.5) / (float)target->w;

      double ndcX = (2 * ssX - 1) * ((float)target->w/(float)target->h) * fov;
      double ndcY = (1 - 2 * ssY) * fov;

      int i = y * target->w + x;

      Ray r = rayForPixel(ndcX, ndcY);
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
  int id = -1;

  if (_scene->intersect(r, t, id))
  {
    return glm::vec3(1.0);
  }

  return glm::vec3(0.0);
}

Ray Renderer::rayForPixel(double ndcX, double ndcY)
{
  using namespace glm;

  //camera looks down the cam space -z
  //cam is 1 unit away from the cam plane (at z -1)
  Ray r;

  vec4 origin = _scene->cam()->transform * vec4(0.0f, 0.0f, 0.0f, 1.0f);
  vec4 camSpacePixel = _scene->cam()->transform * vec4(ndcX, ndcY, -1.0f, 1.0f);

  vec4 dir = normalize(camSpacePixel - origin);

  r.o = vec3(origin.x, origin.y, origin.z);
  r.d = vec3(dir.x, dir.y, dir.z);
  r.mint = _scene->cam()->near;
  r.maxt = _scene->cam()->far;

  return r;
}
