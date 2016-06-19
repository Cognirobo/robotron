/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/String.h>

const int pmwPin1 = 2;
const int pwmPin2 = 3;
const int pwmPin5 = 5;
const int pwmPin6 = 6; //motor2 PWM
const int pwmPin7 = 7; //motor2 B1
const int pmwPin8 = 8; //motor2 B2

int PotiVal=0;
int PWM=0;
int num=0;


ros::NodeHandle  nh;

void messageCb( const std_msgs::String& input){
  digitalWrite(12, HIGH);
  if(strlen( (const char* ) input.data) == 1) {
  digitalWrite(13, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  analogWrite(5, 0);
  analogWrite(6, 0);
  
  }
  if(strlen( (const char* ) input.data) == 2) {
  digitalWrite(13, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  PotiVal = analogRead(A0);
  PWM= DutyCycle(PotiVal);
  analogWrite(5, PWM);
  analogWrite(6, PWM);
  }
  if(strlen( (const char* ) input.data) == 3) {
  digitalWrite(13, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  PotiVal = analogRead(A0);
  PWM= DutyCycle(PotiVal);
  analogWrite(5, PWM);
  analogWrite(6, PWM);
  }
  if(strlen( (const char* ) input.data) == 4) {
  digitalWrite(13, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  analogWrite(5, 0);
  analogWrite(6, 0);
  }
  
}

ros::Subscriber<std_msgs::String> sub("robotron", &messageCb );

void setup()
{ 
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
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

int DutyCycle(int Val){
  const int Untergrenze=40; //20% Duty Cycle
  const int Obergrenze=140;  //50% Duty Cycle
  
  int backValue=0;
  
  backValue = Untergrenze+(0.098*Val);
  //backValue=Val/4;
  
  return backValue;
}
