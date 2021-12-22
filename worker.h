#ifndef WORKER_H
#define WORKER_H

class Worker
{
    protected:
        int id;
		double cash;
		double salary;
    public:
        Worker(int id, double cash);
        virtual ~Worker();
        int get_id() const;
        virtual void work() = 0;
		void get_paid();
};


#endif