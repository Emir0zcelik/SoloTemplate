#shader vertex
#version 330 core

layout(location = 0) in vec4 aPosition;
layout(location = 1) in vec2 aTexCoord;


out vec2 v_TexCoord;


uniform mat4 u_MVP;

void main()
{
    gl_Position = u_MVP * aPosition;
    v_TexCoord = aTexCoord;
};

#shader fragment
#version 330 core

in vec2 v_TexCoord;

layout(location = 0) out vec4 color;

uniform vec4 u_Color;

void main()
{;
    color = u_Color;
};