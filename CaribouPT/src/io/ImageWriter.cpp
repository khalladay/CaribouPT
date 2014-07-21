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

  ofstream ofs;
  ofs.open(filepath.c_str());

  ofs<< "P6\n" << image->w << " " << image->h << "\n255\n";

  for (int y = 0; y < image->h; y++)
  {
    for (int x = 0; x < image->w; x++)
    {
      double col[3];
      col[0] = image->pixels[(y * image->w + x)*3];
      col[1] = image->pixels[(y * image->w + x)*3 + 1];
      col[2] = image->pixels[(y * image->w + x)*3 + 2];

      col[0] = max(0.0, min(255.0, pow(col[0], 1.0/2.0) * 255.0 + 0.5));
      col[1] = max(0.0, min(255.0, pow(col[1], 1.0/2.0) * 255.0 + 0.5));
      col[2] = max(0.0, min(255.0, pow(col[2], 1.0/2.0) * 255.0 + 0.5));


      char pixel[3];
      pixel[0] = (unsigned char)col[0];
      pixel[1] = (unsigned char)col[1];
      pixel[2] = (unsigned char)col[2];

      ofs.write(pixel,3);
    }
  }

  ofs.close();
}
