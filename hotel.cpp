#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "hotel.h"

using namespace std;

Hotel::Hotel(string name, int capital)
{
    this-> name = name;
    this-> capital = capital;
}

void Hotel::Info()
{
    return;
}

int Hotel::get_capital()
{
    return capital;
}

void Hotel::Add_Guests(int id, int size, int acc_length, int cash)
{
    GroupOfGuests* g = new GroupOfGuests(id, size, acc_length, cash);
    guests.push_back(g);
}

void Hotel::Add_Room(std::string type, int number_of_beds, double area, double fee, bool additional_furniture)
{
    Room *r = new Room(type, number_of_beds, area, fee, additional_furniture);
    rooms.push_back(r);
}

void Hotel::Add_Worker(string type_of_worker, int id, int cash)
{
    if (type_of_worker == "croupier")
    {
        Croupier *worker = new Croupier(id, cash);
        workers.push_back(worker);
    }
    else if (type_of_worker == "receptionist")
    {
        Receptionist *worker = new Receptionist(id, cash);
        workers.push_back(worker);
    }
    else if (type_of_worker == "waiter")
    {
        Waiter *worker = new Waiter(id, cash);
        workers.push_back(worker);
    }
    else if (type_of_worker == "room_service")
    {
        RoomService *worker = new RoomService(id, cash);
        workers.push_back(worker);
    }
}

void Hotel::Read_Guests_From_File(std::string FileName)
{
    ifstream fileIn;

    int id;
    int size;
    int accomodation_length;
    int cash;

    fileIn.open(FileName.c_str());
    if (!fileIn.is_open()) {
        cout << "Can not read file\n";
    }

    string line;
    getline(fileIn, line);

    while (fileIn >> id >> size >> accomodation_length >> cash) {
        Add_Guests(id, size, accomodation_length, cash);
    }

    if ( fileIn.is_open() ) {
        fileIn.close();
    }

    // Test Guests from File
    for (int i = 0; i < guests.size(); i++) {
        cout << "Id: " << guests[i]->get_id() << " "
        << "Size: " << guests[i]->get_size() << " "
        << "Accomodation length: " << guests[i]->get_acc_length() << " "
        << "Cash: " << guests[i]->get_cash() << "\n";
    }

}

void Hotel::Read_Rooms_From_File(std::string FileName)
{
    ifstream fileIn;

    string type;
    int number_of_beds;
    double area;
    double fee;
    bool additional_furniture;

    fileIn.open(FileName.c_str());
    if (!fileIn.is_open()) {
        cout << "Can not read file\n";
    }

    string line;
    getline(fileIn, line);

    while (fileIn >> type >> number_of_beds >> area >> fee >> additional_furniture) {
        Add_Room(type, number_of_beds, area, fee, additional_furniture);
    }

    if ( fileIn.is_open() ) {
        fileIn.close();
    }

    // Test Rooms from File
    for (int i = 0; i < rooms.size(); i++) {
        cout << "Type: " << rooms[i]->get_type() << " "
        << "Number of beds: " << rooms[i]->get_number_of_beds() << " "
        << "Area: " << rooms[i]->get_area() << " "
        << "Fee: " << rooms[i]->get_fee() << " "
        << "Additional furniture: " << rooms[i]->get_additional_furniture() << "\n";
    }
}

void Hotel::Read_Workers_From_File(std::string FileName)
{
    ifstream fileIn;

    string type_of_worker;
    int id;
    int cash;

    fileIn.open(FileName.c_str());
    if (!fileIn.is_open()) {
        cout << "Can not read file\n";
    }

    string line;
    getline(fileIn, line);

    while (fileIn >> type_of_worker >> id >> cash) {
        Add_Worker(type_of_worker, id, cash);
    }

    if ( fileIn.is_open() ) {
        fileIn.close();
    }

    // Test Workers from File
    for (int i = 0; i < rooms.size(); i++) {
        cout << "id: " << workers[i]->get_id() << " " // tutaj by sie przydalo wypisywac jakos typ workera
        << "Cash: " << workers[i]->get_cash() << "\n";
    }
}

void Hotel::Simulate()
{
    return;
}

Hotel::~Hotel()
{
    return;
}
