#ifndef OLDTHERMOSTAT_H
#define OLDTHERMOSTAT_H

class OldThermostat {
private:
    double temperature;
public:
    double getTemperature() const;
    void setTemperature(double temp);
};

#endif // OLDTHERMOSTAT_H
