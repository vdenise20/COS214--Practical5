#include <iostream>
#include <vector>
#include "Light.h"
#include "Thermostat.h"
#include "DoorLock.h"
#include "OldThermostat.h"
#include "SmartThermostatIntegrator.h"
#include "TurnOffAllLights.h"
#include "LockAllDoors.h"
#include "MacroRoutine.h"
#include "ThermostatCommand.h"
/*#include "Sensor.h"*/

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
    Device *thermostat = new Thermostat(20);
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

   // 4. Testing the LegacyThermostat class
    std::cout << "Testing LegacyThermostat class:" << std::endl;
    OldThermostat legacyThermo;
    legacyThermo.setTemperature(18.5);
    std::cout << "Legacy thermostat temperature: " << legacyThermo.getTemperature() << std::endl;
    legacyThermo.setTemperature(21.0);
    std::cout << "Legacy thermostat new temperature: " << legacyThermo.getTemperature() << std::endl;
    std::cout << std::endl;

    // 5. Testing the SmartThermostatAdapter class
    std::cout << "Testing SmartThermostatIntegrator class:" << std::endl;
    Device *adapter = new SmartThermostatIntegrator();
    std::cout << "Adapter status: " << adapter->getStatus() << std::endl;
    adapter->performAction("SetTemperature");
    std::cout << "Adapter status after setting temperature: " << adapter->getStatus() << std::endl;
    std::cout << std::endl;

    Device* livingRoomLight = new Light();
    Device* frontDoor = new DoorLock();
    Thermostat* thermostat2 = new Thermostat(20);

    // Initial statuses
    std::cout << "Initial Statuses:" << std::endl;
    std::cout << "Living Room Light: " << livingRoomLight->getStatus() << std::endl;
    std::cout << "Front Door Lock: " << frontDoor->getStatus() << std::endl;
    std::cout << "Thermostat Status: " << thermostat->getStatus() << std::endl;

    std::vector<Device*> lights = {livingRoomLight, light};
    std::vector<Device*> doors = {frontDoor, lock};
    // Create command instances
    Command *turnOffLightsCommand = new TurnOffAllLights(lights);
    Command *lockAllDoorsCommand = new LockAllDoors(doors);
    ThermostatCommand adjustThermostatCommand(thermostat2, 22); // Set target temperature to 22°C

    // Create a macro routine for a "Goodnight" routine
    MacroRoutine *goodnightRoutine = new MacroRoutine();

    // Add commands to the routine
    goodnightRoutine->addProcedure(turnOffLightsCommand);
    goodnightRoutine->addProcedure(lockAllDoorsCommand);
    goodnightRoutine->addProcedure(&adjustThermostatCommand);

    // Execute the routine
    std::cout << "\nExecuting Goodnight routine..." << std::endl;
    goodnightRoutine->execute();

    // Display the status of the devices after executing commands
    std::cout << "\nStatuses after executing Goodnight routine:" << std::endl;
    std::cout << "Living Room Light: " << livingRoomLight->getStatus() << std::endl;
    std::cout << "Kitchen Light: " << light->getStatus() << std::endl;
    std::cout << "Front Door Lock: " << frontDoor->getStatus() << std::endl;
    std::cout << "Back Door Lock: " << lock->getStatus() << std::endl;
    std::cout << "Thermostat Status: " << thermostat2->getStatus() << std::endl;

    // Test Undo Functionality
    std::cout << "\nUndoing last commands..." << std::endl;
    goodnightRoutine->removeProcedure(turnOffLightsCommand); // Undo specific commands
    goodnightRoutine->removeProcedure(lockAllDoorsCommand);
    goodnightRoutine->removeProcedure(&adjustThermostatCommand);
    goodnightRoutine->execute(); // Revert changes if desired

    /*// 7. Testing the Sensor class
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
    delete livingRoomLight;
    delete frontDoor;
    delete thermostat2;
    delete turnOffLightsCommand;
    delete lockAllDoorsCommand;
    delete goodnightRoutine;
    return 0;
}
