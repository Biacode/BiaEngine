//
// Created by Arthur Asatryan
// Company: BiaCode
// Date: 7/5/15
// Copyright (c) 2015 BiaCode. All rights reserved.
//

#include <iostream>
#include "TestGame.h"

TestGame::TestGame()
{

}

TestGame::~TestGame()
{

}

void TestGame::init()
{
    BiaGame::init();
}

void TestGame::update() const
{
    BiaGame::update();
    std::cout << "asdasd" << std::endl;
}
