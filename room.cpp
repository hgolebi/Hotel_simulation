#include <iostream>
#include <vector>
#include "room.h"

Room::Room(int id, std::string type, int number_of_beds, int area, int fee, bool additional_furniture)
{
    this-> id = id;
    this-> type = type;
    this-> number_of_beds = number_of_beds;
    this-> area = area;
    this-> fee = fee;
    this-> additional_furniture = additional_furniture;

    this-> guests = nullptr;
}

void Room::change_guests(GroupOfGuests &guests)
{
    this -> guests = &guests;
    guests.set_room_id(id);
}

void Room::checkout()
{
    if (guests == nullptr) {return;}
    else if (guests->get_acc_length() > 0)
    {
        guests->decrease_acc_length();
        return;
    }
    else
    {
        cout<<"Guests no. "<<guests->get_id()<<" checked out of room no. "<<get_id()<<endl;
        guests->set_room_id(-1);
        guests = nullptr;
        return;
    }
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
int Room::get_area() const
{
    return area;
}

int Room::get_fee() const
{
    return fee;
}

bool Room::get_additional_furniture() const
{
    return additional_furniture;
}

ostream& operator<<(ostream& os, Room& r)
{
    if (r.guests != nullptr)
    {
       os << "ID: " << r.get_id() << " " << "Type: " << r.get_type() << " "
       << "Number of beds: " << r.get_number_of_beds() << " "
       << "Area: " << r.get_area() << " "
       << "Fee: " << r.get_fee() << " "
        << "Additional furniture: " << std::boolalpha << r.get_additional_furniture() << "\n"
        << "In this room stays group of guests of id: " << r.guests->get_id() << "\n";
    }
    else
    {
        os << "ID: " << r.get_id() << " " << "Type: " << r.get_type() << " "
       << "Number of beds: " << r.get_number_of_beds() << " "
       << "Area: " << r.get_area() << " "
       << "Fee: " << r.get_fee() << " "
        << "Additional furniture: " << std::boolalpha << r.get_additional_furniture() << "\n "
        << "The room is empty " << "\n";
    }
    return os;
}