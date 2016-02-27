#include "window.h"

namespace rokka { namespace graphics {

  void windowResize(GLFWwindow *window, int width, int height);

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
    glfwSetWindowSizeCallback(m_Window, windowResize);

    if(glewInit() != GLEW_OK) {
      std::cout << "Could not initialize GLEW!" << std::endl;
      return false;
    }

    return true;
  }

  void Window::Update() {
    glfwPollEvents();
    glfwSwapBuffers(m_Window);
  }

  void Window::clear() const {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  }

  bool Window::closed() const {
    return glfwWindowShouldClose(m_Window) == 1;
  }

  void windowResize(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
  }



} }
