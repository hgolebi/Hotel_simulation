#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include "group_of_guests.h"

class Room
{
    private:
        enum rank {};
        int number_of_beds;
        double area;
        double fee;
        bool additional_furniture;
        GroupOfGuests guests;
    public:
        Room(enum, int, double, double, bool, GroupOfGuests);
        void change_number_of_guests();
        void get_cleaned();
        void next_day(); // metoda po upływie dnia aktualizuje length_of_accomodation gości i pobiera opłatę,
        // jeśli goście kończą pobyt
};

#endif