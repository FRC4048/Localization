//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: ixfun.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

#ifndef IXFUN_H
#define IXFUN_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
void expand_max(const ::coder::array<double, 2U> &a,
                ::coder::array<double, 2U> &c);

void expand_min(const double a[2], const ::coder::array<double, 2U> &b,
                ::coder::array<double, 2U> &c);

void expand_min(const ::coder::array<double, 2U> &a, const double b[2],
                ::coder::array<double, 2U> &c);

void expand_mod(const ::coder::array<double, 2U> &a, const double b[2],
                ::coder::array<double, 2U> &c);

} // namespace internal
} // namespace coder

#endif
//
// File trailer for ixfun.h
//
// [EOF]
//
