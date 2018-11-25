#include "pitches.h"

int rib[] = {
  NOTE_E2, NOTE_E2, NOTE_E2, NOTE_E4,
  NOTE_AS4, NOTE_B4, NOTE_AS4,
  NOTE_FS3, NOTE_AS4, NOTE_A4,
  NOTE_F3, NOTE_A4, NOTE_GS4,
  
  NOTE_E2, NOTE_E2, NOTE_E2, NOTE_E3,
  NOTE_AS4, NOTE_B4, NOTE_AS4,
  NOTE_FS3, NOTE_AS4, NOTE_A4,
  NOTE_F3, NOTE_A4, NOTE_GS4,
  
  NOTE_E2, NOTE_E2, NOTE_E2, NOTE_A4,
  NOTE_DS5, NOTE_E5, NOTE_DS5,
  NOTE_B4, NOTE_DS5, NOTE_D5,
  NOTE_AS4, NOTE_D5, NOTE_CS5,
  
  NOTE_E2, NOTE_E2, NOTE_E2, NOTE_A4,
  NOTE_DS5, NOTE_E5, NOTE_DS5,
  NOTE_B4, NOTE_DS5, NOTE_D5,
  NOTE_AS4, NOTE_D5, NOTE_CS5,

};

int rib_tempo[] = {
  8, 8, 8, 8,
  8, 8, 4,
  8, 8, 4,  
  8, 8, 4,

  8, 8, 8, 8,
  8, 8, 4,
  8, 8, 4,  
  8, 8, 4,
  
  8, 8, 8, 8,
  8, 8, 4,
  8, 8, 4,  
  8, 8, 4,
  
  8, 8, 8, 8,
  8, 8, 4,
  8, 8, 4,  
  8, 8, 4
};

uint8_t numberOfRibNotes = sizeof(rib)/sizeof(int);

