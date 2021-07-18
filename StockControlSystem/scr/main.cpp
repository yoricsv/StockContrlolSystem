#include "warehousecontrol.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WarehouseControl w;
    w.show();
    return a.exec();
}
