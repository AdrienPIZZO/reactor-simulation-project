#include "ReactorWindow.h"
#include "reactor.h"
#include <QGraphicsScene>
#include <QVBoxLayout>
#include <QValueAxis>

ReactorWindow::ReactorWindow(QWidget *parent, Reactor *reactor)
    : QMainWindow(parent), reactor(reactor) {

    // Control panel

    reactorView = new QGraphicsView(this);
    QGraphicsScene *scene = new QGraphicsScene(this);
    reactorView->setScene(scene);

    controlSlider = new QSlider(Qt::Horizontal, this);
    controlSlider->setRange(0, 100);
    controlSlider->setObjectName("controlSlider");

    powerLabel = new QLabel("Puissance : 0 MW", this);
    powerLabel->setObjectName("powerLabel");

    temperatureLabel = new QLabel("Température : 20°C", this);
    temperatureLabel->setObjectName("temperatureLabel");

    // Chart

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
    axisY->setRange(0, 1000);
    powerChartView->chart()->addAxis(axisY, Qt::AlignLeft);
    powerSeries->attachAxis(axisY);

    // Central widget

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(reactorView);
    layout->addWidget(controlSlider);
    layout->addWidget(powerLabel);
    layout->addWidget(temperatureLabel);
    layout->addWidget(powerChartView);
    setCentralWidget(centralWidget);

    // TODO : do the update in the reactor and put an observer
    simulationTimer = new QTimer(this);
    connect(simulationTimer, &QTimer::timeout, this, &ReactorWindow::updateGUI);
    simulationTimer->start(100);
}

ReactorWindow::~ReactorWindow() {}

void ReactorWindow::updatePowerChart(int elapsedTime, double power) {
    powerSeries->append(elapsedTime, power);
    powerChartView->chart()->axes(Qt::Horizontal).first()->setRange(0, elapsedTime);
}

void ReactorWindow::updateGUI() {
    int position = controlSlider->value();
    reactor->setControlPosition(position);

    // TO DO : delete this line once the update is in the reactor
    reactor->update();

    powerLabel->setText(QString("Puissance : %1 MW").arg(reactor->getPower(), 0, 'f', 1));
    temperatureLabel->setText(QString("Température : %1°C").arg(reactor->getTemperature(), 0, 'f', 1));

    static int elapsedTime = 0;
    elapsedTime += TIMER_INTERVAL;

    updatePowerChart(elapsedTime, reactor->getPower());
}
