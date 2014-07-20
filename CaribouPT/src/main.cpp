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

using namespace std::tr1;

int main()
{
    shared_ptr<Scene> scene(new Scene());
    shared_ptr<Image> image(new Image(480,320));

    Renderer r;
    r.render(scene, image);

    ImageWriter writer;
    writer.writePPM(image, "test.ppm");
}
