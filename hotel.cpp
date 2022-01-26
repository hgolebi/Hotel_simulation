#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <random>
#include <chrono>
#include "hotel.h"

using namespace std;

unsigned SEED = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 generator (SEED);

Hotel::Hotel(string name, int capital)
{
    this-> name = name;
    this-> capital = capital;
}

string Hotel::get_name()
{
    return name;
}

int Hotel::get_capital()
{
    return capital;
}

void Hotel::set_time_interval(int time_interval)
{
    this -> time_interval = time_interval;
}

void Hotel::Info()
{
    cout << "LIST OF GUESTS: " << endl;

    for (int i = 0; i < guests.size(); i++) {
        cout << *(guests[i]);
    }

    cout << endl;
    cout << "LIST OF WORKERS: " << endl;

    map<string, vector<Worker*>>::iterator it;
    for (it=workers.begin(); it!=workers.end(); ++it){
       for (int i=0; i<it->second.size(); i++)
           cout << it->first << " " << "ID: " << it->second[i]->get_id() << " "
           << "Cash: $" << it->second[i]->get_cash() << endl;
    }

    cout << endl;
    cout << "LIST OF ROOMS: " << endl;

    for (int i = 0; i < rooms.size(); i++) {
       cout << *(rooms[i]);
    }
    cout << endl;
}

void Hotel::Add_Guests(int id, int size, int acc_length, int cash)
{
    GroupOfGuests* g = new GroupOfGuests(id, size, acc_length, cash);
    guests.push_back(g);
}

void Hotel::Add_Room(int id, std::string type, int number_of_beds, double area, double fee, bool additional_furniture)
{
    Room *r = new Room(id, type, number_of_beds, area, fee, additional_furniture);
    rooms.push_back(r);
}

void Hotel::Add_Worker(string type_of_worker, int id, int cash)
{
    if (type_of_worker == "croupier")
    {
        Croupier *worker = new Croupier(id, cash);
        workers["Croupier"].push_back(worker);
    }
    else if (type_of_worker == "receptionist")
    {
        Receptionist *worker = new Receptionist(id, cash);
        workers["Receptionist"].push_back(worker);
    }
    else if (type_of_worker == "waiter")
    {
        Waiter *worker = new Waiter(id, cash);
        workers["Waiter"].push_back(worker);
    }
    else if (type_of_worker == "room_service")
    {
        RoomService *worker = new RoomService(id, cash);
        workers["Room_service"].push_back(worker);
    }
}

Hotel::~Hotel()
{
    for (auto guest : guests)
        delete guest;
    for (auto room : rooms)
        delete room;
    map<string, vector<Worker*>>::iterator it;
    for (it=workers.begin(); it!=workers.end(); ++it)
        delete &(it->second);
}

void sleep(float seconds){
    clock_t startClock = clock();
    float secondsAhead = seconds * CLOCKS_PER_SEC;
    // do nothing until the elapsed time has passed.
    while(clock() < startClock+secondsAhead);
    return;
}

void Hotel::Accomodation(GroupOfGuests &guests)
{
    for (int i=0; i<rooms.size(); i++)
    {
        if (guests.get_cash() >= rooms[i]->get_fee()*guests.get_acc_length() && guests.get_size() <= rooms[i]->get_number_of_beds())
        {
            // zmniejsz cash
            rooms[i]->change_guests(guests);
            cout << "Guests no. "<<guests.get_id()<<" accomodated in room no. "<<rooms[i]->get_id()<<endl;
            sleep(3);
            return;
        }
    }
}

// Room r = *rooms[generator()%(rooms.size())];
//             if (r.guests == nullptr)

void Hotel::Simulate()
{
    cout << "Welcome to our Hotel" << endl;
    cout << "Hotel will work in the span of " << time_interval << " days" << endl;
    cout << endl;

    for (int i=1; i<=time_interval; i++)
    {
        cout << "======================================" << endl;
        cout << "DAY " << i << endl;
        cout << "======================================" << endl;
        // jesli nie zyja w hotelu to akomoduje
        // a jesli zyja to losujesz jedna metode
        for (auto guest : guests)
        {
            if (guest->get_room_id() == -1)
            {
                Accomodation(*guest);
            }
            int x = generator()%5;
            switch(x)
            {
                case 0:
                {
                    capital += guest->extend_the_time_of_accomodation(generator()%5, rooms[guest->get_room_id()]->get_fee());

                }
                case 1:
                {
                    int cash_spent = guest->order_the_meal();
                    if (cash_spent == 0)
                    {
                        break;
                    }
                    capital += cash_spent;
                    int x = generator()%workers["Room_service"].size();
                    Worker *W = workers["Room_service"][x];
                    W->work(*guest);
                    W->receive_tip(guest->give_tip(W->get_id()));
                }
                case 2:
                {
                    int cash_spent = guest->go_to_the_restaurant();
                    if (cash_spent == 0)
                    {
                        break;
                    }
                    capital += cash_spent;
                    int x = generator()%workers["Waiter"].size();
                    Worker *W = workers["Waiter"][x];
                    W->receive_tip(guest->give_tip(W->get_id()));
                }
                case 3:
                {

                }
                case 4:
                {
                    int cash_spent = guest->go_to_the_casino();
                    if (cash_spent == 0)
                    {
                        break;
                    }
                    capital += cash_spent;
                    int x = generator()%workers["Croupier"].size();
                    Worker *W = workers["Croupier"][x];
                    W->work(*guest);
                    W->receive_tip(guest->give_tip(W->get_id()));
                }
            }
        }
    }

    cout << "Waited 0.5s\n";

    Info();
    rooms[1]->change_guests(*(guests[2]));

    Info();

}