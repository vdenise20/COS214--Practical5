#include "SmartThermostatIntegrator.h"

std::string SmartThermostatIntegrator::getStatus() const {
    return "Temperature: " + std::to_string(getTemperature());
}

void SmartThermostatIntegrator::performAction(const std::string &action) {
    if (action == "SetTemperature") {
        setTemperature(22.0);  // Example action
    }
}

std::string SmartThermostatIntegrator::getDeviceType() const {
    return "Thermostat";
}
