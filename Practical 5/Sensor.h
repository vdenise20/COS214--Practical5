#ifndef SENSOR_H
#define SENSOR_H

#include <vector>
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

    void notify() {
        for (Device* observer : observers) {
            observer->update(this);
        }
    }
};

#endif  // SENSOR_H
