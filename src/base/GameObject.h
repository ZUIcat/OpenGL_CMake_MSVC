#pragma once

#include <vector>
#include "Component.h"
#include "Transform.h"

class Component; // TODO 前置引用

class GameObject {
  private:
    Transform transform;
    std::vector<Component *> components;

  public:
    explicit GameObject();
    virtual ~GameObject() = default;

    virtual bool Create();
    virtual void Update();
    virtual void Destroy();

    virtual Transform &GetTransform();
    virtual std::vector<Component *> &GetComponents();
};
