// the pin the speaker is attached to
int speakerPin = 8;
int iSong = 0;
int nSounds = 4;
int nRepeats = 4;

void setupAudioAlarm()
{
  pinMode(speakerPin, OUTPUT);
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
      chirp(16, 440, 15);
      break;
    case 1:
      chirpDown(16, 800, 15);
      break;
    case 2:
      alarmBeep(660, 100);
      break;
    case 3:
      siren(24, 800, 10);
      break;
    default:
      break;
  }
}

void nextAudioAlarm()
{
  iSong = (iSong + 1) % (3 * nSounds);
  carAlarm(iSong);
}

