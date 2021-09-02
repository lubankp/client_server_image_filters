
#include "effect.h"

class Frame : public Effect {



public:
	void makeEffect(Picture& e_image_) override {
		
		
		std::cout << "Podaj wartosc horyzontalna ramki: \n";
		std::string horizontal;
		bool correct_value = 0;
		int horizontal_int;
		while (!correct_value)
		{
			try {
				std::getline(std::cin, horizontal);
				horizontal_int = std::stoi(horizontal);
				if ((horizontal_int < e_image_.getImage()->getSize().x) and (horizontal_int > 0)) {
					correct_value = true;
				}
				else {
					std::cout << "Podaj wartosc liczbowa z zakresu (0 - " << e_image_.getImage()->getSize().x << ") :\n";
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
				if ((vertical_int < e_image_.getImage()->getSize().y) and (vertical_int > 0)) {
					correct_value1 = true;
				}
				else {
					std::cout << "Podaj wartosc liczbowa z zakresu (0 - " << e_image_.getImage()->getSize().y << ") :\n";
				}
			}
			catch (std::invalid_argument e) {
				std::cout << "Podaj wartosc liczbowa: \n";
			}
		}

		sf::Color white = sf::Color::White;
		int horizontal_s = (e_image_.getImage()->getSize().x - horizontal_int) / 2;
		int horizontal_f = e_image_.getImage()->getSize().x - horizontal_s;
		int vertical_s = (e_image_.getImage()->getSize().y - vertical_int) / 2;
		int vertical_f = e_image_.getImage()->getSize().y - vertical_s;


		for (int x = 0; x < e_image_.getImage()->getSize().x; x++) {

			for (int y = 0; y < e_image_.getImage()->getSize().y; y++) {

				if ((x < horizontal_s or x > horizontal_f) or (y < vertical_s or y > vertical_f)) {

					e_image_.getImage()->setPixel(x, y, white);
				}
			}
		}

	}
	~Frame(){};
};