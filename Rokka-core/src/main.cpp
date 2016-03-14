#include "./graphics/window.h"
#include "./graphics/shader.h"
#include "./math/math.h"


int main() {
  using namespace rokka;
  using namespace graphics;

  Window window("Rokka", 800, 600);
  glClearColor(0.2f, 0.3f, 0.8f, 1.0f);



  GLfloat vertices[] = {
    -0.5f, -0.5f, 0.0f,
    -0.5f,  0.5f, 0.0f,
     0.5f,  0.5f, 0.0f,
     0.5f,  0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f
  };


  GLuint vbo;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);

  Shader shader("./shaders/basic.vert", "./shaders/basic.frag");
  shader.enable();

  while(!window.closed()) {
    window.clear();
    glDrawArrays(GL_TRIANGLES, 0, 6);
    window.Update();
  }

  return 0;
}
