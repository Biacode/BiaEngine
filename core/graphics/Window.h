//
// Created by arthur on 6/30/15.
//

#ifndef BIAENGINE_WINDOW_H
#define BIAENGINE_WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../util/Logger.h"

#define MAX_KEYS        1024
#define MAX_BUTTONS     32

namespace biaengine
{
    namespace graphics
    {
        class Window
        {
        private:
            const char *_title;
            int _width, _height;
            GLFWwindow *_window;

            bool _keys[MAX_KEYS];
            bool _mouseButtons[MAX_BUTTONS];
            double _mx, _my;
        public:
            Window(const char *title, int width, int height);

            ~Window();

            void update() const;

            void terminate(const char *message) const;

            bool closed() const;

            bool isKeyPressed(unsigned int keyCode) const;

            bool isMouseButtonPressed(unsigned int buttonCode) const;

            void getMousePosition(double &x, double &y) const;

        private:
            void init();

            friend void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

            friend void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);

            friend void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);
        };
    }
}

#endif //BIAENGINE_WINDOW_H
