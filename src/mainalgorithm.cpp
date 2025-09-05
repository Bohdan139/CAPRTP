#include "mainalgorithm.h"

MainAlgorithm::MainAlgorithm()
{
    _result = std::make_shared<Result>();
}

std::shared_ptr<AbstractMath> MainAlgorithm::getDrillingMath() const
{
    return std::make_shared<DrillingMath>();
}

void MainAlgorithm::calculate(std::shared_ptr<AbstractMath> algo)
{

    Collector& coll = Collector::getCollector();

    _result->setT(algo->calcT(coll));
    coll.getRestData()->setT(_result->getT());


    _result->setS(algo->calcS(coll));

    _result->setNb(algo->calcNb(coll));

    coll.getRestData()->setN(_result->getNb());

    _result->setVd(algo->calcVd(coll));

    _result->setM(algo->calcM(coll));

    _result->setPo(algo->calcPo(coll));

    _result->setTo(algo->calcTo(coll));


}

std::shared_ptr<Result> MainAlgorithm::getResult() const
{
    return _result;
}
