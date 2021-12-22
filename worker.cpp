#include "worker.h"

Worker::Worker(int id, double cash)
{
    this->id = id;
    this->cash = cash;
}

Worker::~Worker() {};

int Worker::get_id() const
{
    return this->id;
}

void Worker::work() {};

void Worker::get_paid()
{
    cash += salary;
}