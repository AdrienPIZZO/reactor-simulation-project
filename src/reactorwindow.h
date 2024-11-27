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
    ReactorWindow(QWidget *parent = nullptr);
    ~ReactorWindow();

private:
    Reactor *reactor;
    QGraphicsView *reactorView;
    QSlider *controlSlider;
    QLabel *powerLabel;
    QLabel *temperatureLabel;
    QChartView *powerChartView;
    QLineSeries *powerSeries;

    void setupUI();
    void updatePowerChart(int elapsedTime, double power);

private slots:
    void updateUI();
};

#endif // REACTORWINDOW_H