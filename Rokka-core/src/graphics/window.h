#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace rokka { namespace graphics {

#define MAX_KEYS            1024
#define MAX_BUTTONS         32

    class Window {
    private:
      const char *m_Title;
      int m_Width, m_Height;
      GLFWwindow *m_Window;
      bool m_Closed;

      bool Init();
      friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
      friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

      static bool m_Keys[MAX_KEYS];
      static bool m_MouseButtons[MAX_BUTTONS];
      static double m_MouseX, m_MouseY;



    public:
      Window(const char *title, int width, int height);
      ~Window();
      bool closed() const;
      void Update();
      void clear() const;

      inline int getWidth() const { return m_Width; }
      inline int getHeight() const { return m_Height; }

      static bool isKeyPressed(unsigned int keycode);
      static bool isMouseButtonPressed(unsigned int button);
    };

} }
