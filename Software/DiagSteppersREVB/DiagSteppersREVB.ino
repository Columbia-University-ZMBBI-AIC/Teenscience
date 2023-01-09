//Diagnostic of Steppers in Teenscience Platform REVA, R.Hormigo 2019
//Supports DRV8825s in board 

#include <AccelStepper.h>

// The X Stepper pins
#define STEPPER1_DIR_PIN 49
#define STEPPER1_STEP_PIN 50


// The Y stepper pins
#define STEPPER2_DIR_PIN 45
#define STEPPER2_STEP_PIN 46

#define RST 43
#define MODE0 51
#define MODE1 52
#define MODE2 53

// Define some steppers and the pins the will use
AccelStepper stepper1(AccelStepper::DRIVER, STEPPER1_STEP_PIN, STEPPER1_DIR_PIN);
AccelStepper stepper2(AccelStepper::DRIVER, STEPPER2_STEP_PIN, STEPPER2_DIR_PIN);

void setup()
{  
   pinMode(MODE0, OUTPUT); 
   pinMode(MODE1, OUTPUT); 
   pinMode(MODE2, OUTPUT);
   pinMode(RST, OUTPUT); 
   digitalWrite(RST,HIGH);
   digitalWrite(MODE1,HIGH);  //1/4 step
    
    stepper1.setMaxSpeed(500.0);
    stepper1.setAcceleration(200.0);
    stepper1.moveTo(1000);
    
    stepper2.setMaxSpeed(2000.0);
    stepper2.setAcceleration(800.0);
    stepper2.moveTo(1000);
}

void loop()
{
    // Change direction at the limits
    if (stepper1.distanceToGo() == 0)
      stepper1.moveTo(-stepper1.currentPosition());
    if (stepper2.distanceToGo() == 0)
      stepper2.moveTo(-stepper2.currentPosition());
    stepper1.run();
    stepper2.run();
}
