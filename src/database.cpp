#include "database.h"
#include <string>


DataBase::DataBase()
{
    sess = std::make_unique<mysqlx::Session>(
        mysqlx::SessionOption::USER, "user",
        mysqlx::SessionOption::PWD, "user123",
        mysqlx::SessionOption::HOST, "cutting-data-cuttingdata.h.aivencloud.com",
        mysqlx::SessionOption::PORT, 20918,
        mysqlx::SessionOption::SSL_MODE, mysqlx::SSLMode::REQUIRED,
        mysqlx::SessionOption::DB, "defaultdb"
        );
}

QVector<MaterialsDB> DataBase::getTableMaterials()
{
    QVector<MaterialsDB> result;

   mysqlx::Table table = sess->getDefaultSchema().getTable("materials");


    mysqlx::RowResult sqlResult = table.select("*").execute();

    for(const auto& elem : sqlResult)
    {
        result.append(MaterialsDB(elem[MaterialsDB::id].get<int>(), QString::fromStdString(elem[MaterialsDB::material].get<std::string>())));
    }


    return result;

}

QVector<InstrumentsDB> DataBase::getTableInstruments()
{
    QVector<InstrumentsDB> result;

    mysqlx::Table table = sess->getDefaultSchema().getTable("instruments");


    mysqlx::RowResult sqlResult = table.select("*").execute();


    for( const auto& elem : sqlResult)
    {
        result.append(InstrumentsDB(elem[InstrumentsDB::id].get<int>(), QString::fromStdString(elem[InstrumentsDB::instrument].get<std::string>())));
    }

    return result;
}



QVector<DrillingMachineDB> DataBase::getTableDrillingMachines()
{
    QVector<DrillingMachineDB> result;

    mysqlx::Table table = sess->getDefaultSchema().getTable("drilling_machines");

    mysqlx::RowResult sqlResult = table.select("*").execute();

    for(const auto& elem : sqlResult)
    {
        result.append(DrillingMachineDB(elem[DrillingMachineDB::id].get<int>(),
                                        QString::fromStdString(elem[DrillingMachineDB::drillingMachine].get<std::string>())));
    }


    return result;
}

std::shared_ptr<TableValueDB> DataBase::getTableValue(int material_id, int instrument_id)
{


    mysqlx::Table table = sess->getDefaultSchema().getTable("table_value");

    mysqlx::RowResult sqlResult = table.select("*").where("material_id = :material_id AND instrument_id = :instrument_id")
                                      .bind("material_id", material_id).bind("instrument_id", instrument_id)
                                      .execute();



    mysqlx::Row row = sqlResult.fetchOne();


    if(row.isNull())
    {
        return nullptr;
    }

    return std::make_shared<TableValueDB>(row[TableValueDB::id].get<int>(), row[TableValueDB::materialId].get<int>(),
                                          row[TableValueDB::instrumentId].get<int>(), row[TableValueDB::Cv].get<float>(),
                                          row[TableValueDB::qv].get<float>(), row[TableValueDB::yv].get<float>(),
                                          row[TableValueDB::mv].get<float>(), row[TableValueDB::Cm].get<float>(),
                                          row[TableValueDB::qm].get<float>(), row[TableValueDB::xm].get<float>(),
                                          row[TableValueDB::ym].get<float>(), row[TableValueDB::Cp].get<float>(),
                                          row[TableValueDB::qp].get<float>(), row[TableValueDB::xp].get<float>(),
                                          row[TableValueDB::yp].get<float>());


}

std::shared_ptr<TValueDB> DataBase::getTValue(int material_id, int instrument_id, int d)
{
    mysqlx::Table table = sess->getDefaultSchema().getTable("t_value");

    mysqlx::RowResult sqlResult = table.select("*").where("material_id = :material_id AND instrument_id = :instrument_id")
                                      .bind("material_id", material_id).bind("instrument_id", instrument_id)
                                      .execute();

    mysqlx::Row row = sqlResult.fetchOne();

    int data{0};

    if(50< d && d <= 60)
    {
        data = TValueDB::D60;
    }
    else if( 40 < d)
    {
        data = TValueDB::D50;
    }
    else if( 30 < d)
    {
        data = TValueDB::D40;
    }
    else if( 20 < d)
    {
        data = TValueDB::D30;
    }
    else if( 10 < d)
    {
        data = TValueDB::D20;
    }
    else if( 5 < d)
    {
        data = TValueDB::D10;

    }
    else if( 0 < d)
    {
        data = TValueDB::D5;
    }

    if(data == 0 || row[data].isNull())
    {
        return nullptr;
    }


    return std::make_shared<TValueDB>(row[TValueDB::id].get<int>(), row[TValueDB::materialId].get<int>(),
                                      row[TValueDB::instrumentId].get<int>(), row[data].get<int>());


}

std::shared_ptr<KmvDB> DataBase::getKmvValue(int material_id)
{
    mysqlx::Table table = sess->getDefaultSchema().getTable("kmv_value");

    mysqlx::RowResult sqlResult = table.select("*").where("material_id = :material_id")
                                      .bind("material_id", material_id)
                                      .execute();

    mysqlx::Row row = sqlResult.fetchOne();

    if(row.isNull())
    {
        return nullptr;
    }


    return std::make_shared<KmvDB>(row[KmvDB::id].get<int>(), row[KmvDB::materialId].get<int>(),
                                   row[KmvDB::kmv].get<float>());


}

std::shared_ptr<PRMDB> DataBase::getPRMValue(int drilling_machine_id)
{
    mysqlx::Table table = sess->getDefaultSchema().getTable("prm");

    mysqlx::RowResult sqlResult = table.select("*").where("drilling_machine_id = :drilling_machine_id")
                                      .bind("drilling_machine_id", drilling_machine_id)
                                      .execute();

    mysqlx::Row row = sqlResult.fetchOne();

    if(row.isNull())
    {
        return nullptr;
    }


    return std::make_shared<PRMDB>(row[PRMDB::id].get<int>(), row[PRMDB::drillingMachineId].get<int>(),
                                   row[PRMDB::minSpeed].get<int>(), row[PRMDB::maxSpeed].get<int>());
}

std::shared_ptr<FeedDB> DataBase::getFeedValue(int material_id, int d)
{
    mysqlx::Table table = sess->getDefaultSchema().getTable("feed");

    mysqlx::RowResult sqlResult = table.select("*").where("material_id = :material_id")
                                      .bind("material_id", material_id)
                                      .execute();

    mysqlx::Row row = sqlResult.fetchOne();

    int data{0};

    if(40< d && d <= 50)
    {
        data = FeedDB::D50;
    }
    else if( 30 < d)
    {
        data = FeedDB::D40;
    }
    else if( 25 < d)
    {
        data = FeedDB::D30;
    }
    else if( 20 < d)
    {
        data = FeedDB::D25;
    }
    else if( 16 < d)
    {
        data = FeedDB::D20;
    }
    else if( 12 < d)
    {
        data = FeedDB::D16;

    }
    else if( 10 < d)
    {
        data = FeedDB::D12;
    }
    else if( 8 < d)
    {
        data = FeedDB::D10;
    }
    else if( 6 < d)
    {
        data = FeedDB::D8;
    }
    else if( 4 < d)
    {
        data = FeedDB::D6;
    }
    else if( 2 < d)
    {
        data = FeedDB::D4;
    }
    else if( 0 < d)
    {
        data = FeedDB::D2;
    }

    if(data == 0 || row[data].isNull())
    {
        return nullptr;
    }


    return std::make_shared<FeedDB>(row[FeedDB::id].get<int>(), row[FeedDB::materialId].get<int>(),
                                    row[data].get<float>());

}

std::shared_ptr<KmpDB> DataBase::getKmpValue(int material_id)
{
    mysqlx::Table table = sess->getDefaultSchema().getTable("kmp_value");

    mysqlx::RowResult sqlResult = table.select("*").where("material_id = :material_id")
                                      .bind("material_id", material_id)
                                      .execute();

    mysqlx::Row row = sqlResult.fetchOne();

    if(row.isNull())
    {
        return nullptr;
    }


    return std::make_shared<KmpDB>(row[KmpDB::id].get<int>(), row[KmpDB::materialId].get<int>(),
                                   row[KmpDB::kmp].get<float>());

}

