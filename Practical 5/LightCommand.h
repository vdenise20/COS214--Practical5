#ifndef LIGHTCOMMAND_H
#define LIGHTCOMMAND_H

#include "Command.h"
#include "Light.h"

class LightCommand : public Command {
private:
    Light* light;
    bool previousState;

public:
    LightCommand(Light* light);
    void execute() override;
};

#endif  // LIGHTCOMMAND_H
