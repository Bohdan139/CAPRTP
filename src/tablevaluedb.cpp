#include "tablevaluedb.h"


int TableValueDB::getId() const
{
    return _id;
}

int TableValueDB::getMaterialId() const
{
    return _material_id;
}

int TableValueDB::getInstrumentId() const
{
    return _instrument_id;
}

const std::array<float, 4> &TableValueDB::getDataV() const
{
    return _dataV;
}

const std::array<float, 4> &TableValueDB::getDataM() const
{
    return _dataM;
}

const std::array<float, 4> &TableValueDB::getDataP() const
{
    return _dataP;
}
