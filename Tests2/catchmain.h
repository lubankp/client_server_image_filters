#include <iostream>
#include "catch.hpp"

int main(int argc, char* argv[]) {

	auto result = Catch::Session().run(argc, argv);
	std::cin.get();
	std::cout << "Returning with result: " << result << std::endl;
	return result;
}