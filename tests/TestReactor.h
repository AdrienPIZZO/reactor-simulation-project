#ifndef TEST_REACTOR_H
#define TEST_REACTOR_H

#include <QtTest>
#include "../reactorwindow.h"

class TestReactor : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testUpdateSimulation();

private:
    ReactorWindow *calc;
};

#endif // TEST_REACTOR_H
