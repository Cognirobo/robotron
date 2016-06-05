/*
 * rosserial Publisher Example
 * Prints "the potival ak input from a poti on the board"
 */

#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>

ros::NodeHandle nh;

std_msgs::Int32 str_msg;
ros::Publisher chatter("chatter", &str_msg);

//std_msgs::String str_msg;
//ros::Publisher chatter("chatter", &str_msg);

int PotiVal = 0;

void setup()
{
  nh.initNode();
  nh.advertise(chatter);
  pinMode(A0, INPUT);
}

void loop()
{
  PotiVal = analogRead(A0);
  str_msg.data = PotiVal;
  chatter.publish( &str_msg );
  nh.spinOnce();
  delay(2);
}
