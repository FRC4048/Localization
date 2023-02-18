//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: SpecialMsgUtil.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

#ifndef SPECIALMSGUTIL_H
#define SPECIALMSGUTIL_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct sensor_msgs_LaserScanStruct_T;

// Function Declarations
void b_binary_expand_op(coder::array<bool, 1U> &in1,
                        const coder::array<bool, 1U> &in2,
                        const sensor_msgs_LaserScanStruct_T *in3,
                        const float in4[2], const float in5[2]);

void binary_expand_op(coder::array<double, 2U> &in1,
                      const coder::array<double, 1U> &in2,
                      const coder::array<float, 1U> &in3,
                      const coder::array<double, 1U> &in4);

#endif
//
// File trailer for SpecialMsgUtil.h
//
// [EOF]
//
