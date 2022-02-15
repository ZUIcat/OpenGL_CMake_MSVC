#include "GameObject.h"

GameObject::GameObject() {
    transform = Transform();
    components = std::vector<Component *>();
}

bool GameObject::Create() {
    bool success = true;
    for (int i = 0; i < components.size(); i++) {
        success = success && components.at(i)->Create(this);
    }
    return success;
}

void GameObject::Update() {
    for (int i = 0; i < components.size(); i++) {
        components.at(i)->Update();
    }
}

void GameObject::Destroy() {
    for (int i = 0; i < components.size(); i++) {
        Component *tempPointer = components.at(i);
        tempPointer->Destroy();
        delete (tempPointer);
    }
    components.clear();
}

Transform &GameObject::GetTransform() { return transform; }

std::vector<Component *> &GameObject::GetComponents() { return components; }
