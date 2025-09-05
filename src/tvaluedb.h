#ifndef TVALUEDB_H
#define TVALUEDB_H

#include <array>

class TValueDB
{
public:

    enum
    {
        id = 0,
        materialId = 1,
        instrumentId = 2,
        D5 = 3,
        D10 = 4,
        D20 = 5,
        D30 = 6,
        D40 = 7,
        D50 = 8,
        D60 = 9,
    };

    TValueDB(int id, int material_id, int instrument_id, int d)
        : _id(id), _material_id(material_id), _instrument_id(instrument_id),
        _data(d)
    {}


    int getId() const;
    int getMaterialId() const;

    int getData() const;


private:
    int _id;
    int _material_id;
    int _instrument_id;

    int _data;
};

#endif // TVALUEDB_H
