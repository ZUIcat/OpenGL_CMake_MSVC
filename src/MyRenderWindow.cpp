#include "MyRenderWindow.h"
#include "util/TextureUtil.h"

void MyRenderWindow::OnWindowCreated() {
    // 设置窗口大小发生改变的回调方法
    // 当窗口第一次显示的时候 FramebufferSizeCallback 也会被调用 // TODO 没有啊
    glfwSetFramebufferSizeCallback(glfwWindow, FramebufferSizeCallback);
    // 打开背面剪裁
    // glEnable(GL_CULL_FACE);
    // 开启深度测试
    glEnable(GL_DEPTH_TEST);
    // 设置用来清除的颜色
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    // Enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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

    tempVal = 0;

    // 加载纹理
    TextureUtil::Init();
    TextureUtil::AddTexture("tex003", "./res/tex003_rgba.png");

    gameObjectTest01 = new GameObject();
    gameObjectTest01->GetTransform().SetPosition(0.5f, 0.0f, -1.0f);
    Component *quad1 = new Quad(TextureUtil::GetTexture("tex003"));
    gameObjectTest01->GetComponents().push_back(quad1);
    gameObjectTest01->Create();

    gameObjectTest02 = new GameObject();
    gameObjectTest02->GetTransform().SetPosition(-0.5f, 0.0f, -1.0f);
    Component *quad2 = new Quad(TextureUtil::GetTexture("tex003"));
    gameObjectTest02->GetComponents().push_back(quad2);
    gameObjectTest02->Create();
}

void MyRenderWindow::OnDrawFrame() {
    // 处理输入
    ProcessInput();
    // 清除颜色缓冲和深度缓冲
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // 输出 deltaFrameTime
    std::cout << "The deltaFrameTime is: " << deltaFrameTime << std::endl;

    //tempVal += 0.04f;
    //gameObjectTest01->GetTransform().SetRotation(0.0f, tempVal * deltaFrameTime, 0.0f);
    gameObjectTest01->GetTransform().SetRotation(0.0f, (float)glfwGetTime(), 0.0f);

    gameObjectTest01->Update();
    gameObjectTest02->Update();
}

void MyRenderWindow::OnWindowDestroy() {
    gameObjectTest01->Destroy();
    delete (gameObjectTest01);
    gameObjectTest02->Destroy();
    delete (gameObjectTest02);
}

void MyRenderWindow::ProcessInput() {
    if (glfwGetKey(glfwWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(glfwWindow, true);
    }

    if (glfwGetKey(glfwWindow, GLFW_KEY_R) == GLFW_PRESS) {
        CameraUtil::Zoom(0.2f * deltaFrameTime);
    }
    if (glfwGetKey(glfwWindow, GLFW_KEY_F) == GLFW_PRESS) {
        CameraUtil::Zoom(-0.2f * deltaFrameTime);
    }
    if (glfwGetKey(glfwWindow, GLFW_KEY_W) == GLFW_PRESS) {
        CameraUtil::RotateIn2AxisForInitPos(0.2f * deltaFrameTime, 0.0f);
    }
    if (glfwGetKey(glfwWindow, GLFW_KEY_S) == GLFW_PRESS) {
        CameraUtil::RotateIn2AxisForInitPos(-0.2f * deltaFrameTime, 0.0f);
    }
    if (glfwGetKey(glfwWindow, GLFW_KEY_A) == GLFW_PRESS) {
        CameraUtil::RotateIn2AxisForInitPos(0.0f, 0.2f * deltaFrameTime);
    }
    if (glfwGetKey(glfwWindow, GLFW_KEY_D) == GLFW_PRESS) {
        CameraUtil::RotateIn2AxisForInitPos(0.0f, -0.2f * deltaFrameTime);
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
