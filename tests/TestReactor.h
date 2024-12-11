#ifndef TEST_REACTOR_H
#define TEST_REACTOR_H

#include <QtTest>
#include "../src/reactorwindow.h"

class TestReactor : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testUpdateSimulation();
    void testDynamicPowerGraph();
    void testDynamicTemperatureGraph();

private:
    ReactorWindow *calc;
};

#endif // TEST_REACTOR_H
