#ifndef DOORLOCKCOMMAND_H
#define DOORLOCKCOMMAND_H

#include "Command.h"
#include "DoorLock.h"

class DoorLockCommand : public Command {
private:
    DoorLock* doorLock;
    bool previousState;

public:
    DoorLockCommand(DoorLock* lock);
    void execute() override;
};

#endif  // DOORLOCKCOMMAND_H
