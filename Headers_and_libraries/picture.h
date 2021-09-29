#pragma once
#include <iostream>
#include <string>
#include "my_exeption.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

typedef unsigned char byte;

class picture {

	cv::Mat image_;

public:

	void open_picture(std::string& file_name) {

		image_ = cv::imread(file_name, cv::IMREAD_COLOR);
		if (image_.empty())
		{
			throw my_exceptions{ "Niewlasciwa nazwa pliku: " + file_name + " , podaj inna:" };
		}
	}

	cv::Mat* get_image() { return &image_; }

	void write_picture(std::string file_name) {

		cv::imwrite(file_name, image_);
	}


	void show() {

		cv::imshow("Display Window", image_);
		cv::waitKey(0);
		cv::destroyWindow("Display Window");
	}

	int get_size_x() {
		return image_.cols;
	}

	int get_size_y() {
		return image_.rows;
	}

	std::array<int, 3> get_pixel(int x, int y) {

		std::array<int, 3> pixel = { 0,0,0 };

		pixel[0] = image_.at<cv::Vec3b>(y, x)[0];
		pixel[1] = image_.at<cv::Vec3b>(y, x)[1];
		pixel[2] = image_.at<cv::Vec3b>(y, x)[2];
		return pixel;
	}

	void set_pixel(int x, int y, std::array<int, 3> array) {

		image_.at<cv::Vec3b>(y, x)[0] = array[0];
		image_.at<cv::Vec3b>(y, x)[1] = array[1];
		image_.at<cv::Vec3b>(y, x)[2] = array[2];

	}

	byte* mat_to_bytes()
	{
		int size = image_.total() * image_.elemSize();
		byte* bytes = new byte[size];  // you will have to delete[] that later
		std::memcpy(bytes, image_.data, size * sizeof(byte));
		return bytes;
	}

	void bytes_to_mat(byte* bytes, int width, int height)
	{
		image_ = cv::Mat(height, width, CV_8UC3, bytes).clone();
	}

	size_t total()
	{
		return image_.total();
	}

	size_t elem_size()
	{
		return image_.elemSize();
	}
};