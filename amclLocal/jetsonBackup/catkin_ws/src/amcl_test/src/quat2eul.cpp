//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: quat2eul.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

// Include Files
#include "quat2eul.h"
#include "amcl_test_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Declarations
static void binary_expand_op(double in1[3],
                             const coder::array<signed char, 2U> &in2,
                             const coder::array<double, 1U> &in3,
                             const coder::array<double, 1U> &in4);

// Function Definitions
//
// Arguments    : double in1[3]
//                const coder::array<signed char, 2U> &in2
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
// Return Type  : void
//
static void binary_expand_op(double in1[3],
                             const coder::array<signed char, 2U> &in2,
                             const coder::array<double, 1U> &in3,
                             const coder::array<double, 1U> &in4)
{
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  stride_0_0 = (in3.size(0) != 1);
  stride_1_0 = (in4.size(0) != 1);
  if (in4.size(0) == 1) {
    loop_ub = in3.size(0);
  } else {
    loop_ub = in4.size(0);
  }
  for (int i{0}; i < loop_ub; i++) {
    in1[in2[i] - 1] = -in3[i * stride_0_0] * 2.0 * in4[i * stride_1_0];
  }
}

//
// Arguments    : double q[4]
//                double eul[3]
// Return Type  : void
//
namespace coder {
void quat2eul(double q[4], double eul[3])
{
  array<double, 1U> r;
  array<double, 1U> x;
  array<signed char, 2U> r1;
  double aSinInput;
  double b;
  double matrix_idx_1;
  double matrix_idx_2;
  double matrix_idx_3;
  int b_trueCount;
  int k;
  int trueCount;
  bool mask1;
  bool mask2;
  aSinInput = q[0];
  matrix_idx_1 = q[1];
  matrix_idx_2 = q[2];
  matrix_idx_3 = q[3];
  b = 1.0 /
      std::sqrt(((q[0] * q[0] + q[1] * q[1]) + q[2] * q[2]) + q[3] * q[3]);
  q[0] = aSinInput * b;
  q[1] = matrix_idx_1 * b;
  q[2] = matrix_idx_2 * b;
  q[3] = matrix_idx_3 * b;
  aSinInput = -2.0 * (q[1] * q[3] - q[0] * q[2]);
  mask1 = (aSinInput >= 0.99999999999999778);
  mask2 = (aSinInput <= -0.99999999999999778);
  trueCount = 0;
  if (mask1) {
    aSinInput = 1.0;
  }
  if (mask2) {
    trueCount = 1;
  }
  for (k = 0; k < trueCount; k++) {
    aSinInput = -1.0;
  }
  mask1 = (mask1 || mask2);
  matrix_idx_1 = q[0] * q[0];
  matrix_idx_2 = q[1] * q[1];
  matrix_idx_3 = q[2] * q[2];
  b = q[3] * q[3];
  eul[0] = rt_atan2d_snf(2.0 * (q[1] * q[2] + q[0] * q[3]),
                         ((matrix_idx_1 + matrix_idx_2) - matrix_idx_3) - b);
  eul[1] = std::asin(aSinInput);
  eul[2] = rt_atan2d_snf(2.0 * (q[2] * q[3] + q[0] * q[1]),
                         ((matrix_idx_1 - matrix_idx_2) - matrix_idx_3) + b);
  trueCount = 0;
  if (mask1) {
    trueCount = 1;
  }
  x.set_size(trueCount);
  for (k = 0; k < trueCount; k++) {
    x[0] = aSinInput;
  }
  for (k = 0; k < trueCount; k++) {
    if (std::isnan(x[0])) {
      x[0] = rtNaN;
    } else if (x[0] < 0.0) {
      x[0] = -1.0;
    } else {
      x[0] = (x[0] > 0.0);
    }
  }
  b_trueCount = 0;
  if (mask1) {
    b_trueCount = 1;
  }
  r.set_size(b_trueCount);
  for (k = 0; k < b_trueCount; k++) {
    r[0] = rt_atan2d_snf(q[1], q[0]);
  }
  k = 0;
  if (mask1) {
    k = 1;
  }
  r1.set_size(1, k);
  if (mask1) {
    r1[0] = 1;
  }
  if (trueCount == b_trueCount) {
    if (trueCount - 1 >= 0) {
      eul[0] = -x[0] * 2.0 * r[0];
    }
  } else {
    binary_expand_op(eul, r1, x, r);
  }
  trueCount = 0;
  if (mask1) {
    trueCount = 1;
  }
  if (trueCount - 1 >= 0) {
    eul[2] = 0.0;
  }
}

} // namespace coder

//
// File trailer for quat2eul.cpp
//
// [EOF]
//
