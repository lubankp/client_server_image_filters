#pragma once
#include "effect.h"

class Inversion : public Effect {

public:
	void makeEffect(Picture& e_image_) override {

		for (int x = 0; x < e_image_.getSizeX(); x++) {

			for (int y = 0; y < e_image_.getSizeY(); y++) {

				std::vector<int> color;

				color.push_back(255 - e_image_.getPixel(x, y)[0]);
				color.push_back(255 - e_image_.getPixel(x, y)[1]);
				color.push_back(255 - e_image_.getPixel(x, y)[2]);
			
				e_image_.setPixel(x, y, color);
			}
		}
	}
	~Inversion(){};
};