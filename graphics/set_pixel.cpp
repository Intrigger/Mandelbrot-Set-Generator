#include "graphics.h"
#include <iostream>

using namespace graphics;

void BMPImage::set_pixel(size_t x, size_t y, RGB_Color color){
	if (x < 0){
		std::cerr << "x can`t be less than 0." << std::endl;
		return;
	}
	if (x >= MAX_WIDTH){
		std::cerr << "x is to large." << std::endl;
		return;
	}
	if (y < 0){
		std::cerr << "y can`t be less than 0." << std::endl;
		return;
	}
	if (y >= MAX_HEIGHT){
		std::cerr << "y is to large." << std::endl;
		return;
	}

	this->pixels[y][x] = color;
}