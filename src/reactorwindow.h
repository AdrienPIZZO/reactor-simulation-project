#ifndef REACTORWINDOW_H
#define REACTORWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QSlider>
#include <QLabel>
#include <QTimer>
#include <QChartView>
#include <QLineSeries>

constexpr int TIMER_INTERVAL = 100;
constexpr double POWER_SCALING = 0.1;
constexpr double TEMP_OFFSET = 20;
constexpr double TEMP_SCALING = 0.05;

class ReactorWindow : public QMainWindow
{
    Q_OBJECT

public:
    ReactorWindow(QWidget *parent = nullptr);
    ~ReactorWindow();

private slots:
    void updateSimulation();

private:
    QGraphicsView *reactorView;
    QSlider *controlSlider;
    QLabel *powerLabel;
    QLabel *temperatureLabel;
    QTimer *simulationTimer;
    QChartView *powerChartView;
    QLineSeries *powerSeries;
    double power;
    double temperature;

    void updatePowerChart(int elapsedTime, double power);
};
#endif // REACTORWINDOW_H
