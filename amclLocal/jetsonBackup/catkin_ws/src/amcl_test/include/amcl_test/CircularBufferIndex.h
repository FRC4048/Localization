//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: CircularBufferIndex.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

#ifndef CIRCULARBUFFERINDEX_H
#define CIRCULARBUFFERINDEX_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace matlabshared {
namespace autonomous {
namespace internal {
class CircularBufferIndex {
public:
  double Head[2];
  double Size[2];
  double NewRegions[4];
  bool DropEntireMap;
  bool DropTwoRegions[2];
};

} // namespace internal
} // namespace autonomous
} // namespace matlabshared
} // namespace coder

#endif
//
// File trailer for CircularBufferIndex.h
//
// [EOF]
//
