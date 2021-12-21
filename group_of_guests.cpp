#include "group_of_guests.h"
#include <algorithm>

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

void GroupOfGuests::extend_the_time_of_accomodation(int days)
{
    this->acc_length += days;
}

double GroupOfGuests::give_tip()
{
    srand(0);
    if (std::rand() % 2 == 0)
    {
        return 0;
    }
    double tip = double(std::rand() % 21);
    if (tip > this->cash)
    {
        return 0;
    }
    else
    {
        this->cash -= tip;
        return tip;
    }
}