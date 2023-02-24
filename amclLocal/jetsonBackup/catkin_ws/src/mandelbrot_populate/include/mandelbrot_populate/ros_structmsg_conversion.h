#ifndef _ROS_STRUCTMSG_CONVERSION_H_
#define _ROS_STRUCTMSG_CONVERSION_H_

#include <ros/ros.h>
#include <ros/time.h>
#include <sensor_msgs/LaserScan.h>
#include <std_msgs/Header.h>
#include "mandelbrot_populate_types.h"
#include "mlroscpp_msgconvert_utils.h"


void struct2msg(ros::Time* msgPtr, ros_TimeStruct_T const* structPtr);
void msg2struct(ros_TimeStruct_T* structPtr, ros::Time const* msgPtr);

void struct2msg(sensor_msgs::LaserScan* msgPtr, sensor_msgs_LaserScanStruct_T const* structPtr);
void msg2struct(sensor_msgs_LaserScanStruct_T* structPtr, sensor_msgs::LaserScan const* msgPtr);

void struct2msg(std_msgs::Header* msgPtr, std_msgs_HeaderStruct_T const* structPtr);
void msg2struct(std_msgs_HeaderStruct_T* structPtr, std_msgs::Header const* msgPtr);


#endif
