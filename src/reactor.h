#ifndef REACTOR_H
#define REACTOR_H

#include <QObject>
#include <QTimer>

constexpr int TIMER_INTERVAL = 100;

class Reactor : public QObject {
    Q_OBJECT
public:
    Reactor(QObject *parent = nullptr, double power = 0, double temperature = 20, double controlPosition = 0);
    ~Reactor();

    double getPower() const;
    double getTemperature() const;
    double getControlPosition() const;
    void setControlPosition(double controlPosition);

    void startSimulation();
    void stopSimulation();

signals:
    void dataUpdated(double power, double temperature);

private:
    double power;
    double temperature;
    double controlPosition;
    QTimer *simulationTimer;

    const double k = 0.05;       // Power increase factor
    const double lambda = 0.01;  // Natural power decay
    const double alpha = 0.07;    // Power-to-temperature conversion factor
    const double beta = 0.02;        // Heat dissipation factor
    const double T_environment = 25; // Ambient temperature

private slots:
    void update();
};

#endif // REACTOR_H
