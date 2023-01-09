//Diagnostic of Playing wav Audio Files  in Teenscience Platform REVA, R.Hormigo 2019
//Test using teensy audio library at 44.1KHz 16bit with codec AK4558


//control_ak4558.h changes  define AK4558_CAD1 0 and define AK4558_CAD0 0 to support TeenScience REV A (Default to 1 in REV B)
//Also check bug in control_ak4558.cpp at convertVolume(float). I changed it to : uint8_t temp = (vol*255)+0.5; 
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioPlaySdWav           playSdWav1;     //xy=475,260
AudioOutputI2S           i2s1;           //xy=678,286
AudioConnection          patchCord1(playSdWav1, 0, i2s1, 0);
AudioConnection          patchCord2(playSdWav1, 1, i2s1, 1);
AudioControlAK4558       ak4558_1;       //xy=605,417.3999996185303
// GUItool: end automatically generated code



// Teensy 3.5 & 3.6 SD card
#define SDCARD_CS_PIN    BUILTIN_SDCARD
#define SDCARD_MOSI_PIN  11  // not actually used
#define SDCARD_SCK_PIN   13  // not actually used


void setup() {
  Serial.begin(115200);
  delay(100);

  AudioMemory(8);

  ak4558_1.enable();
  ak4558_1.enableOut();
  ak4558_1.volume(0.8);

  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    // stop here, but print a message repetitively
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
}

void playFile(const char *filename)
{
  Serial.print("Playing file: ");
  Serial.println(filename);

  // Start playing the file.  This sketch continues to
  // run while the file plays.
  playSdWav1.play(filename);
  // A brief delay for the library read WAV info
  delay(5);
  // Simply wait for the file to finish playing.
  while (playSdWav1.isPlaying()) {
    float vol = analogRead(0);  //Pot in Teenscience controlling the out attenuation
    vol = vol / 1024;
    ak4558_1.volume(vol);
  }
}


void loop() {

  playFile("TONE880.WAV");  // filenames are always uppercase 8.3 format
  delay(500);

  playFile("CANTDO.WAV");
  delay(500);

  playFile("TONES.WAV");
  delay(500);
}
