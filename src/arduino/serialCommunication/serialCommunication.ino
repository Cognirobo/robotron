
const int ledPin = 13;
void setup()
{
 pinMode(ledPin, OUTPUT);
 Serial.begin(9600);
}
void loop()
{
 if (Serial.available())
 {
  int num = Serial.read() - '0';
  {
   for (int i= 0; i<num; i++)
    {
     digitalWrite(ledPin, HIGH);
     delay(300);
     digitalWrite(ledPin, LOW);
     delay(300);
    }
   }
  }
 delay(1000);
}
