#include "Invalid_File_Header_Exception.h"
#include <iostream>

Invalid_File_Header_Exception::Invalid_File_Header_Exception(std::string line) :
    std::invalid_argument("Invalid file header: " + line) {}
