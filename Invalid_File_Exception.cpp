#include "Invalid_File_Exception.h"

Invalid_File_Exception::Invalid_File_Exception(double price_value) :
    std::invalid_argument("Niedodatnia cena biletu: " + std::to_string(price_value)) {}
