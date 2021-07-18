#include "warehousecontrol.h"
#include "./ui_warehousecontrol.h"

WarehouseControl::WarehouseControl(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WarehouseControl)
{
    ui->setupUi(this);
}

WarehouseControl::~WarehouseControl()
{
    delete ui;
}

