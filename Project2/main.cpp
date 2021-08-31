#include "yami.h"
#include <iostream>
#include "image.h"
#include <SFML/Graphics.hpp>

int main() {

	Picture picture;
	
	picture.openPicture("C:/Users/p.lubanski/source/repos/CPP Learning2/Project2/obraz1.bmp");
	Picture picture1;
	//picture.invertion();
	//picture.frame();
	picture.writePicture("C:/Users/p.lubanski/source/repos/CPP Learning2/Project2/obraz3.bmp");
	
	picture.tresholding();
	picture.show();
}