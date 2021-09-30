#pragma once
#include <vector>
#include <map>
#include "inversion.h"
#include "treshold.h"
#include "frame.h"
#include "execute.h"
#include "enum_operation.h"

class effect_factory {

	std::vector<std::map<std::string, int>> operation_vector_;
	

public:

	effect_factory(std::vector<std::map<std::string, int>> operation_vector) : operation_vector_(operation_vector) {};

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