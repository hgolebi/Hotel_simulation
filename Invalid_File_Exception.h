#ifndef INVALID_FILE_EXCEPTION_H
#define INVALID_FILE_EXCEPTION_H

#include <stdexcept>
//Własny typ wyjątku, klasa dziedzicząca po jednym ze standardowych typów wyjątków
class Invalid_File_Exception : public std::invalid_argument
{
    public:
        Invalid_File_Exception(double price_value);
};

#endif
