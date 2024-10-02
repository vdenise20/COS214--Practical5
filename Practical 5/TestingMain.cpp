#include <iostream>
#include <vector>
#include "Light.h"
#include "Thermostat.h"
#include "DoorLock.h"
/*#include "LegacyThermostat.h"
#include "SmartThermostatAdapter.h"
#include "TurnOffAllLights.h"
#include "Sensor.h"*/

int main() {
    // 1. Testing the Light class
    std::cout << "Testing Light class:" << std::endl;
    Device *light = new Light();
    std::cout << "Initial status: " << light->getStatus() << std::endl;
    light->performAction("ToggleOn");
    std::cout << "After ToggleOn: " << light->getStatus() << std::endl;
    light->performAction("ToggleOff");
    std::cout << "After ToggleOff: " << light->getStatus() << std::endl;
    std::cout << std::endl;

    // 2. Testing the Thermostat class
    std::cout << "Testing Thermostat class:" << std::endl;
    Device *thermostat = new Thermostat();
    std::cout << "Initial status: " << thermostat->getStatus() << std::endl;
    thermostat->performAction("SetTemperature");
    std::cout << "After setting temperature: " << thermostat->getStatus() << std::endl;
    std::cout << std::endl;

    // 3. Testing the DoorLock class
    std::cout << "Testing DoorLock class:" << std::endl;
    Device *lock = new DoorLock;
    std::cout << "Initial status: " << lock->getStatus() << std::endl;
    lock->performAction("Lock");
    std::cout << "After Lock: " << lock->getStatus() << std::endl;
    lock->performAction("Unlock");
    std::cout << "After Unlock: " << lock->getStatus() << std::endl;
    std::cout << std::endl;

    /*// 4. Testing the LegacyThermostat class
    std::cout << "Testing LegacyThermostat class:" << std::endl;
    LegacyThermostat legacyThermo;
    legacyThermo.setTemperature(18.5);
    std::cout << "Legacy thermostat temperature: " << legacyThermo.getTemperature() << std::endl;
    legacyThermo.setTemperature(21.0);
    std::cout << "Legacy thermostat new temperature: " << legacyThermo.getTemperature() << std::endl;
    std::cout << std::endl;

    // 5. Testing the SmartThermostatAdapter class
    std::cout << "Testing SmartThermostatAdapter class:" << std::endl;
    SmartThermostatAdapter adapter(&legacyThermo);
    std::cout << "Adapter status: " << adapter.getStatus() << std::endl;
    adapter.performAction("SetTemperature");
    std::cout << "Adapter status after setting temperature: " << adapter.getStatus() << std::endl;
    std::cout << std::endl;

    // 6. Testing the TurnOffAllLights command
    std::cout << "Testing TurnOffAllLights command:" << std::endl;
    Light light1, light2;
    light1.performAction("ToggleOn");
    light2.performAction("ToggleOn");
    std::cout << "Light1 status: " << light1.getStatus() << std::endl;
    std::cout << "Light2 status: " << light2.getStatus() << std::endl;

    std::vector<SmartDevice*> devices = {&light1, &light2};
    TurnOffAllLights turnOffCommand(devices);
    turnOffCommand.execute();
    
    std::cout << "Light1 status after TurnOffAll: " << light1.getStatus() << std::endl;
    std::cout << "Light2 status after TurnOffAll: " << light2.getStatus() << std::endl;
    std::cout << std::endl;

    // 7. Testing the Sensor class
    std::cout << "Testing Sensor class:" << std::endl;
    Sensor motionSensor;
    motionSensor.addDevice(&light1);
    motionSensor.addDevice(&lock);
    std::cout << "Light1 initial status: " << light1.getStatus() << std::endl;
    std::cout << "DoorLock initial status: " << lock.getStatus() << std::endl;

    motionSensor.notifyDevices();
    std::cout << "Light1 status after notify: " << light1.getStatus() << std::endl;  // Lights should turn on
    std::cout << "DoorLock status after notify: " << lock.getStatus() << std::endl;  // Door remains unlocked
    std::cout << std::endl;*/

    delete light;
    delete thermostat;
    delete lock;
    return 0;
}
