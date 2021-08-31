#include "effect.h"

void Effect::init() {

	std::cout << "Wyberz obraz: \n";
	std::cin >> imageName_;

}
void Effect::chooseOperation() {

	std::cout << "Wyberz operacje (1-inwersja, 2-biala_ramka, 3-tresholding_kanalu): \n";
	std::cin >> operation_;

	Picture picture;
	picture.openPicture("C:/Users/p.lubanski/source/repos/CPP Learning2/Project2/" + imageName_);

	switch (operation_) {
		case 1: picture.invertion();
			break;
		case 2: picture.frame();
			break;
		case 3: picture.tresholding();
			break;
	}
	picture.writePicture("C:/Users/p.lubanski/source/repos/CPP Learning2/Project2/obraz3.bmp");

	
	picture.show();

}