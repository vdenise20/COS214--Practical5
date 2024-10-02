#include "Thermostat.h"

Thermostat::Thermostat() : currentTemperature(20.0) {}

std::string Thermostat::getStatus() const {
    return "Temperature: " + std::to_string(currentTemperature);
}

void Thermostat::performAction(const std::string &action) {
    if (action == "SetTemperature") {
        currentTemperature++;  // Example temperature adjustment
    }
}

std::string Thermostat::getDeviceType() const {
    return "Thermostat";
}
