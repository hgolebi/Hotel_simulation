#include "receptionist.h"

using namespace std;

Receptionist::Receptionist(int id, int cash): Worker(id, cash)
{
    salary = 20;
    profession = receptionist;
}

void Receptionist::work(GroupOfGuests& guests)
{
    cout<<"Receptionist "<<id<<" called for taxi for guests "<<guests.get_id()<<endl;
}