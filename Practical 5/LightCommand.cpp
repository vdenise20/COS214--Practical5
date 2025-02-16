#include "LightCommand.h"

LightCommand::LightCommand(Device* light) : light(light), previousState(light->getStatus() == "on") {}

void LightCommand::execute() {
    previousState = light->getStatus() == "on";
    if(previousState){
        light->performAction("ToggleOff");
    } else {
        light->performAction("ToggleOn");
    }
}