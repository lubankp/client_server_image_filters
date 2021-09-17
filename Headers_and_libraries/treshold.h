#pragma once
#include "effect.h"


class Treshold : public Effect {

	int canal_;
	int treshold_;

public:

	Treshold(int canal, int treshold) : canal_(canal), treshold_(treshold) {};

	
	void makeEffect(Picture& e_image_) override {

		for (int x = 0; x < e_image_.getSizeX(); x++) {

			for (int y = 0; y < e_image_.getSizeY(); y++) {

				if (e_image_.getPixel(x, y)[0] < treshold_ and canal_ == 98) {
					std::array <int,3> color;

					color[0] = treshold_;
					color[1] = e_image_.getPixel(x, y)[1];
					color[2] = e_image_.getPixel(x, y)[2];

					e_image_.setPixel(x, y, color);
				}
				if (e_image_.getPixel(x, y)[1] < treshold_ and canal_ == 103) {
					std::array<int, 3> color;

					color[0] = e_image_.getPixel(x, y)[0];
					color[1] = treshold_;
					color[2] = e_image_.getPixel(x, y)[2];

					e_image_.setPixel(x, y, color);
				}
				if (e_image_.getPixel(x, y)[2] < treshold_ and canal_ == 114) {
					std::array<int, 3> color;

					color[0] = e_image_.getPixel(x, y)[0];
					color[1] = e_image_.getPixel(x, y)[1];
					color[2] = treshold_;

					e_image_.setPixel(x, y, color);
				}

			}
		}
		
	}
	~Treshold(){};
};