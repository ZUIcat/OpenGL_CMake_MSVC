#pragma once

#include <iostream>
#include <cmath>

#include "MartrixUtil.h"

class CameraUtil {
  private:
    explicit CameraUtil() = default;

    static float cameraParm[9];
    static float cameraXAngle;
    static float cameraYAngle;

  public:
    virtual ~CameraUtil() = default;

    // 设置摄像机参数
    static void SetCamera(
        float eyeX, float eyeY, float eyeZ,
        float centerX, float centerY, float centerZ,
        float upX, float upY, float upZ
    );

    // 只用纵横两个轴旋转摄像机（以自己为中心）
    static void RotateIn2AxisForInitPos(float xAngle, float yAngle);

    // 旋转摄像机（以自己为中心）
    static void Rotate(float x, float y, float z, float angle);

    // 环绕摄像机（以视点为中心）
    static void Surround(float x, float y, float z, float angle);

    // 移动摄像机
    static void Move(float x, float y, float z);

    // 推拉摄像机
    static void Zoom(float distance);
};
