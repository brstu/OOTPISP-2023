#include "mainwindow.h"
#include "openfile.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mw;
    mw.show();
    OpenFile of;
    of.show();
    return a.exec();
}
