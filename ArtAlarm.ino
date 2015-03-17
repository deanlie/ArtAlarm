/*
 * Derived from Osepp Tutorial 4a: Melody
 * 
 * Plays car alarm sounds through a speaker.
 *
 * The circuit:
 *  - 8-ohm speaker conected to digital pin 8 through a 100 ohm resistor
 *
 * created 21 Jan 2010
 * modified 30 Aug 2011
 * by Tom Igoe 
 * modified 14 August 2013
 * by Blaise Jarrett
 *
 * For further mods see GitHub deanlie/ArtAlarm
 *
 * This example code is in the public domain.
 *
 * Derivative work from:
 * http://arduino.cc/en/Tutorial/Tone
 *
 */

// include our list of note pitches
#include "pitches.h"

// the pin the speaker is attached to
int speakerPin = 8;
int ledPin = 4;

// the notes in our melody and their duration in fractions of a second
// e.g. quarter note = 4, eighth note = 8, etc.
const int shaveSong[][2] = 
{
    {NOTE_C4, 4},
    {NOTE_G3, 8},
    {NOTE_G3, 8},
    {NOTE_A3, 4},
    {NOTE_G3, 4},
    {NOTE_BLANK, 4},
    {NOTE_B3, 4},
    {NOTE_C4, 4}
};
const int shaveSongNum = sizeof(shaveSong) / sizeof(shaveSong[0]);

const int chirpSong[][2] =
{
  {NOTE_C4, 32},
  {NOTE_CS4, 32},
  {NOTE_D4, 32},
  {NOTE_DS4, 32},
  {NOTE_E4, 32},
  {NOTE_F4, 32},
  {NOTE_FS4, 32},
  {NOTE_G4, 32},
  {NOTE_GS4, 32},
  {NOTE_A4, 32},
  {NOTE_AS4, 32},
  {NOTE_B4, 32},
  {NOTE_CS5, 32}
};
const int chirpSongNum = sizeof(chirpSong) / sizeof(chirpSong[0]);

void playSong(const int aSong[][2], const int numNotes, int beatsPerMinute)
{
  int wholeNoteDuration = 240000 / beatsPerMinute;

  // iterate over the notes of the melody
  for (int thisNote = 0; thisNote < numNotes; thisNote++)
  {
    // grab our note and note duration from our array
    int thisNoteTone = aSong[thisNote][0];
    int thisNoteValue = aSong[thisNote][1];

    // to calculate the note duration in ms
    int noteDurationMS = wholeNoteDuration / thisNoteValue * 0.70;
    int spaceDurationMS = wholeNoteDuration / thisNoteValue * 0.30;

    // play the note
    tone(speakerPin, thisNoteTone, noteDurationMS);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    delay(noteDurationMS);
        
    delay(spaceDurationMS);
  }
}

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
  switch(i % 9) {
    case 0:
    case 1:
    case 2:
      chirp(16, 262, 25);
      break;
    case 3:
    case 4:
    case 5:
      siren(24, 800, 20);
      break;
    case 6:
    case 7:
    case 8:
      alarmBeep(440, 250);
      break;
    default:
      break;
  }
}

void setup()
{
    pinMode(speakerPin, OUTPUT);
    
    pinMode(ledPin, OUTPUT);
    
    digitalWrite(ledPin, HIGH);

    chirp(16, 262, 25);
    digitalWrite(ledPin, HIGH);
    chirp(16, 262, 25);
    digitalWrite(ledPin, LOW);
    chirp(16, 262, 25);
    digitalWrite(ledPin, HIGH);
    
    siren(24, 800, 20);
    digitalWrite(ledPin, LOW);
    siren(24, 800, 20);
    digitalWrite(ledPin, HIGH);
    siren(24, 800, 20);
    digitalWrite(ledPin, LOW);
    
    alarmBeep(440, 250);
    digitalWrite(ledPin, HIGH);
    alarmBeep(440, 250);
    digitalWrite(ledPin, LOW);
    alarmBeep(440, 250);
    digitalWrite(ledPin, HIGH);
}

void loop()
{
    // no need to repeat the melody.
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(1000);
    // do nothing
}

  
