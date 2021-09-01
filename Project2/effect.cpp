#include "effect.h"

Picture Effect::init() {

	std::cout << "Wyberz obraz: \n";
	std::cin >> imageName_;
	Picture picture;

	while (!picture.openPicture("C:/Users/p.lubanski/source/repos/CPP Learning2/Project2/" + imageName_)){
			std::cout << "Niewlasciwa nazwa pliku, podaj inna: \n";
			std::cin >> imageName_;
	}
	return picture;
}
void Effect::chooseOperation(Picture picture) {

	std::cout << "Wyberz operacje (1-inwersja, 2-biala_ramka, 3-tresholding_kanalu): \n";
	std::getline(std::cin, operation_);

	bool correct_oper = false;
	while (!correct_oper) {
		if (operation_ == "1" or operation_ == "2" or operation_ == "3") {
			correct_oper = true;
		}
		else {
			std::cout << "Niewlasciwa nazwa operacji, podaj (1, 2, 3): \n";
			std::getline(std::cin, operation_);
		}
	}

	switch (stoi(operation_)) {
		case 1 : picture.invertion();
			break;
		case 2 : picture.frame();
			break;
		case 3 : picture.tresholding();
			break;
	}
	picture.writePicture("C:/Users/p.lubanski/source/repos/CPP Learning2/Project2/obraz3.bmp");

	
	picture.show();

}