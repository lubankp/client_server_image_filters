#pragma once

#include "comunication_client.h"



void send_reply(yami::agent& client_agent, std::string& message_name, const std::string& server_address, yami::parameters& params, int& step) {


	auto message = client_agent.send(server_address, "printer", message_name, params, 0, true);
	message->wait_for_completion();

	const yami::message_state state = message->get_state();

	if (state == yami::replied)
	{
		const yami::parameters& reply = message->get_reply();

		std::string answer_data = reply.get_string(message_name);
		step = reply.get_integer("step");

		std::cout << answer_data << '\n';

	}
	else if (state == yami::rejected)
	{
		std::cout << "The message has been rejected: " << message->get_exception_msg();
	}
	else
	{
		std::cout << "The message has been abandoned.";
	}
}

void run(yami::agent& client_agent, Comunication& comunication, const std::string& server_address, int& step) {
   
    bool end = 0;

    do {
        yami::parameters params;
        std::string message_name;

        switch (step)
        {
        case 0: {
            comunication.init(params);
            message_name = "init";
            send_reply(client_agent, message_name, server_address, params, step);
            break;
        }
        case 1: {
            comunication.chooseImage(params);
            message_name = "image";
            send_reply(client_agent, message_name, server_address, params, step);
            break;
        }
        case 2: {
            comunication.chooseOperation(params);
            message_name = "operation";
            send_reply(client_agent, message_name, server_address, params, step);
            break;
        }
        case 3: {
            comunication.setParametersFrameHorizontal(params);
            message_name = "horizontal";
            send_reply(client_agent, message_name, server_address, params, step);
            break;
        }
        case 4: {
            comunication.setParametersFrameVertical(params);
            message_name = "vertical";
            send_reply(client_agent, message_name, server_address, params, step);
            break;
        }
        case 5: {
            comunication.setParametersTresholdCanal(params);
            message_name = "canal";
            send_reply(client_agent, message_name, server_address, params, step);
            break;
        }
        case 6: {
            comunication.setParametersTresholdValue(params);
            message_name = "treshold";
            send_reply(client_agent, message_name, server_address, params, step);
            break;
        }
        case 7: {
            comunication.execute(params);
            message_name = "execute";
            send_reply(client_agent, message_name, server_address, params, step);
            break;
        }
        default: {
            if (end == 0) {
                std::cout << "END" << std::endl;
                end = 1;
            }
            break;
        }

        }
    } while (true);


}