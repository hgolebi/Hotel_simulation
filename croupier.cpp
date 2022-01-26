#include "croupier.h"

using namespace std;

Croupier::Croupier(int id, int cash): Worker(id, cash)
{
    salary = 23;
    profession = croupier;
}

void Croupier::work(GroupOfGuests& guests)
{
    cout<<"Croupier "<<id<<" served guests no. "<<guests.get_id()<<" in casino"<<endl;
}