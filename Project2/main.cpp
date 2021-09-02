
#include "comunication.cpp"
#include "execute.cpp"

int main() {

	Comunication comunication;
	std::vector<std::shared_ptr<Effect>> finish_vect;
	
	Picture  picture = comunication.init();
	finish_vect = comunication.chooseOperation(picture);
	
	Execute execute;
	execute.execute(finish_vect, picture);
	
	picture.writePicture("C:/Users/p.lubanski/source/repos/CPP Learning2/Project2/obraz2.bmp");
	picture.show();

}