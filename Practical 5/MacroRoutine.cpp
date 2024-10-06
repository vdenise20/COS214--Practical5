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
void MacroRoutine::addProcedure(Command* procedure) {
    procedures.push_back(procedure);
}
void MacroRoutine::removeProcedure(Command* procedure) {
    procedures.erase(std::remove(procedures.begin(), procedures.end(), procedure), procedures.end());
}