#include "ThermostatCommand.h"

ThermostatCommand::ThermostatCommand(Thermostat* thermo, int temp) : thermostat(thermo), previousTemp(thermo->getTemperature()), newTemp(temp) {}

void ThermostatCommand::execute() {
    previousTemp = thermostat->getTemperature();
    thermostat->performAction("SetTemperature");
}