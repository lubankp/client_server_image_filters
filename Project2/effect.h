#pragma once
#include "image.h"

class Effect {

public:
	Picture e_image_;
	virtual void makeEffect() = 0;
	virtual ~Effect() {};
};

