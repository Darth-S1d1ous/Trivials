#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <sstream>
int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker_a");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<std_msgs::Int32>("topic_a", 1000);
  int number;
  std_msgs::Int32 msg;
  while (ros::ok()) {
    std::cout << "Enter an integer a: ";
    std::cin >> number;

    msg.data = number;
    pub.publish(msg);

    ros::spinOnce();
  }
  return 0;
}
