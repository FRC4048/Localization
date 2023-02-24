//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: TransformationTree.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

// Include Files
#include "TransformationTree.h"
#include "amcl_test_types.h"
#include "geometry_msgs_TransformStampedStruct.h"
#include "ros_TimeStruct.h"
#include "rt_nonfinite.h"
#include "mlroscpp_transform.h"
#include <functional>
#include <string.h>

// Variable Definitions
static const char cv[9]{'b', 'a', 's', 'e', '_', 'l', 'i', 'n', 'k'};

static const char cv1[9]{'b', 'a', 's', 'e', '_', 's', 'c', 'a', 'n'};

// Function Definitions
//
// Arguments    : void
// Return Type  : bool
//
namespace coder {
namespace ros {
bool TransformationTree::canTransform()
{
  ros_TimeStruct();
  return std::mem_fn(&MATLABROSTransform::canTransform)(
      &TransformHelper, &cv[0], 9.0, &cv1[0], 9.0, 0U, 0U);
}

//
// Arguments    : geometry_msgs_TransformStampedStruct_T *tform
// Return Type  : void
//
void TransformationTree::getTransform(
    geometry_msgs_TransformStampedStruct_T *tform)
{
  ros_TimeStruct();
  ros_TimeStruct();
  geometry_msgs_TransformStampedStruct(tform);
  std::mem_fn (&MATLABROSTransform::lookupTransform)(
      &TransformHelper, tform, &cv[0], 9.0, &cv1[0], 9.0, 0U, 0U, 0U, 0U);
}

//
// Arguments    : void
// Return Type  : void
//
void TransformationTree::waitForTransform()
{
  while (!canTransform()) {
    char targetFrame[9];
    for (int i{0}; i < 9; i++) {
      targetFrame[i] = cv[i];
    }
    //(&targetFrame[0]);
  }
}

} // namespace ros
} // namespace coder

//
// File trailer for TransformationTree.cpp
//
// [EOF]
//
