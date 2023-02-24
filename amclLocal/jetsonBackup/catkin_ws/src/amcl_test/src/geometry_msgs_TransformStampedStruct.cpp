//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: geometry_msgs_TransformStampedStruct.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

// Include Files
#include "geometry_msgs_TransformStampedStruct.h"
#include "amcl_test_types.h"
#include "geometry_msgs_TransformStruct.h"
#include "rt_nonfinite.h"
#include "std_msgs_HeaderStruct.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Message struct definition for geometry_msgs/TransformStamped
//
// Arguments    : geometry_msgs_TransformStampedStruct_T *msg
// Return Type  : void
//
void geometry_msgs_TransformStampedStruct(
    geometry_msgs_TransformStampedStruct_T *msg)
{
  static const char b_cv[30]{'g', 'e', 'o', 'm', 'e', 't', 'r', 'y', '_', 'm',
                             's', 'g', 's', '/', 'T', 'r', 'a', 'n', 's', 'f',
                             'o', 'r', 'm', 'S', 't', 'a', 'm', 'p', 'e', 'd'};
  std_msgs_HeaderStruct(&msg->Header);
  geometry_msgs_TransformStruct(&msg->Transform);
  for (int i{0}; i < 30; i++) {
    msg->MessageType[i] = b_cv[i];
  }
  msg->ChildFrameId.set_size(1, 0);
  //(msg);
}

//
// File trailer for geometry_msgs_TransformStampedStruct.cpp
//
// [EOF]
//
