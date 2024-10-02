#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "Device.h"

class Thermostat : public Device {
private:
    double currentTemperature;
    double targetTemperature;
public:
    Thermostat();
    std::string getStatus() const override;
    void performAction(const std::string &action) override;
    std::string getDeviceType() const override;
};

#endif // THERMOSTAT_H
