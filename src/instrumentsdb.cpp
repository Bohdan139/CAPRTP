#include "instrumentsdb.h"



int InstrumentsDB::getId() const
{
    return _id;
}

QString InstrumentsDB::getName() const
{
    return _instrumentName;
}
