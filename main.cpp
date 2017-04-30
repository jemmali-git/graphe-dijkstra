#include "openingpage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    openingPage p;
    p.show();

    return a.exec();
}
