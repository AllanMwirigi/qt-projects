#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QTableView>
#include <QHeaderView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;

    //if(!createConnection())
      //  return 1;

    enum {
    Scooter_Id = 0,
    Scooter_Name = 1,
    Scooter_MaxSpeed = 2,
    Scooter_MaxRange = 3,
    Scooter_Weight = 4,
    Scooter_Description = 5
    };

    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("scooter");
    model->setSort(Scooter_Name, Qt::AscendingOrder);
    model->setHeaderData(Scooter_Name, Qt::Horizontal, "Name");
    model->setHeaderData(Scooter_MaxSpeed, Qt::Horizontal, "MPH");
    model->setHeaderData(Scooter_MaxRange, Qt::Horizontal, "Miles");
    model->setHeaderData(Scooter_Weight, Qt::Horizontal, "Lbs");
    model->setHeaderData(Scooter_Description, Qt::Horizontal, "Description");
    model->select();

    QTableView *view = new QTableView;
    view->setModel(model);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setColumnHidden(Scooter_Id, true);
    view->resizeColumnsToContents();
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QHeaderView *header = view->horizontalHeader();
    header->setStretchLastSection(true);

    view->show();

    //w.show();
    return a.exec();
}

bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("allo.mwirigi.qt");
    db.setDatabaseName("schooldb");
    db.setUserName("Allo");
    db.setPassword("123");
    if (!db.open()) {
        //QMessageBox::critical(0, QObject::tr("Database Error"),
        //db.lastError().text());
        return false;}
    return true;
}
