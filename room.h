#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include "group_of_guests.h"

class Room
{
    private:
        std::string type;
        int number_of_beds;
        double area;
        double fee;
        bool additional_furniture;
        GroupOfGuests guests;
    public:
        Room(std::string, int, double, double, bool);
        void change_guests(GroupOfGuests guests);
        std::string get_type() const;
        int get_number_of_beds() const;
        double get_area() const;
        double get_fee() const;
        bool get_additional_furniture() const;
};

#endif