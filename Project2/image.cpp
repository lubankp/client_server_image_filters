#include "image.h"

void Picture::openPicture(std::string fileName) {

	image_.loadFromFile(fileName);
	
}

void Picture::writePicture(std::string fileName) {

	
	image_.saveToFile(fileName);	
}

void Picture::createPicture(unsigned int width, unsigned int high, sf::Color color) {

	image_.create(width, high, color);
}

void Picture::invertion(){

	
	sf::Color white = sf::Color::White;
	for (int x = 0; x < image_.getSize().x; x++){

		for (int y = 0; y < image_.getSize().y; y++) {

			sf::Color color;
			color.a = white.a;
			color.b = white.b - image_.getPixel(x, y).b;
			color.r = white.r - image_.getPixel(x, y).r;
			color.g = white.g - image_.getPixel(x, y).g;
			
			image_.setPixel(x, y, color);

		}
	}
}