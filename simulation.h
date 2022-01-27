#ifndef SIMULATION_H
#define SIMULATION_H

#include <string>
#include <iostream>
#include <fstream>

#include "group_of_guests.h"

using namespace std;

class Simulation
{
    public:
        virtual void Simulate() = 0;
        virtual void Info() = 0;
        virtual void Add_Room(int, string, int, double, double, bool) = 0;
        virtual void Add_Worker(int, int, int) = 0;
        virtual void Add_Guests(int, int, int, int) = 0;
        virtual void Accomodation(GroupOfGuests &guests) = 0;
        virtual ~Simulation() = 0;
};

#endif