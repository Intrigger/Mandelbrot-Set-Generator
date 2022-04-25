#include "graphics.h"

using namespace graphics;

void BMPImage::set_height(const size_t& Height){
	if (Height <= MAX_HEIGHT){
		if (Height > 0) this->height = Height;
		else{
			std::cerr << "In set_height(): " << " Height must be 1 or bigger." << std::endl;
			this->height = 0;
		}
	}
	else{
		this->height = 0;
		std::cerr << "In set_height(): " <<
				     "Couldn`t set height to value " << Height << std::endl;
		std::cerr << "(maximum height is " << MAX_HEIGHT << ")." << std::endl;
	}
}