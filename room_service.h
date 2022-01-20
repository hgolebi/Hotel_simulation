#ifndef ROOM_SERVICE_H
#define ROOM_SERVICE_H
#include "worker.h"
#include "room.h"

class RoomService : public Worker
{
    public:
        RoomService(int id, int cash);
        void work(GroupOfGuests& guests);
        void clean_room(int room_id);
};


#endif