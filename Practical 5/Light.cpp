#include "Light.h"

Light::Light() : isOn(false) {}

std::string Light::getStatus() const {
    return isOn ? "on" : "off";
}

void Light::performAction(const std::string &action) {
    if (action == "ToggleOn") isOn = true;
    else if (action == "ToggleOff") isOn = false;
}

std::string Light::getDeviceType() const {
    return "Light";
}
