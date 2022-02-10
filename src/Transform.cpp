#include "Transform.h"

// bool Transform::needUpdate;

Transform::Transform() {
    position = glm::vec3(0.0f);
    rotation = glm::vec3(0.0f);
    scale = glm::vec3(1.0f);

    forward = glm::vec3(0.0f, 0.0f, -1.0f); // 默认面朝 -Z
    up = glm::vec3(0.0f, 1.0f, 0.0f);
    right = glm::vec3(1.0f, 0.0f, 0.0f);
}
