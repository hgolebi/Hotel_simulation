#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <vector>
#include "room.h"

class Hotel
{
    private:
        std::string name;
        std::vector<*Room> rooms;
        std::vector<*Worker> workers;
        std::vector<*Guests> guests;
        double capital;
    public:
        Hotel(std::string, std::vector<*Room>, std::vector<*Worker>, std::vector<*Guests>, double);
        void simulate();
};

#endif