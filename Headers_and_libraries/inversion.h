#pragma once
#include "effect.h"

class inversion : public effect {

public:
	void make_effect(picture& e_image_) override {

		for (int x = 0; x < e_image_.get_size_x(); x++) {
			for (int y = 0; y < e_image_.get_size_y(); y++) {

				std::array<int, 3> color;

				color[0] = 255 - e_image_.get_pixel(x, y)[0];
				color[1] = 255 - e_image_.get_pixel(x, y)[1];
				color[2] = 255 - e_image_.get_pixel(x, y)[2];

				e_image_.set_pixel(x, y, color);
			}
		}
	}
	~inversion() {};
};