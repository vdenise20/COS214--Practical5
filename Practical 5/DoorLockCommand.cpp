#include "DoorLockCommand.h"

DoorLockCommand::DoorLockCommand(DoorLock* lock) : doorLock(lock), previousState(lock->getStatus() == "locked") {}

void DoorLockCommand::execute() {
    if (previousState) {
        doorLock->performAction("Unlock");
    } else {
        doorLock->performAction("Lock");
    }
}