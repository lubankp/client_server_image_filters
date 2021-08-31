#include "yami.h"
#include <iostream>
#include "image.h"
#include <SFML/Graphics.hpp>

int main() {

	Picture picture;
	picture.createPicture(30u, 30u, sf::Color::Green);
	picture.writePicture("C:/Users/p.lubanski/source/repos/CPP Learning/Project2/obraz2.bmp");
	
	Picture picture1;
	picture1.openPicture("C:/Users/p.lubanski/source/repos/CPP Learning/Project2/obraz1.bmp");
	picture1.writePicture("C:/Users/p.lubanski/source/repos/CPP Learning/Project2/obraz3.bmp");
}