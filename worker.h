#ifndef WORKER_H
#define WORKER_H
#include <iostream>

class Worker
{
    protected:
        int id;
		int cash;
		double salary;
    public:
        Worker(int id, int cash);
        virtual ~Worker();
        int get_id() const;
        virtual void work() = 0;
		void get_paid();
        void receive_tip(int tip);

};


#endif