#include "DoorLockSensor.h"

void DoorLockSensor::unlock() {
    isUnlocked = true; // Set door to unlocked
    notify(); // Notify all registered devices
}
