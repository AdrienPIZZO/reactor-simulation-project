#include "ReactorWindow.h"
#include <QGraphicsScene>
#include <QVBoxLayout>

ReactorWindow::ReactorWindow(QWidget *parent)
    : QMainWindow(parent), power(0), temperature(20) {

    reactorView = new QGraphicsView(this);
    QGraphicsScene *scene = new QGraphicsScene(this);
    reactorView->setScene(scene);

    controlSlider = new QSlider(Qt::Horizontal, this);
    controlSlider->setRange(0, 100);

    powerLabel = new QLabel("Puissance : 0 MW", this);
    temperatureLabel = new QLabel("Température : 20°C", this);

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(reactorView);
    layout->addWidget(controlSlider);
    layout->addWidget(powerLabel);
    layout->addWidget(temperatureLabel);
    setCentralWidget(centralWidget);

    simulationTimer = new QTimer(this);
    connect(simulationTimer, &QTimer::timeout, this, &ReactorWindow::updateSimulation);
    simulationTimer->start(100);
}

ReactorWindow::~ReactorWindow() {}

void ReactorWindow::updateSimulation() {
    int position = controlSlider->value();

    power = 0.1 * position * position;
    temperature = 20 + 0.05 * power;

    powerLabel->setText(QString("Puissance : %1 MW").arg(power, 0, 'f', 1));
    temperatureLabel->setText(QString("Température : %1°C").arg(temperature, 0, 'f', 1));
}
