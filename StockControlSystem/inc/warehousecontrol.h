#ifndef WAREHOUSECONTROL_H
#define WAREHOUSECONTROL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class WarehouseControl; }
QT_END_NAMESPACE

class WarehouseControl : public QMainWindow
{
    Q_OBJECT

public:
    WarehouseControl(QWidget *parent = nullptr);
    ~WarehouseControl();

private:
    Ui::WarehouseControl *ui;
};
#endif // WAREHOUSECONTROL_H
