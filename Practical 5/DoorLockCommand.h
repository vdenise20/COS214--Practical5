#ifndef DOORLOCKCOMMAND_H
#define DOORLOCKCOMMAND_H

#include "Command.h"
#include "DoorLock.h"

class DoorLockCommand : public Command {
private:
    Device* doorLock;
    bool previousState;

public:
    DoorLockCommand(Device* lock);
    void execute() override;
};

#endif  // DOORLOCKCOMMAND_H
