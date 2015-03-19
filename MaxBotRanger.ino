int MBTrigPin = 3; // yellow
int MBEchoPin = 2; // green

void setupMaxBotRanger()
{
  pinMode(MBTrigPin, OUTPUT);
  pinMode(MBEchoPin, INPUT);
  
  digitalWrite(MBTrigPin, LOW);
  
  Serial.begin(9600);
}

float measureMaxBotRange()
{
  int pulseLenMicroseconds;
  float distanceInCentimeters;

  digitalWrite(MBTrigPin, HIGH);
  delayMicroseconds(30);
  digitalWrite(MBTrigPin, LOW);
  
  pulseLenMicroseconds = pulseIn(MBEchoPin, HIGH);
  distanceInCentimeters = pulseLenMicroseconds / 29.387 / 2;
  
  Serial.println(distanceInCentimeters);
 
  return distanceInCentimeters; 
}

bool MaxBotAlarmCondition()
{
  float distanceInCentimeters = measureMaxBotRange();
  
  return (distanceInCentimeters < 20);
}
