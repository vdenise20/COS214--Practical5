#ifndef SMARTTHERMOSTATINTEGRATOR_H
#define SMARTTHERMOSTATINTEGRATOR_H

#include "Device.h"
#include "OldThermostat.h"

class SmartThermostatIntegrator : public Device, public OldThermostat {
public:
    SmartThermostatIntegrator() {}
    std::string getStatus() const override;
    void performAction(const std::string &action) override;
    std::string getDeviceType() const override;
};

#endif // SMARTTHERMOSTATINTEGRATOR_H
