#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_1_clicked()
{
    QString text = ui->lineEdit->text();
    if(text.isEmpty())
        ui->lineEdit->setText("1");
    else
        ui->lineEdit->setText(text + "1");
}

void MainWindow::on_pushButton_2_clicked()
{
    QString text = ui->lineEdit->text();
    if(text.isEmpty())
        ui->lineEdit->setText("2");
    else
        ui->lineEdit->setText(text + "2");
}

void MainWindow::on_pushButton_3_clicked()
{
    QString text = ui->lineEdit->text();
    if(text.isEmpty())
        ui->lineEdit->setText("3");
    else
        ui->lineEdit->setText(text + "3");
}

void MainWindow::on_pushButton_plus_clicked()
{
    QString text = ui->lineEdit->text();
    if(text.isEmpty())
        ui->lineEdit->setText("+");
    else
        ui->lineEdit->setText(text + "+");
}

void MainWindow::on_pushButton_4_clicked()
{
    QString text = ui->lineEdit->text();
    if(text.isEmpty())
        ui->lineEdit->setText("4");
    else
        ui->lineEdit->setText(text + "4");
}

void MainWindow::on_pushButton_5_clicked()
{
    QString text = ui->lineEdit->text();
    if(text.isEmpty())
        ui->lineEdit->setText("5");
    else
        ui->lineEdit->setText(text + "5");
}

void MainWindow::on_pushButton_6_clicked()
{
    QString text = ui->lineEdit->text();
    if(text.isEmpty())
        ui->lineEdit->setText("6");
    else
        ui->lineEdit->setText(text + "6");
}

void MainWindow::on_pushButton_minus_clicked()
{
    QString text = ui->lineEdit->text();
    if(text.isEmpty())
        ui->lineEdit->setText("-");
    else
        ui->lineEdit->setText(text + "-");
}

void MainWindow::on_pushButton_7_clicked()
{
    QString text = ui->lineEdit->text();
    if(text.isEmpty())
        ui->lineEdit->setText("7");
    else
        ui->lineEdit->setText(text + "7");
}

void MainWindow::on_pushButton_8_clicked()
{
    QString text = ui->lineEdit->text();
    if(text.isEmpty())
        ui->lineEdit->setText("8");
    else
        ui->lineEdit->setText(text + "8");
}

void MainWindow::on_pushButton_9_clicked()
{
    QString text = ui->lineEdit->text();
    if(text.isEmpty())
        ui->lineEdit->setText("9");
    else
        ui->lineEdit->setText(text + "9");
}

void MainWindow::on_pushButton_times_clicked()
{
    QString text = ui->lineEdit->text();
    if(text.isEmpty())
        ui->lineEdit->setText("*");
    else
        ui->lineEdit->setText(text + "*");
}

void MainWindow::on_pushButton_0_clicked()
{
    QString text = ui->lineEdit->text();
    if(text.isEmpty())
        ui->lineEdit->setText("0");
    else
        ui->lineEdit->setText(text + "0");
}

void MainWindow::on_pushButton_decimal_clicked()
{
    QString text = ui->lineEdit->text();
    if(text.isEmpty())
        ui->lineEdit->setText(".");
    else
        ui->lineEdit->setText(text + ".");
}

void MainWindow::on_pushButton_10_clicked()
{
    QString text = ui->lineEdit->text();
    if(text.isEmpty())
        ui->lineEdit->setText("/");
    else
        ui->lineEdit->setText(text + "/");
}

void MainWindow::on_pushButton_equals_clicked()
{
    QString text = ui->lineEdit->text();

    if(text.indexOf('+') >= 0)
    {
    int l = text.length() - 1;
    int i1 = text.indexOf('+');
    double n1 = text.left(i1).toDouble();
    double n2 = text.mid(i1+1, l).toDouble();
    double result = n1 + n2;
    QString answer;
    ui->lineEdit->setText(answer.setNum(result));}

    if(text.indexOf('-') >= 0)
    {
    int l = text.length() - 1;
    int i1 = text.indexOf('-');
    double n1 = text.left(i1).toDouble();
    double n2 = text.mid(i1+1, l).toDouble();
    double result = n1 - n2;
    QString answer;
    ui->lineEdit->setText(answer.setNum(result));}

    if(text.indexOf('*') >= 0)
    {
    int l = text.length() - 1;
    int i1 = text.indexOf('*');
    double n1 = text.left(i1).toDouble();
    double n2 = text.mid(i1+1, l).toDouble();
    double result = n1 * n2;
    QString answer;
    ui->lineEdit->setText(answer.setNum(result));}

    if(text.indexOf('/') >= 0)
    {
    int l = text.length() - 1;
    int i1 = text.indexOf('/');
    double n1 = text.left(i1).toDouble();
    double n2 = text.mid(i1+1, l).toDouble();
    double result = n1 / n2;
    QString answer;
    ui->lineEdit->setText(answer.setNum(result));}
}

void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->backspace();
}
