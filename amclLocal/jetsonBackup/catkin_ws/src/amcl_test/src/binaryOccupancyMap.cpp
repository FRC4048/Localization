//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: binaryOccupancyMap.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

// Include Files
#include "binaryOccupancyMap.h"
#include "CircularBuffer.h"
#include "CircularBufferIndex.h"
#include "MapLayer.h"
#include "SharedMapProperties.h"
#include "ixfun.h"
#include "mod.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : matlabshared::autonomous::internal::CircularBuffer *iobj_0
//                matlabshared::autonomous::internal::CircularBufferIndex
//                *iobj_1
//                matlabshared::autonomous::internal::SharedMapProperties
//                *iobj_2 binaryOccupancyMap *iobj_3
// Return Type  : binaryOccupancyMap *
//
namespace coder {
binaryOccupancyMap *binaryOccupancyMap::copy(
    matlabshared::autonomous::internal::CircularBuffer *iobj_0,
    matlabshared::autonomous::internal::CircularBufferIndex *iobj_1,
    matlabshared::autonomous::internal::SharedMapProperties *iobj_2,
    binaryOccupancyMap *iobj_3)
{
  binaryOccupancyMap *cpObj;
  matlabshared::autonomous::internal::CircularBuffer *obj;
  matlabshared::autonomous::internal::CircularBufferIndex *b_obj;
  matlabshared::autonomous::internal::SharedMapProperties *varargin_1;
  array<bool, 2U> matrix;
  double obj_idx_2;
  double obj_idx_3;
  double varargin_1_idx_0;
  double varargin_1_idx_1;
  int loop_ub;
  bool obj_idx_0;
  bool obj_idx_1;
  iobj_3->HasParent = false;
  cpObj = iobj_3;
  varargin_1 = SharedProperties;
  iobj_2->Resolution = varargin_1->Resolution;
  varargin_1_idx_0 = varargin_1->GridSize[0];
  varargin_1_idx_1 = varargin_1->GridSize[1];
  iobj_2->GridSize[0] = varargin_1_idx_0;
  iobj_2->GridSize[1] = varargin_1_idx_1;
  iobj_2->Width = varargin_1->Width;
  iobj_2->Height = varargin_1->Height;
  varargin_1_idx_0 = varargin_1->GridOriginInLocal[0];
  varargin_1_idx_1 = varargin_1->GridOriginInLocal[1];
  iobj_2->GridOriginInLocal[0] = varargin_1_idx_0;
  iobj_2->GridOriginInLocal[1] = varargin_1_idx_1;
  varargin_1_idx_0 = varargin_1->LocalOriginInWorld[0];
  varargin_1_idx_1 = varargin_1->LocalOriginInWorld[1];
  iobj_2->LocalOriginInWorld[0] = varargin_1_idx_0;
  iobj_2->LocalOriginInWorld[1] = varargin_1_idx_1;
  varargin_1_idx_0 = varargin_1->LocalOriginInWorldInternal[0];
  varargin_1_idx_1 = varargin_1->LocalOriginInWorldInternal[1];
  iobj_2->LocalOriginInWorldInternal[0] = varargin_1_idx_0;
  iobj_2->LocalOriginInWorldInternal[1] = varargin_1_idx_1;
  iobj_3->SharedProperties = iobj_2;
  iobj_3->DefaultValueInternal = DefaultValueInternal;
  obj = Buffer;
  b_obj = obj->Index;
  varargin_1_idx_0 = b_obj->Size[0];
  varargin_1_idx_1 = b_obj->Size[1];
  iobj_1->Head[0] = 1.0;
  iobj_1->Head[1] = 1.0;
  iobj_1->Size[0] = varargin_1_idx_0;
  iobj_1->Size[1] = varargin_1_idx_1;
  iobj_1->DropEntireMap = false;
  iobj_1->NewRegions[0] = 0.0;
  iobj_1->NewRegions[1] = 0.0;
  iobj_1->NewRegions[2] = 0.0;
  iobj_1->NewRegions[3] = 0.0;
  iobj_1->DropTwoRegions[0] = false;
  iobj_1->DropTwoRegions[1] = false;
  varargin_1_idx_0 = b_obj->Head[0];
  varargin_1_idx_1 = b_obj->Head[1];
  iobj_1->Head[0] = varargin_1_idx_0;
  iobj_1->Head[1] = varargin_1_idx_1;
  varargin_1_idx_0 = b_obj->Size[0];
  varargin_1_idx_1 = b_obj->Size[1];
  iobj_1->Size[0] = varargin_1_idx_0;
  iobj_1->Size[1] = varargin_1_idx_1;
  varargin_1_idx_0 = b_obj->NewRegions[0];
  varargin_1_idx_1 = b_obj->NewRegions[1];
  obj_idx_2 = b_obj->NewRegions[2];
  obj_idx_3 = b_obj->NewRegions[3];
  iobj_1->NewRegions[0] = varargin_1_idx_0;
  iobj_1->NewRegions[1] = varargin_1_idx_1;
  iobj_1->NewRegions[2] = obj_idx_2;
  iobj_1->NewRegions[3] = obj_idx_3;
  iobj_1->DropEntireMap = b_obj->DropEntireMap;
  obj_idx_0 = b_obj->DropTwoRegions[0];
  obj_idx_1 = b_obj->DropTwoRegions[1];
  iobj_1->DropTwoRegions[0] = obj_idx_0;
  iobj_1->DropTwoRegions[1] = obj_idx_1;
  obj_idx_0 = obj->ConstVal;
  matrix.set_size(obj->Buffer.size(0), obj->Buffer.size(1));
  loop_ub = obj->Buffer.size(0) * obj->Buffer.size(1);
  for (int i{0}; i < loop_ub; i++) {
    matrix[i] = obj->Buffer[i];
  }
  varargin_1_idx_0 = iobj_1->Size[0];
  varargin_1_idx_1 = iobj_1->Size[1];
  iobj_0->Index = iobj_1;
  iobj_0->ConstVal = obj_idx_0;
  iobj_0->Buffer.set_size(static_cast<int>(varargin_1_idx_0),
                          static_cast<int>(varargin_1_idx_1));
  loop_ub =
      static_cast<int>(varargin_1_idx_0) * static_cast<int>(varargin_1_idx_1);
  for (int i{0}; i < loop_ub; i++) {
    iobj_0->Buffer[i] = matrix[i];
  }
  iobj_3->Buffer = iobj_0;
  iobj_3->Index = iobj_3->Buffer->Index;
  varargin_1_idx_0 = DataSize[0];
  varargin_1_idx_1 = DataSize[1];
  iobj_3->DataSize[0] = varargin_1_idx_0;
  iobj_3->DataSize[1] = varargin_1_idx_1;
  return cpObj;
}

//
// Arguments    : double val[2]
// Return Type  : void
//
void binaryOccupancyMap::counterFPECeil(double val[2])
{
  array<double, 2U> r1;
  array<signed char, 2U> r;
  array<signed char, 2U> r2;
  double absx;
  double d;
  int nx;
  int trueCount;
  bool b;
  bool highFPE_idx_0;
  trueCount = 0;
  d = val[0];
  absx = std::abs(d);
  if (std::isinf(absx) || std::isnan(absx)) {
    absx = rtNaN;
  } else if (absx < 4.4501477170144028E-308) {
    absx = 4.94065645841247E-324;
  } else {
    std::frexp(absx, &nx);
    absx = std::ldexp(1.0, nx - 53);
  }
  b = (d - std::floor(d) <= absx * 2.0);
  highFPE_idx_0 = b;
  if (b) {
    trueCount = 1;
  }
  d = val[1];
  absx = std::abs(d);
  if (std::isinf(absx) || std::isnan(absx)) {
    absx = rtNaN;
  } else if (absx < 4.4501477170144028E-308) {
    absx = 4.94065645841247E-324;
  } else {
    std::frexp(absx, &nx);
    absx = std::ldexp(1.0, nx - 53);
  }
  b = (d - std::floor(d) <= absx * 2.0);
  if (b) {
    trueCount++;
  }
  r.set_size(1, trueCount);
  nx = 0;
  if (highFPE_idx_0) {
    r[0] = 1;
    nx = 1;
  }
  if (b) {
    r[nx] = 2;
  }
  r1.set_size(1, r.size(1));
  nx = r.size(1);
  for (trueCount = 0; trueCount < nx; trueCount++) {
    r1[trueCount] = val[r[trueCount] - 1];
  }
  nx = r.size(1);
  for (trueCount = 0; trueCount < nx; trueCount++) {
    r1[trueCount] = std::floor(r1[trueCount]);
  }
  nx = 0;
  trueCount = 0;
  if (highFPE_idx_0) {
    val[0] = r1[0];
    nx = 1;
  } else {
    trueCount = 1;
  }
  if (b) {
    val[1] = r1[nx];
  } else {
    trueCount++;
  }
  r2.set_size(1, trueCount);
  nx = 0;
  if (!highFPE_idx_0) {
    r2[0] = 1;
    nx = 1;
  }
  if (!b) {
    r2[nx] = 2;
  }
  r1.set_size(1, r2.size(1));
  nx = r2.size(1);
  for (trueCount = 0; trueCount < nx; trueCount++) {
    r1[trueCount] = val[r2[trueCount] - 1];
  }
  nx = r2.size(1);
  for (trueCount = 0; trueCount < nx; trueCount++) {
    r1[trueCount] = std::ceil(r1[trueCount]);
  }
  nx = 0;
  if (!highFPE_idx_0) {
    val[0] = r1[0];
    nx = 1;
  }
  if (!b) {
    val[1] = r1[nx];
  }
}

//
// Arguments    : binaryOccupancyMap *og
//                const ::coder::array<double, 1U> &values
// Return Type  : binaryOccupancyMap *
//
binaryOccupancyMap *
binaryOccupancyMap::writeToOG(binaryOccupancyMap *og,
                              const ::coder::array<double, 1U> &values)
{
  matlabshared::autonomous::internal::CircularBuffer *b_obj;
  matlabshared::autonomous::internal::CircularBufferIndex *c_obj;
  array<double, 2U> bRight;
  array<double, 2U> b_y;
  array<double, 2U> block;
  array<double, 2U> botRightIJ;
  array<double, 2U> c_y;
  array<double, 2U> mapStart;
  array<double, 2U> matrix;
  array<double, 2U> obj;
  array<double, 2U> uLeft;
  array<double, 2U> varargin_1;
  array<double, 2U> y;
  array<double, 1U> b_matrix;
  array<int, 1U> r;
  array<bool, 2U> x;
  array<bool, 1U> validInd;
  double sz[2];
  double tmp;
  int dim;
  int i;
  int i1;
  int k;
  int loop_ub;
  int lowerDim;
  int nd2;
  int npages;
  sz[1] = og->SharedProperties->GridSize[1];
  tmp = og->SharedProperties->GridSize[0];
  lowerDim = static_cast<int>(sz[1]);
  matrix.set_size(static_cast<int>(tmp), lowerDim);
  for (i = 0; i < lowerDim; i++) {
    nd2 = static_cast<int>(tmp);
    for (i1 = 0; i1 < nd2; i1++) {
      matrix[i1 + matrix.size(0) * i] = values[i + lowerDim * i1];
    }
  }
  dim = 1;
  if (matrix.size(0) != 1) {
    dim = 0;
  }
  if ((matrix.size(0) != 0) && (matrix.size(1) != 0) &&
      (matrix.size(dim) > 1)) {
    int pagelen;
    int vstride;
    vstride = 1;
    for (k = 0; k < dim; k++) {
      vstride *= matrix.size(0);
    }
    pagelen = vstride * matrix.size(dim);
    npages = 1;
    lowerDim = dim + 2;
    for (k = lowerDim; k < 3; k++) {
      npages *= matrix.size(1);
    }
    i = matrix.size(dim) - 1;
    nd2 = matrix.size(dim) >> 1;
    i1 = npages - 1;
    for (int j{0}; j <= i1; j++) {
      lowerDim = vstride - 1;
      for (int b_i{0}; b_i <= lowerDim; b_i++) {
        dim = j * pagelen + b_i;
        for (k = 0; k < nd2; k++) {
          npages = dim + k * vstride;
          tmp = matrix[npages];
          loop_ub = dim + (i - k) * vstride;
          matrix[npages] = matrix[loop_ub];
          matrix[loop_ub] = tmp;
        }
      }
    }
  }
  sz[0] = og->SharedProperties->GridSize[0];
  if (std::isnan(sz[0])) {
    y.set_size(1, 1);
    y[0] = rtNaN;
  } else if (sz[0] < 1.0) {
    y.set_size(1, 0);
  } else {
    y.set_size(1, static_cast<int>(sz[0] - 1.0) + 1);
    nd2 = static_cast<int>(sz[0] - 1.0);
    for (i = 0; i <= nd2; i++) {
      y[i] = static_cast<double>(i) + 1.0;
    }
  }
  sz[1] = og->SharedProperties->GridSize[1];
  if (std::isnan(sz[1])) {
    b_y.set_size(1, 1);
    b_y[0] = rtNaN;
  } else if (sz[1] < 1.0) {
    b_y.set_size(1, 0);
  } else {
    b_y.set_size(1, static_cast<int>(sz[1] - 1.0) + 1);
    nd2 = static_cast<int>(sz[1] - 1.0);
    for (i = 0; i <= nd2; i++) {
      b_y[i] = static_cast<double>(i) + 1.0;
    }
  }
  block.set_size(y.size(1), b_y.size(1));
  i = b_y.size(1);
  for (k = 0; k < i; k++) {
    i1 = block.size(0);
    for (lowerDim = 0; lowerDim < i1; lowerDim++) {
      block[lowerDim + block.size(0) * k] = y[lowerDim];
    }
  }
  c_y.set_size(y.size(1), b_y.size(1));
  i = b_y.size(1);
  for (k = 0; k < i; k++) {
    i1 = c_y.size(0);
    for (lowerDim = 0; lowerDim < i1; lowerDim++) {
      c_y[lowerDim + c_y.size(0) * k] = b_y[k];
    }
  }
  npages = block.size(0) * block.size(1);
  lowerDim = c_y.size(0) * c_y.size(1);
  varargin_1.set_size(npages, 2);
  for (i = 0; i < npages; i++) {
    varargin_1[i] = block[i];
  }
  for (i = 0; i < lowerDim; i++) {
    varargin_1[i + varargin_1.size(0)] = c_y[i];
  }
  if ((varargin_1.size(0) << 1 == 2) && (matrix.size(0) * matrix.size(1) > 1)) {
    bool d_y[2];
    bool e_y;
    bool exitg1;
    sz[0] = matrix.size(0) * matrix.size(1);
    sz[1] = 1.0;
    botRightIJ.set_size(varargin_1.size(0), 2);
    nd2 = varargin_1.size(0);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < nd2; i1++) {
        botRightIJ[i1 + botRightIJ.size(0) * i] =
            (varargin_1[i1 + varargin_1.size(0) * i] + sz[i]) - 1.0;
      }
    }
    if (varargin_1.size(0) == 1) {
      uLeft.set_size(1, 2);
      tmp = varargin_1[0];
      uLeft[0] = std::fmax(tmp, 1.0);
      tmp = varargin_1[1];
      uLeft[1] = std::fmax(tmp, 1.0);
    } else {
      internal::expand_max(varargin_1, uLeft);
    }
    sz[0] = og->SharedProperties->GridSize[0];
    sz[1] = og->SharedProperties->GridSize[1];
    if (botRightIJ.size(0) == 1) {
      bRight.set_size(1, 2);
      tmp = botRightIJ[0];
      bRight[0] = std::fmin(tmp, sz[0]);
      tmp = botRightIJ[1];
      bRight[1] = std::fmin(tmp, sz[1]);
    } else {
      internal::expand_min(botRightIJ, sz, bRight);
    }
    if (bRight.size(0) == uLeft.size(0)) {
      nd2 = bRight.size(0) * 2;
      bRight.set_size(bRight.size(0), 2);
      for (i = 0; i < nd2; i++) {
        bRight[i] = (bRight[i] - uLeft[i]) + 1.0;
      }
    } else {
      binary_expand_op(bRight, uLeft);
    }
    x.set_size(bRight.size(0), 2);
    nd2 = bRight.size(0) * 2;
    for (i = 0; i < nd2; i++) {
      x[i] = (bRight[i] > 0.0);
    }
    d_y[0] = true;
    d_y[1] = true;
    lowerDim = x.size(0);
    npages = 0;
    exitg1 = false;
    while ((!exitg1) && (npages + 1 <= lowerDim)) {
      if (!x[npages]) {
        d_y[0] = false;
        exitg1 = true;
      } else {
        npages++;
      }
    }
    lowerDim = x.size(0) + x.size(0);
    npages = x.size(0);
    exitg1 = false;
    while ((!exitg1) && (npages + 1 <= lowerDim)) {
      if (!x[npages]) {
        d_y[1] = false;
        exitg1 = true;
      } else {
        npages++;
      }
    }
    e_y = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (!d_y[k]) {
        e_y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (e_y) {
      double varargin_2;
      tmp = uLeft[0] - varargin_1[0];
      varargin_2 = uLeft[1] - varargin_1[1];
      lowerDim = matrix.size(0) * matrix.size(1);
      block.set_size(static_cast<int>(bRight[0] - 1.0) + 1,
                     static_cast<int>(bRight[1] - 1.0) + 1);
      nd2 = static_cast<int>(bRight[1] - 1.0);
      for (i = 0; i <= nd2; i++) {
        loop_ub = static_cast<int>(bRight[0] - 1.0);
        for (i1 = 0; i1 <= loop_ub; i1++) {
          block[i1 + block.size(0) * i] =
              matrix[(static_cast<int>(tmp + static_cast<double>(i1 + 1)) +
                      lowerDim * (static_cast<int>(varargin_2 +
                                                   static_cast<double>(i + 1)) -
                                  1)) -
                     1];
        }
      }
      b_obj = og->Buffer;
      c_obj = b_obj->Index;
      if (uLeft.size(0) == 1) {
        mapStart.set_size(1, 2);
        tmp = uLeft[0];
        mapStart[0] = std::fmax(tmp, 1.0);
        tmp = uLeft[1];
        mapStart[1] = std::fmax(tmp, 1.0);
      } else {
        internal::expand_max(uLeft, mapStart);
      }
      if ((mapStart[0] > c_obj->Size[0]) || (mapStart[1] > c_obj->Size[1])) {
        obj.set_size(mapStart.size(0), 2);
        nd2 = mapStart.size(0);
        for (i = 0; i < 2; i++) {
          for (i1 = 0; i1 < nd2; i1++) {
            obj[i1 + obj.size(0) * i] =
                (c_obj->Head[i] + mapStart[i1 + mapStart.size(0) * i]) - 1.0;
          }
        }
        mapStart.set_size(obj.size(0), 2);
        nd2 = obj.size(0) * 2;
        for (i = 0; i < nd2; i++) {
          mapStart[i] = obj[i];
        }
        nd2 = mapStart.size(0) * 2;
        mapStart.set_size(mapStart.size(0), 2);
        for (i = 0; i < nd2; i++) {
          mapStart[i] = mapStart[i] - 1.0;
        }
        sz[0] = c_obj->Size[0];
        sz[1] = c_obj->Size[1];
        if (mapStart.size(0) == 1) {
          botRightIJ.set_size(1, 2);
          tmp = mapStart[0];
          botRightIJ[0] = internal::scalar::b_mod(tmp, sz[0]);
          tmp = mapStart[1];
          botRightIJ[1] = internal::scalar::b_mod(tmp, sz[1]);
        } else {
          internal::expand_mod(mapStart, sz, botRightIJ);
        }
        mapStart.set_size(botRightIJ.size(0), 2);
        nd2 = botRightIJ.size(0) * 2;
        for (i = 0; i < nd2; i++) {
          mapStart[i] = botRightIJ[i] + 1.0;
        }
      }
      sz[0] = static_cast<int>(bRight[0] - 1.0) + 1;
      sz[1] = static_cast<int>(bRight[1] - 1.0) + 1;
      botRightIJ.set_size(mapStart.size(0), 2);
      nd2 = mapStart.size(0);
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < nd2; i1++) {
          botRightIJ[i1 + botRightIJ.size(0) * i] =
              (c_obj->Size[i] - mapStart[i1 + mapStart.size(0) * i]) + 1.0;
        }
      }
      if (botRightIJ.size(0) == 1) {
        uLeft.set_size(1, 2);
        lowerDim = static_cast<int>(bRight[0] - 1.0) + 1;
        varargin_2 = botRightIJ[0];
        uLeft[0] = std::fmin(static_cast<double>(lowerDim), varargin_2);
        lowerDim = static_cast<int>(bRight[1] - 1.0) + 1;
        varargin_2 = botRightIJ[1];
        uLeft[1] = std::fmin(static_cast<double>(lowerDim), varargin_2);
      } else {
        internal::expand_min(sz, botRightIJ, uLeft);
      }
      if (uLeft[0] < 1.0) {
        nd2 = 0;
      } else {
        nd2 = static_cast<int>(uLeft[0]);
      }
      if (uLeft[1] < 1.0) {
        loop_ub = 0;
      } else {
        loop_ub = static_cast<int>(uLeft[1]);
      }
      obj.set_size(mapStart.size(0), 2);
      npages = mapStart.size(0);
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < npages; i1++) {
          obj[i1 + obj.size(0) * i] =
              (c_obj->Head[i] + mapStart[i1 + mapStart.size(0) * i]) - 1.0;
        }
      }
      mapStart.set_size(obj.size(0), 2);
      npages = obj.size(0) * 2;
      for (i = 0; i < npages; i++) {
        mapStart[i] = obj[i];
      }
      npages = mapStart.size(0) * 2;
      mapStart.set_size(mapStart.size(0), 2);
      for (i = 0; i < npages; i++) {
        mapStart[i] = mapStart[i] - 1.0;
      }
      sz[0] = c_obj->Size[0];
      sz[1] = c_obj->Size[1];
      if (mapStart.size(0) == 1) {
        botRightIJ.set_size(1, 2);
        tmp = mapStart[0];
        botRightIJ[0] = internal::scalar::b_mod(tmp, sz[0]);
        tmp = mapStart[1];
        botRightIJ[1] = internal::scalar::b_mod(tmp, sz[1]);
      } else {
        internal::expand_mod(mapStart, sz, botRightIJ);
      }
      mapStart.set_size(botRightIJ.size(0), 2);
      npages = botRightIJ.size(0) * 2;
      for (i = 0; i < npages; i++) {
        mapStart[i] = botRightIJ[i] + 1.0;
      }
      varargin_1.set_size(mapStart.size(0), 2);
      npages = mapStart.size(0);
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < npages; i1++) {
          varargin_1[i1 + varargin_1.size(0) * i] =
              (c_obj->Size[i] - mapStart[i1 + mapStart.size(0) * i]) + 1.0;
        }
      }
      sz[0] = uLeft[0];
      sz[1] = uLeft[1];
      if (varargin_1.size(0) == 1) {
        botRightIJ.set_size(1, 2);
        tmp = varargin_1[0];
        varargin_2 = uLeft[0];
        botRightIJ[0] = std::fmin(tmp, varargin_2);
        tmp = varargin_1[1];
        varargin_2 = uLeft[1];
        botRightIJ[1] = std::fmin(tmp, varargin_2);
      } else {
        internal::expand_min(varargin_1, sz, botRightIJ);
      }
      if (mapStart.size(0) == botRightIJ.size(0)) {
        varargin_1.set_size(botRightIJ.size(0), 2);
        npages = botRightIJ.size(0);
        for (i = 0; i < 2; i++) {
          for (i1 = 0; i1 < npages; i1++) {
            varargin_1[i1 + varargin_1.size(0) * i] =
                uLeft[i] - botRightIJ[i1 + botRightIJ.size(0) * i];
          }
        }
        obj.set_size(
            ((mapStart.size(0) + mapStart.size(0)) + varargin_1.size(0)) +
                botRightIJ.size(0),
            2);
        npages = mapStart.size(0);
        lowerDim = varargin_1.size(0);
        dim = botRightIJ.size(0);
        for (i = 0; i < 2; i++) {
          for (i1 = 0; i1 < npages; i1++) {
            obj[i1 + obj.size(0) * i] = mapStart[i1 + mapStart.size(0) * i];
            obj[(i1 + mapStart.size(0)) + obj.size(0) * i] =
                (mapStart[i1 + mapStart.size(0) * i] +
                 botRightIJ[i1 + botRightIJ.size(0) * i]) -
                1.0;
          }
          for (i1 = 0; i1 < lowerDim; i1++) {
            obj[((i1 + mapStart.size(0)) + mapStart.size(0)) +
                obj.size(0) * i] = varargin_1[i1 + varargin_1.size(0) * i];
          }
          for (i1 = 0; i1 < dim; i1++) {
            obj[(((i1 + mapStart.size(0)) + mapStart.size(0)) +
                 varargin_1.size(0)) +
                obj.size(0) * i] = botRightIJ[i1 + botRightIJ.size(0) * i];
          }
        }
        for (i = 0; i < loop_ub; i++) {
          for (i1 = 0; i1 < nd2; i1++) {
            block[i1 + nd2 * i] = block[i1 + block.size(0) * i];
          }
        }
        block.set_size(nd2, loop_ub);
        b_obj->setBaseMatrix(obj, block);
      } else {
        binary_expand_op(b_obj, mapStart, botRightIJ, uLeft, block, nd2 - 1,
                         loop_ub - 1);
      }
    }
  } else {
    sz[0] = og->SharedProperties->GridSize[0];
    sz[1] = og->SharedProperties->GridSize[1];
    validInd.set_size(varargin_1.size(0));
    nd2 = varargin_1.size(0);
    for (i = 0; i < nd2; i++) {
      double varargin_2;
      tmp = varargin_1[i];
      varargin_2 = varargin_1[i + varargin_1.size(0)];
      validInd[i] = ((tmp > 0.0) && (tmp < sz[0] + 1.0) && (varargin_2 > 0.0) &&
                     (varargin_2 < sz[1] + 1.0));
    }
    if (matrix.size(0) * matrix.size(1) == 1) {
      dim = validInd.size(0) - 1;
      npages = 0;
      for (int b_i{0}; b_i <= dim; b_i++) {
        if (validInd[b_i]) {
          npages++;
        }
      }
      r.set_size(npages);
      lowerDim = 0;
      for (int b_i{0}; b_i <= dim; b_i++) {
        if (validInd[b_i]) {
          r[lowerDim] = b_i + 1;
          lowerDim++;
        }
      }
      npages = matrix.size(0) * matrix.size(1);
      obj.set_size(r.size(0), 2);
      nd2 = r.size(0);
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < nd2; i1++) {
          obj[i1 + obj.size(0) * i] =
              varargin_1[(r[i1] + varargin_1.size(0) * i) - 1];
        }
      }
      b_matrix = matrix.reshape(npages);
      og->Buffer->setValueAtIndices(obj, b_matrix);
    } else {
      dim = validInd.size(0) - 1;
      npages = 0;
      for (int b_i{0}; b_i <= dim; b_i++) {
        if (validInd[b_i]) {
          npages++;
        }
      }
      r.set_size(npages);
      lowerDim = 0;
      for (int b_i{0}; b_i <= dim; b_i++) {
        if (validInd[b_i]) {
          r[lowerDim] = b_i + 1;
          lowerDim++;
        }
      }
      obj.set_size(r.size(0), 2);
      nd2 = r.size(0);
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < nd2; i1++) {
          obj[i1 + obj.size(0) * i] =
              varargin_1[(r[i1] + varargin_1.size(0) * i) - 1];
        }
      }
      b_matrix.set_size(r.size(0));
      nd2 = r.size(0);
      for (i = 0; i < nd2; i++) {
        b_matrix[i] = matrix[r[i] - 1];
      }
      og->Buffer->setValueAtIndices(obj, b_matrix);
    }
  }
  return og;
}

} // namespace coder

//
// File trailer for binaryOccupancyMap.cpp
//
// [EOF]
//
