#ifndef THERMOSTATCOMMAND_H
#define THERMOSTATCOMMAND_H

#include "Command.h"
#include "Thermostat.h"

class ThermostatCommand : public Command {
private:
    Thermostat* thermostat;
    int previousTemp;
    int newTemp;

public:
    ThermostatCommand(Thermostat* thermo, int temp);
    void execute() override;
    
};

#endif  // THERMOSTATCOMMAND_H
