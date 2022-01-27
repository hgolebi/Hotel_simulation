#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <random>
#include <chrono>
#include "hotel.h"

using namespace std;

void sleep(float seconds){
    clock_t startClock = clock();
    float secondsAhead = seconds * CLOCKS_PER_SEC;
    while(clock() < startClock+secondsAhead);
    return;
}

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
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << setw(25) << right <<"CAPITAL OF THE HOTEL: $" << capital << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;

    sleep(2);

    cout << "LIST OF GUESTS: " << endl;

    for (unsigned i = 0; i < guests.size(); i++) {
        cout << *(guests[i]);
    }

    sleep(2.5);

    cout << endl;
    cout << "LIST OF WORKERS: " << endl;

    map<string, vector<Worker*>>::iterator it;
    for (it=workers.begin(); it!=workers.end(); ++it){
       for (unsigned i=0; i<it->second.size(); i++)
           cout << it->first << " " << "ID: " << it->second[i]->get_id() << " "
           << "Cash: $" << it->second[i]->get_cash() << endl;
    }

    sleep(2.5);

    cout << endl;
    cout << "LIST OF ROOMS: " << endl;

    for (unsigned i = 0; i < rooms.size(); i++) {
       cout << *(rooms[i]);
    }
    cout << endl;

    sleep(2.5);
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

void Hotel::Add_Worker(int type_of_worker, int id, int cash)
{
    if (type_of_worker == 0)
    {
        Croupier *worker = new Croupier(id, cash);
        workers["Croupier"].push_back(worker);
    }
    else if (type_of_worker == 1)
    {
        RoomService *worker = new RoomService(id, cash);
        workers["Room_service"].push_back(worker);
    }
    else if (type_of_worker == 2)
    {
        Waiter *worker = new Waiter(id, cash);
        workers["Waiter"].push_back(worker);
    }
    else if (type_of_worker == 3)
    {
        Receptionist *worker = new Receptionist(id, cash);
        workers["Receptionist"].push_back(worker);
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

void Hotel::Accomodation(GroupOfGuests &guests)
{
    if (guests.get_acc_length() <= 0)
    {
        return;
    }

    Room *r = nullptr;
    for (unsigned i=1; i<rooms.size(); i++)
    {
        if (rooms[i]->guests == nullptr)
        {
            if (guests.get_cash() >= rooms[i]->get_fee()*guests.get_acc_length() && guests.get_size() <= rooms[i]->get_number_of_beds())
            {
                if (r == nullptr)
                {
                    r = rooms[i];
                }
                if (rooms[i]->get_fee() <= r->get_fee())
                {
                    r = rooms[i];
                }
            }
        }
    }
    if (r == nullptr)
    {
        cout << "Guests no. "<<guests.get_id()<<" couldn't find a room for themselves"<<endl;
        return;
    }
    guests.pay(r->get_fee()*guests.get_acc_length());
    capital+=r->get_fee()*guests.get_acc_length();
    r->change_guests(guests);
    cout << "Guests no. "<<guests.get_id()<<" accomodated in room no. "<<r->get_id()<<endl;
    return;
}

void Hotel::Simulate()
{
    cout << "===========================================================" << endl;
    cout << "Welcome to our " << name << ". " << endl;
    cout << "Hotel will work in the span of " << time_interval << " days." << endl;
    cout << "===========================================================" << endl;
    cout << "When you get into a hotel room, you lock the door, and you" << endl;
    cout << "know there is a secrecy, there is a luxury, there is a fantasy" << endl;
    cout << "There is comfort. There is reassurance." << endl;
    cout << "===========================================================" << endl;
    sleep(7);
    cout << endl;

    for (int i=1; i<=time_interval; i++)
    {
        cout << "======================================" << endl;
        cout << "DAY " << i << endl;
        cout << "======================================" << endl;

        sleep(2);

        Info();

        sleep(8);

        for (auto guest : guests)
        {
            if (guest->get_room_id() == -1)
            {
                Accomodation(*guest);
                cout << endl;
                sleep(2);
            }
            else
            {
                int x = generator()%5;
            switch(x)
            {
                case 0:
                {
                    capital += guest->extend_the_time_of_accomodation(generator()%7+1, rooms[guest->get_room_id()]->get_fee());
                    break;
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
                    break;
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
                    W->work(*guest);
                    W->receive_tip(guest->give_tip(W->get_id()));
                    break;
                }
                case 3:
                {
                    bool if_taxi = guest->demand_taxi();
                    if (if_taxi == false)
                    {
                        break;
                    }
                    int x = generator()%workers["Receptionist"].size();
                    Worker *W = workers["Receptionist"][x];
                    W->work(*guest);
                    W->receive_tip(guest->give_tip(W->get_id()));
                    break;
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
                    break;
                }
            }
            cout << endl;
            sleep(5);
            }
        }

        for (auto room : rooms)
        {
            room->checkout();
        }

        sleep(1.5);

        for (auto room: rooms)
        {
            int x = generator()%workers["Room_service"].size();
            Worker *W = workers["Room_service"][x];
            RoomService* worker = dynamic_cast<RoomService*> (W);
            worker->clean_room(room->get_id());
            if (room->guests != nullptr)
            {
                worker->receive_tip(room->guests->give_tip(W->get_id()));
                sleep(2);
            }
        }

        sleep(1.5);

        for (auto worker: workers)
        {
            map<string, vector<Worker*>>::iterator it;
            for (it=workers.begin(); it!=workers.end(); ++it)
            {
                for (unsigned i=0; i<it->second.size(); i++)
                {
                    it->second[i]->get_paid(); // salary
                }
            }
        }
        sleep(5);
    }
    cout << endl;
    cout << "The end of the simulation, everyone dies." << endl;
}