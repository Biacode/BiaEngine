//
// Created by Arthur Asatryan
// Company: BiaCode
// Date: 7/5/15
// Copyright (c) 2015 BiaCode. All rights reserved.
//

#ifndef BIAENGINE_RECTANGLE2F_H
#define BIAENGINE_RECTANGLE2F_H

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "../util/logger.h"

namespace biaengine
{
        namespace shapes
        {
            class Rectangle2f
            {
            public:
                Rectangle2f();

                ~Rectangle2f();

                void init();

                void draw();

            private:
                // Vertex buffer, array object, element buffer objects
                GLuint _VBO, _VAO, _EBO;

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
                        "color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                        "}\n\0";
            };
        }
}


#endif //BIAENGINE_RECTANGLE2F_H
