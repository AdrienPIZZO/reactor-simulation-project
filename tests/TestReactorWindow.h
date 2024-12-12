#ifndef TEST_REACTOR_WINDOW_H
#define TEST_REACTOR_WINDOW_H

#include <QtTest>
#include "../src/reactorwindow.h"

class TestReactorWindow : public QObject
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

#endif // TEST_REACTOR_WINDOW_H
