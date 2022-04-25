#include "graphics.h"
#include <iostream>

using namespace graphics;

void BMPImage::clear(){



	if (pixels != nullptr){
		for (int i = 0; i < height; i++){
			if (pixels[i] != nullptr) delete[] pixels[i];
		}
		this->height = this->width = 0;
		delete[] pixels;
		pixels = nullptr;
	}
	
}