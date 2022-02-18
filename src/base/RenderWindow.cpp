#include "RenderWindow.h"

RenderWindow::RenderWindow(const char *title, unsigned int width, unsigned int height)
    : title(title), width(width), height(height) {
}

GLFWwindow *RenderWindow::InitWindow() {
    // GLFW：初始化与配置
    glfwInit(); // 初始化 GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // 配置 GLFW，将主版本号设置为 3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // 将次版本号设置为 3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 使用核心模式
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // GLFW：创建窗口
    glfwWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (glfwWindow == nullptr) {
        std::cout << "[ERROR] RenderWindow: Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }

    // GLFW：将窗口的上下文设置为当前线程的主上下文
    glfwMakeContextCurrent(glfwWindow);
    // glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback); // TODO 这个要放在哪里比较好

    // GLAD: 加载 OpenGL 相关的函数指针
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "[ERROR] RenderWindow: Failed to initialize GLAD" << std::endl;
        return nullptr;
    }

    // 调用自定义的 OnWindowCreated 方法，这个方法会在派生类中被实现
    OnWindowCreated();
    return glfwWindow;
}

void RenderWindow::StartDraw() {
    // 绘制循环
    while (!glfwWindowShouldClose(glfwWindow)) {
        // 更新时间差值
        float currentFrameTime = glfwGetTime();
        deltaFrameTime = currentFrameTime - lastFrameTime;
        lastFrameTime = currentFrameTime;
        // 调用自定义的 OnDrawFrame 方法，这个方法会在派生类中被实现
        OnDrawFrame();
        // GLFW：交换缓冲
        glfwSwapBuffers(glfwWindow); // TODO 双缓冲是必备项吗
        // GLFW：拉取 IO 事件（按键按下与释放，鼠标移动等）
        glfwPollEvents(); // TODO 这个是必备项吗
    }
    OnWindowDestroy();
    glfwTerminate();
}
