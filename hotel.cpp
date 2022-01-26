#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <chrono>
#include "hotel.h"

using namespace std;

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
    cout << "LISTA GOŚCI: " << endl;
    for (int i = 0; i < guests.size(); i++) {
        cout << *(guests[i]);
     }
    cout << endl;

    // Test Rooms from File
    // for (int i = 0; i < num; i++) {
    //    cout << "Type: " << h.rooms[i]->get_type() << " "
    //    << "Number of beds: " << h.rooms[i]->get_number_of_beds() << " "
    //    << "Area: " << h.rooms[i]->get_area() << " "
    //    << "Fee: " << h.rooms[i]->get_fee() << " "
    //    << "Additional furniture: " << h.rooms[i]->get_additional_furniture() << "\n";
    // }

    // map<string, vector<Worker*>>::iterator it;
    // Test Workers from File
    // for (it=h.workers.begin(); it!=h.workers.end(); ++it) {
    //    for (int i=0; i<it->second.size(); i++)
    //        cout << it->first << " " << "Id: " << it->second[i]->get_id() << " "
    //        << "Cash: " << it->second[i]->get_cash() << endl;
    // }
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

void Hotel::Simulate()
{
    return;
}