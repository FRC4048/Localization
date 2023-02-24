//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: ros_TimeStruct.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

// Include Files
#include "ros_TimeStruct.h"
#include "amcl_test_types.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Message struct definition for ros/Time
//
// Arguments    : void
// Return Type  : ros_TimeStruct_T
//
ros_TimeStruct_T ros_TimeStruct()
{
  ros_TimeStruct_T msg;
  msg.Sec = 0U;
  msg.Nsec = 0U;
  //(&msg);
  return msg;
}

//
// File trailer for ros_TimeStruct.cpp
//
// [EOF]
//
