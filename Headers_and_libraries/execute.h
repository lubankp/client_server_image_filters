
#pragma once
#include "picture.h"
#include "effect.h"

class execute {


public:

	void execute_fun(std::vector<std::shared_ptr<effect>>& finish_vect, picture& picture) {
	
		for (const auto &element : finish_vect) {
			element->make_effect(picture);
		}
	}
};