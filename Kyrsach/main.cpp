#include "mainwindow.h"
#include <QString>
#include <QImage>
#include <iostream>
#include <QApplication>
#include <QPixmap>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
