//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: amcl_test_rtwutil.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

// Include Files
#include "amcl_test_rtwutil.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
double rt_atan2d_snf(double u0, double u1)
{
  double y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = rtNaN;
  } else if (std::isinf(u0) && std::isinf(u1)) {
    int i;
    int i1;
    if (u0 > 0.0) {
      i = 1;
    } else {
      i = -1;
    }
    if (u1 > 0.0) {
      i1 = 1;
    } else {
      i1 = -1;
    }
    y = std::atan2(static_cast<double>(i), static_cast<double>(i1));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = std::atan2(u0, u1);
  }
  return y;
}

//
// File trailer for amcl_test_rtwutil.cpp
//
// [EOF]
//
