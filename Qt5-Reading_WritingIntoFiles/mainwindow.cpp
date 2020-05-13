#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QFile myFile("C:/Users/Lewis Mwirigi/Desktop/COMPS/Qt/Qt5-Reading_WritingIntoFiles/file.txt");

    if(!myFile.open(QFile::WriteOnly | QFile::Text))
        QMessageBox::warning(this, "Warning", "File not Open!");

    QTextStream out(&myFile);
    QString text = ui->plainTextEdit->toPlainText();
    out << text;
    myFile.flush();
    myFile.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    QFile myFile("C:/Users/Lewis Mwirigi/Desktop/COMPS/Qt/Qt5-Reading_WritingIntoFiles/file.txt");

    if(!myFile.open(QFile::ReadOnly | QFile::Text))
        QMessageBox::warning(this, "Warning", "File not Open!");

    QTextStream in(&myFile);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    myFile.close();
}
