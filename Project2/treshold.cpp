
#include "effect.h"


class Treshold : public Effect {

	std::string canal_;
	int treshold_;

public:

	Treshold(std::string canal, int treshold) : canal_(canal), treshold_(treshold) {};

	std::string* getCanal() { return &canal_; };
	int* getTreshold() { return &treshold_; };

	void makeEffect(Picture& e_image_) override {
		sf::Color color;

		for (int x = 0; x < e_image_.getImage()->getSize().x; x++) {

			for (int y = 0; y < e_image_.getImage()->getSize().y; y++) {


				color = e_image_.getImage()->getPixel(x, y);
				if (e_image_.getImage()->getPixel(x, y).r < treshold_ and canal_ == "r") {
					color.r = treshold_;
				}
				if (e_image_.getImage()->getPixel(x, y).g < treshold_ and canal_ == "g") {
					color.g = treshold_;
				}
				if (e_image_.getImage()->getPixel(x, y).b < treshold_ and canal_ == "b") {
					color.b = treshold_;
				}
				e_image_.getImage()->setPixel(x, y, color);

			}
		}
		
	}
	~Treshold(){};
};