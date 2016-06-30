#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <vector>
#include <GL/glew.h>
#include "../utils/fileutils.h"

namespace rokka { namespace graphics {

  class Shader {
  private:
    GLuint m_ShaderID;
    // keeping these paths up here for debug purposes
    const char* m_VertPath;
    const char* m_FragPath;

    GLuint load();

  public:
    Shader(const char* vertPath, const char* fragPath);
    ~Shader();

    void enable() const;
    void disable() const;






  };




}}


#endif
