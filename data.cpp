#include "data.h"

using namespace std;

Data::Data(std::string guests_address, std::string rooms_address, std::string workers_address)
{
    g_address = guests_address;
    r_address = rooms_address;
    w_address = workers_address;
}

void Data::loadGuests(Hotel &h, int num)
{
    ifstream fileIn;

    int id;
    int size;
    int accomodation_length;
    int cash;

    fileIn.open(g_address);
    if (!fileIn.good()) {
        cerr << "FILE ERROR";
    }

    string line;
    getline(fileIn, line);
    if (line != "id size acc_length cash")
    {
        cerr << "WRONG FILE HEAD LINE";
    }

    for (int i=0; i<num && !fileIn.eof(); i++)
    {
        fileIn >> id >> size >> accomodation_length >> cash;
        h.Add_Guests(id, size, accomodation_length, cash);
    }

    if ( fileIn.is_open() ) {
        fileIn.close();
    }

    // Test Guests from File
    for (int i = 0; i < num; i++) {
        cout << *(h.guests[i]);
    }
}

void Data::loadRooms(Hotel &h, int num)
{
    ifstream fileIn;

    string type;
    int number_of_beds;
    double area;
    double fee;
    bool additional_furniture;

    fileIn.open(r_address);
    if (!fileIn.good()) {
        cerr << "FILE ERROR";
    }

    string line;
    getline(fileIn, line);
    if (line != "type 	number_of_beds	 area 	fea	 additional_furniture")
    {
        cerr << "WRONG FILE HEAD LINE";
    }

    for (int i=0; i<num && !fileIn.eof(); i++)
    {
        fileIn >> type >> number_of_beds >> area >> fee >> additional_furniture;
        h.Add_Room(type, number_of_beds, area, fee, additional_furniture);
    }

    if ( fileIn.is_open() ) {
        fileIn.close();
    }

    // Test Rooms from File
    for (int i = 0; i < num; i++) {
        cout << "Type: " << h.rooms[i]->get_type() << " "
        << "Number of beds: " << h.rooms[i]->get_number_of_beds() << " "
        << "Area: " << h.rooms[i]->get_area() << " "
        << "Fee: " << h.rooms[i]->get_fee() << " "
        << "Additional furniture: " << h.rooms[i]->get_additional_furniture() << "\n";
    }
}

void Data::loadWorkers(Hotel &h, int num)
{
    ifstream fileIn;

    string type_of_worker;
    int id;
    int cash;

    fileIn.open(w_address);
    if (!fileIn.good()) {
        cerr << "FILE ERROR";
    }

    string line;
    getline(fileIn, line);
    if (line != "type_of_worker 	id 	cash")
    {
        cerr << "WRONG FILE HEAD LINE";
    }

    for (int i=0; i<num && !fileIn.eof(); i++)
    {
        fileIn >> type_of_worker >> id >> cash;
        h.Add_Worker(type_of_worker, id, cash);
    }

    if ( fileIn.is_open() ) {
        fileIn.close();
    }

    // Test Workers from File
    for (int i = 0; i < num; i++) {
        cout << *(h.workers[i]);
    }
}