/*
 * Derived from Osepp Tutorial 4a: Melody, which was
 * created 21 Jan 2010
 * modified 30 Aug 2011
 * by Tom Igoe 
 * modified 14 August 2013
 * by Blaise Jarrett
 *
 * The Osepp tutorial example code is in the public domain.
 *
 * Derivative work from:
 * http://arduino.cc/en/Tutorial/Tone
 *
 * Plays car alarm sounds through a speaker.
 *
 * The circuit:
 *  - 8-ohm speaker conected to digital pin 8 through a 100 ohm resistor
 *  - LED connected to digital pin 4 through a 330 ohm resistor
 *  - momentary pushbutton switch connected to digital pin 7 with a pullup
 *
 * For further mods see GitHub deanlie/ArtAlarm
 */

int buttonPin = 7;
int thresholdInCm = 30;

void setupSensor()
{
  setupPushButtonSensor(buttonPin);
  setupMaxBotRanger(thresholdInCm);
}

void setupOutput()
{
  setupAudioAlarm();
  setupRedLightAlarm();
}

bool alarmCondition()
{
  return (PushButtonAlarmCondition() ||
          MaxBotAlarmCondition());
}

void setup()
{
  Serial.begin(9600);
  setupSensor();
  setupOutput();
}

void loop()
{
  if (alarmCondition()) {
    nextRedLight();
    nextAudioAlarm();
  } else {
    noRedLight();
  }
  delay(200);
}

  
