//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: sensor_msgs_LaserScanStruct.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 06-Dec-2022 20:28:40
//

// Include Files
#include "sensor_msgs_LaserScanStruct.h"
#include "mandelbrot_populate_types.h"
#include "std_msgs_HeaderStruct.h"
#include "coder_array.h"

// Function Definitions
//
// Message struct definition for sensor_msgs/LaserScan
//
// Arguments    : sensor_msgs_LaserScanStruct_T *msg
// Return Type  : void
//
void sensor_msgs_LaserScanStruct(sensor_msgs_LaserScanStruct_T *msg)
{
  static const char cv[21]{'s', 'e', 'n', 's', 'o', 'r', '_',
                           'm', 's', 'g', 's', '/', 'L', 'a',
                           's', 'e', 'r', 'S', 'c', 'a', 'n'};
  std_msgs_HeaderStruct(&msg->Header);
  for (int i{0}; i < 21; i++) {
    msg->MessageType[i] = cv[i];
  }
  msg->AngleMin = 0.0F;
  msg->AngleMax = 0.0F;
  msg->AngleIncrement = 0.0F;
  msg->TimeIncrement = 0.0F;
  msg->ScanTime = 0.0F;
  msg->RangeMin = 0.0F;
  msg->RangeMax = 0.0F;
  msg->Ranges.set_size(0);
  msg->Intensities.set_size(0);
  //(msg);
}

//
// File trailer for sensor_msgs_LaserScanStruct.cpp
//
// [EOF]
//
