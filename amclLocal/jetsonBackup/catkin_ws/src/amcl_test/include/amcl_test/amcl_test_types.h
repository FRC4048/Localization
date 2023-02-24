//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: amcl_test_types.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

#ifndef AMCL_TEST_TYPES_H
#define AMCL_TEST_TYPES_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"

// Type Definitions
struct ros_TimeStruct_T {
  unsigned int Sec;
  unsigned int Nsec;
};

struct geometry_msgs_PointStruct_T {
  char MessageType[19];
  double X;
  double Y;
  double Z;
};

struct geometry_msgs_QuaternionStruct_T {
  char MessageType[24];
  double X;
  double Y;
  double Z;
  double W;
};

struct geometry_msgs_PoseStruct_T {
  char MessageType[18];
  geometry_msgs_PointStruct_T Position;
  geometry_msgs_QuaternionStruct_T Orientation;
};

struct nav_msgs_MapMetaDataStruct_T {
  char MessageType[20];
  ros_TimeStruct_T MapLoadTime;
  float Resolution;
  unsigned int Width;
  unsigned int Height;
  geometry_msgs_PoseStruct_T Origin;
};

struct geometry_msgs_Vector3Struct_T {
  char MessageType[21];
  double X;
  double Y;
  double Z;
};

struct geometry_msgs_TransformStruct_T {
  char MessageType[23];
  geometry_msgs_Vector3Struct_T Translation;
  geometry_msgs_QuaternionStruct_T Rotation;
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

struct nav_msgs_OccupancyGridStruct_T {
  char MessageType[22];
  std_msgs_HeaderStruct_T Header;
  nav_msgs_MapMetaDataStruct_T Info;
  coder::array<signed char, 1U> Data;
};

struct geometry_msgs_PointStampedStruct_T {
  char MessageType[26];
  std_msgs_HeaderStruct_T Header;
  geometry_msgs_PointStruct_T Point;
};

struct geometry_msgs_TransformStampedStruct_T {
  char MessageType[30];
  std_msgs_HeaderStruct_T Header;
  coder::array<char, 2U> ChildFrameId;
  geometry_msgs_TransformStruct_T Transform;
};

#endif
//
// File trailer for amcl_test_types.h
//
// [EOF]
//
