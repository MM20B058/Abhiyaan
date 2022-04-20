#include "ros/ros.h"
#include "std_msgs/String.h"

std::string str;

void func(const std_msgs::String::ConstPtr& msg){
        int n = strlen(msg->data.c_str());
        int j = 0;
        str = msg->data.c_str();
        for(int i = 0;i < n;i++){
                if(str[i]==' '){
                        std::reverse(str.begin()+j,str.begin()+i);
                        j = i+1;
                }
                else if(i == n-1)
                        std::reverse(str.begin()+j,str.end());
        }
}

int main(int argc, char **argv){
	ros::init(argc, argv, "Node3");
	ros::NodeHandle n;
	ros::Subscriber topic_sub =  n.subscribe("team_abhiyaan",1000,func);
	ros::Publisher topic_pub =  n.advertise<std_msgs::String>("naayihba_maet",1000);
	ros::Rate loop_rate(1);
    while(ros::ok()){
	std_msgs::String msg;
	msg.data = str;
topic_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
        ros::spin();
    return 0;
}

