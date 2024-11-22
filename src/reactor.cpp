#include "reactor.h"

Reactor::Reactor(double power, double temperature) :
    power(power), temperature(temperature) {}

void Reactor::update(int controlPosition) {
    power = POWER_SCALING * controlPosition * controlPosition;
    temperature = TEMP_OFFSET + TEMP_SCALING * power;
}

double Reactor::getPower() const { return power; }
double Reactor::getTemperature() const { return temperature; }
