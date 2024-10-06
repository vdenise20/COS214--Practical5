#include "TemperatureSensor.h"

void TemperatureSensor::checkTemp(float newTemp) {
    currentTemp = newTemp;
    if (currentTemp >= thresholdTemp) {
        notify(); // Notify devices if the temperature exceeds the threshold
    }
}