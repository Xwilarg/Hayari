#include <QApplication>
#include <QtWebEngine>
#include "inc/MainWindow.hpp"

int main(int argc, char *argv[])
{
    QtWebEngine::initialize();
    QApplication a(argc, argv);

    Hayari::MainWindow w;
    w.show();

    return a.exec();
}
