/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/String.h>

ros::NodeHandle  nh;

void messageCb( const std_msgs::String& input){
  digitalWrite(12, HIGH);
  if(strlen( (const char* ) input.data) == 1) {
  digitalWrite(13, HIGH);
  }
  if(strlen( (const char* ) input.data) == 2) {
  digitalWrite(13, LOW);
}

ros::Subscriber<std_msgs::String> sub("robotron", &messageCb );

void setup()
{ 
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  digitalWrite(11, HIGH);
  delay(1);
}

