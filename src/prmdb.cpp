#include "prmdb.h"



int PRMDB::getId() const
{
    return _id;
}

int PRMDB::getDrillingMachineId() const
{
    return _drilling_machine_id;
}

int PRMDB::getMinSpeed() const
{
    return _min_speed;
}

int PRMDB::getMaxSpeed() const
{
    return _max_speed;
}
