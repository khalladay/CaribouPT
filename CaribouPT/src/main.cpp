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
#include "Sphere.h"
#include "Cube.h"

using namespace std::tr1;

int main()
{
    Intersectable** sceneObjects = new Intersectable*[1];
    //sceneObjects[0] = new Cube(glm::vec3(0.0f, -5.0f, -25.0f),
      //                          glm::vec3(10.0f, 5.0f, -35.0f));
    sceneObjects[0] = new Sphere(5.0, glm::vec3(0.0f,0.0f,-15.0f) );

  //  {
    //  Sphere(10.0, glm::vec3(0.0f,0.0f,-20.0f) )
    //    new Plane(glm::vec3(0.0f, 0.0f, -20.0f), glm::vec3(0.0f, 0.0f, 1.0f))
  //  };


    shared_ptr<Scene> scene(new Scene(sceneObjects, 1));
    shared_ptr<Image> image(new Image(480,320));

    Renderer r;
    r.render(scene, image);

    ImageWriter writer;
    writer.writePPM(image, "test.ppm");
}
