#pragma once
#include "yami.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <memory>
#include "inversion.h"
#include "treshold.h"
#include "frame.h"
#include <vector>
#include <array>
#include "execute.h"
#include "yami.h"

class Comunication {


	std::vector<std::array<int, 3>> operation_vector_;
	int vertical_int;
	int horizontal_int;
	int treshold_;
	int canal_;
	

public:

	Picture picture_;
	std::string imageName_;
	Execute execute_;
	std::vector<std::shared_ptr<Effect>> finish_vect_;
	int step_ = 0;


	std::string init() {

		imageName_ = "Wyberz obraz: \n";
		step_ = 1;
		return imageName_;
	}


	Picture getPicture() {
		return picture_;
	}
	

	std::string open(std::string& imageName) {


		std::string fileName = imageName;
		std::string message = " ";

		if (picture_.openPicture(fileName) == 1) {
			message = "Niewlasciwa nazwa pliku, podaj inna: \n";
		}
		else
		{

			message = "Wyberz operacje (1-inwersja, 2-biala_ramka, 3-tresholding_kanalu, 0-koniec wprowadzania): \n";
			step_ = 2;
		}
		return message;
	}

	std::string createOperationVec(std::string& operation)
	{
		std::string message;
		try {
			int operation_num = std::stoi(operation);
			switch (operation_num) {
			case 1:
			{
				std::array<int, 3> tab = { 1, 0, 0 };
				operation_vector_.push_back(tab);
				message = "Wprowadzono inversje";
				step_ = 2;
				break;
			}
			case 2:
			{
				message = "Podaj wartosc horyzontalna z zakresu (0 - " + std::to_string(picture_.getSizeX()) + " ):";
				step_ = 3;
				break;
			}
			case 3:
			{
				message = "Podaj nazwe kanalu (b, g, r):";
				step_ = 5;
				break;
			}
			case 0:
			{
				message = "Koniec wprowadzania";
				step_ = 7;
				break;
			}
			default:
			{
				message = "Niewlasciwa nazwa operacji, podaj (1, 2, 3, 0):";
				step_ = 2;
			}
			}
		}
		catch (std::invalid_argument e)
		{
			message = "Niewlasciwa nazwa operacji, podaj (1, 2, 3, 0): ";
			step_ = 2;
		}
		return message;
	}
	
	std::string horizontal(std::string & value) {

		std::string message;
		try {
			horizontal_int = std::stoi(value);

				if ((horizontal_int < picture_.getSizeX()) and (horizontal_int > 0)) {


					message = "Podaj wartosc wertykalna z zakresu (0 - " + std::to_string(picture_.getSizeY()) + " ):";
					step_ = 4;
				}
				else {
					message =  "Podaj wartosc liczbowa z zakresu (0 - " + std::to_string(picture_.getSizeX()) + " ):";
					step_ = 3;
				}
			}
			catch (std::invalid_argument e) {
				message = "Error: Podaj wartosc liczbowa z zakresu (0 - " + std::to_string(picture_.getSizeX()) + " ):";
				step_ = 3;
			}
		return message;
	}

	std::string vertical(std::string& value) {

		std::string message;
		try {
			vertical_int = std::stoi(value);

			if ((vertical_int < picture_.getSizeY()) and (vertical_int > 0)) {

				std::array<int, 3> tab1 = { 2, horizontal_int, vertical_int };
				operation_vector_.push_back(tab1);
				message = "Wprowadzono ramke";
				step_ = 2;
			}
			else {
				message = "Podaj wartosc liczbowa z zakresu (0 - " + std::to_string(picture_.getSizeY()) + " ):";
				step_ = 4;
			}
		}
		catch (std::invalid_argument e) {
			message = "Podaj wartosc liczbowa z zakresu (0 - " + std::to_string(picture_.getSizeY()) + " ):";
			step_ = 4;
		}
		return message;
	}

	std::string canal(std::string& canal)
	{
		std::string message;

		if (canal == "r" or canal == "g" or canal == "b") {
			canal_ = (int)canal[0];
			message = "Podaj wartosc tresholdu z zakresu (0 - 255):";
			step_ = 6;
		}
		else {
			message = "Niewlasciwa nazwa kanalu, podaj (r, g, b): \n";
			step_ = 5;
		}
		return message;
	}

	std::string treshold(std::string& value) {

		std::string message;
		try {
			treshold_ = std::stoi(value);


			if ((treshold_ < 255) and (treshold_> 0)) {

				std::array<int, 3> tab1 = { 3, canal_, treshold_ };
				operation_vector_.push_back(tab1);
				message = "Wprowadzono treshold";
				step_ = 2;
			}
			else {
				message = "Podaj wartosc liczbowa z zakresu (0 - 255):";
				step_ = 6;
			}
		}
		catch (std::invalid_argument e) {
			message = "Podaj wartosc liczbowa z zakresu (0 - 255):";
			step_ = 6;
		}
		return message;
	}

	std::vector<std::shared_ptr<Effect>> chooseOperation() {

		std::vector<std::shared_ptr<Effect>> finish_vec;
		;
		for (auto element : operation_vector_) {
			switch (element[0]) {
			case 1:
			{
				std::shared_ptr<Effect> inversion = std::make_shared<Inversion>();
				finish_vec.push_back(inversion);
				break;
			}
			case 2:
			{
				std::shared_ptr<Effect> frame = std::make_shared<Frame>(element[1], element[2]);
				finish_vec.push_back(frame);
				break;
			}
			case 3:
			{
				std::shared_ptr<Effect> treshold = std::make_shared<Treshold>(element[1], element[2]);
				
				Treshold tr(element[1], element[2]);
				
				finish_vec.push_back(treshold);
				break;
			}
			}
		}
		return finish_vec;
	}
};