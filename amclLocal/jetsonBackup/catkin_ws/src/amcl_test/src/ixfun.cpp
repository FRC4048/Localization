//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: ixfun.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

// Include Files
#include "ixfun.h"
#include "mod.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &a
//                ::coder::array<double, 2U> &c
// Return Type  : void
//
namespace coder {
namespace internal {
void expand_max(const ::coder::array<double, 2U> &a,
                ::coder::array<double, 2U> &c)
{
  c.set_size(a.size(0), 2);
  if (a.size(0) != 0) {
    for (int k{0}; k < 2; k++) {
      int i;
      i = c.size(0) - 1;
      for (int b_k{0}; b_k <= i; b_k++) {
        c[b_k + c.size(0) * k] = std::fmax(a[b_k + a.size(0) * k], 1.0);
      }
    }
  }
}

//
// Arguments    : const double a[2]
//                const ::coder::array<double, 2U> &b
//                ::coder::array<double, 2U> &c
// Return Type  : void
//
void expand_min(const double a[2], const ::coder::array<double, 2U> &b,
                ::coder::array<double, 2U> &c)
{
  c.set_size(b.size(0), 2);
  if (b.size(0) != 0) {
    for (int k{0}; k < 2; k++) {
      int i;
      i = c.size(0) - 1;
      for (int b_k{0}; b_k <= i; b_k++) {
        c[b_k + c.size(0) * k] = std::fmin(a[k], b[b_k + b.size(0) * k]);
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &a
//                const double b[2]
//                ::coder::array<double, 2U> &c
// Return Type  : void
//
void expand_min(const ::coder::array<double, 2U> &a, const double b[2],
                ::coder::array<double, 2U> &c)
{
  c.set_size(a.size(0), 2);
  if (a.size(0) != 0) {
    for (int k{0}; k < 2; k++) {
      int i;
      i = c.size(0) - 1;
      for (int b_k{0}; b_k <= i; b_k++) {
        c[b_k + c.size(0) * k] = std::fmin(a[b_k + a.size(0) * k], b[k]);
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &a
//                const double b[2]
//                ::coder::array<double, 2U> &c
// Return Type  : void
//
void expand_mod(const ::coder::array<double, 2U> &a, const double b[2],
                ::coder::array<double, 2U> &c)
{
  c.set_size(a.size(0), 2);
  if (a.size(0) != 0) {
    for (int k{0}; k < 2; k++) {
      int i;
      i = c.size(0) - 1;
      for (int b_k{0}; b_k <= i; b_k++) {
        c[b_k + c.size(0) * k] = scalar::b_mod(a[b_k + a.size(0) * k], b[k]);
      }
    }
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for ixfun.cpp
//
// [EOF]
//
