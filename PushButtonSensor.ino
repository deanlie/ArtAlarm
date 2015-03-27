int sensorPin;

void setupPushButtonSensor(int useThisPin)
{
  sensorPin = useThisPin;
  pinMode(sensorPin, INPUT);
}

bool PushButtonAlarmCondition()
{
  return (digitalRead(sensorPin) == LOW);
}


