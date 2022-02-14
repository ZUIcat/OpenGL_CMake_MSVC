#pragma once

#include <iostream>
#include <cmath>

#include "../util/MartrixUtil.h"

class Transform {
  private:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

    glm::vec3 forward;
    glm::vec3 up;
    glm::vec3 right;

    glm::mat4 positionMatrix;
    glm::mat4 rotationMatrix;
    glm::mat4 scaleMatrix;

    bool needUpdate;

  public:
    explicit Transform();
    virtual ~Transform() = default;

    glm::vec3 GetPosition();
    void SetPosition(const float &x, const float &y, const float &z);

    glm::vec3 GetRotation();
    void SetRotation(const float &x, const float &y, const float &z);

    glm::vec3 GetScale();
    void SetScale(const float &x, const float &y, const float &z);

    glm::mat4 GetPositionMatrix();
    glm::mat4 GetRotationMatrix();
    glm::mat4 GetScaleMatrix();
    glm::mat4 getMMatrix();
    glm::vec3 GetForward();
    glm::vec3 GetUp();
    glm::vec3 GetRight();

    void DoUpdate();
    void ForceUpdate();
};
