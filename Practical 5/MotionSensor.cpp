#include "MotionSensor.h"

void MotionSensor::detectMotion() {
    motionDetected = true; // Set motion detected to true
    notify(); // Notify all registered devices of motion event
}

