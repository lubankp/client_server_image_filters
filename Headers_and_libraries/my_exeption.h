#pragma once
#include <stdexcept>
#include <string>

struct my_exceptions : public std::invalid_argument {

	my_exceptions(std::string const &msg) : std::invalid_argument(msg) {}

};