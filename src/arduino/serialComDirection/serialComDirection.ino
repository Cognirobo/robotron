
const int ledPin = 13;
const int pmwPin1 = 2;
const int pwmPin2 = 3;
int PotiVal=0;
int PWM=0;

void setup()
{
 pinMode(ledPin, OUTPUT);
 pinMode(A0, INPUT);
 Serial.begin(9600);
}
void loop()
{

  
 if (Serial.available())
 {
  int num = Serial.read() - '0';
  {
    if(num == 1) {
      digitalWrite(ledPin, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      PotiVal = analogRead(A0);
      PWM= DutyCycle(PotiVal);
      analogWrite(5, PWM);
      delay(1000);
    }
    if (num == 2) {
      digitalWrite(ledPin, HIGH);
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      PotiVal = analogRead(A0);
      PWM= DutyCycle(PotiVal);
      analogWrite(5, PWM);
      delay(1000);
    }
    if (num == 3) {
      digitalWrite(ledPin, LOW);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
    }
  }
 delay(1000);
}
}

int DutyCycle(int Val){
  const int Untergrenze=40; //20% Duty Cycle
  const int Obergrenze=140;  //50% Duty Cycle
  
  int backValue=0;
  
  //backValue = Untergrenze+(0.098*Val);
  backValue=Val/4;
  
  return backValue;
}
