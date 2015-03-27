int MBTrigPin = 3; // yellow
int MBEchoPin = 2; // green

int maxBotAlarmDistance;

void setupMaxBotRanger(int distance)
{
  maxBotAlarmDistance = distance;
  
  pinMode(MBTrigPin, OUTPUT);
  pinMode(MBEchoPin, INPUT);
  
  digitalWrite(MBTrigPin, LOW);
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
  
  Serial.print("Distance in cm: ");
  Serial.println(distanceInCentimeters);
 
  return distanceInCentimeters; 
}

bool MaxBotAlarmCondition()
{
  float distanceInCentimeters = measureMaxBotRange();
  
  return (distanceInCentimeters > 0.01 &&
          distanceInCentimeters < maxBotAlarmDistance);
}
