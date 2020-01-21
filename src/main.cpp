#include <QApplication>
#include "inc/MainWindow.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Hayari::MainWindow w;
    w.show();

    return a.exec();
}
