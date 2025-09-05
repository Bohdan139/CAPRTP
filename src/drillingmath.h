#ifndef DRILLINGMATH_H
#define DRILLINGMATH_H

#include "abstractmath.h"

class DrillingMath : public AbstractMath
{
public:
    DrillingMath();

    float calcT(Collector& coll) override;
    float calcS(Collector& coll) override;
    float calcNb(Collector& coll) override;

    float calcVd(Collector& coll) override;
    float calcM(Collector& coll) override;
    float calcPo(Collector& coll) override;
    float calcTo(Collector& coll) override;
};

#endif // DRILLINGMATH_H
