#pragma once
#include <image.h>
#include <SFML/Graphics.hpp>

enum effect_ {
	invertion,
	frame,
	tresholding
	};

class Effect : Picture {

	std::string imageName_;
	std::string operation_;

public:

	Picture init();
	void chooseOperation(Picture);
	std::string getImageName(){ return imageName_; };
	std::string getOperation() { return operation_; };
};