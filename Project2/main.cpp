#include "yami.h"
#include <iostream>
#include "image.h"
#include <SFML/Graphics.hpp>
#include <effect.h>

int main() {

	Effect effect;
	Picture  picture = effect.init();
	effect.chooseOperation(picture);
	
}