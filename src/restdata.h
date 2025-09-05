#ifndef RESTDATA_H
#define RESTDATA_H

class RestData
{
public:
    RestData(int d, float l);


    int getDDrilling() const;
    int getDReaming() const;
    float getL() const;
    float getT() const;
    float getN() const;

    void setT(float t);
    void setN(float n);

private:
    float _n{};
    float _t{};
    int _d_drilling{};
    int _d_reaming {};
    float _l{};
};

#endif // RESTDATA_H
