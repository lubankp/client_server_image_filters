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
#include <map>
#include "execute.h"



class comunication_server {


	std::vector<std::map<std::string,int>> operation_vector_;
	int vertical_int;
	int horizontal_int;
	int treshold_;
	int canal_;


	enum operation {
		inversion_enum,
		frame_enum,
		treshold_enum
	};
	

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
	
	std::vector<std::map<std::string, int>>* get_operation_vector() { return &operation_vector_; }


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
				std::map<std::string, int> map = { {"operation", operation::inversion_enum} };
				operation_vector_.push_back(map);
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
					horizontal.assign(horizontal_temp.begin(), horizontal_temp.end() - (operation.size() - found2));
					vertical_temp = operation.substr(found2 + 1);
					vertical.assign(vertical_temp.begin(), vertical_temp.end() - 1);
					
					horizontal_int = std::stoi(horizontal);
					vertical_int = std::stoi(vertical);

					if ((horizontal_int > picture_.get_size_x()) or (horizontal_int < 0)) {

						message = "Podaj wartosc liczbowa horyzontalna z zakresu (0 - " + std::to_string(picture_.get_size_x()) + " ):";
						
					}else if ((vertical_int > picture_.get_size_y()) or (vertical_int < 0)) {

						message = "Podaj wartosc liczbowa wertykalna z zakresu (0 - " + std::to_string(picture_.get_size_y()) + " ):";
					
					}else 
					{ 
						std::map<std::string, int> map1 = { {"operation", operation::frame_enum},{"horizontal", horizontal_int},{"vertical", vertical_int} };
						operation_vector_.push_back(map1);
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
					canal.assign(canal_temp.begin(), canal_temp.end() - (operation.size() - found4));
					treshold_temp = operation.substr(found4 + 1);
					treshold.assign(treshold_temp.begin(), treshold_temp.end() - 1);

					canal_ = (int)canal[0];
					treshold_ = std::stoi(treshold);

					if (canal != "r" and canal != "g" and canal != "b")
					{ 
						message = "Wprowadz kanal (r,g,b):";
					}
					else if ((treshold_ > 255) or (treshold_ < 0)) {

						message = "Wprowadz treshold z zakresu (0 - 255):";	
					}
					else {
						std::map<std::string, int> map2 = { {"operation", operation::treshold_enum},{"canal", canal_},{"treshold", treshold_} };
						operation_vector_.push_back(map2);
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
			switch (element["operation"]) {
			case operation::inversion_enum:
			{
				std::shared_ptr<effect> inversion_ = std::make_shared<inversion>();
				finish_vec.push_back(inversion_);
				break;
			}
			case operation::frame_enum:
			{
				std::shared_ptr<effect> frame_ = std::make_shared<frame>(element["horizontal"], element["vertical"]);
				finish_vec.push_back(frame_);
				break;
			}
			case operation::treshold_enum:
			{
				std::shared_ptr<effect> treshold_ = std::make_shared<treshold>(element["canal"], element["treshold"]);
				
				finish_vec.push_back(treshold_);
				break;
			}
			}
		}
		return finish_vec;
	}
};