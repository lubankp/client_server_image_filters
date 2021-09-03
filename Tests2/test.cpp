// Let Catch provide main():
#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "catchmain.h"
#include "comunication.h"
#include "execute.h"
#include <SFML/Graphics.hpp>


SCENARIO("File is loaded correctly", "file") {
    
    GIVEN("Loaded images ") {
        sf::Image image;
        image.loadFromFile("C:/Users/p.lubanski/Source/Repos/CPP Learning2/Project2/obraz1.bmp");
        Comunication comunication;

        WHEN("Init function is called") {
            std::string file_name = "obraz1.bmp";
            Picture picture = comunication.open(file_name);
            
            THEN("Images are identical") {
                sf::Image* result = picture.getImage();

                for (int x = 0; x < picture.getImage()->getSize().x; x++) {

                    for (int y = 0; y < picture.getImage()->getSize().y; y++) {

                        sf::Color expected_pixel = image.getPixel(x, y);
                        sf::Color pixel = result->getPixel(x, y);

                        REQUIRE(expected_pixel == pixel);
                    }
                }
            }
        }
    }
}
/*
SCENARIO("If operation vector is created correctly", "create_vector") {

    GIVEN("Load vector ") {
       
        std::vector<int> vec = { 1, 2, 3, 1, 2, 3 };
        Comunication comunication;
        

        WHEN("chooseOperation function is called") {
          
            std::vector<std::shared_ptr<Effect>> finish_vec;
            finish_vec = comunication.chooseOperation(picture, operation_vector);

            THEN("Images are identical") {
               
                
            }
        }
    }
}
*/



SCENARIO("Image is inverted correctly", "inversion") {

    GIVEN("Loaded images ") {
        sf::Image image;
        image.loadFromFile("C:/Users/p.lubanski/Source/Repos/CPP Learning2/Project2/obraz2.bmp");

        Comunication comunication;
        std::string file_name = "obraz1.bmp";
        Picture picture = comunication.open(file_name);
        sf::Image* result = picture.getImage();

        WHEN("Invertion function is called") {

                std::shared_ptr<Effect> inversion = std::make_shared<Inversion>();
                inversion->makeEffect(picture);

            THEN("Images are identical") {

                for (int x = 0; x < picture.getImage()->getSize().x; x++) {

                    for (int y = 0; y < picture.getImage()->getSize().y; y++) {

                        sf::Color expected_pixel = image.getPixel(x, y);
                        sf::Color pixel = result->getPixel(x, y);

                        REQUIRE(expected_pixel == pixel);
                    }
                }
            }
        }
    }
}

SCENARIO("Frame is printed correctly", "treshold red") {

    GIVEN("Loaded images ") {
        sf::Image image;
        image.loadFromFile("C:/Users/p.lubanski/Source/Repos/CPP Learning2/Project2/obraz3.bmp");

        Comunication comunication;
        std::string file_name = "obraz1.bmp";
        Picture picture = comunication.open(file_name);
        sf::Image* result = picture.getImage();

        WHEN("TFrame function is called with parameters: horizontal = 100, vertical = 100") {

            std::shared_ptr<Effect> frame = std::make_shared<Frame>(100, 100);
            frame->makeEffect(picture);

            THEN("Images are identical") {

                for (int x = 0; x < picture.getImage()->getSize().x; x++) {

                    for (int y = 0; y < picture.getImage()->getSize().y; y++) {

                        sf::Color expected_pixel = image.getPixel(x, y);
                        sf::Color pixel = result->getPixel(x, y);

                        REQUIRE(expected_pixel == pixel);
                    }
                }
            }
        }
    }
}

SCENARIO("Red canal is tresholded correctly", "treshold red") {

    GIVEN("Loaded images ") {
        sf::Image image;
        image.loadFromFile("C:/Users/p.lubanski/Source/Repos/CPP Learning2/Project2/obraz4.bmp");

        Comunication comunication;
        std::string file_name = "obraz1.bmp";
        Picture picture = comunication.open(file_name);
        sf::Image* result = picture.getImage();

        WHEN("Treshold function is called with parameters: canal = r, treshold = 100") {

            std::shared_ptr<Effect> treshold = std::make_shared<Treshold>("r",100);
            treshold->makeEffect(picture);

            THEN("Images are identical") {

                for (int x = 0; x < picture.getImage()->getSize().x; x++) {

                    for (int y = 0; y < picture.getImage()->getSize().y; y++) {

                        sf::Color expected_pixel = image.getPixel(x, y);
                        sf::Color pixel = result->getPixel(x, y);

                        REQUIRE(expected_pixel == pixel);
                    }
                }
            }
        }
    }
}

SCENARIO("Green canal is tresholded correctly", "treshold green") {

    GIVEN("Loaded images ") {
        sf::Image image;
        image.loadFromFile("C:/Users/p.lubanski/Source/Repos/CPP Learning2/Project2/obraz5.bmp");

        Comunication comunication;
        std::string file_name = "obraz1.bmp";
        Picture picture = comunication.open(file_name);
        sf::Image* result = picture.getImage();

        WHEN("Treshold function is called with parameters: canal = g, treshold = 100") {

            std::shared_ptr<Effect> treshold = std::make_shared<Treshold>("g", 100);
            treshold->makeEffect(picture);

            THEN("Images are identical") {

                for (int x = 0; x < picture.getImage()->getSize().x; x++) {

                    for (int y = 0; y < picture.getImage()->getSize().y; y++) {

                        sf::Color expected_pixel = image.getPixel(x, y);
                        sf::Color pixel = result->getPixel(x, y);

                        REQUIRE(expected_pixel == pixel);
                    }
                }
            }
        }
    }
}

SCENARIO("Blue canal is tresholded correctly", "treshold green") {

    GIVEN("Loaded images ") {
        sf::Image image;
        image.loadFromFile("C:/Users/p.lubanski/Source/Repos/CPP Learning2/Project2/obraz6.bmp");

        Comunication comunication;
        std::string file_name = "obraz1.bmp";
        Picture picture = comunication.open(file_name);
        sf::Image* result = picture.getImage();

        WHEN("Treshold function is called with parameters: canal = b, treshold = 100") {

            std::shared_ptr<Effect> treshold = std::make_shared<Treshold>("b", 100);
            treshold->makeEffect(picture);

            THEN("Images are identical") {

                for (int x = 0; x < picture.getImage()->getSize().x; x++) {

                    for (int y = 0; y < picture.getImage()->getSize().y; y++) {

                        sf::Color expected_pixel = image.getPixel(x, y);
                        sf::Color pixel = result->getPixel(x, y);

                        REQUIRE(expected_pixel == pixel);
                    }
                }
            }
        }
    }
}