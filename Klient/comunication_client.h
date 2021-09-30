
#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include "my_exeption.h"
#include "execute.h"
#include <stdio.h>
#include <WS2tcpip.h>


template<class Parameters>
class comunication_client {

public:

	byte* bytes;

	void init(Parameters& parameters) {

		std::string init = "connected";
		parameters.set_string("init", init);

	}

	void choose_image(Parameters& parameters, picture& picture) {

		std::string image_name;
		std::getline(std::cin, image_name);
		parameters.set_string("image", image_name);

		picture.open_picture(image_name);

		int size = picture.get_size();
		auto width_ = picture.get_size_x();
		auto height_ = picture.get_size_y();
		parameters.set_integer("sizeX", width_);
		parameters.set_integer("sizeY", height_);

		bytes = picture.mat_to_bytes(size);

		parameters.set_integer("size", size);
		parameters.set_binary("picture", bytes, size);

	}

	void choose_operation(Parameters& parameters) {

		std::string operation;
		std::getline(std::cin, operation);
		parameters.set_string("operation", operation);
	}

	void execute(Parameters& parameters) {

		std::string execute = "execute";
		parameters.set_string("execute", execute);
	}

	void to_image(void* pic, int width, int height, picture& picture, int& step)
	{
		try {
			picture.bytes_to_mat((byte*)pic, width, height);

		}
		catch (const my_exceptions& e)
		{
			throw;
		}
	}
};