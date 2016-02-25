// #include "../../libs/GLFW/glfw3.h"
#include <GLFW/glfw3.h>

#include <iostream>
#include "./graphics/window.h"

int main() {
  using namespace rokka;
  using namespace graphics;

  Window window("Rokka", 800, 600);

  while(!window.closed()) {
    window.Update();
  }

  return 0;
}
