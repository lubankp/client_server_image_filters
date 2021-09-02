#include "yami.h"
#include <memory>
#include "inversion.cpp"
#include "treshold.cpp"
#include "frame.cpp"
#include <vector>


class Comunication {


	std::string imageName_;
	std::string operation_ = "";
	int vertical_int;
	int horizontal_int;
	int value_int;
	std::string canal;

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


	std::vector<std::shared_ptr<Effect>> chooseOperation(Picture picture) {

		std::cout << "Wyberz operacje (1-inwersja, 2-biala_ramka, 3-tresholding_kanalu): \n";
		std::getline(std::cin, operation_);

		bool correct_oper = false;
		std::vector<int> operation_vec;
		std::vector<std::shared_ptr<Effect>> finish_vec;

		while (!correct_oper){
			for (auto element : operation_) {

				switch (element) {
				case '1': operation_vec.push_back(1);
					break;
				case '2': operation_vec.push_back(2);
					break;
				case '3':  operation_vec.push_back(3);
					break;
				}
			}

			if (operation_vec.empty()) {
				std::cout << "Niewlasciwa nazwa operacji, podaj (1, 2, 3): \n";
				std::getline(std::cin, operation_);
			}
			else {
				correct_oper = true;
			}
		}
		
		for (auto element : operation_vec) {
			switch (element) {
				case 1:
				{
					std::shared_ptr<Effect> inversion = std::make_shared<Invertion>();
					finish_vec.push_back(inversion);
					break;
				}
				case 2:
				{
					makeFrameComunication(picture);
					std::shared_ptr<Effect> frame = std::make_shared<Frame>(horizontal_int, vertical_int);
					finish_vec.push_back(frame);
					break;
				}
				case 3:
				{
					makeTresholdComunication();
					std::shared_ptr<Effect> treshold = std::make_shared<Treshold>(canal, value_int);
					finish_vec.push_back(treshold);
					break;
				}
			}
		}
		
		return finish_vec;
	}

	void makeFrameComunication(Picture picture) {

		std::cout << "Podaj wartosc horyzontalna ramki: \n";
		std::string horizontal;
		bool correct_value = 0;

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
	}

	void makeTresholdComunication() {

			std::cout << "Podaj kanal (r, g, b): \n";

			std::getline(std::cin, canal);

			bool correct_canal = false;
			while (!correct_canal) {
				if (canal == "r" or canal == "g" or canal == "b") {
					correct_canal = true;
				}
				else {
					std::cout << "Niewlasciwa nazwa kanalu, podaj (r, g, b): \n";
					std::cin >> canal;
				}
			}

			std::cout << "Podaj wartosc tresholdu (0 - 255): \n";
			std::string value;
			bool correct_value2 = false;

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
	}
	
};