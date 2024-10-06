#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "Device.h"

class Thermostat : public Device {
private:
    double currentTemperature;
public:
    Thermostat(double temperature);
    double getTemperature() const;
    std::string getStatus() const override;
    void performAction(const std::string &action) override;
    std::string getDeviceType() const override;
    void update(Sensor* sensor) override;
};

#endif // THERMOSTAT_H
