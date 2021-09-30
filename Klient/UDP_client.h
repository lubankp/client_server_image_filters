#pragma once
#include <iostream>

enum  message_state {
	rejected,
	replied
};




class parameters {

public:
	void set_integer(std::string message_name, int value) {
	}

	void set_string(std::string message_name, std::string string) {
	}

	void set_binary() {
	}

	std::string get_string(std::string message_name) {

		std::string str;

		return str;
	}

	int get_integer(std::string message_name) {

		int number;

		return number;
	}

	const void* get_binary(std::string, std::size_t size) {

		const void* binary;

		return binary;
	}
};

class message {

	message_state message_state_;
	const parameters param_;

public:

	message_state get_state() { return message_state_; }

	const parameters& get_reply() {

		return param_;
	}

	void wait_for_completion() {


	}

	std::string get_exception_msg() {
		std::string exception = "ERROR";

		return exception;
	}

};

class agent {

public:
	message* send(std::string server_address, std::string name, std::string message_name, parameters params, int num, bool value) {

		message* message;



		return message;
	}
};