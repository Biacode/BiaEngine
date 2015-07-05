//
// Created by Arthur Asatryan
// Company: BiaCode
// Date: 7/6/15
// Copyright (c) 2015 BiaCode. All rights reserved.
//

#include "Shader.h"

namespace biaengine
{
    namespace graphics
    {

        Shader::Shader(const char *vertexPath, const char *fragmentPath) :
                _vertexPath(vertexPath), _fragmentPath(fragmentPath)
        {
            _shaderID = load();
        }

        Shader::~Shader()
        {
            glDeleteProgram(_shaderID);
        }

        void Shader::enable() const
        {
            glUseProgram(_shaderID);
        }

        void Shader::disable() const
        {
            glUseProgram(0);
        }

        GLuint Shader::load()
        {
            using namespace biaengine::util;
            GLuint program = glCreateProgram();
            GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
            GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

            const char *vertexSource = read_file(_vertexPath).c_str();
            const char *fragmentSource = read_file(_fragmentPath).c_str();

            // vertex shader
            GLint success;
            glShaderSource(vertex, 1, &vertexSource, NULL);
            glCompileShader(vertex);
            glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
            if (success == GL_FALSE)
            {
                GLint length;
                glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
                std::vector<char> error((unsigned long) length);
                glGetShaderInfoLog(vertex, length, &length, &error[0]);
                LOG(&error[0]);
                glDeleteShader(vertex);
                return 0;
            }

            //fragment shader
            glShaderSource(fragment, 1, &fragmentSource, NULL);
            glCompileShader(fragment);
            glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
            if (success == GL_FALSE)
            {
                GLint length;
                glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
                std::vector<char> error((unsigned long) length);
                glGetShaderInfoLog(fragment, length, &length, &error[0]);
                LOG(&error[0]);
                glDeleteShader(fragment);
                return 0;
            }

            // get ready program for GPU
            glAttachShader(program, vertex);
            glAttachShader(program, fragment);
            glLinkProgram(program);
            glValidateProgram(program);
            glDeleteShader(vertex);
            glDeleteShader(fragment);
            return program;
        }
    }
}
