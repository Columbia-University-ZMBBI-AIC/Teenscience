#include "MAX14870.h"
//This Library is a fork to support standalone MAX14870 Drivers in TennScience Platform with fast writing
//Also rupport current reading from Analog pin
//R.Hormigo 2019


// Constructors 
MAX14870::MAX14870() :
  _DIR(7), _PWM(5),_CURRENT(A14), _nEN(24), _nFAULT(26) 
{
  init(); // initialize once
}
MAX14870::MAX14870(uint8_t DIR,
                   uint8_t PWM,
				   uint16_t CURRENT,
                   uint8_t nEN,
                   uint8_t nFAULT) :
  _DIR(DIR), _PWM(PWM), _CURRENT(CURRENT), _nEN(nEN), _nFAULT(nFAULT)
{
  init(); // initialize once
}


void MAX14870::initPins()
{
  pinMode(_PWM, OUTPUT);
  digitalWrite(_PWM, LOW);
  pinMode(_DIR, OUTPUT);
  digitalWrite(_DIR, LOW);
  pinMode(_nEN, OUTPUT);
  digitalWrite(_nEN, HIGH); // default to off
  pinMode(_nFAULT, INPUT_PULLUP);

}

// speed should be a number between -127 to 127   
void MAX14870::setSpeed(int8_t speed)
{

  boolean reverse = 0;
  //Serial.println(speed);
  if (speed < 0)
  {
    speed = -speed; // make speed a positive quantity
    reverse = 1;    // preserve the direction
  }
 
  if (speed > 127)  // max
    speed = 127;
	
  analogWrite(_PWM, speed); 

//Serial.print(speed );
  if (reverse ^ _flip) // flip if speed was negative or _flipM1 setting is active, but not both
  {  digitalWrite(_DIR, HIGH);
//	Serial.println(" +" );
  }
  else
  { digitalWrite(_DIR, LOW);
//	Serial.println(" -" );
  }
}

uint16_t MAX14870::getCurrent(){
  return analogRead(_CURRENT);
}


void MAX14870::flip(bool flip)
{
  _flip = flip;
}


bool MAX14870::getFault()
{
  return !digitalRead(_nFAULT);
}

void MAX14870::enableDriver()
{
  digitalWrite(_nEN, LOW);
}

void MAX14870::disableDriver()
{
  digitalWrite(_nEN, HIGH);
}
