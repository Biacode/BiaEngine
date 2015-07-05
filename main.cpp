//
// Created by Arthur Asatryan
// Company: BiaCode
// Date: 7/5/15
// Copyright (c) 2015 BiaCode. All rights reserved.
//

#include "TestGame.h"
#include "core/math/maths.h"

int main()
{
    using namespace biaengine::math;
    mat4 position = mat4::translation(vec3(2.f, 3.f, 4.f));
    position *= mat4::identity();

    position.elements[12] = 2.0f;

    vec4 c0 = position.columns[3];
    std::cout << c0 << std::endl;
    TestGame testGame;
    return 1;
}