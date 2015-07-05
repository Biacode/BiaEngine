//
// Created by Arthur Asatryan
// Company: BiaCode
// Date: 7/5/15
// Copyright (c) 2015 BiaCode. All rights reserved.
//

#include "Rectangle2f.h"

namespace biaengine
{
        namespace shapes
        {
            Rectangle2f::Rectangle2f()
            {
                init();
            }

            Rectangle2f::~Rectangle2f()
            {
                glDeleteVertexArrays(1, &_VAO);
                glDeleteBuffers(1, &_VBO);
                glDeleteBuffers(1, &_EBO);
            }

            void Rectangle2f::init()
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
                        0.5f, 0.5f, 0.0f,  // Top Right
                        0.5f, -0.5f, 0.0f,  // Bottom Right
                        -0.5f, -0.5f, 0.0f,  // Bottom Left
                        -0.5f, 0.5f, 0.0f   // Top Left
                };
                GLuint indices[] = {  // Note that we start from 0!
                        0, 1, 3,  // First Triangle
                        1, 2, 3   // Second Triangle
                };
                _VBO, _VAO, _EBO;
                glGenVertexArrays(1, &_VAO);
                glGenBuffers(1, &_VBO);
                glGenBuffers(1, &_EBO);
                // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
                glBindVertexArray(_VAO);

                glBindBuffer(GL_ARRAY_BUFFER, _VBO);
                glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *) 0);
                glEnableVertexAttribArray(0);
                // Note that this is allowed, the call to glVertexAttributePointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs), remember: do NOT unbind the EBO, keep it bound to this VAO
                glBindVertexArray(0);

                // Uncommenting this call will result in wire frame polygons.
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                _shaderProgram = shaderProgram;
            }

            void Rectangle2f::draw()
            {
                // Draw our first triangle
                glUseProgram(_shaderProgram);
                glBindVertexArray(_VAO);
                //glDrawArrays(GL_TRIANGLES, 0, 6);
                glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
                glBindVertexArray(0);
            }
        }
}
