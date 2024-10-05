#include "OldThermostat.h"

double OldThermostat::getTemperature() const {
    return temperature;
}

void OldThermostat::setTemperature(double temp) {
    temperature = temp;
}
