#include "yami.h"
#include <cstdlib>
#include <string>
#include <iostream>


void call(yami::incoming_message& im)
{
	// extract the parameters for calculations

	const yami::parameters& params = im.get_parameters();

	const int a = params.get_integer("a");
	const int b = params.get_integer("b");

	std::cout << "get: " << a <<", "<< b <<  std::endl;
	yami::parameters reply_param;

	reply_param.set_integer("sum", a + b);
	reply_param.set_integer("difference", a - b);
	reply_param.set_integer("product", a * b);

	if (b != 0){
	reply_param.set_integer("ratio", a / b);
	}

	im.reply(reply_param);
}


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