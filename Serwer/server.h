#pragma once
#include "comunication_server.h"
#include "effect_factory.h"


template<class Agent, class Incoming_Message, class Parameters>
class server {

	Agent server_agent_;
	comunication_server comunication_;

	const std::string server_address_;

public:

	server(const std::string server_address) : server_address_(server_address) {

		const std::string resolved_address = server_agent_.add_listener(server_address_);
		std::cout << "The server is listening on " << resolved_address << std::endl;
	};

	void init_step(std::string& answer, const Parameters params, Parameters& reply_param) {

		answer = params.get_string("init");

		reply_param.set_string("init", comunication_.init());
		reply_param.set_integer("step", comunication_.step_);

	}

	void image_step(std::string& answer, const Parameters params, Parameters& reply_param) {

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

	void operation_step(std::string& answer, const Parameters params, Parameters& reply_param) {

		answer = params.get_string("operation");

		auto mess = comunication_.create_operation_vec(answer);

		reply_param.set_string("operation", mess);
		reply_param.set_integer("step", comunication_.step_);
	}

	void execute_step(Parameters& reply_param) {

		effect_factory effect_factory_(comunication_.operation_vector_);
		std::vector<std::shared_ptr<effect>> finish_vect_ = effect_factory_.choose_operation();
		execute execute_;
		execute_.execute_fun(finish_vect_, comunication_.picture_);

		reply_param.set_string("execute", "end");
		reply_param.set_integer("step", 4);

		int size = comunication_.picture_.total() * comunication_.picture_.elem_size();
		int width = comunication_.picture_.get_size_x();
		int hight = comunication_.picture_.get_size_y();
		reply_param.set_integer("sizeX", width);
		reply_param.set_integer("sizeY", hight);

		auto byte = comunication_.get_picture().mat_to_bytes();

		reply_param.set_integer("size", size);
		reply_param.set_binary("picture", byte, size);
	}

	void operator () (Incoming_Message& im)
	{

		const Parameters params = im.get_parameters();

		std::string answer;
		Parameters reply_param;
		std::string message_name = im.get_message_name();
		std::cout << "message_name: " << message_name << std::endl;

		if (message_name == "init")
		{
			init_step(answer, params, reply_param);
		}

		if (message_name == "image")
		{
			image_step(answer, params, reply_param);
		}

		if (message_name == "operation")
		{
			operation_step(answer, params, reply_param);
		}

		if (message_name == "execute")
		{
			execute_step(reply_param);
		}

		std::cout << "get: " << answer << std::endl;
		im.reply(reply_param);

	}


	void run() {

		server_agent_.register_object("printer", *this);
	}
};
