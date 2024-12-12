#include <QtTest>
#include "TestReactor.h"

void TestReactor::initTestCase() {
    reactor = new Reactor(nullptr, 10.0, 25.0, 50.0);
    reactor->startSimulation();
}

void TestReactor::cleanupTestCase() {
    delete reactor;
}

void TestReactor::testInitialValues() {
    QCOMPARE(reactor->getPower(), 10.0);
    QCOMPARE(reactor->getTemperature(), 25.0);
    QCOMPARE(reactor->getControlPosition(), 50.0);
}

void TestReactor::testUpdate() {
    // Effectuer une mise à jour et vérifier que les valeurs changent
    double initialPower = reactor->getPower();
    double initialTemperature = reactor->getTemperature();

    reactor->setControlPosition(70.0); // Simuler un changement de contrôle
    QTest::qWait(TIMER_INTERVAL * 2);

    QVERIFY(reactor->getPower() > initialPower); // La puissance doit augmenter
    QVERIFY(reactor->getTemperature() > initialTemperature); // La température doit augmenter
}

void TestReactor::testControlPositionEffect() {
    reactor->startSimulation();
    // Tester l'effet de la position de contrôle sur la puissance
    reactor->setControlPosition(0.0);
    QTest::qWait(TIMER_INTERVAL * 2);
    double lowControlPower = reactor->getPower();

    reactor->setControlPosition(100.0);
    QTest::qWait(TIMER_INTERVAL * 2);
    double highControlPower = reactor->getPower();

    QVERIFY(highControlPower > lowControlPower); // La position de contrôle élevée doit entraîner une puissance plus élevée
}

QTEST_MAIN(TestReactor)
#include "TestReactor.moc"
