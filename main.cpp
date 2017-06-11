#include "mainwindow.h"
#include <QApplication>

bool isDebug = false;

int main(int argc, char *argv[])
{
    // Mark Debug Flag
    #ifdef QT_DEBUG
        isDebug = true;
    #endif

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
