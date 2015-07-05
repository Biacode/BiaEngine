//
// Created by Arthur Asatryan
// Company: BiaCode
// Date: 7/5/15
// Copyright (c) 2015 BiaCode. All rights reserved.
//

#include "Triangle2f.h"

namespace biaengine
{
        namespace shapes
        {

            Triangle2f::Triangle2f()
            {
                init();
            }

            Triangle2f::~Triangle2f()
            {
                // Properly de-allocate all resources once they've outlived their purpose
                glDeleteVertexArrays(1, &_VAO);
                glDeleteBuffers(1, &_VBO);
            }

            void Triangle2f::init()
            {
                // Build and compile our shader program
                // Vertex shader
                GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
                glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
                glCompileShader(vertexShader);
                // Check for compile time errors
                GLint success;
                GLchar infoLog[512];
                glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
                if (!success) {
                    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
                    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
                }
                // Fragment shader
                GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
                glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
                glCompileShader(fragmentShader);
                // Check for compile time errors
                glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
                if (!success) {
                    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
                    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
                }
                // Link shader
                GLuint shaderProgram = glCreateProgram();
                glAttachShader(shaderProgram, vertexShader);
                glAttachShader(shaderProgram, fragmentShader);
                glLinkProgram(shaderProgram);
                // Check for linking errors
                glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
                if (!success) {
                    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
                    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
                }
                glDeleteShader(vertexShader);
                glDeleteShader(fragmentShader);
                // Set up vertex data (and buffer(s)) and attribute pointers
                GLfloat vertices[] = {
                        -0.5f, -0.5f, 1.0f, // Left
                        0.5f, -0.5f, 1.0f, // Right
                        0.0f, 0.5f, 1.0f  // Top
                };
                glGenVertexArrays(1, &_VAO);
                glGenBuffers(1, &_VBO);
                // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
                glBindVertexArray(_VAO);

                glBindBuffer(GL_ARRAY_BUFFER, _VBO);
                glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *) 0);
                glEnableVertexAttribArray(0);
                // Note that this is allowed, the call to glVertexAttributePointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)
                glBindVertexArray(0);
                _shaderProgram = shaderProgram;
            }

            void Triangle2f::draw()
            {
                // Draw our first triangle
                glUseProgram(_shaderProgram);
                glBindVertexArray(_VAO);
                glDrawArrays(GL_TRIANGLES, 0, 3);
                glBindVertexArray(0);
            }
    }
}