#include "CameraUtil.h"

float CameraUtil::cameraParm[9] = {}; // TODO C++ 各种初始化规则
float CameraUtil::cameraXAngle = 0;
float CameraUtil::cameraYAngle = 0;

void CameraUtil::SetCamera(
    float eyeX, float eyeY, float eyeZ,
    float centerX, float centerY, float centerZ,
    float upX, float upY, float upZ
) {
    // 记录摄像机参数
    cameraParm[0] = eyeX;
    cameraParm[1] = eyeY;
    cameraParm[2] = eyeZ;
    cameraParm[3] = centerX;
    cameraParm[4] = centerY;
    cameraParm[5] = centerZ;
    cameraParm[6] = upX;
    cameraParm[7] = upY;
    cameraParm[8] = upZ;
    // 设置摄像机参数
    MartrixUtil::SetLookAt(
        cameraParm[0], cameraParm[1], cameraParm[2],
        cameraParm[3], cameraParm[4], cameraParm[5],
        cameraParm[6], cameraParm[7], cameraParm[8]
    );
}

void CameraUtil::RotateIn2AxisForInitPos(float xAngle, float yAngle) {
    // 让摄像机根据自身坐标系转多少有点麻烦
    // 不加任何处理的话则又是直接沿着世界坐标系转，用着不对劲
    // 所以默认摄像机包含纵向和横向的两个轴，它只会分别沿着这两个轴转
    // 像是一个父子节点，父节点只动 Y 轴，子节点只动 X 轴
    // 这样父节点就是世界坐标系下的变化，子节点是物体坐标系下的变化
    // PosNew = matrixY * matrixX * PosInitial

    cameraXAngle = xAngle; // TODO from initial pos
    cameraYAngle = yAngle;
 
    glm::mat4 matrixY = glm::rotate(glm::mat4(1.0f), cameraYAngle, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 matrixYX = glm::rotate(matrixY, cameraXAngle, glm::vec3(1.0f, 0.0f, 0.0f));

    glm::vec4 centerVec = glm::vec4(cameraParm[3] - cameraParm[0], cameraParm[4] - cameraParm[1], cameraParm[5] - cameraParm[2], 0.0f);
    centerVec = glm::normalize(matrixYX * centerVec);
    cameraParm[3] = cameraParm[0] + centerVec.x;
    cameraParm[4] = cameraParm[1] + centerVec.y;
    cameraParm[5] = cameraParm[2] + centerVec.z;

    glm::vec4 upVec = glm::vec4(cameraParm[6], cameraParm[7], cameraParm[8], 0.0f);
    upVec = glm::normalize(matrixYX * upVec);
    cameraParm[6] = upVec.x;
    cameraParm[7] = upVec.y;
    cameraParm[8] = upVec.z;

    // 设置摄像机参数
    MartrixUtil::SetLookAt(
        cameraParm[0], cameraParm[1], cameraParm[2],
        cameraParm[3], cameraParm[4], cameraParm[5],
        cameraParm[6], cameraParm[7], cameraParm[8]
    );
}

void CameraUtil::Rotate(float x, float y, float z, float angle) {}

void CameraUtil::Surround(float x, float y, float z, float angle) {}

void CameraUtil::Move(float x, float y, float z) {
    // 移动摄像机位置
    cameraParm[0] += x;
    cameraParm[1] += y;
    cameraParm[2] += z;
    // 移动视线目标点位置
    cameraParm[3] += x;
    cameraParm[4] += y;
    cameraParm[5] += z;
    // 设置摄像机参数
    MartrixUtil::SetLookAt(
        cameraParm[0], cameraParm[1], cameraParm[2],
        cameraParm[3], cameraParm[4], cameraParm[5],
        cameraParm[6], cameraParm[7], cameraParm[8]
    );
}

void CameraUtil::Zoom(float distance) {
    // 获取摄像机到视线目标点的视线向量
    float fx = cameraParm[3] - cameraParm[0];
    float fy = cameraParm[4] - cameraParm[1];
    float fz = cameraParm[5] - cameraParm[2];
    // 获取该向量长度
    float fLength = static_cast<float>(std::sqrt(std::pow(fx, 2) + std::pow(fy, 2) + std::pow(fz, 2)));
    // 单位化该向量 // TODO 不用每次单位化
    fx /= fLength;
    fy /= fLength;
    fz /= fLength;
    // 将摄像机位置沿视线向量方向推进 distance 距离
    cameraParm[0] += fx * distance;
    cameraParm[1] += fy * distance;
    cameraParm[2] += fz * distance;
    // 将视线目标点沿视线向量方向推进 distance 距离
    cameraParm[3] += fx * distance;
    cameraParm[4] += fy * distance;
    cameraParm[5] += fz * distance;
    // 设置摄像机参数
    MartrixUtil::SetLookAt(
        cameraParm[0], cameraParm[1], cameraParm[2],
        cameraParm[3], cameraParm[4], cameraParm[5],
        cameraParm[6], cameraParm[7], cameraParm[8]
    );
}
