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
