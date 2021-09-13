#pragma once
#include "comunication_server.h"

Comunication comunication;
	
	void call(yami::incoming_message& im)
	{
			const yami::parameters& params = im.get_parameters();

			std::string answer;
			yami::parameters reply_param;
			std::string message_name = im.get_message_name();
			std::cout << "message_name: " << message_name << std::endl;

			if (message_name == "init")
			{
				answer = params.get_string("init");

				reply_param.set_string("init", comunication.init());
				reply_param.set_integer("step", comunication.step_);
			}

			if (message_name == "image")
			{
				answer = params.get_string("image");
				
				auto mess = comunication.open(answer);
				
				reply_param.set_string("image", mess);
				reply_param.set_integer("step", comunication.step_);
			}

			if (message_name == "operation")
			{
				answer = params.get_string("operation");
				
				auto mess = comunication.createOperationVec(answer);

				reply_param.set_string("operation", mess);
				reply_param.set_integer("step", comunication.step_);
				
			}
			
			if (message_name == "horizontal")
			{
				answer = params.get_string("horizontal");

				auto mess = comunication.horizontal(answer);

				reply_param.set_string("horizontal", mess);
				reply_param.set_integer("step", comunication.step_);
			}

			if (message_name == "vertical")
			{
				answer = params.get_string("vertical");

				auto mess = comunication.vertical(answer);

				reply_param.set_string("vertical", mess);
				reply_param.set_integer("step", comunication.step_);

			}

			if (message_name == "canal")
			{
				answer = params.get_string("canal");

				auto mess = comunication.canal(answer);

				reply_param.set_string("canal", mess);
				reply_param.set_integer("step", comunication.step_);
			}

			if (message_name == "treshold")
			{
				answer = params.get_string("treshold");

				auto mess = comunication.treshold(answer);
				
				reply_param.set_string("treshold", mess);
				reply_param.set_integer("step", comunication.step_);
			}

			if (message_name == "execute")
			{
			
				comunication.finish_vect_ = comunication.chooseOperation();
				comunication.execute_.execute(comunication.finish_vect_, comunication.picture_);
				comunication.getPicture().show();
				reply_param.set_string("execute", "end");
				reply_param.set_integer("step", 8);
			}

			
			std::cout << "get: " << answer << std::endl;
			im.reply(reply_param);
	}
	
