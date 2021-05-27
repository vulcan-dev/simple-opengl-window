#ifndef _window_h
#define _window_h

#define GLFW_INCLUDE_NONE
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

class window {
public:
    window(const int width, const int height, char* title);

    inline const uint32_t getWidth() const { return this->width_; }
    inline const uint32_t getHeight() const { return this->height_; }
    inline const bool isRunning() const { return !glfwWindowShouldClose(this->window_); }

    void update();
    void render();

    ~window();

private:
    void initialize();

private:
    GLFWwindow* window_;

    uint32_t width_, height_;
    bool isRunning_;
    char* title_;
};

#endif