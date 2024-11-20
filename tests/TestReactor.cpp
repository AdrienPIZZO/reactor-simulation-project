#include <QtTest>
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
    QTest::qWait(100);

    std::cout << powerLabel->text().toStdString() << std::endl;

    QVERIFY(powerLabel->text() == "Puissance : 10.0 MW");
    QVERIFY(temperatureLabel->text() == "Température : 20.5°C");
}

QTEST_MAIN(TestReactor)
#include "TestReactor.moc"
