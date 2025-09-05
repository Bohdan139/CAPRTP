#include "kmpdb.h"

int KmpDB::getId() const
{
    return _id;
}

int KmpDB::getMaterialid() const
{
    return _material_id;
}

float KmpDB::getKmp() const
{
    return _kmp;
}
