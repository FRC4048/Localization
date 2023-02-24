#include "ros_structmsg_conversion.h"


// Conversions between ros_TimeStruct_T and ros::Time

void struct2msg(ros::Time* msgPtr, ros_TimeStruct_T const* structPtr)
{
  const std::string rosMessageType("ros_time/Time");

  msgPtr->nsec =  structPtr->Nsec;
  msgPtr->sec =  structPtr->Sec;
}

void msg2struct(ros_TimeStruct_T* structPtr, ros::Time const* msgPtr)
{
  const std::string rosMessageType("ros_time/Time");

  structPtr->Nsec =  msgPtr->nsec;
  structPtr->Sec =  msgPtr->sec;
}


// Conversions between sensor_msgs_LaserScanStruct_T and sensor_msgs::LaserScan

void struct2msg(sensor_msgs::LaserScan* msgPtr, sensor_msgs_LaserScanStruct_T const* structPtr)
{
  const std::string rosMessageType("sensor_msgs/LaserScan");

  msgPtr->angle_increment =  structPtr->AngleIncrement;
  msgPtr->angle_max =  structPtr->AngleMax;
  msgPtr->angle_min =  structPtr->AngleMin;
  struct2msg(&msgPtr->header, &structPtr->Header);
  convertFromStructPrimitiveArray(msgPtr->intensities, structPtr->Intensities);
  msgPtr->range_max =  structPtr->RangeMax;
  msgPtr->range_min =  structPtr->RangeMin;
  convertFromStructPrimitiveArray(msgPtr->ranges, structPtr->Ranges);
  msgPtr->scan_time =  structPtr->ScanTime;
  msgPtr->time_increment =  structPtr->TimeIncrement;
}

void msg2struct(sensor_msgs_LaserScanStruct_T* structPtr, sensor_msgs::LaserScan const* msgPtr)
{
  const std::string rosMessageType("sensor_msgs/LaserScan");

  structPtr->AngleIncrement =  msgPtr->angle_increment;
  structPtr->AngleMax =  msgPtr->angle_max;
  structPtr->AngleMin =  msgPtr->angle_min;
  msg2struct(&structPtr->Header, &msgPtr->header);
  convertToStructPrimitiveArray(structPtr->Intensities, msgPtr->intensities);
  structPtr->RangeMax =  msgPtr->range_max;
  structPtr->RangeMin =  msgPtr->range_min;
  convertToStructPrimitiveArray(structPtr->Ranges, msgPtr->ranges);
  structPtr->ScanTime =  msgPtr->scan_time;
  structPtr->TimeIncrement =  msgPtr->time_increment;
}


// Conversions between std_msgs_HeaderStruct_T and std_msgs::Header

void struct2msg(std_msgs::Header* msgPtr, std_msgs_HeaderStruct_T const* structPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertFromStructPrimitiveArray(msgPtr->frame_id, structPtr->FrameId);
  msgPtr->seq =  structPtr->Seq;
  struct2msg(&msgPtr->stamp, &structPtr->Stamp);
}

void msg2struct(std_msgs_HeaderStruct_T* structPtr, std_msgs::Header const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertToStructPrimitiveArray(structPtr->FrameId, msgPtr->frame_id);
  structPtr->Seq =  msgPtr->seq;
  msg2struct(&structPtr->Stamp, &msgPtr->stamp);
}

