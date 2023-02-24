//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: nav_msgs_MapMetaDataStruct.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

// Include Files
#include "nav_msgs_MapMetaDataStruct.h"
#include "amcl_test_types.h"
#include "geometry_msgs_PoseStruct.h"
#include "ros_TimeStruct.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Message struct definition for nav_msgs/MapMetaData
//
// Arguments    : nav_msgs_MapMetaDataStruct_T *msg
// Return Type  : void
//
void nav_msgs_MapMetaDataStruct(nav_msgs_MapMetaDataStruct_T *msg)
{
  static const char b_cv[20]{'n', 'a', 'v', '_', 'm', 's', 'g', 's', '/', 'M',
                             'a', 'p', 'M', 'e', 't', 'a', 'D', 'a', 't', 'a'};
  for (int i{0}; i < 20; i++) {
    msg->MessageType[i] = b_cv[i];
  }
  msg->MapLoadTime = ros_TimeStruct();
  msg->Resolution = 0.0F;
  msg->Width = 0U;
  msg->Height = 0U;
  geometry_msgs_PoseStruct(&msg->Origin);
  //(msg);
}

//
// File trailer for nav_msgs_MapMetaDataStruct.cpp
//
// [EOF]
//
