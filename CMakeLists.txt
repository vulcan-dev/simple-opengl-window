cmake_minimum_required(VERSION 3.16)
project(open_gl)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(deps/glfw)
add_subdirectory(deps/glew)

set(SOURCE
    src/main.cpp
    src/window/window.cpp
)

set(INCLUDE_DIRS
    include
    deps/glfw/include/GLFW
)

include_directories(${INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME}
    libglew_static
    glfw
    OpenGL::GL
)