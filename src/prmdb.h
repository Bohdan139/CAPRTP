#ifndef PRMDB_H
#define PRMDB_H

class PRMDB
{
public:

    enum
    {
        id =0,
        drillingMachineId = 1,
        minSpeed = 2,
        maxSpeed = 3

    };


    PRMDB(int id, int drilling_machine_id, int min_speed, int max_speed)
        : _id(id), _drilling_machine_id(drilling_machine_id),
        _min_speed(min_speed), _max_speed(max_speed)
    {
    }


    int getId() const;
    int getDrillingMachineId() const;
    int getMinSpeed() const;
    int getMaxSpeed() const;



private:
    int _id;
    int _drilling_machine_id;
    int _min_speed;
    int _max_speed;

};

#endif // PRMDB_H
