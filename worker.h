#ifndef WORKER_H
#define WORKER_H
#include <iostream>
#include "group_of_guests.h"

class Worker
{
    protected:
        int id;
		int cash;
		int salary;
    public:
        Worker(int id, int cash);
        virtual ~Worker();
        int get_id() const;
        virtual void work(GroupOfGuests& guests) = 0;
		void get_paid();
        void receive_tip(int tip);

};


#endif