#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <chrono>
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
        void Add_Worker(int, int, int);
        void Add_Guests(int, int, int, int);
        void Accomodation(GroupOfGuests &guests);
        ~Hotel();

        string get_name();
        int get_capital();
        void set_time_interval(int time_interval);
        void Simulate() override;

        friend class Data;
};

#endif