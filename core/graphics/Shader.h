//
// Created by Arthur Asatryan
// Company: BiaCode
// Date: 7/6/15
// Copyright (c) 2015 BiaCode. All rights reserved.
//

#ifndef BIAENGINE_SHADER_H
#define BIAENGINE_SHADER_H

#include "vector"
#include "GL/glew.h"
#include "../util/fileutil.h"
#include "../util/logger.h"

namespace biaengine
{
    namespace graphics
    {
        class Shader
        {
        private:
            GLuint _shaderID;
            const char *_vertexPath;
            const char *_fragmentPath;
        public:
            Shader(const char *vertexPath, const char *fragmentPath);

            ~Shader();

            void enable() const;

            void disable() const;

        private:
            GLuint load();
        };
    }
}

#endif //BIAENGINE_SHADER_H
