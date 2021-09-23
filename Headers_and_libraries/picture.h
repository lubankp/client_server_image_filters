#pragma once
#include <iostream>
#include <string>
#include "exeption.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

typedef unsigned char byte;

class Picture {

	cv::Mat image_;

public:
	
	void openPicture(std::string &fileName) {

		image_ = cv::imread(fileName, cv::IMREAD_COLOR);
		if (image_.empty())
		{
			throw myExceptions{ "Niewlasciwa nazwa pliku: " + fileName + " , podaj inna:" };
		}
	}

	cv::Mat* getImage() { return &image_; }

	void writePicture(std::string fileName) {

		cv::imwrite(fileName, image_);
	}

	
	void show() {

		cv::imshow("Display Window", image_);
		cv::waitKey(0);
		cv::destroyWindow("Display Window");
	}
	
	int getSizeX() {
		return image_.cols;
	}

	int getSizeY() {
		return image_.rows;
	}

	std::array<int,3> getPixel(int x, int y) {
	
		std::array<int, 3> pixel = {0,0,0};
			
		pixel[0] = image_.at<cv::Vec3b>(y, x)[0];
		pixel[1] = image_.at<cv::Vec3b>(y, x)[1];
		pixel[2] = image_.at<cv::Vec3b>(y, x)[2];
		return pixel;
	}

	void setPixel(int x, int y, std::array<int,3> array) {

		image_.at<cv::Vec3b>(y, x)[0] = array[0];
		image_.at<cv::Vec3b>(y, x)[1] = array[1];
		image_.at<cv::Vec3b>(y, x)[2] = array[2];

	}

	byte* matToBytes()
	{
		int size = image_.total() * image_.elemSize();
		byte* bytes = new byte[size];  // you will have to delete[] that later
		std::memcpy(bytes, image_.data, size * sizeof(byte));
		return bytes;
	}

	void bytesToMat(byte* bytes, int width, int height)
	{
		image_ = cv::Mat(height, width, CV_8UC3, bytes).clone();
	}

	size_t total()
	{
		return image_.total();
	}

	size_t elemSize()
	{
		return image_.elemSize();
	}
};