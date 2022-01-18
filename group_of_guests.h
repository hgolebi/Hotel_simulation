#ifndef GROUP_OF_GUESTS_H
#define GROUP_OF_GUESTS_H
#include "worker.h"

class GroupOfGuests
{
    private:
	    int id;
        int size;           // number of people in the group
	    int acc_length;     // length of accomodation in days
	    double cash;
        int room_id;
    public:
        GroupOfGuests(int id = 0, int size = 1, int length_of_accomodation = 5, double cash = 2000);
        double get_cash() const;
        int get_size() const;
        int get_room_id() const;
        void extend_the_time_of_accomodation(int days);
        void order_the_meal();
        void go_to_the_restaurant();
        void demand_waking_up();
        void go_to_the_casino();
        void give_tip(Worker& receiver);


};

#endif