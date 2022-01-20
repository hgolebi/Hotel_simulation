#ifndef CROUPIER_H
#define CROUPIER_H
#include "worker.h"


class Croupier : public Worker
{
    public:
        Croupier(int id, int cash);
        void work(GroupOfGuests& guests);
};

#endif