#include "worker.h"

using namespace std;

Worker::Worker(int id, int cash)
{
    this->id = id;
    this->cash = cash;
}

Worker::~Worker() {};

int Worker::get_id() const
{
    return id;
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