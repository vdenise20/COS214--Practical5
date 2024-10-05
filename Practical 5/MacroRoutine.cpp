#include "MacroRoutine.h"
#include <vector>
#include <algorithm>

MacroRoutine::MacroRoutine() {

}
void MacroRoutine::execute() {
    for(auto& procedure : procedures){
        procedure->execute();
    }
}
void MacroRoutine::addProcedures(Command* procedure) {
    procedures.push_back(procedure);
}
void MacroRoutine::removeProcedures(Command* procedure) {
    procedures.erase(std::remove(procedures.begin(), procedures.end(), procedure), procedures.end());
}