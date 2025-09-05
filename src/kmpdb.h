#ifndef KMPDB_H
#define KMPDB_H

class KmpDB
{
public:

    enum
    {
        id = 0,
        materialId = 1,
        kmp = 2
    };

    KmpDB(int id, int material_id, float kmp)
        : _id(id), _material_id(material_id), _kmp(kmp)
    {}


    int getId() const;
    int getMaterialid() const;
    float getKmp() const;

private:
    int _id;
    int _material_id;
    float _kmp;

};

#endif // KMPDB_H
