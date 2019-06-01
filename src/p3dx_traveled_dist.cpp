#include <ros/ros.h>
#include <tf/tf.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>
#include <nav_msgs/Odometry.h>
#include <math.h>

float x_ant, y_ant, x_act, y_act, dist;
// Global variable declaration
class p3dx_travelled_dist
{
private:
  float d_0;

public:

  void set_intial_dist(float d)
  {
    d_0 = d;
  }
  float get_initial_dist(void)
  {
    return d_0;
  }
};

float distance(float x_an,float x_ac, float y_an, float y_ac)
{
    float d_x, d_y;

    d_x = x_an-x_ac;

    d_y = y_an-y_ac;

    float distance;
    distance = sqrt((d_x*d_x)+(d_y*d_y));

    return distance;
}

void chatterCallback(const nav_msgs::Odometry::ConstPtr msg)
{
  float temp_x, temp_y;
    int i;

    for (i; i<1; i++)
    {
        x_ant = msg->pose.pose.position.x;
        y_ant = msg->pose.pose.position.y;
        dist = 0;
    }

    x_act = msg->pose.pose.position.x;
    y_act = msg->pose.pose.position.y;

    dist += distance(x_ant,x_act,y_ant,y_act);

  //ROS_INFO("Seq: [%d]", msg->header.seq);

    ROS_INFO("Distancia Recorrida: [%f] m", dist);

    temp_x = x_ant;
    temp_y = y_ant;

    x_ant = x_act;
    y_ant = y_act;
}

int main(int argc, char **argv)
{


    float dist = 0;
    ros::init(argc, argv, "p3dx_traveled_dist");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("/RosAria/pose",1000, chatterCallback);
    ros::spin();

    return 0;
}
