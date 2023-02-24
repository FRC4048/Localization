//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: std_msgs_HeaderStruct.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 06-Dec-2022 20:28:40
//

// Include Files
#include "std_msgs_HeaderStruct.h"
#include "mandelbrot_populate_types.h"
#include "ros_TimeStruct.h"
#include "coder_array.h"

// Function Definitions
//
// Message struct definition for std_msgs/Header
//
// Arguments    : std_msgs_HeaderStruct_T *msg
// Return Type  : void
//
void std_msgs_HeaderStruct(std_msgs_HeaderStruct_T *msg)
{
  static const char cv[15]{'s', 't', 'd', '_', 'm', 's', 'g', 's',
                           '/', 'H', 'e', 'a', 'd', 'e', 'r'};
  msg->Stamp = ros_TimeStruct();
  for (int i{0}; i < 15; i++) {
    msg->MessageType[i] = cv[i];
  }
  msg->Seq = 0U;
  msg->FrameId.set_size(1, 0);
  //(msg);
}

//
// File trailer for std_msgs_HeaderStruct.cpp
//
// [EOF]
//
