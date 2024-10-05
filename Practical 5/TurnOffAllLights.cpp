#include "TurnOffAllLights.h"

TurnOffAllLights::TurnOffAllLights(std::vector<Device*> &lights) : lights(lights) {}

void TurnOffAllLights::execute() {
    for (auto light : lights) {
        if (light->getDeviceType() == "Light") {
            light->performAction("ToggleOff");
        }
    }
}
