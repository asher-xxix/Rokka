#pragma once

#include <iostream>
// #include "../../../libs/GLFW/glfw3.h"
#include <GLFW/glfw3.h>

namespace rokka { namespace graphics {

    class Window {
    private:
      const char *m_Title;
      int m_Width, m_Height;
      GLFWwindow *m_Window;
      bool m_Closed;

      bool Init();


    public:
      Window(const char *title, int width, int height);
      ~Window();
      bool closed() const;
      void Update();
      void clear() const;

      inline int getWidth() const { return m_Width; }
      inline int getHeight() const { return m_Height; }

    };

} }
