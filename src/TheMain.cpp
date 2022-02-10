// glm 定义 // TODO 位置
#ifndef GLM_FORCE_EXPLICIT_CTOR
#define GLM_FORCE_EXPLICIT_CTOR
#endif

#include "MyRenderWindow.h"

int main() {
    std::cout << "[APP START]" << std::endl;

    MyRenderWindow *myRenderWindow = new MyRenderWindow("LearnOpenGL", 800, 600);
    myRenderWindow->InitWindow();
    myRenderWindow->StartDraw();
    delete (myRenderWindow);

    std::cout << "[APP END]" << std::endl;
    return 0;
}
