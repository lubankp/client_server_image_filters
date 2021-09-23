#pragma once
#include "comunication_server.h"


template<class T, class R, class S>
class Server {

	T server_agent_;
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

	void operator () (R & im)
	{
			
			const S & params = im.get_parameters();

			std::string answer;
			S reply_param;
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
				std::size_t size = params.get_integer("size");
				auto pic = params.get_binary("picture", size);
				auto hight = params.get_integer("sizeY");
				auto width = params.get_integer("sizeX");

				comunication_.get_operation_vector()->clear();
				auto mess = comunication_.open(pic, width, hight);

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
			
			if (message_name == "execute")
			{
			
				comunication_.finish_vect_ = comunication_.chooseOperation();
				comunication_.execute_.execute(comunication_.finish_vect_, comunication_.picture_);

				reply_param.set_string("execute", "end");
				reply_param.set_integer("step", 4);

				int size = comunication_.picture_.getImage()->total() * comunication_.picture_.getImage()->elemSize();
				int width = comunication_.picture_.getSizeX();
				int hight = comunication_.picture_.getSizeY();
				reply_param.set_integer("sizeX", width);
				reply_param.set_integer("sizeY", hight);

				auto byte = comunication_.getPicture().matToBytes();
				
				reply_param.set_integer("size", size);
				reply_param.set_binary("picture", byte, size);

			}

			std::cout << "get: " << answer << std::endl;
			im.reply(reply_param);
	}
};
