#include "collector.h"

#include <QDebug>

Collector &Collector::getCollector()
{

    static Collector coll;
    return coll;


}

void Collector::setMaterialsTable(const QVector<MaterialsDB> &materials)
{
    try
    {

        DataBase db;

        _materialsTable = db.getTableMaterials();

    }
    catch (mysqlx::Error &err)
    {
        qDebug() << err.what();
    }
}

void Collector::setInstrumentsTable(const QVector<InstrumentsDB> &instruments)
{
    try
    {

        DataBase db;

        _instrumentsTable = db.getTableInstruments();

    }
    catch (mysqlx::Error &err)
    {
        qDebug() << err.what();
    }
}

void Collector::setDrillingMachinesTable(const QVector<DrillingMachineDB> &materials)
{
    try
    {

        DataBase db;

        _drillingMachinesTable = db.getTableDrillingMachines();

    }
    catch (mysqlx::Error &err)
    {
        qDebug() << err.what();
    }


}

void Collector::setTableValue(std::shared_ptr<TableValueDB> table_value)
{
    _table_value = table_value;
}

void Collector::setTValue(std::shared_ptr<TValueDB> t_value)
{
    _t_value = t_value;
}

void Collector::setKmv(std::shared_ptr<KmvDB> kmv)
{
    _kmv = kmv;
}

void Collector::setKmp(std::shared_ptr<KmpDB> kmp)
{
    _kmp = kmp;
}

void Collector::setPRM(std::shared_ptr<PRMDB> prm)
{
    _prm = prm;
}

void Collector::setRest(std::shared_ptr<RestData> restData)
{
    _restData = restData;
}

void Collector::setFeed(std::shared_ptr<FeedDB> feed)
{
    _feed = feed;
}



const QVector<MaterialsDB>& Collector::getMaterialsTabel() const
{
    return _materialsTable;
}

const QVector<InstrumentsDB>& Collector::getInstrumentsTable() const
{
    return _instrumentsTable;
}

const QVector<DrillingMachineDB>& Collector::getDrillingMachinesTable() const
{
    return _drillingMachinesTable;
}

std::shared_ptr<TableValueDB> Collector::getTableValue() const
{
    return _table_value;
}

std::shared_ptr<TValueDB> Collector::getTValue() const
{
    return _t_value;
}

std::shared_ptr<KmvDB> Collector::getKmvValue() const
{
    return _kmv;
}

std::shared_ptr<KmpDB> Collector::getKmpValue() const
{
    return _kmp;
}

std::shared_ptr<PRMDB> Collector::getPRMValue() const
{
    return _prm;
}

std::shared_ptr<FeedDB> Collector::getFeed() const
{
    return _feed;
}

std::shared_ptr<RestData> Collector::getRestData() const
{
    return _restData;
}





