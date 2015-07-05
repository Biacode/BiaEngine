cmake_minimum_required(VERSION 3.2)
project(BiaEngine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(BiaEngine ${SOURCE_FILES}
core/graphics/Window.cpp core/graphics/Window.h
core/util/Logger.h)

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
