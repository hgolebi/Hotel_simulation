#include "worker.h"
#include <iomanip>

using namespace std;

Worker::Worker(int id, int cash)
{
    this->id = id;
    this->cash = cash;
    this->salary = 0;
}

Worker::~Worker() {};

int Worker::get_id() const
{
    return id;
}

int Worker::get_cash() const
{
    return cash;
}

int Worker::get_salary() const
{
    return salary;
}

std::string Worker::get_profession() const
{
    string prof[5] = {"croupier", "room_service", "waiter", "receptionist"};
    return prof[profession];
}

void Worker::work(GroupOfGuests& guests) {};

void Worker::get_paid()
{
    this->cash += salary;
}

void Worker::receive_tip(int tip)
{
    this->cash += tip;
}

ostream& operator<<(ostream &os, Worker &w)
{
    os<<"Worker id: "<<w.get_id()<<"\tProfession: "<<setw(15)<<left<<w.get_profession();
    os<<"\tSalary: "<<w.get_salary()<<"$/day"<<"\t\tAvailable cash: "<<w.get_cash()<<"$"<<endl;
    return os;
}

