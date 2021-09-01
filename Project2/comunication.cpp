#include "yami.h"
#include <memory>
#include "inversion.cpp"
#include "treshold.cpp"
#include "frame.cpp"


class Comunication {


	std::string imageName_;
	std::string operation_;

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

		switch (stoi(operation_)) {
			case 1:
				{std::shared_ptr<Effect> inversion = std::make_shared<Invertion>();
				inversion->makeEffect();
				std::cout << "inversion \n";
				break;
				}
			case 2:
				{std::shared_ptr<Effect> frame = std::make_shared<Frame>();
				frame->makeEffect();
				std::cout << "frame \n";
				break;
				}
			case 3:
				{std::shared_ptr<Effect> treshold = std::make_shared<Treshold>();
				treshold->makeEffect();
				std::cout << "treshold \n";
				break;
				}
		}
		picture.writePicture("C:/Users/p.lubanski/source/repos/CPP Learning2/Project2/obraz3.bmp");
		picture.show();

	}

	~Comunication() {};
};