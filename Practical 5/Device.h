#ifndef DEVICE_H
#define DEVICE_H
#include <iostream>

class Sensor;

using namespace std;
class Device {
public:
    virtual ~Device() = default;
    virtual std::string getStatus() const = 0;
    virtual void performAction(const std::string &action) = 0;
    virtual std::string getDeviceType() const = 0;
    //virtual void update(Sensor* sensor) = 0;
};
#endif /*DEVICE_H*/