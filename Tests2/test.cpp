// Let Catch provide main():
#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "catchmain.h"
#include "comunication.h"
#include "execute.h"



SCENARIO("File is loaded correctly", "file") {

	GIVEN("Loaded images ") {
		cv::Mat image;
		image = cv::imread("../Headers_and_libraries/obraz1.bmp", cv::IMREAD_COLOR);
		Comunication comunication;

		WHEN("Init function is called") {
			std::string file_name = "obraz1.bmp";
			picture picture = comunication.open(file_name);

			THEN("Images are identical") {
				cv::Mat* result = picture.getImage();

				for (int x = 0; x < picture.getSizeX(); x++) {

					for (int y = 0; y < picture.getSizeY(); y++) {

						auto expected_pixel = image.at<cv::Vec3b>(y, x);
						auto pixel = result->at<cv::Vec3b>(y, x);

						REQUIRE(expected_pixel == pixel);
					}
				}
			}
		}
	}
}


SCENARIO("Image is inverted correctly", "inversion") {

	GIVEN("Loaded images ") {
		cv::Mat image;
		image = cv::imread("../Headers_and_libraries/obraz2.bmp", cv::IMREAD_COLOR);

		Comunication comunication;
		std::string file_name = "obraz1.bmp";
		picture picture = comunication.open(file_name);
		cv::Mat* result = picture.get_image();

		WHEN("Invertion function is called") {

			std::shared_ptr<effect> inversion_ = std::make_shared<inversion>();
			inversion_->make_effect(picture);

			THEN("Images are identical") {

				for (int x = 0; x < picture.get_size_x(); x++) {

					for (int y = 0; y < picture.get_size_y(); y++) {

						auto expected_pixel = image.at<cv::Vec3b>(y, x);
						auto pixel = result->at<cv::Vec3b>(y, x);

						REQUIRE(expected_pixel == pixel);
					}
				}
			}
		}
	}
}

SCENARIO("Frame is printed correctly", "treshold red") {

	GIVEN("Loaded images ") {
		cv::Mat image;
		image = cv::imread("../Headers_and_libraries/obraz3.bmp", cv::IMREAD_COLOR);

		Comunication comunication;
		std::string file_name = "obraz1.bmp";
		picture picture = comunication.open(file_name);
		cv::Mat* result = picture.get_image();

		WHEN("TFrame function is called with parameters: horizontal = 100, vertical = 100") {

			std::shared_ptr<effect> frame_ = std::make_shared<frame>(100, 100);
			frame_->make_effect(picture);


			THEN("Images are identical") {

				for (int x = 0; x < picture.get_size_x(); x++) {

					for (int y = 0; y < picture.get_size_y(); y++) {

						auto expected_pixel = image.at<cv::Vec3b>(y, x);
						auto pixel = result->at<cv::Vec3b>(y, x);

						REQUIRE(expected_pixel == pixel);
					}
				}
			}
		}
	}
}

SCENARIO("Red canal is tresholded correctly", "treshold red") {

	GIVEN("Loaded images ") {
		cv::Mat image;
		image = cv::imread("../Headers_and_libraries/obraz4.bmp", cv::IMREAD_COLOR);

		Comunication comunication;
		std::string file_name = "obraz1.bmp";
		picture picture = comunication.open(file_name);
		cv::Mat* result = picture.get_image();

		WHEN("Treshold function is called with parameters: canal = r (114), treshold = 100") {

			std::shared_ptr<effect> treshold_ = std::make_shared<treshold>(114, 100);
			treshold_->make_effect(picture);

			THEN("Images are identical") {

				for (int x = 0; x < picture.get_size_x(); x++) {

					for (int y = 0; y < picture.get_size_y(); y++) {

						auto expected_pixel = image.at<cv::Vec3b>(y, x);
						auto pixel = result->at<cv::Vec3b>(y, x);

						REQUIRE(expected_pixel == pixel);
					}
				}
			}
		}
	}
}

SCENARIO("Green canal is tresholded correctly", "treshold green") {

	GIVEN("Loaded images ") {
		cv::Mat image;
		image = cv::imread("../Headers_and_libraries/obraz5.bmp", cv::IMREAD_COLOR);

		Comunication comunication;
		std::string file_name = "obraz1.bmp";
		picture picture = comunication.open(file_name);
		cv::Mat* result = picture.get_image();

		WHEN("Treshold function is called with parameters: canal = g (103), treshold = 100") {

			std::shared_ptr<effect> treshold_ = std::make_shared<treshold>(103, 100);
			treshold_->make_effect(picture);

			THEN("Images are identical") {

				for (int x = 0; x < picture.get_size_x(); x++) {

					for (int y = 0; y < picture.get_size_y(); y++) {

						auto expected_pixel = image.at<cv::Vec3b>(y, x);
						auto pixel = result->at<cv::Vec3b>(y, x);

						REQUIRE(expected_pixel == pixel);
					}
				}
			}
		}
	}
}

SCENARIO("Blue canal is tresholded correctly", "treshold green") {

	GIVEN("Loaded images ") {
		cv::Mat image;
		image = cv::imread("../Headers_and_libraries/obraz6.bmp", cv::IMREAD_COLOR);

		Comunication comunication;
		std::string file_name = "obraz1.bmp";
		picture picture = comunication.open(file_name);
		cv::Mat* result = picture.get_image();

		WHEN("Treshold function is called with parameters: canal = b (98), treshold = 100") {

			std::shared_ptr<effect> treshold_ = std::make_shared<treshold>(98, 100);
			treshold_->make_effect(picture);

			THEN("Images are identical") {

				for (int x = 0; x < picture.get_size_x(); x++) {

					for (int y = 0; y < picture.get_size_y(); y++) {

						auto expected_pixel = image.at<cv::Vec3b>(y, x);
						auto pixel = result->at<cv::Vec3b>(y, x);

						REQUIRE(expected_pixel == pixel);
					}
				}
			}
		}
	}
}