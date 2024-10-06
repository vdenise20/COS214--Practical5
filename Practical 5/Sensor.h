#ifndef SENSOR_H
#define SENSOR_H

#include <vector>
#include <algorithm>
#include "Device.h"

class Sensor {
private:
    std::vector<Device*> observers;

public:
    void attach(Device* observer) {
        observers.push_back(observer);
    }

    void detach(Device* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    virtual void notify() {
        for (Device* observer : observers) {
            observer->update(this);
        }
    }

    virtual void detectMotion() {}
    virtual void unlock() {}
    virtual void checkTemp(float newTemp){}
};

#endif  // SENSOR_H
