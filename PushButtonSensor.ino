int sensorPin = 7;

void setupPushButtonSensor()
{
  pinMode(sensorPin, INPUT);
}

bool PushButtonAlarmCondition()
{
  return (digitalRead(sensorPin) == LOW);
}


