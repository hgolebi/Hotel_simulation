#include <iostream>
#include <vector>
#include "room.h"

Room::Room(std::string type, int number_of_beds, double area, double fee, bool additional_furniture)
{
    this-> type = type;
    this-> number_of_beds = number_of_beds;
    this-> area = area;
    this-> fee = fee;
    this-> additional_furniture = additional_furniture;
}

void Room::change_guests(GroupOfGuests guests)
{
    this -> guests = guests;
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