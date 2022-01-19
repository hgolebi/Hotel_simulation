#include "group_of_guests.h"
#include <algorithm>
#include <iostream>
#include <random>
#include <chrono>


using namespace std;

// pseudo-random number generetor initialization
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 random (seed);

GroupOfGuests::GroupOfGuests(int id, int size, int length_of_accomodation, int cash)
{
    this->id = id;
    this->size = size;
    this->acc_length = length_of_accomodation;
    this->cash = cash;
}

int GroupOfGuests::get_cash() const
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
    if (random() % 2 == 0)
    {
        cout<<"Guests from room "<<get_room_id()<<" decided to give no tip"<<endl;
        return;
    }
    int tip = random() % 21;
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

int GroupOfGuests::order_the_meal()
{
    if (cash < 10)
    {
        cout<<"Guests from room "<<get_room_id()<<" wanted to order a meal but they couldn't aford it"<<endl;
        return 0;
    }
    int cash_spent = random() % 100 + 10;
    if (cash_spent > cash)
    {
        cash_spent = random() % (cash - 10) + 10;
    }
    cout<<"Guests from room "<<get_room_id()<<" ordered meal worth "<<cash_spent<<"$"<<endl;
    cash -= cash_spent;
    return cash_spent;
}

int GroupOfGuests::go_to_the_restaurant()
{
    if (cash < 10)
    {
        cout<<"Guests from room "<<get_room_id()<<" wanted to go to the restaurant but they couldn't aford it"<<endl;
        return 0;
    }
    int cash_spent = random() % 100 + 10;
    if (cash_spent > cash)
    {
        cash_spent = random() % (cash - 10) + 10;
    }
    cout<<"Guests from room "<<get_room_id()<<" went to restaurant and spent "<<cash_spent<<"$"<<endl;
    cash -= cash_spent;
    return cash_spent;
}

void GroupOfGuests::demand_waking_up()
{
    cout<<"Guests from room "<<get_room_id()<<" demanded waking up"<<endl;
}

int GroupOfGuests::go_to_the_casino()
{
    if (cash < 10)
    {
        cout<<"Guests from room "<<get_room_id()<<" wanted to go to the casino but they couldn't aford it"<<endl;
        return 0;
    }
    int profit = random() % cash + 1;
    if (random() % 2 == 0)
    {
        cout<<"Guests from room "<<get_room_id()<<" went to casino and lost "<<profit<<"$"<<endl;
        cash -= profit;
        return profit;
    }
    else
    {
        cout<<"Guests from room "<<get_room_id()<<" went to casino and won "<<profit<<"$"<<endl;
        cash += profit;
        return -profit;
    }
}