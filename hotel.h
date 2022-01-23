#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <vector>
#include "room.h"
#include "worker.h"
#include "group_of_guests.h"
#include "simulation.h"
#include "croupier.h"
#include "receptionist.h"
#include "waiter.h"

using namespace std;

class Hotel : public Simulation
{
    private:
        int time_interval;
        string name;
        vector<GroupOfGuests*> guests;
        vector<Room*> rooms;
        vector<Worker*> workers;
        int capital;
    public:
        Hotel(string, int = 10000000);
        void Info();
        void Add_Room(string, int, double, double, bool);
        void Add_Worker(string, int, int);
        void Add_Guests(int, int, int, int);
        ~Hotel();

        int get_capital();
        void Simulate() override;
        void Read_Guests_From_File(string) override;
        void Read_Rooms_From_File(string) override;
        void Read_Workers_From_File(string) override;
};

#endif