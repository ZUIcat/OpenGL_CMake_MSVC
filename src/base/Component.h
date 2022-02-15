#pragma once

#include "../util/MartrixUtil.h"
#include "../util/ShaderUtil.h"
#include "../util/TextureUtil.h"
#include "../util/CameraUtil.h"
#include "GameObject.h"

class GameObject; // TODO 前置引用
class Transform;  // TODO 前置引用

class Component {
  private:
  protected:
    GameObject *gameObject;
    Transform *transform;

  public:
    explicit Component();
    virtual ~Component() = default;

    virtual bool Create(GameObject *gameObject);
    virtual void Update();
    virtual void Destroy();
};
