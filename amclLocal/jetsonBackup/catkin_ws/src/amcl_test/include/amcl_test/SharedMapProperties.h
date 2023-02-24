//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: SharedMapProperties.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

#ifndef SHAREDMAPPROPERTIES_H
#define SHAREDMAPPROPERTIES_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace matlabshared {
namespace autonomous {
namespace internal {
class SharedMapProperties {
public:
  double Resolution;
  double GridSize[2];
  double GridOriginInLocal[2];
  double LocalOriginInWorld[2];
  double Width;
  double Height;
  double LocalOriginInWorldInternal[2];
};

} // namespace internal
} // namespace autonomous
} // namespace matlabshared
} // namespace coder

#endif
//
// File trailer for SharedMapProperties.h
//
// [EOF]
//
