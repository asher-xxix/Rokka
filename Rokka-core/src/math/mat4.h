#ifndef MAT4_H
#define MAT4_H

// #define _USE_MATH_DEFINES
#include "math.h"
// #include <math.h>

namespace rokka { namespace math {

  struct Mat4 {
    float elements[4 * 4];

    Mat4();
    Mat4(float diagonal);

    static Mat4 identity();

    // multiples current matrix by what is specified and returns it
    Mat4& multiply(const Mat4& other);
    friend Mat4 operator*(Mat4 left, const Mat4& right);
    Mat4& operator*=(const Mat4& other);

    static Mat4 orthographic(float left, float right, float top, float bottom, float near, float far);
    static Mat4 perspective(float fov, float aspectRatio, float near, float far);

    static Mat4 translation(const Vec3& translation);
    static Mat4 scale(const Vec3& scale);
    static Mat4 rotation(float angle, const Vec3& axis);




  };



}}

#endif
