#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>



class Picture {

	sf::Image image_;

public:
	void openPicture(std::string);
	void writePicture(std::string);
	void createPicture(unsigned int, unsigned int, sf::Color);
	sf::Image getImage() { return image_; };

};