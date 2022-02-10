#pragma once

#include "MartrixUtil.h"
#include "ShaderUtil.h"
#include "CameraUtil.h"

class GLDrawble {
  private:
  public:
    // 自身的模型变换矩阵
    // TODO private
    // glm::mat4 selfMMatrix = glm::mat4(1.0f);

    // GLDrawble();
    virtual ~GLDrawble() = default;

    virtual bool Create() = 0;
    virtual void DrawSelf() = 0;
    virtual void Destroy() = 0;
};
