#include "mainwindow.h"
#include "ui_mainwindow.h"
#define SEC_MS	1000
#define MIN_MS	(SEC_MS * 60)
#define HOUR_MS	(MIN_MS * 60)

QTime operator1(const QTime & t1, const QTime & t2)
{
    int diff = t2.msecsTo(t1);
    return QTime(diff / HOUR_MS, (diff % HOUR_MS) / MIN_MS, (diff % MIN_MS) / SEC_MS, diff % SEC_MS);
}


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timeo = new QTimer();
    connect(ui->start, SIGNAL(pressed()), this, SLOT(StartTimer()));
    connect(ui->stop, SIGNAL(pressed()), this, SLOT(StopTimer()));
    connect(timeo, SIGNAL(timeout()), this, SLOT(update()));
    ui->stop->setStyleSheet("QPushButton {"
                                "background-color: rgb(123, 231, 255);"
                                "border: 2px solid #000000;"
                                "border-radius: 15px;"
                                 "}"
                            "QPushButton:hover{"
                                "background-color: rgb(20, 160, 150);"
                                "border: 2px solid #000000;"
                                "border-radius: 15px;"
                                "}"
                            "QPushButton:pressed{"
                                "background-color: rgb(123, 231, 200);"
                                "border: 2px solid #000000;"
                                "border-radius: 15px;"
                                 "}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update()
{
    ui->label->setText(operator1(QTime::currentTime(),this->start_time).toString());
}

void MainWindow::StartTimer()
{
    this->start_time = QTime::currentTime();
    timeo->start(0);
}

void MainWindow::StopTimer()
{
    timeo->stop();
}
