#include "graphics.h"

using namespace graphics;

void BMPImage::set_height(const size_t& Height){
	if (Height <= MAX_HEIGHT){
		if (Height > 0){

			for (int i = 0; i < this->height; i++){
				if (pixels[i] != nullptr) delete[] pixels[i];
			}

			if (pixels != nullptr) delete[] pixels;

			this->height = Height;

			pixels = new RGB_Color*[this->height];

			if (this->width == 0){
				for (int i = 0; i < height; i++){
					pixels[i] = nullptr;
				}
			}
			else{
				for (int i = 0; i < height; i++){
					pixels[i] = new RGB_Color[this->width];
				}
			}	

			
			for (int y = 0; y < this->height; y++){
				for (int x = 0; x < this->width; x++){
					pixels[y][x] = WHITE_COLOR;
				}
			}

		}
		else{
			std::cerr << "In set_height(): " << " Height must be 1 or bigger." << std::endl;
			this->height = 0;
			exit(-1);
		}
	}
	else{
		this->height = 0;
		std::cerr << "In set_height(): " <<
				     "Couldn`t set height to value " << Height << std::endl;
		std::cerr << "(maximum height is " << MAX_HEIGHT << ")." << std::endl;
		exit(-1);
	}
}