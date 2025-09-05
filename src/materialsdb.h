#ifndef MATERIALSDB_H
#define MATERIALSDB_H

#include "tabledb.h"


class MaterialsDB : public TableDB
{
public:

    enum
    {
        id = 0,
        material = 1
    };



    MaterialsDB(int id, QString materialName)
        : _id(id), _material(materialName)
    {}

    int getId() const override;
    QString getName() const override;


private:

    int _id;
    QString _material;

};

#endif // MATERIALSDB_H
