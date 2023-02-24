//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
// File: amcl_test.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 12-Feb-2023 15:27:05
//

// Include Files
#include "amcl_test.h"
#include "CircularBuffer.h"
#include "CircularBufferIndex.h"
#include "MonteCarloLocalizationBuiltins.h"
#include "Publisher.h"
#include "SharedMapProperties.h"
#include "Subscriber.h"
#include "TransformationTree.h"
#include "amcl_test_rtwutil.h"
#include "amcl_test_types.h"
#include "binaryOccupancyMap.h"
#include "geometry_msgs_TransformStampedStruct.h"
#include "lidarScan.h"
#include "likelihoodFieldSensorModel.h"
#include "monteCarloLocalization.h"
#include "odometryMotionModel.h"
#include "quat2eul.h"
#include "rosReadBinaryOccupancyGrid.h"
#include "rosReadCartesian.h"
#include "rt_nonfinite.h"
#include "wrapToPi.h"
#include "coder_array.h"
#include "mclcodegen_api.hpp"
#include "mlroscpp_pub.h"
#include "mlroscpp_transform.h"
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <string.h>

// Function Declarations
static double rt_hypotd_snf(double u0, double u1);

// Function Definitions
//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_hypotd_snf(double u0, double u1)
{
  double a;
  double b;
  double y;
  a = std::abs(u0);
  b = std::abs(u1);
  if (a < b) {
    a /= b;
    y = b * std::sqrt(a * a + 1.0);
  } else if (a > b) {
    b /= a;
    y = a * std::sqrt(b * b + 1.0);
  } else if (std::isnan(b)) {
    y = rtNaN;
  } else {
    y = a * 1.4142135623730951;
  }
  return y;
}

//
// Arguments    : void
// Return Type  : void
//
void amcl_test()
{
  static const double val[9]{0.5, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.5};
  static const char b_cv[10]{'m', 'a', 't', 'l', 'a', 'b', '_', 'm', 's', 'g'};
  void *mclData;
  coder::binaryOccupancyMap lobj_11[2];
  coder::binaryOccupancyMap lobj_3;
  coder::binaryOccupancyMap map;
  coder::binaryOccupancyMap *iobj_3;
  coder::lidarScan scan;
  coder::likelihoodFieldSensorModel lobj_9;
  coder::likelihoodFieldSensorModel rangeFinderModel;
  coder::matlabshared::autonomous::internal::CircularBuffer lobj_12[3];
  coder::matlabshared::autonomous::internal::CircularBuffer lobj_0;
  coder::matlabshared::autonomous::internal::CircularBuffer *iobj_0;
  coder::matlabshared::autonomous::internal::CircularBufferIndex lobj_13[3];
  coder::matlabshared::autonomous::internal::CircularBufferIndex lobj_1;
  coder::matlabshared::autonomous::internal::CircularBufferIndex *iobj_1;
  coder::matlabshared::autonomous::internal::SharedMapProperties lobj_14[3];
  coder::matlabshared::autonomous::internal::SharedMapProperties lobj_2;
  coder::matlabshared::autonomous::internal::SharedMapProperties *iobj_2;
  coder::monteCarloLocalization amcl;
  coder::odometryMotionModel lobj_10;
  coder::odometryMotionModel odometryModel;
  coder::ros::Publisher debug;
  coder::ros::Subscriber mapSub;
  coder::ros::TransformationTree tftree;
  coder::ros::b_Subscriber laserSub;
  coder::ros::c_Subscriber odomSub;
  coder::array<double, 2U> aRanges;
  coder::array<double, 2U> b_aAngles;
  coder::array<double, 2U> cart;
  coder::array<double, 1U> aAngles;
  coder::array<double, 1U> b_aRanges;
  coder::array<signed char, 1U> t4_Data;
  geometry_msgs_PointStampedStruct_T msg;
  geometry_msgs_TransformStampedStruct_T expl_temp;
  geometry_msgs_TransformStampedStruct_T r;
  nav_msgs_MapMetaDataStruct_T t4_Info;
  sensor_msgs_LaserScanStruct_T scanMsg;
  double sensorTransform_Transform_Rotat[4];
  double pose[3];
  double odompose_Y;
  double odompose_Z;
  double randomSeed;
  char statustext[7];
  bool flag;
  lobj_10.matlabCodegenIsDeleted = true;
  amcl._pobj0.matlabCodegenIsDeleted = true;
  amcl.MCLObj.matlabCodegenIsDeleted = true;
  amcl.matlabCodegenIsDeleted = true;
  printf("Starting\n");
  fflush(stdout);
  mapSub.init();
  laserSub.init();
  printf("Found /scan and /my_map topics\n");
  fflush(stdout);
  //      map = binaryOccupancyMap(100,100);
  mapSub.receive(&t4_Info, t4_Data);
  coder::rosReadBinaryOccupancyGrid(&t4_Info, t4_Data, &lobj_12[2], &lobj_13[2],
                                    &lobj_14[2], &map);
  printf("reveived map\n");
  fflush(stdout);
  odometryModel.isInitialized = 0;
  odometryModel.matlabCodegenIsDeleted = false;
  odometryModel.Noise[0] = 0.2;
  odometryModel.Noise[1] = 0.2;
  odometryModel.Noise[2] = 0.2;
  odometryModel.Noise[3] = 0.2;
  iobj_0 = &lobj_12[1];
  iobj_1 = &lobj_13[1];
  iobj_2 = &lobj_14[1];
  iobj_3 = &lobj_11[1];
  rangeFinderModel.InternalMap = map.copy(iobj_0, iobj_1, iobj_2, iobj_3);
  //  Query the Transformation Tree (tf tree) in ROS.
  printf("waiting for tf Tree");
  fflush(stdout);
  tftree.TransformHelper = MATLABROSTransform();
  UNUSED_PARAM(tftree.TransformHelper);
  geometry_msgs_TransformStampedStruct(&r);
  printf("found transformationTree");
  fflush(stdout);
  tftree.waitForTransform();
  printf("Found tf transformation between base_link and base_scan");
  fflush(stdout);
  tftree.getTransform(&expl_temp);
  //  Get the euler rotation angles.
  //  Setup the |SensorPose|, which includes the translation along base_link's
  //  +X, +Y direction in meters and rotation angle along base_link's +Z axis
  //  in radians.
  odomSub.init();
  // create ros publisher named debug and msg oject to send data
  debug.init();
  coder::ros::Publisher::rosmessage(&msg);
  amcl.Seed = 67.0;
  amcl.PrivateInitialPose[0] = 0.0;
  amcl.PrivateInitialPose[1] = 0.0;
  amcl.PrivateInitialPose[2] = 0.0;
  amcl.isInitialized = 0;
  amcl._pobj1.NumBeams = 60.0;
  amcl._pobj1.MeasurementNoise = 0.2;
  amcl._pobj1.RandomMeasurementWeight = 0.05;
  amcl._pobj1.ExpectedMeasurementWeight = 0.95;
  amcl._pobj1.MaxLikelihoodDistance = 2.0;
  amcl.PrivateSensorModel = &amcl._pobj1;
  amcl._pobj0.isInitialized = 0;
  amcl._pobj0.matlabCodegenIsDeleted = false;
  amcl.PrivateMotionModel = &amcl._pobj0;
  randomSeed = amcl.Seed;
  mclData = mclInitializeWithSeed_real64(randomSeed);
  amcl.MCLObj.MCLData = mclData;
  amcl.MCLObj.matlabCodegenIsDeleted = false;
  amcl.matlabCodegenIsDeleted = false;
  amcl.PrivateMotionModel = odometryModel.clone(&lobj_10);
  flag = (amcl.isInitialized == 1);
  if (flag) {
    mclData = amcl.MCLObj.MCLData;
    mclSetMotionModel_real64(mclData, &odometryModel.Noise[0]);
  }
  iobj_0 = &lobj_12[0];
  iobj_1 = &lobj_13[0];
  iobj_2 = &lobj_14[0];
  iobj_3 = &lobj_11[0];
  rangeFinderModel.InternalMap->copy(&lobj_0, &lobj_1, &lobj_2, &lobj_3);
  sensorTransform_Transform_Rotat[0] = expl_temp.Transform.Rotation.W;
  sensorTransform_Transform_Rotat[1] = expl_temp.Transform.Rotation.X;
  sensorTransform_Transform_Rotat[2] = expl_temp.Transform.Rotation.Y;
  sensorTransform_Transform_Rotat[3] = expl_temp.Transform.Rotation.Z;
  lobj_9.SensorPose[0] = expl_temp.Transform.Translation.X;
  lobj_9.SensorPose[1] = expl_temp.Transform.Translation.Y;
  coder::quat2eul(sensorTransform_Transform_Rotat, pose);
  lobj_9.SensorPose[2] = pose[0];
  lobj_9.SensorLimits[0] = 0.45;
  lobj_9.SensorLimits[1] = 8.0;
  lobj_9.NumBeams = 60.0;
  lobj_9.MeasurementNoise = 0.2;
  lobj_9.RandomMeasurementWeight = 0.05;
  lobj_9.ExpectedMeasurementWeight = 0.95;
  lobj_9.MaxLikelihoodDistance = 2.0;
  lobj_9.InternalMap =
      rangeFinderModel.InternalMap->copy(iobj_0, iobj_1, iobj_2, iobj_3);
  amcl.PrivateSensorModel = &lobj_9;
  amcl.PrivateUpdateThresholds[0] = 0.2;
  amcl.PrivateUpdateThresholds[1] = 0.2;
  amcl.PrivateUpdateThresholds[2] = 0.2;
  flag = (amcl.isInitialized == 1);
  if (flag) {
    mclData = amcl.MCLObj.MCLData;
    mclSetUpdateThresholds_real64(mclData, 0.2, 0.2, 0.2);
  }
  amcl.PrivateResamplingInterval = 1.0;
  flag = (amcl.isInitialized == 1);
  if (flag) {
    mclData = amcl.MCLObj.MCLData;
    mclSetResamplingInterval_real64(mclData, 1.0);
  }
  amcl.PrivateParticleLimits[0] = 500.0;
  amcl.PrivateParticleLimits[1] = 5000.0;
  amcl.PrivateGlobalLocalization = false;
  std::copy(&val[0], &val[9], &amcl.PrivateInitialCovariance[0]);
  while (1) {
    //  Receive laser scan and odometry message.
    laserSub.receive(&scanMsg.AngleMin, &scanMsg.AngleIncrement,
                     &scanMsg.RangeMin, &scanMsg.RangeMax, scanMsg.Ranges,
                     &flag, statustext);
    odomSub.get_LatestMessage(&randomSeed, &odompose_Y, &odompose_Z);
    if (flag) {
      double posecov[12];
      double posedata[12];
      int nx;
      coder::rosReadCartesian(&scanMsg, cart);
      if (cart.size(0) == 0) {
        b_aAngles.set_size(0, 0);
        aRanges.set_size(0, 0);
      } else {
        aAngles.set_size(cart.size(0));
        nx = cart.size(0);
        for (int k{0}; k < nx; k++) {
          aAngles[k] = rt_atan2d_snf(cart[k + cart.size(0)], cart[k]);
        }
        b_aRanges.set_size(cart.size(0));
        nx = cart.size(0);
        for (int k{0}; k < nx; k++) {
          b_aRanges[k] = rt_hypotd_snf(cart[k], cart[k + cart.size(0)]);
        }
        b_aAngles.set_size(aAngles.size(0), 1);
        nx = aAngles.size(0);
        for (int k{0}; k < nx; k++) {
          b_aAngles[k] = aAngles[k];
        }
        aRanges.set_size(b_aRanges.size(0), 1);
        nx = b_aRanges.size(0);
        for (int k{0}; k < nx; k++) {
          aRanges[k] = b_aRanges[k];
        }
      }
      scan.InternalRanges.set_size(aRanges.size(0) * aRanges.size(1));
      nx = aRanges.size(0) * aRanges.size(1);
      for (int k{0}; k < nx; k++) {
        scan.InternalRanges[k] = aRanges[k];
      }
      scan.InternalAngles.set_size(b_aAngles.size(0) * b_aAngles.size(1));
      nx = b_aAngles.size(0) * b_aAngles.size(1);
      for (int k{0}; k < nx; k++) {
        scan.InternalAngles[k] = b_aAngles[k];
      }
      coder::robotics::internal::wrapToPi(scan.InternalAngles);
      //  Create lidarScan object to pass to the AMCL object.
      //  For sensors that are mounted upside down, you need to reverse the
      //  order of scan angle readings using 'flip' function.
      //  Compute robot's pose [x,y,yaw] from odometry message.
      pose[0] = randomSeed;
      pose[1] = odompose_Y;
      pose[2] = odompose_Z;
      printf("odom z = %f\n", odompose_Z);
      fflush(stdout);
      //  Update estimated robot's pose and covariance using new odometry and
      //  sensor readings.
      if (amcl.isInitialized != 1) {
        amcl.setupAndReset();
      }
      mclData = amcl.MCLObj.MCLData;
      mclUpdate_real64(mclData,
                       static_cast<double>(aRanges.size(0) * aRanges.size(1)),
                       &(scan.InternalRanges.data())[0],
                       &(scan.InternalAngles.data())[0], &pose[0]);
      mclData = amcl.MCLObj.MCLData;
      mclIsUpdated_real64(mclData);
      mclData = amcl.MCLObj.MCLData;
      mclGetHypothesis_real64(mclData, &posecov[0]);
      for (int k{0}; k < 3; k++) {
        nx = k << 2;
        posedata[nx] = posecov[k];
        posedata[nx + 1] = posecov[k + 3];
        posedata[nx + 2] = posecov[k + 6];
        posedata[nx + 3] = posecov[k + 9];
      }
      //  Set the message object values(x,y,z) created by the publisher to the
      //  x,y,and yaw of the estimated pos
      msg.Point.X = posedata[0];
      // pos x
      msg.Point.Y = posedata[4];
      // pos y
      msg.Point.Z = posedata[8];
      // pos yaw
      msg.Header.FrameId.set_size(1, 10);
      for (int k{0}; k < 10; k++) {
        msg.Header.FrameId[k] = b_cv[k];
      }
      MATLABPUBLISHER_publish(debug.PublisherHelper, &msg);
      printf("estimated pose z = %f\n", posedata[8]);
      fflush(stdout);
    }
  }
}

//
// File trailer for amcl_test.cpp
//
// [EOF]
//
