#include "Curtains.h";
#include <Stepper_Motor.h>

Curtains::Curtains(
    byte enable_pin,
    byte direction_pin,
    byte step_pin,
    int length
) : Stepper_Motor(
    enable_pin,
    direction_pin,
    step_pin
) {
    _length = length;
}

Curtains::Curtains(
    byte enable_pin,
    byte direction_pin,
    byte step_pin,
    byte sleep_pin,
    byte reset_pin,
    byte ms1_pin,
    byte ms2_pin,
    byte ms3_pin,
    int length
) : Stepper_Motor(
    enable_pin,
    direction_pin,
    step_pin,
    sleep_pin,
    reset_pin,
    ms1_pin,
    ms2_pin,
    ms3_pin
) {
    _length = length;
}

void Curtains::setButtonAndLimitSwitch(
    byte buttons_pin,
    int button_clockwise_threshold,
    int button_anti_clockwise_threshold
) {
    _pin_buttons = buttons_pin;
    _button_clockwise_threshold = button_clockwise_threshold;
    _button_anti_clockwise_threshold = button_anti_clockwise_threshold;

    pinMode(_pin_buttons, INPUT);
}
void Curtains::setButtonAndLimitSwitch(
    byte buttons_pin,
    int button_clockwise_threshold,
    int button_anti_clockwise_threshold,
    byte limit_switch_pin
) {
    _pin_buttons = buttons_pin;
    _button_clockwise_threshold = button_clockwise_threshold;
    _button_anti_clockwise_threshold = button_anti_clockwise_threshold;
    _pin_limit_switch = limit_switch_pin;

    pinMode(_pin_buttons, INPUT);
    pinMode(_pin_limit_switch, INPUT);
}

void Curtains::_readButtonInputs() {
    int buttonValue = analogRead(_pin_buttons);
    if (buttonValue > _button_clockwise_threshold) {
        _pressedButton = BUTTON_CLOCKWISE;
    } else if (buttonValue > _button_anti_clockwise_threshold) {
        _pressedButton = BUTTON_ANTI_CLOCKWISE;
    } else {
        _pressedButton = NONE;
    }

    _isLimitSwitchPressed = digitalRead(_pin_limit_switch);
}

void Curtains::open() {
    // set direction, enabling, and disabling once
    antiClockwise();
    enable();
    takeSteps();
    disable();
}

void Curtains::open(int percentage) {
    antiClockwise();
    enable();
    takeSteps(percentage);
    disable();
}

void Curtains::close() {
    // set direction, enabling, and disabling once
    clockwise();
    enable();
    takeSteps();
    disable();
}

void Curtains::close(int percentage) {
    clockwise();
    enable();
    takeSteps(percentage);
    disable();
}
