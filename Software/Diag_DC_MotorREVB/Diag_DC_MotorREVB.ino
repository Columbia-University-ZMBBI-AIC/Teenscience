//Diagnostic of DC Motors in Teenscience Platform REVA, R.Hormigo 2019
//Control Speed and direction For 1 motor
//Use UP/DW buttons, then SEL to control L or R


#include "MAX14870.h"  
#include <Wire.h> // Include the I2C library (required for SX1509 to control LEDs and switches)
#include <SparkFunSX1509.h> // Need to istall SparkFun SX1509 library

#define SEL_RD 10
#define DW_RD 9
#define UP_RD 8
#define LED_RGB_R 4

// SX1509 I2C address (set by ADDR1 and ADDR0 (00 by default):
const byte SX1509_ADDRESS = 0x3E;  // SX1509 I2C address
SX1509 io; // Create an SX1509 object to be used throughout

MAX14870 motorL;  // Left Motor TeenScience uses default pins 
MAX14870 motorR(8,6,A15,25,27); //TeenScience Pins for Right Motor 


void setup() {
  analogWriteResolution(7);  //Resolution of 7 to control speed in motors
  analogWriteFrequency(9, 20000); // Also Change PWM frq @ pins 5 y 6 for motors, along with 9, 10, 20, 21, 22, and 23
  io.begin(SX1509_ADDRESS);
  io.pinMode(LED_RGB_R, OUTPUT);
  io.pinMode(SEL_RD, INPUT_PULLUP);
  io.pinMode(DW_RD, INPUT_PULLUP);
  io.pinMode(UP_RD, INPUT_PULLUP);
  
  Serial.begin(115200);
  delay(100);
  Serial.println("DC Motor DIAGNOSTICS  TEENSCIENCE");
  motorL.enableDriver();
  motorR.enableDriver();
  
} 

enum {MOTOR_L, MOTOR_R};
bool selMotor = MOTOR_L;
signed char speedL, speedR;
char count;
void loop() {
  
  if (!io.digitalRead(UP_RD)){
     if (speedL<126 && selMotor==MOTOR_L){
      speedL++;
      Serial.print("SPEED L: "); 
      Serial.println(speedL);
     }
     else if (speedR<126 && selMotor==MOTOR_R){
      speedR++;
      Serial.print("SPEED R: "); 
      Serial.println(speedR);   
     }
    delay(200);
  }
  else if (!io.digitalRead(DW_RD)){
     if (speedL>-126 && selMotor==MOTOR_L){
      speedL--;
      Serial.print("SPEED L: "); 
      Serial.println(speedL);
     }
     else if (speedR>-126 && selMotor==MOTOR_R){
      speedR--;
      Serial.print("SPEED R: "); 
      Serial.println(speedR);
     }
    delay(200);
  }
  else if (!io.digitalRead(SEL_RD)){
    selMotor = !selMotor; //
    Serial.print("SELECTED ");
    if (selMotor==MOTOR_R)  Serial.println("RIGHT");
    else Serial.println("LEFT");
    delay(300);
  }
  motorL.setSpeed(speedL);
  motorR.setSpeed(speedR);
  delay(1);
  if(! count++){ //Every 256 counts (2.5 sec)
      Serial.print(" CURRENTS: "); 
      Serial.print(motorL.getCurrent());
      Serial.print(" "); 
      Serial.println(motorR.getCurrent());
  }
  stopIfFault();
}

void stopIfFault()
{
  if (motorL.getFault() || motorR.getFault() )
  {
    motorL.disableDriver();
    motorR.disableDriver();
    while (1)
    {
      io.digitalWrite(LED_RGB_R, LOW);
      delay(500);
      io.digitalWrite(LED_RGB_R, HIGH);
      delay(500);
      Serial.println(" HARDWARE FAILIURE! "); 
    }
  }
}
