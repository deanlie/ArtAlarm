
int ledPin = 4;
int iBlink = 0;

void setupRedLightAlarm()
{
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void nextRedLight()
{
  iBlink = (iBlink + 1) % 2;

  if (iBlink) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}

void noRedLight()
{
  digitalWrite(ledPin, LOW);
}
