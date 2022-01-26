#ifndef DATA_H
#define DATA_H
#include <iostream>
#include "hotel.h"

using namespace std;

class Data
{
    private:
        string g_address;
        string r_address;
        string w_address;
    public:
        Data(string guests_address, string rooms_address, string workers_address);
        void loadGuests(Hotel &h, int num);
        void loadRooms(Hotel &h, int num);
        void loadWorkers(Hotel &h, int num);
};

#endif