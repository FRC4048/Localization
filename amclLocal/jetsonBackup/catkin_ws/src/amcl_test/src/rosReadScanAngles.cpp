//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: rosReadScanAngles.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

// Include Files
#include "rosReadScanAngles.h"
#include "rt_nonfinite.h"
#include "wrapToPi.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : float msg_AngleMin
//                float msg_AngleIncrement
//                const ::coder::array<float, 1U> &msg_Ranges
//                ::coder::array<double, 1U> &angles
// Return Type  : void
//
namespace coder {
void rosReadScanAngles(float msg_AngleMin, float msg_AngleIncrement,
                       const ::coder::array<float, 1U> &msg_Ranges,
                       ::coder::array<double, 1U> &angles)
{
  array<int, 2U> r;
  int loop_ub;
  if (msg_Ranges.size(0) - 1 < 0) {
    r.set_size(1, 0);
  } else {
    r.set_size(1, msg_Ranges.size(0));
    loop_ub = msg_Ranges.size(0);
    for (int i{0}; i < loop_ub; i++) {
      r[i] = i;
    }
  }
  angles.set_size(r.size(1));
  loop_ub = r.size(1);
  for (int i{0}; i < loop_ub; i++) {
    angles[i] = msg_AngleMin + static_cast<float>(r[i]) * msg_AngleIncrement;
  }
  robotics::internal::wrapToPi(angles);
}

} // namespace coder

//
// File trailer for rosReadScanAngles.cpp
//
// [EOF]
//
