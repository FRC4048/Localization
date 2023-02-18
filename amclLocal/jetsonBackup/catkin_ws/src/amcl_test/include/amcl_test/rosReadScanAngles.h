//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: rosReadScanAngles.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

#ifndef ROSREADSCANANGLES_H
#define ROSREADSCANANGLES_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void rosReadScanAngles(float msg_AngleMin, float msg_AngleIncrement,
                       const ::coder::array<float, 1U> &msg_Ranges,
                       ::coder::array<double, 1U> &angles);

}

#endif
//
// File trailer for rosReadScanAngles.h
//
// [EOF]
//
