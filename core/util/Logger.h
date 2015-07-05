//
// Created by arthur on 6/30/15.
//

#ifndef BIAENGINE_LOGGER_H
#define BIAENGINE_LOGGER_H
#define DEBUG_MODE 1
#if DEBUG_MODE

#include <iostream>

#define LOG(log) std::cout<<log<<std::endl;
#else
#define LOG(log)
#endif
#endif //BIAENGINE_LOGGER_H
