//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: mod.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

// Include Files
#include "mod.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : double x
//                double y
// Return Type  : double
//
namespace coder {
namespace internal {
namespace scalar {
double b_mod(double x, double y)
{
  double r;
  r = x;
  if (y == 0.0) {
    if (x == 0.0) {
      r = y;
    }
  } else if (std::isnan(x) || std::isnan(y) || std::isinf(x)) {
    r = rtNaN;
  } else if (x == 0.0) {
    r = 0.0 / y;
  } else if (std::isinf(y)) {
    if ((y < 0.0) != (x < 0.0)) {
      r = y;
    }
  } else {
    bool rEQ0;
    r = std::fmod(x, y);
    rEQ0 = (r == 0.0);
    if ((!rEQ0) && (y > std::floor(y))) {
      double q;
      q = std::abs(x / y);
      rEQ0 = !(std::abs(q - std::floor(q + 0.5)) > 2.2204460492503131E-16 * q);
    }
    if (rEQ0) {
      r = y * 0.0;
    } else if ((x < 0.0) != (y < 0.0)) {
      r += y;
    }
  }
  return r;
}

} // namespace scalar
} // namespace internal
} // namespace coder

//
// File trailer for mod.cpp
//
// [EOF]
//
