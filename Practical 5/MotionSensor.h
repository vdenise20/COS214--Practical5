#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H

#include "Sensor.h"

class MotionSensor : public Sensor {
private:
    bool motionDetected;

public:
    MotionSensor() : motionDetected(false) {}

    void detectMotion() override; // Detect motion and notify devices
};

#endif // MOTIONSENSOR_H
