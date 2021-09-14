#pragma once
#include <stdexcept>
#include <string>

struct myExceptions : public std::invalid_argument {

	myExceptions(std::string const &msg) : std::invalid_argument(msg) {}

};