#include "Component.h"

Component::Component() {
    gameObject = nullptr;
    transform = nullptr;
}

bool Component::Create(GameObject *gameObject) {
    this->gameObject = gameObject;
    this->transform = &(gameObject->GetTransform());
    return true;
}

void Component::Update() {}

void Component::Destroy() {}
