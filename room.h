#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include "group_of_guests.h"

class Room
{
    private:
        int id;
        std::string type;
        int number_of_beds;
        double area;
        double fee;
        bool additional_furniture;
        GroupOfGuests *guests;
    public:
        Room(int, std::string, int, double, double, bool);
        void change_guests(GroupOfGuests &guests);
        int get_id() const;
        std::string get_type() const;
        int get_number_of_beds() const;
        double get_area() const;
        double get_fee() const;
        bool get_additional_furniture() const;

        friend class Hotel;
        friend ostream& operator<<(ostream& os, Room& r);
};

ostream& operator<<(ostream& os, Room& r);

#endif