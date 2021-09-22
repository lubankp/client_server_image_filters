
#pragma once
#include "yami.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include "exeption.h"
#include "execute.h"
#include <stdio.h>



class Comunication_client {

	

public:

	byte* bytes;
	


	void init(yami::parameters& parameters) {

		std::string init = "connected";
		parameters.set_string("init", init);

	}

	void chooseImage(yami::parameters& parameters, Picture& picture) {

		std::string imageName;
		std::getline(std::cin, imageName);
		parameters.set_string("image", imageName);
		
		picture.openPicture(imageName);
		
		int size = picture.getImage()->total() * picture.getImage()->elemSize();
		auto width_ = picture.getSizeX();
		auto hight_ = picture.getSizeY();
		parameters.set_integer("sizeX", width_);
		parameters.set_integer("sizeY", hight_);

		bytes = picture.matToBytes();

		parameters.set_integer("size", size);
		parameters.set_binary("picture",bytes, size);
		
	}

	void chooseOperation(yami::parameters& parameters) {

		std::string operation;
		std::getline(std::cin, operation);
		parameters.set_string("operation", operation);
	}

	void execute(yami::parameters& parameters) {

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