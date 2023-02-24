#ifndef _ROS_STRUCTMSG_CONVERSION_H_
#define _ROS_STRUCTMSG_CONVERSION_H_

#include <ros/ros.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/PointStamped.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Transform.h>
#include <geometry_msgs/TransformStamped.h>
#include <geometry_msgs/Vector3.h>
#include <nav_msgs/MapMetaData.h>
#include <nav_msgs/OccupancyGrid.h>
#include <ros/time.h>
#include <sensor_msgs/LaserScan.h>
#include <std_msgs/Header.h>
#include "amcl_test_types.h"
#include "mlroscpp_msgconvert_utils.h"


void struct2msg(geometry_msgs::Point* msgPtr, geometry_msgs_PointStruct_T const* structPtr);
void msg2struct(geometry_msgs_PointStruct_T* structPtr, geometry_msgs::Point const* msgPtr);

void struct2msg(geometry_msgs::PointStamped* msgPtr, geometry_msgs_PointStampedStruct_T const* structPtr);
void msg2struct(geometry_msgs_PointStampedStruct_T* structPtr, geometry_msgs::PointStamped const* msgPtr);

void struct2msg(geometry_msgs::Pose* msgPtr, geometry_msgs_PoseStruct_T const* structPtr);
void msg2struct(geometry_msgs_PoseStruct_T* structPtr, geometry_msgs::Pose const* msgPtr);

void struct2msg(geometry_msgs::Quaternion* msgPtr, geometry_msgs_QuaternionStruct_T const* structPtr);
void msg2struct(geometry_msgs_QuaternionStruct_T* structPtr, geometry_msgs::Quaternion const* msgPtr);

void struct2msg(geometry_msgs::Transform* msgPtr, geometry_msgs_TransformStruct_T const* structPtr);
void msg2struct(geometry_msgs_TransformStruct_T* structPtr, geometry_msgs::Transform const* msgPtr);

void struct2msg(geometry_msgs::TransformStamped* msgPtr, geometry_msgs_TransformStampedStruct_T const* structPtr);
void msg2struct(geometry_msgs_TransformStampedStruct_T* structPtr, geometry_msgs::TransformStamped const* msgPtr);

void struct2msg(geometry_msgs::Vector3* msgPtr, geometry_msgs_Vector3Struct_T const* structPtr);
void msg2struct(geometry_msgs_Vector3Struct_T* structPtr, geometry_msgs::Vector3 const* msgPtr);

void struct2msg(nav_msgs::MapMetaData* msgPtr, nav_msgs_MapMetaDataStruct_T const* structPtr);
void msg2struct(nav_msgs_MapMetaDataStruct_T* structPtr, nav_msgs::MapMetaData const* msgPtr);

void struct2msg(nav_msgs::OccupancyGrid* msgPtr, nav_msgs_OccupancyGridStruct_T const* structPtr);
void msg2struct(nav_msgs_OccupancyGridStruct_T* structPtr, nav_msgs::OccupancyGrid const* msgPtr);

void struct2msg(ros::Time* msgPtr, ros_TimeStruct_T const* structPtr);
void msg2struct(ros_TimeStruct_T* structPtr, ros::Time const* msgPtr);

void struct2msg(sensor_msgs::LaserScan* msgPtr, sensor_msgs_LaserScanStruct_T const* structPtr);
void msg2struct(sensor_msgs_LaserScanStruct_T* structPtr, sensor_msgs::LaserScan const* msgPtr);

void struct2msg(std_msgs::Header* msgPtr, std_msgs_HeaderStruct_T const* structPtr);
void msg2struct(std_msgs_HeaderStruct_T* structPtr, std_msgs::Header const* msgPtr);


#endif
