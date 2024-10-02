#ifndef DOORLOCK_H
#define DOORLOCK_H

#include "Device.h"

class DoorLock : public Device {
private:
    bool isLocked;
public:
    DoorLock();
    std::string getStatus() const override;
    void performAction(const std::string &action) override;
    std::string getDeviceType() const override;
};

#endif // DOORLOCK_H
