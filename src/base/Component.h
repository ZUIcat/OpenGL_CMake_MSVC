#pragma once

#include "../util/MartrixUtil.h"
#include "../util/ShaderUtil.h"
#include "../util/TextureUtil.h"
#include "../util/CameraUtil.h"
#include "GameObject.h"

class Component {
  private:
    GameObject gameObject;

  public:
    // Component();
    virtual ~Component() = default;

    virtual bool Create(GameObject gameObject) = 0;
    virtual void DrawSelf() = 0;
    virtual void Destroy() = 0;
};
