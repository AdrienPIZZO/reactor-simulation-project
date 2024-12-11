#include "ReactorWindow.h"
#include "reactor.h"
#include <QGraphicsScene>
#include <QVBoxLayout>
#include <QValueAxis>

ReactorWindow::ReactorWindow(QWidget *parent)
    : QMainWindow(parent), reactor(new Reactor(this)) {
    setupUI();
    connect(reactor, &Reactor::dataUpdated, this, &ReactorWindow::updateUI);
    reactor->startSimulation();
}

ReactorWindow::~ReactorWindow() {}

void ReactorWindow::setupUI() {
    // Control panel
    reactorView = new QGraphicsView(this);
    QGraphicsScene *scene = new QGraphicsScene(this);
    reactorView->setScene(scene);

    controlSlider = new QSlider(Qt::Horizontal, this);
    controlSlider->setRange(0, 100);
    controlSlider->setObjectName("controlSlider");

    QString powerQString = QString("Puissance : %1 MW").arg(reactor->getPower(), 0, 'f', 1);
    powerLabel = new QLabel(powerQString, this);
    powerLabel->setObjectName("powerLabel");

    QString temperatureQString = QString("Température : %1°C").arg(reactor->getTemperature(), 0, 'f', 1);
    temperatureLabel = new QLabel(temperatureQString, this);
    temperatureLabel->setObjectName("temperatureLabel");

    // Power Chart
    powerChartView = new QChartView(new QChart(), this);
    powerChartView->setObjectName("powerChartView");

    powerSeries = new QLineSeries();
    powerSeries->setName("Évolution de la puissance");
    powerChartView->chart()->addSeries(powerSeries);

    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Temps (ms)");
    axisX->setLabelFormat("%i");
    powerChartView->chart()->addAxis(axisX, Qt::AlignBottom);
    powerSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Puissance (MW)");
    axisY->setRange(0, 100);
    powerChartView->chart()->addAxis(axisY, Qt::AlignLeft);
    powerSeries->attachAxis(axisY);

    // Temperature Chart
    temperatureChartView = new QChartView(new QChart(), this);
    temperatureChartView->setObjectName("temperatureChartView");

    temperatureSeries = new QLineSeries();
    temperatureSeries->setName("Évolution de la température");
    temperatureChartView->chart()->addSeries(temperatureSeries);

    QValueAxis *axisXTemp = new QValueAxis();
    axisXTemp->setTitleText("Temps (ms)");
    axisXTemp->setLabelFormat("%i");
    temperatureChartView->chart()->addAxis(axisXTemp, Qt::AlignBottom);
    temperatureSeries->attachAxis(axisXTemp);

    QValueAxis *axisYTemp = new QValueAxis();
    axisYTemp->setTitleText("Température (°C)");
    axisYTemp->setRange(0, 350);
    temperatureChartView->chart()->addAxis(axisYTemp, Qt::AlignLeft);
    temperatureSeries->attachAxis(axisYTemp);

    // Central widget
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Chart layout
    QHBoxLayout *chartLayout = new QHBoxLayout();
    chartLayout->addWidget(powerChartView);
    chartLayout->addWidget(temperatureChartView);

    layout->addWidget(reactorView);
    layout->addWidget(controlSlider);
    layout->addWidget(powerLabel);
    layout->addWidget(temperatureLabel);
    layout->addLayout(chartLayout);

    setCentralWidget(centralWidget);
}

void ReactorWindow::updatePowerChart(int elapsedTime, double power) {
    powerSeries->append(elapsedTime, power);
    powerChartView->chart()->axes(Qt::Horizontal).first()->setRange(0, elapsedTime);
}

void ReactorWindow::updateTemperatureChart(int elapsedTime, double temperature) {
    temperatureSeries->append(elapsedTime, temperature);
    temperatureChartView->chart()->axes(Qt::Horizontal).first()->setRange(0, elapsedTime);
}

void ReactorWindow::updateUI() {
    int position = controlSlider->value();
    reactor->setControlPosition(position);

    powerLabel->setText(QString("Puissance : %1 MW").arg(reactor->getPower(), 0, 'f', 1));
    temperatureLabel->setText(QString("Température : %1°C").arg(reactor->getTemperature(), 0, 'f', 1));

    static int elapsedTime = 0;
    elapsedTime += TIMER_INTERVAL;

    updatePowerChart(elapsedTime, reactor->getPower());
    updateTemperatureChart(elapsedTime, reactor->getTemperature());
}
