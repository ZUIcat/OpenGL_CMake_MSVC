#pragma once

#include <iostream>
#include "base/Component.h"

class Rectangle : public Component {
  private:
    std::string name;

    unsigned int shaderProgram;

    unsigned int uMVPMatrixHandle;
    unsigned int vPosHandle;
    unsigned int vColorHandle;
    unsigned int vTexCoordHandle;

    unsigned int uTextureHandle;

    unsigned int VAO, VBO01, VBO02, VBO03, EBO;
    unsigned int texID01;

  public:
    explicit Rectangle(unsigned int texID01);
    // virtual ~Rectangle() override;

    virtual bool Create(GameObject gameObject) override;
    virtual void DrawSelf() override;
    virtual void Destroy() override;

    bool CreateShader();
    bool CreateData();
};
