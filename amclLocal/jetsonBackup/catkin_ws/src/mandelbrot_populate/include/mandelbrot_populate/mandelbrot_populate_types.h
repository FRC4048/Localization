//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: mandelbrot_populate_types.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 06-Dec-2022 20:28:40
//

#ifndef MANDELBROT_POPULATE_TYPES_H
#define MANDELBROT_POPULATE_TYPES_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"

// Type Definitions
struct ros_TimeStruct_T {
  unsigned int Sec;
  unsigned int Nsec;
};

struct std_msgs_HeaderStruct_T {
  char MessageType[15];
  unsigned int Seq;
  ros_TimeStruct_T Stamp;
  coder::array<char, 2U> FrameId;
};

struct sensor_msgs_LaserScanStruct_T {
  char MessageType[21];
  std_msgs_HeaderStruct_T Header;
  float AngleMin;
  float AngleMax;
  float AngleIncrement;
  float TimeIncrement;
  float ScanTime;
  float RangeMin;
  float RangeMax;
  coder::array<float, 1U> Ranges;
  coder::array<float, 1U> Intensities;
};

#endif
//
// File trailer for mandelbrot_populate_types.h
//
// [EOF]
//
