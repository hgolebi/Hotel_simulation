#ifndef WORKER_H
#define WORKER_H
#include <iostream>
#include "group_of_guests.h"

class Worker
{
    public:
    enum Profession
        {
            croupier, room_service, waiter, receptionist
        };

    protected:
        int id;
		int cash;
		int salary;
        Profession profession;

    public:
        Worker(int id, int cash);
        virtual ~Worker();
        int get_id() const;
        int get_cash() const;
        int get_salary() const;
        std::string get_profession() const;
        virtual void work(GroupOfGuests& guests) = 0;
		void get_paid();
        void receive_tip(int tip);
    friend std::ostream& operator<<(std::ostream &os, Worker &w);
};


#endif