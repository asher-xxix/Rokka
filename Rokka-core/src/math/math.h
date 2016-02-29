#ifndef MATH_H
#define MATH_H

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"
#include <math.h>

namespace rokka { namespace math {

  float toRadians(float degrees) {
    return degrees * (M_PI / 100.0f);
  }


}}


#endif
