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

// include our list of note pitches
#include "pitches.h"

// the pin the speaker is attached to
int sensorPin = 7;
int speakerPin = 8;
int ledPin = 4;
int iSong = 0;
int iBlink = 0;
int nSounds = 4;

void chirp(int numberOfNotes, int basePitch, int durationEach)
{
  float thisNoteTone = basePitch;
  unsigned int thisNoteInt;

  // iterate over the notes of the melody
  for (int thisNote = 0; thisNote < numberOfNotes; thisNote++)
  {
    thisNoteTone *= (226.0 / 220.0);
    thisNoteInt = thisNoteTone;

    // play the note
    tone(speakerPin, thisNoteInt);
    delay(durationEach);
  }
  noTone(speakerPin);
  delay(8 * durationEach);
}

void chirpDown(int numberOfNotes, int basePitch, int durationEach)
{
  float thisNoteTone = basePitch * 2;
  unsigned int thisNoteInt;

  // iterate over the notes of the melody
  for (int thisNote = numberOfNotes - 1; thisNote > 0; thisNote--)
  {
    thisNoteTone *= (220.0 / 226.0);
    thisNoteInt = thisNoteTone;

    // play the note
    tone(speakerPin, thisNoteInt);
    delay(durationEach);
  }
  noTone(speakerPin);
  delay(8 * durationEach);
}

void siren(int numberOfNotes, int basePitch, int durationEach)
{
  float thisNoteTone = basePitch;
  unsigned int thisNoteInt;
  
  // iterate over pitches, rising first
  for (int thisNote = 0; thisNote < numberOfNotes; thisNote++)
  {
    thisNoteTone *= (226.0 / 220.0);
    thisNoteInt = thisNoteTone;
    
    // play the tone
    tone(speakerPin, thisNoteInt);
    delay(durationEach);
  }
  for (int thisNote = 0; thisNote < numberOfNotes; thisNote++)
  {
    thisNoteTone *= (220.0 / 226.0);
    thisNoteInt = thisNoteTone;
    
    // play the tone
    tone(speakerPin, thisNoteInt);
    delay(durationEach);
  }
  noTone(speakerPin);
  delay(10 * durationEach);
}

void alarmBeep(int basePitch, int duration)
{
  tone(speakerPin, basePitch);
  delay(duration);
  noTone(speakerPin);
  delay(2 * duration);
}

void carAlarm(int i)
{
  int switchValue = (i / 3) % nSounds;
  switch(switchValue) {
    case 0:
      chirp(16, 262, 25);
      break;
    case 1:
      chirpDown(16, 262, 25);
      break;
    case 2:
      alarmBeep(440, 250);
      break;
    case 3:
      siren(24, 800, 20);
      break;
    default:
      break;
  }
}

void setupSensor()
{
  pinMode(sensorPin, INPUT);
}

void setupOutput()
{
  pinMode(speakerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

bool alarmCondition()
{
  return (digitalRead(sensorPin) == LOW);
}

void setup()
{
  setupSensor();
  setupOutput();
}

void loop()
{
  if (alarmCondition()) {
    iSong = (iSong + 1) % (3 * nSounds);
    iBlink = (iBlink + 1) % 2;

    if (iBlink) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
    
    carAlarm(iSong);
  } else {
    // else make sure the light is off
    digitalWrite(ledPin, LOW);
  }
}

  
