//Diagnostic of Audio DSP in to out in Teenscience Platform REVA, R.Hormigo 2019
//Test using teensy audio library at 44.1KHz 16bit with codec AK4558


//remember to revert control_ak4558.h if was changed in Teenscience REVA. In REVB of the board define AK4558_CAD1 and define AK4558_CAD0 must be 1 (default)
//Also check bug in control_ak4558.cpp at convertVolume(float). I changed it to : uint8_t temp = (vol*255)+0.5; 

#include <Audio.h> 
#include <Wire.h>


// GUItool: begin automatically generated code  
AudioInputI2S           i2s1;
AudioOutputI2S           i2s2;          
AudioConnection          patchCord1(i2s1, 0, i2s2, 0);
AudioConnection          patchCord2(i2s1, 1, i2s2, 1);
AudioControlAK4558       ak4558;       



void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Starting");
  AudioMemory(12);
  ak4558.enable();
  ak4558.enableIn();
  ak4558.enableOut();

}


void loop() {
    float vol = analogRead(0);  //Pot in Teenscience controlling the out attenuation
    Serial.print(vol);
    Serial.print(" ");
    vol = vol / 1023.0;
    ak4558.volume(vol);
    Serial.println(vol,4);
    delay(250);
    
}
