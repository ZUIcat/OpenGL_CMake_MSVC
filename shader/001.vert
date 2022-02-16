#version 330 core

// https://docs.gl/

uniform mat4 uMVPMatrix;

in vec3 vPos;
in vec4 vColor;
in vec2 vTexCoord;

out vec2 fTexCoord;
out vec4 fColor;

void main()
{
    fTexCoord = vTexCoord;
    fColor = vColor;
    gl_Position = uMVPMatrix * vec4(vPos.x, vPos.y, vPos.z, 1.0f);
}
