#version 330 core

layout(location = 0) out Vec4 color;

uniform mat4 pr_matrix;
uniform mat4 vw_matrix = mat4(1.0);
uniform mat4 ml_matrix = mat4(1.0);


void main() {
  color = Vec4(1.0, 0.0, 1.0, 1.0);
}
