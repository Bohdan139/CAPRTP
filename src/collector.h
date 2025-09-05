#ifndef COLLECTOR_H
#define COLLECTOR_H


#include "dbheaders.h"
#include <QVector>
#include <memory>
#include "database.h"

class Collector
{


protected:
    Collector()
    {}

public:
    Collector(const Collector& coll) = delete;

    void operator=(const Collector& coll) = delete;

    static Collector& getCollector();

    void setMaterialsTable(const QVector<MaterialsDB>& materials);

    void setInstrumentsTable(const QVector<InstrumentsDB>& instruments);

    void setDrillingMachinesTable(const QVector<DrillingMachineDB>& materials);

    void setTableValue(std::shared_ptr<TableValueDB> table_value);

    void setTValue(std::shared_ptr<TValueDB> t_value);

    void setKmv(std::shared_ptr<KmvDB> kmv);

    void setKmp(std::shared_ptr<KmpDB> kmp);

    void setPRM(std::shared_ptr<PRMDB> prm);

    void setRest(std::shared_ptr<RestData> restData);

    void setFeed(std::shared_ptr<FeedDB> feed);


    const QVector<MaterialsDB>& getMaterialsTabel() const;
    const QVector<InstrumentsDB>& getInstrumentsTable() const;
    const QVector<DrillingMachineDB>& getDrillingMachinesTable() const;

    std::shared_ptr<TableValueDB> getTableValue() const;
    std::shared_ptr<TValueDB> getTValue() const;
    std::shared_ptr<KmvDB> getKmvValue() const;
    std::shared_ptr<KmpDB> getKmpValue() const;
    std::shared_ptr<PRMDB> getPRMValue() const;
    std::shared_ptr<FeedDB> getFeed() const;

    std::shared_ptr<RestData> getRestData() const;


private:

    std::shared_ptr<PRMDB> _prm;
    std::shared_ptr<KmvDB> _kmv;
    std::shared_ptr<KmpDB> _kmp;
    std::shared_ptr<TValueDB> _t_value;
    std::shared_ptr<TableValueDB> _table_value;
    std::shared_ptr<FeedDB> _feed;

    QVector<MaterialsDB> _materialsTable;
    QVector<InstrumentsDB> _instrumentsTable;
    QVector<DrillingMachineDB> _drillingMachinesTable;

    std::shared_ptr<RestData> _restData;

};



#endif // COLLECTOR_H
