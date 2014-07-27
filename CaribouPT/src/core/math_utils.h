//
//  math_utils.h
//  CaribouPT
//
//  Created by Kyle Halladay on 2014-07-17.
//  Copyright (c) 2014 Kyle Halladay. All rights reserved.
//

#ifndef CaribouPT_math_utils_h
#define CaribouPT_math_utils_h

#include <math.h>

inline float clampZeroOne(float x){ return x<0 ? 0 : x>1 ? 1 : x; }
inline int toInt(float x){ return int(pow(clampZeroOne(x),1/2.2)*255+.5); }


#endif
