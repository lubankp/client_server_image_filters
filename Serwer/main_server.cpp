#include "server.h"

int main(){

	const std::string server_address = "tcp://localhost:12345";
	
	try
	{
		yami::agent server_agent;
		


		const std::string resolved_address =
			server_agent.add_listener(server_address);

		std::cout << "The server is listening on "
			<< resolved_address << std::endl;
			
			server_agent.register_object("printer", call);
		

		// block
		std::string dummy;
		std::cin >> dummy;

	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

}