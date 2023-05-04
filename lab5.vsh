#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 projection_mat;
uniform mat4 modelview_mat;

out vec3 aPoss;

void main(void)
{
    aPoss = aPos;
    gl_Position = projection_mat * (modelview_mat * vec4(aPos.x, aPos.y, aPos.z, 1));
}
