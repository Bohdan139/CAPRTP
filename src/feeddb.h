#ifndef FEEDDB_H
#define FEEDDB_H

#include <array>
class FeedDB
{
public:

    enum
    {
        id = 0,
        materialId = 1,
        D2 = 2,
        D4 = 3,
        D6 = 4,
        D8 = 5,
        D10 = 6,
        D12 = 7,
        D16 = 8,
        D20 = 9,
        D25 = 10,
        D30 = 11,
        D40 = 12,
        D50 = 13
    };

    FeedDB(int id, int material_id, float d)
        : _id(id), _materialId(material_id),
        _data(d)
    {}


    int getId() const;
    int getMaterialId() const;

    float getData() const;

private:
    int _id;
    int _materialId;
    float _data;

};

#endif // FEEDDB_H
