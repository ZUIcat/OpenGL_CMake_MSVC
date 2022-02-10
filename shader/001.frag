#version 330 core

uniform sampler2D uTexture;

in vec2 fTexCoord;
in vec4 fColor;

out vec4 FragColor;

void main()
{
    FragColor = texture(uTexture, fTexCoord) * fColor;
}
