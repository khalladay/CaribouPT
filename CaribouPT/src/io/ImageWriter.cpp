//
//  ImageWriter.cpp
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-17.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#include "ImageWriter.h"
#include "math_utils.h"
#include <fstream>
#include <stdio.h>

void ImageWriter::writePPM(const std::tr1::shared_ptr<Image> image,
                           const std::string& filepath)
{
  using namespace std;

    FILE *f = fopen(filepath.c_str(), "w");
    fprintf(f, "P3\n%d %d\n%d\n", image->w, image->h, 255);

    for (int y = 0; y < image->h; y++)
    {
        for (int x = 0; x < image->w; x++)
        {
            double col[3];
            col[0] = image->pixels[(y * image->w + x)*3];
            col[1] = image->pixels[(y * image->w + x)*3 + 1];
            col[2] = image->pixels[(y * image->w + x)*3 + 2];

            int r = min(255,toInt(col[0]));
            int g = min(255,toInt(col[1]));
            int b = min(255,toInt(col[2]));
        
            fprintf(f,"%d %d %d ", r, g, b);
        }
    }
}
