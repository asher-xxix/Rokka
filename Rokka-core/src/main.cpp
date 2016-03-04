#include "./graphics/window.h"
#include "./graphics/shader.h"
#include "./math/math.h"


int main() {
  using namespace rokka;
  using namespace graphics;

  Window window("Rokka", 800, 600);
  glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  Shader shader("./shaders/basic.vert", "./shaders/basic.frag");

  while(!window.closed()) {
    window.clear();
    glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
    window.Update();
  }

  return 0;
}
