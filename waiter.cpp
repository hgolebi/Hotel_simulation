#include "waiter.h"

using namespace std;

Waiter::Waiter(int id, int cash): Worker(id, cash)
{
    salary = 17;
}

void Waiter::work(GroupOfGuests& guests)
{
    cout<<"Waiter "<<id<<" delivered food to guests "<<guests.get_id()<<endl;
}