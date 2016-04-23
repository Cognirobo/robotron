
int PotiVal=0;
int PWM=0;

void setup()
{
    
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  
  pinMode(5, OUTPUT);//PWM
  pinMode(6, OUTPUT); //PWM
  
  Serial.begin(9600);
 
 //pinMode(A0, INPUT); 
}

void loop()
{
  digitalWrite(0, LOW); 
  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  
  PotiVal = analogRead(A0);
  
  PWM= DutyCycle(PotiVal);
  
  Serial.print("PotiVal: ");
  Serial.print(PotiVal);
  Serial.print(" - PWM Duty Cylce: ");
  Serial.println(PWM);
  
  analogWrite(5, PWM);
  analogWrite(6, PWM); 
  
  
}

int DutyCycle(int Val){
  const int Untergrenze=40; //20% Duty Cycle
  const int Obergrenze=140;  //50% Duty Cycle
  
  int backValue=0;
  
  //backValue = Untergrenze+(0.098*Val);
  backValue=Val/4;
  
  return backValue;
}
