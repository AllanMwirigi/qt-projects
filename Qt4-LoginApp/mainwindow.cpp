#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pic(":/resources/img/backgrnd.png");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pic.scaled(w, h, Qt::KeepAspectRatio));

    /*To include widgets in status bar: first add them in the designer e.g. label3, progressBar
    ui->statusBar->addPermanentWidget(ui->label_3);
    ui->statusBar->addPermanentWidget(ui->progressBar);*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username == "Allan" && password == "123")
     {   QMessageBox::information(this, "LogIn", "Username and password entered are valid");
        // hide();
        secDialog = new SecDialog(this);
        secDialog->show();
    //To use the status bar instead:
     // ui->statusBar->showMessage("Username and password entered are valid", 5000);
    }

    else{
        QMessageBox::warning(this, "LogIn", "Username and password entered are invalid");
    //To use the status bar instead:
     // ui->statusBar->showMessage("Username and password entered are invalid", 5000);
    }

}
