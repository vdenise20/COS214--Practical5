Component 1: Command pattern

1. Main (Client)
The client is responsible for setting up the system by creating devices, commands, and assigning them to the RemoteControl.
Variables:
	• RemoteControl remote; – The invoker that interacts with commands.
	• Light light; – Receiver for the smart light.
	• Thermostat thermostat; – Receiver for the smart thermostat.
	• DoorLock doorLock; – Receiver for the smart door lock.
Methods:
	• void initializeCommands() – Sets up commands for each device and assigns them to the RemoteControl.
Purpose: Initializes the system and connects commands with receivers and the invoker.

2. RemoteControl (Invoker)
The invoker holds and executes commands when a user interacts with it.
Variables:
	• Command* slot; – Stores the current command to be executed.
	• std::string deviceType; – Stores the type of device being controlled (optional, useful for UI).
Methods:
	• void setCommand(Command* cmd) – Assigns a specific command to the invoker.
	• void pressButton() – Executes the command stored in slot.
Purpose: Acts as the interface between the user and the smart devices, triggering commands.

3. Command (Interface)
The base interface that all commands will implement.
Methods:
	• virtual void execute() = 0; – Executes the command.
	• virtual void undo() = 0; – Reverts the command (optional).
Purpose: Ensures all commands follow a standard structure and can be executed or undone.

4. ConcreteCommand (LightCommand, ThermostatCommand, DoorLockCommand, etc.)

LightCommand
This command turns on the light.
Variables:
	• Light* lightReceiver; – Stores the receiver (light) to act upon.
Methods:
	• LightOnCommand(Light* light) – Constructor that assigns the light receiver.
	• void execute() – Calls light->turnOn() to turn on the light.
	• void undo() – Calls light->turnOff() to revert the action.
Purpose: Executes the action to turn on the light and can undo it by turning it off.

ThermostatCommand
This command sets the thermostat to a specific temperature.
Variables:
	• Thermostat* thermoReceiver; – Stores the thermostat receiver.
	• int newTemp; – The temperature to set the thermostat to.
	• int prevTemp; – Stores the previous temperature for undo purposes.
Methods:
	• ThermostatSetTempCommand(Thermostat* thermostat, int temp) – Constructor that assigns the thermostat and target temperature.
	• void execute() – Calls thermostat->setTemperature(newTemp) to set the thermostat to the new temperature.
	• void undo() – Calls thermostat->setTemperature(prevTemp) to revert the thermostat to its previous temperature.
Purpose: Adjusts the thermostat temperature and stores the previous temperature for undo functionality.

DoorLockCommand
This command locks the door.
Variables:
	• DoorLock* doorLockReceiver; – Stores the door lock receiver.
	• bool prevState; – Stores the previous lock state for undo purposes.
Methods:
	• LockDoorCommand(DoorLock* doorLock) – Constructor that assigns the door lock receiver.
	• void execute() – Calls doorLock->lock() to lock the door.
	• void undo() – Calls doorLock->unlock() to revert the lock state.
Purpose: Executes the action to lock the door and can undo it by unlocking the door.



5. Receiver (Light, Thermostat, DoorLock)
a. Light (Receiver)
Represents a smart light that can be turned on or off.
Variables:
	• bool isOn; – Stores whether the light is on (true) or off (false).
Methods:
	• void turnOn() – Turns the light on.
	• void turnOff() – Turns the light off.
	• std::string getStatus() – Returns the current status of the light ("on" or "off").
Purpose: Controls and manages the state of the light. Commands like LightOnCommand will invoke these methods.


b. Thermostat (Receiver)
Represents a smart thermostat that can have its temperature adjusted.
Variables:
	• int currentTemp; – Stores the current temperature of the thermostat.
	• int targetTemp; – The target temperature the thermostat is set to.
Methods:
	• void setTemperature(int temp) – Sets the thermostat to the given temperature.
	• int getTemperature() – Returns the current temperature setting.
	• std::string getStatus() – Returns the thermostat's current status, e.g., "set to 22°C".
Purpose: Manages the temperature settings of the thermostat. Commands like SetThermostatTempCommand will interact with this receiver.


c. DoorLock (Receiver)
Represents a smart door lock that can be locked or unlocked.
Variables:
	• bool isLocked; – Tracks whether the door is locked (true) or unlocked (false).
Methods:
	• void lock() – Locks the door.
	• void unlock() – Unlocks the door.
	• std::string getStatus() – Returns the current lock status ("locked" or "unlocked").
Purpose: Controls the locking mechanism for the door. Commands like LockDoorCommand will invoke these methods.




Helper Methods for State Management
	1. Light
		○ void toggle() – Toggles between on and off.
		○ Purpose: Useful for creating commands that can flip the light’s state without needing separate on/off commands.
	2. Thermostat
		○ bool isAtTargetTemperature() – Checks if the current temperature matches the target temperature.
		○ Purpose: Useful for ensuring the thermostat reaches the desired temperature and for more complex automation.
	3. DoorLock
		○ bool isLockedState() – Checks if the door is currently locked.
		○ Purpose: Useful for automation routines that require the door to be locked before proceeding.


=======================================================================

Component 2 : Adapter Pattern


1. Adaptee
	• Class: OldThermostat
	• Role: The existing legacy device that has an incompatible interface with the modern system. It contains methods like oldSetTemperature() and oldGetTemperature(), which need to be adapted to match the smart home system's interface.
	• Purpose: The Adaptee has a legacy interface that needs to be adapted to work within the smart home system.

3. Target
	• Class: Thermostat (abstract class or interface)
	• Role: The domain-specific interface used by the client. The modern smart home system expects devices (both legacy and new) to conform to this interface. For instance, it includes methods like setTemperature() and getTemperature().
	• Purpose: The Target defines the interface that the system works with, ensuring that all devices (both legacy and modern) are controlled in a uniform way.

5. Adapter
	• Class: LegacyThermostatAdapter
	• Role: The Adapter converts the legacy interface of the OldThermostat (Adaptee) to the Thermostat interface (Target). It delegates commands to the adaptee (legacy device) while conforming to the Target interface.
	• Purpose: The Adapter allows the legacy device (Adaptee) to be controlled via the Target interface, bridging the gap between incompatible interfaces.

6. Client
	• Class: Main Application (or some higher-level class interacting with the system)
	• Role: The Client interacts with objects that implement the Target interface (in this case, the modern Thermostat interface). The client is unaware of the legacy system and interacts uniformly with all devices via the Target interface.
	• Purpose: The Client uses the smart home system, issuing commands to devices. It interacts with the Adapter through the Target interface (Thermostat), not knowing or caring that a legacy device is behind the scenes.

Integration with component 1:

 Client
The client sets up both the smart and legacy devices, creating adapters for legacy devices to interact with the system.
Variables:
	• RemoteControl remote; – Invoker used to send commands.
	• Light light; – Receiver for a modern light.
	• Thermostat thermostat; – Receiver for a modern thermostat.
	• DoorLock doorLock; – Receiver for a modern door lock.
	• Legacy Devices:
		○ OldThermostat oldThermostat; – The legacy thermostat device that needs an adapter.
Methods:
	• void initializeCommands() – Sets up commands for both modern and legacy devices by using an adapter for legacy devices.
Purpose: The client initializes both modern and legacy devices, creating adapters for the latter to ensure they can be controlled using the RemoteControl.

2. RemoteControl (Invoker)
The invoker interacts with both modern and legacy devices via commands.
Variables:
	• Command* slot; – Stores the command to be executed.
Methods:
	• void setCommand(Command* cmd) – Assigns a command to the invoker.
	• void pressButton() – Executes the command.
Purpose: Acts as the interface for the user to trigger actions on both modern and legacy devices via the adapter.

3. Command (Interface)
The base command interface that both modern and legacy device commands will implement.
Methods:
	• virtual void execute() = 0; – Executes the command.
	• virtual void undo() = 0; – Optionally undoes the command.
Purpose: Ensures consistency across commands for both smart and legacy devices, allowing them to be executed by the invoker.

4. ConcreteCommand (ThermostatSetTempCommand, LightOnCommand, LegacyThermostatSetTempCommand, etc.)
These classes invoke specific actions on modern or legacy devices.
Variables:
	• Receiver* receiver; – Stores the reference to the device (modern or legacy).
	• int previousState; – Stores the previous state for undo functionality.
Methods:
	• void execute() – Executes the command on the device (e.g., turns on a light or sets a thermostat temperature).
	• void undo() – Reverts the action on the device.
Purpose: Encapsulates the interaction between the invoker and both modern and legacy receivers, ensuring they can be controlled similarly.

5. Receivers
a. Modern Devices
The modern devices follow the same structure as described in Component 1 (Light, Thermostat, DoorLock), with methods like turnOn(), setTemperature(), lock(), etc.
b. Legacy Device (OldThermostat)
Legacy devices don't follow the smart home interface, so we need an adapter to integrate them into the system.
OldThermostat (Adaptee):
Represents a legacy thermostat that has a different interface compared to the modern one.
Variables:
	• float currentTemp; – The temperature of the old thermostat.
Methods:
	• void oldSetTemperature(float temp) – Sets the temperature using the old interface.
	• float oldGetTemperature() – Gets the current temperature from the legacy thermostat.
Purpose: Controls the old thermostat using its own interface, which will be adapted to work with the modern smart home system.

6. Adapter (LegacyThermostatAdapter)
The adapter allows the old thermostat to be controlled like a modern smart thermostat.
Variables:
	• OldThermostat* oldThermostat; – Reference to the legacy device being adapted.
	• int targetTemp; – Target temperature to be set.
Methods:
	• LegacyThermostatAdapter(OldThermostat* oldThermostat) – Constructor that takes in the legacy thermostat.
	• void setTemperature(int temp) – Converts the modern setTemperature() command to the old oldSetTemperature() method.
	• int getTemperature() – Converts the modern getTemperature() call to the old oldGetTemperature() method.
Purpose: Adapts the legacy thermostat interface to behave like the modern thermostat, allowing it to be controlled by the RemoteControl.

Helper Methods for State Management (Legacy Devices)
	1. OldThermostat
		○ float oldGetTemperature() – Fetches the current temperature from the legacy thermostat.
		○ Purpose: Converts the old interface method into something usable by the adapter.
	2. LegacyThermostatAdapter
		○ int getTemperature() – Adapts the legacy temperature reading to match the modern interface.
		○ Purpose: Adapts old data into the format expected by the smart home system.
