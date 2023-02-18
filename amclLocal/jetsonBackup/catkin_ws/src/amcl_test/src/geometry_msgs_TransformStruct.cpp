//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: geometry_msgs_TransformStruct.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

// Include Files
#include "geometry_msgs_TransformStruct.h"
#include "amcl_test_types.h"
#include "geometry_msgs_QuaternionStruct.h"
#include "geometry_msgs_Vector3Struct.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Message struct definition for geometry_msgs/Transform
//
// Arguments    : geometry_msgs_TransformStruct_T *msg
// Return Type  : void
//
void geometry_msgs_TransformStruct(geometry_msgs_TransformStruct_T *msg)
{
  static const char b_cv[23]{'g', 'e', 'o', 'm', 'e', 't', 'r', 'y',
                             '_', 'm', 's', 'g', 's', '/', 'T', 'r',
                             'a', 'n', 's', 'f', 'o', 'r', 'm'};
  for (int i{0}; i < 23; i++) {
    msg->MessageType[i] = b_cv[i];
  }
  msg->Translation = geometry_msgs_Vector3Struct();
  msg->Rotation = geometry_msgs_QuaternionStruct();
  //(msg);
}

//
// File trailer for geometry_msgs_TransformStruct.cpp
//
// [EOF]
//
