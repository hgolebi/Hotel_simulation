#include "waiter.h"

using namespace std;

Waiter::Waiter(int id, int cash): Worker(id, cash)
{
    salary = 17;
    profession = waiter;
}

void Waiter::work(GroupOfGuests& guests)
{
    cout<<"Waiter "<<id<<" delivered food to guests "<<guests.get_id()<<endl;
}