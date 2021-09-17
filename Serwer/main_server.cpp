#include "server.h"
#include <functional>

int main(){

	const std::string server_address = "tcp://localhost:12345";
	
	try
	{

		Server server(server_address);
		server.run();

		// block
		std::string dummy;
		std::cin >> dummy;

	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

}