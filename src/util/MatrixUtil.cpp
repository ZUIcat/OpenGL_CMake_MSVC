#include "MartrixUtil.h"

// TODO Why float not double

std::stack<glm::mat4> MartrixUtil::MMatrixStack = std::stack<glm::mat4>();
glm::mat4 MartrixUtil::MMatrix = glm::mat4(1.0f);
glm::mat4 MartrixUtil::VMatrix = glm::mat4(1.0f);
glm::mat4 MartrixUtil::PMatrix = glm::mat4(1.0f);

void MartrixUtil::Push() {
    MMatrixStack.push(MMatrix);
}

void MartrixUtil::Pop() {
    MMatrix = MMatrixStack.top();
    MMatrixStack.pop();
}

void MartrixUtil::Translate(float x, float y, float z) {
    // 因为默认 原矩阵 * 变换矩阵 的形式不符合直觉，先不管效率，都改成 变换矩阵 * 原矩阵 的形式
    // MMatrix = glm::translate(MMatrix, glm::vec3(x, y, z));
    glm::mat4 translateM = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));
    MMatrix = translateM * MMatrix;
}

void MartrixUtil::Rotate(float x, float y, float z, float angle) {
    // 因为默认 原矩阵 * 变换矩阵 的形式不符合直觉，先不管效率，都改成 变换矩阵 * 原矩阵 的形式
    // MMatrix = glm::rotate(MMatrix, angle, glm::vec3(x, y, z));
    glm::mat4 rotateM = glm::rotate(MMatrix, angle, glm::vec3(x, y, z));
    MMatrix = rotateM * MMatrix;
}

void MartrixUtil::Scale(float x, float y, float z) {
    // 因为默认 原矩阵 * 变换矩阵 的形式不符合直觉，先不管效率，都改成 变换矩阵 * 原矩阵 的形式
    // MMatrix = glm::scale(MMatrix, glm::vec3(x, y, z));
    glm::mat4 scaleM = glm::scale(MMatrix, glm::vec3(x, y, z));
    MMatrix = scaleM * MMatrix;
}

void MartrixUtil::SetLookAt(glm::vec3 eye, glm::vec3 center, glm::vec3 up) {
    VMatrix = glm::lookAt(eye, center, up);
}

void MartrixUtil::SetLookAt(
    float eyeX, float eyeY, float eyeZ,
    float centerX, float centerY, float centerZ,
    float upX, float upY, float upZ
) {
    VMatrix = glm::lookAt(
        glm::vec3(eyeX, eyeY, eyeZ),
        glm::vec3(centerX, centerY, centerZ),
        glm::vec3(upX, upY, upZ)
    );
}

void MartrixUtil::SetOrthoProjection(
    float left, float right,
    float bottom, float top,
    float near, float far
) {
    PMatrix = glm::ortho(left, right, bottom, top, near, far);
}

void MartrixUtil::SetPerspProjection(
    float left, float right,
    float bottom, float top,
    float near, float far
) {
    PMatrix = glm::frustum(left, right, bottom, top, near, far);
}

void MartrixUtil::SetPerspProjection(
    float fovy, float aspect,
    float near, float far
) {
    PMatrix = glm::perspective(fovy, aspect, near, far);
}

glm::mat4 MartrixUtil::GetMMatrix() {
    return MMatrix;
}

glm::mat4 MartrixUtil::GetVMatrix() {
    return VMatrix;
}

glm::mat4 MartrixUtil::GetPMatrix() {
    return PMatrix;
}

glm::mat4 MartrixUtil::GetVPMatrix() {
    return PMatrix * VMatrix;
}

glm::mat4 MartrixUtil::GetMVPMatrix() {
    return PMatrix * VMatrix * MMatrix;
}

glm::mat4 MartrixUtil::GetMVPMatrix(glm::mat4 m_MMatrix) {
    return PMatrix * VMatrix * m_MMatrix;
}
