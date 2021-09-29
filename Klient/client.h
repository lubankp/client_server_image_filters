#pragma once

#include "comunication_client.h"


template<class R, class S, class T>
class client {

	S client_agent_;
	comunication_client<R> comunication_;
	const std::string server_address_;
	picture picture_;
	std::size_t size_;
	int width_;
	int hight_;
	T replied_;
	T rejected_;


public:

	void* byte_;
	client(const std::string& server_address, T replied, T rejected) : server_address_(server_address), replied_(replied), rejected_(rejected) {};

	void run(int& step) {

		bool end = 0;

		do {
			R params;
			std::string message_name;

			switch (step)
			{
			case 0: {
				comunication_.init(params);
				message_name = "init";
				send_reply(message_name, params, step);
				break;
			}
			case 1: {
				//  comunication_.chooseImage(command, picture_);
				//  to_yami_params(command, params);
				comunication_.choose_image(params, picture_);
				message_name = "image";
				send_reply(message_name, params, step);
				
				break;
			}
			case 2: {
				
				comunication_.choose_operation(params);
				message_name = "operation";
				send_reply(message_name, params, step);
				break;
			}
			case 3: {
				comunication_.execute(params);
				message_name = "execute";
				send_reply(message_name, params, step);
				break;
			}
			case 4: {

				comunication_.to_image(byte_, width_, hight_, picture_);
				picture_.show();

				break;
			}
			default: {
				break;
			}

			}
		} while (true);
	}


	void send_reply(std::string& message_name, R& params, int& step) {

		auto message = client_agent_.send(server_address_, "printer", message_name, params, 0, true);

		message->wait_for_completion();

		try {
			const T state = message->get_state();

			if (state == replied_)
			{
				const R& reply = message->get_reply();

				std::string answer_data = reply.get_string(message_name);
				step = reply.get_integer("step");

				std::cout << answer_data << '\n';

				if (step == 4) {

					hight_ = reply.get_integer("sizeY");
					width_ = reply.get_integer("sizeX");
					size_ = reply.get_integer("size");
					auto tmp = reply.get_binary("picture", size_);
					byte_ = (void*)(new byte[size_]);
					memcpy(byte_, tmp, size_);
				}

			}
			else if (state == rejected_)
			{
				std::cout << "The message has been rejected: " << message->get_exception_msg();
			}
			else
			{
				std::cout << "The message has been abandoned.";
			}

		}
		catch (const std::exception& e)
		{
			std::cout << "Brak odpowiedzi" << std::endl;
		}

	}
};
