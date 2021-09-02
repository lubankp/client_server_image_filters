
#include "effect.h"


class Treshold : public Effect {


public:
	void makeEffect(Picture& e_image_) override {
		
		

		sf::Color color;

		for (int x = 0; x < e_image_.getImage()->getSize().x; x++) {

			for (int y = 0; y < e_image_.getImage()->getSize().y; y++) {


				color = e_image_.getImage()->getPixel(x, y);
				if (e_image_.getImage()->getPixel(x, y).r < *getTreshold() and *getCanal() == 'r') {
					color.r = *getTreshold();
				}
				if (e_image_.getImage()->getPixel(x, y).g < *getTreshold() and *getCanal() == 'g') {
					color.g = *getTreshold();
				}
				if (e_image_.getImage()->getPixel(x, y).b < *getTreshold() and *getCanal() == 'b') {
					color.b = *getTreshold();
				}
				e_image_.getImage()->setPixel(x, y, color);

			}
		}
		
	}
	~Treshold(){};
};