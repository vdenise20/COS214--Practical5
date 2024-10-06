#ifndef REMOTECONTROL_H
#define REMOTECONTROL_H

#include "Command.h"
#include "string"

class RemoteControl {
private:
    Command* slot;
    std::string deviceType;

public:
    void setCommand(Command* cmd) {
        slot = cmd;
    }

    void pressButton() {
        slot->execute();
    }
};

#endif //REMOTECONTROL_H