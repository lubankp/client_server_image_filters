#pragma once
#include "comunication_server.h"


class Server {

	yami::agent server_agent_;
	Comunication_server comunication_;
	const std::string server_address_;

public:

	Server(const std::string server_address) : server_address_(server_address) {

		const std::string resolved_address = server_agent_.add_listener(server_address_);
		std::cout << "The server is listening on " << resolved_address << std::endl;
	};
	
	void run(){

		server_agent_.register_object("printer", *this);
	}

	void operator () (yami::incoming_message& im)
	{
			
			const yami::parameters& params = im.get_parameters();

			std::string answer;
			yami::parameters reply_param;
			std::string message_name = im.get_message_name();
			std::cout << "message_name: " << message_name << std::endl;

			if (message_name == "init")
			{
				answer = params.get_string("init");

				reply_param.set_string("init", comunication_.init());
				reply_param.set_integer("step", comunication_.step_);
			}

			if (message_name == "image")
			{
				answer = params.get_string("image");
				
				auto mess = comunication_.open(answer);
				
				reply_param.set_string("image", mess);
				reply_param.set_integer("step", comunication_.step_);
			}

			if (message_name == "operation")
			{
				answer = params.get_string("operation");
				
				auto mess = comunication_.createOperationVec(answer);

				reply_param.set_string("operation", mess);
				reply_param.set_integer("step", comunication_.step_);
				
			}
			/*
			if (message_name == "horizontal")
			{
				answer = params.get_string("horizontal");

				auto mess = comunication_.horizontal(answer);

				reply_param.set_string("horizontal", mess);
				reply_param.set_integer("step", comunication_.step_);
			}

			if (message_name == "vertical")
			{
				answer = params.get_string("vertical");

				auto mess = comunication_.vertical(answer);

				reply_param.set_string("vertical", mess);
				reply_param.set_integer("step", comunication_.step_);

			}

			if (message_name == "canal")
			{
				answer = params.get_string("canal");

				auto mess = comunication_.canal(answer);

				reply_param.set_string("canal", mess);
				reply_param.set_integer("step", comunication_.step_);
			}

			if (message_name == "treshold")
			{
				answer = params.get_string("treshold");

				auto mess = comunication_.treshold(answer);
				
				reply_param.set_string("treshold", mess);
				reply_param.set_integer("step", comunication_.step_);
			}
			*/
			if (message_name == "execute")
			{
			
				comunication_.finish_vect_ = comunication_.chooseOperation();
				comunication_.execute_.execute(comunication_.finish_vect_, comunication_.picture_);
				comunication_.getPicture().show();
				reply_param.set_string("execute", "end");
				reply_param.set_integer("step", 8);
			}

			
			std::cout << "get: " << answer << std::endl;
			im.reply(reply_param);
	}
};
