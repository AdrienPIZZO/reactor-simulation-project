#ifndef REACTORWINDOW_H
#define REACTORWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QSlider>
#include <QLabel>
#include <QTimer>

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

    double power;
    double temperature;

};
#endif // REACTORWINDOW_H