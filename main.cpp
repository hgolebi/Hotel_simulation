#include <iostream>
#include <chrono>
#include <random>
#include "hotel.h"
#include "simulation.h"
#include "group_of_guests.h"
#include "data.h"

#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    /*
    argv[1] - time_interval
    argv[2] - Guests
    argv[3] - number_of_guests
    argv[4] - Rooms
    argv[5] - number_of_rooms
    argv[6] - Workers
    argv[7] - number_of_workers
    */

    Hotel hotel("Hotel");

    int time_interval = atoi(argv[1]);
    string g_addr(argv[2]);
    int number_of_guests = atoi(argv[3]);
    string r_addr(argv[4]);
    int number_of_rooms = atoi(argv[5]);
    string w_addr(argv[6]);
    int number_of_workers = atoi(argv[7]);

    // loading files
    Data handle(g_addr, r_addr, w_addr);
    handle.loadGuests(hotel, number_of_guests);
    handle.loadRooms(hotel, number_of_rooms);
    handle.loadWorkers(hotel, number_of_workers);

    hotel.Simulate();

    return 0;
}