#include "feeddb.h"

int FeedDB::getId() const
{
    return _id;
}

int FeedDB::getMaterialId() const
{
    return _materialId;
}

float FeedDB::getData() const
{
    return _data;
}
