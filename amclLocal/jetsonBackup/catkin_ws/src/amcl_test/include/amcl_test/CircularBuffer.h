//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: CircularBuffer.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
namespace matlabshared {
namespace autonomous {
namespace internal {
class CircularBufferIndex;

}
} // namespace autonomous
} // namespace matlabshared
} // namespace coder

// Type Definitions
namespace coder {
namespace matlabshared {
namespace autonomous {
namespace internal {
class CircularBuffer {
public:
  void setValueAtIndices(const ::coder::array<double, 2U> &indices,
                         const ::coder::array<double, 1U> &values);
  void setBaseMatrix(const ::coder::array<double, 2U> &region,
                     const ::coder::array<double, 2U> &newBlock);
  bool ConstVal;
  CircularBufferIndex *Index;
  array<bool, 2U> Buffer;
};

} // namespace internal
} // namespace autonomous
} // namespace matlabshared
} // namespace coder

// Function Declarations
void binary_expand_op(
    coder::matlabshared::autonomous::internal::CircularBuffer *in1,
    const coder::array<double, 2U> &in2, const coder::array<double, 2U> &in3,
    const coder::array<double, 2U> &in4, const coder::array<double, 2U> &in5,
    int in6, int in7);

#endif
//
// File trailer for CircularBuffer.h
//
// [EOF]
//
