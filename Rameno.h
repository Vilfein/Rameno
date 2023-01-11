#ifndef _RAMENO_H_
#define _RAMENO_H_

#if(ARDUINO>=100)
#include "Arduino.h"
#else
#include "Wprogram.h"
#endif

class Rameno {
  private:
    int dirPin; // = 3;
    int stepPin;// = 4;
    int enPin;  // = 2;

  public:
    Rameno(int dirPin, int stepPin, int enPin);
    void RunL(int pause, int pulses);
    void RunR(int pause, int pulses);

    void RunL2(int pause, int pulses, Rameno &R2);
    void RunR2(int pause, int pulses, Rameno &R2);


    void RunL3(int pause, int pulses, Rameno &R2, Rameno &R3);
    void RunR3(int pause, int pulses, Rameno &R2, Rameno &R3);

    byte getDirPin();
    void setDirPin(byte newPin);

    byte getStepPin();
    void setStepPin(byte newPin);

    byte getEnPin();
    void setEnPin(byte newPin);
};

#endif
