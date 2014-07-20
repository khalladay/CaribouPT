//
//  Renderer.cpp
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-18.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#include "Renderer.h"
#include <omp.h>
#include <stdio.h>

void Renderer::render(shared_ptr<Scene> scene, shared_ptr<Image> target)
{
    //parallelize this loop, 1 iteration per thread
    //division of work done at runtime since image size isn't known
    #pragma omp parallel for schedule(dynamic, 1) collapse(2)
    for (int x = 0; x < target->width; x++)
    {
        for (int y = 0; y < target->height; y++)
        {
            double aspect = float(target->width )/(float)target->height;
            double ndcX = (x + 0.5) / (float)target->width;
            double ndcY = (y + 0.5) / (float)target->height;

            double ssX = 1.0 - 2.0 * ndcX;
            double ssY = 1.0 - 2.0 * ndcY;

            printf("%f %f \t thread %d\n", ssX, ssY,
                omp_get_thread_num());
        }
    }
}
