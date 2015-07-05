//
// Created by Arthur Asatryan
// Company: BiaCode
// Date: 7/5/15
// Copyright (c) 2015 BiaCode. All rights reserved.
//

#include <iostream>
#include "TestGame.h"
#include "core/util/fileutil.h"

int main()
{
    using namespace biaengine::util;
    std::string file = read_file("/home/arthur/ClionProjects/BiaEngine/main.cpp");
    std::cout << file << std::endl;
    TestGame testGame;
    return 1;
}