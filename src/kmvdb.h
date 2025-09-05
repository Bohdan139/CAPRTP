#ifndef KMVDB_H
#define KMVDB_H

class KmvDB
{
public:

    enum
    {
        id = 0,
        materialId = 1,
        kmv = 2
    };

    KmvDB(int id, int material_id, float kmv)
        : _id(id), _material_id(material_id), _kmv(kmv)
    {}


    int getId() const;
    int getMaterialid() const;
    float getKmv() const;

private:
    int _id;
    int _material_id;
    float _kmv;
};

#endif // KMVDB_H
