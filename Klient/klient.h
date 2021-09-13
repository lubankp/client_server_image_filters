#pragma once
#include <iostream>
#include <cstdlib>
#include "klient.h"
#include "yami.h"
#include <string>


class Comunication {


public:

	void init(yami::parameters &parameters) {
	
		std::string init = "connected";
		parameters.set_string("init", init);
	
	}

	void chooseImage(yami::parameters& parameters) {

		std::string imageName;
		std::getline(std::cin, imageName);
		parameters.set_string("image", imageName);
	}

	void chooseOperation(yami::parameters& parameters) {

		std::string operation;
		std::getline(std::cin, operation);
		parameters.set_string("operation", operation);
	}

	void setParametersFrameHorizontal(yami::parameters& parameters) {

		std::string horizontal;
		std::getline(std::cin, horizontal);
		parameters.set_string("horizontal", horizontal);
	}

	void setParametersFrameVertical(yami::parameters& parameters) {

		std::string vertical;
		std::getline(std::cin, vertical);
		parameters.set_string("vertical", vertical);
	}

	void setParametersTresholdCanal(yami::parameters& parameters) {

		std::string canal;
		std::getline(std::cin, canal);
		parameters.set_string("canal", canal);
	}

	void setParametersTresholdValue(yami::parameters& parameters) {

		std::string treshold;
		std::getline(std::cin, treshold);
		parameters.set_string("treshold", treshold);
	}

	void execute(yami::parameters& parameters) {

		std::string execute = "execute";
		parameters.set_string("execute", execute);
	}

};