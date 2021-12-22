#include <iostream>
#include <vector>
#include "room.h"

Room::Room(enum rank, int number_of_beds, double area, double fee, bool additional_furniture, Guests guests);
{
    this-> rank = rank;
    this-> number_of_beds = number_of_beds;
    this-> area = area;
    this-> fee = fee;
    this-> additional_furniture = additional_furniture;
    this-> Guests = guests;
}