#include "materialsdb.h"



int MaterialsDB::getId() const
{
    return _id;
}

QString MaterialsDB::getName() const
{
    return _material;
}
