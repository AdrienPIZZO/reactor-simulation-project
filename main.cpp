#include "reactorwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ReactorWindow w;
    w.show();
    return a.exec();
}
