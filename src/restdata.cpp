#include "restdata.h"

RestData::RestData(int d, float l)
{
    if(d<=30)
    {
        _d_drilling = d;
    }
    else
    {
        _d_drilling = 30;
        _d_reaming = d;
    }

    _l = l;
}

int RestData::getDDrilling() const
{
    return _d_drilling;
}

int RestData::getDReaming() const
{
    return _d_reaming;
}

float RestData::getL() const
{
    return _l;
}

float RestData::getT() const
{
    return _t;
}

float RestData::getN() const
{
    return _n;
}

void RestData::setT(float t)
{
    _t = t;
}

void RestData::setN(float n)
{
    _n = n;
}
