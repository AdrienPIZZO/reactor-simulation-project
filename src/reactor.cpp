#include "reactor.h"

Reactor::Reactor(double power, double temperature, double controlPosition) :
    power(power), temperature(temperature), controlPosition(controlPosition) {}

void Reactor::update() {
    power = POWER_SCALING * controlPosition * controlPosition;
    temperature = TEMP_OFFSET + TEMP_SCALING * power;
}

double Reactor::getPower() const { return power; }
double Reactor::getTemperature() const { return temperature; }
double Reactor::getControlPosition() const { return controlPosition; }

void Reactor::setControlPosition(double controlPosition)
{
    this->controlPosition = controlPosition;
}
