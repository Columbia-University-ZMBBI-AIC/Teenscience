///Diagnostic of  General Purpose OUTPUT EXPANSION IC24 in Teenscience Platform REVB, R.Hormigo 2020
// Simple writing GPOs with PWM increasing then decreasing value 

#include <Wire.h> // Include the I2C library (required for SX1509 to control LEDs and switches)
#include <SparkFunSX1509.h> // Need to istall SparkFun SX1509 library

#define GPO1 0
#define GPO2 1 
#define GPO3 2 
#define GPO4 3 
#define RGB_RED 4 
#define RGB_GREEN 5 
#define RGB_BLUE 6
#define LED 7
#define SW_UP 8
#define SW_DW 9
#define SW_SEL 10
#define GPO12 11
#define GPO13 12
#define GPO14 13
#define GPO15 14
#define GPO16 15
// SX1509 I2C address (set by ADDR1 and ADDR0 (00 by default):
const byte SX1509_ADDRESS = 0x3E;  // SX1509 I2C address
SX1509 io; // Create an SX1509 object to be used throughout  


void setup() {
 io.begin(SX1509_ADDRESS);
  
 for (byte n=0;n<16;n++){
  io.pinMode(n, ANALOG_OUTPUT);
  io.analogWrite(n, 0);
 }
 
 Serial.begin(115200);
 delay(100);
 Serial.println("GPO expansion at IC24 DIAGNOSTICS  TEENSCIENCE");

} 

void loop() {
  Serial.println("GPO 16 OUTPUTS: ");
  for (byte n=0;n<16;n++){ //OUTS set active low
    for (int i=0;i<256;i++){
       io.analogWrite(n, i); //Write PWM with increasing duty value
       delay(2);     
    }
    Serial.print("GPO");
    Serial.print(n+1);
    Serial.print(" of 16 ON... ");
    for (int i=256;i;i--){
       io.analogWrite(n, i-1);  //Write PWM with decreasing duty value
       delay(2);     
    }   
    Serial.println(" OFF...");
  }
 delay(500); 
 Serial.println("");
}
