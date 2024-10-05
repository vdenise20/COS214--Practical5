#include "Thermostat.h"

Thermostat::Thermostat(double temperature) : currentTemperature(temperature) {}

std::string Thermostat::getStatus() const {
    return "Temperature: " + std::to_string(currentTemperature);
}

void Thermostat::performAction(const std::string &action) {
    if (action == "SetTemperature") {
        currentTemperature++;  // Example temperature adjustment
    }
}

double Thermostat::getTemperature() const {
    return currentTemperature;
}

std::string Thermostat::getDeviceType() const {
    return "Thermostat";
}
