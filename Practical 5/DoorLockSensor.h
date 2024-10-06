#ifndef DOORLOCKSENSOR_H
#define DOORLOCKSENSOR_H

#include "Sensor.h"

class DoorLockSensor : public Sensor {
private:
    bool isUnlocked;

public:
    DoorLockSensor() : isUnlocked(false) {}

    void unlock(); // Unlock and notify devices
};

#endif // DOORLOCKSENSOR_H
