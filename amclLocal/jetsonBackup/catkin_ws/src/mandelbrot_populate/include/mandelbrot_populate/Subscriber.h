//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: Subscriber.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 06-Dec-2022 20:28:40
//

#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

// Include Files
#include "mandelbrot_populate_types.h"
#include "rtwtypes.h"
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
  float receive() const;
  float get_LatestMessage() const;
  char TopicName[12];
  double BufferSize;
  double MessageCount;

private:
  std::unique_ptr<
      MATLABSubscriber<sensor_msgs::LaserScan, sensor_msgs_LaserScanStruct_T>>
      SubscriberHelper;
  sensor_msgs_LaserScanStruct_T MsgStruct;
};

} // namespace ros
} // namespace coder

#endif
//
// File trailer for Subscriber.h
//
// [EOF]
//
