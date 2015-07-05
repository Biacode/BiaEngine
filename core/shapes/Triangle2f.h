//
// Created by Arthur Asatryan
// Company: BiaCode
// Date: 7/5/15
// Copyright (c) 2015 BiaCode. All rights reserved.
//

#ifndef BIAENGINE_TRIANGLE_H
#define BIAENGINE_TRIANGLE_H

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "../util/Logger.h"

namespace biaengine
{
    namespace shapes
    {
        class Triangle2f
        {
        public:
            Triangle2f();

            ~Triangle2f();

            void init();

            void draw();

        private:
            // Vertex buffer object and array object
            GLuint _VBO, _VAO;

            // shading program
            GLuint _shaderProgram;

            // Shader
            const GLchar *vertexShaderSource = "#version 330 core\n"
                    "layout (location = 0) in vec3 position;\n"
                    "void main()\n"
                    "{\n"
                    "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
                    "}\0";

            const GLchar *fragmentShaderSource = "#version 330 core\n"
                    "out vec4 color;\n"
                    "void main()\n"
                    "{\n"
                    "color = vec4(0.0f, 0.5f, 0.2f, 1.0f);\n"
                    "}\n\0";
        };
    }
}

#endif //BIAENGINE_TRIANGLE_H
