#ifndef SIMULATION_H
#define SIMULATION_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Simulation
{
    public:
        virtual void Simulate() = 0;
        virtual void Read_Guests_From_File(string) = 0;
        virtual void Read_Rooms_From_File(string) = 0;
        virtual void Read_Workers_From_File(string) = 0;
        virtual ~Simulation() = 0;
};

#endif