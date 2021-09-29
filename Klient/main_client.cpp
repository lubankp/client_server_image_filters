#include "client.h"
#include "yami.h"
#include "UDP_client.h"

int main() {

	const std::string server_address = "tcp://localhost:12345";
	int step = 0;

	try
	{
		//Client for YUMI-4
		client<yami::parameters, yami::agent, yami::message_state> client(server_address, yami::replied, yami::rejected);

		//Client for UDP
	   // Client<parameters, agent, message_state> client(server_address, message_state::replied, message_state::rejected);

		client.run(step);

	}
	catch (const std::exception& e)
	{
		std::cout << "error1: " << e.what() << std::endl;
	}
	std::string key;
	std::getline(std::cin, key);

}
