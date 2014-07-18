//
//  ImageWriter.h
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-17.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#ifndef __CaribouPT__ImageWriter__
#define __CaribouPT__ImageWriter__

#include "Image.h"
#include <string>
#include <tr1/memory>
class ImageWriter
{
public:
    void writePPM(const std::tr1::shared_ptr<Image> image, const std::string& filepath);
};
#endif /* defined(__CaribouPT__ImageWriter__) */
