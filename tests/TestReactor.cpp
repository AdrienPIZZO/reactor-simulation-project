#include <QtTest>
#include <QChartView>
#include <QLineSeries>
#include <iostream>
#include "TestReactor.h"

void TestReactor::initTestCase() {
    calc = new ReactorWindow();
    calc->show();
}

void TestReactor::cleanupTestCase() {
    delete calc;
}

void TestReactor::testUpdateSimulation() {
    QSlider *slider = calc->findChild<QSlider*>("controlSlider");
    QLabel *powerLabel = calc->findChild<QLabel*>("powerLabel");
    QLabel *temperatureLabel = calc->findChild<QLabel*>("temperatureLabel");

    QVERIFY(slider);
    QVERIFY(powerLabel);
    QVERIFY(temperatureLabel);

    slider->setValue(10);
    QTest::qWait(TIMER_INTERVAL);

    std::cout << powerLabel->text().toStdString() << std::endl;

    QVERIFY(powerLabel->text() == "Puissance : 10.0 MW");
    QVERIFY(temperatureLabel->text() == "Température : 20.5°C");
}

void TestReactor::testDynamicGraph() {
    QChartView *chartView = calc->findChild<QChartView*>("powerChartView");
    QVERIFY(chartView);

    QChart *chart = chartView->chart();
    QVERIFY(chart);

    QSlider *slider = calc->findChild<QSlider*>("controlSlider");
    QVERIFY(slider);

    slider->setValue(10);
    QTest::qWait(TIMER_INTERVAL);

    auto *series = qobject_cast<QLineSeries*>(chart->series().at(0));
    QVERIFY(series);
    QVERIFY(series->count() > 0);
}

QTEST_MAIN(TestReactor)
#include "TestReactor.moc"
