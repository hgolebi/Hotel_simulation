#include <iostream>
#include <chrono>
#include <random>
#include "hotel.h"
#include "simulation.h"
#include "group_of_guests.h"

#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    /*unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::mt19937 generator (seed);  // mt19937 is a standard mersenne_twister_engine
    std::cout << "Random value: " << generator() << std::endl; */

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
    string arg1(argv[2]);
    int number_of_guests = atoi(argv[3]);
    string arg2(argv[4]);
    int number_of_rooms = atoi(argv[5]);
    string arg3(argv[6]);
    int number_of_workers = atoi(argv[7]);

    hotel.Read_Guests_From_File(arg1);
    hotel.Read_Rooms_From_File(arg2);
    hotel.Read_Workers_From_File(arg3);

    return 0;
}