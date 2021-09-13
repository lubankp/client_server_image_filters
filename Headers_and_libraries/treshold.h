
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
					std::vector<int> color;

					color.push_back(treshold_);
					color.push_back(e_image_.getPixel(x, y)[1]);
					color.push_back(e_image_.getPixel(x, y)[2]);

					e_image_.setPixel(x, y, color);
				}
				if (e_image_.getPixel(x, y)[1] < treshold_ and canal_ == 103) {
					std::vector<int> color;

					color.push_back(e_image_.getPixel(x, y)[0]);
					color.push_back(treshold_);
					color.push_back(e_image_.getPixel(x, y)[2]);

					e_image_.setPixel(x, y, color);
				}
				if (e_image_.getPixel(x, y)[2] < treshold_ and canal_ == 114) {
					std::vector<int> color;

					color.push_back(e_image_.getPixel(x, y)[0]);
					color.push_back(e_image_.getPixel(x, y)[1]);
					color.push_back(treshold_);

					e_image_.setPixel(x, y, color);
				}

			}
		}
		
	}
	~Treshold(){};
};