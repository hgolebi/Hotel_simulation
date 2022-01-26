#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <vector>
#include <map>
#include "room.h"
#include "worker.h"
#include "group_of_guests.h"
#include "simulation.h"
#include "croupier.h"
#include "receptionist.h"
#include "waiter.h"
#include "room_service.h"

using namespace std;

class Hotel : public Simulation
{
    private:
        int time_interval;
        string name;
        vector<GroupOfGuests*> guests;
        vector<Room*> rooms;
        map<string, vector<Worker*>> workers;
        int capital;
    public:
        Hotel(string, int = 10000000);
        void Info();
        void Add_Room(int, string, int, double, double, bool);
        void Add_Worker(string, int, int);
        void Add_Guests(int, int, int, int);
        ~Hotel();

        string get_name();
        int get_capital();
        void Simulate() override;

        friend class Data;
};

#endif