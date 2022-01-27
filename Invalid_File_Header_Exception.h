#ifndef INVALID_FILE_HEADER_EXCEPTION_H
#define INVALID_FILE_HEADER_EXCEPTION_H

#include <stdexcept>

class Invalid_File_Header_Exception : public std::invalid_argument
{
    public:
        Invalid_File_Header_Exception(std::string line);
};

#endif