#ifndef LIGHTCOMMAND_H
#define LIGHTCOMMAND_H

#include "Command.h"
#include "Light.h"

class LightCommand : public Command {
private:
    Device* light;
    bool previousState;

public:
    LightCommand(Device* light);
    void execute() override;
};

#endif  // LIGHTCOMMAND_H
