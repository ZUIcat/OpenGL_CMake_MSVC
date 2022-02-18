#pragma once

#include <iostream>
#include <glad/glad.h>
// GLFW (include after glad)
#include <GLFW/glfw3.h>

class RenderWindow {
  protected:
    const char *title;
    const int width;
    const int height;

    GLFWwindow *glfwWindow;

    float lastFrameTime = 0.0f; // 上一帧的时间
    float deltaFrameTime = 0.0f; // 当前帧与上一帧的时间差

    virtual void OnWindowCreated() = 0;
    virtual void OnDrawFrame() = 0;
    virtual void OnWindowDestroy() = 0;

  public:
    explicit RenderWindow(const char *title, unsigned int width, unsigned int height);
    virtual ~RenderWindow() = default;

    virtual GLFWwindow *InitWindow();
    virtual void StartDraw();
};
