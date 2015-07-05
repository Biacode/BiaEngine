//
// Created by Arthur Asatryan
// Company: BiaCode
// Date: 7/5/15
// Copyright (c) 2015 BiaCode. All rights reserved.
//

#include "GameState.h"

namespace biaengine
{
    namespace game
    {

        GameState::GameState()
        {

        }

        GameState::~GameState()
        {

        }

        void GameState::attachState(BiaGame *game)
        {
            this->_game = game;
        }

        void GameState::init()
        {

        }

        void GameState::update() const
        {

        }
    }
}