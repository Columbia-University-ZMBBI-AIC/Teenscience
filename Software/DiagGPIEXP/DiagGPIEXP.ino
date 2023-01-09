///Diagnostic of  General Purpose INPUT EXPANDER IC24 in Teenscience Platform REVB, R.Hormigo 2020
// Simple  reading GPIs for expaner IC 24

#include <Wire.h> // Include the I2C library (required for SX1509 to control LEDs and switches)
#include <SparkFunSX1509.h> // Need to istall SparkFun SX1509 library

#define GPI1 0
#define GPI2 1 
#define GPI3 2 
#define GPI4 3 
#define RGB_RED 4 
#define RGB_GREEN 5 
#define RGB_BLUE 6
#define LED 7
#define SW_UP 8
#define SW_DW 9
#define SW_SEL 10
#define GPI12 11
#define GPI13 12
#define GPI14 13
#define GPI15 14
#define GPI16 15
// SX1509 I2C address (set by ADDR1 and ADDR0 (00 by default):
const byte SX1509_ADDRESS = 0x3E;  // SX1509 I2C address
SX1509 io; // Create an SX1509 object to be used throughout  


void setup() {
 io.begin(SX1509_ADDRESS);
  
 for (byte n=0;n<16;n++){
  io.pinMode(n, INPUT_PULLUP);
 }
 Serial.begin(115200);
 delay(100);
 Serial.println("GPI expansion at IC24 DIAGNOSTICS  TEENSCIENCE");
} 

void loop() {
  Serial.println("GPI 16 INPUTS: ");
  for (byte n=0;n<16;n++){ //GENERAL PURPOSE INPUTS
    Serial.print("GPI");
    Serial.print(n+1);
    Serial.print(" of 16: ");
    Serial.println(io.digitalRead(n));   //Show value in INPUT 
  }
 delay(500); 
 Serial.println("");
}
