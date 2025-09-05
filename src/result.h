#ifndef RESULT_H
#define RESULT_H

class Result
{
public:
    Result();





    float getT() const;
    void setT(float newT);

    float getS() const;
    void setS(float newS);

    float getNb() const;
    void setNb(float newNb);

    float getVd() const;
    void setVd(float newVd);

    float getM() const;
    void setM(float newM);

    float getPo() const;
    void setPo(float newPo);

    float getTo() const;
    void setTo(float newTo);

private:

    float _t;
    float _s;
    float _nb;
    float _vd;
    float _m;
    float _po;
    float _to;


};

#endif // RESULT_H
