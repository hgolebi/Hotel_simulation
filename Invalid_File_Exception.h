#ifndef INVALID_FILE_EXCEPTION_H
#define INVALID_FILE_EXCEPTION_H

#include <stdexcept>
class Invalid_File_Exception : public std::invalid_argument
{
    public:
        Invalid_File_Exception(std::string file_name);
};

#endif
