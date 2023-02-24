//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: likelihoodFieldSensorModel.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

#ifndef LIKELIHOODFIELDSENSORMODEL_H
#define LIKELIHOODFIELDSENSORMODEL_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class binaryOccupancyMap;

}

// Type Definitions
namespace coder {
class likelihoodFieldSensorModel {
public:
  double SensorPose[3];
  double SensorLimits[2];
  double NumBeams;
  double MeasurementNoise;
  double RandomMeasurementWeight;
  double ExpectedMeasurementWeight;
  double MaxLikelihoodDistance;
  binaryOccupancyMap *InternalMap;
};

} // namespace coder

#endif
//
// File trailer for likelihoodFieldSensorModel.h
//
// [EOF]
//
