#include "croupier.h"

using namespace std;

Croupier::Croupier(int id, int cash): Worker(id, cash)
{
    salary = 23;
}

void Croupier::work(GroupOfGuests& guests)
{
    cout<<"Croupier "<<id<<" served guests "<<guests.get_id()<<" in casino"<<endl;
}