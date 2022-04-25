#include "graphics.h"
#include <iostream>

using namespace graphics;

void BMPImage::set_width(const size_t& Width){
	if (Width <= MAX_WIDTH){
		if (Width > 0) this->width = Width;
		else{
			std::cerr << "In set_width(): " << " Width must be 1 or bigger." << std::endl;
			this->width = 0;
		}
	}
	else{
		this->width = 0;
		std::cerr << "In set_width(): " <<
				     "Couldn`t set width to value " << Width << std::endl;
		std::cerr << "(maximum width is " << MAX_WIDTH << ")." << std::endl;
	}
}