#include "./graphics/window.h"



int main() {
  using namespace rokka;
  using namespace graphics;

  Window window("Rokka", 800, 600);
  glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

  while(!window.closed()) {
    window.clear();
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glEnd();
    window.Update();
  }

  return 0;
}
