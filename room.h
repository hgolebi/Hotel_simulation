#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include "guests.h"

class Room
{
    private:
        std::string rank;
        int number_of_beds;
        double area;
        double fee;
        bool additional_furniture;
        Guests guests;
    public:
        Room(std::string, int, double, double, bool, Guests);
        void change_number_of_guests;
        void get_cleaned;
        void next_day; // metoda po upływie dnia aktualizuje length_of_accomodation gości i pobiera opłatę,
        // jeśli goście kończą pobyt
};

#endif