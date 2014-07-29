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
   // sceneObjects.push_back(Primitive::makeLambertSphere(3.0,glm::vec3(0.0f, 0.0f, -15.0f),glm::vec3(1.0,1.0,1.0)));

    //back wall
    sceneObjects.push_back(Primitive::makeLambertCube(glm::vec3(-20.0f, -10.0f, -26.0f),glm::vec3(20.0f, 10.0f, -25.0f), glm::vec3(1.0,0.0,0.0)));
    
    //ceiling light
    sceneObjects.push_back(Primitive::makeLambertCube(glm::vec3(-4.0f, 9.8f, -15.0f),glm::vec3(4.0f, 11.0f, -7.0f), glm::vec3(1.0,1.0,1.0),glm::vec3(1.0,1.0,1.0)));
   
    //ceiling
    sceneObjects.push_back(Primitive::makeLambertCube(glm::vec3(-20.0f, 10.0f, -25.0f),glm::vec3(20.0f, 11.0f, 21.0f), glm::vec3(1.0,1.0,1.0)));

    //floor
    sceneObjects.push_back(Primitive::makeLambertCube(glm::vec3(-20.0f, -11.0f, -25.0f),glm::vec3(20.0f, -10.0f, 21.0f), glm::vec3(1.0,1.0,1.0)));
    
    //left wall
    sceneObjects.push_back(Primitive::makeLambertCube(glm::vec3(-21.0f, -10.0f, -25.0f),glm::vec3(-20.0f, 10.0f, 21.0f), glm::vec3(0.0,0.0,1.0)));

    //right wall
    sceneObjects.push_back(Primitive::makeLambertCube(glm::vec3(20.0f, -10.0f, -25.0f),glm::vec3(21.0f, 10.0f, 21.0f), glm::vec3(0.0,1.0,0.0)));
    
    //front wall
    sceneObjects.push_back(Primitive::makeLambertCube(glm::vec3(-20.0f, -10.0f, 20.0f),glm::vec3(20.0f, 10.0f, 21.0f), glm::vec3(1.0,0.0,0.0)));


    shared_ptr<Scene> scene(new Scene(sceneObjects));
    shared_ptr<Image> image(new Image(800,600));

    Renderer r;
    r.render(scene, image, 8);

    ImageWriter writer;
    writer.writePPM(image, "test.ppm");
}
