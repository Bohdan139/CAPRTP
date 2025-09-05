#ifndef ABSTRACTMATH_H
#define ABSTRACTMATH_H

#include "dbheaders.h"
#include "collector.h"
#include <cmath>


class AbstractMath
{
public:
    AbstractMath() {}


    virtual float calcT(Collector& coll) = 0;
    virtual float calcS(Collector& coll) = 0;
    virtual float calcNb(Collector& coll) = 0;

    virtual float calcVd(Collector& coll) = 0;
    virtual float calcM(Collector& coll) = 0;
    virtual float calcPo(Collector& coll) = 0;
    virtual float calcTo(Collector& coll) = 0;

};

#endif // ABSTRACTMATH_H
