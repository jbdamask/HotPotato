///////////////////////////////////////////////////////////////////////////////
// Circuit Playground Hot Potato
//
// Original Author: Carter Nelson 
// Extended by: John B. Damask 2018 (added fail song and other tunes)
// MIT License (https://opensource.org/licenses/MIT)

#include <Adafruit_CircuitPlayground.h>
#include "melody.h"
#include "fail.h"
#include "rainingBlood.h"   

#define SHAKE_THRESHOLD     30    // Total acceleration threshold for shake detect

int gameLength;
uint8_t numNotes; 

int * currentTune;
int * currentTempo;

///////////////////////////////////////////////////////////////////////////////
float getTotalAccel() {
  // Compute total acceleration
  float X = 0;
  float Y = 0;
  float Z = 0;
  for (int i=0; i<10; i++) {
    X += CircuitPlayground.motionX();
    Y += CircuitPlayground.motionY();
    Z += CircuitPlayground.motionZ();
    delay(1);
  }
  X /= 10;
  Y /= 10;
  Z /= 10;

  return sqrt(X*X + Y*Y + Z*Z);
}

///////////////////////////////////////////////////////////////////////////////
void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_8_G);
  
  // Make it bright!
  CircuitPlayground.setBrightness(50);

  // Set the NeoPixels all red
  for (int p=0; p<10; p++) CircuitPlayground.setPixelColor(p, 0xFF0000);

  // Seed the random function with noise
  int seed = 0;
  
  seed += analogRead(12);
  seed += analogRead(7);
  seed += analogRead(9);
  seed += analogRead(10);
 
  randomSeed(seed);
}

int currentTime = millis();

///////////////////////////////////////////////////////////////////////////////
void loop() {
  // Wait for shaking
  while (getTotalAccel() < SHAKE_THRESHOLD) {
    // do nothing
    if(millis() - currentTime > 10000){
      CircuitPlayground.clearPixels();
    }
  }

  int r = random(1,3);
  Serial.println(r);
  switch(r){
    case 1:
      currentTune = rib;
      currentTempo = rib_tempo;
      numNotes = sizeof(rib)/sizeof(int);
      break;
    default:
      currentTune = melody;
      currentTempo = tempo;
      numNotes = sizeof(melody)/sizeof(int);
      break;
  }

  // Game length
  int gameLength = random(numberOfNotes,2*numberOfNotes);

  // Game play with melody
  int noteToPlay = 0;
  for (int gameStep=0; gameStep<gameLength; gameStep++) {

    // Add some flare using the NeoPixels
    for (int p=0; p<10; p++) CircuitPlayground.setPixelColor(p, 0x000000);
    CircuitPlayground.setPixelColor(random(0,10), random(256),random(256),random(256)); 
    
    // Play the note
    int noteDuration = 1000 / currentTempo[noteToPlay];
    CircuitPlayground.playTone(currentTune[noteToPlay], noteDuration);
        
    // Increment and check the note counter
    noteToPlay++;
    if (noteToPlay >= numNotes) noteToPlay = 0;    
  }

  //
  // GAME OVER
  //
  
  // Set the NeoPixels all red
  for (int p=0; p<10; p++) CircuitPlayground.setPixelColor(p, 0xFF0000);
  noteToPlay = 0; // reset
  while(noteToPlay < numberOfFailNotes){    
    int noteDuration = 1000 / fail_tempo[noteToPlay];
    CircuitPlayground.playTone(fail[noteToPlay], noteDuration);
    noteToPlay++;    
  }
  noteToPlay = 0;

  // Delay a bit so can't just reset with a shake
  delay(2000);
}
