//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: geometry_msgs_Vector3Struct.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

// Include Files
#include "geometry_msgs_Vector3Struct.h"
#include "amcl_test_types.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Message struct definition for geometry_msgs/Vector3
//
// Arguments    : void
// Return Type  : geometry_msgs_Vector3Struct_T
//
geometry_msgs_Vector3Struct_T geometry_msgs_Vector3Struct()
{
  static const geometry_msgs_Vector3Struct_T b_msg{
      {'g', 'e', 'o', 'm', 'e', 't', 'r', 'y', '_', 'm', 's',
       'g', 's', '/', 'V', 'e', 'c', 't', 'o', 'r', '3'}, // MessageType
      0.0,                                                // X
      0.0,                                                // Y
      0.0                                                 // Z
  };
  geometry_msgs_Vector3Struct_T msg;
  msg = b_msg;
  //(&b_msg);
  return msg;
}

//
// File trailer for geometry_msgs_Vector3Struct.cpp
//
// [EOF]
//
