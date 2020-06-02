#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->first, &QPushButton::clicked, [](){qDebug() << "Hello, BITCH!";});
    connect(ui->second, &QPushButton::clicked, [this](){this->ui->second->close();});
    connect(ui->nextwindow, SIGNAL(clicked()), this, SLOT(show_dialog()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_dialog()
{
    Dialog *hi = new Dialog(this);
    this->close();
    hi->showMaximized();
}
