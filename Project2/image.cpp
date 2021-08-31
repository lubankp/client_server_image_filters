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