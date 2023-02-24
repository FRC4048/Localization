//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: Publisher.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

#ifndef PUBLISHER_H
#define PUBLISHER_H

// Include Files
#include "rtwtypes.h"
#include "mlroscpp_pub.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct geometry_msgs_PointStampedStruct_T;

// Type Definitions
namespace coder {
namespace ros {
class Publisher {
public:
  Publisher *init();
  static void rosmessage(geometry_msgs_PointStampedStruct_T *msgFromPub);
  char TopicName[12];
  double BufferSize;
  bool IsLatching;
  std::unique_ptr<MATLABPublisher<geometry_msgs::PointStamped,
                                  geometry_msgs_PointStampedStruct_T>>
      PublisherHelper;
};

} // namespace ros
} // namespace coder

#endif
//
// File trailer for Publisher.h
//
// [EOF]
//
