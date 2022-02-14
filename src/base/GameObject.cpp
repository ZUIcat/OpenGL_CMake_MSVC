#include "GameObject.h"

GameObject::GameObject() {
    transform = Transform();
    components = std::vector<Component>();
}

bool GameObject::Create() {
    bool success = false;
    for (int i = 0; i < components.size(); i++) {
        success = success && components.at(i).Create();
    }
    return success;
}

void GameObject::DrawSelf() {
    for (int i = 0; i < components.size(); i++) {
        components.at(i).DrawSelf();
    }
}

void GameObject::Destroy() {
    for (int i = 0; i < components.size(); i++) {
        components.at(i).Destroy();
    }
    components.clear();
}

Transform GameObject::GetTransform() { return transform; }

std::vector<Component> GameObject::GetComponents() { return components; }
