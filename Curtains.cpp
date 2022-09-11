#include "Curtains.h";
#include <Stepper_Motor.h>

Curtains::Curtains(
    int enable_pin,
    int direction_pin,
    int step_pin,
    int length
) : Stepper_Motor(
    enable_pin,
    direction_pin,
    step_pin
) {
    _length = length;
}

Curtains::Curtains(
    int enable_pin,
    int direction_pin,
    int step_pin,
    int sleep_pin,
    int reset_pin,
    int ms1_pin,
    int ms2_pin,
    int ms3_pin,
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
