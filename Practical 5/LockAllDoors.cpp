#include "LockAllDoors.h"

LockAllDoors::LockAllDoors(std::vector<Device*> &doors) : doors(doors) {}

void LockAllDoors::execute() {
    for (auto door : doors) {
        if (door->getDeviceType() == "DoorLock") {
            door->performAction("Lock");
        }
    }
}
