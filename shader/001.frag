#version 330 core

uniform sampler2D uTexture;

in vec2 fTexCoord;
in vec4 fColor;

out vec4 FragColor;

void main()
{
    vec4 texColor = texture(uTexture, fTexCoord);
    FragColor = texColor * fColor;

//    if(texColor.a == 0.0f) {
//        if(texColor.r == 0.0f) {
//            FragColor = vec4(1.0f, 0.0f, 0.0f, 0.0f); // inside (0 0 0 0)
//        } else {
//            FragColor = vec4(0.0f, 1.0f, 0.0f, 0.0f); // outside (1 1 1 0)
//        }
//    } else {
//        FragColor = texColor * max(vec4(1.0f), fColor);
//    }
}
