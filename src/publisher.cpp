#include "ros/ros.h"
#include "std_msgs/String.h"
#include "homework1/data.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "publisher");

  ros::NodeHandle n;
  ros::Publisher publisher = n.advertise<homework1::data>("info", 1000);
  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    homework1::data msg;
    msg.name = "Buck Back";
    msg.age = 27;
    msg.course = "American Constitutional Thought and Jurisprudence (for PoliSci) and Japanese language and East Asian Popular Culture Studies (for AsianCiv)";
    publisher.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
