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
#include "math_utils.h"

#define DEG2RAD 0.0174532925

Renderer::Renderer()
{
    randGen.seed((unsigned int)time(NULL));
}

void Renderer::render(shared_ptr<Scene> scene, shared_ptr<Image> target, int samplesPerPixel)
{
    _scene = scene;
    uniform_real<float> randDist(0.0,1.0);

    double fov = tan( (_scene->cam()->fov/ 2.0) * DEG2RAD);
    double aspect;

    if (target->w >= target->h)
    {
        aspect = ((double)target->w/(double)target->h);
    }
    else
    {
        aspect = ((double)target->h/(double)target->w);
    }
    
    glm::vec3 col = glm::vec3(0.0);

    #pragma omp for schedule(dynamic) collapse(2)
    for (int y = 0; y < target->h; y++)
    {
        for (int x = 0; x < target->w; x++)
        {
            int i = y * target->w + x;
            col = glm::vec3(0.0);
            for (int s = 0; s < samplesPerPixel; s++)
            {
                double pixX =  (x + 0.5);
                double pixY =  (y + 0.5);

                pixX = (2 * pixX / (double)target->w - 1) * aspect * fov;
                pixY = (1 - 2 * pixY / (double)target->h) * fov;

                Ray r = rayForPixel(pixX, pixY);
                col = col + (traceRay(&r, 1, randDist) * (1.0f/(float)samplesPerPixel));
            }

            target->pixels[i*3] = clampZeroOne(col.x);
            target->pixels[i*3+1] = clampZeroOne(col.y);
            target->pixels[i*3+2] = clampZeroOne(col.z);
        }
    }
}

glm::vec3 Renderer::traceRay(Ray* r, int depth, uniform_real<float>& rDist)
{
    using namespace glm;

    double t = r->maxt;

    Intersection isect;

    if (!_scene->intersect(r, t, &isect))
    {
        return glm::vec3(0.0,0.5,0.0);
    }
    
    //todo: add russian roulette
    if (depth > 5)
    {
        return isect.hitObj->_mat->_eCol;
    }

    vec3 em = isect.hitObj->_mat->_eCol;
    vec3 hitPoint = r->o + r->d * r->t;
    vec3 normal =isect.hitObj->_shape->normalAtPoint(hitPoint);
    vec3 nl = glm::dot(normal, r->d) < 0 ? normal : normal * -1.0f;
    
    float cosTheta = glm::dot(nl, r->d);
    
    float r1=2*M_PI*rDist(randGen);
    float r2=rDist(randGen);
    float r2s=glm::sqrt(r2);
    
    vec3 w = nl;
    vec3 u = (fabs(w.x) > 0.1) ? vec3(0.0,1.0,0.0) : vec3(1.0, 0.0, 0.0);
    u = normalize( cross ( u, w));
    vec3 v = cross(w,u);
    

    vec3 brdf = isect.hitObj->_mat->getBRDF()->eval(r->d, r->d);

    r->o = hitPoint;
    r->setDirection(normalize(u * cos(r1)*r2s + v*sin(r1)*r2s + w * glm::sqrt(1-r2)));
    
    return em + ( brdf * traceRay(r, ++depth, rDist) );
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
