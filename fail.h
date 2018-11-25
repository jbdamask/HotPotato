#include "pitches.h"

int fail[] = {
  NOTE_G3, NOTE_A3, NOTE_AS3, NOTE_G3,
  NOTE_CS4, NOTE_C4, NOTE_CS4, NOTE_C4,
  NOTE_CS4, NOTE_C4, NOTE_CS4, NOTE_C4,
  NOTE_CS4, NOTE_C4, NOTE_CS4, NOTE_C4,
  NOTE_CS4, NOTE_C4, NOTE_CS4, NOTE_C4
};

int fail_tempo[] = {
  3, 4, 2, 2,
  16, 16, 16, 16,
  16, 16, 16, 16,
  16, 16, 16, 16,
  16, 16, 16, 16  
};

uint8_t numberOfFailNotes = sizeof(fail)/sizeof(int);

