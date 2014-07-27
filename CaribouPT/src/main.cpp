//
//  main.cpp
//  TestMakefileCLTool
//
//  Created by Kyle Halladay on 2014-07-14.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//
#include <omp.h>
#include <stdio.h>
#include "Scene.h"
#include <tr1/memory>
#include <string>
#include "Image.h"
#include "ImageWriter.h"
#include "Renderer.h"
#include "Primitive.h"
#include <vector>

using namespace std::tr1;

int main()
{
    std::vector<shared_ptr<Primitive> > sceneObjects;
    sceneObjects.push_back(Primitive::makeLambertSphere(5.0, glm::vec3(0.0f,0.0f,-15.0f), glm::vec3(1.0,0.2,0.2),glm::vec3(1.0,0.2,0.2)));
    //sceneObjects.push_back(Primitive::makeLambertCube(glm::vec3(0.0f, -5.0f, -25.0f),glm::vec3(10.0f, 5.0f, -35.0f), glm::vec3(1.0,1.0,1.0)));
   

    shared_ptr<Scene> scene(new Scene(sceneObjects));
    shared_ptr<Image> image(new Image(480,320));

    Renderer r;
    r.render(scene, image);

    ImageWriter writer;
    writer.writePPM(image, "test.ppm");
}
