#include "room_service.h"


using namespace std;

RoomService::RoomService(int id, int cash): Worker(id, cash)
{
    salary = 18;
    profession = room_service;
}

void RoomService::work(GroupOfGuests& guests)
{
    cout<<"Room service "<<id<<" delivered food to room "<<guests.get_room_id()<<endl;
}

void RoomService::clean_room(int room_id)
{
    cout<<"Room service "<<id<<" cleaned room "<<room_id<<endl;
}