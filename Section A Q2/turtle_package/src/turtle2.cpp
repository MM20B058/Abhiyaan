#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
float pi=3.14;
float l_x2, a_z2;    
float x,y,alpha,beta,r; 
void func(const turtlesim::Pose& msg){
    x = msg.x;                       
    y = msg.y;                       
    beta = msg.theta;                  
    r = 2*pow((pow((x-5.5),2)+pow((y-5.5),2)),0.5);
    alpha = acos(sqrt(2)*(1-(2/r)));
    if(y < 5.5)
        alpha = 2*pi - alpha;
    if(beta < 0)
        beta += 2*pi ;
    l_x2 = 3/(r*sin(beta-alpha));
    a_z2 = 6/pow(r,2);
}

int main(int argc, char **argv){
	ros::init(argc, argv, "Turtle2");
	ros::NodeHandle n;
    ros::Subscriber posesub2 = n.subscribe("/turtle2/pose",10,func);
    ros::Publisher velpub2 =  n.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel",10);
    ros::Rate loop_rate(1);
    while(ros::ok()){
    	geometry_msgs::Twist vel_msg2;
    	vel_msg2.linear.x = l_x2;
        vel_msg2.linear.y = 0;           
        vel_msg2.linear.z = 0;
        vel_msg2.angular.x = 0;
        vel_msg2.angular.y = 0;
        vel_msg2.angular.z = a_z2;
        velpub2.publish(vel_msg2);
    	ros::spinOnce();
    	loop_rate.sleep();
    }
    ros::spin();
    return 0;
}

    	