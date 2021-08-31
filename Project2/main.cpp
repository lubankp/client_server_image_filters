#include "yami.h"
#include <iostream>
#include "image.h"
#include <SFML/Graphics.hpp>

int main() {

	Picture picture;
	//picture.createPicture(30u, 30u, sf::Color::Green);
	picture.openPicture("C:/Users/p.lubanski/source/repos/CPP Learning2/Project2/obraz1.bmp");
	Picture picture1;
	picture.invertion();
	picture.writePicture("C:/Users/p.lubanski/source/repos/CPP Learning2/Project2/obraz3.bmp");

	sf::RenderWindow window(sf::VideoMode(picture.getImage().getSize().x, picture.getImage().getSize().y), "Picture");

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
		//window.draw(picture1.getImage());
		window.display();
	}

}