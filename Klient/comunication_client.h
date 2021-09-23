
#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include "exeption.h"
#include "execute.h"
#include <stdio.h>


template<class T>
class Comunication_client {

	

public:

	byte* bytes;

	void init(T & parameters) {

		std::string init = "connected";
		parameters.set_string("init", init);

	}

	void chooseImage(T & parameters, Picture& picture) {

		std::string imageName;
		std::getline(std::cin, imageName);
		parameters.set_string("image", imageName);
		
		picture.openPicture(imageName);
		
		int size = picture.total() * picture.elemSize();
		auto width_ = picture.getSizeX();
		auto hight_ = picture.getSizeY();
		parameters.set_integer("sizeX", width_);
		parameters.set_integer("sizeY", hight_);

		bytes = picture.matToBytes();

		parameters.set_integer("size", size);
		parameters.set_binary("picture",bytes, size);
		
	}

	void chooseOperation(T & parameters) {

		std::string operation;
		std::getline(std::cin, operation);
		parameters.set_string("operation", operation);
	}

	void execute(T & parameters) {

		std::string execute = "execute";
		parameters.set_string("execute", execute);
	}

	void toImage(void* pic, int width, int hight, Picture& picture)
	{
		try {
			picture.bytesToMat((byte*)pic, width, hight);

		}
		catch (const myExceptions& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
};