#ifndef REACTOR_H
#define REACTOR_H

constexpr int TIMER_INTERVAL = 100;
constexpr double POWER_SCALING = 0.1;
constexpr double TEMP_OFFSET = 20;
constexpr double TEMP_SCALING = 0.05;

class Reactor
{
public:
    Reactor(double power, double temperature);
    ~Reactor();
    double getPower() const;
    double getTemperature() const;
    void update(int controlPosition);
private:
    double power;
    double temperature;
};

#endif // REACTOR_H
