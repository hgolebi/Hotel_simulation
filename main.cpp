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
    cout << hotel.get_capital() << endl;

    return 0;
}