#include "window.h"

window::window(const int width, const int height, char* title) {
    this->height_ = height;
    this->width_ = width;
    this->title_ = title;
    this->isRunning_ = true;

    this->initialize();
}

void window::initialize() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 16);
    if (!glfwInit()) {
        spdlog::error("Failed to initialize GLFW");
        exit(1);
    }

    this->window_ = glfwCreateWindow(this->width_, this->height_, this->title_, nullptr, nullptr);

    if (!this->window_) {
        spdlog::error("Failed creating window. \{{} x {} - {}\}", this->width_, this->height_, this->title_);
        glfwTerminate();
    }

    glfwMakeContextCurrent(this->window_);
    //glfwSetWindowSizeCallback(this->window_, cb_glfw_resize);

    glClearColor(0.2, 0.2, 0.5, 1.0);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        spdlog::error("Failed to initialize GLEW");
        exit(1);
    }

    spdlog::info("Renderer: {}", glGetString(GL_RENDERER));
    spdlog::info("OpenGL Version: {}", glGetString(GL_VERSION));
}

void window::update() {
    glfwPollEvents();
}

void window::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glfwSwapBuffers(this->window_);
}

window::~window() {
    glfwDestroyWindow(this->window_);
}
