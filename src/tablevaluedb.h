#ifndef TABLEVALUEDB_H
#define TABLEVALUEDB_H

#include <array>


class TableValueDB
{
public:

    enum
    {
        id = 0,
        materialId = 1,
        instrumentId = 2,
        Cv =3,
        qv = 4,
        yv = 5,
        mv = 6,
        Cm = 7,
        qm = 8,
        xm = 9,
        ym = 10,
        Cp = 11,
        qp = 12,
        xp = 13,
        yp = 14

    };

    TableValueDB(int id, int material_id, int instrument_id, float cv, float qv, float yv, float mv,
                 float cm, float qm, float xm, float ym, float cp, float qp, float xp, float yp)
        : _id(id), _material_id(material_id), _instrument_id(instrument_id),
        _dataV{cv, qv, yv, mv}, _dataM{cm, qm, xm, ym}, _dataP{cp, qp, xp, yp}
    {}


    int getId() const;
    int getMaterialId() const;
    int getInstrumentId() const;

    const std::array<float, 4>& getDataV() const;
    const std::array<float, 4>& getDataM() const;
    const std::array<float, 4>& getDataP() const;


private:

    int _id;
    int _material_id;
    int _instrument_id;

    std::array<float, 4> _dataV;
    std::array<float, 4> _dataM;
    std::array<float, 4> _dataP;


};

#endif // TABLEVALUEDB_H
