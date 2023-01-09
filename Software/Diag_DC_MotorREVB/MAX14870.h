#pragma once

#include <Arduino.h>

class MAX14870
{
  public:
    MAX14870();
    MAX14870(uint8_t DIR,
              uint8_t PWM,
			        uint16_t CURRENT,
              uint8_t nEN,
              uint8_t nFAULT);

    void setSpeed(int8_t speed);
    void flip(bool flip);
    bool getFault();
    void enableDriver();
    void disableDriver();
    uint16_t getCurrent();
    

  private:
    void initPins();

    uint8_t _DIR;
    uint8_t _PWM;
    uint16_t _CURRENT;
    uint8_t _nEN;
    uint8_t _nFAULT;

    bool _flip = false;

    bool initialized = false;

    inline void init()
    {
      if (!initialized)
      {
        initialized = true;
        initPins();
      }
    }
};
