//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: odometryMotionModel.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

// Include Files
#include "odometryMotionModel.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
namespace coder {
void odometryMotionModel::SystemCore_delete()
{
  release();
}

//
// Arguments    : void
// Return Type  : void
//
void odometryMotionModel::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
    SystemCore_delete();
  }
}

//
// Arguments    : void
// Return Type  : void
//
void odometryMotionModel::release()
{
  if (isInitialized == 1) {
    isInitialized = 2;
  }
}

//
// Arguments    : odometryMotionModel *iobj_0
// Return Type  : odometryMotionModel *
//
odometryMotionModel *
odometryMotionModel::clone(odometryMotionModel *iobj_0) const
{
  odometryMotionModel *clonedObj;
  clonedObj = iobj_0;
  iobj_0->isInitialized = 0;
  iobj_0->matlabCodegenIsDeleted = false;
  iobj_0->Noise[0] = Noise[0];
  iobj_0->Noise[1] = Noise[1];
  iobj_0->Noise[2] = Noise[2];
  iobj_0->Noise[3] = Noise[3];
  return clonedObj;
}

//
// Arguments    : void
// Return Type  : odometryMotionModel
//
odometryMotionModel::odometryMotionModel()
{
  matlabCodegenIsDeleted = true;
}

//
// Arguments    : void
// Return Type  : void
//
odometryMotionModel::~odometryMotionModel()
{
  matlabCodegenDestructor();
}

} // namespace coder

//
// File trailer for odometryMotionModel.cpp
//
// [EOF]
//
