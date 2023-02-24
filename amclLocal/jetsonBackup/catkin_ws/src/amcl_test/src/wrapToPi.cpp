//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: wrapToPi.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

// Include Files
#include "wrapToPi.h"
#include "mod.h"
#include "rt_nonfinite.h"
#include "wrapTo2Pi.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : ::coder::array<double, 1U> &theta
// Return Type  : void
//
namespace coder {
namespace robotics {
namespace internal {
void wrapToPi(::coder::array<double, 1U> &theta)
{
  array<double, 1U> y;
  array<bool, 1U> x;
  int nx;
  bool b_y;
  bool exitg1;
  nx = theta.size(0);
  y.set_size(theta.size(0));
  for (int k{0}; k < nx; k++) {
    y[k] = std::abs(theta[k]);
  }
  x.set_size(y.size(0));
  nx = y.size(0);
  for (int k{0}; k < nx; k++) {
    x[k] = (y[k] > 3.1415926535897931);
  }
  b_y = false;
  nx = 1;
  exitg1 = false;
  while ((!exitg1) && (nx <= x.size(0))) {
    if (x[nx - 1]) {
      b_y = true;
      exitg1 = true;
    } else {
      nx++;
    }
  }
  if (b_y) {
    y.set_size(theta.size(0));
    nx = theta.size(0);
    for (int k{0}; k < nx; k++) {
      y[k] = theta[k] + 3.1415926535897931;
    }
    theta.set_size(y.size(0));
    nx = y.size(0);
    for (int k{0}; k < nx; k++) {
      double varargin_1;
      varargin_1 = y[k];
      theta[k] =
          ::coder::internal::scalar::b_mod(varargin_1, 6.2831853071795862);
    }
    if (theta.size(0) == y.size(0)) {
      x.set_size(theta.size(0));
      nx = theta.size(0);
      for (int k{0}; k < nx; k++) {
        x[k] = ((theta[k] == 0.0) && (y[k] > 0.0));
      }
    } else {
      c_binary_expand_op(x, theta, y);
    }
    nx = x.size(0);
    for (int k{0}; k < nx; k++) {
      if (x[k]) {
        theta[k] = 6.2831853071795862;
      }
    }
    nx = theta.size(0);
    for (int k{0}; k < nx; k++) {
      theta[k] = theta[k] - 3.1415926535897931;
    }
  }
}

} // namespace internal
} // namespace robotics
} // namespace coder

//
// File trailer for wrapToPi.cpp
//
// [EOF]
//
