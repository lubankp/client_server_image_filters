#include "server.h"
#include "yami.h"
#include <functional>

int main(){
	
	const std::string server_address = "tcp://localhost:12345";
	
	try
	{

		server<yami::agent, yami::incoming_message, yami::parameters> server(server_address);
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