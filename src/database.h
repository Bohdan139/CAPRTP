#ifndef DATABASE_H
#define DATABASE_H

#include "dbheaders.h"
#include <QVector>

#include <mysqlx/xdevapi.h>

class DataBase
{
public:
    DataBase();

    QVector<MaterialsDB> getTableMaterials();
    QVector<InstrumentsDB> getTableInstruments();
    QVector<DrillingMachineDB> getTableDrillingMachines();

    std::shared_ptr<TableValueDB> getTableValue(int material_id, int instrument_id);

    std::shared_ptr<TValueDB> getTValue(int material_id, int instrument_id, int d);
    std::shared_ptr<KmvDB> getKmvValue(int material_id);
    std::shared_ptr<PRMDB> getPRMValue(int drilling_machine_id);
    std::shared_ptr<FeedDB> getFeedValue(int material_id, int d);
    std::shared_ptr<KmpDB> getKmpValue(int material_id);


private:

    std::unique_ptr<mysqlx::Session> sess;
};

#endif // DATABASE_H
