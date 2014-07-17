//
//  ImageWriter.h
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-17.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#ifndef __CaribouPT__ImageWriter__
#define __CaribouPT__ImageWriter__

#include <string>
#include "Image.h"

class ImageWriter
{
public:
    void writePPM(const Image& image, std::string filepath);
};
#endif /* defined(__CaribouPT__ImageWriter__) */
