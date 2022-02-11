#pragma once

#include "../util/MartrixUtil.h"
#include "../util/ShaderUtil.h"
#include "../util/CameraUtil.h"

class GLDrawble {
  private:
  public:
    // GLDrawble();
    virtual ~GLDrawble() = default;

    virtual bool Create() = 0;
    virtual void DrawSelf() = 0;
    virtual void Destroy() = 0;
};
