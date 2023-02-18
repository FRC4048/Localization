//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: Subscriber.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

// Include Files
#include "amcl_test_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "mlroscpp_sub.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace ros {
class Subscriber {
public:
  Subscriber *init();
  void callback();
  double get_MessageCount() const;
  void receive(nav_msgs_MapMetaDataStruct_T *receivedMsg_Info,
               ::coder::array<signed char, 1U> &receivedMsg_Data) const;
  void
  get_LatestMessage(nav_msgs_MapMetaDataStruct_T *lastSubMsg_Info,
                    ::coder::array<signed char, 1U> &lastSubMsg_Data) const;
  char TopicName[7];
  double BufferSize;
  double MessageCount;

private:
  std::unique_ptr<
      MATLABSubscriber<nav_msgs::OccupancyGrid, nav_msgs_OccupancyGridStruct_T>>
      SubscriberHelper;
  nav_msgs_OccupancyGridStruct_T MsgStruct;
};

class b_Subscriber {
public:
  b_Subscriber *init();
  void callback();
  double get_MessageCount() const;
  void receive(float *receivedMsg_AngleMin, float *receivedMsg_AngleIncrement,
               float *receivedMsg_RangeMin, float *receivedMsg_RangeMax,
               ::coder::array<float, 1U> &receivedMsg_Ranges, bool *status,
               char statusText[7]) const;
  void get_LatestMessage(float *lastSubMsg_AngleMin,
                         float *lastSubMsg_AngleIncrement,
                         float *lastSubMsg_RangeMin, float *lastSubMsg_RangeMax,
                         ::coder::array<float, 1U> &lastSubMsg_Ranges) const;
  char TopicName[5];
  double BufferSize;
  double MessageCount;

private:
  std::unique_ptr<
      MATLABSubscriber<sensor_msgs::LaserScan, sensor_msgs_LaserScanStruct_T>>
      SubscriberHelper;
  sensor_msgs_LaserScanStruct_T MsgStruct;
};

class c_Subscriber {
public:
  c_Subscriber *init();
  void callback();
  double get_MessageCount() const;
  void get_LatestMessage(double *lastSubMsg_X, double *lastSubMsg_Y,
                         double *lastSubMsg_Z) const;
  char TopicName[4];
  double BufferSize;
  double MessageCount;

private:
  std::unique_ptr<
      MATLABSubscriber<geometry_msgs::Point, geometry_msgs_PointStruct_T>>
      SubscriberHelper;
  geometry_msgs_PointStruct_T MsgStruct;
};

} // namespace ros
} // namespace coder

#endif
//
// File trailer for Subscriber.h
//
// [EOF]
//
