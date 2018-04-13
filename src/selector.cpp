#include "ros/ros.h"
#include "std_msgs/String.h"
#include "homework1/data.h"
#include "homework1/select.h"
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <string>

// From https://ubuntuforums.org/archive/index.php/t-225713.html
int getch(void)
{
int ch;
struct termios oldt;
struct termios newt;
tcgetattr(STDIN_FILENO, &oldt); /*store old settings */
newt = oldt; /* copy old settings to new settings */
newt.c_lflag &= ~(ICANON | ECHO); /* make one change to old settings in new settings */
tcsetattr(STDIN_FILENO, TCSANOW, &newt); /*apply the new settings immediatly */
ch = getchar(); /* standard getchar call */
tcsetattr(STDIN_FILENO, TCSANOW, &oldt); /*reapply the old settings */
return ch; /*return received char */
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "selector");

  ros::NodeHandle n;
  ros::Publisher select = n.advertise<homework1::select>("select", 1000);

  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    char c = getch();

    if (std::string("nec").find(c) != std::string::npos) {
      homework1::select msg;
      msg.selection = c;
      select.publish(msg);

      ros::spinOnce();
    }

    // loop_rate.sleep();
  }

  return 0;
}
