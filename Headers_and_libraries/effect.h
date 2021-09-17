#pragma once
#include "picture.h"

class Effect {

public:
	
	virtual void makeEffect(Picture&) = 0;
	virtual ~Effect() {};
};

