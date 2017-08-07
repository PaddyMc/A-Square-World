#include "startwindow.h"
#include <QApplication>
#include <QtCore>
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow w;
    w.setWindowTitle("Project : 10109781");
    w.show();

    return a.exec();
}
