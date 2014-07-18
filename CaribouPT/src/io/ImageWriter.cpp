//
//  ImageWriter.cpp
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-17.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#include "ImageWriter.h"
#include "math_utils.h"

void ImageWriter::writePPM(const Image& image, const std::string& filepath)
{
    FILE *f = fopen(filepath.c_str(), "w");
    
    //write ppm header
    fprintf(f, "P3\n%d %d\n%d\n", image.width, image.height, 255);
    
    //write ppm data
    for (int i=0; i<image.width*image.height; i++)
    {
        fprintf(f,"%d %d %d ", toInt(image.pixels[i*3]), toInt(image.pixels[i*3+1]), toInt(image.pixels[i*3+1]));
    }

}