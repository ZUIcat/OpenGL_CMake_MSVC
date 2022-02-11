#include "MyRenderWindow.h"
#include "util/TextureUtil.h"

void MyRenderWindow::OnWindowCreated() {
    // 设置窗口大小发生改变的回调方法
    // 当窗口第一次显示的时候 FramebufferSizeCallback 也会被调用 // TODO 没有啊
    glfwSetFramebufferSizeCallback(glfwWindow, FramebufferSizeCallback);
    // 打开背面剪裁
    glEnable(GL_CULL_FACE);

    //
    CameraUtil::SetCamera(
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f
    );

    // TODO 重构
    float aspect = static_cast<float>(width) / height;
    float right = 0.5f * aspect;
    float top = 0.5f;
    float near = 1.0f;
    float far = 100.0f;
    MartrixUtil::SetPerspProjection(-right, right, -top, top, near, far);

    // 加载纹理
    TextureUtil::AddTexture("tex003", "./res/tex003.png");
    // 创建矩形对象
    rectangle = new Rectangle(TextureUtil::GetTexture("tex003"));
    rectangle -> Create();
}

void MyRenderWindow::OnDrawFrame() {
    // 处理输入
    ProcessInput();
    // 设置用来清除的颜色
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    // 清除颜色缓冲
    glClear(GL_COLOR_BUFFER_BIT);

    MartrixUtil::Push();
    MartrixUtil::Translate(0.5f, 0.0f, 0.0f);
    // 绘制矩形
    rectangle->DrawSelf();
    MartrixUtil::Pop();
}

void MyRenderWindow::OnWindowDestroy() {
    // 销毁矩形对象
    rectangle->Destroy();
    delete(rectangle);
}

void MyRenderWindow::ProcessInput() {
    if (glfwGetKey(glfwWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(glfwWindow, true);
    }

    if (glfwGetKey(glfwWindow, GLFW_KEY_W) == GLFW_PRESS) {
        CameraUtil::Zoom(0.001f);
    }

    if (glfwGetKey(glfwWindow, GLFW_KEY_S) == GLFW_PRESS) {
        CameraUtil::Zoom(-0.001f);
    }
}

void MyRenderWindow::FramebufferSizeCallback(GLFWwindow *glfwWindow, int width, int height) {
    // 改变视口大小
    glViewport(0, 0, width, height);
    std::cout << "FramebufferSizeCallback()" << std::endl;

    float aspect = static_cast<float>(width) / height;
    float right = 0.5f * aspect;
    float top = 0.5f;
    float near = 1.0f;
    float far = 100.0f;
    MartrixUtil::SetPerspProjection(-right, right, -top, top, near, far);
}
