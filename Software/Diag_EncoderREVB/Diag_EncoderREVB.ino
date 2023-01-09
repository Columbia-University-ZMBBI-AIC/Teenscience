//Diagnostic of encoder function in Teenscience Platform REVA, R.Hormigo 2019
//YOu neeed the Encoder library already in Teensyduino and initiate an object Encoder  with the pins used in Teenscience 3, 4, 29, and 30). 
//To find a position just assign the function read of the class Encoder to a long variable


#include <Wire.h> // Include the I2C library (required for SX1509 to control LEDs)
#include <SparkFunSX1509.h> // Need to istall SparkFun SX1509 library

#include <Encoder.h>

// SX1509 I2C address (set by ADDR1 and ADDR0 (00 by default):
const byte SX1509_ADDRESS = 0x3E;  // SX1509 I2C address
SX1509 io; // Create an SX1509 object to be used throughout

#define LED_RGB_R 4
#define LED_RGB_G 5
#define LED_RGB_B 6
#define LED_GR 7

Encoder myEncL(3, 4); //Encoder Left pins (With IRQ for performance)
Encoder myEncR(29, 30); //Encoder Right pins (With IRQ for performance)

void setup() {
  io.begin(SX1509_ADDRESS);
  io.pinMode(LED_RGB_R, OUTPUT);
  io.pinMode(LED_RGB_G, OUTPUT);
  io.pinMode(LED_RGB_B, OUTPUT);
  io.pinMode(LED_GR, OUTPUT);

  Serial.begin(115200);
  delay(1000);
  Serial.println("ENCODERS DIAGNOSTICS  TEENSCIENCE");
  io.digitalWrite(LED_GR, 0); //Turn on main led
}
long posL, posR, posL1, posR1 ;  //Encoder positions 
void loop() {
  posL = myEncL.read();
  posR = myEncR.read();
  if (posL!=posL1){
    Serial.print("LEFT: ");
    Serial.println(posL);
    //translate to an LED color (just to see change)
    io.digitalWrite(LED_RGB_R, posL&4L);
    io.digitalWrite(LED_RGB_G, posL&2L);
    io.digitalWrite(LED_RGB_B, posL&1L);
  }
  else if (posR!=posR1){
    Serial.print("RIGHT: ");
    Serial.println(posR);
    //translate to an LED color (just to see change)
    io.digitalWrite(LED_RGB_R, posR&4L);
    io.digitalWrite(LED_RGB_G, posR&2L);
    io.digitalWrite(LED_RGB_B, posR&1L);
  }
  posL1=posL, posR1=posR;
}
