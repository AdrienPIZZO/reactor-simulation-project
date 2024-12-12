#ifndef TEST_REACTOR_H
#define TEST_REACTOR_H

#include <QtTest>
#include "../src/reactor.h"

class TestReactor : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testInitialValues();
    void testUpdate();
    void testControlPositionEffect();

private:
    Reactor *reactor;
};

#endif // TEST_REACTOR_WINDOW_H
