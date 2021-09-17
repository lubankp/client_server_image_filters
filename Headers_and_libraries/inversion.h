#pragma once
#include "effect.h"

class Inversion : public Effect {

public:
	void makeEffect(Picture& e_image_) override {

		for (int x = 0; x < e_image_.getSizeX(); x++) {

			for (int y = 0; y < e_image_.getSizeY(); y++) {

				std::array<int, 3> color;

				color[0] = 255 - e_image_.getPixel(x, y)[0];
				color[1] = 255 - e_image_.getPixel(x, y)[1];
				color[2] = 255 - e_image_.getPixel(x, y)[2];
			
				e_image_.setPixel(x, y, color);
			}
		}
	}
	~Inversion(){};
};