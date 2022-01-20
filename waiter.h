#ifndef WAITER_H
#define WAITER_H
#include "worker.h"

class Waiter : public Worker
{
    public:
        Waiter(int id, int cash);
        void work(GroupOfGuests& guests);
};


#endif