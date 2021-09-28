#pragma once
#include "effect.h"


class treshold : public effect {

	int canal_;
	int treshold_;

public:

	treshold(int canal, int treshold) : canal_(canal), treshold_(treshold) {};

	
	void make_effect(picture& e_image_) override {

		for (int x = 0; x < e_image_.get_size_x(); x++) {

			for (int y = 0; y < e_image_.get_size_y(); y++) {

				if (e_image_.get_pixel(x, y)[0] < treshold_ and canal_ == int('b')) {
					std::array <int,3> color;

					color[0] = treshold_;
					color[1] = e_image_.get_pixel(x, y)[1];
					color[2] = e_image_.get_pixel(x, y)[2];

					e_image_.set_pixel(x, y, color);
				}
				if (e_image_.get_pixel(x, y)[1] < treshold_ and canal_ == int('g')) {
					std::array<int, 3> color;

					color[0] = e_image_.get_pixel(x, y)[0];
					color[1] = treshold_;
					color[2] = e_image_.get_pixel(x, y)[2];

					e_image_.set_pixel(x, y, color);
				}
				if (e_image_.get_pixel(x, y)[2] < treshold_ and canal_ == int('r')) {
					std::array<int, 3> color;

					color[0] = e_image_.get_pixel(x, y)[0];
					color[1] = e_image_.get_pixel(x, y)[1];
					color[2] = treshold_;

					e_image_.set_pixel(x, y, color);
				}

			}
		}
		
	}
	~treshold(){};
};