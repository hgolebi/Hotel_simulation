#ifndef DATA_H
#define DATA_H
#include <iostream>
#include "hotel.h"

class Data
{
    private:
        std::string g_address;
        std::string r_address;
        std::string w_address;
    public:
        Data(std::string guests_address, std::string rooms_address, std::string workers_address);
        void loadGuests(Hotel &h, int num);
        void loadRooms(Hotel &h, int num);
        void loadWorkers(Hotel &h, int num);



};

#endif