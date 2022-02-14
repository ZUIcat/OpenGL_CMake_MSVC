#include "Transform.h"

Transform::Transform() {
    position = glm::vec3(0.0f);
    rotation = glm::vec3(0.0f);
    scale = glm::vec3(1.0f);

    forward = glm::vec3(0.0f, 0.0f, -1.0f); // 默认面朝 -Z
    up = glm::vec3(0.0f, 1.0f, 0.0f);
    right = glm::vec3(1.0f, 0.0f, 0.0f);

    positionMatrix = glm::mat4(1.0f);
    rotationMatrix = glm::mat4(1.0f);
    scaleMatrix = glm::mat4(1.0f);

    needUpdate = false;
}

glm::vec3 Transform::GetPosition() { return position; }

void Transform::SetPosition(const float &x, const float &y, const float &z) {
    position.x = x;
    position.y = y;
    position.z = z;

    positionMatrix = glm::translate(glm::mat4(1.0f), position);

    needUpdate = true;
}

glm::vec3 Transform::GetRotation() { return rotation; }

void Transform::SetRotation(const float &x, const float &y, const float &z) {
    rotation.x = x;
    rotation.y = y;
    rotation.z = z;

    rotationMatrix = glm::rotate(glm::mat4(1.0f), rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    rotationMatrix = glm::rotate(rotationMatrix, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    rotationMatrix = glm::rotate(rotationMatrix, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
 
    needUpdate = true;
}

glm::vec3 Transform::GetScale() { return scale; }

void Transform::SetScale(const float &x, const float &y, const float &z) {
    scale.x = x;
    scale.y = y;
    scale.z = z;

    positionMatrix = glm::scale(glm::mat4(1.0f), scale);

    needUpdate = true;
}

glm::mat4 Transform::GetPositionMatrix() { return positionMatrix; }

glm::mat4 Transform::GetRotationMatrix() { return rotationMatrix; }

glm::mat4 Transform::GetScaleMatrix() { return scaleMatrix; }

glm::mat4 Transform::getMMatrix() { return positionMatrix * rotationMatrix * scaleMatrix; }

glm::vec3 Transform::GetForward() {
    DoUpdate();
    return forward;
}

glm::vec3 Transform::GetUp() {
    DoUpdate();
    return up;
}

glm::vec3 Transform::GetRight() {
    DoUpdate();
    return right;
}

void Transform::DoUpdate() {
    if (!needUpdate) {
        return;
    }
    ForceUpdate();
}

void Transform::ForceUpdate() {
    glm::mat4 tmpMat = positionMatrix * rotationMatrix * scaleMatrix;

    glm::vec4 tmpForward = tmpMat * glm::vec4(0.0f, 0.0f, -1.0f, 1.0f);
    forward.x = tmpForward.x;
    forward.y = tmpForward.y;
    forward.z = tmpForward.z;
    forward = glm::normalize(forward);

    glm::vec4 tmpUp = tmpMat * glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
    up.x = tmpUp.x;
    up.y = tmpUp.y;
    up.z = tmpUp.z;
    up = glm::normalize(up);

    glm::vec4 tmpRight = tmpMat * glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
    right.x = tmpRight.x;
    right.y = tmpRight.y;
    right.z = tmpRight.z;
    right = glm::normalize(right);

    needUpdate = false;
}
