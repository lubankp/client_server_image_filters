#pragma once
#include "effect.h"

class frame : public effect {

	int horizontal_;
	int vertical_;

public:

	frame(int horizontal, int vertical) : horizontal_(horizontal), vertical_(vertical) {};

	void make_effect(picture& e_image_) override {
		int horizontal_s;
		int horizontal_f;
		int vertical_s;
		int vertical_f;
			
		if(horizontal_ > e_image_.get_size_x()){
			horizontal_s = e_image_.get_size_x();
			horizontal_f = 0;
		}
		else {
			horizontal_s = horizontal_;
			horizontal_f = e_image_.get_size_x() - horizontal_;
		}
		if (vertical_ > e_image_.get_size_x()) {
			vertical_s = e_image_.get_size_y();
			vertical_f = 0;
		}
		else{
			vertical_s = vertical_;
			vertical_f = e_image_.get_size_y() - vertical_;
		}


		for (int x = 0; x < e_image_.get_size_x(); x++) {

			for (int y = 0; y < e_image_.get_size_y(); y++) {

				if ((x < horizontal_s or x > horizontal_f) or (y < vertical_s or y > vertical_f)) {

					std::array<int, 3> array;
					array[0] = 255;
					array[1] = 255;
					array[2] = 255;

					e_image_.set_pixel(x, y, array);
				}
			}
		}
	}
	~frame() {};
};