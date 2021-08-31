#include "image.h"

void Picture::openPicture(std::string fileName) {

	image_.loadFromFile(fileName);
	
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
	int horizontal;
	std::cin >> horizontal;
	std::cout << "Podaj wartosc wertykalna ramki: \n";
	int vertical;
	std::cin >> vertical;

	sf::Color white = sf::Color::White;
	int horizontal_s = (image_.getSize().x - horizontal)/2;
	int horizontal_f = image_.getSize().x - horizontal_s;
	int vertical_s = (image_.getSize().y - vertical) / 2;
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
	std::cout << "Podaj wartosæ tresholdu (0 - 255): \n";
	int value;
	std::cin >> value;

	sf::Color color;

	for (int x = 0; x < image_.getSize().x; x++) {

		for (int y = 0; y < image_.getSize().y; y++) {


			color = image_.getPixel(x, y);
			if (image_.getPixel(x, y).r < value and canal == 'r') {
				color.r = value;
			}
			if (image_.getPixel(x, y).g < value and canal == 'g') {
				color.g = value;
			}
			if (image_.getPixel(x, y).b < value and canal == 'b') {
				color.b = value;
			}
			image_.setPixel(x, y, color);
			
		}
	}

}