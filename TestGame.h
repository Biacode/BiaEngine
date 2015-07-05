//
// Created by Arthur Asatryan
// Company: BiaCode
// Date: 7/5/15
// Copyright (c) 2015 BiaCode. All rights reserved.
//

#ifndef BIAENGINE_TESTGAME_H
#define BIAENGINE_TESTGAME_H

#include "core/game/BiaGame.h"

using namespace biaengine::game;

class TestGame : public BiaGame
{

public:

    TestGame();

    ~TestGame();

    virtual void init() override;

    virtual void update() const override;
};


#endif //BIAENGINE_TESTGAME_H
