#ifndef DRILLINGMACHINEDB_H
#define DRILLINGMACHINEDB_H

#include "tabledb.h"

class DrillingMachineDB : public TableDB
{
public:

    enum
    {
        id = 0,
        drillingMachine = 1
    };


    DrillingMachineDB(int id, QString drillingMachineName)
        : _id(id), _drillingMachineName(drillingMachineName)
    {}


    int getId() const override;
    QString getName() const override;


private:
    int _id;
    QString _drillingMachineName;

};

#endif // DRILLINGMACHINEDB_H
