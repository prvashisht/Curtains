#ifndef Curtains_h
#define Curtains_h

#include "Arduino.h"
#include <Stepper_Motor.h>
#define DEFAULT_LENGTH 200 * 44

class Curtains: public Stepper_Motor {
  public:
    Curtains(
        byte enable_pin,
        byte dir_pin,
        byte step_pin,
        int length = DEFAULT_LENGTH
    );
    Curtains(
        byte enable_pin,
        byte dir_pin,
        byte step_pin,
        byte sleep_pin,
        byte reset_pin,
        byte ms1_pin,
        byte ms2_pin,
        byte ms3_pin,
        int length = DEFAULT_LENGTH
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