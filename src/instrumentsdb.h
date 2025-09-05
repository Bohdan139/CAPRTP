#ifndef INSTRUMENTSDB_H
#define INSTRUMENTSDB_H

#include "tabledb.h"

class InstrumentsDB : public TableDB
{
public:

    enum
    {
        id = 0,
        instrument = 1
    };

    InstrumentsDB(int id, QString instrumentName)
        : _id(id), _instrumentName(instrumentName)
    {}

    int getId() const override;

    QString getName() const override;

private:

    int _id;
    QString _instrumentName;

};

#endif // INSTRUMENTSDB_H
