#include "ros/ros.h"
#include "std_msgs/String.h"
#include "square_it.h"

#include <iostream>

int main(int argc, char **argv) {

    ros::init(argc, argv, "talker");

    ros::NodeHandle nh;

    ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter", 1000);

    ros::Rate loop_rate(10);

    int count= 0;

    while (ros::ok()){

        std_msgs::String msg;

        std::stringstream ss;

        double value_count = square_it(count);

        ss << "Doubling " << count << " to " << value_count;
        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());

        chatter_pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
        ++count;
    }

    return 0;
}
