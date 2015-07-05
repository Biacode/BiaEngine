//
// Created by Arthur Asatryan
// Company: BiaCode
// Date: 7/5/15
// Copyright (c) 2015 BiaCode. All rights reserved.
//

#include "BiaGame.h"
#include "../graphics/Window.h"

namespace biaengine
{
    namespace game
    {
        BiaGame::BiaGame()
        {
            init();
        }

        BiaGame::BiaGame(const char *title, int width, int height)
        {
            _title = title;
            _width = width;
            _height = height;
            init();
        }

        BiaGame::~BiaGame()
        {
        }

        void BiaGame::init()
        {
            biaengine::graphics::Window window(this, _title, _width, _height);
        }

        void BiaGame::update() const
        {
        }

        GLFWwindow *BiaGame::getWindow() const
        {
            return _window;
        }
    }
}