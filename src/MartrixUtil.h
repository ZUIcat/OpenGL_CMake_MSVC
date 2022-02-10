#pragma once

#include <iostream>
#include <vector>
#include <stack>

// https://github.com/g-truc/glm/blob/master/manual.md

// https://www.shuxuele.com/algebra/matrix-inverse.html
// https://zhuanlan.zhihu.com/p/69069042
// https://docs.gl/

#include <glm/glm.hpp>
// #include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class MartrixUtil {
  private:
    // 不存指针了，感觉 C++ 内部替自己优化了很多
    // 等 C++ 学到一定程度再研究重构吧
    static std::stack<glm::mat4> MMatrixStack;  // 保存模型变换矩阵的栈
    static glm::mat4 MMatrix;                   // 模型变换矩阵
    static glm::mat4 VMatrix;                   // 视图变换矩阵
    static glm::mat4 PMatrix;                   // 投影变换矩阵

    explicit MartrixUtil() = default;

  public:
    virtual ~MartrixUtil() = default;

    // 将模型变换矩阵存入栈中
    static void Push();
    // 从栈顶取出模型变换矩阵
    static void Pop();

    // 对模型变换矩阵进行平移变换
    static void Translate(float x, float y, float z);
    // 对模型变换矩阵进行旋转变换
    static void Rotate(float x, float y, float z, float angle);
    // 对模型变换矩阵进行缩放变换
    static void Scale(float x, float y, float z);

    // 设置摄像机参数
    static void SetLookAt(glm::vec3 eye, glm::vec3 center, glm::vec3 up);
    // 设置摄像机参数
    static void SetLookAt(
        float eyeX, float eyeY, float eyeZ,
        float centerX, float centerY, float centerZ,
        float upX, float upY, float upZ
    );

    // 设置正交投影参数
    static void SetOrthoProjection(
        float left, float right,
        float bottom, float top,
        float near, float far
    );
    // 设置透视投影参数 frustum
    static void SetPerspProjection(
        float left, float right,
        float bottom, float top,
        float near, float far
    );
    // 设置透视投影参数 perspective
    static void SetPerspProjection(
        float fovy, float aspect,
        float near, float far
    );

    // 获取模型变换矩阵
    static glm::mat4 GetMMatrix();
    // 获取视图变换矩阵
    static glm::mat4 GetVMatrix();
    // 获取投影变换矩阵
    static glm::mat4 GetPMatrix();
    // 获取投影与视图组合矩阵
    static glm::mat4 GetVPMatrix();
    // 获取总变换矩阵
    static glm::mat4 GetMVPMatrix();
};
