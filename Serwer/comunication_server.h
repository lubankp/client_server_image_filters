#pragma once
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


class comunication_server {


	std::vector<std::array<int, 3>> operation_vector_;
	int vertical_int;
	int horizontal_int;
	int treshold_;
	int canal_;
	

public:

	picture picture_;
	std::string image_name_;
	execute execute_;
	std::vector<std::shared_ptr<effect>> finish_vect_;
	int step_ = 0;


	std::string init() {

		image_name_ = "Wyberz obraz: \n";
		step_ = 1;
		return image_name_;
	}


	picture get_picture() {
		return picture_;
	}
	
	std::vector<std::array<int, 3>>* get_operation_vector() { return &operation_vector_; }


	std::string open(const void * pic, int width, int hight) {

		std::string message = " ";
		try{
			picture_.bytes_to_mat((byte*)pic, width, hight);

			message = "Wyberz operacje (I-inwersja, R(horyzontalna,wertykalna)-biala_ramka, C(kanal,treshold)-tresholding_kanalu, 0-koniec wprowadzania): \n";
			step_ = 2;
		}
		catch (const my_exceptions& e)
		{
			message = e.what();
		}
		return message;
	}

	std::string create_operation_vec(std::string& operation)
	{
		std::string message;

		try {
			
			switch (operation[0]) {
			case 'I':
			{
				std::array<int, 3> tab = { 1, 0, 0 };
				operation_vector_.push_back(tab);
				message = "Wprowadzono inversje";
				step_ = 2;
				break;
			}
			case 'R':
			{
				std::string horizontal;
				std::string vertical;
				std::string horizontal_temp;
				std::string vertical_temp;

				std::size_t found1 = operation.find_first_of("-1234567890");
				std::size_t found2 = operation.find(",");
 
				if (found1 != std::string::npos and found2 != std::string::npos)
				{
					horizontal_temp = operation.substr(found1);
					horizontal.assign(horizontal_temp.begin(), horizontal_temp.end() - found2);
					vertical_temp = operation.substr(found2 + 1);
					vertical.assign(vertical_temp.begin(), vertical_temp.end() - 1);
					
					horizontal_int = std::stoi(horizontal);
					vertical_int = std::stoi(vertical);
					std::cout << horizontal_int << std::endl;
					std::cout << vertical_int << std::endl;

					if ((horizontal_int > picture_.get_size_x()) or (horizontal_int < 0)) {

						message = "Podaj wartosc liczbowa horyzontalna z zakresu (0 - " + std::to_string(picture_.get_size_x()) + " ):";
						
					}else if ((vertical_int > picture_.get_size_y()) or (vertical_int < 0)) {

						message = "Podaj wartosc liczbowa wertykalna z zakresu (0 - " + std::to_string(picture_.get_size_y()) + " ):";
					
					}else 
					{ 
						std::array<int, 3> tab1 = { 2, horizontal_int, vertical_int };
						operation_vector_.push_back(tab1);
						message = "Wprowadzono ramke";
					}
				}
				else
				{
					message = "Niepoprawne dane dla ramki:";
					
				}
				step_ = 2;
				break;
			}
			case 'C':
			{
				std::string canal;
				std::string treshold;
				std::string canal_temp;
				std::string treshold_temp;

				std::size_t found3 = operation.find_first_of("rgb");
				std::size_t found4 = operation.find(",");
				if (found3 != std::string::npos and found4 != std::string::npos)
				{
					canal_temp = operation.substr(found3);
					canal.assign(canal_temp.begin(), canal_temp.end() - found4);
					treshold_temp = operation.substr(found4 + 1);
					treshold.assign(treshold_temp.begin(), treshold_temp.end() - 1);

					canal_ = (int)canal[0];
					treshold_ = std::stoi(treshold);
					std::cout << canal_ << std::endl;
					std::cout << treshold_ << std::endl;

					if (canal != "r" and canal != "g" and canal != "b")
					{ 
						message = "Wprowadzono kanal (r,g,b):";
					}
					else if ((treshold_ > 255) or (treshold_ < 0)) {

						message = "Wprowadz treshold z zakresu (0 - 255):";	
					}
					else {
						std::array<int, 3> tab1 = { 3, canal_, treshold_ };
						operation_vector_.push_back(tab1);
						message = "Wprowadzono treshold";
						
					}	
				}
				else
				{
					message = "Niepoprawne dane dla tresholdu:";
				}
				step_ = 2;
				break;

			}
			case '0':
			{
				message = "Koniec wprowadzania";
				step_ = 3;
				break;
			}
			default:
			{
				message = "Niepoprawne dane, podaj (I, R(h,v), C(c,t), 0):";
				step_ = 2;
			}
			}
		}
		catch (const std::exception &e)
		{
			message = "Niepoprawne dane, podaj (I, R(h,v), C(c,t), 0): ";
			step_ = 2;
		}
		return message;
	}
	
	std::vector<std::shared_ptr<effect>> choose_operation() {

		std::vector<std::shared_ptr<effect>> finish_vec;
		
		for (auto element : operation_vector_) {
			switch (element[0]) {
			case 1:
			{
				std::shared_ptr<effect> inversion_ = std::make_shared<inversion>();
				finish_vec.push_back(inversion_);
				break;
			}
			case 2:
			{
				std::shared_ptr<effect> frame_ = std::make_shared<frame>(element[1], element[2]);
				finish_vec.push_back(frame_);
				break;
			}
			case 3:
			{
				std::shared_ptr<effect> treshold_ = std::make_shared<treshold>(element[1], element[2]);
				
				//treshold tr(element[1], element[2]);
				
				finish_vec.push_back(treshold_);
				break;
			}
			}
		}
		return finish_vec;
	}
};