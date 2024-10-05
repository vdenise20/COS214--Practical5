#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H

#include "Sensor.h"

class MotionSensor : public Sensor {
private:
    bool motionDetected;

public:
    MotionSensor() : motionDetected(false) {}

    void detectMotion() { 
        motionDetected = true; 
        notify();
    }

    bool getMotionStatus() const { return motionDetected; }
};

#endif  // MOTIONSENSOR_H
