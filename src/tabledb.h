#ifndef TABLEDB_H
#define TABLEDB_H
#include <QVector>
#include <QString>
#include <QDebug>



class TableDB
{
public:

    virtual int getId() const = 0;
    virtual QString getName() const  = 0;

    template<typename T>
    static QVector<const TableDB*> convertToBase(const QVector<T>& child)
    {
        QVector<const TableDB*> parent;
        for(auto& elem : child)
        {

            parent.append(static_cast<const TableDB*>(&elem));
        }

        return parent;
    }

};

#endif // TABLEDB_H
