#include <QtTest>
#include <QChartView>
#include <QLineSeries>
#include "TestReactorWindow.h"

void TestReactorWindow::initTestCase() {
    calc = new ReactorWindow();
    calc->show();
}

void TestReactorWindow::cleanupTestCase() {
    delete calc;
}

void TestReactorWindow::testUpdateSimulation() {
    QSlider *slider = calc->findChild<QSlider*>("controlSlider");
    QLabel *powerLabel = calc->findChild<QLabel*>("powerLabel");
    QLabel *temperatureLabel = calc->findChild<QLabel*>("temperatureLabel");

    QVERIFY(slider);
    QVERIFY(powerLabel);
    QVERIFY(temperatureLabel);

    auto initialPower = powerLabel->text();
    auto initialTemperature = temperatureLabel->text();

    slider->setValue(50);
    QTest::qWait(TIMER_INTERVAL * 2); // Wait for 2 updates

    // Check if power and temperature updated
    QVERIFY(powerLabel->text() != initialPower);
    QVERIFY(temperatureLabel->text() != initialTemperature);
}

void TestReactorWindow::testDynamicPowerGraph() {
    QChartView *powerChartView = calc->findChild<QChartView*>("powerChartView");
    QVERIFY(powerChartView);

    QChart *powerChart = powerChartView->chart();
    QVERIFY(powerChart);

    QSlider *slider = calc->findChild<QSlider*>("controlSlider");
    QVERIFY(slider);

    auto *powerSeries = qobject_cast<QLineSeries*>(powerChart->series().at(0));
    QVERIFY(powerSeries);
    int initialPointCount = powerSeries->count();

    slider->setValue(70);
    QTest::qWait(TIMER_INTERVAL * 3);

    // Verify new points are added to the graph
    QVERIFY(powerSeries->count() > initialPointCount);
}

void TestReactorWindow::testDynamicTemperatureGraph() {
    QChartView *temperatureChartView = calc->findChild<QChartView*>("temperatureChartView");
    QVERIFY(temperatureChartView);

    QChart *temperatureChart = temperatureChartView->chart();
    QVERIFY(temperatureChart);

    QSlider *slider = calc->findChild<QSlider*>("controlSlider");
    QVERIFY(slider);

    auto *temperatureSeries = qobject_cast<QLineSeries*>(temperatureChart->series().at(0));
    QVERIFY(temperatureSeries);
    int initialPointCount = temperatureSeries->count();

    slider->setValue(70);
    QTest::qWait(TIMER_INTERVAL * 3);

    // Verify new points are added to the graph
    QVERIFY(temperatureSeries->count() > initialPointCount);
}

QTEST_MAIN(TestReactorWindow)
#include "TestReactorWindow.moc"
