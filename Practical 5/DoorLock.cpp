#include "DoorLock.h"

DoorLock::DoorLock() : isLocked(false) {}

std::string DoorLock::getStatus() const {
    return isLocked ? "locked" : "unlocked";
}

void DoorLock::performAction(const std::string &action) {
    if (action == "Lock") isLocked = true;
    else if (action == "Unlock") isLocked = false;
}

std::string DoorLock::getDeviceType() const {
    return "DoorLock";
}
