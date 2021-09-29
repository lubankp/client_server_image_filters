#pragma once
#include "picture.h"


class effect {

public:

	virtual void make_effect(picture&) = 0;
	virtual ~effect() {};
};

