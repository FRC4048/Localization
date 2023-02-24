//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: rosReadBinaryOccupancyGrid.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

#ifndef ROSREADBINARYOCCUPANCYGRID_H
#define ROSREADBINARYOCCUPANCYGRID_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct nav_msgs_MapMetaDataStruct_T;

namespace coder {
namespace matlabshared {
namespace autonomous {
namespace internal {
class CircularBuffer;

class CircularBufferIndex;

class SharedMapProperties;

} // namespace internal
} // namespace autonomous
} // namespace matlabshared
class binaryOccupancyMap;

} // namespace coder

// Function Declarations
namespace coder {
binaryOccupancyMap *rosReadBinaryOccupancyGrid(
    const nav_msgs_MapMetaDataStruct_T *msg_Info,
    const ::coder::array<signed char, 1U> &msg_Data,
    matlabshared::autonomous::internal::CircularBuffer *iobj_0,
    matlabshared::autonomous::internal::CircularBufferIndex *iobj_1,
    matlabshared::autonomous::internal::SharedMapProperties *iobj_2,
    binaryOccupancyMap *iobj_3);

}

#endif
//
// File trailer for rosReadBinaryOccupancyGrid.h
//
// [EOF]
//
