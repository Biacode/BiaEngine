//
// Created by Arthur Asatryan
// Company: BiaCode
// Date: 7/5/15
// Copyright (c) 2015 BiaCode. All rights reserved.
//

#ifndef BIAENGINE_MATHS_H
#define BIAENGINE_MATHS_H

#include <math.h>
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"

namespace biaengine
{
    namespace math
    {
        inline float toRadians(float degrees)
        {
            return (float) (degrees * (M_PI / 180.0f));
        }
    }
}

#endif //BIAENGINE_MATHS_H
