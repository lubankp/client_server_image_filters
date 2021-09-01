
#include "effect.h"


class Treshold : public Effect {


public:
	void makeEffect() override {
		
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

		sf::Color color;

		for (int x = 0; x < e_image_.getImage().getSize().x; x++) {

			for (int y = 0; y < e_image_.getImage().getSize().y; y++) {


				color = e_image_.getImage().getPixel(x, y);
				if (e_image_.getImage().getPixel(x, y).r < value_int and canal == 'r') {
					color.r = value_int;
				}
				if (e_image_.getImage().getPixel(x, y).g < value_int and canal == 'g') {
					color.g = value_int;
				}
				if (e_image_.getImage().getPixel(x, y).b < value_int and canal == 'b') {
					color.b = value_int;
				}
				e_image_.getImage().setPixel(x, y, color);

			}
		}

	}
	~Treshold(){};
};