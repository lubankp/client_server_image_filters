
#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include "my_exeption.h"
#include "execute.h"
#include <stdio.h>
#include <WS2tcpip.h>


template<class T>
class comunication_client {

	

public:

	byte* bytes;

	void init(T & parameters) {

		std::string init = "connected";
		parameters.set_string("init", init);

	}

	void choose_image(T & parameters, picture& picture) {

		std::string image_name;
		std::getline(std::cin, image_name);
		parameters.set_string("image", image_name);
		
		picture.open_picture(image_name);
		
		int size = picture.total() * picture.elem_size();
		auto width_ = picture.get_size_x();
		auto hight_ = picture.get_size_y();
		parameters.set_integer("sizeX", width_);
		parameters.set_integer("sizeY", hight_);

		bytes = picture.mat_to_bytes();

		parameters.set_integer("size", size);
		parameters.set_binary("picture",bytes, size);
		
	}

	void choose_operation(T & parameters) {

		std::string operation;
		std::getline(std::cin, operation);
		parameters.set_string("operation", operation);
	}

	void execute(T & parameters) {

		std::string execute = "execute";
		parameters.set_string("execute", execute);
	}

	void to_image(void* pic, int width, int hight, picture& picture)
	{
		try {
			picture.bytes_to_mat((byte*)pic, width, hight);

		}
		catch (const my_exceptions& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
};