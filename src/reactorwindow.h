#ifndef REACTORWINDOW_H
#define REACTORWINDOW_H

#include "reactor.h"
#include <QMainWindow>
#include <QGraphicsView>
#include <QSlider>
#include <QLabel>
#include <QTimer>
#include <QChartView>
#include <QLineSeries>

class ReactorWindow : public QMainWindow
{
    Q_OBJECT

public:
    ReactorWindow(QWidget *parent = nullptr, Reactor *reactor = new Reactor(0, 20));
    ~ReactorWindow();

private slots:
    void updateGUI();

private:
    Reactor *reactor;
    QGraphicsView *reactorView;
    QSlider *controlSlider;
    QLabel *powerLabel;
    QLabel *temperatureLabel;
    QTimer *simulationTimer;
    QChartView *powerChartView;
    QLineSeries *powerSeries;

    void updatePowerChart(int elapsedTime, double power);
};
#endif // REACTORWINDOW_H
