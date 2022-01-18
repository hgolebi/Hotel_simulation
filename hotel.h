#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <vector>
#include "room.h"
#include "worker.h"
#include "group_of_guests.h"

class Hotel
{
    private:
        std::string name;
        std::vector<Room*> rooms;
        std::vector<Worker*> workers;
        std::vector<GroupOfGuests*> guests;
        double capital;
    public:
        Hotel(std::string, std::vector<Room*>, std::vector<Worker*>, std::vector<GroupOfGuests*>, double);
        void simulate();
};

#endif