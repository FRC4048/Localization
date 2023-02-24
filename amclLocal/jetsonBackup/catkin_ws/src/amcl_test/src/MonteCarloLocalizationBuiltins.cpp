//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: MonteCarloLocalizationBuiltins.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

// Include Files
#include "MonteCarloLocalizationBuiltins.h"
#include "MonteCarloLocalizationBuildable.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
namespace coder {
namespace nav {
namespace algs {
namespace internal {
void MonteCarloLocalizationBuiltins::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
  }
}

//
// Arguments    : void
// Return Type  : void
//
void MonteCarloLocalizationBuiltins::cleanup() const
{
  coder::MonteCarloLocalizationBuildable::cleanup(MCLData);
}

//
// Arguments    : void
// Return Type  : MonteCarloLocalizationBuiltins
//
MonteCarloLocalizationBuiltins::MonteCarloLocalizationBuiltins()
{
  matlabCodegenIsDeleted = true;
}

//
// Arguments    : void
// Return Type  : void
//
MonteCarloLocalizationBuiltins::~MonteCarloLocalizationBuiltins()
{
  matlabCodegenDestructor();
}

} // namespace internal
} // namespace algs
} // namespace nav
} // namespace coder

//
// File trailer for MonteCarloLocalizationBuiltins.cpp
//
// [EOF]
//
