#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H
#include "worker.h"


class Receptionist : public Worker
{
    public:
        Receptionist(int id, int cash);
        void work(GroupOfGuests& guests);
};

#endif