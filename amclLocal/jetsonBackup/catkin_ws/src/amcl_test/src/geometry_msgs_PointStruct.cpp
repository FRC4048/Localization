//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: geometry_msgs_PointStruct.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

// Include Files
#include "geometry_msgs_PointStruct.h"
#include "amcl_test_types.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Message struct definition for geometry_msgs/Point
//
// Arguments    : void
// Return Type  : geometry_msgs_PointStruct_T
//
geometry_msgs_PointStruct_T geometry_msgs_PointStruct()
{
  static const geometry_msgs_PointStruct_T b_msg{
      {'g', 'e', 'o', 'm', 'e', 't', 'r', 'y', '_', 'm', 's', 'g', 's', '/',
       'P', 'o', 'i', 'n', 't'}, // MessageType
      0.0,                       // X
      0.0,                       // Y
      0.0                        // Z
  };
  geometry_msgs_PointStruct_T msg;
  msg = b_msg;
  //(&b_msg);
  return msg;
}

//
// File trailer for geometry_msgs_PointStruct.cpp
//
// [EOF]
//
