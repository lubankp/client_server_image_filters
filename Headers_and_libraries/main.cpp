
#include "comunication.h"
#include "execute.h"
#include "yami.h"
#include <cstdlib>





int main() {

	Comunication comunication;

	std::string file_name = comunication.init();
	picture  picture = comunication.open(file_name);

	std::vector<std::array<int, 3>> operation_vector;
	operation_vector = comunication.createOperationVec(picture);

	std::vector<std::shared_ptr<effect>> finish_vect;
	finish_vect = comunication.chooseOperation(operation_vector);

	execute execute_;
	execute_.execute(finish_vect, picture);
	picture.show();
	//	picture.writePicture("C:/Users/p.lubanski/source/repos/CPP Learning2/Project2/obraz4.bmp");

}


