#include "window.h"

namespace rokka { namespace graphics {

  Window::Window(const char *title, int width, int height) {
    m_Title = title;
    m_Width = width;
    m_Height = height;
    if(!Init()) glfwTerminate();
  }

  Window::~Window() {
    glfwTerminate();
  }

  bool Window::Init() {
    if(!glfwInit()) {
      std::cout << "Failed to initialize GLFW!" << std::endl;
      return false;
    }

    m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

    if(!m_Window) {
      glfwTerminate();
      std::cout << "Failed to create GFLW window!" << std::endl;
      return false;
    }
    glfwMakeContextCurrent(m_Window);
    return true;
  }

  void Window::clear() const {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  }

  bool Window::closed() const {
    return glfwWindowShouldClose(m_Window) == 1;
  }

  void Window::Update() {
    glfwPollEvents();
    glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
    glViewport(0, 0, m_Width, m_Height);
    glfwSwapBuffers(m_Window);

  }

} }
