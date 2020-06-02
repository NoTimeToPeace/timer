#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->close->setText("BAN");
    connect(ui->close, &QPushButton::clicked, [](){QApplication::quit();});
}

Dialog::~Dialog()
{
    delete ui;
}
