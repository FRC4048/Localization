//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: odometryMotionModel.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

#ifndef ODOMETRYMOTIONMODEL_H
#define ODOMETRYMOTIONMODEL_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
class odometryMotionModel {
public:
  odometryMotionModel *clone(odometryMotionModel *iobj_0) const;
  void matlabCodegenDestructor();
  void release();
  ~odometryMotionModel();
  odometryMotionModel();

private:
  void SystemCore_delete();

public:
  bool matlabCodegenIsDeleted;
  int isInitialized;
  double Noise[4];
};

} // namespace coder

#endif
//
// File trailer for odometryMotionModel.h
//
// [EOF]
//
