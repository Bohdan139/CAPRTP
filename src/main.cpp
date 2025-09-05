#include "mainwindow.h"
#include "collector.h"
#include <mysqlx/xdevapi.h>
#include <QApplication>
#include "database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    try
    {
        Collector& coll = Collector::getCollector();

        DataBase db;


        coll.setMaterialsTable(db.getTableMaterials());
        coll.setInstrumentsTable(db.getTableInstruments());
        coll.setDrillingMachinesTable(db.getTableDrillingMachines());




    }
    catch (const mysqlx::Error &err)
    {
        qDebug() << err.what();
        QMessageBox::warning(nullptr,"Error","Не вдалося підключитися до бази даних");
        return -1;
    }





    MainWindow w;



    w.show();
    return a.exec();

}
