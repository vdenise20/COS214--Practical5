#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include "Sensor.h"

class TemperatureSensor : public Sensor {
private:
    float currentTemp;
    float thresholdTemp;

public:
    TemperatureSensor(float threshold) : currentTemp(0), thresholdTemp(threshold) {}

    void checkTemp(float newTemp); // Check if temperature crosses the threshold
};

#endif // TEMPERATURESENSOR_H
