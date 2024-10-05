#ifndef TURNOFFALLLIGHTS_H
#define TURNOFFALLLIGHTS_H

#include <vector>
#include "Device.h"
#include "Command.h"

class TurnOffAllLights : public Command {
private:
    std::vector<Device*> &lights;
public:
    TurnOffAllLights(std::vector<Device*> &lights);
    void execute() override;
};

#endif // TURNOFFALLLIGHTS_H
