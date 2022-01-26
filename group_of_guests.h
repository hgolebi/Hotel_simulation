#ifndef GROUP_OF_GUESTS_H
#define GROUP_OF_GUESTS_H
#include <iostream>

using namespace std;

class GroupOfGuests
{
    private:
	    int id;
        int size;           // number of people in the group
	    int acc_length;     // length of accomodation in days
	    int cash;
        int room_id;
    public:
        GroupOfGuests(int id = 0, int size = 0, int acc_length = 0, int cash = 0);
        GroupOfGuests(const GroupOfGuests& source);
        GroupOfGuests& operator=(const GroupOfGuests& source);
        void set_room_id(int room_id);
        void decrease_acc_length(int days = 1);
        int get_id() const;
        int get_cash() const;
        int get_size() const;
        int get_acc_length() const;
        int get_room_id() const;
        int extend_the_time_of_accomodation(int days, int prize);
        int order_the_meal();
        int go_to_the_restaurant();
        void demand_taxi();
        int go_to_the_casino();
        int give_tip(int worker_id);

        bool operator==(const GroupOfGuests& other) const;

    friend ostream& operator<<(ostream& os, GroupOfGuests& g);
};

ostream& operator<<(ostream& os, GroupOfGuests& g);

#endif