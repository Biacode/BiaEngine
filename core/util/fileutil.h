//
// Created by Arthur Asatryan
// Company: BiaCode
// Date: 7/6/15
// Copyright (c) 2015 BiaCode. All rights reserved.
//

#ifndef BIAENGINE_FILEUTIL_H
#define BIAENGINE_FILEUTIL_H

#include <string.h>
#include "fstream"

namespace biaengine
{
    namespace util
    {
        std::string read_file(const char *filePath)
        {
            FILE *file = fopen(filePath, "rt");
            fseek(file, 0, SEEK_END);
            unsigned long length = (unsigned long) ftell(file);
            char *data = new char[length + 1];
            memset(data, 0, length + 1);
            fseek(file, 0, SEEK_SET);
            fread(data, 1, length, file);
            fclose(file);
            std::string result(data);
            delete[] data;
            return result;
        }
    }
}

#endif //BIAENGINE_FILEUTIL_H
