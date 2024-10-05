#ifndef MACROROUTINE_H
#define MACROROUTINE_H

#include <vector>
#include "Device.h"
#include "Command.h"

class MacroRoutine : public Command {
private:
    std::vector<Command*> procedures;
public:
    MacroRoutine();
    void execute() override;
    void addProcedures(Command* procedure);
    void removeProcedures(Command* procedure);
};
#endif //MACROROUTINE_H

