#include "Invalid_File_Exception.h"
#include <iostream>

Invalid_File_Exception::Invalid_File_Exception(std::string file_name) :
    std::invalid_argument("Nieprawidłowa nazwa pliku: " + file_name) {}
