//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: rosReadCartesian.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

// Include Files
#include "rosReadCartesian.h"
#include "SpecialMsgUtil.h"
#include "amcl_test_types.h"
#include "rosReadScanAngles.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const sensor_msgs_LaserScanStruct_T *msg
//                ::coder::array<double, 2U> &cart
// Return Type  : void
//
namespace coder {
void rosReadCartesian(const sensor_msgs_LaserScanStruct_T *msg,
                      ::coder::array<double, 2U> &cart)
{
  array<double, 1U> angles;
  array<double, 1U> cartAngles;
  array<float, 1U> validR;
  array<bool, 1U> r;
  array<bool, 1U> validIdx;
  float defaults_RangeLimits[2];
  float rangeLimits[2];
  int end;
  int nx;
  defaults_RangeLimits[0] = msg->RangeMin;
  defaults_RangeLimits[1] = msg->RangeMax;
  rangeLimits[0] = msg->RangeMin;
  rangeLimits[1] = msg->RangeMax;
  validIdx.set_size(msg->Ranges.size(0));
  nx = msg->Ranges.size(0);
  for (end = 0; end < nx; end++) {
    validIdx[end] = std::isinf(msg->Ranges[end]);
  }
  r.set_size(msg->Ranges.size(0));
  nx = msg->Ranges.size(0);
  for (end = 0; end < nx; end++) {
    r[end] = std::isnan(msg->Ranges[end]);
  }
  if (validIdx.size(0) == 1) {
    nx = msg->Ranges.size(0);
  } else {
    nx = validIdx.size(0);
  }
  if ((validIdx.size(0) == msg->Ranges.size(0)) &&
      (nx == msg->Ranges.size(0))) {
    nx = validIdx.size(0);
    for (end = 0; end < nx; end++) {
      validIdx[end] = ((!validIdx[end]) && (!r[end]) &&
                       (msg->Ranges[end] >= rangeLimits[0]) &&
                       (msg->Ranges[end] <= defaults_RangeLimits[1]));
    }
  } else {
    b_binary_expand_op(validIdx, r, msg, rangeLimits, defaults_RangeLimits);
  }
  end = validIdx.size(0) - 1;
  nx = 0;
  for (int i{0}; i <= end; i++) {
    if (validIdx[i]) {
      nx++;
    }
  }
  validR.set_size(nx);
  nx = 0;
  for (int i{0}; i <= end; i++) {
    if (validIdx[i]) {
      validR[nx] = msg->Ranges[i];
      nx++;
    }
  }
  rosReadScanAngles(msg->AngleMin, msg->AngleIncrement, msg->Ranges, angles);
  end = validIdx.size(0) - 1;
  nx = 0;
  for (int i{0}; i <= end; i++) {
    if (validIdx[i]) {
      nx++;
    }
  }
  cartAngles.set_size(nx);
  nx = 0;
  for (int i{0}; i <= end; i++) {
    if (validIdx[i]) {
      cartAngles[nx] = angles[i];
      nx++;
    }
  }
  angles.set_size(cartAngles.size(0));
  nx = cartAngles.size(0);
  for (end = 0; end < nx; end++) {
    angles[end] = cartAngles[end];
  }
  nx = cartAngles.size(0);
  for (end = 0; end < nx; end++) {
    angles[end] = std::cos(angles[end]);
  }
  nx = cartAngles.size(0);
  for (end = 0; end < nx; end++) {
    cartAngles[end] = std::sin(cartAngles[end]);
  }
  if ((angles.size(0) == validR.size(0)) &&
      (cartAngles.size(0) == validR.size(0))) {
    cart.set_size(angles.size(0), 2);
    nx = angles.size(0);
    for (end = 0; end < nx; end++) {
      cart[end] = static_cast<float>(angles[end]) * validR[end];
    }
    nx = cartAngles.size(0);
    for (end = 0; end < nx; end++) {
      cart[end + cart.size(0)] =
          static_cast<float>(cartAngles[end]) * validR[end];
    }
  } else {
    binary_expand_op(cart, angles, validR, cartAngles);
  }
}

} // namespace coder

//
// File trailer for rosReadCartesian.cpp
//
// [EOF]
//
