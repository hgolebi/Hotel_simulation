#include "group_of_guests.h"
#include <algorithm>
#include <iostream>


using namespace std;

GroupOfGuests::GroupOfGuests(int id, int size, int length_of_accomodation, double cash)
{
    this->id = id;
    this->size = size;
    this->acc_length = length_of_accomodation;
    this->cash = cash;
}

double GroupOfGuests::get_cash() const
{
    return this->cash;
}

int GroupOfGuests::get_size() const
{
    return this->size;
}

int GroupOfGuests::get_room_id() const
{
    return this->room_id;
}


void GroupOfGuests::extend_the_time_of_accomodation(int days)
{
    return;
}

void GroupOfGuests::give_tip(Worker& receiver)
{
    srand(0);
    if (std::rand() % 2 == 0)
    {
        cout<<"Guests from room "<<get_room_id()<<" decided to give no tip"<<endl;
        return;
    }
    int tip = std::rand() % 21;
    if (tip > this->cash)
    {
        cout<<"Guests from room "<<get_room_id()<<" decided to give no tip"<<endl;
        return;
    }
    else
    {
        this->cash -= tip;
        cout<<"Guests from room "<<get_room_id()<<" decided to give "<<tip<<"$ to worker "<<receiver.get_id()<<endl;
        receiver.receive_tip(tip);
    }
}