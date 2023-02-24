//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: SpecialMsgUtil.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

// Include Files
#include "SpecialMsgUtil.h"
#include "amcl_test_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : coder::array<bool, 1U> &in1
//                const coder::array<bool, 1U> &in2
//                const sensor_msgs_LaserScanStruct_T *in3
//                const float in4[2]
//                const float in5[2]
// Return Type  : void
//
void b_binary_expand_op(coder::array<bool, 1U> &in1,
                        const coder::array<bool, 1U> &in2,
                        const sensor_msgs_LaserScanStruct_T *in3,
                        const float in4[2], const float in5[2])
{
  coder::array<bool, 1U> b_in1;
  float b_in4;
  float b_in5;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  b_in4 = in4[0];
  b_in5 = in5[1];
  if (in3->Ranges.size(0) == 1) {
    i = in1.size(0);
  } else {
    i = in3->Ranges.size(0);
  }
  b_in1.set_size(i);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in3->Ranges.size(0) != 1);
  stride_2_0 = (in3->Ranges.size(0) != 1);
  if (in3->Ranges.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in3->Ranges.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1[i] = ((!in1[i * stride_0_0]) && (!in2[i * stride_0_0]) &&
                (in3->Ranges[i * stride_1_0] >= b_in4) &&
                (in3->Ranges[i * stride_2_0] <= b_in5));
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<float, 1U> &in3
//                const coder::array<double, 1U> &in4
// Return Type  : void
//
void binary_expand_op(coder::array<double, 2U> &in1,
                      const coder::array<double, 1U> &in2,
                      const coder::array<float, 1U> &in3,
                      const coder::array<double, 1U> &in4)
{
  coder::array<double, 1U> b_in2;
  coder::array<double, 1U> b_in4;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    i = in2.size(0);
  } else {
    i = in3.size(0);
  }
  b_in2.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in2[i] = static_cast<float>(in2[i * stride_0_0]) * in3[i * stride_1_0];
  }
  if (in3.size(0) == 1) {
    i = in4.size(0);
  } else {
    i = in3.size(0);
  }
  b_in4.set_size(i);
  stride_0_0 = (in4.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  if (in3.size(0) == 1) {
    loop_ub = in4.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in4[i] = static_cast<float>(in4[i * stride_0_0]) * in3[i * stride_1_0];
  }
  in1.set_size(b_in2.size(0), 2);
  loop_ub = b_in2.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in2[i];
  }
  loop_ub = b_in4.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i + in1.size(0)] = b_in4[i];
  }
}

//
// File trailer for SpecialMsgUtil.cpp
//
// [EOF]
//
