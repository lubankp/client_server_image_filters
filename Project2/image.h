#pragma once
#include <iostream>
//#include <SFML/Graphics.hpp>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>


class Picture {

	cv::Mat image_;

public:
	
	bool openPicture(std::string &fileName) {

		image_ = cv::imread(fileName, cv::IMREAD_COLOR);
		if (image_.empty())
		{
			std::cout << "Could not read the image: " << fileName << std::endl;
			return	1;
		}
		else {
		
			return 0;
		}
	}

	void writePicture(std::string fileName) {

		cv::imwrite(fileName, image_);
	}

	
	void show() {

		//cv::namedWindow("Display Window", cv::WINDOW_GUI_NORMAL);
		cv::imshow("Display Window", image_);
		cv::waitKey(0);
		cv::destroyWindow("Display Window");
	}

	cv::Mat* getImage() { return &image_; };
	
	int getSizeX() {
		return image_.cols;
	}

	int getSizeY() {
		return image_.rows;
	}

	std::vector<int> getPixel(int x, int y) {
	
		std::vector<int> pixel = {0,0,0};
			
		pixel[0] = image_.at<cv::Vec3b>(y, x)[0];
		pixel[1] = image_.at<cv::Vec3b>(y, x)[1];
		pixel[2] = image_.at<cv::Vec3b>(y, x)[2];
		return pixel;
	}

	void setPixel(int x, int y, std::vector<int> vec) {

		image_.at<cv::Vec3b>(y, x)[0] = vec[0];
		image_.at<cv::Vec3b>(y, x)[1] = vec[1];
		image_.at<cv::Vec3b>(y, x)[2] = vec[2];

	}



};