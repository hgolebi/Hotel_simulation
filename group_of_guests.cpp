#include "group_of_guests.h"
#include "hotel.h"
#include <algorithm>
#include <iostream>
#include <random>
#include <chrono>

using namespace std;

// pseudo-random number generetor initialization
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 random (seed);

GroupOfGuests::GroupOfGuests(int id, int size, int acc_length, int cash)
{
    this->id = id;
    this->size = size;
    this->acc_length = acc_length;
    this->cash = cash;
    this->room_id = -1;
}

GroupOfGuests::GroupOfGuests(const GroupOfGuests& source)
{
    id = source.id;
    size = source.size;
    acc_length = source.acc_length;
    cash = source.cash;
    room_id = source.room_id;
}

GroupOfGuests& GroupOfGuests::operator=(const GroupOfGuests& source)
{
    if(this != &source)
    {
        id = source.id;
        size = source.size;
        acc_length = source.acc_length;
        cash = source.cash;
        room_id = source.room_id;
    }
    return *this;
}

void GroupOfGuests::set_room_id(int room_id)
{
    this->room_id = room_id;
}

void GroupOfGuests::decrease_acc_length(int days = 1)
{
    acc_length -= days;
}

int GroupOfGuests::get_id() const
{
    return this->id;
}

int GroupOfGuests::get_cash() const
{
    return this->cash;
}

int GroupOfGuests::get_size() const
{
    return this->size;
}

int GroupOfGuests::get_acc_length() const
{
    return this->acc_length;
}

int GroupOfGuests::get_room_id() const
{
    return this->room_id;
}

int GroupOfGuests::extend_the_time_of_accomodation(int days, int prize)
{
    while(days > 0 && cash < days*prize )
    {
        days--;
    }
    if (days <= 0)
    {
        cout<<"Guests no. "<<get_id()<<" from room "<<get_room_id()<<" wanted to extend their stay but they couldn't afford it"<<endl;
        return 0;
    }
    else
    {
        cout<<"Guests no. "<<get_id()<<" from room "<<get_room_id()<<" decided to extend their stay by "<<days<<" days"<<endl;
        cash -= days*prize;
        return days*prize;
    }
}

int GroupOfGuests::give_tip(int worker_id)
{
    if (random() % 2 == 0)
    {
        cout<<"Guests no. "<<get_id()<<" from room "<<get_room_id()<<" decided to give no tip"<<endl;
        return 0;
    }
    int tip = random() % 21;
    if (tip > this->cash)
    {
        cout<<"Guests no. "<<get_id()<<" from room "<<get_room_id()<<" decided to give no tip"<<endl;
        return 0;
    }
    else
    {
        this->cash -= tip;
        cout<<"Guests no. "<<get_id()<<" from room "<<get_room_id()<<" decided to give "<<tip<<"$ to worker "<<worker_id<<endl;
        return tip;
    }
}

int GroupOfGuests::order_the_meal()
{
    if (cash < 10)
    {
        cout<<"Guests no. "<<get_id()<<" from room "<<get_room_id()<<" wanted to order a meal but they couldn't afford it"<<endl;
        return 0;
    }
    int cash_spent = random() % 100 + 10;
    if (cash_spent > cash)
    {
        cash_spent = random() % (cash - 10) + 10;
    }
    cout<<"Guests no. "<<get_id()<<" from room "<<get_room_id()<<" ordered meal worth "<<cash_spent<<"$"<<endl;
    cash -= cash_spent;
    return cash_spent;
}

int GroupOfGuests::go_to_the_restaurant()
{
    if (cash < 10)
    {
        cout<<"Guests no. "<<get_id()<<" from room "<<get_room_id()<<" wanted to go to the restaurant but they couldn't afford it"<<endl;
        return 0;
    }
    int cash_spent = random() % 100 + 10;
    if (cash_spent > cash)
    {
        cash_spent = random() % (cash - 10) + 10;
    }
    cout<<"Guests no. "<<get_id()<<" from room "<<get_room_id()<<" went to restaurant and spent "<<cash_spent<<"$"<<endl;
    cash -= cash_spent;
    return cash_spent;
}

void GroupOfGuests::demand_taxi()
{
    if (cash < 10)
    {
        cout<<"Guests no. "<<get_id()<<" from room "<<get_room_id()<<" wanted to call for taxi but they couldn't afford it"<<endl;
    }
    int cash_spent = random() % 100 + 10;
    if (cash_spent > cash)
    {
        cash_spent = random() % (cash - 10) + 10;
    }
    cout<<"Guests no. "<<get_id()<<" from room "<<get_room_id()<<" want hotel receptionist to call for a taxi "<<endl;
    cout<<"This course will cost them "<<cash_spent<<"$"<<endl;
    cash -= cash_spent;
}

int GroupOfGuests::go_to_the_casino()
{
    if (cash < 10)
    {
        cout<<"Guests no. "<<get_id()<<" from room "<<get_room_id()<<" wanted to go to the casino but they couldn't afford it"<<endl;
        return 0;
    }
    int profit = random() % cash + 1;
    if (random() % 2 == 0)
    {
        cout<<"Guests no. "<<get_id()<<" from room "<<get_room_id()<<" went to casino and lost "<<profit<<"$"<<endl;
        cash -= profit;
        return profit;
    }
    else
    {
        cout<<"Guests no. "<<get_id()<<" from room "<<get_room_id()<<" went to casino and won "<<profit<<"$"<<endl;
        cash += profit;
        return -profit;
    }
}

bool GroupOfGuests::operator==(const GroupOfGuests& other) const
{
    if (id == other.id && size == other.size && acc_length == other.acc_length && cash == other.cash && room_id == other.room_id)
    {
        return true;
    }
    return false;
}


ostream& operator<<(ostream& os, GroupOfGuests& g)
{
    if (g.room_id > 0)
    {
        os<<"Group no. "<<g.get_id()<<" consisting of "<<g.get_size()<<" people stays in room "<<g.get_room_id()<<"."<<endl;
        os<<"Staying for: "<<g.get_acc_length()<<" day(s). Available cash: "<<g.get_cash()<<"$"<<endl;
    }
    else
    {
        os<<"Group no. "<<g.get_id()<<" consisting of "<<g.get_size()<<" people isn't staying in this hotel."<<endl;
        os<<"Available cash: "<<g.get_cash()<<"$"<<endl;
    }
    return os;
}