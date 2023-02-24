//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: nav_msgs_OccupancyGridStruct.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

// Include Files
#include "nav_msgs_OccupancyGridStruct.h"
#include "amcl_test_types.h"
#include "nav_msgs_MapMetaDataStruct.h"
#include "rt_nonfinite.h"
#include "std_msgs_HeaderStruct.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Message struct definition for nav_msgs/OccupancyGrid
//
// Arguments    : nav_msgs_OccupancyGridStruct_T *msg
// Return Type  : void
//
void nav_msgs_OccupancyGridStruct(nav_msgs_OccupancyGridStruct_T *msg)
{
  static const char b_cv[22]{'n', 'a', 'v', '_', 'm', 's', 'g', 's',
                             '/', 'O', 'c', 'c', 'u', 'p', 'a', 'n',
                             'c', 'y', 'G', 'r', 'i', 'd'};
  std_msgs_HeaderStruct(&msg->Header);
  nav_msgs_MapMetaDataStruct(&msg->Info);
  for (int i{0}; i < 22; i++) {
    msg->MessageType[i] = b_cv[i];
  }
  msg->Data.set_size(0);
  //(msg);
}

//
// File trailer for nav_msgs_OccupancyGridStruct.cpp
//
// [EOF]
//
