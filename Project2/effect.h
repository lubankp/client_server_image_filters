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
	int operation_;

public:

	void init();
	void chooseOperation();
	std::string getImageName(){ return imageName_; };
	int getOperation() { return operation_; };
};