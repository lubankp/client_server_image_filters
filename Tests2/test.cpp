// Let Catch provide main():
#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "catchmain.h"
#include "comunication.h"
#include "execute.h"



SCENARIO("File is loaded correctly", "file") {
    
    GIVEN("Loaded images ") {
        cv::Mat image;
        image = cv::imread("C:/Users/p.lubanski/Source/Repos/CPP Learning2/Project2/obraz1.bmp", cv::IMREAD_COLOR);
        Comunication comunication;

        WHEN("Init function is called") {
            std::string file_name = "obraz1.bmp";
            Picture picture = comunication.open(file_name);
            
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
        image = cv::imread("C:/Users/p.lubanski/Source/Repos/CPP Learning2/Project2/obraz2.bmp", cv::IMREAD_COLOR);

        Comunication comunication;
        std::string file_name = "obraz1.bmp";
        Picture picture = comunication.open(file_name);
        cv::Mat* result = picture.getImage();

        WHEN("Invertion function is called") {

                std::shared_ptr<Effect> inversion = std::make_shared<Inversion>();
                inversion->makeEffect(picture);

            THEN("Images are identical") {

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

SCENARIO("Frame is printed correctly", "treshold red") {

    GIVEN("Loaded images ") {
        cv::Mat image;
        image = cv::imread("C:/Users/p.lubanski/Source/Repos/CPP Learning2/Project2/obraz3.bmp", cv::IMREAD_COLOR);

        Comunication comunication;
        std::string file_name = "obraz1.bmp";
        Picture picture = comunication.open(file_name);
        cv::Mat* result = picture.getImage();

        WHEN("TFrame function is called with parameters: horizontal = 100, vertical = 100") {

            std::shared_ptr<Effect> frame = std::make_shared<Frame>(100, 100);
            frame->makeEffect(picture);


            THEN("Images are identical") {

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

SCENARIO("Red canal is tresholded correctly", "treshold red") {

    GIVEN("Loaded images ") {
        cv::Mat image;
        image = cv::imread("C:/Users/p.lubanski/Source/Repos/CPP Learning2/Project2/obraz4.bmp", cv::IMREAD_COLOR);

        Comunication comunication;
        std::string file_name = "obraz1.bmp";
        Picture picture = comunication.open(file_name);
        cv::Mat* result = picture.getImage();

        WHEN("Treshold function is called with parameters: canal = r (114), treshold = 100") {

            std::shared_ptr<Effect> treshold = std::make_shared<Treshold>(114,100);
            treshold->makeEffect(picture);

            THEN("Images are identical") {

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

SCENARIO("Green canal is tresholded correctly", "treshold green") {

    GIVEN("Loaded images ") {
        cv::Mat image;
        image = cv::imread("C:/Users/p.lubanski/Source/Repos/CPP Learning2/Project2/obraz5.bmp", cv::IMREAD_COLOR);

        Comunication comunication;
        std::string file_name = "obraz1.bmp";
        Picture picture = comunication.open(file_name);
        cv::Mat* result = picture.getImage();

        WHEN("Treshold function is called with parameters: canal = g (103), treshold = 100") {

            std::shared_ptr<Effect> treshold = std::make_shared<Treshold>(103, 100);
            treshold->makeEffect(picture);

            THEN("Images are identical") {

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

SCENARIO("Blue canal is tresholded correctly", "treshold green") {

    GIVEN("Loaded images ") {
        cv::Mat image;
        image = cv::imread("C:/Users/p.lubanski/Source/Repos/CPP Learning2/Project2/obraz6.bmp", cv::IMREAD_COLOR);

        Comunication comunication;
        std::string file_name = "obraz1.bmp";
        Picture picture = comunication.open(file_name);
        cv::Mat* result = picture.getImage();

        WHEN("Treshold function is called with parameters: canal = b (98), treshold = 100") {

            std::shared_ptr<Effect> treshold = std::make_shared<Treshold>(98, 100);
            treshold->makeEffect(picture);

            THEN("Images are identical") {

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