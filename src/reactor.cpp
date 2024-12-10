#include "reactor.h"
#include <qtimer.h>

// CONSTRUCTOR
Reactor::Reactor(QObject *parent, double power, double temperature, double controlPosition)
    : QObject(parent),
    simulationTimer(new QTimer(this)),
    power(power),
    temperature(temperature),
    controlPosition(controlPosition)
    {
        // Connexion du timer pour mettre à jour la simulation
        connect(simulationTimer, &QTimer::timeout, this, &Reactor::update);
    }

//DESTRUCTOR
Reactor::~Reactor() {
    stopSimulation();
}

//GETTERS SETTERS
double Reactor::getPower() const { return power; }
double Reactor::getTemperature() const { return temperature; }
double Reactor::getControlPosition() const { return controlPosition; }
void Reactor::setControlPosition(double controlPosition) {
    this->controlPosition = controlPosition;
}

//START AND STOP SIMULATION
void Reactor::startSimulation() {
    if (!simulationTimer->isActive()) {
        simulationTimer->start(TIMER_INTERVAL);
    }
}
void Reactor::stopSimulation() {
    if (simulationTimer->isActive()) {
        simulationTimer->stop();
    }
}

//UPDATE
void Reactor::update() {
    power += k * (controlPosition - power) - lambda * power;
    temperature = T_base + alpha * power;

    emit dataUpdated(power, temperature);
}
