//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: Subscriber.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

// Include Files
#include "Subscriber.h"
#include "amcl_test_types.h"
#include "geometry_msgs_PointStruct.h"
#include "nav_msgs_OccupancyGridStruct.h"
#include "rt_nonfinite.h"
#include "sensor_msgs_LaserScanStruct.h"
#include "coder_array.h"
#include "mlroscpp_sub.h"
#include "ros/duration.h"
#include "ros/time.h"
#include <string.h>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
namespace coder {
namespace ros {
void Subscriber::callback()
{
  MessageCount = get_MessageCount() + 1.0;
}

//
// Arguments    : void
// Return Type  : void
//
void b_Subscriber::callback()
{
  MessageCount = get_MessageCount() + 1.0;
}

//
// Arguments    : void
// Return Type  : void
//
void c_Subscriber::callback()
{
  MessageCount = get_MessageCount() + 1.0;
}

//
// Arguments    : nav_msgs_MapMetaDataStruct_T *lastSubMsg_Info
//                ::coder::array<signed char, 1U> &lastSubMsg_Data
// Return Type  : void
//
void Subscriber::get_LatestMessage(
    nav_msgs_MapMetaDataStruct_T *lastSubMsg_Info,
    ::coder::array<signed char, 1U> &lastSubMsg_Data) const
{
  int loop_ub;
  MATLABSUBSCRIBER_lock(SubscriberHelper);
  *lastSubMsg_Info = MsgStruct.Info;
  lastSubMsg_Data.set_size(MsgStruct.Data.size(0));
  loop_ub = MsgStruct.Data.size(0);
  for (int i{0}; i < loop_ub; i++) {
    lastSubMsg_Data[i] = MsgStruct.Data[i];
  }
  MATLABSUBSCRIBER_unlock(SubscriberHelper);
}

//
// Arguments    : float *lastSubMsg_AngleMin
//                float *lastSubMsg_AngleIncrement
//                float *lastSubMsg_RangeMin
//                float *lastSubMsg_RangeMax
//                ::coder::array<float, 1U> &lastSubMsg_Ranges
// Return Type  : void
//
void b_Subscriber::get_LatestMessage(
    float *lastSubMsg_AngleMin, float *lastSubMsg_AngleIncrement,
    float *lastSubMsg_RangeMin, float *lastSubMsg_RangeMax,
    ::coder::array<float, 1U> &lastSubMsg_Ranges) const
{
  int loop_ub;
  MATLABSUBSCRIBER_lock(SubscriberHelper);
  lastSubMsg_Ranges.set_size(MsgStruct.Ranges.size(0));
  loop_ub = MsgStruct.Ranges.size(0);
  for (int i{0}; i < loop_ub; i++) {
    lastSubMsg_Ranges[i] = MsgStruct.Ranges[i];
  }
  MATLABSUBSCRIBER_unlock(SubscriberHelper);
  *lastSubMsg_AngleMin = MsgStruct.AngleMin;
  *lastSubMsg_AngleIncrement = MsgStruct.AngleIncrement;
  *lastSubMsg_RangeMin = MsgStruct.RangeMin;
  *lastSubMsg_RangeMax = MsgStruct.RangeMax;
}

//
// Arguments    : void
// Return Type  : double
//
double Subscriber::get_MessageCount() const
{
  return MessageCount;
}

//
// Arguments    : void
// Return Type  : double
//
double c_Subscriber::get_MessageCount() const
{
  return MessageCount;
}

//
// Arguments    : void
// Return Type  : double
//
double b_Subscriber::get_MessageCount() const
{
  return MessageCount;
}

//
// Arguments    : double *lastSubMsg_X
//                double *lastSubMsg_Y
//                double *lastSubMsg_Z
// Return Type  : void
//
void c_Subscriber::get_LatestMessage(double *lastSubMsg_X, double *lastSubMsg_Y,
                                     double *lastSubMsg_Z) const
{
  MATLABSUBSCRIBER_lock(SubscriberHelper);
  *lastSubMsg_X = MsgStruct.X;
  *lastSubMsg_Y = MsgStruct.Y;
  *lastSubMsg_Z = MsgStruct.Z;
  MATLABSUBSCRIBER_unlock(SubscriberHelper);
}

//
// Arguments    : void
// Return Type  : Subscriber *
//
Subscriber *Subscriber::init()
{
  static const char topic[7]{'/', 'm', 'y', '_', 'm', 'a', 'p'};
  Subscriber *obj;
  obj = this;
  for (int i{0}; i < 7; i++) {
    obj->TopicName[i] = topic[i];
  }
  obj->BufferSize = 1.0;
  obj->MessageCount = 0.0;
  nav_msgs_OccupancyGridStruct(&obj->MsgStruct);
  auto structPtr = (&obj->MsgStruct);
  obj->SubscriberHelper =
      std::unique_ptr<MATLABSubscriber<nav_msgs::OccupancyGrid,
                                       nav_msgs_OccupancyGridStruct_T>>(
          new MATLABSubscriber<nav_msgs::OccupancyGrid,
                               nav_msgs_OccupancyGridStruct_T>(
              structPtr, [this] { this->callback(); })); //();
  MATLABSUBSCRIBER_createSubscriber(obj->SubscriberHelper, &obj->TopicName[0],
                                    7.0, obj->BufferSize);
  obj->callback();
  return obj;
}

//
// Arguments    : void
// Return Type  : b_Subscriber *
//
b_Subscriber *b_Subscriber::init()
{
  static const char topic[5]{'/', 's', 'c', 'a', 'n'};
  b_Subscriber *obj;
  obj = this;
  for (int i{0}; i < 5; i++) {
    obj->TopicName[i] = topic[i];
  }
  obj->BufferSize = 1.0;
  obj->MessageCount = 0.0;
  sensor_msgs_LaserScanStruct(&obj->MsgStruct);
  auto structPtr = (&obj->MsgStruct);
  obj->SubscriberHelper = std::unique_ptr<
      MATLABSubscriber<sensor_msgs::LaserScan, sensor_msgs_LaserScanStruct_T>>(
      new MATLABSubscriber<sensor_msgs::LaserScan,
                           sensor_msgs_LaserScanStruct_T>(
          structPtr, [this] { this->callback(); })); //();
  MATLABSUBSCRIBER_createSubscriber(obj->SubscriberHelper, &obj->TopicName[0],
                                    5.0, obj->BufferSize);
  obj->callback();
  return obj;
}

//
// Arguments    : void
// Return Type  : c_Subscriber *
//
c_Subscriber *c_Subscriber::init()
{
  c_Subscriber *obj;
  obj = this;
  obj->TopicName[0] = '/';
  obj->TopicName[1] = 'i';
  obj->TopicName[2] = 'm';
  obj->TopicName[3] = 'u';
  obj->BufferSize = 1.0;
  obj->MessageCount = 0.0;
  obj->MsgStruct = geometry_msgs_PointStruct();
  auto structPtr = (&obj->MsgStruct);
  obj->SubscriberHelper = std::unique_ptr<
      MATLABSubscriber<geometry_msgs::Point, geometry_msgs_PointStruct_T>>(
      new MATLABSubscriber<geometry_msgs::Point, geometry_msgs_PointStruct_T>(
          structPtr, [this] { this->callback(); })); //();
  MATLABSUBSCRIBER_createSubscriber(obj->SubscriberHelper, &obj->TopicName[0],
                                    4.0, obj->BufferSize);
  obj->callback();
  return obj;
}

//
// Arguments    : nav_msgs_MapMetaDataStruct_T *receivedMsg_Info
//                ::coder::array<signed char, 1U> &receivedMsg_Data
// Return Type  : void
//
void Subscriber::receive(
    nav_msgs_MapMetaDataStruct_T *receivedMsg_Info,
    ::coder::array<signed char, 1U> &receivedMsg_Data) const
{
  double nMessages;
  nMessages = get_MessageCount();
  while (get_MessageCount() == nMessages) {
    ::ros::Time::now();
  }
  char statusText[7];
  getStatusText(true, &statusText[0]);
  get_LatestMessage(receivedMsg_Info, receivedMsg_Data);
}

//
// Arguments    : float *receivedMsg_AngleMin
//                float *receivedMsg_AngleIncrement
//                float *receivedMsg_RangeMin
//                float *receivedMsg_RangeMax
//                ::coder::array<float, 1U> &receivedMsg_Ranges
//                bool *status
//                char statusText[7]
// Return Type  : void
//
void b_Subscriber::receive(float *receivedMsg_AngleMin,
                           float *receivedMsg_AngleIncrement,
                           float *receivedMsg_RangeMin,
                           float *receivedMsg_RangeMax,
                           ::coder::array<float, 1U> &receivedMsg_Ranges,
                           bool *status, char statusText[7]) const
{
  ::ros::Duration tDur;
  ::ros::Time tStop;
  double nMessages;
  bool exitg1;
  nMessages = get_MessageCount();
  tDur = tDur.fromSec(10.0);
  tStop = ::ros::Time::now() + (tDur);
  *status = true;
  exitg1 = false;
  while ((!exitg1) && (get_MessageCount() == nMessages)) {
    ::ros::Time currentTime;
    currentTime = ::ros::Time::now();
    if (currentTime >= tStop) {
      *status = false;
      exitg1 = true;
    }
  }
  getStatusText(*status, &statusText[0]);
  get_LatestMessage(receivedMsg_AngleMin, receivedMsg_AngleIncrement,
                    receivedMsg_RangeMin, receivedMsg_RangeMax,
                    receivedMsg_Ranges);
}

} // namespace ros
} // namespace coder

//
// File trailer for Subscriber.cpp
//
// [EOF]
//
