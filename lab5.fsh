#version 330 core

uniform float point_x;
uniform float point_y;

in vec3 aPoss;

void main()
{
    float r = sqrt((aPoss.x - point_x) * (aPoss.x - point_x) + (aPoss.y - point_y) * (aPoss.y - point_y));
    gl_FragColor = vec4(0.58,0,0.83, 1 - r / (2 * sqrt(2)));
}

