#ifndef LIGHT_H
#define LIGHT_H

#include "Device.h"

class Light : public Device {
private:
    bool isOn;
public:
    Light();
    std::string getStatus() const override;
    void performAction(const std::string &action) override;
    std::string getDeviceType() const override;
    void update(Sensor* sensor) override;
};

#endif // LIGHT_H
