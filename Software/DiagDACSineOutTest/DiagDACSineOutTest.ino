


#include <Audio.h>
#include <Wire.h>


AudioSynthToneSweep      tonesweep;     
AudioOutputAnalogStereo        dacs;      
AudioConnection          patchCord1(tonesweep,0, dacs, 0);
AudioConnection          patchCord2(tonesweep,0, dacs, 1); 



int phase = 0;

void setup() {
  // put your setup code here, to run once:
  AudioMemory(12);
  dacs.analogReference(EXTERNAL);

  Serial.begin(115200);
  delay(100);


}

void loop() {
  tonesweep.play(1.0, 1000, 2000, 5);

	delay(6000);

}
