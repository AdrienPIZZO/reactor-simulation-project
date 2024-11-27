#ifndef REACTOR_H
#define REACTOR_H

#include <QObject>
#include <QTimer>

constexpr int TIMER_INTERVAL = 100;
constexpr double POWER_SCALING = 0.1;
constexpr double TEMP_OFFSET = 20;
constexpr double TEMP_SCALING = 0.05;

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

private slots:
    void update();
};

#endif // REACTOR_H
