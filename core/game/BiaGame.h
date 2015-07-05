//
// Created by Arthur Asatryan
// Company: BiaCode
// Date: 7/5/15
// Copyright (c) 2015 BiaCode. All rights reserved.
//

#ifndef BIAENGINE_BIAGAME_H
#define BIAENGINE_BIAGAME_H

#include "GL/glew.h"
#include <GLFW/glfw3.h>

namespace biaengine
{
    namespace game
    {
        class BiaGame
        {
        public:
            BiaGame();

            BiaGame(const char *title, int width, int height);

            ~BiaGame();

            virtual void init();

            virtual void update() const;

            GLFWwindow *getWindow() const;

        private:
            const char *_title = "BiaEngine";
            int _width = 800, _height = 600;
            GLFWwindow *_window;
        };
    }
}

#endif //BIAENGINE_BIAGAME_H
