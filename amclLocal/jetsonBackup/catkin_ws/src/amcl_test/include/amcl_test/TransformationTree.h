//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: TransformationTree.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

#ifndef TRANSFORMATIONTREE_H
#define TRANSFORMATIONTREE_H

// Include Files
#include "rtwtypes.h"
#include "mlroscpp_transform.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct geometry_msgs_TransformStampedStruct_T;

// Type Definitions
namespace coder {
namespace ros {
class TransformationTree {
public:
  void waitForTransform();
  bool canTransform();
  void getTransform(geometry_msgs_TransformStampedStruct_T *tform);
  MATLABROSTransform TransformHelper;
};

} // namespace ros
} // namespace coder

#endif
//
// File trailer for TransformationTree.h
//
// [EOF]
//
