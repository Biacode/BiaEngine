# Created by Arthur Asatryan
# Company: BiaCode
# Date: 7/5/15
# Copyright (c) 2015 BiaCode. All rights reserved.

cmake_minimum_required(VERSION 3.2)
project(BiaEngine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(BiaEngine ${SOURCE_FILES}
core/graphics/Window.cpp core/graphics/Window.h
core/util/Logger.h
core/shapes/Triangle2f.cpp core/shapes/Triangle2f.h
core/shapes/Rectangle2f.cpp core/shapes/Rectangle2f.h
core/game/BiaGame.cpp core/game/BiaGame.h
TestGame.cpp TestGame.h
core/game/GameState.cpp core/game/GameState.h
core/math/vec2.h core/math/vec2.cpp
core/math/vec3.h core/math/vec3.cpp
core/math/vec4.h core/math/vec4.cpp
core/math/mat4.cpp core/math/mat4.h
core/math/maths.h NewCppClass.cpp NewCppClass.h)

if (UNIX)
add_subdirectory(external/glfw)
add_subdirectory(external/glew)
include_directories(
    external/glfw/include
    external/glew/include
)
target_link_libraries(BiaEngine glfw ${GLFW_LIBRARIES})
target_link_libraries(BiaEngine ${CMAKE_SOURCE_DIR}/external/glew/lib/libGLEW.a)
endif (UNIX)
