#include <iostream>
#include <vector>
#include "hotel.h"

Hotel::Hotel(std::string name, std::vector<Room*> rooms, std::vector<Worker*> workers, std::vector<GroupOfGuests*> guests, double capital);
{
    this-> name = name;
    this-> rooms = rooms;
    this-> workers = workers;
    this-> guests = guests;
    this-> capital = capital;
}