//
// Created by Arthur Asatryan
// Company: BiaCode
// Date: 7/5/15
// Copyright (c) 2015 BiaCode. All rights reserved.
//

#ifndef BIAENGINE_GAMESTATE_H
#define BIAENGINE_GAMESTATE_H

#include "BiaGame.h"

namespace biaengine
{
    namespace game
    {
        class GameState
        {
        private:
            BiaGame *_game;
        public:
            GameState();

            ~GameState();

            void init();

            void update() const;

            void attachState(BiaGame *game);
        };
    }
}


#endif //BIAENGINE_GAMESTATE_H
