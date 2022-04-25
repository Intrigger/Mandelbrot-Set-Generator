#include "graphics.h"
#include <iostream>

using namespace graphics;

RGB_Color BMPImage::get_pixel(size_t x, size_t y){
	if (x < 0){
		std::cerr << "x can`t be less than 0." << std::endl;
		return {0, 0, 0};
	}
	if (x >= MAX_WIDTH){
		std::cerr << "x is to large." << std::endl;
		return {0, 0, 0};
	}
	if (y < 0){
		std::cerr << "y can`t be less than 0." << std::endl;
		return {0, 0, 0};
	}
	if (y >= MAX_HEIGHT){
		std::cerr << "y is to large." << std::endl;
		return {0, 0, 0};
	}

	return this->pixels[y][x];
}