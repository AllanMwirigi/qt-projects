#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myFunction()));
    timer->start(1000);
    myFunction();
    setWindowTitle("Digital Clock");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myFunction()
{
    QTime time = QTime::currentTime();
    QString timeText = time.toString("hh:mm");
    if((time.second() % 2) == 0)
        timeText[2] = ' ';
    ui->lcdNumber->display(timeText);
}
