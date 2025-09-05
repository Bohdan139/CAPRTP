#include "drillingmath.h"

DrillingMath::DrillingMath() {}

float DrillingMath::calcT(Collector &coll)
{

    int d = coll.getRestData()->getDDrilling();

    return float(d)/2;
}

float DrillingMath::calcS(Collector &coll)
{
    return coll.getFeed()->getData();
}

float DrillingMath::calcNb(Collector &coll)
{
    auto dV = coll.getTableValue()->getDataV();
    qDebug() << "V0 = " << dV[0];
    qDebug() << "V1 = " << dV[1];
    qDebug() << "V2 = " << dV[2];
    qDebug() << "V3 = " << dV[3];


    float v = (dV[0]*
               std::pow(coll.getRestData()->getDDrilling(), dV[1]) )/
              (std::pow(coll.getTValue()->getData(), dV[3]) *
               std::pow(coll.getFeed()->getData(), dV[2]));

    v = v * coll.getKmvValue()->getKmv();
    qDebug() << "V = " << v;

    float n = (1000 * v)/(3.1415 * float(coll.getRestData()->getDDrilling()));
    qDebug() << "N = " << n;

    if( n < coll.getPRMValue()->getMinSpeed())
    {
        return coll.getPRMValue()->getMinSpeed();
    }
    else if ( n > coll.getPRMValue()->getMaxSpeed())
    {
        return coll.getPRMValue()->getMaxSpeed();
    }
    else
    {
        return n;
    }

}

float DrillingMath::calcVd(Collector &coll)
{
    return (3.1415 * float(coll.getRestData()->getDDrilling())*
            coll.getRestData()->getN())/
           (1000);
}

float DrillingMath::calcM(Collector &coll)
{
    auto m = coll.getTableValue()->getDataM();
    auto d = coll.getRestData()->getDDrilling();
    auto s = coll.getFeed()->getData();
    auto k = coll.getKmpValue()->getKmp();
    qDebug() << "V0 = " << m[0];
    qDebug() << "V1 = " << m[1];
    qDebug() << "V2 = " << m[2];
    qDebug() << "V3 = " << m[3];
    qDebug() << "D = " << d;
    qDebug() << "S = " << s;
    qDebug() << "K = " << k;

    return 10.f* m[0] * std::pow(d, m[1]) * std::pow(s, m[3]) * k;
}

float DrillingMath::calcPo(Collector &coll)
{
    auto p = coll.getTableValue()->getDataP();
    auto d = coll.getRestData()->getDDrilling();
    auto s = coll.getFeed()->getData();
    auto k = coll.getKmpValue()->getKmp();

    return 10.f* p[0] * std::pow(d, p[1]) * std::pow(s, p[3]) * k;
}

float DrillingMath::calcTo(Collector &coll)
{
    auto l = coll.getRestData()->getL() + 0.3 * coll.getRestData()->getDDrilling() + 0.1;
    auto n = coll.getRestData()->getN();
    auto s = coll.getFeed()->getData();

    return l/(n*s);
}



