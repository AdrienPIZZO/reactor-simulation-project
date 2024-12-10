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

    double k = 0.05;       // Power increase factor
    double lambda = 0.01;  // Natural power decay
    double alpha = 0.5;    // Power-to-temperature conversion factor
    double T_base = 20.0;  // Base temperature

private slots:
    void update();
};

#endif // REACTOR_H
