#pragma once

#include <iostream>
#include <cmath>

#include "MartrixUtil.h"

class Transform {
  private:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

    glm::vec3 forward;
    glm::vec3 up;
    glm::vec3 right;

    bool needUpdate;

  public:
    explicit Transform();
    virtual ~Transform() = default;

    glm::vec3 getPosition();
    void setPosition(float x, float y, float z);

    glm::vec3 getRotation();
    void setRotation(float x, float y, float z);

    glm::vec3 getScale();
    void setScale(float x, float y, float z);

    glm::vec3 getForward();
    glm::vec3 getUp();
    glm::vec3 getRight();

    void forceUpdate();
};
