#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFont>
#include <QFontDialog>
#include <QColor>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    filePath = "";
    ui->textEdit->setText("");
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File");
    QFile file(fileName);
    filePath = fileName;
    if(!file.open(QFile::ReadOnly | QFile::Text))
        QMessageBox::warning(this, "Warning", "File not Open");

    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionSave_triggered()
{
    QFile file(filePath);
    if(!file.open(QFile::WriteOnly | QFile::Text))
        QMessageBox::warning(this, "Warning", "File not Open");

    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Open File");
    QFile file(fileName);
    filePath = fileName;
    if(!file.open(QFile::WriteOnly | QFile::Text))
        QMessageBox::warning(this, "Warning", "File not Open");

    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_actionExit_triggered()
{

}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionAbout_Allo_s_Notepad_triggered()
{
    QMessageBox::about(this, "About", "Allo's Notepad is a simple application by Allan Mwirigi,"
                                      "a first year student at JKUAT");
}

void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok)
        ui->textEdit->setFont(font);
    else
        return;
}

void MainWindow::on_actionColour_triggered()
{
    QColor colour = QColorDialog::getColor(Qt::white, this, "Choose Colour");
    if(colour.isValid())
        ui->textEdit->setTextColor(colour);
}
