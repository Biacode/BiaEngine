//
// Created by Arthur Asatryan
// Company: BiaCode
// Date: 7/5/15
// Copyright (c) 2015 BiaCode. All rights reserved.
//

#include "Window.h"
#include "../shapes/Rectangle2f.h"
#include "../shapes/Triangle2f.h"

namespace biaengine
{
        namespace graphics
        {
            void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

            void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);

            void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);

            Window::Window(biaengine::game::BiaGame *game, const char *title, int width, int height)
            {
                _title = title;
                _width = width;
                _height = height;
                _game = game;
                // initialize keys and mouse buttons
                for (int i = 0; i < MAX_KEYS; i++)
                    _keys[i] = false;
                for (int i = 0; i < MAX_BUTTONS; i++)
                    _mouseButtons[i] = false;
                init();
            }

            Window::~Window()
            {
                terminate("");
            }

            void Window::init()
            {
                if (!glfwInit())
                    terminate("Failed to initialize GLFW");
                glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
                glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
                glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
                glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
                _window = glfwCreateWindow(_width, _height, _title, nullptr, nullptr);
                if (_window == nullptr)
                    terminate("Failed to create GLFW window!");
                glfwMakeContextCurrent(_window);
                glfwSetWindowUserPointer(_window, this);
                glViewport(0, 0, _width, _height);
                glewExperimental = GL_TRUE;
                if (glewInit() != GLEW_OK)
                    terminate("Failed to initialize GLEW");
                glfwSetKeyCallback(_window, key_callback);
                glfwSetMouseButtonCallback(_window, mouse_button_callback);
                glfwSetCursorPosCallback(_window, cursor_position_callback);
                // Game loop
                while (!closed())
                {
                    glfwPollEvents();
                    _game->update();
                    glfwSwapBuffers(_window);
                }
                glfwTerminate();
            }

            void Window::update() const
            {
                using namespace biaengine::shapes;

                double x, y;
                if (isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
                {
                    getMousePosition(x, y);
                    std::cout << "X: " << x << " Y: " << y << std::endl;
                }
            }

            void Window::terminate(const char *message) const
            {
                LOG(message);
                glfwTerminate();
            }

            bool Window::closed() const
            {
                return glfwWindowShouldClose(_window) == GL_TRUE;
            }

            bool Window::isKeyPressed(unsigned int keyCode) const
            {
                // TODO: Log this!
                if (keyCode >= MAX_KEYS)
                    return false;
                return _keys[keyCode];
            }

            bool Window::isMouseButtonPressed(unsigned int buttonCode) const
            {
                // TODO: Log this!
                if (buttonCode >= MAX_BUTTONS)
                    return false;
                return _mouseButtons[buttonCode];
            }

            void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
            {
                Window *_window = (Window *) glfwGetWindowUserPointer(window);
                _window->_keys[key] = action != GLFW_RELEASE;
                if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
                    glfwSetWindowShouldClose(window, GL_TRUE);
            }

            void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
            {
                Window *_window = (Window *) glfwGetWindowUserPointer(window);
                _window->_mouseButtons[button] = action != GLFW_RELEASE;
            }

            void cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
            {
                Window *_window = (Window *) glfwGetWindowUserPointer(window);
                _window->_mx = xpos;
                _window->_my = ypos;
            }

            void Window::getMousePosition(double &x, double &y) const
            {
                x = _mx;
                y = _my;
            }
    }
}
