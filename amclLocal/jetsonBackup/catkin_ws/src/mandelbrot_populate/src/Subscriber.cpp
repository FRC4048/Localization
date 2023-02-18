//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: Subscriber.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 06-Dec-2022 20:28:40
//

// Include Files
#include "Subscriber.h"
#include "mandelbrot_populate_types.h"
#include "sensor_msgs_LaserScanStruct.h"
#include "mlroscpp_sub.h"

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
// Return Type  : float
//
float Subscriber::get_LatestMessage() const
{
  float lastSubMsg_AngleMin;
  MATLABSUBSCRIBER_lock(SubscriberHelper);
  lastSubMsg_AngleMin = MsgStruct.AngleMin;
  MATLABSUBSCRIBER_unlock(SubscriberHelper);
  return lastSubMsg_AngleMin;
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
// Return Type  : Subscriber *
//
Subscriber *Subscriber::init()
{
  static const char topic[12]{'/', 'l', 'a', 's', 'e', 'r',
                              '2', '/', 's', 'c', 'a', 'n'};
  Subscriber *obj;
  obj = this;
  for (int i{0}; i < 12; i++) {
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
                                    12.0, obj->BufferSize);
  obj->callback();
  return obj;
}

//
// Arguments    : void
// Return Type  : float
//
float Subscriber::receive() const
{
  double nMessages;
  nMessages = get_MessageCount();
  while (get_MessageCount() == nMessages) {
    ::ros::Time::now();
  }
  char statusText[7];
  getStatusText(true, &statusText[0]);
  return get_LatestMessage();
}

} // namespace ros
} // namespace coder

//
// File trailer for Subscriber.cpp
//
// [EOF]
//
