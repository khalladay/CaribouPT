//
//  Image.h
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-17.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#ifndef CaribouPT_Image_h
#define CaribouPT_Image_h
#include <stdio.h>
#include <string.h>

class Image
{
public:
    Image(int w, int h) : width(w), height(h)
    {
        pixels = new double[w*h*3];
        memset(pixels, 0, sizeof(double)*w*h*3);
    }
    
    ~Image()
    {
        delete[] pixels;
    }
    
    int width;
    int height;
    double* pixels;
};

#endif
