#include "image.h"
#include <string>

bool Picture::openPicture(std::string fileName) {

	return	image_.loadFromFile(fileName);
}

void Picture::writePicture(std::string fileName) {

	
	image_.saveToFile(fileName);	
}

void Picture::createPicture(unsigned int width, unsigned int high, sf::Color color) {

	image_.create(width, high, color);
}

void Picture::invertion(){

	
	sf::Color white = sf::Color::White;
	for (int x = 0; x < image_.getSize().x; x++){

		for (int y = 0; y < image_.getSize().y; y++) {

			sf::Color color;
			color.a = white.a;
			color.b = white.b - image_.getPixel(x, y).b;
			color.r = white.r - image_.getPixel(x, y).r;
			color.g = white.g - image_.getPixel(x, y).g;
			
			image_.setPixel(x, y, color);

		}
	}
}

void Picture::frame() {

	std::cout << "Podaj wartosc horyzontalna ramki: \n";
	std::string horizontal;
	bool correct_value = 0;
	int horizontal_int;
	while (!correct_value)
	{
		try {
			std::getline(std::cin, horizontal);
			horizontal_int = std::stoi(horizontal);
			if ((horizontal_int < image_.getSize().x) and (horizontal_int > 0)) {
				correct_value = true;
			}
			else {
				std::cout << "Podaj wartosc liczbowa z zakresu (0 - " << image_.getSize().x << ") :\n";
			}
		}
		catch(std::invalid_argument e){
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
			if ((vertical_int < image_.getSize().y) and (vertical_int > 0)) {
				correct_value1 = true;
			}
			else {
				std::cout << "Podaj wartosc liczbowa z zakresu (0 - " << image_.getSize().y << ") :\n";
			}
		}
		catch (std::invalid_argument e) {
			std::cout << "Podaj wartosc liczbowa: \n";
		}
	}

	sf::Color white = sf::Color::White;
	int horizontal_s = (image_.getSize().x - horizontal_int)/2;
	int horizontal_f = image_.getSize().x - horizontal_s;
	int vertical_s = (image_.getSize().y - vertical_int) / 2;
	int vertical_f = image_.getSize().y - vertical_s;


	for (int x = 0; x < image_.getSize().x; x++) {

		for (int y = 0; y < image_.getSize().y; y++) {

			if ((x < horizontal_s or x > horizontal_f) or (y < vertical_s or y > vertical_f) ) {

				image_.setPixel(x, y, white);
			}
		}
	}

}

void Picture::show() {

	sf::RenderWindow window(sf::VideoMode(image_.getSize().x, image_.getSize().y), "Picture");
	sf::Texture texture;
	sf::IntRect r1(0, 0, image_.getSize().x, image_.getSize().y);
	texture.loadFromImage(image_, r1);


	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		sf::Sprite sprite(texture);
		window.draw(sprite);
		window.display();
	}

}

void Picture::tresholding() {

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

	for (int x = 0; x < image_.getSize().x; x++) {

		for (int y = 0; y < image_.getSize().y; y++) {


			color = image_.getPixel(x, y);
			if (image_.getPixel(x, y).r < value_int and canal == 'r') {
				color.r = value_int;
			}
			if (image_.getPixel(x, y).g < value_int and canal == 'g') {
				color.g = value_int;
			}
			if (image_.getPixel(x, y).b < value_int and canal == 'b') {
				color.b = value_int;
			}
			image_.setPixel(x, y, color);
			
		}
	}

}