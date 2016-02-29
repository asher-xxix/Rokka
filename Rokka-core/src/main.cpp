#include "./graphics/window.h"
#include "./math/vec2.h"


int main() {
  using namespace rokka;
  using namespace graphics;

  Window window("Rokka", 800, 600);
  glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  while(!window.closed()) {
    window.clear();
    if(window.isKeyPressed(GLFW_KEY_A)) {
      std::cout << "PRESSED!" << std::endl;
    }
    if(window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) {
      std::cout << "PRESSED MOUSE!" << std::endl;
    }

    double x, y;
    window.getMousePosition(x, y);
    std::cout << x << ", " << y << std::endl;

#if 0
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glEnd();
#endif
    glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
    window.Update();
  }

  return 0;
}
