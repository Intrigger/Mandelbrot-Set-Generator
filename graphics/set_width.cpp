#include "graphics.h"
#include <iostream>

using namespace graphics;

void BMPImage::set_width(const size_t& Width){
	if (Width <= MAX_WIDTH){
		if (Width > 0){
			for (int i = 0; i < this->height; i++){
				if (pixels[i] != nullptr) delete[] pixels[i];
			}

			if (pixels != nullptr) delete[] pixels;

			this->width = Width;

			if (this->height == 0) return;

			pixels = new RGB_Color*[this->height];

			for (int i = 0; i < height; i++){
				pixels[i] = new RGB_Color[this->width];
			}
			for (int y = 0; y < this->height; y++){
				for (int x = 0; x < this->width; x++){
					pixels[y][x] = WHITE_COLOR;
				}
			}
		}

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