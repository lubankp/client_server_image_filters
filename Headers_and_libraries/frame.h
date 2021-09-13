
#include "effect.h"

class Frame : public Effect {

	int horizontal_;
	int vertical_;

public:

	Frame(int horizontal, int vertical) : horizontal_(horizontal), vertical_(vertical) {};
	
	void makeEffect(Picture& e_image_) override {

		int horizontal_s = (e_image_.getSizeX() - horizontal_) / 2;
		int horizontal_f = e_image_.getSizeX() - horizontal_s;
		int vertical_s = (e_image_.getSizeY() - vertical_) / 2;
		int vertical_f = e_image_.getSizeY() - vertical_s;


		for (int x = 0; x < e_image_.getSizeX(); x++) {

			for (int y = 0; y < e_image_.getSizeY(); y++) {

				if ((x < horizontal_s or x > horizontal_f) or (y < vertical_s or y > vertical_f)) {

					std::vector<int> vec;
					vec.push_back(255);
					vec.push_back(255);
					vec.push_back(255);

					e_image_.setPixel(x, y, vec);
				}
			}
		}

	}
	~Frame(){};
};