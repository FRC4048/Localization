//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: monteCarloLocalization.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

#ifndef MONTECARLOLOCALIZATION_H
#define MONTECARLOLOCALIZATION_H

// Include Files
#include "MonteCarloLocalizationBuiltins.h"
#include "likelihoodFieldSensorModel.h"
#include "odometryMotionModel.h"
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
struct cell_wrap_1 {
  unsigned int f1[8];
};

namespace coder {
class monteCarloLocalization {
public:
  void setupAndReset();
  void matlabCodegenDestructor();
  void release();
  void releaseWrapper() const;
  ~monteCarloLocalization();
  monteCarloLocalization();

protected:
  void releaseImpl() const;

private:
  void SystemCore_delete();

public:
  bool matlabCodegenIsDeleted;
  int isInitialized;
  double Seed;
  nav::algs::internal::MonteCarloLocalizationBuiltins MCLObj;
  odometryMotionModel *PrivateMotionModel;
  likelihoodFieldSensorModel *PrivateSensorModel;
  double PrivateParticleLimits[2];
  double PrivateInitialPose[3];
  double PrivateInitialCovariance[9];
  double PrivateResamplingInterval;
  double PrivateUpdateThresholds[3];
  bool PrivateGlobalLocalization;
  odometryMotionModel _pobj0;
  likelihoodFieldSensorModel _pobj1;

private:
  bool isSetupComplete;
  cell_wrap_1 inputVarSize[2];
};

} // namespace coder

#endif
//
// File trailer for monteCarloLocalization.h
//
// [EOF]
//
