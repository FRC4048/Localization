//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: rosReadCartesian.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

#ifndef ROSREADCARTESIAN_H
#define ROSREADCARTESIAN_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct sensor_msgs_LaserScanStruct_T;

// Function Declarations
namespace coder {
void rosReadCartesian(const sensor_msgs_LaserScanStruct_T *msg,
                      ::coder::array<double, 2U> &cart);

}

#endif
//
// File trailer for rosReadCartesian.h
//
// [EOF]
//
