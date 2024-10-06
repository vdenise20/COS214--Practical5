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
#include "RemoteControl.h"
#include "MotionSensor.h"
#include "DoorLockSensor.h"
#include "TemperatureSensor.h"

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
    
    RemoteControl remote;

    remote.setCommand(goodnightRoutine);
    remote.pressButton();

    // Display the status of the devices after executing commands
    std::cout << "\nStatuses after executing Goodnight routine:" << std::endl;
    std::cout << "Living Room Light: " << livingRoomLight->getStatus() << std::endl;
    std::cout << "Kitchen Light: " << light->getStatus() << std::endl;
    std::cout << "Front Door Lock: " << frontDoor->getStatus() << std::endl;
    std::cout << "Back Door Lock: " << lock->getStatus() << std::endl;
    std::cout << "Thermostat Status: " << thermostat2->getStatus() << std::endl;

    // Test Undo Functionality
    std::cout << "\nRemoving procedures..." << std::endl;
    goodnightRoutine->removeProcedure(turnOffLightsCommand); // Undo specific commands
    goodnightRoutine->removeProcedure(lockAllDoorsCommand);
    goodnightRoutine->removeProcedure(&adjustThermostatCommand);
    goodnightRoutine->execute(); // Revert changes if desired

    // 7. Testing the Sensor class
    std::cout << "Testing Sensor class:" << std::endl;
    Sensor *motionSensor = new MotionSensor();
    Sensor *doorLockSensor = new DoorLockSensor();
    Sensor *temperatureSensor = new TemperatureSensor(25.0);  // Threshold is set to 25 degrees Celsius

    // Register devices to sensors
    motionSensor->attach(livingRoomLight);  // Register light to be notified by the motion sensor
    doorLockSensor->attach(frontDoor);  // Register door lock to be notified by the door lock sensor
    temperatureSensor->attach(thermostat); // Register light to the temperature sensor for notification

    // Initial device statuses
    std::cout << "Initial Statuses:" << std::endl;
    std::cout << "Living Room Light: " << livingRoomLight->getStatus() << std::endl;
    std::cout << "Front Door Lock: " << frontDoor->getStatus() << std::endl;

    // Simulate motion detection
    std::cout << "\nMotion detected..." << std::endl;
    motionSensor->detectMotion();  // Notify devices connected to the motion sensor
    std::cout << "Living Room Light (after motion): " << livingRoomLight->getStatus() << std::endl;

    // Simulate door unlocking
    std::cout << "\nDoor unlocking..." << std::endl;
    doorLockSensor->unlock();  // Notify devices connected to the door lock sensor
    std::cout << "Front Door Lock (after unlocking): " << frontDoor->getStatus() << std::endl;

    // Simulate temperature change crossing threshold
    std::cout << "\nTemperature rising to 26°C..." << std::endl;
    temperatureSensor->checkTemp(26.0);  // Notify devices if the temperature crosses the threshold
    std::cout << "Thermostat (after temperature threshold crossed): " << thermostat->getStatus() << std::endl;

    motionSensor->detach(livingRoomLight);
    doorLockSensor->detach(frontDoor);  // Register door lock to be notified by the door lock sensor
    temperatureSensor->detach(thermostat); // Register light to the temperature sensor for notification

    delete light;
    delete thermostat;
    delete lock;
    delete livingRoomLight;
    delete frontDoor;
    delete thermostat2;
    delete turnOffLightsCommand;
    delete lockAllDoorsCommand;
    delete goodnightRoutine;
    delete motionSensor;
    delete doorLockSensor;
    delete temperatureSensor;
    return 0;
}
