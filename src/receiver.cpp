#include "ros/ros.h"
#include "std_msgs/String.h"
#include "homework1/data.h"
#include "homework1/select.h"

char type = 'x';

void infoCallback(const homework1::data::ConstPtr& msg)
{
  switch (type) {
    case 'n':
      ROS_INFO("Name: '%s'", msg->name.c_str());
    break;
    case 'e':
      ROS_INFO("Age: %d", msg->age);
    break;
    case 'c':
      ROS_INFO("Course: '%s'", msg->course.c_str());
    break;
  }
}

void selectCallback(const homework1::select::ConstPtr& msg)
{
  type = msg->selection;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "receiver");

  ros::NodeHandle n;
  ros::Subscriber sub_inf = n.subscribe("info", 1000, infoCallback);
  ros::Subscriber sub_sel = n.subscribe("select", 1000, selectCallback);

  ros::spin();
  return 0;
}
