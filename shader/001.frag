#version 330 core

uniform sampler2D uTexture;

in vec2 fTexCoord;
in vec4 fColor;

out vec4 FragColor;

void main()
{
    vec4 texColor = texture(uTexture, fTexCoord);
//    FragColor = texColor * max(vec4(1.0f), fColor);
    if(texColor.a == 0.0f) {
        FragColor = vec4(1.0f, 0.0f, 0.0f, 0.0f);
    } else {
        FragColor = texColor * max(vec4(1.0f), fColor);
    }
}
