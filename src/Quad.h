#pragma once

#include "base/Component.h"

class Quad : public Component {
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
    explicit Quad(unsigned int texID01);
    virtual ~Quad() override = default;

    virtual bool Create(GameObject *gameObject) override;
    virtual void Update() override;
    virtual void Destroy() override;

    bool CreateShader();
    bool CreateData();
    bool InitShaderValue();
};
