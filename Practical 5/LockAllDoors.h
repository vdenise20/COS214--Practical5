#ifndef LOCKALLDOORS_H
#define LOCKALLDOORS_H

#include <vector>
#include "Device.h"
#include "Command.h"

class LockAllDoors : public Command {
private:
    std::vector<Device*> &doors;
public:
    LockAllDoors(std::vector<Device*> &doors);
    void execute() override;
};

#endif // TURNOFFALLLIGHTS_H
