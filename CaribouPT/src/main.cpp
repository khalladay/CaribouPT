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
#include "Image.h"

int main()
{
    Image* s = new Image(480,320);
    printf("Hello! %f", s->pixelData[0]);
}