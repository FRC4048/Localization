//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: CircularBuffer.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

// Include Files
#include "CircularBuffer.h"
#include "CircularBufferIndex.h"
#include "ixfun.h"
#include "mod.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &region
//                const ::coder::array<double, 2U> &newBlock
// Return Type  : void
//
namespace coder {
namespace matlabshared {
namespace autonomous {
namespace internal {
void CircularBuffer::setBaseMatrix(const ::coder::array<double, 2U> &region,
                                   const ::coder::array<double, 2U> &newBlock)
{
  double d;
  double d1;
  double d2;
  int b_loop_ub;
  int i;
  int i1;
  int i2;
  int i3;
  int loop_ub;
  d = region[3];
  if (d < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = static_cast<int>(d);
  }
  d = region[region.size(0) + 3];
  if (d < 1.0) {
    b_loop_ub = 0;
  } else {
    b_loop_ub = static_cast<int>(d);
  }
  d = region[0];
  if (d > region[1]) {
    i = 1;
  } else {
    i = static_cast<int>(d);
  }
  d = region[region.size(0)];
  if (d > region[region.size(0) + 1]) {
    i1 = 1;
  } else {
    i1 = static_cast<int>(d);
  }
  for (i2 = 0; i2 < b_loop_ub; i2++) {
    for (i3 = 0; i3 < loop_ub; i3++) {
      Buffer[((i + i3) + Buffer.size(0) * ((i1 + i2) - 1)) - 1] =
          (newBlock[i3 + newBlock.size(0) * i2] != 0.0);
    }
  }
  d = region[3] + 1.0;
  if (d > newBlock.size(0)) {
    i = 0;
    i1 = 0;
  } else {
    i = static_cast<int>(d) - 1;
    i1 = newBlock.size(0);
  }
  d1 = region[region.size(0) + 3];
  if (d1 < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = static_cast<int>(d1);
  }
  d1 = region[region.size(0)];
  if (d1 > region[region.size(0) + 1]) {
    i2 = 1;
  } else {
    i2 = static_cast<int>(d1);
  }
  for (i3 = 0; i3 < loop_ub; i3++) {
    b_loop_ub = i1 - i;
    for (int i4{0}; i4 < b_loop_ub; i4++) {
      Buffer[i4 + Buffer.size(0) * ((i2 + i3) - 1)] =
          (newBlock[(i + i4) + newBlock.size(0) * i3] != 0.0);
    }
  }
  d1 = region[3];
  if (d1 < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = static_cast<int>(d1);
  }
  d1 = region[region.size(0) + 3] + 1.0;
  if (d1 > newBlock.size(1)) {
    i = 0;
    i1 = 0;
  } else {
    i = static_cast<int>(d1) - 1;
    i1 = newBlock.size(1);
  }
  d2 = region[0];
  if (d2 > region[1]) {
    i2 = 1;
  } else {
    i2 = static_cast<int>(d2);
  }
  b_loop_ub = i1 - i;
  for (i1 = 0; i1 < b_loop_ub; i1++) {
    for (i3 = 0; i3 < loop_ub; i3++) {
      Buffer[((i2 + i3) + Buffer.size(0) * i1) - 1] =
          (newBlock[i3 + newBlock.size(0) * (i + i1)] != 0.0);
    }
  }
  if (d > newBlock.size(0)) {
    i = 0;
    i1 = 0;
  } else {
    i = static_cast<int>(d) - 1;
    i1 = newBlock.size(0);
  }
  if (d1 > newBlock.size(1)) {
    i2 = 0;
    i3 = 0;
  } else {
    i2 = static_cast<int>(d1) - 1;
    i3 = newBlock.size(1);
  }
  loop_ub = i3 - i2;
  for (i3 = 0; i3 < loop_ub; i3++) {
    b_loop_ub = i1 - i;
    for (int i4{0}; i4 < b_loop_ub; i4++) {
      Buffer[i4 + Buffer.size(0) * i3] =
          (newBlock[(i + i4) + newBlock.size(0) * (i2 + i3)] != 0.0);
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &indices
//                const ::coder::array<double, 1U> &values
// Return Type  : void
//
void CircularBuffer::setValueAtIndices(
    const ::coder::array<double, 2U> &indices,
    const ::coder::array<double, 1U> &values)
{
  CircularBufferIndex *obj;
  array<double, 2U> mapStart;
  array<double, 2U> r;
  array<int, 1U> b_r;
  double y[2];
  int a;
  int loop_ub;
  obj = Index;
  mapStart.set_size(indices.size(0), 2);
  loop_ub = indices.size(0);
  for (int i{0}; i < 2; i++) {
    for (a = 0; a < loop_ub; a++) {
      mapStart[a + mapStart.size(0) * i] =
          (obj->Head[i] + indices[a + indices.size(0) * i]) - 1.0;
    }
  }
  loop_ub = mapStart.size(0) * 2;
  mapStart.set_size(mapStart.size(0), 2);
  for (int i{0}; i < loop_ub; i++) {
    mapStart[i] = mapStart[i] - 1.0;
  }
  y[0] = obj->Size[0];
  y[1] = obj->Size[1];
  if (mapStart.size(0) == 1) {
    double varargin_1;
    r.set_size(1, 2);
    varargin_1 = mapStart[0];
    r[0] = ::coder::internal::scalar::b_mod(varargin_1, y[0]);
    varargin_1 = mapStart[1];
    r[1] = ::coder::internal::scalar::b_mod(varargin_1, y[1]);
  } else {
    ::coder::internal::expand_mod(mapStart, y, r);
  }
  mapStart.set_size(r.size(0), 2);
  loop_ub = r.size(0) * 2;
  for (int i{0}; i < loop_ub; i++) {
    mapStart[i] = r[i] + 1.0;
  }
  a = Buffer.size(0);
  b_r.set_size(mapStart.size(0));
  loop_ub = mapStart.size(0);
  for (int i{0}; i < loop_ub; i++) {
    b_r[i] = static_cast<int>(static_cast<double>(a) *
                                  (mapStart[i + mapStart.size(0)] - 1.0) +
                              mapStart[i]);
  }
  loop_ub = values.size(0);
  for (int i{0}; i < loop_ub; i++) {
    Buffer[b_r[i] - 1] = (values[i] != 0.0);
  }
}

//
// Arguments    : coder::matlabshared::autonomous::internal::CircularBuffer *in1
//                const coder::array<double, 2U> &in2
//                const coder::array<double, 2U> &in3
//                const coder::array<double, 2U> &in4
//                const coder::array<double, 2U> &in5
//                int in6
//                int in7
// Return Type  : void
//
} // namespace internal
} // namespace autonomous
} // namespace matlabshared
} // namespace coder
void binary_expand_op(
    coder::matlabshared::autonomous::internal::CircularBuffer *in1,
    const coder::array<double, 2U> &in2, const coder::array<double, 2U> &in3,
    const coder::array<double, 2U> &in4, const coder::array<double, 2U> &in5,
    int in6, int in7)
{
  coder::array<double, 2U> b_in2;
  coder::array<double, 2U> b_in4;
  coder::array<double, 2U> b_in5;
  coder::array<double, 2U> c_in2;
  int b_loop_ub;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    i = in2.size(0);
  } else {
    i = in3.size(0);
  }
  b_in2.set_size(i, 2);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  b_in4.set_size(in3.size(0), 2);
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  b_loop_ub = in3.size(0);
  for (i = 0; i < 2; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      b_in2[i1 + b_in2.size(0) * i] = (in2[i1 * stride_0_0 + in2.size(0) * i] +
                                       in3[i1 * stride_1_0 + in3.size(0) * i]) -
                                      1.0;
    }
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      b_in4[i1 + b_in4.size(0) * i] = in4[i] - in3[i1 + in3.size(0) * i];
    }
  }
  c_in2.set_size(((in2.size(0) + b_in2.size(0)) + b_in4.size(0)) + in3.size(0),
                 2);
  loop_ub = in2.size(0);
  for (i = 0; i < 2; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      c_in2[i1 + c_in2.size(0) * i] = in2[i1 + in2.size(0) * i];
    }
  }
  loop_ub = b_in2.size(0);
  for (i = 0; i < 2; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      c_in2[(i1 + in2.size(0)) + c_in2.size(0) * i] =
          b_in2[i1 + b_in2.size(0) * i];
    }
  }
  loop_ub = b_in4.size(0);
  for (i = 0; i < 2; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      c_in2[((i1 + in2.size(0)) + b_in2.size(0)) + c_in2.size(0) * i] =
          b_in4[i1 + b_in4.size(0) * i];
    }
  }
  loop_ub = in3.size(0);
  for (i = 0; i < 2; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      c_in2[(((i1 + in2.size(0)) + b_in2.size(0)) + b_in4.size(0)) +
            c_in2.size(0) * i] = in3[i1 + in3.size(0) * i];
    }
  }
  b_in5.set_size(in6 + 1, in7 + 1);
  for (i = 0; i <= in7; i++) {
    for (int i1{0}; i1 <= in6; i1++) {
      b_in5[i1 + b_in5.size(0) * i] = in5[i1 + in5.size(0) * i];
    }
  }
  in1->setBaseMatrix(c_in2, b_in5);
}

//
// File trailer for CircularBuffer.cpp
//
// [EOF]
//
