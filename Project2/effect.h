#pragma once
#include "image.h"

class Effect {

	char canal_;
	int treshold_;
	int horizontal_;
	int vertical_;

public:
	
	char* getCanal() { return &canal_; };
	int* getTreshold() { return &treshold_; };
	int* getHorizontal() { return &horizontal_; };
	int* getVertical() { return &vertical_; };
	virtual void makeEffect(Picture&) = 0;
	virtual ~Effect() {};
};

