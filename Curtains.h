#ifndef Curtains_h
#define Curtains_h

#include "Arduino.h"
#include <Stepper_Motor.h>

class Curtains: public Stepper_Motor {
  public:
    Curtains(
        int enable_pin,
        int dir_pin,
        int step_pin,
        int length
    );
    Curtains(
        int enable_pin,
        int dir_pin,
        int step_pin,
        int sleep_pin,
        int reset_pin,
        int ms1_pin,
        int ms2_pin,
        int ms3_pin,
        int length
    );
    void open();
    void open(int percentage);
    void close();
    void close(int percentage);
  private:
    int _length; // in rotations;
    int _position_opened;
    int _position_closed;
    int _position_current;
};

#endif