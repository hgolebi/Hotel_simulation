#include <iostream>
#include <vector>
#include "room.h"

Room::Room(int id, std::string type, int number_of_beds, double area, double fee, bool additional_furniture)
{
    this-> id = id;
    this-> type = type;
    this-> number_of_beds = number_of_beds;
    this-> area = area;
    this-> fee = fee;
    this-> additional_furniture = additional_furniture;

    GroupOfGuests g;
    this-> guests = g;
}

void Room::change_guests(GroupOfGuests &guests)
{
    this -> guests = guests;
}

int Room::get_id() const
{
    return id;
}

std::string Room::get_type() const
{
    return type;
}

int Room::get_number_of_beds() const
{
    return number_of_beds;
}
double Room::get_area() const
{
    return area;
}

double Room::get_fee() const
{
    return fee;
}

bool Room::get_additional_furniture() const
{
    return additional_furniture;
}

ostream& operator<<(ostream& os, Room& r)
{
    GroupOfGuests g;
    if ((r.guests == g) != true)
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