#ifndef MAINALGORITHM_H
#define MAINALGORITHM_H

#include "result.h"
#include "abstractmath.h"
#include "drillingmath.h"
#include <memory>

class MainAlgorithm
{
public:
    MainAlgorithm();

    std::shared_ptr<AbstractMath> getDrillingMath() const;

    void calculate(std::shared_ptr<AbstractMath> algo);

    std::shared_ptr<Result> getResult() const;

private:

    std::shared_ptr<Result> _result;

};

#endif // MAINALGORITHM_H
