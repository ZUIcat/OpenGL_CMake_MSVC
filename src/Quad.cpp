#include "Quad.h"

Quad::Quad(unsigned int texID01) {
    this->texID01 = texID01;
    name = "Quad";
}

bool Quad::Create(GameObject *gameObject) {
    if (!Component::Create(gameObject)) {
        return false;
    }

    if (!CreateShader()) {
        std::cout << "[ERROR] " << name << ": Could not CreateShader" << std::endl;
        return false;
    }
    if (!CreateData()) {
        std::cout << "[ERROR] " << name << ": Could not CreateData" << std::endl;
        return false;
    }
    if (!InitShaderValue()) {
        std::cout << "[ERROR] " << name << ": Could not InitShaderValue" << std::endl;
        return false;
    }

    return true;
}

bool Quad::CreateShader() {
    return ShaderUtil::CreateShaderProgram(shaderProgram, "./shader/001.vert", "./shader/001.frag") &&
           ShaderUtil::GetUniformLocation(uMVPMatrixHandle, shaderProgram, "uMVPMatrix") &&
           ShaderUtil::GetAttribLocation(vPosHandle, shaderProgram, "vPos") &&
           ShaderUtil::GetAttribLocation(vColorHandle, shaderProgram, "vColor") &&
           ShaderUtil::GetAttribLocation(vTexCoordHandle, shaderProgram, "vTexCoord") &&
           ShaderUtil::GetUniformLocation(uTextureHandle, shaderProgram, "uTexture");
}

bool Quad::CreateData() {
    float vertices[] = {
        -0.5f, 0.5f,  0.0f, // top left
        -0.5f, -0.5f, 0.0f, // bottom left
        0.5f,  -0.5f, 0.0f, // bottom right
        0.5f,  0.5f,  0.0f  // top right
    };
    float colors[] = {
        1.0f, 0.0f, 0.0f, 1.0f, // top left
        0.0f, 1.0f, 0.0f, 1.0f, // bottom left
        0.0f, 0.0f, 1.0f, 1.0f, // bottom right
        1.0f, 1.0f, 0.0f, 1.0f  // top right
    };
    float texCoords[] = {
        0.0f, 0.0f, // top left
        0.0f, 1.0f, // bottom left
        1.0f, 1.0f, // bottom right
        1.0f, 0.0f  // top right
    };
    unsigned int indices[] = {
        // note that we start from 0
        0, 1, 3, // first Triangle
        1, 2, 3  // second Triangle
    };

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // 一个顶点数组对象会储存以下这些内容：
    // glEnableVertexAttribArray 和 glDisableVertexAttribArray 的调用。
    // 通过 glVertexAttribPointer 设置的顶点属性配置。
    // 通过 glVertexAttribPointer 调用与顶点属性关联的顶点缓冲对象。

    glGenBuffers(1, &VBO01);
    glBindBuffer(GL_ARRAY_BUFFER, VBO01);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 每个顶点属性从一个 VBO 管理的内存中获得它的数据, 而具体是从哪个 VBO (程序中可以有多个 VBO)
    // 获取则是通过在调用 glVertexAttribPointer 时绑定到 GL_ARRAY_BUFFER 的 VBO 决定的。
    // 由于在调用 glVertexAttribPointer 之前绑定的是先前定义的 VBO 对象, 顶点属性 0 现在会链接到它的顶点数据
    glVertexAttribPointer(vPosHandle, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(vPosHandle);

    glGenBuffers(1, &VBO03);
    glBindBuffer(GL_ARRAY_BUFFER, VBO03);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

    glVertexAttribPointer(vColorHandle, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(vColorHandle);

    glGenBuffers(1, &VBO02);
    glBindBuffer(GL_ARRAY_BUFFER, VBO02);
    glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);

    glVertexAttribPointer(vTexCoordHandle, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(vTexCoordHandle);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // 当目标是 GL_ELEMENT_ARRAY_BUFFER 的时候，VAO 会储存 glBindBuffer 的函数调用。这也意味着它也会储存解绑调用，
    // 所以确保你没有在解绑 VAO 之前解绑索引数组缓冲，否则它就没有这个 EBO 配置了。
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    return true;
}

bool Quad::InitShaderValue() {
    // shader
    glUseProgram(shaderProgram);
    // texture
    glActiveTexture(GL_TEXTURE0); // 激活纹理单元
    glBindTexture(GL_TEXTURE_2D, texID01); // 绑定这个纹理到当前激活的纹理单元（纹理单元 GL_TEXTURE0 默认总是被激活）
    glUniform1i(static_cast<int>(uTextureHandle), 0); // 定义哪个 uniform 采样器对应哪个纹理单元
    // vertex buffer
    glBindVertexArray(VAO); // TODO 估计这东西不能放这里，可能需要每次 Update 的时候用

    return true;
}

void Quad::Update() {
    // shader
    glUseProgram(shaderProgram);
    // matrix
    glUniformMatrix4fv(static_cast<int>(uMVPMatrixHandle), 1, GL_FALSE, glm::value_ptr(MartrixUtil::GetMVPMatrix(transform->getMMatrix())));
    // glDrawArrays(GL_TRIANGLES, 0, 6);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    // glBindVertexArray(0); // no need to unbind it every time
}

void Quad::Destroy() {
    // optional: de-allocate all resources once they've outlived their purpose:
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO01);
    glDeleteBuffers(1, &VBO02);
    glDeleteBuffers(1, &VBO03);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);
}
