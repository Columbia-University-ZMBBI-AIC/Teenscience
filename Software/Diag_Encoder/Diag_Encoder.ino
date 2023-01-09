//Diagnostic of encoder function in Teenscience Platform REVA, R.Hormigo 2019
//YOu neeed the Encoder library already in Teensyduino and initiate an object Encoder  with the pins used in Teenscience 3, 4, 29, and 30). 
//To find a position just assign the function read of the class Encoder to a long variable

#include <Encoder.h>

#define LED_GR 10
#define LED_RGB_R 12
#define LED_RGB_G 54
#define LED_RGB_B 55


Encoder myEncL(3, 4); //Encoder Left pins (With IRQ for performance)
Encoder myEncR(29, 30); //Encoder Right pins (With IRQ for performance)


void setup() {
  pinMode(LED_GR, OUTPUT);
  pinMode(LED_RGB_R, OUTPUT);
  pinMode(LED_RGB_G, OUTPUT);
  pinMode(LED_RGB_B, OUTPUT);
  Serial.begin(115200);
  delay(1000);
  Serial.println("ENCODERS DIAGNOSTICS  TEENSCIENCE");

}
long posL, posR, posL1, posR1 ;  //Encoder positions 
void loop() {
  posL = myEncL.read();
  posR = myEncR.read();
  if (posL!=posL1){
    Serial.print("LEFT: ");
    Serial.println(posL);
    //translate to an LED color (just to see change)
    digitalWrite(LED_RGB_R, posL&4L);
    digitalWrite(LED_RGB_G, posL&2L);
    digitalWrite(LED_RGB_B, posL&1L);
  }
  else if (posR!=posR1){
    Serial.print("RIGHT: ");
    Serial.println(posR);
    //translate to an LED color (just to see change)
    digitalWrite(LED_RGB_R, posR&4L);
    digitalWrite(LED_RGB_G, posR&2L);
    digitalWrite(LED_RGB_B, posR&1L);
  }
  posL1=posL, posR1=posR;
}
