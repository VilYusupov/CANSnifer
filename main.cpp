#include "cansnifer.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CANSnifer w;
    w.show();
    return a.exec();
}
