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

    glm::vec3 getPosition();
    void setPosition(float x, float y, float z);

    glm::vec3 getRotation();
    void setRotation(float x, float y, float z);

    glm::vec3 getScale();
    void setScale(float x, float y, float z);

    glm::mat4 getPositionMatrix();
    glm::mat4 getRotationMatrix();
    glm::mat4 getScaleMatrix();
    glm::vec3 getForward();
    glm::vec3 getUp();
    glm::vec3 getRight();

    void doUpdate();
    void forceUpdate();
};
