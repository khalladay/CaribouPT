//
//  Renderer.h
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-18.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#ifndef __CaribouPT__Renderer__
#define __CaribouPT__Renderer__

#include <tr1/memory>
#include "glm.hpp"

class Scene;
class Ray;
class Image;

using namespace std::tr1;

class Renderer
{
public:
    Renderer(){}
    ~Renderer(){}

    void render(shared_ptr<Scene> scene, shared_ptr<Image> target);
    glm::vec3 traceRay(Ray* r);
    Ray rayForPixel(double ndcX, double ndcY);

private:
  shared_ptr<Scene> _scene;

};
#endif /* defined(__CaribouPT__Renderer__) */
