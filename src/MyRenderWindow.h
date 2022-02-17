#pragma once

#include "base/RenderWindow.h"
#include "Quad.h"

class MyRenderWindow : public RenderWindow {
  private:
    GameObject* gameObjectTest01;
    GameObject* gameObjectTest02;

    virtual void ProcessInput();
    static void FramebufferSizeCallback(GLFWwindow *glfwWindow, int width, int height);

  protected:
    virtual void OnWindowCreated() override;
    virtual void OnDrawFrame() override;
    virtual void OnWindowDestroy() override;

  public:
    using RenderWindow::RenderWindow;
    // MyRenderWindow();
    // virtual ~MyRenderWindow() override;
};
