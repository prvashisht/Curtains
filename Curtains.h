#ifndef Curtains_h
#define Curtains_h

#include "Arduino.h"
#include <Stepper_Motor.h>

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
    void setButtonAndLimitSwitch(
      byte buttons_pin,
      int button_clockwise_threshold,
      int button_anti_clockwise_threshold
    );
    void setButtonAndLimitSwitch(
      byte buttons_pin,
      int button_clockwise_threshold,
      int button_anti_clockwise_threshold,
      byte limit_switch_pin
    );
    void open();
    void open(int percentage);
    void close();
    void close(int percentage);
    void handleButtonInputs();
  private:
    static const int DEFAULT_LENGTH = 200 * 44;
    byte _pin_buttons;
    byte _pin_limit_switch;
    int _button_clockwise_threshold;
    int _button_anti_clockwise_threshold;
    int _length; // in rotations;
    int _position_opened;
    int _position_closed;
    int _position_current;
    bool _isLimitSwitchPressed = false;
    enum _inputButtons { NONE, BUTTON_CLOCKWISE, BUTTON_ANTI_CLOCKWISE };
    _inputButtons _pressedButton = NONE;
    void _readButtonInputs();
};

#endif