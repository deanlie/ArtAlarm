/*
 * Tutorial 4a: Melody
 * 
 * Plays a melody through a speaker.
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
const int melody[][2] = 
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

const int chirpSound[][2] =
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

void setup()
{
    pinMode(speakerPin, OUTPUT);

    // figure out the number of notes in our melody
    int numberOfNotes = sizeof(melody) / sizeof(chirpSound[0]);

    // iterate over the notes of the melody
    for (int thisNote = 0; thisNote < numberOfNotes; thisNote++)
    {
        // grab our note and note duration from our array
        int thisNoteTone = melody[thisNote][0];
        int thisNoteDuration = melody[thisNote][1];

        // to calculate the note duration in ms
        int noteDurationMS = 1000 / thisNoteDuration;

        // play the note
        tone(speakerPin, thisNoteTone, noteDurationMS);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        delay(noteDurationMS);
        
        delay(noteDurationMS * 0.30);
    }
    delay(100);
    chirp();
    delay(200);
    chirp();
    delay(200);
    chirp();
}

void loop()
{
    // no need to repeat the melody.
    // do nothing
}

void chirp()
{
    int numberOfNotes = sizeof(chirpSound) / sizeof(chirpSound[0]);

    // iterate over the notes of the melody
    for (int thisNote = 0; thisNote < numberOfNotes; thisNote++)
    {
        // grab our note and note duration from our array
        int thisNoteTone = chirpSound[thisNote][0];
        int thisNoteDuration = chirpSound[thisNote][1];

        // to calculate the note duration in ms
        int noteDurationMS = 1000 / thisNoteDuration;

        // play the note
        tone(speakerPin, thisNoteTone, noteDurationMS);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        // delay(noteDurationMS);
        
        delay(noteDurationMS * 0.30);
    }
}  
