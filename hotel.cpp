#include <iostream>
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
            rooms[i]->change_guests(guests);
            cout << "Guests no. "<<guests.get_id()<<" accomodated in room no. "<<rooms[i]->get_id()<<endl;
        }
    }
}

//     if (guests.get_room_id() == -1) // don't have a room

// Room r = *rooms[generator()%(rooms.size())];
//             if (r.guests == nullptr)

void Hotel::Simulate()
{
    cout << "Welcome to our Hotel" << endl;
    sleep(0.5);
    cout << "Waited 0.5s\n";

    Info();
    rooms[1]->change_guests(*(guests[2]));

    Info();

}