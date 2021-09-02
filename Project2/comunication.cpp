#include "yami.h"
#include <memory>
#include "inversion.cpp"
#include "treshold.cpp"
#include "frame.cpp"


class Comunication {


	std::string imageName_;
	std::string operation_ = "";

public:

	Picture init() {

		std::cout << "Wyberz obraz: \n";
		std::cin >> imageName_;
		Picture picture;

		while (!picture.openPicture("C:/Users/p.lubanski/source/repos/CPP Learning2/Project2/" + imageName_)) {
			std::cout << "Niewlasciwa nazwa pliku, podaj inna: \n";
			std::cin >> imageName_;
		}
		return picture;
	}


	void chooseOperation(Picture picture) {

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
		auto choose = std::stoi(operation_);

		switch (choose) {
			case 1:
				{
				std::shared_ptr<Effect> inversion = std::make_shared<Invertion>();
				inversion->makeEffect(picture);
				break;
				}
			case 2:
				{
					std::cout << "Podaj wartosc horyzontalna ramki: \n";
					std::string horizontal;
					bool correct_value = 0;
					int horizontal_int;
					while (!correct_value)
					{
						try {
							std::getline(std::cin, horizontal);
							horizontal_int = std::stoi(horizontal);
							if ((horizontal_int < picture.getImage()->getSize().x) and (horizontal_int > 0)) {
								correct_value = true;
							}
							else {
								std::cout << "Podaj wartosc liczbowa z zakresu (0 - " << picture.getImage()->getSize().x << ") :\n";
							}
						}
						catch (std::invalid_argument e) {
							std::cout << "Podaj wartosc liczbowa: \n";
						}
					}

					std::cout << "Podaj wartosc wertykalna ramki: \n";
					std::string vertical;
					bool correct_value1 = false;
					int vertical_int;
					while (!correct_value1)
					{
						try {
							std::getline(std::cin, vertical);
							vertical_int = std::stoi(vertical);
							if ((vertical_int < picture.getImage()->getSize().y) and (vertical_int > 0)) {
								correct_value1 = true;
							}
							else {
								std::cout << "Podaj wartosc liczbowa z zakresu (0 - " << picture.getImage()->getSize().y << ") :\n";
							}
						}
						catch (std::invalid_argument e) {
							std::cout << "Podaj wartosc liczbowa: \n";
						}
					}

					std::shared_ptr<Effect> frame = std::make_shared<Frame>();
					*(frame->getHorizontal()) = horizontal_int;
					*(frame->getVertical()) = vertical_int;
					frame->makeEffect(picture);
					break;
				}
			case 3:
				{
					std::cout << "Podaj kanal (r, g, b): \n";
					char canal;
					std::cin >> canal;

					bool correct_canal = false;
					while (!correct_canal) {
						if (canal == 'r' or canal == 'g' or canal == 'b') {
							correct_canal = true;
						}
						else {
							std::cout << "Niewlasciwa nazwa kanalu, podaj (r, g, b): \n";
							std::cin >> canal;
						}
					}

					std::cout << "Podaj wartosc tresholdu (0 - 255): \n";
					std::string value;
					std::getline(std::cin, value);
					bool correct_value2 = false;
					int value_int;
					while (!correct_value2)
					{
						try {
							std::getline(std::cin, value);
							value_int = std::stoi(value);
							if ((value_int < 255) and (value_int > 0)) {
								correct_value2 = true;
							}
							else {
								std::cout << "Podaj wartosc liczbowa z zakresu (0 - 255) :\n";
							}
						}
						catch (std::invalid_argument e) {
							std::cout << "Podaj wartosc liczbowa: \n";
						}
					}
					std::shared_ptr<Effect> treshold = std::make_shared<Treshold>();
					*(treshold->getTreshold()) = value_int;
					*(treshold->getCanal()) = canal;
					treshold->makeEffect(picture);
					break;
				}
		}
		picture.writePicture("C:/Users/p.lubanski/source/repos/CPP Learning2/Project2/obraz3.bmp");
		picture.show();
		
	}

};